/* xsh_create.c - xsh_create */
#include <xinu.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*------------------------------------------------------------------------
* xsh_create - shell command to create
*------------------------------------------------------------------------
*/
shellcmd xsh_create(int nargs, char *args[])
{
    pri16 priority;
    char ch;
    char *chprio;
    pid32 pid;
    if (nargs == 1) {
        priority=INITPRIO;
    }
    else if (nargs <= 4) 
    {
        int i = 1;
        for (i; i<=nargs;i++)
        {
            chprio = args[i];
            priority = 0;
            priority = atoi(chprio);
            pid = create(runforever, 1024, priority, "Test", 0);
        }

        //ch = *chprio++;

        //kprintf("prio = %d", priority);
    }
    else {
            kprintf("Too many arguments\n");
            return 1;
    }

    //kprintf("pid = %d\n", pid);
    resume(pid);
    return 0;
}
