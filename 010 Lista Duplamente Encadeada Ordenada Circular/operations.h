typedef struct node* Node;
typedef struct list* List;

Node searchNode(List L, int value, Node *LastNode);

Node insertNode(List L, int value);
Node removeNode(List L, int value);

int printListFoward(List L);
int printListBackward(List L);

List createList();