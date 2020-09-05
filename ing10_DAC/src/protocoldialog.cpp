#include "protocoldialog.h"
#include "ui_protocoldialog.h"
//#include "QAbstractItemView"

#define  BGC_RW QColor(198, 239, 206) // 读/写 背景色
#define  BGC_RO QColor(252, 213, 180) // 只读 背景色


protocolDialog::protocolDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::protocolDialog)
{
    ui->setupUi(this);
    this->setInitRegList();
    QStringList strlist;
    strlist<<"设备标志寄存器(Addr:1000(0x03E8))"<<"只读"<<"设备名称为：MD+设备ID，即MD1040。";
    this->insertTable(0x1040, strlist);
    strlist.clear();

    strlist<<"通信参数1(Addr:1001(0x03E9))"<<"可读/可写"<<"Modbus从设备地址，可设置1~100，该参数需要在复位重启之后才有效";
    this->insertTable(0x0001, strlist);
    strlist.clear();

    strlist<<"通信参数2(Addr:1002(0x03EA))"<<"只读"<<"数据长度固定为8位，串口整帧长度固定为11位（1位起始位+8位字长+校验位+停止位);   \n"
                                             "停止位根据校验位自动配置,无校验时自动为2位停止位,偶校验,奇校验时自动为1位停止位;";
    this->insertTable(0x0801, strlist, 163);
    strlist.clear();

    strlist<<"通信参数3(Addr:1003(0x03EB))"<<"可读/可写"<<"0: 无校验位,停止位自动为2位;  \n"
                                                 "1: Even偶校验,停止位自动为1位;\n"
                                                 "2: Odd奇校验,停止位自动为1位; \n"
                                                 "在复位重启之后生效";
    this->insertTable(0x0001, strlist, 203);
    strlist.clear();

    strlist<<"通信参数4(Addr:1004(0x03EC))"<<"可读/可写"<<"0:  4800;\n"
                                                 "1:  9600;\n"
                                                 "2: 19200;\n"
                                                 "3: 38400;\n"
                                                 "4: 57600;\n"
                                                 "5:115200;\n"
                                                 "6:256000;\n"
                                                 "在复位重启之后生效。";
    this->insertTable(0x0005, strlist, 283);
    strlist.clear();

    strlist<<"系统寄存器(Addr:1005(0x03ED))"<<"只读"<<"该位由\"控制模式选择\"跳帽状态决定   \n"
                                             "无跳帽:0--RS485的Modbus通信控制;  \n"
                                             "有跳帽:1--外部输入PWM信号占空比控制;\n"
                                             "(PWM频率在1KHz~36Khz之间,占空比从0~100%线性对应0~10V)";
    this->insertTable(0x0000, strlist, 203);
    strlist.clear();

    strlist<<"输出通道A(Addr:1006(0x03EE))"<<"可读/可写"<<"输出电压值,单位:mV,取值范围为:0~10000,对应0~10V.例:该寄存器值为6345,实际目标电压为6.345V\n"
                                                 "(PWM模式:只读)";
    this->insertTable(0x0000, strlist, 163);
    strlist.clear();

    strlist<<"输出通道B(Addr:1007(0x03EF))"<<"可读/可写"<<"输出电压值,单位:mV,取值范围为:0~10000,对应0~10V.例:该寄存器值为6345,实际目标电压为6.345V\n"
                                                 "(PWM模式:只读)";
    this->insertTable(0x0000, strlist, 163);
    strlist.clear();

    strlist<<"校准通道A(Addr:1008(0x03F0))"<<"可读/可写"<<"输出电压值=目标值*校准比例值/10000;\n"
                                                 "校准比例值取值范围:9000~11000.因为设备使用了运算放大器,放大倍数由电阻阻值决定,\n"
                                                 "为了消除运放带来的放大倍数偏差影响,这里设置这个校准比例值,以10000代表1倍,9000代表0.9倍";
    this->insertTable(0x2710, strlist, 183);
    strlist.clear();

    strlist<<"校准通道B(Addr:1009(0x03F1))"<<"可读/可写"<<"输出电压值=目标值*校准比例值/10000;\n"
                                                 "校准比例值取值范围:9000~11000.因为设备使用了运算放大器,放大倍数由电阻阻值决定,\n"
                                                 "为了消除运放带来的放大倍数偏差影响,这里设置这个校准比例值,以10000代表1倍,9000代表0.9倍";
    this->insertTable(0x2710, strlist, 183);
    strlist.clear();

    ui->scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
}

