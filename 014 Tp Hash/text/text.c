#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "text.h"

struct word{
  int nWord; // How many words like that exist in the text
  int wLine[50]; // Which lines they are located in the text
};

Word getInfo(char fileName[], char word[]){ //read the text and return where are the word and how many of them exist in the text
  Word W; // Create a struct word named W
  W = malloc(sizeof(struct word));

  int line = 1; //total de linhas
  int count = 0; //total de palavras
  char str[100];
  FILE *arq;
  arq = fopen(fileName,"r"); //open the file to read it
  if (arq == NULL)
  {
    printf("ERROR 404 File not found \n");
    return NULL;
  }
  int i=0;
  while(fgets(str,100, arq) != NULL) {
    if(strstr(str, word) != 0) {//compare a string inside another string(usualy a line)
      count++; //increase the count everytime the requested word is found
      W->wLine[i] = line;//save the current line in the position i
      i++;
      }
    line++;
    }
    W->nWord = count;
    return W;
}

int getNWord(Word W){
  return W->nWord;
}

int *getWLines(Word W){
  static int wLine[50];
  for (int i = 0; i < W->nWord; i++)
    wLine[i] = W->wLine[i];
  return wLine;
}

void printWord(Word W){
  printf("\nWe found the word the word %d times!\n in the lines:\n", W->nWord);
  for(int i = 0; i < W->nWord; i++)
    printf("%d\n", W->wLine[i]);
}
