#include "dac.h"
#include "ui_dac.h"
#include <QStyleFactory>
#include <QDesktopServices>
#include <QUrl>
#include "protocoldialog.h"

/* DAC——WinForm */
DAC::DAC(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DAC)
{
    ui->setupUi(this);
    currentPort = new BaseSerialComm();
    this->initComboBox_Config();
    /* 串口错误信息处理 */
    connect(currentPort,SIGNAL(errorOccurred(QSerialPort::SerialPortError)),this, SLOT(slots_errorHandler(QSerialPort::SerialPortError)  ));
    this->setWindowTitle("硬石电子-DAC模块控制工具 v1.0");

    QString styleName;
    styleName = loadStyle();
    if(styleName != NULL)
        this->configStyle(styleName);

    this->Master = new MBSerialMaster();
    tim = new QTimer();
}

DAC::~DAC()
{
    delete ui;
}

/*   初始化了串口设置当中的下拉列表(ComboBox) */
void DAC::initComboBox_Config()
{
    /* 更新下拉列表 */
    BaseSerialComm::listBaudRate( ui->cbbBaud, 0);
    BaseSerialComm::listDataBit ( ui->cbbDataBit, 0);
    BaseSerialComm::listVerify  ( ui->cbbVerify , 0 );
    BaseSerialComm::listStopBit ( ui->cbbStopBit);
    BaseSerialComm::listPortNum ( ui->cbbPortNum);
    BaseSerialComm::listBaudRate( ui->cbbNewBaud, 0);
    BaseSerialComm::listVerify  ( ui->cbbNewVerify, 0);

}
/* updata stop bits 槽函数 */
void DAC::on_cbbVerify_currentIndexChanged(int index)
{
    QVariant tmpVariant;
    switch(index){
    case 0:
        ui -> cbbStopBit->setCurrentText("2");
        break;
    default :
        ui -> cbbStopBit->setCurrentText("1");
        break;
    }
    if(currentPort->isOpen()){
        tmpVariant = ui->cbbStopBit->currentData();// 某些情况不支持1.5停止位
        currentPort->setStopBits (tmpVariant.value < BaseSerialComm::StopBits > ());
    }
}

/* updata baudRate 槽函数 */
void DAC::on_cbbBaud_currentIndexChanged(int index)
{
    Q_UNUSED(index)
    if(currentPort->isOpen()){
        QVariant tmpVariant;
        /* 设置波特率 */
        tmpVariant = ui->cbbBaud->currentData();  // 读取控件的当前项的值
        currentPort->setBaudRate(tmpVariant.value < BaseSerialComm::BaudRate > ()  );
    }
}


/* 刷新按钮点击 槽函数 */
void DAC::on_btnRefresh_clicked()
{

    if( !currentPort->isOpen()){  // 关闭串口才能刷新端口号
        ui -> cbbPortNum ->clear();
        BaseSerialComm::listPortNum ( ui -> cbbPortNum );
    }
}

/* 打开串口 槽函数*/
void DAC::on_btnOpenPort_clicked(bool checked)
{
    QString tmp = ui->cbbPortNum->currentText();
    tmp = tmp.split(" ").first();//  Item的 text 由 <COM1 "描述"> 组成,使用空格作为分隔符取第一段就是端口名
    if(checked){
        // 当前串口处于关闭状态
        currentPort->setPortName( tmp );              // 设置端口号
        if( currentPort->open(QIODevice::ReadWrite)){ // 打开串口
            currentPort -> setDTRState(false);
            currentPort -> setRTSState(false);
            /* 配置端口的波特率等参数 */
            this->configPort();
            this->Master->configMaster(currentPort, ui->txtCurrentAddr->text().toInt() );
            ui->btnOpenPort->setText(tr("关闭端口"));
        }else{
            ui->btnOpenPort->setChecked(false);
        }
    }
    else{
        currentPort->close();
        ui->btnOpenPort->setText(tr("打开端口"));
    }
}

