#pragma once

#include <QTimer>
#include <iostream>

class testqtimer : public QObject
{
    Q_OBJECT;
public:
    explicit testqtimer(QObject *parent = 0);
    void TestTimerTypes();

public slots:
    void VeryCoarseTimerSlot();

private:
    QTimer VeryCoarseTimerObj;
    void SetupVeryCoarseTimer();
};
