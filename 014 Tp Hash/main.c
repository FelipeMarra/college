#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text/text.h"
#include "hash/hash.h"

void main () {
    Word W;
    Cell C;
    HashTab H;
    H = createHashTab(10);//Creating a hash table size 10
    int nuWord, answer, answer2;
    int *nuLine;
    int x = 0;
    char fileName[100];
    char word[50];

    while(x == 0) {
        printf("Type 1 to search for a word of the text file\n"); 
        printf("Type 2 to print the entire Hash\n"); 
        printf("Type 3 to search for a word that is already in the Hash \n "); 
        printf("Type 0 to close the application: \n"); 

	    scanf("%d", &answer);
        
        if(answer == 0)
            break;
        
        if(answer > 3 || answer < 0)
            printf("Invalid option!\n");

        if(answer == 1) {
            printf("Type the word that you want to search :\n");
            setbuf(stdin, NULL);
            gets(word);
            printf("Type the path to the txt file:\n");
            setbuf(stdin, NULL);
            gets(fileName);
            printf("file name: %s", fileName);
            W = getInfo(fileName,word);
            if(W != NULL){
                nuWord = getNWord(W);
                nuLine = getWLines(W);
                printWord(W);
                printf("Do you want to insert this word info into the hash? y/n");
                scanf("%c", &answer2);
                if (answer2 == 'y')
                {
                    C = insertInTab(word, nuLine, nuWord, H);
                    printf("Do you want to print the cell where the word was stored? y/n\n");
                    scanf("%d", &answer2);
                    if (answer2 == 'y'){
                        printCell(C); 
                        printf("\n");
                    }
                }
            }
        }
        
        if(answer == 2)
            printHash(H);

        if(answer == 3) {
            printf("Type the word that you want to search: \n");
            scanf("%s",word);
            C = searchInTab(word,H);
            printCell(C); printf("\n");
        }
    }
}