typedef struct list* List;
typedef struct node* Node;

List createList();
int printList(List L);
Node searchNode(List L, int value, Node *LastNode);
Node insertNode(List L, int value);
Node deleteNode(List L, int value);