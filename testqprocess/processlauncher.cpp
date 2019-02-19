#include "processlauncher.h"
#include <QDebug>

ProcessLauncher::ProcessLauncher(QObject* parent):
    QProcess(parent)
{

}

void ProcessLauncher::LaunchProcess()
{

}

void ProcessLauncher::HandleFinishedStateSlot()
{
    qDebug() << "ProcessLauncher::HandleFinishedStateSlot() calling this->deleteLater()";
    this->deleteLater();
}

void ProcessLauncher::HandleStartedStateSlot()
{
    qDebug() << "ProcessLauncher::HandleStartedStateSlot()";
}
