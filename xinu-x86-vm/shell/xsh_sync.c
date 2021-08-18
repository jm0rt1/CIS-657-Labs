
/* xsh_sync.c - xsh_sync */
#include <xinu.h>
#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#include <clock.h>
int controller(int mutNum);

shellcmd xsh_sync(int nargs, char* args[])
{
    pid32 controllerId;

    int seedArgument;
    if (nargs == 1)
    {
        srand(clktime);

    } else if (nargs == 2) 
    {
        seedArgument = atoi(args[1]);
        srand(seedArgument);
    } else {
        kprintf("Too many arguments\n");
        return 1;
    }    
    
    //generate a random number to determine which runs first
    //Ideally this simulates the two processes already running in the OS for a long time
    int32 random = rand();
    int32 mutNum = random % 2;

    controllerId = create(controller, 1024, 60, "controller", 1, mutNum);

    resume(controllerId);

}

int controller(int mutNum)
{
    pid32 Apid, Bpid;
    sid32 Aarrived = semcreate(0);
    sid32 Barrived = semcreate(0);

    Apid = create(alice, 1024, 60, "alice", 2, Aarrived, Barrived);
    Bpid = create(bob, 1024, 60, "bob", 2, Aarrived, Barrived);



    if (mutNum == 0)
    {
        resume(Apid);
        resume(Bpid);
    }
    else
    {
        resume(Bpid);
        resume(Apid);
    }
    while (1){
        if ((semcount(Aarrived) + semcount(Barrived)) > 10)
        {
            return 0;
        }
    }
}