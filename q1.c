#include<stdio.h>

int lsearch(int [], int, int);

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
    res = lsearch(ar,n,x);
    if(res == -1)
        printf("Number not found!\n");
    else
        printf("%d is located at position %d", x, res);
    return 0;
}

int lsearch(int ar[],int n, int x){
    int i,pos = -1;
    for(i=0;i<n;i++)
        if(ar[i]==x)
            pos = i+1;
    return pos;
}
