#include <stdio.h>
//dont get exited by the name,the time complexity is still O(n^2),but it does reduce some time

void swap(int *a,int *b){
	int temp=*b;
	*b=*a;
	*a=temp;
}

void bubble_sort_optimized(int arr[],int size){
	bool swapped;
	for(int i=0;i<size;i++){
		swapped=false;
		for(int j=0;j<size-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(&arr[j+1],&arr[j]);
				swapped=true;
			}
		}
		if(swapped=false)
			break;
	}
}

int main(){
	int size;
	scanf("%d",&size);
	int arr[size];
	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	bubble_sort_optimized(arr,size);
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
