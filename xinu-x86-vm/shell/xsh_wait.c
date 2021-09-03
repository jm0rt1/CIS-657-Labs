

/* xsh_wait.c - xsh_wait */

#include <xinu.h>
#include <stdio.h>
#include <string.h>

/*------------------------------------------------------------------------
 * xsh_wait - Creates a process with a semaphore and the process waits on the semaphore
 *------------------------------------------------------------------------
 */

void printWaitRunforever(sid32 mutex);

shellcmd xsh_wait(int32 nargs, char *args[])
{
    sid32 mutex = semcreate(0);

    resume(create(printWaitRunforever, 1024, 20, "Test", 1, mutex));
}

void printWaitRunforever(sid32 mutex)
{
	pid32 currpid = getpid();
    kprintf("current process id is %d\n",currpid);
    wait(mutex);
    while(1)
    {

    }

}