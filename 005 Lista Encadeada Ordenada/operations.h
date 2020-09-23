//A struct for the nodes
typedef struct node* Node;
//A struct for the nodes ordered list
typedef struct list* List;

//Creates the list
List initilizeList();

//Print List
int printList(List L);

//Search for a node
Node searchNode(List L, int value, Node *LastNode);

//Add a node in the correct position to mantain the order
Node insertNode(List L, int value);

Node removeNode(List L, int value);