/* C Program to perform Circular Queue Operations such as Add, Delete and Search */
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 100 
typedef struct {
    int front, rear;
    int size;
    int *array;
} queue;
queue *createQueue(int size) {
    queue *q = (queue *)malloc(sizeof(queue));
    q->size = size;
    q->front = q->rear = -1;
    q->array = (int *)malloc(sizeof(int)*size);
    return q;
}
int isFull(queue *q) {
    return (q->rear == q->size-1);
}
int isEmpty(queue *q) {
    return (q->front == -1);
}
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
int main() {
    queue *q = createQueue(MAX);
    int choice, element, i;
    while(1) {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
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
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
// Output:
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Exit
// Enter your choice
// 1
// Enter the element to be inserted
// 10
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Exit
// Enter your choice
// 1
// Enter the element to be inserted
// 20
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Exit
// Enter your choice
// 1
// Enter the element to be inserted
// 30
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Exit
// Enter your choice
// 1
// Enter the element to be inserted
// 40
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Exit
// Enter your choice
// 1
// Enter the element to be inserted
// 50
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Exit
// Enter your choice
// 2
// Dequeued element is 10
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Exit
// Enter your choice
// 2
// Dequeued element is 20
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Exit
// Enter your choice
// 2
// Dequeued element is 30
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Exit
// Enter your choice
// 2
// Dequeued element is 40
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Exit
// Enter your choice
// 2
// Dequeued element is 50
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Exit
// Enter your choice
// 3
// Queue elements are:
// 10
// 20
// 30
// 1. Enqueue
// 2. Dequeue
// 3. Display
// 4. Exit
// Enter your choice
// 4
