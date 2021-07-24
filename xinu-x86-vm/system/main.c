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
	printf("started");
	int i=0;
	for (i; i < NQENT; i++)
	{
		int32 key = queuetab[NQENT].qkey;
		qid16 prev = queuetab[NQENT].qprev;
		qid16 next = queuetab[NQENT].qnext;
		printf("Entry %d: key = %d, next = %d, prev = %d", i,key,next,prev);
	}
	printf("finished");
}

int main(int argc, char **argv)
{

	resume(create(p1, 8192, 40, "1", 1, CONSOLE));
	resume(create(p2, 8192, 30, "2", 1, CONSOLE));
	resume(create(p3, 8192, 20, "3", 1, CONSOLE));
	resume(create(p4, 8192, 20, "4", 1, CONSOLE));
	resume(create(print_q_tab, 8192, 50, "print", 1, CONSOLE));


	return OK;


}
