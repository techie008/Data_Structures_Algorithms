//Given an expression string exp, write a program to examine whether the pairs and the orders of "{", "}", "(", ")", "[", "]" are correct in exp.
//Check for bracket well-orderness
/*Approach : Push opening brackets,when closing brackets are encountered check if the recent one pushed matches the closing bracket, 
if yes pop and continue until top=-1
 if no return false immediately
  */
//Difficulty : Medium

#include <stdio.h>
#include <stdlib.h>

struct stack{
    int top;
    int size;
    char *brack;
};

struct stack *create_stack(int size){
    struct stack *stack=(struct stack *)malloc(sizeof(struct stack));
    stack->top=-1;
    stack->size=size;
    stack->brack=(char *)malloc(size*sizeof(char));
    return stack;
};

void push(struct stack *stack,char value){
    stack->brack[++stack->top]=value;
}

int pop(struct stack *stack){
    return stack->brack[stack->top--];
}

void display(struct stack *stack){
    int temp=stack->top;
    while(stack->top>=0){
        printf("%c",stack->brack[stack->top]);
        stack->top--;
    }
    stack->top=temp;
}

int main(){
    char input[1000];
    scanf("%s",input);
    int size=sizeof(input)/sizeof(input[0]);
    struct stack *stack=create_stack(size);
    
    for(int i=0;input[i]!='\0';i++){
        if(input[i]=='(' || input[i]=='[' || input[i]=='{'){
            push(stack,input[i]);
        }
        else if((input[i]==')' && stack->brack[stack->top]=='(') || (input[i]==']' && stack->brack[stack->top]=='[') || (input[i]=='}' && stack->brack[stack->top]=='{')){
            pop(stack);
        }
        else if((input[i]==')' && stack->brack[stack->top]!='(') || (input[i]==']' && stack->brack[stack->top]!='[') || (input[i]=='}' && stack->brack[stack->top]!='{')){
            top=0;
            break;
        }
    }
    if(stack->top==-1)
        printf("True");
    else
        printf("False");
}
