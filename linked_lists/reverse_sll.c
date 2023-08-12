//write a program to reverse a linked list
//Time-Complexity : O(n)
//Difficulty : Medium

#include <stdio.h>
#include <stdlib.h>

struct node{
        int data;
        struct node *next;
};

struct node *head=NULL;

void insert_node(int data){
        struct node *new_node=(struct node *)malloc(sizeof(struct node));
        new_node->data=data;
        new_node->next=NULL;

        if(head==NULL){
                new_node->next=NULL;
                head=new_node;
        }

        else{
                struct node *temp=head;
                while(temp->next!=NULL){
                        temp=temp->next;
                }
                temp->next=new_node;//inserting at last
        }
}

void reverse_ll(){
	struct node *current=head;
	struct node *prev=NULL;
	struct node *next=NULL;
	
	while(current!=NULL){
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
}

void display(){
	struct node *temp=head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}

int main(){
        int n;
        scanf("%d",&n);
        int item;
        while(n--){
                scanf("%d",&item);
                insert_node(item);
        }
        reverse_ll();
	display();
        return 0;
}
