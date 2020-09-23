#include <stdlib.h>
#include <stdio.h>
#include "operations.h"

int main()
{   
    //Creating a List type pointes
    List L;
    //Inserting a list struct into it
    L = initializeList();
    //Initializing a varible that will contain the user operation inputs
    int operationNumber = 0;
    //Initializing a varible that will contain the value user whats to pass to the operations
    int value;
    //Variable to get the retutn of the operations
    int operationsReturn;
    //PRINTING THE LIST FOR NO REASON
    printList(L);

    //A infinit loop to get user inputs
    while (1)
    {
        //the menu
        printf("Type the operation you want \n");
        printf("0 -> Print List \n 1 -> Search \n 2-> Insert \n 3-> Delete \n operation: ");
        scanf("%d", &operationNumber);
        //switching the input
        switch (operationNumber)
        {
        case 0:
            printList(L);
        case 1:
            printf("Type the value you looking for: ");
            scanf("%d", &value); 
            operationsReturn = search(L, value);
            if(operationsReturn == -1){
                //Say we didint find it
                printf("Value not found \n");
            }else
            {
                //Say that we found it
                printf("Value found in array position %d\n", operationsReturn);
            }
            printList(L);
            break;
        case 2:
            printf("Type the value you want to insert: ");
            scanf("%d", &value); 
            operationsReturn = insert(L, value);
            if(operationsReturn == -1){
                //Say it already exists
                printf("The value already exists \n");
            }else if(operationsReturn == -2)
            {
                //Say the list is fully ocupied
                printf("The list is fully ocupied %d\n");
            }else
            {
                //Say that we inserted it
                printf("Value inserted in array position %d\n", operationsReturn);
            }
            printList(L);
            break;
        case 3:
            printf("Type the value you want to delete: ");
            scanf("%d", &value); 
            operationsReturn = delete(L, value);
            if(operationsReturn == -1){
                printf("The value you want to delete dosent exist");
            }else
            {
                printf("List value %d deleted sucssesfully\n", operationsReturn);
            }
            printList(L);
            break;
        default:
            printf("insert a valid operation\n");
            break;
        }        
    }
    
    return 0;
}
