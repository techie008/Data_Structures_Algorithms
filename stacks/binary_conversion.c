//Write a program to convert decimal to binary system
//Difficulty : Medium

#include <stdio.h>
#include <stdlib.h>

struct stack{
    int top;
    int size;
    int *array;
};

struct stack* create_stack(int size){
    struct stack *stack=(struct stack *)malloc(sizeof(struct stack));
    stack->top=-1;
    stack->size=size;
    stack->array=(int *)malloc(size*sizeof(int));
}

void push(struct stack *stack,int data){
    stack->array[++stack->top]=data;
}

void display(struct stack *stack){
    int temp=stack->top;
    while(stack->top>=0){
        printf("%d",stack->array[stack->top]);
        stack->top--;
    }
    stack->top=temp;
}

int main(){
    int n,bin;
    scanf("%d",&n);
    struct stack *stack=create_stack(10);
    while(n>0){
        bin=n%2;
        n=n/2;
        push(stack,bin);
    }
    display(stack);
}


