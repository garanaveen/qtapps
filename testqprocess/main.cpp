#include <QCoreApplication>
#include "testqprocess.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TestQProcess Obj;
    Obj.GenerateFileName("CrashTestDummyApp");
    Obj.StartProcess();
    return a.exec();
}
