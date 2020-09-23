#include <stdio.h>
#include <stdlib.h>
#include "operatios.h"

int main()
{
    Stack S;
    S = initializeStack();

 //Initializing a varible that will contain the user operation inputs
    int operationNumber = 0;
    //Initializing a varible that will contain the value user whats to pass to the operations
    int value;
    //Variable to get the retutn of the operations
    int operationsReturn;
    //PRINTING THE LIST FOR NO REASON
    showFullStack(S);

    //A infinit loop to get user inputs
    while (1)
    {
        //the menu
        printf("\nType the operation you want \n");
        printf("0 -> Show Full Stack \n 1 -> Get Top\n 2-> Push\n 3-> Pop \n Operation: ");
        scanf("%d", &operationNumber);
        //switching the input
        switch (operationNumber)
        {
        case 0:
            showFullStack(S);
        case 1:
            operationsReturn = getTop(S);
            if(operationsReturn == -1){
                //
                printf("Empty stack \n");
            }else
            {
                //
                printf("\nTop value = %d\n", operationsReturn);
            }

            showFullStack(S);
            break;
        case 2:
            printf("Type the value you want to push into the stack: ");
            scanf("%d", &value); 
            operationsReturn = push(S, value);
            if(operationsReturn == -1){
                printf("Overflow\n");
            }else
            {
                printf("Value %d pushed into position %d\n", value, operationsReturn);
            }

            showFullStack(S);
            break;
        case 3:
            printf("Status: ");
            operationsReturn = pop(S, value);
            if(operationsReturn == -1){
                printf("Underrflow\n");
            }else
            {
                printf("Positon %d poped out of the stack\n", operationsReturn);
            }

            showFullStack(S);
            break;
        default:
            printf("insert a valid operation\n");
            break;
        }        
    }
    
    return 0;
}
