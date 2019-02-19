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
    void HandleFinishedStateSlot();
    void HandleStartedStateSlot();
};

#endif // PROCESSLAUNCHER_H
