#include "dac.h"
#include "ui_dac.h"

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
    index = index;
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
            this->Master = new MBSerialMaster();
            this->Master->configMaster(currentPort, ui->txtCurrentAddr->text().toInt() );
            ui->btnOpenPort->setText(tr("关闭串口"));
        }else{
            ui->btnOpenPort->setChecked(false);
        }
    }
    else{
        delete this->Master;
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

/* 读设备ID */
void DAC::on_btnDeviceMsg_clicked()
{
    if(!currentPort->isOpen()){
        ui->statusBar->showMessage(tr("未打开串口"));
        return;
    }
    ui->statusBar->showMessage(tr("读取设备ID和控制模式"));
    this->readDeviceID();
    this->Delay_MSec(100);
    this->readCtrlMode();
}

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
void DAC::writeOutputVolt(quint32 CHx, quint16 Volt)
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


void DAC::on_btnOutA_clicked()
{
    if(!currentPort->isOpen()){
        ui->statusBar->showMessage(tr("未打开串口"));
        return;
    }
    quint16 volt = (ui->spbVoltChA->value()*1000);
    this->writeOutputVolt(RegOutputA, volt);
}

void DAC::on_btnOutB_clicked()
{
    if(!currentPort->isOpen()){
        ui->statusBar->showMessage(tr("未打开串口"));
        return;
    }
    quint16 volt = (ui->spbVoltChB->value()*1000);
    this->writeOutputVolt(RegOutputB, volt);
}

void DAC::on_btnOutAll_clicked()
{
    if(!currentPort->isOpen()){
        ui->statusBar->showMessage(tr("未打开串口"));
        return;
    }
    emit ui->btnOutA->click();
    emit ui->btnOutB->click();
}
void DAC::writeCalibrationRate(quint32 CHx, quint16 Rate)
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

void DAC::on_btnCaliA_clicked()
{
    if(!currentPort->isOpen()){
        ui->statusBar->showMessage(tr("未打开串口"));
        return;
    }
    quint16 Rate = (ui->spbVoltCaliA->value()*10000);
    writeCalibrationRate(RegCalibrationA, Rate);
}

void DAC::on_btnCaliB_clicked()
{
    if(!currentPort->isOpen()){
        ui->statusBar->showMessage(tr("未打开串口"));
        return;
    }
    quint16 Rate = (ui->spbVoltCaliB->value()*10000);
    writeCalibrationRate(RegCalibrationB, Rate);
}

void DAC::on_btnCaliAll_clicked()
{
    if(!currentPort->isOpen()){
        ui->statusBar->showMessage(tr("未打开串口"));
        return;
    }
    emit ui->btnCaliA->click();
    emit ui->btnCaliB->click();
}

void DAC::on_btnConfig_clicked()
{
    if(!currentPort->isOpen()){
        ui->statusBar->showMessage(tr("未打开串口"));
        return;
    }
    QByteArray txbuf;
    QByteArray rxbuf;
    QByteArray data;
    data[0] = 0;
    data[1] = ui->txtNewAddr->text().toInt();
    data[2] = 0;
    data[3] = ui->cbbNewVerify->currentIndex();
    data[4] = 0;
    data[5] = ui->cbbNewBaud->currentIndex();

    ui->statusBar->clearMessage();
    if(Master->writeHoldingRegister(RegCommAddress,data,txbuf,rxbuf) == MBSerialMaster::ErrNone){
        ui->statusBar->showMessage(tr("成功写入通信参数,重启DAC模块之后生效"));

        /* 修改新的从机地址 */
        ui->txtCurrentAddr->setText(ui->txtNewAddr->text().toLatin1());
        Master->setDeviceAddr(ui->txtCurrentAddr->text().toInt());

    }else{
        ui->statusBar->showMessage(tr("配置通信参数失败"));
    }
    ui->txtTx->setText( txbuf.toHex(' ').toUpper());
    ui->txtRx->setText( rxbuf.toHex(' ').toUpper());
}
void DAC::on_txtCurrentAddr_editingFinished()
{
    Master->setDeviceAddr(ui->txtCurrentAddr->text().toInt());
}
/* 短暂延时函数,不宜延时太长时间 */
void DAC::Delay_MSec(quint32 msec)
{
    QTime _Timer = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < _Timer )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 20);
}
//void MBSerialMaster::Delay_MSec(int mSec)
//{
//    QEventLoop loop;
//    QTimer::singleShot(mSec, &loop, SLOT(quit()));
//    loop.exec();
//}


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


