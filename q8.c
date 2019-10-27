#include<stdio.h>

void pswap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void printarray(int ar[], int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d ",ar[i]);
    printf("\n");
}

void selectionSort(int *ar, int n){
    int imin, i, j;
    for(i=0;i<n-1;i++){
        imin = i ;
        for(j=i+1;j<n;j++){
            if(ar[j]<ar[imin]) imin = j;
        }
        pswap(&ar[i],&ar[imin]);
    }
}

int main(){
    int i,n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int ar[n];
    for(i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&ar[i]);
    }
    printf("The array you've entered is: ");
    printarray(ar,n);
    printf("After sorting: ");
    selectionSort(ar,n);
    printarray(ar,n);
    return 0;
}
