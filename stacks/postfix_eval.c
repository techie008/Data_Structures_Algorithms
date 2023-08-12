//Write a program to evaluate postfix expression.
//Difficulty : Easy

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct stack{
    int top;
    int *array;
};

struct stack* create_stack(int size){
    struct stack *stack=(struct stack *)malloc(sizeof(struct stack));
    stack->top=-1;
    stack->array=(int *)malloc(size*sizeof(int));
    return stack;
}

void push(struct stack *stack,int data){
    stack->array[++stack->top]=data;
}

int pop(struct stack *stack){
    return stack->array[stack->top--];
}

int evaluate(char *exp){
    struct stack *stack=create_stack(20);
    int num1,num2,i=0;
    char ch;
    while((ch=exp[i++])!='\0'){ 
        if(isdigit(ch)){ //check if digit, if yes push
            push(stack,ch- '0'); //to convert character to digit
        }
        else{
            num2=pop(stack);
            num1=pop(stack);
            switch(ch){
                case '+':
                    push(stack,num1+num2);
                    break;
                case '-':
                    push(stack,num1-num2);
                    break;
                case '*':
                    push(stack,num1*num2);
                    break;
                case '/':
                    push(stack,num1/num2);
                    break;
            }
        }
    }
    return pop(stack);
}


int main(){
    char postfix[20];
    scanf("%s",postfix);
    printf("%d",evaluate(postfix));
}
