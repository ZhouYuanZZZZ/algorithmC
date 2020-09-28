# define MAX_SIZE 50
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef struct {
    int data[MAX_SIZE];
    int top;
} SeqStack;

SeqStack* createStack(){
    SeqStack * stack = (SeqStack*)malloc(sizeof(SeqStack));

    stack->top = -1;

    return stack;
}

bool isEmpty(SeqStack* stack){

    return stack->top == -1;
}

void push(SeqStack* stack,int elem){

    if(stack->top == MAX_SIZE - 1){
        printf("stack overflow");
        return;
    }

    stack->data[++stack->top] = elem;
}

int pop(SeqStack* stack){

    if(isEmpty(stack)){
        printf("stack empty");
    }

    return stack->data[stack->top--];
}

int getTop(SeqStack* stack){
    if(isEmpty(stack)){
        printf("stack empty");
    }

    return stack->data[stack->top];
}

int main667(){

    SeqStack * stack = createStack();

    srand((unsigned)time(NULL));
    for (int i=0;i<20;i++){
        int elem = rand()%100;
        push(stack,elem);

        printf("%d,",elem);
    }

    printf("\n");

    while(stack->top != -1){
        printf("%d,",pop(stack));
    }
    
    return 0;
}

