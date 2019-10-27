#include<stdio.h>
#include<stdlib.h>

void merge(int *a, int *l, int *r,int n){
    int i,j,k;
    int n1 = n/2;
    int n2 = n-n1;
    i=0; j=0; k=0;
    while(i<n1 && j<n2){
        if(l[i]<r[j]) a[k++] = l[i++];
        else a[k++] = r[j++];
    }
    while(i<n1) a[k++] = l[i++];
    while(j<n2) a[k++] = r[j++];
}

void mergesort(int *ar,int n){
    int i,*l,*r;
    if(n<2) return;
    int mid = n/2;
    l = (int*)malloc(mid*sizeof(int));
    r = (int*)malloc((n-mid)*sizeof(int));
    for(i=0;i<mid;i++) l[i] = ar[i];
    for(i=mid;i<n;i++) r[i-mid] = ar[i];
    mergesort(l, mid);
    mergesort(r, n-mid);
    merge(ar, l, r, n);
    free(l);
    free(r);
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
    printf("The array you've entered is: ");
    printarray(ar,n);
    printf("After sorting: ");
    mergesort(ar,n);
    printarray(ar,n);
    return 0;
}
