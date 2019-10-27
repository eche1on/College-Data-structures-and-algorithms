#include<stdio.h>

int binarysearch(int *ar, int start, int end, int x){
    int mid = start + (end-start)/2;
    while(start<=end){
        if(x == ar[mid])
            return mid;
        if(x>ar[mid])
            return binarysearch(ar, mid+1, end, x);
        else
            return binarysearch(ar, start, mid-1, x);
    }
    return -1;
}

int main(){
    int n,i,x;
    printf("Enter the number of terms: ");
    scanf("%d",&n);
    int ar[n];
    for(i=0;i<n;i++){
        printf("Enter element %d: ",i+1);
        scanf("%d",&ar[i]);
    }
    printf("Enter the number you want to search: ");
    scanf("%d",&x);
    printf("\nSearching...\n\n");
    int res;
    res = binarysearch(ar,0,n,x);
    if(res == -1)
        printf("Number not found!\n");
    else
        printf("%d is located at position %d", x, res+1);
    return 0;
}
