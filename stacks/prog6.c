//find the intersection of two given linked lists


#include <stdio.h>
#include <stdlib.h>

struct node{
        int data;
        struct node *next;
};

struct node *head1=NULL;
struct node *head2=NULL;

void insert_node(struct node *head,int data){
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


int main(){
        int n1,n2;
        scanf("%d",&n1);
        int item;
        while(n--){
                scanf("%d",&item);
                insert_node(head1,item);
        }
	scanf("%d",&n2);

        find_mid_ele();
        return 0;
}
