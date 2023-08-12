//Write a program to accept a 3 x 3 matrix and print the sum of individual rows in the matrix
//Approach : Create a 2-dimensional array
//Time-Complexity : O(n^2) where n refers to number rows of matrix


#include <stdio.h>

int main(){
    int k;
    int sum;
    int array[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&array[i][j]);
        }
    }
    for(int i=0;i<3;i++){
        sum=0;
        for(int j=0;j<3;j++){
            sum+=array[i][j];
        }
        printf("Sum of row%d=%d",i,sum);
    }
    
}
