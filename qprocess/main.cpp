#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <thread>
#include "testqprocess.h"

namespace
{
//constexpr const char* TOP_PROCESS_NAME = "top";
constexpr const int ITERATIONS = 1;
constexpr const char* CRASHTEST_BUILD_DIR = "build-crashtest-Desktop-Debug";
constexpr const char* CRASHTEST_PROCESS_NAME = "crashtest";

QString GetCrashTestExecutablePath()
{

    QDir sourcePath(QDir::currentPath());
    sourcePath.cdUp();
    sourcePath.cd(CRASHTEST_BUILD_DIR);
    QString fullPath = sourcePath.absolutePath() +  QDir::separator() + CRASHTEST_PROCESS_NAME;
    qDebug() << "fullPath : " << fullPath;
    return fullPath;
}

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
        Obj.StartProcess(GetCrashTestExecutablePath(), arguments);
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    qDebug() << "All Done!";
    return a.exec();
}
