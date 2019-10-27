#include<stdio.h>

void pswap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(int ar[], int n){
    int i,j;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if(ar[j]>ar[j+1])
                pswap(&ar[j],&ar[j+1]);
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
    bubblesort(ar,n);
    printarray(ar,n);
    return 0;
}