/* 配置端口的波特率\数据位\奇偶校验\停止位 */
void DAC::configPort()
{
    QVariant tmpVariant;
    /* 设置波特率 */
    tmpVariant = ui->cbbBaud->currentData();  // 读取控件的当前项的值
    currentPort->setBaudRate(tmpVariant.value < BaseSerialComm::BaudRate > ()  );

    /* 设置数据位 */
    tmpVariant = ui->cbbDataBit->currentData();
    currentPort->setDataBits( tmpVariant.value <BaseSerialComm::DataBits > () );

    /* 设置校验位 */
    tmpVariant = ui->cbbVerify->currentData();
    currentPort->setParity (tmpVariant.value < BaseSerialComm::Parity > () );

    /* 设置停止位 */
    tmpVariant = ui->cbbStopBit->currentData();// 某些情况不支持1.5停止位
    if(currentPort->setStopBits (tmpVariant.value < BaseSerialComm::StopBits > () ) == false ){
        ui -> cbbStopBit->clear();
        BaseSerialComm::listStopBit ( ui -> cbbStopBit );
        QMessageBox::information(NULL, tr("不支持的设置"),  tr("该串口设备不支持当前停止位设置,已修改为默认的设置"), 0, 0);
    }
}

/* 串口错误信息处理 */
void DAC::slots_errorHandler(QSerialPort::SerialPortError error)
{
    switch(error){
    case QSerialPort::DeviceNotFoundError:QMessageBox::information(NULL, tr("未找到设备"),  tr("检查设备是否已经连接,或者是否正常供电"), 0, 0);
        break;
    case QSerialPort::OpenError:
    case QSerialPort::PermissionError:QMessageBox::information(NULL, tr("打开失败"),  tr("检查设备是否已被其他软件占用"), 0, 0);
        break;
    default:
        break;
    }
}

/* 读设备信息 */
void DAC::on_btnDeviceMsg_clicked()
{
    if(!currentPort->isOpen()){
        ui->statusBar->showMessage(tr("未打开串口"));
        return;
    }
    ui->statusBar->showMessage(tr("读取设备ID和控制模式"));

    this->readAll();
}

void DAC::readAll()
{
    ui->statusBar->clearMessage();
    /* 连续读10个寄存器 */
    QByteArray txbuf;
    QByteArray rxbuf;
    if(Master->readHoldingRegisters(RegDeviceID, 10, txbuf, rxbuf) == MBSerialMaster::ErrNone){
        QByteArray deviceID = rxbuf.mid(3,2).toHex().toUpper();// 设备ID:MD+0x1040
        deviceID.prepend("MD");
        ui->lblDeviceID->setText(deviceID);

        quint16 deviceAddress = (rxbuf.at(5)<<8) | rxbuf.at(6); // 通信参数1,从地址
        ui->txtNewAddr->setText(tr("%01").arg(deviceAddress)); // 显示从机地址

//        quint16 deviceDataWidth = (rxbuf.at(7)<<8) | rxbuf.at(8);   // 通信参数2,数据长度,停止位

        quint16 deviceVerify = (rxbuf.at(9)<<8) | rxbuf.at(10);  // 通信参数3,校验位
        ui->cbbNewVerify->setCurrentIndex(deviceVerify);

        quint16 deviceBaud = (rxbuf.at(11)<<8) | rxbuf.at(12);  // 通信参数4,波特率
        ui->cbbNewBaud->setCurrentIndex(deviceBaud);

        quint16 deviceSys = (rxbuf.at(13)<<8) | rxbuf.at(14);  // 系统寄存器,控制模式
        if( 0 != deviceSys ){
            ui->lblCtrlMode->setText("PWM");
        }else{
            ui->lblCtrlMode->setText("Modbus");
        }

        quint16 deviceCHAOutput = ((quint8)(rxbuf.at(15))<<8) | (quint8)rxbuf.at(16);  // 通道A输出电压值
        double Output = (double)deviceCHAOutput/(double)1000;
        ui->spbVoltChA->setValue(Output);
        quint16 deviceCHBOutput = ((quint8)rxbuf.at(17)<<8) | (quint8)rxbuf.at(18);  // 通道A输出电压值
        Output = (double)deviceCHBOutput/(double)1000;
        ui->spbVoltChB->setValue(Output);

        quint16 deviceCHACalibration = ((quint8)rxbuf.at(19)<<8) | (quint8)rxbuf.at(20);  // 通道A输出校准比例
        Output = (double)deviceCHACalibration /(double)10000;
        ui->spbVoltCaliA->setValue(Output);

        quint16 deviceCHBCalibration = ((quint8)rxbuf.at(21)<<8) | (quint8)rxbuf.at(22);  // 通道B输出校准比例
        Output = (double)deviceCHBCalibration /(double)10000;
        ui->spbVoltCaliB->setValue(Output);
    }
    ui->txtTx->setText( txbuf.toHex(' ').toUpper());
    ui->txtRx->setText( rxbuf.toHex(' ').toUpper());
    ui->statusBar->showMessage(tr("成功读取所有数据"));
}
/* 读取设备ID */
void DAC::readDeviceID()
{
    QByteArray txbuf;
    QByteArray rxbuf;

    ui->statusBar->clearMessage();
    if(Master->readHoldingRegisters(RegDeviceID, 1, txbuf, rxbuf) == MBSerialMaster::ErrNone){
        QByteArray tmp = rxbuf.mid(3,2).toHex().toUpper();
        tmp.prepend("MD");
        ui->lblDeviceID->setText(tmp);
    }else{
        ui->statusBar->showMessage(tr("读取ID失败"));
    }
    ui->txtTx->setText( txbuf.toHex(' ').toUpper());
    ui->txtRx->setText( rxbuf.toHex(' ').toUpper());
}
/* 读取控制模式 */
void DAC::readCtrlMode()
{
    QByteArray txbuf;
    QByteArray rxbuf;
    ui->statusBar->clearMessage();
    if(Master->readHoldingRegisters(RegSys, 1, txbuf, rxbuf) == MBSerialMaster::ErrNone){
        if( 0 != rxbuf.at(4) ){
            ui->lblCtrlMode->setText("PWM");
        }else{
            ui->lblCtrlMode->setText("Modbus");
        }
        ui->statusBar->showMessage(tr("读取设备所有寄存器值"));
    }else{
        ui->statusBar->showMessage(tr("读取控制模式失败"));
    }
    ui->txtTx->setText( txbuf.toHex(' ').toUpper());
    ui->txtRx->setText( rxbuf.toHex(' ').toUpper());
}
/* 修改电压值 */
void DAC::writeOutputVolt(quint16 CHx, quint16 Volt)
{
    QByteArray txbuf;
    QByteArray rxbuf;

    ui->statusBar->clearMessage();
    if(Master->writeHoldingRegister(CHx, Volt, txbuf, rxbuf) == MBSerialMaster::ErrNone){
        ui->statusBar->showMessage(tr("成功写入"));
    }else{
        ui->statusBar->showMessage(tr("配置通道输出电压失败"));
    }
    ui->txtTx->setText( txbuf.toHex(' ').toUpper());
    ui->txtRx->setText( rxbuf.toHex(' ').toUpper());
}

