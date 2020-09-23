#include <stdlib.h>
#include <stdio.h>
#include "operations.h"

struct node
{
    int value;
    Node next;
};

Node createNode(){
    Node N;
    N = malloc(sizeof(struct node));
    N->next = NULL;
    return N;
}

struct list{
    Node Head;
};

List createList(){
    List L;
    L = malloc(sizeof(struct list));
    L->Head = createNode();
    return L;
}


//Print List
int printList(List L){
    //A node to loop the entire list
    Node CurrentNode;
    //The first node is the head next
    CurrentNode = L->Head->next;
    //If no nodes have been added to the list yet the head still pointing to null
    if(CurrentNode == NULL){
        //So we know the list is empty
        printf("Empty List\n");
        return -1;
    }
    //A counter for the nodes for no reason
    int counter = 0;
    printf("\nYour List: \n");
    //While we didint reach the end the next property of a node cant be null
    while (CurrentNode != NULL)
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
    Node CurrentNode;
    *LastNode = L->Head;
    CurrentNode = L->Head->next;

    while (CurrentNode != NULL)
    {
        if (CurrentNode->value != value){
            *LastNode = CurrentNode;
            CurrentNode = CurrentNode->next;
        }else{
            return CurrentNode;
        }
    }
    
    return NULL;
}


Node insertNode(List L, int value){
    Node LastNode;
    if (searchNode(L,value, &LastNode) != NULL){
        printf("Value already exists or empty list\n");
        return NULL;
    }

    Node New;
    New = createNode();
    New->value = value;
    LastNode->next = New;
    return New;
}


Node deleteNode(List L, int value){
    if(L->Head->next == NULL){
        printf("\ndeleteNode: Empty List\n");
        return NULL;
    }

    Node LastNode;
    Node NodeToRemove;
    NodeToRemove = searchNode(L, value, &LastNode); 
    
    if(NodeToRemove == NULL){
        printf("\ndeleteNode: Value Not Found\n");
        return NULL;
    }

    LastNode->next = NodeToRemove->next;
    free(NodeToRemove);
}

