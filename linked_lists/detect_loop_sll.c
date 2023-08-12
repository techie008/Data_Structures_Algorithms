//detect loop in a linked list
//the question demands us to detect loop if found
//Difficulty : Medium


#include <stdio.h>
#include <stdlib.h>

struct node{
        int data;
        struct node *next;
	int flag=0; //if flag=1 means node has been visited once, revisiting would mean loop
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
bool detect_cycle(){
	struct node *temp=head;
	while(temp!=NULL){
		if(temp->flag==0){
			temp->flag=1;
		}
		else
			return true;
		temp=temp->next;
	}
	return false;
}

int main(){
        int n;
        scanf("%d",&n);
        int item;
        while(n--){
                scanf("%d",&item);
                insert_node(item);
        }
	//create a loop
	
	struct node *temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=head;
	
        if(detect_cycle())
		printf("Cycle detected!");
	else
		printf("no loops detected!");
        return 0;
}
