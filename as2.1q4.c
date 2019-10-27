#include<stdio.h>

int main(){
    int i,j,temp,n;
    int ar[100];
    printf("Enter the number of terms in the array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter element %d: ", i+1);
        scanf("%d", &ar[i]);
    }
    printf("The array you've entered is: ");
    for(i=0;i<n;i++) printf("%d ", ar[i]);
    printf("\n\nSorting...\n\nNew array: ");
    for(i=0;i<n;i+=2)
        for(j=i+2;j<n;j+=2)
            if(ar[i]<ar[j]){
                temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
    for(i=1;i<n;i+=2)
        for(j=i+2;j<n;j+=2){
            if(ar[i]>ar[j]){
                temp = ar[i];
                ar[i] = ar[j];
                ar[j] = temp;
            }
        }
    printf("\n");
    for(i=0;i<n;i++)
        printf("%d ",ar[i]);
    return 0;
}
