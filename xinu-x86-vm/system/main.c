/*  main.c  - main */

#include <xinu.h>
#include <stdio.h>


void p1(void)
{
	while(1)
	{

	}
}

void p2(void)
{
	while(1)
	{

	}
}
void p3(void)
{
	while(1)
	{

	}
}

void p4(void)
{
	while(1)
	{

	}
}
void print_q_tab(void){
	printf("started\n");
	int i=0;
	for (i; i < 6; i++)
	{
		int32 key = queuetab[i].qkey;
		qid16 prev = queuetab[i].qprev;
		qid16 next = queuetab[i].qnext;
		printf("Entry %d: key = %d, next = %d, prev = %d\n", i,key,next,prev);
	}
	printf("finished queuetab\n");
}

int main(int argc, char **argv)
{
	printf("main running\n");
	resume(create(p1, 1024, 20, "1", 0));
	printf("proc1\n");
	resume(create(p2, 1024, 20, "2", 0));
	printf("proc2\n");

	resume(create(p3, 1024, 20, "3", 0));
	printf("proc3\n");

	resume(create(p4, 1024, 20, "4", 0));
	printf("proc4\n");

	resume(create(print_q_tab, 1024, 30, "print", 0));
	printf("main done\n");

	return OK;


}
