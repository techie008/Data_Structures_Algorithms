//Write a code to find the Minimum value in an integer Stack in O(1) time complexity.

#include <stdio.h>
#include <stdlib.h>

struct stack{
    int data;
    struct stack *next;
};
int min;
struct stack *top=NULL;

int push(int data){
    struct stack *new_node=(struct stack *)malloc(sizeof(struct stack));
    new_node->data=data;
    new_node->next=NULL;
    
    if(top==NULL){
        top=new_node;
        min=new_node->data;
    }
    else{
        new_node->next=top;
        top=new_node;
        if(min>new_node->data)
            min=new_node->data;
    }
}

int display(){
    struct stack *temp=top;
    while(temp->next!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}


int main(){
    int value;
    int small=0;
    while(1){
        scanf("%d",&value);
        if(value>0){
            push(value);
        }
        else
            break;
    }
    printf("Stack elements are:\n");
    display();
    printf("\nMin value in the stack is:\n");
    printf("%d",min);
}
