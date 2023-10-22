/*Leonardo Loureiro Costa*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "funcs.h"

int globalSum = 0;
int request = 0;
int response = 0;

void criticalSection(int threadId)
{
    int localSum = globalSum;
    sleep(rand() % 2);
    globalSum = localSum + 1;

    printf("thread: %d, gloablSum: %d\n", threadId, globalSum);
}

void client(int threadId)
{
    while (1)
    {
        while (response != threadId)
        {
            request = threadId;
        }

        criticalSection(threadId);

        response = 0;
    }
}

void server()
{
    while (1)
    {
        while (request == 0);
        response = request;

        while (response != 0);
        request = 0;
    }
}