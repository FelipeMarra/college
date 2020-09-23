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
    //By default the next node is null and the value is 0
    N->next = NULL;
    N->value = 0;
    return N;
}

//Creates a list
List initilizeList(){
    List L;
    //Allocating memory    
    L = malloc(sizeof(struct list));
    //Creating the head node
    L->Head = creatNode();
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

//Search a node
//The last node is here just to serve the other operations
Node searchNode(List L, int value, Node *LastNode){
    printf("\nSEARCH\n");
    //A node to save the last node, initialized with the head cause if the list is empty...
    *LastNode = L->Head;
    //The node to loop the list, initialized whith the head next node
    Node CurrentNode = L->Head->next;
    //While there is a next node
    while (CurrentNode != NULL)
    {
        printf("\nSEARCH LOOP Node%p value%d Next node %p \n", CurrentNode,CurrentNode->next,CurrentNode->value);
        //If the value of that node is what we looking for is smaller than the value we searching
        if(CurrentNode->value < value){
            //We have to save that in the LastNode
            *LastNode = CurrentNode;
            //And go for the next node
            CurrentNode = CurrentNode->next;
        }
        //If the value is what we are looking for
        else if(CurrentNode->value == value){
            //Just return the current node. The last node is all hight 
            //cause it have the current node of the last loop
            return CurrentNode;
        }
    }
    //If we find nothing return NULL
    return NULL;
}

//Insert a Node
Node insertNode(List L, int value){
    printf("\nINSERRRRT\n");
    //Creating the LastNode that will be a parameter at the search function
    Node LastNode;
    //If the serch function return null is because that value we want to insert is already in the list
    if(searchNode(L, value, &LastNode) != NULL){
        printf("Value already exists");
        //And we just return null
        return NULL;
    }
    printf("Last node %p %d", LastNode, LastNode->value);
    //If the last condition is false, we can insert the node
    Node New = creatNode();
    //With a value equal to the one passed by the user
    New->value = value;
    //And pointing to the next node after the LastNode
    New->next = LastNode->next;
    //And the next node points to the node we created
    LastNode->next = New;
    //And we just return the new node
    return New;
}

//Remove a node
Node removeNode(List L, int value){
    printf("REMOVE");
    //Creating the LastNode that will be a parameter at the search function
    Node LastNode;
    //If the search function return NULL or if the list is empty we cant remove the value cause it dosent exist 
    if(searchNode(L, value, &LastNode) == NULL || L->Head->next == NULL){
        printf("\nValue not found or empty list\n");
        return NULL;
    }
    //So if the last condition is not satisfied we can remove the node
    //First we get it from the next nodo of LastNode
    Node NodeToRemove = LastNode->next;
    //The next node of the LastNode will be the ontge that the node we are removing was pointing to
    LastNode->next = NodeToRemove->next;
    //And finally we deallocate the memory of the node we are removing
    free(NodeToRemove);
    return NodeToRemove;
}