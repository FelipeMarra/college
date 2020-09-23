#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

struct node
{
    int value;
    Node after;
    Node before;
};

Node createNode(){
    Node N;
    N = malloc(sizeof(struct node));
    N->after = NULL;
    N->before = NULL;
    return N;
}

struct list
{
    Node Head;
};

List createList(){
    List L;
    L = malloc(sizeof(struct list));
    L->Head = createNode();
    L->Head->after = L->Head;
    L->Head->before = L->Head;
    return L;
}

//Print List
int printListFoward(List L){
    //A node to loop the entire list
    Node CurrentNode;
    //The first node is the head next
    CurrentNode = L->Head->after;
    //If no nodes have been added to the list yet the head still pointing to null
    if(CurrentNode == L->Head){
        //So we know the list is empty
        printf("Empty List\n");
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
        CurrentNode = CurrentNode->after;
        counter++;
    }
    printf("End of List \n\n");  
return 0;  
}

//Print List
int printListBackward(List L){
    //A node to loop the entire list
    Node CurrentNode;
    //The first node is the head next
    CurrentNode = L->Head->before;
    //If no nodes have been added to the list yet the head still pointing to null
    if(CurrentNode == L->Head){
        //So we know the list is empty
        printf("Empty List\n");
        return -1;
    }
    //A counter for the nodes for no reason
    int counter = 0;
    printf("\nYour List: \n");
    //While we didint reach the end the next property of a node cant be null
    while (CurrentNode != L->Head)
    {
        printf("Node number: -%d; Value: %d, Memory: %p \n", counter, CurrentNode->value, CurrentNode);
        //And in the next loop we will go to next node and so on
        CurrentNode = CurrentNode->before;
        counter++;
    }
    printf("End of List \n\n");  
return 0;  
}


Node searchNode(List L, int value, Node *LastNode){
    printf("serach\n\n");
    Node CurrentNode = L->Head->after;
    *LastNode = L->Head;

    while (CurrentNode != L->Head)
    {
        if(CurrentNode->value < value){
            *LastNode = CurrentNode;
            CurrentNode = CurrentNode->after;
        }else if(CurrentNode->value == value){
            return CurrentNode;
        }
    }
    return NULL;
}

Node insertNode(List L, int value){
    printf("INSERT\n\n");
    Node LastNode;
    
    if (searchNode(L, value, &LastNode) != NULL){
        printf("\ninsertNode: Value already exists\n");
        return NULL;
    }

    Node CurrentNode;    
    CurrentNode = LastNode->after;

    Node New;
    New = createNode();
    New->value = value;

    New->after = CurrentNode;
    New->before = LastNode;
    LastNode->after = New;
    CurrentNode->before = New;

    return New;
}

Node removeNode(List L, int value){
    if(L->Head->after == L->Head){
        printf("\nremoveNode: Empty List\n");
        return NULL;
    }

    Node LastNode;
    Node NodeToRemove;

    NodeToRemove = searchNode(L, value, &LastNode); 
    if(NodeToRemove == NULL){
        printf("\nremoveNode: Value not found\n");
        return NULL;
    }

    LastNode->after = NodeToRemove->after;
    (NodeToRemove->after)->before = LastNode; 

    free(NodeToRemove);

    return LastNode;
}



















