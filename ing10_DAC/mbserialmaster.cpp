#include "mbserialmaster.h"

MBSerialMaster::MBSerialMaster()
{
   deviceAddr = 0;
}

void MBSerialMaster::configMaster(BaseSerialComm *currentPort,  qint32 deviceAddr )
{
    setDeviceAddr(deviceAddr);
    Device = currentPort;
}
void MBSerialMaster::setDeviceAddr(qint8 Addr )
{
    deviceAddr = Addr;
}
qint8 MBSerialMaster::getDeviceAddr()
{
    return deviceAddr;
}

/*---------------------------------------------*/
/* read a holding register */
MBSerialMaster::ErrorCode MBSerialMaster::readHoldingRegisters(quint16 RegAddr, quint16 quantity, QByteArray &txbuf, QByteArray &rxbuf, qint32 timeout)
{
    if(!Device->isOpen()){
        return ErrNotOpen;
    }
    Device->clear();
    txbuf[0] = deviceAddr;
    txbuf[1] = FC03;
    txbuf[2] = (RegAddr&0xFF00)>>8;
    txbuf[3] = (RegAddr&0x00FF);
    txbuf[4] = (quantity&0xFF00)>>8;
    txbuf[5] = (quantity&0x00FF);

    Device->insertVerify(txbuf, 0,0, BaseSerialComm::VerifyStyle::CRC_Modbus );
    Device->write(txbuf);
    if(timeout < 0)
        timeout = 1;
    if(Device->waitForReadyRead(timeout)){
        rxbuf = Device->readAll();
        QByteArray tmp;
        tmp = Device->insertVerify(rxbuf, 0,0, BaseSerialComm::VerifyStyle::CRC_Modbus );
        rxbuf.chop(2);//Removes n bytes from the end of the byte array.
        bool ok;
        if( tmp.toInt(&ok,16) && (ok==true) ){  // verify error
            return ErrVerify;
        }else if((rxbuf.at(0) != deviceAddr) ){
            return ErrDeviceAddress;
        }else if( (rxbuf.at(1)&0x80) != 0 ){
            return (ErrorCode)rxbuf.at(2);
        }else {
            return ErrNone;
        }
    }else{
        return ErrTimeout;
    }
}

/* Write a holding register */
MBSerialMaster::ErrorCode MBSerialMaster::writeHoldingRegister(quint16 RegAddr, quint16 dataValue, QByteArray &txbuf, QByteArray &rxbuf, qint32 timeout)
{
    if(!Device->isOpen()){
        return ErrNotOpen;
    }
    Device->clear();
    txbuf[0] = deviceAddr;
    txbuf[1] = FC06;
    txbuf[2] = (RegAddr&0xFF00)>>8;
    txbuf[3] = (RegAddr&0x00FF);
    txbuf[4] = (dataValue&0xFF00)>>8;
    txbuf[5] = (dataValue&0x00FF);

    Device->insertVerify(txbuf, 0,0, BaseSerialComm::VerifyStyle::CRC_Modbus );
    Device->write(txbuf);
    if(timeout < 0)
        timeout = 1;
    if(Device->waitForReadyRead(timeout)){
        rxbuf = Device->readAll();
        QByteArray tmp;
        tmp = Device->insertVerify(rxbuf, 0,0, BaseSerialComm::VerifyStyle::CRC_Modbus );
        rxbuf.chop(2);//Removes n bytes from the end of the byte array.
        bool ok;
        if( tmp.toInt(&ok, 16) && (ok==true) ){  // verify error
            return ErrVerify;
        }else if((rxbuf.at(0) != deviceAddr) ){
            return ErrDeviceAddress;
        }else if( (rxbuf.at(1)&0x80) != 0 ){
            return (ErrorCode)rxbuf.at(2);
        }else {
            return ErrNone;
        }
    }else{
        return ErrTimeout;
    }
}


/* Write multi holding register */
MBSerialMaster::ErrorCode MBSerialMaster::writeHoldingRegister(quint16 RegAddr, QByteArray dataValue, QByteArray &txbuf, QByteArray &rxbuf, qint32 timeout)
{
    if(!Device->isOpen()){
        return ErrNotOpen;
    }
    Device->clear();
    uint16_t regNum = dataValue.size()/2;
    uint8_t byteNum = dataValue.size();
    txbuf[0] = deviceAddr;
    txbuf[1] = FC10;
    txbuf[2] = (RegAddr&0xFF00)>>8;
    txbuf[3] = (RegAddr&0x00FF);
    txbuf[4] = (regNum&0xFF00)>>8;
    txbuf[5] = (regNum&0x00FF);
    txbuf[6] = (byteNum&0x00FF);
    txbuf.append(dataValue);
    Device->insertVerify(txbuf, 0,0, BaseSerialComm::VerifyStyle::CRC_Modbus );
    Device->write(txbuf);
    if(timeout < 0)
        timeout = 1;
    if(Device->waitForReadyRead(timeout)){
        rxbuf = Device->readAll();
        QByteArray tmp;
        tmp = Device->insertVerify(rxbuf, 0,0, BaseSerialComm::VerifyStyle::CRC_Modbus );
        rxbuf.chop(2);//Removes n bytes from the end of the byte array.
        bool ok;
        if( tmp.toInt(&ok, 16) && (ok==true) ){  // verify error
            return ErrVerify;
        }else if((rxbuf.at(0) != deviceAddr) ){
            return ErrDeviceAddress;
        }else if( (rxbuf.at(1)&0x80) != 0 ){
            return (ErrorCode)rxbuf.at(2);
        }else {
            return ErrNone;
        }
    }else{
        return ErrTimeout;
    }
}







































