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
        printf("\n1. Push\n2. Pop\n3. Search\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
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
void push(int item)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->next = top;
    top = temp;
}
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


