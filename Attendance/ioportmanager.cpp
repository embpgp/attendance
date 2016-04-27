#include "ioportManager.h"
#include <qglobal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <QDebug>

#ifndef _WIN32
#include <sys/ioctl.h>
#endif

int IOPortManager::ioFile1 = -1;
int IOPortManager::ioFile2 = -1;
IOPortManager::IOPortManager()
{
    //ioFile = ::open("/dev/gpJ4", O_RDWR);
//    ioFile = ::open("/dev/gpf", O_RDWR);
    ioFile1 = ::open("/dev/gpJ2", O_RDWR);
    ioFile2 = ::open("/dev/gpJ4", O_RDWR);
    //qDebug()<<"ioFile1 = "<<ioFile1<<", ioFile2 = "<<ioFile2;
    initPort();
}

IOPortManager::~IOPortManager()
{
    ::close(ioFile1);
    ::close(ioFile2);
}

void IOPortManager::setIOFDir(int bit, int type)
{
     if((ioFile1 < 0) || (ioFile2 < 0))
        return;
     switch(bit)
     {
     case 0:            // GPJ2_7
#ifndef WIN32
         ::ioctl(ioFile1, type & 0x01, 7);
#endif
         break;
     case 1:            // GPJ4_4
     case 2:            // GPJ4_3
     case 3:            // GPJ4_2
         bit = 5 - bit;
#ifndef WIN32
         ::ioctl(ioFile2, type & 0x01, bit);
#endif
         break;
     }

}

void IOPortManager::setIOFDat(int bit, int value)
{
    if((ioFile1 < 0) || (ioFile2 < 0))
       return;
    switch(bit)
    {
    case 0:            // GPJ2_7
#ifndef WIN32
        ::ioctl(ioFile1, 0x10 | value, 7);
#endif
        break;
    case 1:            // GPJ4_4
    case 2:            // GPJ4_3
    case 3:            // GPJ4_2
        bit = 5 - bit;
#ifndef WIN32
        ::ioctl(ioFile2, 0x10 | value, bit);
#endif
        break;
    }
}

void IOPortManager::setLEDDir(int bit, int type)
{
    if(ioFile1 < 0)
        return;
#ifndef WIN32
    ::ioctl(ioFile1, type & 0x01, bit);
#endif
}

void IOPortManager::setLEDDat(int bit, int value)
{
    if(ioFile1 < 0)
        return;
#ifndef WIN32
    ::ioctl(ioFile1, 0x10 | value, bit);
#endif
}

void IOPortManager::initPort()
{
     setIOFDir(0, 1);
     setIOFDir(1, 1);
     setIOFDir(2, 1);
     setIOFDir(3, 1);

    // ::ioctl(ioFile, 0x32, 1);

     setIOFDat(0, 0);
     setIOFDat(1, 0);
     setIOFDat(2, 0);
     setIOFDat(3, 0);

     setLEDDir(0, 1);
     setLEDDir(1, 1);
     setLEDDir(2, 1);
     setLEDDir(3, 1);
     setLEDDat(0, 0);
     setLEDDat(1, 0);
     setLEDDat(2, 0);
     setLEDDat(3, 0);
}

void IOPortManager::setMode(MODETYPE type)
{
    //qDebug()<<"select RFID mode = "<<type;
      switch(type)
      {
      case Mode125K:
          setIOFDat(0, 0);
          setIOFDat(1, 0);
          setIOFDat(2, 0);
          //qDebug()<<"set the mode 125K";
          setLEDDat(0, 1);
          setLEDDat(1, 0);
          setLEDDat(2, 0);
          setLEDDat(3, 0);
          break;
      case Mode13_56M1:
          setIOFDat(0, 1);
          setIOFDat(1, 0);
          setIOFDat(2, 0);
          setLEDDat(0, 0);
          setLEDDat(1, 1);
          setLEDDat(2, 0);
          setLEDDat(3, 0);
          break;
      case Mode13_56M2:
          setIOFDat(0, 0);
          setIOFDat(1, 1);
          setIOFDat(2, 0);
          setLEDDat(0, 0);
          setLEDDat(1, 1);
          setLEDDat(2, 0);
          setLEDDat(3, 0);
          break;
      case Mode900M:
          setIOFDat(0, 1);
          setIOFDat(1, 1);
          setIOFDat(2, 0);
          setLEDDat(0, 0);
          setLEDDat(1, 0);
          setLEDDat(2, 1);
          setLEDDat(3, 0);
          break;
      case ModeScanGun:
          setIOFDat(0, 0);
          setIOFDat(1, 0);
          setIOFDat(2, 1);
          setLEDDat(0, 0);
          setLEDDat(1, 0);
          setLEDDat(2, 0);
          setLEDDat(3, 1);
          //qDebug()<<"set the mode scan gun";
          break;
      default:
          break;
      }

}

static const IOPortManager _dummy_port;