protocolDialog::~protocolDialog()
{
    delete ui;
}

void protocolDialog::setInitRegList()
{
    ui->lbiregList->setStyleSheet("background-color : rgb(188, 220, 244);color:black;");//
    // 设置列宽
    ui->tabRegList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch );// 自适应列宽
    ui->tabRegList->horizontalHeader()->setSectionResizeMode(0,QHeaderView::ResizeToContents );// 适应单元格内容
    ui->tabRegList->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents );// 适应单元格内容
    ui->tabRegList->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tabRegList->setEditTriggers(QAbstractItemView::NoEditTriggers);


    /* 设备标志寄存器 */
    ui->tabRegList->setSpan(0,2,1,16);
    QTableWidgetItem *newItem = new QTableWidgetItem();
    ui->tabRegList->setItem(0,2,newItem);
    newItem->setText("设备ID");
    newItem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    newItem->setBackgroundColor( BGC_RO );
//    QFont font ;//
//    font.setBold(true);  //设置粗体
//    newItem->setFont(font);
    newItem->setTextColor( Qt::black );// 字体颜色
//    newItem->font().setBold(true);

    /* 通信参数1 */
    ui->tabRegList->setSpan(1,2,1,8); // 参数(行/列坐标,行数,列数)
    ui->tabRegList->setSpan(1,10,1,8);
    newItem = new QTableWidgetItem();
    ui->tabRegList->setItem(1,10,newItem);
    newItem->setText("Modbus从设备地址");
    newItem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    newItem->setBackgroundColor( BGC_RW );// 读/写背景色
    newItem->setTextColor( Qt::black );


    /* 通信参数2 */
    ui->tabRegList->setSpan(2,2,1,4);  // 参数(行/列坐标,行数,列数)
    ui->tabRegList->setSpan(2,6,1,4);
    ui->tabRegList->setSpan(2,10,1,6);
    ui->tabRegList->setSpan(2,16,1,2);

    newItem = new QTableWidgetItem();
    ui->tabRegList->setItem(2,6,newItem);
    newItem->setText("数据长度");
    newItem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    newItem->setBackgroundColor( BGC_RO );
    newItem->setTextColor( Qt::black );


    newItem = new QTableWidgetItem();
    ui->tabRegList->setItem(2,16,newItem);
    newItem->setText("停止位");
    newItem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    newItem->setBackgroundColor( BGC_RO );
    newItem->setTextColor( Qt::black );


    /* 通信参数3 */
    ui->tabRegList->setSpan(3,2,1,14);
    ui->tabRegList->setSpan(3,16,1,2);
    newItem = new QTableWidgetItem();
    ui->tabRegList->setItem(3,16,newItem);
    newItem->setText("校验位");
    newItem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    newItem->setBackgroundColor( BGC_RW );// 读/写背景色
    newItem->setTextColor( Qt::black );


    /* 通信参数4 */
    ui->tabRegList->setSpan(4,2,1,13);
    ui->tabRegList->setSpan(4,15,1,3);
    newItem = new QTableWidgetItem();
    ui->tabRegList->setItem(4,15,newItem);
    newItem->setText("波特率");
    newItem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    newItem->setBackgroundColor( BGC_RW );// 读/写背景色
    newItem->setTextColor( Qt::black );


    /* 系统寄存器 */
    ui->tabRegList->setSpan(5,2,1,15);
    newItem = new QTableWidgetItem();
    ui->tabRegList->setItem(5,17,newItem);
    newItem->setText("模式");
    newItem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    newItem->setBackgroundColor( BGC_RO );
    newItem->setTextColor( Qt::black );


    /* 输出通道A */
    ui->tabRegList->setSpan(6,2,1,16);
    newItem = new QTableWidgetItem();
    ui->tabRegList->setItem(6,2,newItem);
    newItem->setText("通道A电压");
    newItem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    newItem->setBackgroundColor( BGC_RW );
    newItem->setTextColor( Qt::black );


    /* 输出通道B */
    ui->tabRegList->setSpan(7,2,1,16);
    newItem = new QTableWidgetItem();
    ui->tabRegList->setItem(7,2,newItem);
    newItem->setText("通道B电压");
    newItem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    newItem->setBackgroundColor( BGC_RW );
    newItem->setTextColor( Qt::black );


    /* 通道A校准比例值 */
    ui->tabRegList->setSpan(8,2,1,16);
    newItem = new QTableWidgetItem();
    ui->tabRegList->setItem(8,2,newItem);
    newItem->setText("通道A校准比例值");
    newItem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    newItem->setBackgroundColor( BGC_RW );
    newItem->setTextColor( Qt::black );


    /* 通道B校准比例值 */
    ui->tabRegList->setSpan(9,2,1,16);
    newItem = new QTableWidgetItem();
    ui->tabRegList->setItem(9,2,newItem);
    newItem->setText("通道B校准比例值");
    newItem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    newItem->setBackgroundColor( BGC_RW );
    newItem->setTextColor( Qt::black );
}

