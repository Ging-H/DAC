#ifndef DAC_H
#define DAC_H

#include <QMainWindow>
#include "baseserialcomm.h"
#include "QMessageBox"
#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QMetaEnum>
#include "mbserialmaster.h"
#include "QXmlStreamWriter"
#include "QXmlStreamReader"
#include "QFile"
#include "QFileDialog"
#include <QtGui>
#include <QApplication>

namespace Ui {
class DAC;
}

class DAC : public QMainWindow
{
    Q_OBJECT

public:
    explicit DAC(QWidget *parent = 0);
    ~DAC();

    /* 寄存器地址 */
    enum RegAddress{
        RegDeviceID     = 0x03E8, // 1000
        RegCommAddress  = 0x03E9, // 1001
        RegCommDataBits = 0x03EA, // 1002
        RegCommVerify   = 0x03EB, //
        RegCommBaudrate = 0x03EC, //
        RegSys          = 0x03ED, //
        RegOutputA      = 0x03EE, //
        RegOutputB      = 0x03EF, //
        RegCalibrationA = 0x03F0, //
        RegCalibrationB = 0x03F1, //
    };
    Q_ENUM(RegAddress)

    BaseSerialComm *currentPort;   // 端口号
//    QTimer *tim;
    QString deviceID;    // device ID

    void initComboBox_Config();
    void configPort();

    quint32 time;
    void listBaudRate(QComboBox *cbbBaud);
    void listDataBit(QComboBox *cbbDataBit);

    void delayMSec(quint32 msec);
    bool modifyDeviceAddress(quint16 newAddress);
    void readDeviceID();
    void readCtrlMode();
    void writeOutputVolt(quint16 CHx, quint16 Volt);
    void writeCalibrationRate(quint16 CHx, quint16 Rate);
    void readAll();

    void configStyle(QString styleName);
    void saveStyle( QString styleName);
    QString loadStyle();
public slots:
    void slots_errorHandler(QSerialPort::SerialPortError error);
    void slots_readVolt();

private slots:
    void on_btnRefresh_clicked();

    void on_btnOpenPort_clicked(bool checked);

    void on_cbbVerify_currentIndexChanged(int index);

    void on_cbbBaud_currentIndexChanged(int index);

    void on_btnDeviceMsg_clicked();

    void on_btnConfig_clicked();

    void on_txtCurrentAddr_editingFinished();

    void on_btnOutA_clicked();

    void on_btnOutB_clicked();

    void on_btnOutAll_clicked();

    void on_btnCaliA_clicked();

    void on_btnCaliB_clicked();

    void on_btnCaliAll_clicked();

    void on_actionSave_triggered();

    void on_actionOpen_triggered();

//    void on_actionProtocol_triggered();

    void on_actionHelp_triggered();

    void on_actionFusion_triggered();

    void on_actionWindows_triggered();

    void on_actionWindoeXP_triggered();

    void on_actionWindowVista_triggered();

    void on_actionDark_triggered();

    void on_actionBlackO_triggered();

    void on_actionRegList_triggered();

    void on_actionModbus_triggered();

    void on_ckbReadVolt_clicked(bool checked);

private:
    Ui::DAC *ui;
    MBSerialMaster *Master = NULL;
    QDialog *pDialog;
    QTimer *tim;

};

#endif // DAC_H
