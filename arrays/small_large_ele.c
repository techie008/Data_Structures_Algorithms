//print the smallest and largest element in the array
//Simple Approach : traverse the array and update the smallest and largest element
//Time-Complexity : O(n)

//Efficient Approach : Sort the array with a O(logn) sorting algorithm then return the first and last element
//Time-Complexity : O(logn)

//Difficulty : Medium

#include <stdio.h>
int main(){
    int size;
    int ch;
    float sum=0;
    float avg=0;
    scanf("%d",&size);
    int array[size];
    
    for(int i=0;i<size;i++){
        scanf("%d",&array[i]);
    }
    scanf("%d",&ch);
    int large=array[0];
    int small=array[0];
    

    for(int i=1;i<size;i++){
        if(array[i]<small)
            small=array[i];
    }
        printf("%d",small);
    
  
    for(int i=1;i<size;i++){
        if(array[i]>large)
            large=array[i];
    }
        printf("%d",large);
    
}
