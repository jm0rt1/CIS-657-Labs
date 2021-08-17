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
    kprintf("B1  ");

    //rendezvous one more time for a new line character
    signal(Aarrived);


}