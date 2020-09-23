//The strcut of the stack and a pointer to it
typedef struct stack* Stack;

//The strcut of the stack nodes and a pointer to it
typedef struct node* Node;

//Function that returns a new stack
Stack createStack();

//Function to push(add to the top) a value
Stack push(Stack S, int value);

//Function to pop(remove from the top) a value
Stack pop(Stack S);

//Print the stack
Stack printStack(Stack S);