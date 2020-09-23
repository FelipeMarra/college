typedef struct node* Node;
typedef struct list* List;

List initilizeList();

int printList(List L);

Node searchNode(List L, int value, Node *LastNode);

Node insertNode(List L, int value);

Node removeNode(List L, int value);