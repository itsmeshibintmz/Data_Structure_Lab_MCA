/* C Program to implement doubly linked list and perform operations 
    such as Insertion, deletion and search. */

#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
    struct node *prev;
};
struct node head;
void insert_at_end(int);
void insert_at_begin(int);
void insert_at_pos(int, int);
void delete_at_end();
void delete_at_begin();
void delete_at_pos(int);
void display();
void search(int);
int main() {
    int choice, data, pos;
    head.next = &head;
    head.prev = &head;
    while (1) {
        printf("\n1. Insert at end\n2. Insert at begin\n3. Insert at pos\n4. Delete at end\n5. Delete at begin\n6. Delete at pos\n7. Display\n8. Search\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                insert_at_end(data);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                insert_at_begin(data);
                break;
            case 3:
                printf("Enter the data: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &pos);
                insert_at_pos(data, pos);
                break;
            case 4:
                delete_at_end();
                break;
            case 5:
                delete_at_begin();
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &pos);
                delete_at_pos(pos);
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Enter the data: ");
                scanf("%d", &data);
                search(data);
                break;
            case 9:
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
/* Inserts a node at the end of the list */
void insert_at_end(int data) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = &head;
    temp->prev = head.prev;
    head.prev->next = temp;
    head.prev = temp;
}
/* Inserts a node at the beginning of the list */
void insert_at_begin(int data) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head.next;
    temp->prev = &head;
    head.next->prev = temp;
    head.next = temp;
}
/* Inserts a node at the given position */
void insert_at_pos(int data, int pos) {
    struct node *temp, *ptr;
    int i;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    ptr = head.next;
    for (i = 1; i < pos; i++) {
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    temp->prev = ptr;
    ptr->next->prev = temp;
    ptr->next = temp;
}
/* Deletes a node from the end of the list */
void delete_at_end() {
    struct node *temp;
    temp = head.prev;
    head.prev = temp->prev;
    temp->prev->next = &head;
    free(temp);
}
/* Deletes a node from the beginning of the list */
void delete_at_begin() {
    struct node *temp;
    temp = head.next;
    head.next = temp->next;
    temp->next->prev = &head;
    free(temp);
}
/* Deletes a node from the given position */
void delete_at_pos(int pos) {
    struct node *temp, *ptr;
    int i;
    ptr = head.next;
    for (i = 1; i < pos; i++) {
        ptr = ptr->next;
    }
    temp = ptr->next;
    ptr->next = temp->next;
    temp->next->prev = ptr;
    free(temp);
}
/* Displays the list */
void display() {
    struct node *ptr;
    ptr = head.next;
    printf("\n");
    while (ptr != &head) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
/* Searches for a node with the given data */
void search(int data) {
    struct node *ptr;
    ptr = head.next;
    while (ptr != &head) {
        if (ptr->data == data) {
            printf("\nData found at position %d\n", ptr->data);
            return;
        }
        ptr = ptr->next;
    }
    printf("\nData not found\n");
}
/*
Algorithm:
1. Insert at end:
    1.1. Allocate memory for new node
    1.2. Assign data to new node
    1.3. Make new node point to head
    1.4. Make head point to new node
    1.5. Make new node point to previous node
    1.6. Make previous node point to new node
2. Insert at begin:
    2.1. Allocate memory for new node
    2.2. Assign data to new node
    2.3. Make new node point to head
    2.4. Make head point to new node
    2.5. Make new node point to next node
    2.6. Make next node point to new node
3. Insert at pos:
    3.1. Allocate memory for new node
    3.2. Assign data to new node
    3.3. Make new node point to head
    3.4. Make head point to new node
    3.5. Make new node point to next node
    3.6. Make next node point to new node
    3.7. Make new node point to previous node
    3.8. Make previous node point to new node
4. Delete at end:
    4.1. Make previous node point to head
    4.2. Make head point to previous node
    4.3. Free memory of last node
5. Delete at begin:
    5.1. Make next node point to head
    5.2. Make head point to next node
    5.3. Free memory of first node
6. Delete at pos:
    6.1. Make previous node point to next node
    6.2. Make next node point to previous node
    6.3. Free memory of node at pos
7. Display:
    7.1. Make ptr point to head
    7.2. While ptr is not pointing to head
        7.2.1. Print data of ptr
        7.2.2. Make ptr point to next node

Output:
1. Insert at end
2. Insert at begin
3. Insert at pos
4. Delete at end
5. Delete at begin
6. Delete at pos
7. Display
8. Search
9. Exit
Enter your choice: 1
Enter the data: 10
1. Insert at end
2. Insert at begin
3. Insert at pos
4. Delete at end
5. Delete at begin
6. Delete at pos
7. Display
8. Search
9. Exit
Enter your choice: 2
Enter the data: 20
1. Insert at end
2. Insert at begin
3. Insert at pos
4. Delete at end
5. Delete at begin
6. Delete at pos
7. Display
8. Search
9. Exit
Enter your choice: 3
Enter the data: 30
Enter the position: 2
1. Insert at end
2. Insert at begin
3. Insert at pos
4. Delete at end    
5. Delete at begin
6. Delete at pos
7. Display
8. Search
9. Exit
Enter your choice: 4
1. Insert at end
2. Insert at begin
3. Insert at pos
4. Delete at end
5. Delete at begin
6. Delete at pos
7. Display
8. Search
9. Exit
Enter your choice: 5
1. Insert at end
2. Insert at begin
3. Insert at pos
4. Delete at end
5. Delete at begin
6. Delete at pos
7. Display
8. Search
9. Exit
Enter your choice: 6
Enter the position: 1
*/
 