/* 修改A通道输出电压值 */
void DAC::on_btnOutA_clicked()
{
    if(!currentPort->isOpen()){
        ui->statusBar->showMessage(tr("未打开串口"));
        return;
    }
    quint16 volt = (ui->spbVoltChA->value()*1000);
    this->writeOutputVolt(RegOutputA, volt);
}
/* 修改B通道输出电压值 */
void DAC::on_btnOutB_clicked()
{
    if(!currentPort->isOpen()){
        ui->statusBar->showMessage(tr("未打开串口"));
        return;
    }
    quint16 volt = (ui->spbVoltChB->value()*1000);
    this->writeOutputVolt(RegOutputB, volt);
}
/* 修改所有通道输出电压值 */
void DAC::on_btnOutAll_clicked()
{
    if(!currentPort->isOpen()){
        ui->statusBar->showMessage(tr("未打开串口"));
        return;
    }
    emit ui->btnOutA->click();
    emit ui->btnOutB->click();
}
/* 修改比例值 */
void DAC::writeCalibrationRate(quint16 CHx, quint16 Rate)
{
    QByteArray txbuf;
    QByteArray rxbuf;

    ui->statusBar->clearMessage();
    if(Master->writeHoldingRegister(CHx, Rate, txbuf, rxbuf) == MBSerialMaster::ErrNone){
        ui->statusBar->showMessage(tr("成功写入"));
    }else{
        ui->statusBar->showMessage(tr("配置通道校准比例值失败"));
    }
    ui->txtTx->setText( txbuf.toHex(' ').toUpper());
    ui->txtRx->setText( rxbuf.toHex(' ').toUpper());
}

/* 修改A通道比例值 */
void DAC::on_btnCaliA_clicked()
{
    if(!currentPort->isOpen()){
        ui->statusBar->showMessage(tr("未打开串口"));
        return;
    }
    quint16 Rate = (ui->spbVoltCaliA->value()*10000);
    writeCalibrationRate(RegCalibrationA, Rate);
}

/* 修改B通道比例值 */
void DAC::on_btnCaliB_clicked()
{
    if(!currentPort->isOpen()){
        ui->statusBar->showMessage(tr("未打开串口"));
        return;
    }
    quint16 Rate = (ui->spbVoltCaliB->value()*10000);
    writeCalibrationRate(RegCalibrationB, Rate);
}

