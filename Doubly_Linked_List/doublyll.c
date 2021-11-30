/* C Program to implement doubly linked list and perform operations 
    such as Insertion, deletion and search. */

#include<stdio.h>
#include<stdlib.h>
struct node {
  int data;
  struct node *next;
  struct node *prev;
};
struct node *head;
void insertBeginning();
void insertLast();
void insertSpecific();
void deleteBeginning();
void deleteLast();
void deleteSpecific();
void display();
void search();

void main() {
  int choice=0;
  while(choice!=9) {
    printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete the node after the given data\n7.Search\n8.Show\n9.Exit\n");
    printf("\nEnter your choice : \n");
    scanf("%d",&choice);
    switch(choice) {
      case 1:
           insertBeginning();
           break;
      case 2:
            insertLast();
           break;
      case 3:
           insertSpecific();
           break;
      case 4:
           deleteBeginning();
           break;
      case 5:
           deleteLast();
           break;
      case 6:
           deleteSpecific();
           break;
      case 7:
           search();
           break;
      case 8:
           display();
           break;
      case 9:
           exit(0);
           break;
      default:
           printf("Please enter valid choice..");
    }
  }
}
void insertBeginning() {
  struct node *ptr;
  int item;
  ptr=(struct node *)malloc(sizeof(struct node));
  if(ptr==NULL)
    printf("\nOverflow");
  else {
    printf("\nEnter a value: ");
    scanf("%d",&item);
    if(head==NULL) {
      ptr->next=NULL;
      ptr->prev=NULL;
      ptr->data=item;
      head=ptr;
    }
    else {
      ptr->data=item;
      ptr->prev=NULL;
      ptr->next=head;
      head->prev=ptr;
      head=ptr;
    }
    printf("\nnode inserted\n");
  }
}
void insertLast() {
  struct node *ptr,*temp;
  int item;
  ptr=(struct node *)malloc(sizeof(struct node));
  if(ptr==NULL)
    printf("\nOverflow\n");
  else {
    printf("\nEnter a value: \n");
    scanf("%d",&item);
    ptr->data=item;
    if(head==NULL) {
      ptr->next=NULL;
      ptr->prev=NULL;
      head=ptr;
    }
    else {
      temp=head;  struct node *head;
      while(temp->next!=NULL)
        temp=temp->next;
      temp->next=ptr;
      ptr->prev=temp;
      ptr->next=NULL;
    }
  }
  printf("\nnode inserted\n");
}
void insertSpecific() {
  struct node *ptr,*temp;
  int item,location,i;
  ptr=(struct node *)malloc(sizeof(struct node));
  if(ptr==NULL)
    printf("\nOverflow");
  else {
    temp=head;
    display();
    printf("\nEnter the location after you want to insert: ");
    scanf("%d",&location);
    for(int i=0;i<location;i++) {
      temp=temp->next;
      if(temp==NULL) {
        printf("\nThere are less than %d elements",location);
        return;
      }
    }
    printf("\nEnter the value: ");
    scanf("%d",&item);
    ptr->data=item;
    ptr->next=temp->next;
    ptr->prev=temp;
    temp->next=ptr;
    temp->next->prev=ptr;
    printf("\nInserted\n");
    display();
  }
}
void deleteBeginning() {
  struct node *ptr;
  if(head==NULL)
    printf("\nUnderflow");
  else if(head->next==NULL) {
    head=NULL;
    free(head);
    printf("\nnode deleted");
  }
  else {
    ptr=head;
    if(ptr->next!=NULL) {
      ptr=ptr->next;
    }
    ptr->prev->next=NULL;
    free(ptr);
    printf("\nnode deleted");
  }
}
void deleteLast() {
  struct node *ptr;
  if(head==NULL)
    printf("\nUnderflow");
  else if(head->next==NULL) {
    head=NULL;
    free(head);
    printf("\nnode deleted\n");
  }
  else {
    ptr=head;
    while(ptr->next!=NULL)
      ptr=ptr->next;
    ptr->prev->next=NULL;
    free(ptr);
    printf("\nnode deleted\n");
  }
}
void deleteSpecific() {
  struct node *ptr,*temp;
  int value;
  display();
  printf("\nEnter the data after which the node is to be deleted :");
  scanf("%d",&value);
  ptr=head;
  while(ptr->data!=value)
    ptr=ptr->next;
  if(ptr->next==NULL)
    printf("Can't delete\n");
  else if(ptr->next->next==NULL)
    ptr->next=NULL;
  else {
    temp=ptr->next;
    ptr->next=temp->next;
    temp->next->prev=ptr;
    free(temp);
    printf("\nNode deleted");
    display();
  }
}
void display() {
  struct node *ptr;
  printf("\nPrinting values..\n");
  ptr=head;
  while(ptr!=NULL) {
    printf("%d\n",ptr->data);
    ptr=ptr->next;
  }
}
void search() {
  struct node *ptr;
  int item,i=0,flag;
  ptr=head;
  if(ptr==NULL)
    printf("\nEmpty List\n");
  else {
    printf("\nEnter item which you want to search: ");
    scanf("%d",&item);
    while(ptr!=NULL) {
      if(ptr->data==item) {
        printf("\nItem found at location %d ",i+1);
        flag=0;
        break;
      } else {
        flag=1;
      }
      i++;
      ptr=ptr->next;
    }
    if(flag==1)
      printf("\nItem not found\n");
  }
}