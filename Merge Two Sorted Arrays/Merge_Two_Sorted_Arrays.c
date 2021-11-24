/* C Program to merge two sorted arrays and store in
    a third array. */

#include <stdio.h>
void main() {
    int i, j, k,m,n,temp;
    /* Input the size of the first array */
    printf("Enter the number of elements in the first array\n");
    scanf("%d",&m);
    int a[m];
    /* Input the elements of the first array */
    printf("Enter the elements of the first array\n");
    for(i=0;i<m;i++) {
        scanf("%d",&a[i]);
    }
    /* Display the elements of the first array */
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
    /* Display the elements of the sorted first array */
    printf("\nSorted First Array is\n");
    for(i=0;i<m;i++) {
        printf("%d\t",a[i]);
    }
    /* Input the size of the second array */
    printf("\nEnter the number of elements in the second array\n");
    scanf("%d",&n);
    int b[n],c[m+n];
    /* Input the elements of the second array */
    printf("\nEnter the elements of the second array\n");
    for(i=0;i<n;i++) { 
        scanf("%d",&b[i]);
    }
    /* Display the elements of the second array */
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
    /* Display the elements of the sorted second array */
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
    /* Display the elements of the merged and sorted array */
    printf("\nMerged and sorted array is\n");
    for(i=0;i<k;i++) {
        printf("%d\t",c[i]);
    }
}

// Output:
// Enter the number of elements in the first array
// 5
// Enter the elements of the first array
// 1
// 2
// 3
// 4
// 5
// Enter the number of elements in the second array
// 4
// Enter the elements of the second array
// 6
// 7
// 8
// 9
// 10
// Original First Array is
// 1	2	3	4	5
// Sorted First Array is
// 1	2	3	4	5
// Original Second Array is
// 6	7	8	9	10
// Sorted second array is
// 6	7	8	9	10
// Merged and sorted array is
// 1	2	3	4	5	6	7	8	9	10

// Time Complexity: O(m+n)
// Space Complexity: O(m+n)
// Approach: Merge two sorted arrays into one sorted array.

// Algorithm:
// 1. Merge two sorted arrays into one sorted array.
// 2. Sort the merged array.
// 3. Display the sorted array.
// 4. Exit.
// C Program to sort and merge two arrays */
