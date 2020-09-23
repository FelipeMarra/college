#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int main()
{
    List L = initilizeList();
    printList(L);

    int value = 1;
    insertNode(L, value);
    printList(L);

    value = 2;
    insertNode(L, value);
    printList(L);

    value = 3;
    insertNode(L, value);
    printList(L);

    insertNode(L, value);
    printList(L);


    value = 10;
    removeNode(L, value);
    printList(L);

    value = 2;
    removeNode(L, value);
    printList(L);

    value = 3;
    removeNode(L, value);
    printList(L);

    value = 1;
    removeNode(L, value);
    printList(L);

    value = 2;
    removeNode(L, value);

    return 0;
}
