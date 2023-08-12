//Find the middle element of a linked list
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

void find_mid_ele(){
	//asumming we dont know n
	int count=0;
	int mid_index;
	struct node *temp=head;
	while(temp!=NULL){
		temp=temp->next;
		count++;
	}
	//calculating the middle posititon
	if(count%2==0)
		mid_index=(count/2)+1;//for even
	else
		mid_index=(count/2);//for odd
	temp=head;

	for(int i=1;i<mid_index;i++){
		temp=temp->next;//traversing until middle index is reached
	}
	printf("%d",temp->data);
}


int main(){
	int n;
	scanf("%d",&n);
	int item;
	while(n--){
		scanf("%d",&item);
		insert_node(item);
	}
	find_mid_ele();
	return 0;
}
