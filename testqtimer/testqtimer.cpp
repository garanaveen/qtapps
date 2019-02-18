#include "testqtimer.h"

testqtimer::testqtimer()
{
    SetupVeryCoarseTimer();
}

void VeryCoarseTimerSlot()
{
    std::cout << "testqtimer::VeryCoarseTimerSlot()" << std::endl;
}

void testqtimer::SetupVeryCoarseTimer()
{
    VeryCoarseTimerObj.setInterval(1000);
    connect(&VeryCoarseTimerObj, SIGNAL(timeout()), this, SLOT(VeryCoarseTimerSlot()));

    VeryCoarseTimerObj.start();
}

void testqtimer::TestTimerTypes()
{
    std::cout << "testqtimer::TestTimerTypes()" << std::endl;
}
