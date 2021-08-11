/*  main.c  - main */

#include <xinu.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 15
#endif

#ifndef TEST_SIZE
#define TEST_SIZE 2000
#endif

void producer(sid32 bufferFull, sid32 accessMutex, int * buffer);
void consumer(sid32 bufferFull, sid32 accessMutex, int * buffer);
void processSafeAddItem(int32 item, int32 index, sid32 accessMutex, int * buffer);
int32 processSafeGetItem(int32 index, sid32 accessMutex, int * buffer);


int main(int argc, char **argv)
{
	int32 buffer[BUFFER_SIZE];
	sid32 bufferFull = semcreate(0);
	sid32 accessMutex = semcreate(1);

	pid32 producerPid = resume(create(producer, 1024, 40, "producer", 3, bufferFull, accessMutex, buffer));
	pid32 consumerPid = resume(create(consumer, 1024, 20, "consumer", 3, bufferFull, accessMutex, buffer));
	
	sleep(1);


}

void producer(sid32 bufferFull, sid32 accessMutex, int* buffer)
{
	int32 i;
	int32 n = 0;
	for (i=1; i<= TEST_SIZE; i++)
	{
		if (n == BUFFER_SIZE){
			n = 0;
			wait(bufferFull);
		}
		processSafeAddItem(i,n, accessMutex, buffer);
		n++;
	}
}
void consumer(sid32 bufferFull, sid32 accessMutex, int * buffer)
{
	int32 i;
	int32 n = 0;
	for (i=1; i <= TEST_SIZE; i++)
	{
		if (n == BUFFER_SIZE)
		{
			n = 0;
			kprintf("\n");
			signal(bufferFull);

		}
		kprintf("%d ", processSafeGetItem(n, accessMutex, buffer));
		n++;
	}
}

void processSafeAddItem(int32 item, int32 index, sid32 accessMutex, int * buffer)
{
	wait(accessMutex);
	buffer[index] = item;
	signal(accessMutex);
}

int32 processSafeGetItem(int32 index, sid32 accessMutex, int* buffer)
{
	wait(accessMutex);
	int32 item = buffer[index];
	signal(accessMutex);
	return item;
}