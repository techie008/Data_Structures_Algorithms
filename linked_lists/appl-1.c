//Application based question
/*
Lalit and his friends are playing cards sitting around a circular table. After the first game, first-person and last person exchange their position. 
Pranav is watching this game and he relates this with Circular Linked List.
So he decided to write a program to exchange first and last nodes in Circular Linked List. Help Pranav to complete this program.
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head;

void insert(int value){
    struct node *new_node;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=value;
    new_node->prev=NULL;
    new_node->next=NULL;
    
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
        new_node->next=head;
        new_node->prev=ptr;
        ptr->next=new_node;
        head->prev=new_node;
    }
}

void swap(){
    int temp;
    struct node *ptr;
    ptr=head;
    while(ptr->next!=head){
        ptr=ptr->next;
    }
    temp=head->data;
    head->data=ptr->data;
    ptr->data=temp;
}


void display(){
    struct node *ptr;
    ptr=head;
    while(ptr->next!=head){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("%d",ptr->data);
}


int main(){
    int n,item;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&item);
        insert(item);
    }
    printf("Before Swap : ");
    display();
    printf("\n");
    printf("After Swap : ");
    swap();
    display();
}


