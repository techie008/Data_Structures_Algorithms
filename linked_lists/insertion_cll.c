//Write a program to insert the elements at the beginning and display it on a circular doubly linked list.
/*
1. Insert in Beginning
2. Show
3. Exit 

The first input choice is 1, in which the value can be inserted.
The second input choice is 2, which displays the elements.
The third input choice is 3, which is the exit
If the user doesn't enter any of the three choices then display "Please enter valid choice.. "
  */
//Difficulty : Medium

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head;

void insert_begin(int value){
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=value;
    new_node->next=NULL;
    new_node->prev=NULL;
    
    if(head==NULL){
        head=new_node;
        head->next=new_node;
        head->prev=new_node;
    }
    else{
        struct node *ptr;
        ptr=head;
        while(ptr->next!=head){
            ptr=ptr->next;
        }
        new_node->prev=ptr;
        ptr->next=new_node;
        new_node->next=head;
        head->prev=new_node;
        head=new_node;
    }
}

void show(){
    struct node *temp;
    temp=head;
    while(temp->next!=head){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}

int main(){
    int ch,item;
    while(1){
        scanf("%d",&ch);
        if(ch==1){
            scanf("%d",&item);
            insert_begin(item);
        }
        if(ch==2){
            show();
        }
        if(ch==3){
            exit(0);
        }
    }
}
