


/* xsh_resumen.c - xsh_resumen */

#include <xinu.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*------------------------------------------------------------------------
 * xsh_resumen - Resume process PID's given in the argument list
 *------------------------------------------------------------------------
 */
void resumeProcs(int32 nargs, char*args[]);

shellcmd xsh_resumen(int32 nargs, char *args[])
{
    if (nargs == 1) {
        //default argument
        kprintf("ERROR: No argument provided -- please provide a PID\n");
        return;
    }
    else if ( nargs >=2 ) {

        //start process with maximum priority so nothing stomps on it
        resume(create(resumeProcs, 1024, 32767, "resumen", 2, nargs, args));

    }
}

void resumeProcs(int32 nargs, char*args[])
{
        
        int i=1;
        for (i; i < nargs; i++)
        {
            char* pidStr = args[i];
            pid32 pid = atoi(pidStr);
            pri16 result = resume(pid);
            if (result == (pri16)SYSERR){
                kprintf("Could not start process %d\n", pid);
            }

        }
        //User gave argument, convert to number
}