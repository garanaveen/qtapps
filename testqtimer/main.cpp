#include <QCoreApplication>
#include "testqtimer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    testqtimer TestObj;
    TestObj.TestTimerTypes();

    return a.exec();
}
