//Write a code to sort an integer Stack using only stack operations.
//use any logn sorting operations for efficient approach
//Here, bubble sort is implemented
//TIME-COMPLEXITY : O(n^2)

#include <stdio.h>
#include <stdlib.h>

struct stack{
    int data;
    struct stack *next;
};

struct stack *top=NULL;

void push(int data){
    struct stack *new_node=(struct stack *)malloc(sizeof(struct stack));
    new_node->data=data;
    new_node->next=NULL;
    
    if(top==NULL)
        top=new_node;
    else{
        new_node->next=top;
        top=new_node;
    }
}

void display(){
    struct stack *temp=top;
    while(temp->next!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}

void sort(){
    struct stack *ptr1=top;
    struct stack *ptr2;
    
    while(ptr1->next!=NULL){
        ptr2=ptr1->next;
        
        while(ptr2!=NULL){
            if(ptr2->data>ptr1->data){
                int temp=ptr2->data;
                ptr2->data=ptr1->data;
                ptr1->data=temp;
            }
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
    }
}

int main(){
    int value;
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
    sort();
    printf("\nAfter sorted:\n");
    display();
}
