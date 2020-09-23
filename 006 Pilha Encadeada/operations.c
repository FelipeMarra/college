#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

//the node struct
struct node
{
    //With a value
    int value;
    //And the next node,k
    Node next;
};

//Function to create a node
Node createNode(){
    //Declare a node N
    Node N;
    //Allocate memory to it
    N = malloc(sizeof(struct node));
    //By default the next node is NULL
    N->next = NULL;
    //And the value -1
    N->value = -1;
    return N;
}

//The stack struct just contains a pointer that points to the top Node
struct stack
{
    Node Top;
};

//Then we have a function to create a stack
Stack createStack(){
    //Declaring a Stack type
    Stack S;
    //Allocating memory
    S = malloc(sizeof(struct stack));
    //The top is just a node that will point to the top node
    S->Top = createNode();
    return S;
}

//Function to print the stack
Stack printStack(Stack S){
    //A Node to loop it
    Node CurrentNode;
    //that begins pointing to the top node
    CurrentNode = S->Top;
    //If the top node is null its because the Stack is empty
    if(CurrentNode->next == NULL){
        printf("\n\nEMPTY STACK!!!!!!\n\n");
        //So we return NULL
        return NULL;
    }

    printf("\n\nYOUR STACK!!!!!!:\n");

    int count = 0;
    //While there is a next node
    while (CurrentNode != NULL)
    {   //bla bla bla
        printf("\nCount: %d; Memory: %p; Value: %d\n", count, CurrentNode, CurrentNode->value);
        //The current node must go to the next one
        CurrentNode = CurrentNode->next;
        count++;
    }

    printf("\nEND OF STACK!!!!!!\n\n");
}

//Funtion to push the values
Stack push(Stack S, int value){
    //We just create a new node
    Node New;
    New = createNode();
    //Set the value to the one passed by the user
    New->value = value;
    //Set the next value to the one the is the current top node
    New->next = S->Top;
    //And the top node now have to be the one we just created
    S->Top = New;
}

//Function to pop the values
Stack pop(Stack S){
    //Create a node that will represent the onde we'll remove
    Node NodeToRemove;
    //Obviously it will be igual to the top node
    NodeToRemove = S->Top;
    //And we have to know if the list is not empty
    if(NodeToRemove->next == NULL){
        printf("\nEMPTYYYYY\n");
        return NULL;
    }
    //Than the top node points to the one under the current top
    S->Top = NodeToRemove->next;
    //And we release the memory 
    free(NodeToRemove);
}