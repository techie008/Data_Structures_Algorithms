/*
  Write a program to Accept n numbers in an array. 
  Accept a search element and print if the search element is available in the array. If available print "Yes". Element exists” else print “No". The element does not exist”.
*/
//Time-Complexity : O(n)
//Difficulty : Easy

#include <stdio.h>

int main(){
    int size;
    int ele;
    int flag=0;
    scanf("%d",&size);
    int array[size];
    for(int i=0;i<size;i++){
        scanf("%d",&array[i]);
    }
    scanf("%d",&ele);
    
    for(int i=0;i<size;i++){
        if(array[i]==ele){
            flag=1;
            break;
        }
    }
    if(flag==1)
        printf("Yes. Element exists");
    else
        printf("No. Element does not exist");
    
}
