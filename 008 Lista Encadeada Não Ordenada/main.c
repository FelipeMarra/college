#include <stdlib.h>
#include <stdio.h>
#include "operations.h"

int main()
{
    List L;
    L = createList();

    int value = 1;
    insertNode( L,  value);
    printList(L);

    value = 2;
    insertNode( L,  value);
    printList(L);

    value = 3;
    insertNode( L,  value);
    printList(L);

    deleteNode( L,  value);
    printList(L);

    value = 1;
    deleteNode( L,  value);
    printList(L);

    value = 2;
    insertNode( L,  value);
    printList(L);

    value = 10;
    deleteNode( L,  value);
    printList(L);

    value = 2;
    deleteNode( L,  value);
    printList(L);

    deleteNode( L,  value);

    return 0;
}
