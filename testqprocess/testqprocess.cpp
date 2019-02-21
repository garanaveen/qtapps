#include "testqprocess.h"
//#include <QStandardPaths> //Qt5
#include <QDebug>
#include <QDir>
#include <QDateTime>
#include <iostream>
#include <thread>

namespace
{
    constexpr const char* LOG_FILE = "tada-stdout";
}

TestQProcess::TestQProcess(QObject *parent):
    QObject(parent)
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

QString TestQProcess::GenerateFileName(const QString& appName)
{
   QString stdOutFile = appName + QDateTime::currentDateTime().toString("-yyyy-MM-dd-hh-mm-ss") + ".txt";
   qDebug() << "stdOutFile : " << stdOutFile;
   return stdOutFile;
}

void TestQProcess::Cleanup()
{
    QProcess::startDetached(QString("rm %1*").arg(QDir::homePath() + QDir::separator() + LOG_FILE));
}

void TestQProcess::StartProcess(const QString& program, const QStringList &arguments)
{
    ProcessLauncher* Launcher = new ProcessLauncher();
//    QProcess* Launcher = new QProcess();
    std::this_thread::sleep_for(std::chrono::seconds(1));

    //How to redirect the output from a process started by QProcess to a file?
    QString stdoutFile = GenerateFileName(QDir::homePath() + QDir::separator() + LOG_FILE);
//    QObject::connect(Launcher, SIGNAL(finished(int,QProcess::ExitStatus)), Launcher, SLOT(deleteLater()));
    QObject::connect(Launcher, SIGNAL(finished(int, QProcess::ExitStatus)), Launcher, SLOT(HandleFinishedStateSlot(int, QProcess::ExitStatus)));
    QObject::connect(Launcher, SIGNAL(started()), Launcher, SLOT(HandleStartedStateSlot()));

    Launcher->setStandardOutputFile(stdoutFile, QIODevice::Truncate);
    Launcher->start(program, arguments);
//    Launcher->waitForStarted();
}
