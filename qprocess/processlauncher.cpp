#include "processlauncher.h"
#include <QDebug>

ProcessLauncher::ProcessLauncher(QObject* parent):
    QProcess(parent)
{

}

void ProcessLauncher::LaunchProcess()
{

}

void ProcessLauncher::HandleFinishedStateSlot(int exitCode, QProcess::ExitStatus exitStatus)
{
    qDebug() << "ProcessLauncher::HandleFinishedStateSlot() exitCode : " << exitCode << "exitStatus : " << exitStatus ;
    qDebug() << "ProcessLauncher::HandleFinishedStateSlot() calling this->deleteLater()";
    this->deleteLater();
}

void ProcessLauncher::HandleStartedStateSlot()
{
    qDebug() << "ProcessLauncher::HandleStartedStateSlot()";
}
