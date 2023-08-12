//reverse a whole string using stack by recursion
//we can do it simply by pushing the elements in the stack and popping them out, which would naturally give out a reversed string

//to make it more interesting and let's try with recursion
//example
//input : hello world
//output : dlrow olleh

#include <stdio.h>
#include <stdlib.h>

struct node{
	char data;
	struct node *next;
};

struct node *top=NULL;

void insert(char data);
bool isEmpty();

struct node *create_stack(char data){
        struct node *stack_node=(struct node *)malloc(sizeof(struct node));
        stack_node->data=data;
        stack_node->next=NULL;
        return stack_node;
}

void push(char data){
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
        char res=temp->data;
        free(temp);
        return res;
}

void display(){
        struct node *temp=top;
        while(top!=NULL){
                printf("%c",top->data);
                top=top->next;
        }
        top=temp;
}

int main(){
        char string[]="hello world hi there this is dave";
	int size=sizeof(string);
	
	for(int i=0;i<size;i++){
		if(string[i]!=' ' && string[i]!='\0')
			push(string[i]);
		else{
			display();
			top=NULL;
			printf("%c",' ');
		}	
	}
}






