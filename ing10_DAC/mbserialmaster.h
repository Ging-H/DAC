#ifndef DACREGISTER_H
#define DACREGISTER_H

#include <QObject>
#include <QTimer>
#include <QEventLoop>
#include "baseserialcomm.h"

class MBSerialMaster : public QObject
{
    Q_OBJECT

public:
    enum FunctionCode{
        FC03 = 0x03, // read single holding register
        FC06 = 0x06, // write single holding register
        FC10 = 0x10, // write Multi holding register
    };
    Q_ENUM(FunctionCode)

    enum ErrorCode{
        ErrDeviceAddress = 0 , // device address error, not expect device address
        Err01Function , // illegal function
        Err02DataAddress , // illegal  data address
        Err03DataValue , // illegal  data value
        Err04 , // illegal response length
        Err05Confim , // confirm,device had rx request , but it need a few minutes to finish it.
        Err06Busy , // device busy

        ErrNotOpen ,
        ErrVerify ,
        ErrTimeout ,
        ErrNone = -1,
    };
    Q_ENUM(ErrorCode)

    struct RxStruct{
        uint8_t functionCode;
        uint8_t byteQuantity;
        ErrorCode ErrState;
        uint16_t data[128]; //

    };
    Q_ENUM(RxStruct)



    MBSerialMaster();

/* the deviceAddr must be set corrected before use this write/read function  */
    void configMaster(BaseSerialComm *currentPort, qint32 deviceAddr = 0);
    void setDeviceAddr(qint8 deviceAddr = 0);
    qint8 getDeviceAddr();
    ErrorCode readHoldingRegisters(quint16 RegAddr, quint16 quantity, QByteArray &src, QByteArray &rxbuf,qint32 timeout = 1000);
    ErrorCode writeHoldingRegister(quint16 RegAddr, quint16 dataValue, QByteArray &txbuf, QByteArray &rxbuf, qint32 timeout = 1000);
    ErrorCode writeHoldingRegister(quint16 RegAddr, QByteArray dataValue, QByteArray &txbuf, QByteArray &rxbuf, qint32 timeout = 1000);

    void Delay_MSec(int mSec);


private:
    BaseSerialComm *Device= NULL;
    qint8  deviceAddr;  // slave address
};

#endif // DACREGISTER_H
