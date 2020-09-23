#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

//List size
#define ListSize 10

//Our List type
struct list{
    //Our current position in the list
    int currentPosition;
    //Our list array
    int listArray[ListSize];
};

//Initialize a List type
List initializeList(){
    //Creating a list called L
    List L = malloc(sizeof(struct list));
    //Initializing the position counter
    L->currentPosition = 0;
    return L;
}

//Obviouly that prints the listArray of the list passed by parameter
void printList(List L){
    printf("Yuor List:\n");
    for (int i = 0; i < L->currentPosition; i++){
        printf("Memory: %p postion [%d]: %d \n", 
        &(L->listArray[i]),i,L->listArray[i]);
    }
    printf("End of list \n");
}

//Function to look for something in the List->listArray
int search(List L,int value){
    //Loop to check if the value passed is in the List
    for (int i = 0; i < L->currentPosition; i++)
    {
        //If the listArray at position i is equal the value
        if(L->listArray[i] == value){
            //Return the position where the value was found
            return i;
        }
    }
    //Case the value wasnt found in the List
    //Retunr -1, wich is a invalid position in a array 
    return -1;
}

//Function to insert something in the List->listArray
int insert(List L, int value){
    //If we didnt use all the Lists array positions
    if(L->currentPosition < ListSize){
        //We will make a search for the value
        int searchReturn = search(L, value);
        //If search returns something different than -1 its because the value exists in the list
        if(searchReturn != -1){
            //Returning a error for values that exists
            return -1;
        //Else the value dosent exists yet so we can insert it
        }else{
            //Into the current array postion we insert the value
            L->listArray[L->currentPosition] = value;
            //Than we increase our current position counter
            L->currentPosition++;
            //Returning the position where the value was inserted
            return L->currentPosition;
        }
    }else
    {
        //Returning a error for no space
        return -2;
    }
}

//Function to delete a postion
int delete(List L, int value){
    //Searching to know if the value exists
    int searchReturn = search(L,value);
    //If it does lets remove it
    if(searchReturn != -1){
        //First we decrease the postion counter
        L->currentPosition--;
        //Then we loop the values so we shitft all the positions subscripting the removing point
        for (int i = searchReturn; i < L->currentPosition; i++)
        {
            printf("\n delete function: i = %d, L->listArray[i] %d, next %d \n", 
                                        i,      L->listArray[i],    L->listArray[i+1]);

            L->listArray[i] = L->listArray[i+1];      
        }
        //Returning searchReturn as a sucsses code
        return searchReturn; 
    }
    //If it doesent lets return a error
    else
    {
        return -1;
    }
    
}