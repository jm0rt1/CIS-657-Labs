/* hello.c - main*/
#include <xinu.h>
void sndch(char);
/* main - just say hello, then exit */ 
void main(void)
{
	resume(create(sndch, 1024, 40, "send A", 1, 'A'));
	resume(create(sndch, 1024, 20, "send B", 1, 'B'));
}

void sndch(char ch)
{
	while(1)
	{
		putc(CONSOLE, ch);

	}
}