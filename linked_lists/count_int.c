//write a function that counts number of times an integer occurs in a given linked list
//Time-Complexity : O(n) as it has to travel the whole linked list
//Space-Complexity : O(1)


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

void count_int(int n){
	int count=0;//stores the occurences of n
	struct node *temp=head;
	while(temp!=NULL){
		if(temp->data==n)
			count++;
		temp=temp->next;
	}
	printf("%d",count);
}

int main(){
        int size;//we are asking for size of linked list, but in real world it would be like entering elements until '0' is entered or '-1' is entered where size is made unknown.
        scanf("%d",&size);
        int item;
        while(size--){
                scanf("%d",&item);
                insert_node(item);
        }
	int n;
	scanf("%d",&n);
        count_int(n);
        return 0;
}
