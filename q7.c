#include<stdio.h>

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int *a, int start, int end){
    int pivot = a[end];
    int pi = start;
    int i;
    for(i=start;i<end;i++)
        if(a[i]<=pivot){
            swap(&a[i],&a[pi]);
            pi++;
        }
    swap(&a[end],&a[pi]);
    return pi;
}

void quicksort(int *a, int start, int end){
    if(start<end){
        int pi = partition(a, start, end);
        quicksort(a, start, pi-1);
        quicksort(a, pi+1, end);
    }
}

void printarray(int *ar, int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d ",ar[i]);
    printf("\n");
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
    printf("\n");
    printf("The array you've entered is: ");
    printarray(ar,n);
    printf("After sorting: ");
    quicksort(ar,0,n-1);
    printarray(ar,n);
    return 0;
}