/* 修改所有比例值 */
void DAC::on_btnCaliAll_clicked()
{
    if(!currentPort->isOpen()){
        ui->statusBar->showMessage(tr("未打开串口"));
        return;
    }
    emit ui->btnCaliA->click();
    emit ui->btnCaliB->click();
}

/* 修改从机地址 */
bool DAC::modifyDeviceAddress(quint16 newAddress)
{
    QByteArray txbuf;
    QByteArray rxbuf;
    bool ok = true;
    ui->statusBar->clearMessage();
    if(Master->writeHoldingRegister(RegCommAddress, newAddress, txbuf, rxbuf) == MBSerialMaster::ErrNone){
        ui->statusBar->showMessage(tr("成功更新从机地址,设备重启之后生效"));
        ok = true;
    }else{
        ui->statusBar->showMessage(tr("配置通道输出电压失败"));
        ok = false;
    }
    ui->txtTx->setText( txbuf.toHex(' ').toUpper());
    ui->txtRx->setText( rxbuf.toHex(' ').toUpper());
    return ok;
}

/* 修改通信参数 */
void DAC::on_btnConfig_clicked()
{
    if(!currentPort->isOpen()){
        ui->statusBar->showMessage(tr("未打开串口"));
        return;
    }
    quint16  newAddress = ui->txtNewAddr->text().toInt();

    if( 100 < newAddress )
    {
        ui->statusBar->showMessage(tr("从机地址范围是1~100,设置通信参数失败"));
        return;
    }
    if(this->modifyDeviceAddress(newAddress) == false){
        ui->statusBar->showMessage(tr("设置通信参数失败,通信错误"));
        return;
    }

    QByteArray txbuf;
    QByteArray rxbuf;
    QByteArray data;
    data[0] = 0;
    data[1] = ui->cbbNewVerify->currentIndex();
    data[2] = 0;
    data[3] = ui->cbbNewBaud->currentIndex();

    ui->statusBar->clearMessage();
    if(Master->writeHoldingRegister(RegCommVerify,data,txbuf,rxbuf) == MBSerialMaster::ErrNone){
        ui->statusBar->showMessage(tr("成功写入通信参数,重启DAC模块之后生效"));
    }else{
        ui->statusBar->showMessage(tr("配置通信参数失败,但是从机地址已经更新")); // 从机地址更新成功才能配置通信参数
    }
    ui->txtTx->setText( txbuf.toHex(' ').toUpper());
    ui->txtRx->setText( rxbuf.toHex(' ').toUpper());
}

/* 实时更新从机地址 */
void DAC::on_txtCurrentAddr_editingFinished()
{
    if(currentPort->isOpen())
        Master->setDeviceAddr(ui->txtCurrentAddr->text().toInt());
}


/* 保存文件 */
void DAC::on_actionSave_triggered()
{
    QString filePath = QFileDialog::getSaveFileName(this,"Save FIle", qApp->applicationDirPath(), "Xml(*.xml)") ;
    if(NULL != filePath ){
        QFile *file = new QFile(filePath);
        if(file->open(QIODevice::WriteOnly | QIODevice::WriteOnly)){
            QXmlStreamWriter xml(file);
            xml.setAutoFormatting(true);
            xml.writeStartDocument(); //
                xml.writeStartElement("DAC");
                    xml.writeStartElement("Communication");
                        xml.writeTextElement("Address",ui->txtCurrentAddr->text());// 从机地址
                        xml.writeTextElement("Baudrate",tr("%1").arg(ui->cbbBaud->currentIndex()));// 波特率
                        xml.writeTextElement("Verify",tr("%1").arg(ui->cbbVerify->currentIndex()));// 校验位
                    xml.writeEndElement();
                    xml.writeStartElement("New");
                        xml.writeTextElement("Address",ui->txtNewAddr->text());// 从机地址
                        xml.writeTextElement("Baudrate",tr("%1").arg(ui->cbbNewBaud->currentIndex()));// 波特率
                        xml.writeTextElement("Verify",tr("%1").arg(ui->cbbNewVerify->currentIndex()));// 校验位
                    xml.writeEndElement();
                    xml.writeStartElement("Voltage");
                        xml.writeTextElement("CHA",tr("%1").arg(ui->spbVoltChA->value()));
                        xml.writeTextElement("CHB",tr("%1").arg(ui->spbVoltChB->value()));
                    xml.writeEndElement();
                    xml.writeStartElement("Calibration");
                        xml.writeTextElement("CHA",tr("%1").arg(ui->spbVoltCaliA->value()));
                        xml.writeTextElement("CHB",tr("%1").arg(ui->spbVoltCaliB->value()));
                    xml.writeEndElement();
                xml.writeEndElement();
            xml.writeEndDocument();
            file->close();
        }
        delete file;
    }
}

