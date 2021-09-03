
/* xsh_signaln.c - xsh_signaln */

#include <xinu.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*------------------------------------------------------------------------
 * xsh_signaln - Signals n semaphores
 *------------------------------------------------------------------------
 */



shellcmd xsh_signaln(int32 nargs, char *args[])
{
    int32 procCount;
    char ch;
    char *chProcCount;
    pid32 pid;
    struct sentry *semptr;

    //accept arguments
    if (nargs == 1) {
        //default argument
        kprintf("ERROR: No argument provided\n");

    }
    else if ( nargs == 2 ) {
        //User gave argument, convert to number
        chProcCount = args[1];

        procCount = 0;
        procCount = atoi(chProcCount);

    }
    else {
        kprintf("Too many arguments\n");
        return 1;
    }

    //signal the desired number of processes -- requirements make no mention of order
    int i;
    int count = 0;
	for (i = 0; i < NSEM; i++) {
        //find the semaphores with a count below 0 in the table
		semptr = &semtab[i];
		if (semptr->scount >= 0) {  /* skip unused slots	*/
			continue;
        }
        else
        {
            signal(i);
            count ++;
        }
        if(count >= procCount){
            //stop signalling after the given count is met
            break;
        }
	}

}