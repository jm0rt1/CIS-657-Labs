
/* xsh_sync.c - xsh_sync */
#include <xinu.h>
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <clock.h>
int monitor(sid32 Aarrived, sid32 Barrived);

shellcmd xsh_sync(int nargs, char* args[])
{
    pid32 Apid, Bpid, monitorPid;
    sid32 Aarrived = semcreate(0);
    sid32 Barrived = semcreate(0);
    sid32 done = semcreate(0);

    int seedArgument;
    if (nargs == 1)
    {
        srand(clktime);
        kprintf("Random number generator seeded with clock time\n");

    } else if (nargs == 2) 
    {
        seedArgument = atoi(args[1]);
        srand(seedArgument);
        kprintf("Random number generator seeded with %d\n", seedArgument);
    } else {
        kprintf("Too many arguments\n");
    }

    //generate a random number to determine which runs first
    //Ideally this simulates the two processes already running in the OS for a long time
    int32 random = rand();
    int32 mutNum = random % 2;

    kprintf("random number is: %d, mutNum is %d\n");

    Apid = create(alice, 1024, 60, "alice", 2, Aarrived, Barrived);
    Bpid = create(bob, 1024, 60, "bob", 2, Aarrived, Barrived);
    //monitorPid = create(monitor, 1024, 60, "bob", 1, done);

    int upper = 1000;
    int lower = 10;
    int randomTime = (rand() % (upper - lower + 1)) + lower;
    if (mutNum == 0)
    {
        resume(Apid);
        //sleepms(randomTime);
        resume(Bpid);
    }
    else
    {
        resume(Bpid);
        //sleepms(randomTime);
        resume(Apid);
    }
    //resume(monitorPid);

}

int monitor(sid32 Aarrived, sid32 Barrived)
{
    while (1){
        if ((semcount(Aarrived) + semcount(Barrived)) == 2)
        {
            return 0;
        }
    }
}