/* 打开文件 */
void DAC::on_actionOpen_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this,"OpenFIle", qApp->applicationDirPath(), "Xml(*.xml)") ;
    if(NULL != filePath ){
        QFile *file = new QFile(filePath);
        if(file->open(QIODevice::ReadOnly | QIODevice::ReadOnly)){
            QXmlStreamReader xml(file);
            quint32 currentElement = 0;
            while(!xml.atEnd()){
                xml.readNextStartElement();
                QString name = xml.name().toString();
                if(name.contains("Communication")){
                    currentElement = 1; // 第一个元素
                }else if(name.contains("New")){
                    currentElement = 2; // 第二个元素
                }
                else if(name.contains("Voltage")){
                    currentElement = 3; // 第三个元素
                }else if(name.contains("Calibration")){
                    currentElement = 4; // 第四个元素
                }
                switch(currentElement){
                case 1:
                    if(name.contains("Address")){
                        ui->txtCurrentAddr->setText( xml.readElementText() );
                    }else if(name.contains("Baudrate")){
                        ui->cbbBaud->setCurrentIndex(xml.readElementText().toInt());
                    }else if(name.contains("Verify")){
                        ui->cbbVerify->setCurrentIndex(xml.readElementText().toInt());
                    }
                    break;
                case 2:
                    if(name.contains("Address")){
                        ui->txtNewAddr->setText( xml.readElementText() );
                    }else if(name.contains("Baudrate")){
                        ui->cbbNewBaud->setCurrentIndex(xml.readElementText().toInt());
                    }else if(name.contains("Verify")){
                        ui->cbbNewVerify->setCurrentIndex(xml.readElementText().toInt());
                    }
                    break;
                case 3:
                    if(name.contains("CHA")){
                        ui->spbVoltChA->setValue( xml.readElementText().toDouble() );
                    }else if(name.contains("CHB")){
                        ui->spbVoltChB->setValue( xml.readElementText().toDouble() );
                    }
                    break;
                case 4:
                    if(name.contains("CHA")){
                        ui->spbVoltCaliA->setValue( xml.readElementText().toDouble() );
                    }else if(name.contains("CHB")){
                        ui->spbVoltCaliB->setValue( xml.readElementText().toDouble() );
                    }
                    break;
                }
            }
            file->close();
        }
    }
}
/* 打开说明文档 */
void DAC::on_actionHelp_triggered()
{
    QString path = QDir::currentPath();
    path += "/helpFile.pdf";
    ui->statusBar->showMessage(tr("打开使用说明文件"));
    QDesktopServices::openUrl(QUrl::fromLocalFile(path));
}

/* 应用皮肤Fusion */
void DAC::on_actionFusion_triggered()
{
    QString styleName =ui->actionFusion->text();
    this->configStyle(styleName);
    this->saveStyle(styleName);
}
/* 应用皮肤Windows */
void DAC::on_actionWindows_triggered()
{
    QString styleName =ui->actionWindows->text();
    this->configStyle(styleName);
    this->saveStyle(styleName);

}

/* 皮肤WindowsXP */
void DAC::on_actionWindoeXP_triggered()
{
    QString styleName =ui->actionWindoeXP->text();
    this->configStyle(styleName);
    this->saveStyle(styleName);
}
/* 皮肤WindowsVista */
void DAC::on_actionWindowVista_triggered()
{
    QString styleName =ui->actionWindowVista->text();
    this->configStyle(styleName);
    this->saveStyle(styleName);
}
/* 皮肤Dark */
void DAC::on_actionDark_triggered()
{
    QString styleName =ui->actionDark->text();
    this->configStyle(styleName);
    this->saveStyle(styleName);
}

/* 皮肤BlackOrange */
void DAC::on_actionBlackO_triggered()
{
    QString styleName =ui->actionBlackO->text();
    this->configStyle(styleName);
    this->saveStyle(styleName);
}

