#ifndef PROCESSLAUNCHER_H
#define PROCESSLAUNCHER_H

#include <QProcess>

class ProcessLauncher : public QProcess
{
    Q_OBJECT
public:
    ProcessLauncher(QObject* parent = nullptr);
    void LaunchProcess();

public slots:
    void HandleStartedStateSlot();
    void HandleFinishedStateSlot(int exitCode, QProcess::ExitStatus exitStatus);
};

#endif // PROCESSLAUNCHER_H
