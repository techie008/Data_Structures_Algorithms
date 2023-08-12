//Write a program to perform polynomial addition
/*Input-format
2  //first polynomial
0 5
1 8
3  //second polynomial
0 2 
1 5
2 8
*/

/*Output-format
1’st polynomial : 5X^0 8X^1 
2’nd polynomial : 2X^0 5X^1 8X^2 
Sum : 7X^0 13X^1 8X^2 
*/
//Difficulty : Hard

#include <stdio.h>
#include <stdlib.h>

struct stack{
    int top1,top2;
    int size;
    int *pow1;int *eq1;
    int *pow2;int *eq2;
};

struct stack* create_stack(int size){
    struct stack *stack=(struct stack *)malloc(sizeof(struct stack));
    stack->top1=-1;
    stack->top2=-1;
    stack->size=size;
    stack->pow1=(int *)malloc(size*sizeof(int));
    stack->pow2=(int *)malloc(size*sizeof(int));
    stack->eq1=(int *)malloc(size*sizeof(int));
    stack->eq2=(int *)malloc(size*sizeof(int));
    return stack;
}

void push(struct stack *stack,int power,int data,int ch){
    if(ch==1){
        stack->eq1[++stack->top1]=data;
        stack->pow1[stack->top1]=power;
    }
    if(ch==2){
        stack->eq2[++stack->top2]=data;
        stack->pow2[stack->top2]=power;
    }
}

void display(struct stack *stack,int ch){
    if(ch==1){
        int temp=stack->top1;
        stack->top1=0;
        while(stack->top1<=temp){
            printf("%dX^%d ",stack->eq1[stack->top1],stack->pow1[stack->top1]);
            stack->top1++;
        }
        stack->top1=temp;
    }
    
    if(ch==2){
        int temp=stack->top2;
        stack->top2=0;
        while(stack->top2<=temp){
            printf("%dX^%d ",stack->eq2[stack->top2],stack->pow2[stack->top2]);
            stack->top2++;
        }
        stack->top2=temp;
    }
}

void sum(struct stack *stack){
    int temp1=stack->top1;
    stack->top1=0;
    int temp2=stack->top2;
    stack->top2=0;
    
    while(stack->top1<=temp1){
        if(stack->pow1[stack->top1]==stack->pow2[stack->top2]){
            printf("%dX^%d ",stack->eq1[stack->top1]+stack->eq2[stack->top2],stack->pow1[stack->top1]);
            stack->top1++;stack->top2++;
        }
        else if(stack->pow1[stack->top1]!=stack->pow2[stack->top2]){
            printf("%dX^%d ",stack->eq1[stack->top1],stack->pow1[stack->top1]);
            stack->top1++;
        }
    }
    if(stack->top2!=temp2 || stack->top2==temp2){
        while(stack->top2<=temp2){
            printf("%dX^%d ",stack->eq2[stack->top2],stack->pow2[stack->top2]);
            stack->top2++;
        }
    }
    
}

int main(){
    struct stack *stack=create_stack(20);
    int n1,n2;
    int power,value;
    scanf("%d",&n1);
    
    while(n1--){
        scanf("%d %d",&power,&value);
        push(stack,power,value,1);
    }
    
    scanf("%d",&n2);
    while(n2--){
        scanf("%d %d",&power,&value);
        push(stack,power,value,2);
    }
    
    printf("1'st polynomial : ");
    display(stack,1);
    printf("\n2'nd polynomial : ");
    display(stack,2);
    printf("\nSum : ");
    sum(stack);
}
