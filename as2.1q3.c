#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int top;
    unsigned capacity;
    char *array;
};

struct stack* createstack(unsigned capacity){
    struct stack * s = (struct stack*)malloc(sizeof(struct stack));
    s->capacity = capacity;
    s->top = -1;
    s->array = (char*)malloc(s->capacity*sizeof(char));
    return s;
}

int isfull(struct stack * s){
    return s->top == s->capacity-1;
}

int isempty(struct stack * s){
    return s->top == -1;
}

void push(struct stack ** s, char val){
    if(isfull(*s)){
        printf("Stack Overflow!\n");
        return;
    }
    (*s)->array[++(*s)->top] = val;
}

void pop(struct stack ** s){
    if(isempty(*s)){
        printf("Stack Underflow!\n");
        return;
    }
    (*s)->array[(*s)->top--];
}

int main(){
    struct stack * s = createstack(100);
    char str[100];
    int i;
    printf("Enter the parenthesis.\n");
    scanf("%s", str);
    if(str[0] == ')')
        printf("Not Well Formed!\n");
    else{
        for(i=0;i<strlen(str);i++){
            if(str[i] == '(')
                push(&s, str[i]);
            else
                pop(&s);
        }
    }
    if(isempty(s))
        printf("Well Formed!\n");
    else
        printf("Not Well Formed!\n");
    return 0;
}
