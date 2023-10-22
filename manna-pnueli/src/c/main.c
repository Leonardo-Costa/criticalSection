/*Leonardo Loureiro Costa*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <omp.h>
#include "funcs.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        return 1;
    }

    int numThreads = atoi(argv[1]);
    omp_set_num_threads(numThreads + 1);

    #pragma omp parallel
    {
        int threadId = omp_get_thread_num();
        printf("threadId: %d\n", threadId);
        if (threadId == 0)
        {
            server();
        }
        else
        {
            client(threadId);
        }
    }
    return 0;
}
