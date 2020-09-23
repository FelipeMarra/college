#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int main()
{

    List L;
    L = createList();

    int value = 1;
    insertNode(L,value);
    printListFoward(L);
    printListBackward(L);

    value = 2;
    insertNode(L,value);
    printListFoward(L);
    printListBackward(L);

    value = 3;
    insertNode(L,value);
    printListFoward(L);
    printListBackward(L);

    removeNode(L,value);
    printListFoward(L);
    printListBackward(L);

    value = 1;
    removeNode(L,value);
    printListFoward(L);
    printListBackward(L);

    value = 10;
    removeNode(L,value);
    printListFoward(L);
    printListBackward(L);


    value = 2;
    removeNode(L,value);
    printListFoward(L);
    printListBackward(L);


    value = 1;
    removeNode(L,value);

    return 0;
}
