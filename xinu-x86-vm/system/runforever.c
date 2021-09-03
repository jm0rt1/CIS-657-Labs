/* runforever.c */
#include <xinu.h>

void runforever()
{
	pid32 currpid = getpid();
    kprintf("current process id is %d\n",currpid);
	
    while(TRUE) {}
}
