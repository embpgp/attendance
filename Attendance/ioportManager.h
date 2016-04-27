#ifndef IOPORTMANAGER_H
#define IOPORTMANAGER_H


enum MODETYPE{Mode125K, Mode13_56M1, Mode13_56M2, Mode900M, ModeScanGun};


class IOPortManager
{
public:
    IOPortManager();
    virtual ~IOPortManager();
    static void setIOFDir(int bit, int type);
    static void setIOFDat(int bit, int value);
    static void setMode(MODETYPE type);

    static void setLEDDir(int bit, int type);
    static void setLEDDat(int bit, int value);

protected:
    static void initPort();

private:
    static int ioFile1;
    static int ioFile2;
};

#endif // IOPORTMANAGER_H
