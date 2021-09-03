

/* xsh_createsleep.c - xsh_createsleep */

#include <xinu.h>
#include <stdio.h>
#include <string.h>

/*------------------------------------------------------------------------
 * xsh_createsleep - Creates a process with the specified priority and puts in sleep state for 10 seconds
 *------------------------------------------------------------------------
 */
void runforeverSleep();


shellcmd xsh_createsleep(int32 nargs, char *args[])
{
    pri16 priority;
    char ch;
    char *chprio;
    pid32 pid;

    if (nargs == 1) {
        //default argument
        priority=INITPRIO;
    }
    else if ( nargs == 2 ) {

        //User gave argument, convert to number
        chprio = args[1];

        
        priority = 0;
        priority = atoi(chprio);

    }
    else {
        kprintf("Too many arguments\n");
        return 1;
    }

    pid = create(runforeverSleep, 1024, priority, "sleep", 0);
    resume(pid);
    return 0;
}

void runforeverSleep()
{
    sleep(10);
    runforever();
}
