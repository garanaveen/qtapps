#pragma once

#include <QTimer>
#include <iostream>

class testqtimer : QObject
{
    Q_OBJECT

public:
    testqtimer();
    void TestTimerTypes();
private:
    QTimer VeryCoarseTimerObj;
    void SetupVeryCoarseTimer();
};
