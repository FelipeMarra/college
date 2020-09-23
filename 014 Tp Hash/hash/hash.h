typedef struct hashTab* HashTab; //Contais the H->tab which is the table it self
//And the H->Size which is the size of the table

typedef struct cell *Cell;//A Hash table cell. For user purpose it contains:
//int C->key = its hash value; char C->word[] = the word sotored in there;
//int C->wordlines[] = in which lines the word was found

//Receives the size that you want for you hash tab
HashTab createHashTab(int Size);//Return a new hash tab with the size passed by parameter

//Receives the word, in which lines it was found
//the number of occurrences, and the hash tab
Cell insertInTab(char word[], int wordLines[], int occurrences, HashTab H);
//Returns the new cell

//Receives the word and the hash tab
int hash(char word[], HashTab H);//Returns the hash value based on the letters ASCII value

//Receives the word and the hash tab
Cell searchInTab(char word[], HashTab H);//Returns the tab cell that contains that word
//in case we succeed, and NULL in case we fail

//No need to explain those ones:
void printCell(Cell C);
void printHash(HashTab H);
