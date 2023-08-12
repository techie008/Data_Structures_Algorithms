#include <stdio.h>
//bubble sort is in-place and stable algorithm
//Time Complexity : O(n^2) -->worst case
//Space COmplexity : O(1)

/*Bubble sort algorithm is the most simplest algorithm with a time complexity of O(n^2), it's used mostly for educational purpose.
 * Algorithm:
 * 	step 1: start 
 * 	step 2: traverse from left to right 
 * 	step 3: while traversing compare the adjacent elements
 * 	step 4: and adjust the larger element on the right most side
 * 	step 5: continue the steps until the array is completely sorted
 * 	step 6: END
 */

//function to swap the adjacent elements for step 4
void swap(int *a,int *b){
	int temp=*b;
	*b=*a;
	*a=temp;
}

void bubble_sort(int arr[],int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size-i-1;j++){
			if(arr[j]>arr[j+1])
				swap(&arr[j+1],&arr[j]);
		}
	}
}

int main(){
	int size;
	scanf("%d",&size);
	int arr[size];
	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	bubble_sort(arr,size);
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
