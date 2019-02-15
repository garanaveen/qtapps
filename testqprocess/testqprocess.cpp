#include "testqprocess.h"
#include <QProcess>
#include <QDebug>
#include <iostream>

namespace
{
const char* PROCESS_NAME = "top";
}
TestQProcess::TestQProcess()
{
}

QString combineProgramAndArguments(const QString& program, const QStringList &arguments)
{
    QString retVal = program;
    foreach (const QString &argument, arguments) {
        retVal += " " + argument;
    }
    retVal += " > " + stdOutFilePath;
    qDebug() << "retVal : " << retVal;
    return retVal;
}

void TestQProcess::StartProcess()
{
    QProcess ProcessObj;
    //How to redirect the output from a process started by QProcess to a file?
    ProcessObj.setStandardOutputFile("/home/ng81401/tada-stdout.log", QIODevice::Truncate);
    QStringList arguments;
    arguments << "-b" << "-n1";

    QString programWithArguments= combineProgramAndArguments(PROCESS_NAME, arguments);
    ProcessObj.start(programWithArguments);
    ProcessObj.waitForFinished();
}
