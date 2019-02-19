#include "testqtimer.h"

testqtimer::testqtimer(QObject *parent) :
    QObject(parent)
{
    SetupVeryCoarseTimer();
}

void testqtimer::VeryCoarseTimerSlot()
{
    std::cout << "testqtimer::VeryCoarseTimerSlot()" << std::endl;
}

void testqtimer::SetupVeryCoarseTimer()
{
    //TODO : Qt::VeryCoarseTimer was introduced in Qt5. Not sure how to specify to compile this with Qt5. So couldn't test this TimerType.
//    VeryCoarseTimerObj.setTimerType(Qt::VeryCoarseTimer);
    VeryCoarseTimerObj.setSingleShot(false);
    VeryCoarseTimerObj.setInterval(1000);
    connect(&VeryCoarseTimerObj, SIGNAL(timeout()), this, SLOT(VeryCoarseTimerSlot()));

    VeryCoarseTimerObj.start();
}

void testqtimer::TestTimerTypes()
{
    std::cout << "testqtimer::TestTimerTypes()" << std::endl;
}
