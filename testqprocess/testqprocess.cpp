#include "testqprocess.h"
#include <QProcess>
#include <QDebug>
#include <QDir>
#include <QDateTime>
#include <iostream>
#include <thread>

namespace
{
    constexpr const char* PROCESS_NAME = "top";
    constexpr const char* LOG_FILE = "/home/ng81401/tada-stdout.log";
}

TestQProcess::TestQProcess()
{
}

QString TestQProcess::combineProgramAndArguments(const QString& program, const QStringList &arguments)
{
    QString retVal = program;
    foreach (const QString &argument, arguments) {
        retVal += " " + argument;
    }
    qDebug() << "retVal : " << retVal;
    return retVal;
}

void TestQProcess::GenerateFileName(const QString& appName)
{
   QString stdOutFile = appName + QDateTime::currentDateTime().toString("-yyyy-MM-dd-hh-mm-ss") + ".txt";
   qDebug() << "stdOutFile : " << stdOutFile;
}

void TestQProcess::Cleanup()
{
    QProcess::startDetached(QString("rm %1").arg(LOG_FILE));
}

void TestQProcess::StartProcess()
{
    Cleanup();
    std::this_thread::sleep_for(std::chrono::seconds(1));

    QProcess ProcessObj; //= new QProcess;
    //How to redirect the output from a process started by QProcess to a file?
    ProcessObj.setStandardOutputFile(LOG_FILE, QIODevice::Truncate);
    QStringList arguments;
    arguments << "-b" << "-n1";

    QString programWithArguments= combineProgramAndArguments(PROCESS_NAME, arguments);
    ProcessObj.set
    ProcessObj.start(programWithArguments);
//    ProcessObj.waitForStarted();
}