void protocolDialog::insertTable(quint16 data, QStringList discription,quint16 lastHeight)
{
    /* 标题 */
    QLabel *newLabel = new QLabel(discription.at(0));
    newLabel->setStyleSheet("background-color : rgb(188, 220, 244);color:black;");//
    ui->scrollAreaWidgetContents->layout()->addWidget(newLabel);
    QFont font ;
    font.setPointSize(15);
    newLabel->setFont(font);

    /* 表格 */
    QTableWidget *regTable = new QTableWidget(4,16);
    QStringList header ;
    for(qint32 i=15; i>=0; i--){
        header<<tr("%1").arg(i);
    }
    regTable->setHorizontalHeaderLabels(header);
    header.clear();
    header<<"bit"<<"读写属性"<<"默认值"<<"说明";
    regTable->setVerticalHeaderLabels(header);
    regTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    regTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch );// 自适应列宽
    regTable->verticalHeader()->setSectionResizeMode(3,QHeaderView::Stretch);// 适应行高

    regTable->setSpan(1,0,1,16);
    regTable->setSpan(2,0,1,16);
    regTable->setSpan(3,0,1,16);

    // 第一行 位默认值
    quint16 j = 0;
    QTableWidgetItem *regBitItem ;
    for(qint32 i=0; i<16; i++){
        regBitItem = new QTableWidgetItem();
        j = (data&(0x0001<<i)) >> i;
        regBitItem->setText(QString::number(j,10));
        regTable->setItem(0,15-i,regBitItem);
        regBitItem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        regBitItem->setTextColor( Qt::black );
    }

    // 第二行 读写属性
    regBitItem = new QTableWidgetItem();
    regBitItem->setText(discription.at(1));
    regBitItem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    regBitItem->setTextColor( Qt::black );
    regTable->setItem(1, 0, regBitItem);

    // 第三行 默认值
    regBitItem = new QTableWidgetItem();
    QString tmpStr = QString("0x%1").arg(data,4,16,QLatin1Char('0'));
    regBitItem->setText(tmpStr);
    regBitItem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    regTable->setItem(2, 0, regBitItem);
    regBitItem->setTextColor( Qt::black );

    // 第三行 说明
    regBitItem = new QTableWidgetItem();
    regBitItem->setText(discription.at(2));
    regBitItem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    regBitItem->setTextColor( Qt::black );
    regTable->setItem(3, 0, regBitItem);
    regTable->setMaximumHeight(lastHeight);
    regTable->setMinimumHeight(lastHeight);
    ui->scrollAreaWidgetContents->layout()->addWidget(regTable);
}
