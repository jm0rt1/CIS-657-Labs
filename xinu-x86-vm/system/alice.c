#include <xinu.h>
extern void alice(sid32 Aarrived, sid32 Barrived)
{
    int upper = 1000;
    int lower = 10;
    int randomTime = (rand() % (upper - lower + 1)) + lower;
    kprintf("A1  ");
    sleepms(randomTime);

    signal(Barrived);
    wait(Aarrived);

    kprintf("A2  ");

    //rendezvous one more time for a new line character
    signal(Barrived);
    wait(Aarrived);
    kprintf("\n")

}