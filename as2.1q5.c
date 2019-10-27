#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>

struct node{
    int coef;
    int expo;
    struct node * next;
};

void create(struct node *node){
    char ch;
    do{
        printf("Enter coeff: ");
        scanf("%d",&node->coef);
        printf("Enter power: ");
        scanf("%d",&node->expo);
        node->next=(struct node*)malloc(sizeof(struct node));
        node=node->next;
        node->next=NULL;
        printf("\nContinue(y/n):");
        ch=getch();
        printf("\n");
        }
     while(ch=='y' || ch=='Y');
}

void show(struct node *node){
    while(node->next!=NULL){
        printf("%dx^%d",node->coef,node->expo);
        node=node->next;
        if(node->next!=NULL)
        printf("+");
    }
}

int power(int x, int y){
    int i;
    if(y==0)
        return 1;
    for(i=0;i<y-1;i++)
        x *= x;
    return x;
}

int main(){
    int x, result = 0;
    struct node * p = (struct node*)malloc(sizeof(struct node));
    printf("Enter the polynomial:\n");
    create(p);
    printf("The polynomial you've entered is: ");
    show(p);
    printf("\n");
    printf("Enter the value of x: ");
    scanf("%d",&x);
    printf("\nEvaluating the polynomial...\n");
    struct node * temp = p;
    while(temp->next != NULL){
        result += ((temp->coef)*power(x,temp->expo));
        temp = temp->next;
    }
    printf("The result after evaluation is = %d\n", result);
    return 0;
}
