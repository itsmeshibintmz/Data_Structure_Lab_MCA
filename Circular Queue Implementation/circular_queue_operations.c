/* C Program to perform Circular Queue Operations such as Add, 
    Delete and Search */

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 100 
/* A structure to represent a queue */
typedef struct {
    int front, rear;
    int size;
    int *array;
} queue;
/* Function to create a queue of given size */
queue *createQueue(int size) {
    queue *q = (queue *)malloc(sizeof(queue));
    q->size = size;
    q->front = q->rear = -1;
    q->array = (int *)malloc(sizeof(int)*size);
    return q;
}
/* Function to check if queue is full */
int isFull(queue *q) {
    return (q->rear == q->size-1);
}
/* Function to check if queue is empty */
int isEmpty(queue *q) {
    return (q->front == -1);
}
/* Function to add an item to the queue */
void enqueue(queue *q, int element) {
    if(isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if(q->front == -1)
        q->front = 0;
    q->rear = q->rear + 1;
    q->array[q->rear] = element;
}
/* Function to remove an item from queue */
int dequeue(queue *q) {
    int element;
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        return INT_MIN;
    }
    element = q->array[q->front];
    q->front = q->front + 1;
    if(q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return element;
}
/* Function to display the queue */
void display(queue *q) {
    int i;
    if(isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are:\n");
    for(i=q->front;i<=q->rear;i++)
        printf("%d\n",q->array[i]);
}
/* Function to search an element in queue */
void searchQueue(queue *q) {
    int element, i, flag = 0;
    printf("Enter the element to be searched\n");
    scanf("%d",&element);
    for(i=q->front;i<=q->rear;i++) {
        if(q->array[i] == element) {
            printf("Element found at location %d\n",i);
            flag = 1;
            break;
        }
    }
    if(flag == 0)
        printf("Element not found\n");
}
/* Driver program to test above functions */
int main() {
    queue *q = createQueue(MAX);
    int choice, element, i;
    while(1) {
        /* Take choice from user */
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Search\n5. Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Enter the element to be inserted\n");
                scanf("%d",&element);
                enqueue(q,element);
                break;
            case 2:
                element = dequeue(q);
                if(element != INT_MIN)
                    printf("Dequeued element is %d\n",element);
                break;
            case 3:
                display(q);
                break;
            case 4:
                searchQueue(q);
                break;
            case 5:
                printf("Exiting, bye!");
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}

// Algorithm:
// 1. Create a queue of size MAX.
// 2. Display the menu.
// 3. Take the choice from the user.
// 4. Perform the corresponding operation.  If the choice is 1, then enqueue the element. 
// If the choice is 2, then dequeue the element.  If the choice is 3, then display the queue.
// If the choice is 4, then search the queue.
// 5. Exit.
// 6. If the choice is not 1, 2, 3 or 4, then display the error message.
// 7. Repeat the steps 2 to 6 until the choice is 5.
// 8. Exit.
// 9. If the choice is 5, then exit.
// 10. Exit

// Output:
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Search
// 5. Exit
// Enter your choice
// 1
// Enter the element to be inserted
// 10
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Search
// 5. Exit  
// Enter your choice
// 1
// Enter the element to be inserted
// 20
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Search
// 5. Exit
// Enter your choice
// 1
// Enter the element to be inserted
// 30
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Search
// 5. Exit
// Enter your choice
// 1
// Enter the element to be inserted
// 40
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Search
// 5. Exit
// Enter your choice
// 1
// Enter the element to be inserted
// 50
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Search
// 5. Exit
// Enter your choice
// 2
// Dequeued element is 10
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Search
// 5. Exit
// Enter your choice
// 2
// Dequeued element is 20
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Search
// 5. Exit
// Enter your choice
// 2
// Dequeued element is 30
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Search
// 5. Exit
// Enter your choice
// 2
// Dequeued element is 40
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Search
// 5. Exit
// Enter your choice
// 2
// Dequeued element is 50
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Search
// 5. Exit
// Enter your choice
// 3
// Queue elements are:
// 10
// 20
// 30
// 40
// 50
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Search
// 5. Exit
// Enter your choice
// 4
// Enter the element to be searched
// 10
// Element found at location 0
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Search
// 5. Exit
// Enter your choice
// 4
// Enter the element to be searched
// 20
// Element found at location 1
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Search
// 5. Exit
// Enter your choice
// 4
// Enter the element to be searched
// 30
// Element found at location 2
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Search
// 5. Exit
// Enter your choice
// 4
// Enter the element to be searched
// 40
// Element found at location 3
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Search
// 5. Exit
// Enter your choice
// 5
// Exiting, bye!