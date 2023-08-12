//reverse a stack using recursion
//this can be done by manipulating the call stack used in function calls

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};
struct node *top=NULL;
void insert(int data);
bool isEmpty();

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

int pop(){
	struct node *temp=top;
	top=temp->next;
	int res=temp->data;
	free(temp);
	return res;
}

void insert(int data){
	if(isEmpty())
		push(data);
	else{
		int temp=pop();
		insert(data);
		push(temp);
	}
}

void reverse(){
	if(!isEmpty()){
		int temp=pop();
		reverse();
		insert(temp);
	}
}
	
bool isEmpty(){
	int a=(top==NULL) ? true:false;
	return a;
}
		

void display(){
	struct node *temp=top;
        while(top!=NULL){
                printf("%d ",top->data);
                top=top->next;
        }
	top=temp;
}


int main(){
	push(4);
	push(3);
	push(2);
	push(1);
	display();
	printf("\n");
	reverse();
	display();
}

		
