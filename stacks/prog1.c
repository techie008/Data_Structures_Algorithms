//implement stack using linked list

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *top=NULL;

struct node *create_stack(int data){
	struct node *stack_node=(struct node *)malloc(sizeof(struct node));
	stack_node->data=data;
	stack_node->next=NULL;
	return stack_node;
}
	
void push(int data){
	if(top==NULL)
		top=create_stack(data);
	else{
		struct node *temp=create_stack(data);
		temp->next=top;
		top=temp;
	}
}

void display(){
	while(top!=NULL){
		printf("%d ",top->data);
		top=top->next;
	}
}

int main(){
	int val;
	for(int i=0;i<5;i++){
		scanf("%d",&val);
		push(val);
	}
	display();
}


