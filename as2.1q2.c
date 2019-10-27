#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

void insertatend(struct node** head_ref, int new_data){
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL){
       *head_ref = new_node;
       return;
    }
    struct node *temp = *head_ref;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
    return;
}

void show(struct node * node){
    struct node * temp = node;
    if(temp == NULL){
        printf("Empty List!\n");
        return;
    }
    while(temp != NULL){
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return;
}

void split(struct node ** head_ref){
    struct node *temp = *head_ref;
    struct node *ehead = NULL;
    struct node *ohead = NULL;
    if(temp == NULL){
        printf("Empty List!");
        return;
    }
    while(temp != NULL){
        if(temp->data%2 == 0)
            insertatend(&ehead, temp->data);
        else
            insertatend(&ohead, temp->data);
        temp = temp->next;
    }
    printf("List is split!\n");
    printf("Even List: ");
    show(ehead);
    printf("Odd List: ");
    show(ohead);
    return;
}

int main(){
    struct node *head = NULL;
    int n,i,val;
    char choice;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for(i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d",&val);
        insertatend(&head, val);
    }
    printf("\n");
    printf("The linked list you have entered is: ");
    show(head);
    printf("\n");
    split(&head);
    return 0;
}
