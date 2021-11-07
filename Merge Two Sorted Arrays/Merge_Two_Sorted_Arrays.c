/* C Program to sort and merge two arrays */

#include <stdio.h>
void main() {
    int i, j, k,m,n,temp;
    printf("Enter the number of elements in the first array\n");
    scanf("%d",&m);
    int a[m];
    printf("Enter the elements of the first array\n");
    for(i=0;i<m;i++) {
        scanf("%d",&a[i]);
    }
    printf("\nOriginal First Array is\n");
    for(i=0;i<m;i++) { 
        printf("%d\t",a[i]);
    }

/* Sort the first array */
    for(i=0;i<m;i++) {
        for(j=i+1;j<m;j++) {
            if(a[i]>a[j]) {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    printf("\nSorted First Array is\n");
    for(i=0;i<m;i++) {
        printf("%d\t",a[i]);
    }

    printf("\nEnter the number of elements in the second array\n");
    scanf("%d",&n);
    int b[n],c[m+n];
    printf("\nEnter the elements of the second array\n");
    for(i=0;i<n;i++) { 
        scanf("%d",&b[i]);
    }
    printf("\nOriginal Second Array is\n");  
    for(i=0;i<n;i++) { 
        printf("%d\t",b[i]);
    }

/* Sort the second array */
    for(i=0;i<n;i++) {
        for(j=i+1;j<n;j++) {
            if(b[i]>b[j]) {
                temp=b[i];
                b[i]=b[j];
                b[j]=temp;
            }
        }
    }
    printf("\nSorted second array is\n");
    for(i=0;i<n;i++) {
        printf("%d\t",b[i]);
    } 

/* Merge and sort two arrays into third One */
    i=j=k=0;
    for(i=0;i<m&&j<n;) {
        if(a[i]<b[j]) {
            c[k]=a[i];
            k++;
            i++;
        }
        else {
            c[k]=b[j];
            k++;
            j++;
        }
    }
    while(i<m) {
        c[k]=a[i];
        k++;
        i++;
    }
    while(j<n) {
        c[k]=b[j];
        k++;
        j++;
    }
    printf("\nMerged and sorted array is\n");
    for(i=0;i<k;i++) {
        printf("%d\t",c[i]);
    }
}