/* C Program to perform array operations such as Traversal, Insertion, Deletion, Search and Update */

#include<stdio.h>
void main() {
    int a[100], i,j,n,pos,element;
    printf("Enter the size of the array");
    scanf("%d",&n);
    printf("Enter the elements of the array");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

/* Traversal */
    printf("The elements of the array are");
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);

/* Insertion */
    printf("\nEnter the position and element to be inserted");  
    scanf("%d%d",&pos,&element);
    if(pos>n)
    printf("Insertion not possible");
    else { 
    for(i=n;i>=pos;i--)
        a[i+1]=a[i];
    a[pos]=element;
    printf("\nThe elements of the array after insertion are");
    for(i=0;i<=n;i++)
        printf("%d\n",a[i]);
    }

/* Deletion */
    printf("\nEnter the position to be deleted");
    scanf("%d",&pos);
    if(pos>n)
    printf("Deletion not possible");
    else {
        a[pos]=a[pos+1];
    for(i=pos+1;i<=n;i++)
        a[i]=a[i+1];
    printf("\nThe elements of the array after deletion are");
    for(i=0;i<n;i++)
        printf("%d\n",a[i]);
    }

/*Search */
    printf("\nEnter the element to be searched");
    scanf("%d",&element);
    for(i=0;i<n;i++) {
        if(a[i]==element)
            printf("\nElement found at position %d",i);
        else
            printf("\nElement not found");
    }
/* Update */
    printf("\nEnter the position and element to be updated");
    scanf("%d%d",&pos,&element);
    if(pos>n)
    printf("Update not possible");
    else {
        a[pos]=element;
        printf("\nThe elements of the array after update are");
        for(i=0;i<n;i++)
            printf("%d\n",a[i]);
    }
}