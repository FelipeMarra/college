#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "hash.h"

struct cell{
    int key;
    int chainPosition;
    int wordLines[50];
    int occurrences;
    char word[50];
    bool isEmpty;
    Cell next;
};

Cell createCell(){
    Cell C;
    C = malloc(sizeof(struct cell));
    C->key = 0;
    C->occurrences = 0;
    C->chainPosition = 0;
    C->next = NULL;
    C->isEmpty = true;
    return C;
};

struct hashTab{
    Cell* tab;
    int Size;
};

HashTab createHashTab(int Size){
    int i;
    HashTab H;
    H = malloc(sizeof(struct hashTab));
    H->tab = malloc(Size * sizeof(struct cell));
    for (i = 0; i < Size; i++)
        H->tab[i] = createCell();    
    H->Size = Size;
    return H;    
}

int hash(char word[], HashTab H){
    int i,sum,strSize;
    sum = 0;
    strSize = strlen(word);
    for (i = 0; i < strSize; i++) 
        sum +=  word[i];
    return (sum % H->Size);
}

void putDataIntoCell(Cell C, int h, char word[], int wordLines[], int occurrences){
    int i;
    C->occurrences = occurrences;
    for (i = 0; i < C->occurrences; i++)//Copy wordlines array
        C->wordLines[i] = wordLines[i];
    strcpy(C->word, word);//Passing the string to the cell
    C->key = h;
    C->isEmpty = false;
}

Cell insertInTab(char word[], int wordLines[], int occurrences, HashTab H){
    //Getting the hash value and Creating a new cell
    int h = hash(word, H);
    if (H->tab[h]->isEmpty == true)//If the position we want to insert is empty
    {//Just put the values there
        putDataIntoCell(H->tab[h], h, word, wordLines, occurrences);
        return H->tab[h];
    }
    //Otherwise 
    Cell C;
    C = createCell();
    //Putting the cell into the hash tab
    putDataIntoCell(C, h, word, wordLines, occurrences);
    Cell Ant;
    Ant = H->tab[h];
    int chainPosition = 1;
    while (Ant->next != NULL){//loop the tab from the cell h till we find a empty position
        Ant = Ant->next;
        chainPosition++;
    }
    C->chainPosition = chainPosition;
    C->next = Ant->next;
    Ant->next = C;
    return C;
}

Cell searchInTab(char word[], HashTab H){
    int h = hash(word, H);
    Cell Ant;
    Ant = H->tab[h];
    if(Ant->next == NULL && strcmp(Ant->word,word) == 0)//If the word is in an chain with 1 position
        return Ant;
    while (Ant->next != NULL){
        if(strcmp(Ant->word,word) == 0)//If the cell contains the word we looking for
            return Ant;//retunr it
        Ant = Ant->next;//Else, go to the next one
    }
    printf("Not in there");
    return NULL;//If we leave the loop its because that word was not found
}

void printCell(Cell C){
    int i;
    for (i = 0; i < C->occurrences; i++)
    {
        printf("Cell Position(hash value): %i, Chain Position:%i, Word: %s, Line: %i",
                        C->key,C->chainPosition,C->word, C->wordLines[i]);    
    }
    printf("\n");
}

void printHash(HashTab H){
    int i;
    for (i = 0; i < H->Size; i++)
    {
        if(H->tab[i]->isEmpty == true){
            printf("Cell Position(hash value): %i is empty \n",i); 
        }else
        {
            int flag = 0;
            Cell Ant;
            Ant = H->tab[i];
            int j = 0;
            while (flag == 0){
                printCell(Ant); 
                if(Ant->next == NULL)
                    flag = 1;
                Ant = Ant->next;
                j++;
            }
        }
        
    }
    printf("\n");
}