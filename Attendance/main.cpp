#include <QtGui/QApplication>
#include "MainWidget.h"
#include <QTextCodec>
#include "login.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //设置UTF-8编码
    QTextCodec *codec=QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);


    login x;
    x.show();

    return a.exec();
}
