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
void insert_at_end(int data) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = &head;
    temp->prev = head.prev;
    head.prev->next = temp;
    head.prev = temp;
}
void insert_at_begin(int data) {
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head.next;
    temp->prev = &head;
    head.next->prev = temp;
    head.next = temp;
}
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
void delete_at_end() {
    struct node *temp;
    temp = head.prev;
    head.prev = temp->prev;
    temp->prev->next = &head;
    free(temp);
}
void delete_at_begin() {
    struct node *temp;
    temp = head.next;
    head.next = temp->next;
    temp->next->prev = &head;
    free(temp);
}
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
