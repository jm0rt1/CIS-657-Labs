

/* xsh_createsuspended.c - xsh_createsuspended */

#include <xinu.h>
#include <stdio.h>
#include <string.h>

/*------------------------------------------------------------------------
 * xsh_createsuspended - Creates a process with the specified priority but leaves it in suspended state
 *------------------------------------------------------------------------
 */

shellcmd xsh_createsuspended(int32 nargs, char *args[])
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
    pid = create(runforever, 1024, priority, "suspended", 0);

    return 0;
}
