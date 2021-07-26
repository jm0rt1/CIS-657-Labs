/*  main.c  - main */

#include <xinu.h>



void waiter(sid32 semaphore, pid32 spid)
{
	int i = 1;
	for (i; i<=2000; i++)
	{
		// print the count
		printf("%d ", i);
		// increment semaphore counter

		wait(semaphore);

	}
	kill(spid);

}

void signaler(sid32 semaphore)
{
	while(1)
	{


		printf("signaler is running\n");

		signaln(semaphore, 5);


	}
}

int main(int argc, char **argv)
{
	sid32 semaphore = semcreate(20);


	pri16 spid = create(signaler, 1024, 20, "signaler", 1, semaphore);
	pri16 wpid = create(waiter, 1024, 40, "waiter", 2, semaphore, spid);
	resume(wpid);
	resume(spid);

	return OK;


}
