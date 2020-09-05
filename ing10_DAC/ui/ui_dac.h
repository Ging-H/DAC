/********************************************************************************
** Form generated from reading UI file 'dac.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAC_H
#define UI_DAC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DAC
{
public:
    QAction *actionSave;
    QAction *actionOpen;
    QAction *actionHelp;
    QAction *actionWindows;
    QAction *actionWindoeXP;
    QAction *actionWindowVista;
    QAction *actionFusion;
    QAction *actionDark;
    QAction *actionBlackO;
    QAction *actionModbus;
    QAction *actionRegList;
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_11;
    QGroupBox *QGBSerialConfig;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_3;
    QLabel *lblVerify;
    QComboBox *cbbDataBit;
    QLabel *lblPortNum;
    QLabel *lblStopBit;
    QLabel *lblBaudRate;
    QComboBox *cbbPortNum;
    QComboBox *cbbVerify;
    QComboBox *cbbStopBit;
    QComboBox *cbbBaud;
    QLabel *lblDataBit;
    QPushButton *btnRefresh;
    QPushButton *btnOpenPort;
    QLabel *lblCurrentAddr;
    QLineEdit *txtCurrentAddr;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_8;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblDeviceAddr;
    QLabel *lblBaudRate_2;
    QLabel *lblVerify_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *txtNewAddr;
    QComboBox *cbbNewBaud;
    QComboBox *cbbNewVerify;
    QPushButton *btnConfig;
    QGroupBox *groupBox_7;
    QGridLayout *gridLayout_6;
    QLabel *label_3;
    QLineEdit *txtTx;
    QLabel *label_4;
    QLineEdit *txtRx;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_5;
    QPushButton *btnDeviceMsg;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *lblDeviceID;
    QLabel *label_2;
    QLabel *lblCtrlMode;
    QSpinBox *spbTime;
    QLabel *label_5;
    QCheckBox *ckbReadVolt;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_10;
    QVBoxLayout *verticalLayout_10;
    QPushButton *btnCaliA;
    QPushButton *btnCaliB;
    QVBoxLayout *verticalLayout_9;
    QDoubleSpinBox *spbVoltCaliA;
    QDoubleSpinBox *spbVoltCaliB;
    QPushButton *btnCaliAll;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_9;
    QVBoxLayout *verticalLayout_6;
    QPushButton *btnOutA;
    QPushButton *btnOutB;
    QVBoxLayout *verticalLayout_5;
    QDoubleSpinBox *spbVoltChA;
    QDoubleSpinBox *spbVoltChB;
    QPushButton *btnOutAll;
    QSpacerItem *verticalSpacer_2;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFiles;
    QMenu *menuHelp;
    QMenu *style;
    QMenu *menu;

    void setupUi(QMainWindow *DAC)
    {
        if (DAC->objectName().isEmpty())
            DAC->setObjectName(QStringLiteral("DAC"));
        DAC->resize(534, 636);
        DAC->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(9);
        DAC->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/general/general/ing10.ico"), QSize(), QIcon::Normal, QIcon::Off);
        DAC->setWindowIcon(icon);
        DAC->setToolButtonStyle(Qt::ToolButtonIconOnly);
        actionSave = new QAction(DAC);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/action/action/filesave.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon1);
        actionOpen = new QAction(DAC);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/action/action/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon2);
        actionHelp = new QAction(DAC);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/general/general/pdf-icon-27.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon3);
        actionWindows = new QAction(DAC);
        actionWindows->setObjectName(QStringLiteral("actionWindows"));
        actionWindoeXP = new QAction(DAC);
        actionWindoeXP->setObjectName(QStringLiteral("actionWindoeXP"));
        actionWindowVista = new QAction(DAC);
        actionWindowVista->setObjectName(QStringLiteral("actionWindowVista"));
        actionFusion = new QAction(DAC);
        actionFusion->setObjectName(QStringLiteral("actionFusion"));
        actionDark = new QAction(DAC);
        actionDark->setObjectName(QStringLiteral("actionDark"));
        actionBlackO = new QAction(DAC);
        actionBlackO->setObjectName(QStringLiteral("actionBlackO"));
        actionModbus = new QAction(DAC);
        actionModbus->setObjectName(QStringLiteral("actionModbus"));
        actionModbus->setIcon(icon3);
        actionRegList = new QAction(DAC);
        actionRegList->setObjectName(QStringLiteral("actionRegList"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/general/general/\345\215\217\350\256\256.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRegList->setIcon(icon4);
        centralWidget = new QWidget(DAC);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer, 2, 2, 1, 1);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_11 = new QGridLayout(groupBox_4);
        gridLayout_11->setSpacing(2);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_11->setContentsMargins(3, 3, 3, 3);
        QGBSerialConfig = new QGroupBox(groupBox_4);
        QGBSerialConfig->setObjectName(QStringLiteral("QGBSerialConfig"));
        QGBSerialConfig->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QGBSerialConfig->sizePolicy().hasHeightForWidth());
        QGBSerialConfig->setSizePolicy(sizePolicy);
        QGBSerialConfig->setMinimumSize(QSize(171, 231));
        QGBSerialConfig->setMaximumSize(QSize(171, 231));
        QGBSerialConfig->setStyleSheet(QStringLiteral(""));
        QGBSerialConfig->setFlat(false);
        QGBSerialConfig->setCheckable(false);
        gridLayout_7 = new QGridLayout(QGBSerialConfig);
        gridLayout_7->setSpacing(2);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        gridLayout_7->setContentsMargins(3, 3, 3, 3);
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        lblVerify = new QLabel(QGBSerialConfig);
        lblVerify->setObjectName(QStringLiteral("lblVerify"));

        gridLayout_3->addWidget(lblVerify, 3, 0, 1, 1);

        cbbDataBit = new QComboBox(QGBSerialConfig);
        cbbDataBit->setObjectName(QStringLiteral("cbbDataBit"));
        QFont font1;
        font1.setPointSize(10);
        cbbDataBit->setFont(font1);
        cbbDataBit->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbDataBit, 2, 1, 1, 1);

        lblPortNum = new QLabel(QGBSerialConfig);
        lblPortNum->setObjectName(QStringLiteral("lblPortNum"));

        gridLayout_3->addWidget(lblPortNum, 0, 0, 1, 1);

        lblStopBit = new QLabel(QGBSerialConfig);
        lblStopBit->setObjectName(QStringLiteral("lblStopBit"));

        gridLayout_3->addWidget(lblStopBit, 4, 0, 1, 1);

        lblBaudRate = new QLabel(QGBSerialConfig);
        lblBaudRate->setObjectName(QStringLiteral("lblBaudRate"));

        gridLayout_3->addWidget(lblBaudRate, 1, 0, 1, 1);

        cbbPortNum = new QComboBox(QGBSerialConfig);
        cbbPortNum->setObjectName(QStringLiteral("cbbPortNum"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cbbPortNum->sizePolicy().hasHeightForWidth());
        cbbPortNum->setSizePolicy(sizePolicy1);
        cbbPortNum->setFont(font1);
        cbbPortNum->setMaxVisibleItems(20);
        cbbPortNum->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        cbbPortNum->setMinimumContentsLength(0);

        gridLayout_3->addWidget(cbbPortNum, 0, 1, 1, 1);

        cbbVerify = new QComboBox(QGBSerialConfig);
        cbbVerify->setObjectName(QStringLiteral("cbbVerify"));
        cbbVerify->setFont(font1);
        cbbVerify->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbVerify, 3, 1, 1, 1);

        cbbStopBit = new QComboBox(QGBSerialConfig);
        cbbStopBit->setObjectName(QStringLiteral("cbbStopBit"));
        cbbStopBit->setEnabled(false);
        cbbStopBit->setFont(font1);
        cbbStopBit->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbStopBit, 4, 1, 1, 1);

        cbbBaud = new QComboBox(QGBSerialConfig);
        cbbBaud->setObjectName(QStringLiteral("cbbBaud"));
        cbbBaud->setFont(font1);
        cbbBaud->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        gridLayout_3->addWidget(cbbBaud, 1, 1, 1, 1);

        lblDataBit = new QLabel(QGBSerialConfig);
        lblDataBit->setObjectName(QStringLiteral("lblDataBit"));

        gridLayout_3->addWidget(lblDataBit, 2, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_3, 0, 0, 1, 3);

        btnRefresh = new QPushButton(QGBSerialConfig);
        btnRefresh->setObjectName(QStringLiteral("btnRefresh"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnRefresh->sizePolicy().hasHeightForWidth());
        btnRefresh->setSizePolicy(sizePolicy2);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/action/action/reload.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnRefresh->setIcon(icon5);
        btnRefresh->setIconSize(QSize(20, 20));

        gridLayout_7->addWidget(btnRefresh, 1, 0, 1, 2);

        btnOpenPort = new QPushButton(QGBSerialConfig);
        btnOpenPort->setObjectName(QStringLiteral("btnOpenPort"));
        btnOpenPort->setEnabled(true);
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(2);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btnOpenPort->sizePolicy().hasHeightForWidth());
        btnOpenPort->setSizePolicy(sizePolicy3);
        btnOpenPort->setStyleSheet(QStringLiteral(""));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/action/action/centrejust.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon6.addFile(QStringLiteral(":/action/action/process-stop.png"), QSize(), QIcon::Normal, QIcon::On);
        btnOpenPort->setIcon(icon6);
        btnOpenPort->setIconSize(QSize(18, 18));
        btnOpenPort->setCheckable(true);
        btnOpenPort->setChecked(false);
        btnOpenPort->setAutoDefault(false);
        btnOpenPort->setFlat(false);

        gridLayout_7->addWidget(btnOpenPort, 1, 2, 1, 1);

        lblCurrentAddr = new QLabel(QGBSerialConfig);
        lblCurrentAddr->setObjectName(QStringLiteral("lblCurrentAddr"));
        lblCurrentAddr->setFont(font);

        gridLayout_7->addWidget(lblCurrentAddr, 2, 0, 1, 1);

        txtCurrentAddr = new QLineEdit(QGBSerialConfig);
        txtCurrentAddr->setObjectName(QStringLiteral("txtCurrentAddr"));

        gridLayout_7->addWidget(txtCurrentAddr, 2, 1, 1, 2);


        gridLayout_11->addWidget(QGBSerialConfig, 0, 0, 1, 1);

        groupBox = new QGroupBox(groupBox_4);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(171, 161));
        groupBox->setMaximumSize(QSize(171, 161));
        groupBox->setSizeIncrement(QSize(0, 0));
        groupBox->setFont(font);
        gridLayout_8 = new QGridLayout(groupBox);
        gridLayout_8->setSpacing(2);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(3, 3, 3, 3);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lblDeviceAddr = new QLabel(groupBox);
        lblDeviceAddr->setObjectName(QStringLiteral("lblDeviceAddr"));
        lblDeviceAddr->setFont(font);

        verticalLayout_2->addWidget(lblDeviceAddr);

        lblBaudRate_2 = new QLabel(groupBox);
        lblBaudRate_2->setObjectName(QStringLiteral("lblBaudRate_2"));
        lblBaudRate_2->setFont(font);

        verticalLayout_2->addWidget(lblBaudRate_2);

        lblVerify_2 = new QLabel(groupBox);
        lblVerify_2->setObjectName(QStringLiteral("lblVerify_2"));
        lblVerify_2->setFont(font);

        verticalLayout_2->addWidget(lblVerify_2);


        gridLayout_8->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        txtNewAddr = new QLineEdit(groupBox);
        txtNewAddr->setObjectName(QStringLiteral("txtNewAddr"));

        verticalLayout->addWidget(txtNewAddr);

        cbbNewBaud = new QComboBox(groupBox);
        cbbNewBaud->setObjectName(QStringLiteral("cbbNewBaud"));
        cbbNewBaud->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        verticalLayout->addWidget(cbbNewBaud);

        cbbNewVerify = new QComboBox(groupBox);
        cbbNewVerify->setObjectName(QStringLiteral("cbbNewVerify"));
        cbbNewVerify->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        verticalLayout->addWidget(cbbNewVerify);


        gridLayout_8->addLayout(verticalLayout, 0, 1, 1, 1);

        btnConfig = new QPushButton(groupBox);
        btnConfig->setObjectName(QStringLiteral("btnConfig"));
        QFont font2;
        font2.setPointSize(11);
        btnConfig->setFont(font2);

        gridLayout_8->addWidget(btnConfig, 1, 0, 1, 2);

        btnConfig->raise();

        gridLayout_11->addWidget(groupBox, 1, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_4, 0, 0, 3, 1);

        groupBox_7 = new QGroupBox(centralWidget);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setMinimumSize(QSize(0, 0));
        groupBox_7->setMaximumSize(QSize(16777215, 83));
        gridLayout_6 = new QGridLayout(groupBox_7);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(6, 6, -1, 6);
        label_3 = new QLabel(groupBox_7);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout_6->addWidget(label_3, 0, 0, 1, 1);

        txtTx = new QLineEdit(groupBox_7);
        txtTx->setObjectName(QStringLiteral("txtTx"));
        txtTx->setFont(font1);

        gridLayout_6->addWidget(txtTx, 0, 1, 1, 1);

        label_4 = new QLabel(groupBox_7);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        gridLayout_6->addWidget(label_4, 1, 0, 1, 1);

        txtRx = new QLineEdit(groupBox_7);
        txtRx->setObjectName(QStringLiteral("txtRx"));
        txtRx->setFont(font1);

        gridLayout_6->addWidget(txtRx, 1, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_7, 4, 0, 1, 2);

        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        gridLayout_5 = new QGridLayout(groupBox_6);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        btnDeviceMsg = new QPushButton(groupBox_6);
        btnDeviceMsg->setObjectName(QStringLiteral("btnDeviceMsg"));
        btnDeviceMsg->setFont(font1);

        gridLayout_5->addWidget(btnDeviceMsg, 0, 2, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(groupBox_6);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        lblDeviceID = new QLabel(groupBox_6);
        lblDeviceID->setObjectName(QStringLiteral("lblDeviceID"));
        lblDeviceID->setFont(font2);

        gridLayout_2->addWidget(lblDeviceID, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox_6);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        lblCtrlMode = new QLabel(groupBox_6);
        lblCtrlMode->setObjectName(QStringLiteral("lblCtrlMode"));
        lblCtrlMode->setFont(font2);

        gridLayout_2->addWidget(lblCtrlMode, 1, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 0, 0, 1, 2);

        spbTime = new QSpinBox(groupBox_6);
        spbTime->setObjectName(QStringLiteral("spbTime"));
        spbTime->setMinimum(200);
        spbTime->setMaximum(10000);
        spbTime->setSingleStep(200);

        gridLayout_5->addWidget(spbTime, 2, 1, 1, 1);

        label_5 = new QLabel(groupBox_6);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout_5->addWidget(label_5, 2, 2, 1, 1);

        ckbReadVolt = new QCheckBox(groupBox_6);
        ckbReadVolt->setObjectName(QStringLiteral("ckbReadVolt"));

        gridLayout_5->addWidget(ckbReadVolt, 2, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_6, 0, 1, 1, 1);

        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        gridLayout = new QGridLayout(groupBox_5);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        groupBox_3 = new QGroupBox(groupBox_5);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setMinimumSize(QSize(301, 161));
        groupBox_3->setMaximumSize(QSize(301, 161));
        gridLayout_10 = new QGridLayout(groupBox_3);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(4);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        btnCaliA = new QPushButton(groupBox_3);
        btnCaliA->setObjectName(QStringLiteral("btnCaliA"));
        QFont font3;
        font3.setPointSize(13);
        btnCaliA->setFont(font3);

        verticalLayout_10->addWidget(btnCaliA);

        btnCaliB = new QPushButton(groupBox_3);
        btnCaliB->setObjectName(QStringLiteral("btnCaliB"));
        btnCaliB->setFont(font3);

        verticalLayout_10->addWidget(btnCaliB);


        gridLayout_10->addLayout(verticalLayout_10, 0, 0, 1, 1);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(4);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        spbVoltCaliA = new QDoubleSpinBox(groupBox_3);
        spbVoltCaliA->setObjectName(QStringLiteral("spbVoltCaliA"));
        QFont font4;
        font4.setPointSize(17);
        spbVoltCaliA->setFont(font4);
        spbVoltCaliA->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spbVoltCaliA->setDecimals(4);
        spbVoltCaliA->setMinimum(0.9);
        spbVoltCaliA->setMaximum(1.1);
        spbVoltCaliA->setSingleStep(0.0001);
        spbVoltCaliA->setValue(1);

        verticalLayout_9->addWidget(spbVoltCaliA);

        spbVoltCaliB = new QDoubleSpinBox(groupBox_3);
        spbVoltCaliB->setObjectName(QStringLiteral("spbVoltCaliB"));
        spbVoltCaliB->setFont(font4);
        spbVoltCaliB->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spbVoltCaliB->setDecimals(4);
        spbVoltCaliB->setMinimum(0.9);
        spbVoltCaliB->setMaximum(1.1);
        spbVoltCaliB->setSingleStep(0.0001);
        spbVoltCaliB->setValue(1);

        verticalLayout_9->addWidget(spbVoltCaliB);


        gridLayout_10->addLayout(verticalLayout_9, 0, 1, 1, 1);

        btnCaliAll = new QPushButton(groupBox_3);
        btnCaliAll->setObjectName(QStringLiteral("btnCaliAll"));
        btnCaliAll->setFont(font3);

        gridLayout_10->addWidget(btnCaliAll, 1, 0, 1, 2);


        gridLayout->addWidget(groupBox_3, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(groupBox_5);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(301, 161));
        groupBox_2->setMaximumSize(QSize(301, 161));
        gridLayout_9 = new QGridLayout(groupBox_2);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(4);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        btnOutA = new QPushButton(groupBox_2);
        btnOutA->setObjectName(QStringLiteral("btnOutA"));
        btnOutA->setFont(font3);

        verticalLayout_6->addWidget(btnOutA);

        btnOutB = new QPushButton(groupBox_2);
        btnOutB->setObjectName(QStringLiteral("btnOutB"));
        btnOutB->setFont(font3);

        verticalLayout_6->addWidget(btnOutB);


        gridLayout_9->addLayout(verticalLayout_6, 0, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(4);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        spbVoltChA = new QDoubleSpinBox(groupBox_2);
        spbVoltChA->setObjectName(QStringLiteral("spbVoltChA"));
        spbVoltChA->setFont(font4);
        spbVoltChA->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spbVoltChA->setDecimals(3);
        spbVoltChA->setMaximum(10);
        spbVoltChA->setSingleStep(0.001);

        verticalLayout_5->addWidget(spbVoltChA);

        spbVoltChB = new QDoubleSpinBox(groupBox_2);
        spbVoltChB->setObjectName(QStringLiteral("spbVoltChB"));
        spbVoltChB->setFont(font4);
        spbVoltChB->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spbVoltChB->setDecimals(3);
        spbVoltChB->setMaximum(10);
        spbVoltChB->setSingleStep(0.001);

        verticalLayout_5->addWidget(spbVoltChB);


        gridLayout_9->addLayout(verticalLayout_5, 0, 1, 1, 1);

        btnOutAll = new QPushButton(groupBox_2);
        btnOutAll->setObjectName(QStringLiteral("btnOutAll"));
        btnOutAll->setFont(font3);

        gridLayout_9->addWidget(btnOutAll, 1, 0, 1, 2);


        gridLayout->addWidget(groupBox_2, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_5, 2, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_2, 5, 0, 1, 1);

        DAC->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DAC);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DAC->setStatusBar(statusBar);
        menuBar = new QMenuBar(DAC);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 534, 22));
        menuFiles = new QMenu(menuBar);
        menuFiles->setObjectName(QStringLiteral("menuFiles"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        style = new QMenu(menuHelp);
        style->setObjectName(QStringLiteral("style"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/general/general/\351\243\216\346\240\274.png"), QSize(), QIcon::Normal, QIcon::Off);
        style->setIcon(icon7);
        menu = new QMenu(menuHelp);
        menu->setObjectName(QStringLiteral("menu"));
        menu->setIcon(icon4);
        DAC->setMenuBar(menuBar);
        QWidget::setTabOrder(cbbPortNum, cbbBaud);
        QWidget::setTabOrder(cbbBaud, cbbDataBit);
        QWidget::setTabOrder(cbbDataBit, cbbVerify);
        QWidget::setTabOrder(cbbVerify, cbbStopBit);
        QWidget::setTabOrder(cbbStopBit, btnRefresh);
        QWidget::setTabOrder(btnRefresh, btnOpenPort);
        QWidget::setTabOrder(btnOpenPort, txtCurrentAddr);
        QWidget::setTabOrder(txtCurrentAddr, txtNewAddr);
        QWidget::setTabOrder(txtNewAddr, cbbNewBaud);
        QWidget::setTabOrder(cbbNewBaud, cbbNewVerify);
        QWidget::setTabOrder(cbbNewVerify, btnConfig);
        QWidget::setTabOrder(btnConfig, btnOutA);
        QWidget::setTabOrder(btnOutA, spbVoltChA);
        QWidget::setTabOrder(spbVoltChA, btnOutB);
        QWidget::setTabOrder(btnOutB, spbVoltChB);
        QWidget::setTabOrder(spbVoltChB, btnOutAll);
        QWidget::setTabOrder(btnOutAll, btnCaliA);
        QWidget::setTabOrder(btnCaliA, spbVoltCaliA);
        QWidget::setTabOrder(spbVoltCaliA, btnCaliB);
        QWidget::setTabOrder(btnCaliB, spbVoltCaliB);
        QWidget::setTabOrder(spbVoltCaliB, btnCaliAll);
        QWidget::setTabOrder(btnCaliAll, txtTx);
        QWidget::setTabOrder(txtTx, txtRx);

        menuBar->addAction(menuFiles->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFiles->addAction(actionOpen);
        menuFiles->addAction(actionSave);
        menuHelp->addAction(menu->menuAction());
        menuHelp->addAction(actionHelp);
        menuHelp->addSeparator();
        menuHelp->addAction(style->menuAction());
        style->addAction(actionFusion);
        style->addAction(actionWindows);
        style->addAction(actionWindoeXP);
        style->addAction(actionWindowVista);
        style->addAction(actionDark);
        style->addAction(actionBlackO);
        menu->addAction(actionModbus);
        menu->addAction(actionRegList);

        retranslateUi(DAC);

        btnOpenPort->setDefault(false);


        QMetaObject::connectSlotsByName(DAC);
    } // setupUi

    void retranslateUi(QMainWindow *DAC)
    {
        DAC->setWindowTitle(QApplication::translate("DAC", "DAC", Q_NULLPTR));
        actionSave->setText(QApplication::translate("DAC", "Save", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("DAC", "Ctrl+S", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("DAC", "Open", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("DAC", "Alt+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionHelp->setText(QApplication::translate("DAC", "\344\275\277\347\224\250\350\257\264\346\230\216.pdf", Q_NULLPTR));
        actionWindows->setText(QApplication::translate("DAC", "2.Windows", Q_NULLPTR));
        actionWindoeXP->setText(QApplication::translate("DAC", "3.WindowsXP", Q_NULLPTR));
        actionWindowVista->setText(QApplication::translate("DAC", "4.WindowsVista", Q_NULLPTR));
        actionFusion->setText(QApplication::translate("DAC", "1.Fusion", Q_NULLPTR));
        actionDark->setText(QApplication::translate("DAC", "5.dark", Q_NULLPTR));
        actionBlackO->setText(QApplication::translate("DAC", "6.blackOrange", Q_NULLPTR));
        actionModbus->setText(QApplication::translate("DAC", "Modbus\345\215\217\350\256\256", Q_NULLPTR));
        actionRegList->setText(QApplication::translate("DAC", "\345\257\204\345\255\230\345\231\250\345\210\227\350\241\250", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("DAC", "\351\200\232\344\277\241\346\216\247\345\210\266", Q_NULLPTR));
        QGBSerialConfig->setTitle(QApplication::translate("DAC", "\344\270\262\345\217\243\350\256\276\347\275\256", Q_NULLPTR));
        lblVerify->setText(QApplication::translate("DAC", "\346\240\241\351\252\214", Q_NULLPTR));
        lblPortNum->setText(QApplication::translate("DAC", "\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
        lblStopBit->setText(QApplication::translate("DAC", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        lblBaudRate->setText(QApplication::translate("DAC", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        lblDataBit->setText(QApplication::translate("DAC", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        btnRefresh->setToolTip(QApplication::translate("DAC", "\345\210\267\346\226\260\347\253\257\345\217\243\345\217\267", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        btnRefresh->setText(QApplication::translate("DAC", "\345\210\267\346\226\260", Q_NULLPTR));
        btnOpenPort->setText(QApplication::translate("DAC", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        lblCurrentAddr->setText(QApplication::translate("DAC", "\344\273\216\345\234\260\345\235\200", Q_NULLPTR));
        txtCurrentAddr->setText(QApplication::translate("DAC", "01", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("DAC", "\351\200\232\344\277\241\345\217\202\346\225\260\350\256\276\347\275\256", Q_NULLPTR));
        lblDeviceAddr->setText(QApplication::translate("DAC", "\344\273\216\345\234\260\345\235\200", Q_NULLPTR));
        lblBaudRate_2->setText(QApplication::translate("DAC", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        lblVerify_2->setText(QApplication::translate("DAC", "\346\240\241\351\252\214", Q_NULLPTR));
        txtNewAddr->setText(QApplication::translate("DAC", "01", Q_NULLPTR));
        btnConfig->setText(QApplication::translate("DAC", "Config", Q_NULLPTR));
        groupBox_7->setTitle(QApplication::translate("DAC", "\351\200\232\344\277\241\346\225\260\346\215\256", Q_NULLPTR));
        label_3->setText(QApplication::translate("DAC", "Tx:", Q_NULLPTR));
        label_4->setText(QApplication::translate("DAC", "Rx:", Q_NULLPTR));
        groupBox_6->setTitle(QApplication::translate("DAC", "\350\256\276\345\244\207\344\277\241\346\201\257", Q_NULLPTR));
        btnDeviceMsg->setText(QApplication::translate("DAC", "\350\256\276\345\244\207\344\277\241\346\201\257", Q_NULLPTR));
        label->setText(QApplication::translate("DAC", "\350\256\276\345\244\207ID:", Q_NULLPTR));
        lblDeviceID->setText(QString());
        label_2->setText(QApplication::translate("DAC", "\346\216\247\345\210\266\346\250\241\345\274\217\357\274\232", Q_NULLPTR));
        lblCtrlMode->setText(QString());
        label_5->setText(QApplication::translate("DAC", "ms", Q_NULLPTR));
        ckbReadVolt->setText(QApplication::translate("DAC", "\345\256\232\346\227\266\350\257\273\345\217\226\346\225\260\346\215\256", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("DAC", "\350\276\223\345\207\272\346\216\247\345\210\266", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("DAC", "\346\240\241\345\207\206\346\257\224\344\276\213", Q_NULLPTR));
        btnCaliA->setText(QApplication::translate("DAC", "CHA", Q_NULLPTR));
        btnCaliB->setText(QApplication::translate("DAC", "CHB", Q_NULLPTR));
        spbVoltCaliA->setPrefix(QString());
        spbVoltCaliA->setSuffix(QString());
        spbVoltCaliB->setPrefix(QString());
        spbVoltCaliB->setSuffix(QString());
        btnCaliAll->setText(QApplication::translate("DAC", "ALL", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("DAC", "\350\276\223\345\207\272\347\224\265\345\216\213\345\200\274", Q_NULLPTR));
        btnOutA->setText(QApplication::translate("DAC", "CHA", Q_NULLPTR));
        btnOutB->setText(QApplication::translate("DAC", "CHB", Q_NULLPTR));
        spbVoltChA->setPrefix(QString());
        spbVoltChA->setSuffix(QApplication::translate("DAC", " V", Q_NULLPTR));
        spbVoltChB->setPrefix(QString());
        spbVoltChB->setSuffix(QApplication::translate("DAC", " V", Q_NULLPTR));
        btnOutAll->setText(QApplication::translate("DAC", "ALL", Q_NULLPTR));
        menuFiles->setTitle(QApplication::translate("DAC", "File(&F)", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("DAC", "Help(&H)", Q_NULLPTR));
        style->setTitle(QApplication::translate("DAC", "\351\243\216\346\240\274", Q_NULLPTR));
        menu->setTitle(QApplication::translate("DAC", "\351\200\232\344\277\241\345\215\217\350\256\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DAC: public Ui_DAC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAC_H
