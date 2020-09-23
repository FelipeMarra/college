//Out List type
typedef struct list* List;

//Initialize a List type
List initializeList();

//Prints the listArray of the list passed by parameter
void printList(List L);

//Function to look for something in the List->listArray, (the List, the value u looking for)
//Retuns the postion if the value was found and -1 if it wasent
int search(List L,int value);

//Funtion to inset something into the List->listArray, (the List, the value u want to inset)
//Retuns the postion if the value was inserted, -1 if it already exists, 
//and -2 if the list is fully ocupied
int insert(List L,int value);

//Function to delete a value into the List->listArray, (the List, the value u want to remove)
//Returns the position of the deleted value if it was deleted and -1 if the value was not
//on the list
int delete(List L, int value);