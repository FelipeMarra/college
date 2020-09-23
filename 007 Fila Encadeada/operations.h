// A struct with the First and Last position of the Queue
typedef struct queue* Queue;

//A struct with a value and a pointer to the next node
typedef struct node* Node;

//A function to create a Queue struct 
Queue createQueue();

//A function to insert a node 
Queue insertValue(Queue Q, int value);

//Function to remove a node
Queue removeValue(Queue Q);

//print the Queue
Queue printQueue(Queue Q);