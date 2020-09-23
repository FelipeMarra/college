#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int main()
{
    Queue Q;
    Q = createQueue();

    printQueue(Q);

    int value = 1;
    insertValue(Q,value);
    printQueue(Q);

    value = 2;
    insertValue(Q,value);
    printQueue(Q);
    
    value = 3;
    insertValue(Q,value);
    printQueue(Q);
    
    removeValue(Q);
    printQueue(Q);

    removeValue(Q);
    printQueue(Q);

    removeValue(Q);
    printQueue(Q);

    value = 1;
    insertValue(Q,value);
    printQueue(Q);

    return 0;
}
