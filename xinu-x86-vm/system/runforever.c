#include <xinu.h>

void runforever(int32 P)
{
	pid32 currpid = getpid();
    kprintf("current process id is %d\n",currpid);
	

    if (P % 2 ==  0)
    {
        //even number
        kprintf("EVEN\n");
    }
    else
    {
        //odd number
        kprintf("odd\n");
    }
    while(TRUE) {}
}
