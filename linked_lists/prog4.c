//A program to print reverse of a linked list with carriage return
//Doesn't work on online compilers and linux terminals
//Nevertheless, it's an interesting trick

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


void print_reverse(int n){
	int j=0;
	struct node *temp=head;
	while(temp!=NULL){
		for(int i=0;i<2*(n-j);i++){
			printf(" ");
		}
		printf("%d\r",temp->data);
		temp=temp->next;
		j++;
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
        print_reverse(n);
        return 0;
}
