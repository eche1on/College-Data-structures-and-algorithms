#include<stdio.h>

void insertionSort(int ar[], int n){
    int i, key, j;
    for(i=1;i<n;i++){
        key = ar[i];
        j = i;
        while(j>0 && ar[j-1]>key){
            ar[j] = ar[j-1];
            j--;
        }
        ar[j] = key;
    }
}

void printarray(int ar[], int n){
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
    printf("The array you've entered is: ");
    printarray(ar,n);
    printf("After sorting: ");
    insertionSort(ar,n);
    printarray(ar,n);
    return 0;
}
