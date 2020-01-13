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
        RegDeviceID     = 0x0000, //
        RegCommAddress  = 0x0001,
        RegCommDataBits = 0x0002,
        RegCommBaudrate = 0x0003,
        RegSys          = 0x0004, //
        RegOutputA      = 0x0005,
        RegOutputB      = 0x0006,
        RegCalibrationA = 0x0007,
        RegCalibrationB = 0x0008,
    };
    Q_ENUM(RegAddress)


    BaseSerialComm *currentPort;   // 端口号
//    QTimer *tim;
    QString deviceID;    // device ID

    void initComboBox_Config();
    void configPort();


    void listBaudRate(QComboBox *cbbBaud);
    void listDataBit(QComboBox *cbbDataBit);

    void Delay_MSec(quint32 msec);
    void readDeviceID();
    void readCtrlMode();
    void writeOutputVolt(quint32 CHx, quint16 Volt);
    void writeCalibrationRate(quint32 CHx, quint16 Rate);

public slots:
    void slots_errorHandler(QSerialPort::SerialPortError error);

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

private:
    Ui::DAC *ui;
    MBSerialMaster *Master;
};

#endif // DAC_H
