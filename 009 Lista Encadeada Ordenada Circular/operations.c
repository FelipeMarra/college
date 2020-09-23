#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

//Node struct
struct node
{
    //With a int value
    int value;
    //And a pointer to the next node
    Node next;
};

//Node List
struct list
{
    //With a pointer to the head node
    Node Head;
};

//Create node
Node creatNode(){
    Node N;
    //Allocating memory
    N = malloc(sizeof(struct node));
    //By default the next node is null
    N->next = NULL;
    return N;
}

//Creates a list
List initilizeList(){
    List L;
    //Allocating memory    
    L = malloc(sizeof(struct list));
    //Creating the head node
    L->Head = creatNode();
    L->Head->next = L->Head;
    return L;
}

//Print List
int printList(List L){
    //A node to loop the entire list
    Node CurrentNode;
    //The first node is the head next
    CurrentNode = L->Head->next;
    //If no nodes have been added to the list yet the head still pointing to null
    if(CurrentNode == L->Head){
        //So we know the list is empty
        printf("\nEmpty List\n");
        return -1;
    }
    //A counter for the nodes for no reason
    int counter = 0;
    printf("\nYour List: \n");
    //While we didint reach the end the next property of a node cant be null
    while (CurrentNode != L->Head)
    {
        printf("Node number: %d; Value: %d, Memory: %p \n", counter, CurrentNode->value, CurrentNode);
        //And in the next loop we will go to next node and so on
        CurrentNode = CurrentNode->next;
        counter++;
    }
    printf("End of List \n\n");  
return 0;  
}

Node searchNode(List L, int value, Node *LastNode){
    *LastNode = L->Head;
    Node CurrentNode = L->Head->next;
    while (CurrentNode != L->Head)
    {
        if (CurrentNode->value < value){
            *LastNode = CurrentNode;
            CurrentNode = CurrentNode->next;
        }else if (CurrentNode->value == value){
            return CurrentNode;
        }
    }

    return NULL;
}

Node insertNode(List L, int value){
    Node LastNode;
    if (searchNode(L, value, &LastNode) != NULL){
        printf("\ninsertNode: Value already exists\n");
        return NULL;
    }
    
    Node New = creatNode();
    New->value = value;
    New->next = LastNode->next;
    LastNode->next = New;
}

Node removeNode(List L, int value){
    Node LastNode;
    Node NodeToRemove = searchNode(L, value, &LastNode);
    
    if (L->Head->next == L->Head){
        printf("\nremoveNode: Empty List\n");
        return NULL;
    }

    if(NodeToRemove == NULL){
        printf("\nremoveNode: Value not found\n");
        return NULL;
    }

    LastNode->next = NodeToRemove->next;
    free(NodeToRemove);
}