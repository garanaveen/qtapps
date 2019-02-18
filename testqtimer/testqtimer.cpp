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
    VeryCoarseTimerObj.setSingleShot(true);
    VeryCoarseTimerObj.setInterval(1000);
    connect(&VeryCoarseTimerObj, SIGNAL(timeout()), this, SLOT(VeryCoarseTimerSlot()));

    VeryCoarseTimerObj.start();
}

void testqtimer::TestTimerTypes()
{
    std::cout << "testqtimer::TestTimerTypes()" << std::endl;
}
