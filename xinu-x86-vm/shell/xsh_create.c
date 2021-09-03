/* xsh_create.c - xsh_create */
#include <xinu.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*------------------------------------------------------------------------
* xsh_create - shell command to create
*------------------------------------------------------------------------
*/
shellcmd xsh_create(int32 nargs, char *args[])
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
    pid = create(runforever, 1024, priority, "created", 0);
    //kprintf("pid = %d\n", pid);
    resume(pid);
    return 0;
}
