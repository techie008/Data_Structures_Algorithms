//Given an array of integers that is initially increasing and then decreasing, find the maximum value in the array.
//Difficulty : Medium
//Time-Complexity : O(n)

#include <stdio.h>


int main(){
    int size,max;
    scanf("%d",&size);
    int array[size];
    for(int i=0;i<size;i++){
        scanf("%d",&array[i]);
    }
    max=array[0];
    for(int i=1;i<size;i++){
        if(array[i]>max){
            max=array[i];
        }
        else{
          break;
        }
    }
    printf("%d",max);
}

