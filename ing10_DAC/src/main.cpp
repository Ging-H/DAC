#include "dac.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DAC w;
    w.show();


    return a.exec();
}