// 设置皮肤样式
//styleName = {1.Fusion, 2.Windows,...}
void DAC::configStyle(QString styleName)
{
    qint32 index = styleName.section('.',0,0).toInt();
    QString style = styleName.section('.',1,1);
    switch(index){
    case 1:
    case 2:
    case 3:
    case 4:
        qApp->setStyleSheet(" ");
        QApplication::setStyle(QStyleFactory::create(style));//Qt自带皮肤风格 可选 Windows,WindowsXP,WindowsVista,Fusion
        return;
        break;
    default:
        QFile file(QString(":/theme/%1.css").arg(style)); //两种自定义的皮肤风格,dark和blackOrange
        if(file.exists() ){
            qApp->setStyleSheet(" ");
            file.open(QFile::ReadOnly | QFile::Text);
            QTextStream ts(&file);
            qApp->setStyleSheet(ts.readAll());
            file.close();
        }

        break;
    }
}
/* 保存为.ini文件 */
void DAC::saveStyle(QString styleName)
{
    /*  读取文件名字 */
    QSettings settings("Style.ini", QSettings::IniFormat);
    settings.beginGroup("Skins");
    settings.setValue("Style", styleName);
    settings.endGroup();
}
/* 加载.ini文件 */
QString DAC::loadStyle()
{
    QSettings settings("Style.ini", QSettings::IniFormat);
    settings.beginGroup("Skins");
    QString styleName = settings.value("Style").toString();
    return styleName;
}
/* 显示寄存器列表 */
void DAC::on_actionRegList_triggered()
{
    ui->statusBar->showMessage(tr("显示寄存器列表"));
    pDialog = new protocolDialog();
    pDialog->setAttribute(Qt::WA_DeleteOnClose); // 关闭的时候delete
    pDialog->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint | Qt::WindowMinMaxButtonsHint);// 自定义按钮
    pDialog->setWindowTitle("DAC模块寄存器列表");
    pDialog->show();

}
/* 打开Modbus协议文档 */
void DAC::on_actionModbus_triggered()
{
    QString path = QDir::currentPath();
    path += "/Modbus.pdf";
    ui->statusBar->showMessage(tr("Modbus协议"));
    QDesktopServices::openUrl(QUrl::fromLocalFile(path));
}

/**
 * @brief DAC::slots_readVolt 定时器处理函数，读取电压值
 */
void DAC::slots_readVolt()
{
    if(currentPort->isBusy()){
        return;
    }else{
        if(currentPort->isOpen() ){

            QByteArray txbuf;
            QByteArray rxbuf;
            if(Master->readHoldingRegisters(RegOutputA, 4, txbuf, rxbuf) == MBSerialMaster::ErrNone){
                quint16 deviceCHAOutput = ((quint8)(rxbuf.at(3))<<8) | (quint8)rxbuf.at(4);  // 通道A输出电压值
                double Output = (double)deviceCHAOutput/(double)1000;
                ui->spbVoltChA->setValue(Output);
                quint16 deviceCHBOutput = ((quint8)rxbuf.at(5)<<8) | (quint8)rxbuf.at(6);  // 通道A输出电压值
                Output = (double)deviceCHBOutput/(double)1000;
                ui->spbVoltChB->setValue(Output);

                quint16 deviceCHACalibration = ((quint8)rxbuf.at(7)<<8) | (quint8)rxbuf.at(8);  // 通道A输出校准比例
                Output = (double)deviceCHACalibration /(double)10000;
                ui->spbVoltCaliA->setValue(Output);

                quint16 deviceCHBCalibration = ((quint8)rxbuf.at(9)<<8) | (quint8)rxbuf.at(10);  // 通道B输出校准比例
                Output = (double)deviceCHBCalibration /(double)10000;
                ui->spbVoltCaliB->setValue(Output);
            }
            if(ui->ckbReadVolt->isChecked() && (currentPort->isOpen()) ){
                quint32 time = this->time;
                tim->singleShot(time ,this, SLOT(slots_readVolt()));
            }
        }
    }
}
/**
 * @brief DAC::on_ckbReadVolt_clicked 读取电压值
 * @param checked  checkedBox状态
 */
void DAC::on_ckbReadVolt_clicked(bool checked)
{
    if(checked){
        if(!currentPort->isOpen()){
            QMessageBox::information(this,"未打开串口","未打开串口");
            ui->ckbReadVolt->setChecked(false);
            return ;
        }
        this->time = ui->spbTime->value();
        quint32 time = this->time;
        tim->singleShot( time, this, SLOT(slots_readVolt()));

    }
}
