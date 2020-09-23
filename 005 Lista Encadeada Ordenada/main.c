#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int main()
{
    
    List L = initilizeList();
    printList(L);

    int value1 = 1;
    insertNode(L, value1);
    printList(L);

    int value2 = 2;
    insertNode(L, value2);
    printList(L);

    int value3 = 3;
    insertNode(L, value3);
    printList(L);

    int value10 = 10;
    removeNode(L, value10);
    printList(L);

    removeNode(L, value2);
    printList(L);

    return 0;
}
