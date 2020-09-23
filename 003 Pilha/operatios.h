//Declaring the stack structure
typedef struct stack* Stack;

//Generating a new stack
Stack initializeStack();

//Print the full stack
void showFullStack(Stack S);

//get the strack's top value
int getTop(Stack S);

int push(Stack S, int value);

int pop(Stack S, int value);