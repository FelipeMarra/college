#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int main()
{
    Queue Q;
    Q = initializeQueue();
    printQueue(Q);
    insetInQueue(Q, 2);
    printQueue(Q);
    removeFromQueue(Q);
    printQueue(Q);

    return 0;
}
