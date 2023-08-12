/*
Given an unsorted array that may contain duplicates, check if the given array contains duplicate elements within 'k' distance from each other. 
Also, given a number 'k' which is smaller than the size of the array, write a program that returns true if the array contains duplicates within 'k' distance.
*/
//Difficulty : Medium
//Time-Complexity : O(n^2)

#include <stdio.h>

int main(){
    
    int count;
    int size;
    int k,dupl;
    scanf("%d",&size);
    int array[size];
    for(int i=0;i<size;i++){
        scanf("%d",&array[i]);
    }
    scanf("%d",&k);
    
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(array[i]==array[j]){
                dupl=j-i;
            }
        }
    }
    if(dupl==k){
        printf("Yes");
    }
    else
        printf("No");
}



