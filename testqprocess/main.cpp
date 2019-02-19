#include <QCoreApplication>
#include <QDebug>
#include <thread>
#include "testqprocess.h"

namespace
{
constexpr const char* TOP_PROCESS_NAME = "top";
constexpr const int ITERATIONS = 10;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TestQProcess Obj;

    Obj.Cleanup();
    QStringList arguments;
    arguments << "-b" << "-n3";
    for(int i = 0 ; i < ITERATIONS ; ++i)
    {
        qDebug() << "Iteration : " << i;
        Obj.StartProcess(TOP_PROCESS_NAME, arguments);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return a.exec();
}
