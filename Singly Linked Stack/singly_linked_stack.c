/* C Program to implement Singly Linked Stack and perform following
    operations: Push, Pop and Linear Search. */

#include<stdio.h>
#include<stdlib.h>
void push(int);
int pop();
int search(int);
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
int main()
{
    int choice, item, pos;
    while(1)
    {
        /* Takes choice from user */
        printf("\n1. Push\n2. Pop\n3. Search\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        /* Perform operation according to choice */
        switch(choice)
        {
            case 1: printf("Enter the element to be pushed: ");
                    scanf("%d", &item);
                    push(item);
                    break;
            case 2: item = pop();
                    if(item == -1)
                        printf("Stack is empty\n");
                    else
                        printf("Popped element is %d\n", item);
                    break;
            case 3: printf("Enter the element to be searched: ");
                    scanf("%d", &item);
                    pos = search(item);
                    if(pos == -1)
                        printf("Element not found\n");
                    else
                        printf("Element found at position %d\n", pos);
                    break;
            case 4: exit(0);
            default: printf("Wrong choice\n");
        }
    }
    return 0;
}
/* Function to push an element to stack */
void push(int item)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->next = top;
    top = temp;
}
/* Function to pop an element from stack */
int pop()
{
    struct node *temp;
    int item;
    if(top == NULL)
        return -1;
    temp = top;
    item = temp->data;
    top = top->next;
    free(temp);
    return item;
}
/* Function to search an element in stack */
int search(int item)
{
    int count = 1;
    struct node *temp;
    temp = top;
    while(temp != NULL)
    {
        if(temp->data == item)
            return count;
        temp = temp->next;
        count++;
    }
    return -1;
}

/*
Algorithm:Push
1. Create a node temp.
2. Assign the value of item to temp->data.
3. Assign the address of top to temp->next.
4. Assign the address of temp to top.
5. Return.

Algorithm:Pop
1. If top is NULL, return -1.
2. Create a node temp.
3. Assign the value of top->data to temp->data.
4. Assign the address of top->next to temp->next.
5. Assign the address of temp to top.
6. Return temp->data.

Algorithm:Search
1. Create a node temp.
2. Assign the address of top to temp.
3. While temp is not NULL
    1. If temp->data is equal to item, return count.
    2. Else, increment count.
    3. Assign the address of temp->next to temp.
4. Return -1.
*/

/*
Output:
1. Push
2. Pop
3. Search
4. Exit
Enter your choice: 1
Enter the element to be pushed: 1
1. Push
2. Pop
3. Search
4. Exit
Enter your choice: 1
Enter the element to be pushed: 2
1. Push
2. Pop
3. Search
4. Exit
Enter your choice: 1
Enter the element to be pushed: 3
1. Push
2. Pop
3. Search
4. Exit
Enter your choice: 1
Enter the element to be pushed: 4
1. Push
2. Pop
3. Search
4. Exit
Enter your choice: 1
Enter the element to be pushed: 5
1. Push
2. Pop
3. Search
4. Exit
Enter your choice: 2
Popped element is 5
1. Push
2. Pop
3. Search
4. Exit
Enter your choice: 2
Popped element is 4
1. Push
2. Pop
3. Search
4. Exit
Enter your choice: 3
Enter the element to be searched: 5
Element found at position 4
1. Push
2. Pop
3. Search
4. Exit
Enter your choice: 3
Enter the element to be searched: 6
Element not found
1. Push
2. Pop
3. Search
4. Exit
Enter your choice: 4
*/

