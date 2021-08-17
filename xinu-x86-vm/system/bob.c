#include <xinu.h>
void bob(sid32 Aarrived, sid32 Barrived)
{
    int upper = 1000;
    int lower = 10;
    int randomTime = (rand() % (upper - lower + 1)) + lower;
    kprintf("B1  ");
    sleepms(randomTime);

    signal(Aarrived);
    wait(Barrived);

    kprintf("B2  ");

    signal(Aarrived);
    wait(Barrived);



}