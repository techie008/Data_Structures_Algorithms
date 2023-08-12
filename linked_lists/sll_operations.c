//write a program to insert and delete element in the beginning,middle,last, and and given index of single linked list

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *head=NULL;

struct node *create_node(int data){
	struct node *new_node=(struct node *)malloc(sizeof(struct node));
	new_node->data=data;
	new_node->next=NULL;
	return new_node;
}

void insert_beginning(int data){
	if(head==NULL)
		head=create_node(data);
	else{
		struct node *temp=create_node(data);
		temp->next=head;
		head=temp;
	}
}

void insert_middle(int data){
	struct node *new_node=create_node(data);
	struct node *temp=head;
	int size=0;
	while(temp!=NULL){
		temp=temp->next;
		size++;
	}
	temp=head;
	if(size%2==0){
		for(int i=1;i<size/2;i++){
			temp=temp->next;
		}
		new_node->next=temp->next;
		temp->next=new_node;
	}
	else{
		for(int i=1;i<size/2;i++){
			temp=temp->next;
		}
		new_node->next=temp->next;
		temp->next=new_node;
	}
}

void insert_last(int data){
	if(head==NULL)
		head=create_node(data);
	else{
		struct node *temp=head;
		while(temp->next!=NULL){
			temp=temp->next;
		}
		struct node *t=create_node(data);
		temp->next=t;
		t->next=NULL;
	}
}

void display(){
	struct node *temp=head;
	printf("Display :");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

void del_begin(){
	struct node *temp=head;
	head=temp->next;
	free(temp);
}

void del_middle(){
        struct node *temp=head;
        int size=0;
        while(temp!=NULL){
                temp=temp->next;
                size++;
        }
        temp=head;

       	for(int i=1;i<size/2;i++){
        	temp=temp->next;
        
	}
	struct node *t=temp->next;
	temp->next=temp->next->next;
        free(t);
}

void del_last(){
	struct node *temp=head;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	struct node *t=temp->next;
	temp->next=NULL;
	free(t);
	t->next=NULL;
}

void del_index(int pos){
	struct node *temp=head;

	if(pos==0)
		del_begin();
	
	else{
		for(int i=0;i<pos-1;i++){
			temp=temp->next;
		}
		struct node *t=temp->next;
		temp->next=temp->next->next;
		free(t);
	}
}


int main(){
	int ch;
	int pos;
	int ele;
	printf("1.Insert at beginning\n2.Insert at middle\n3.Insert at last\n4.Delete at beginning\n5.Delete at middle\n6.Delete at last\n7.Delete at given index\n");
	while(1){
		printf("Enter choice :");
		scanf("%d",&ch);
		if(ch==1){
			scanf("%d",&ele);
			insert_beginning(ele);
			display();
		}
		else if(ch==2){
			scanf("%d",&ele);
			insert_middle(ele);
			display();
		}
		else if(ch==3){
			scanf("%d",&ele);
			insert_last(ele);
			display();
		}
		else if(ch==4){	
			del_begin();
			display();
		}
		else if(ch==5){
			del_middle();
			display();
		}
		else if(ch==6){
			del_last();
			display();
		}
		else if(ch==7){
			printf("Enter position of element :");
			scanf("%d",&pos);
			del_index(pos);
			display();
		}
	}
	return 0;
}
