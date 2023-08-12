//Write a code to find the Maximum value in an integer Stack in O(1) time complexity.

#include <stdio.h>
#include <stdlib.h>

struct stack{
    int data;
    struct stack *next;
};

struct stack *top=NULL;

struct stack* create_node(int data){
    struct stack *new_node=(struct stack *)malloc(sizeof(struct stack));
    new_node->next=NULL;
    new_node->data=data;
    return new_node;
}

void push(int data){
    struct stack *stack_node=create_node(data);
    if(top==NULL)
        top=stack_node;
    else{
        stack_node->next=top;
        top=stack_node;
    }
}


void display(){
    struct stack *temp=top;
    while(temp->next!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d ",temp->data);
}

int main(){
    int value;
    int temp=0;
    while(1){
        scanf("%d",&value);
        if(value>0){
            push(value);
            if(top->data>temp)
                temp=value;
        }
        else{
            break;
        }
    }
    printf("Stack elements are:\n");
    display();
    printf("\nMax value in the stack is:\n");
    printf("%d",temp);
}


