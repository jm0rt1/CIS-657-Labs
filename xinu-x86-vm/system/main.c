/*  main.c  - main */

#include <xinu.h>
#include <stdio.h>
void addProc(int32 num);

int main(int argc, char **argv)
{
	kprintf("starting\n");
	resume(create(addProc, 8192, 5, "Process 2", 1, 2));
	resume(create(addProc, 8192, 10, "Process 3", 1, 3));

	resume(create(addProc, 8192, 20, "Process 4", 1, 4));

	return OK;
}

void addProc(int32 num)
{
	kprintf("Process %d is running \n", num);

	sleep(15);
	int i = 0;
	for (i; i <= 10; i++)
	{
		kprintf("Process %d is running\n", num);
	}
}