#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

//Our node
struct node
{
    //With a value
    int value;
    //Anda a pointer to the next node
    Node next;
};

//A funtion to create a node
Node createNode(){
    //Creating the pointer and allocating memory
    Node N = malloc(sizeof(struct node));
    //By default the next node is NULL
    N->next = NULL;
    N->value = -1;
    
    return N;
}

//A struct for our queue
struct queue
{
    //With a pointer to the first node
    Node First;
    //And the last one
    Node Last;
};

//Function to create the queue
Queue createQueue(){
    //Declaring the struct and allocating memory
    Queue Q;
    Q = malloc(sizeof(struct queue));
    //Creating the nodes for the  pointers First and Last
    Q->First = createNode();
    Q->Last = createNode();

    return Q;
}

//Function to print the Queue
Queue printQueue(Queue Q){
    //If its empty return NULL
    if(Q->First->next == Q->Last->next && Q->Last->next == NULL){
        printf("\n\n EMPTY Q\n\n");
        return NULL;
    }

    //A node to loop the queue, starting by the first position, and a counter for no reason
    Node CurrentNode;
    CurrentNode = Q->First->next;
    int count = 0;  
    
    printf("\n\n YOUR Q\n\n");
    
    //While there is a node
    while (CurrentNode != NULL)
    {   //bla bla bla
        printf("Counter in position order:%d; Memory: %p; Value: %d\n", 
        count, CurrentNode, CurrentNode->value);
        
        //We move to the next node and increase the counter
        CurrentNode = CurrentNode->next;
        count++;
    }
    printf("\n\n END OF Q\n\n");    
}

//Function to insert values at the end of the queue
Queue insertValue(Queue Q, int value){
    //Create a new node
    Node New = createNode();

    //Give to it the value passed by the user
    New->value = value;
    //When adding the first node, both First and Last pointers must point to that node
    if (Q->Last->next == NULL){
        Q->Last->next = New;
        Q->First->next = New;
    } 
    //If it isent the first time
    else
    {   
        //We create a axiliar node that will be the last node
        Node LastNode;
        LastNode = Q->Last->next;
        //The last node will point to the new one 
        //The first node points to the second, that points to the third...So we can remove from the first position
        LastNode->next = New;
        //And the Q->Last will point to the new one, cause it is the new last node
        Q->Last->next = New;
    }
}

//Funtion to remove a value from the first position
int removeValue(Queue Q){
    int lastValue = Q->Last->value;
    //If the queue is empty return NULL, cause there is nothing there to remove
    if(Q->First->next == Q->Last->next && Q->Last->next == NULL){
        printf("\n\n EMPTY Q\n\n");
        return -1;
    }

    //if we are going to remove the first item, both Queue pointers must go back to NULL
    if(Q->Last->next == Q->First->next){
        Q->Last->next = NULL;
        Q->First->next = NULL;
    //Otherwise
    }else
    {
        //We create a axiliar node that will be the onde to remove
        Node NodeToRemove;
        //We will remove the first node
        NodeToRemove = Q->First->next;
        //The first node is now the second one
        Q->First->next = NodeToRemove->next;
        free(NodeToRemove);        
    }
    return lastValue;
}

bool vazio(Queue Q){
    if(Q->First->next == NULL && Q->Last->next == NULL)
        return true;
    return false;
}