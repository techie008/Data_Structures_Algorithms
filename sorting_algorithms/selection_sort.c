#include <stdio.h>
//Selection sort is an in-place and unstable algorithm, as it does not retain the position of duplicate elements
//Time Complexity : O(n^2) -->worst case
//Space Complexity : O(1)

/*Algorithm
 * Step1 : START
 * Step2 : iterate outer loop(i) from 0 to n
 * Step3 : set min_index=i
 * Step4 : iterate inner loop(j) from i+1 to n
 * Step5 : if arr[j]<arr[min_index]
 * 		set min_index=j
 * 	   [ENDOFIF]
 * Step6 : if min_index!=i
 * 		swap(arr[i],arr[min_index])
 * Step7 : Repeat the steps until loop's executed
 * Step8 : END
 */

void swap(int *a,int *b){
	int temp=*b;
	*b=*a;
	*a=temp;
}

void selection_sort(int arr[],int size){
	int min_index;
	for(int i=0;i<size;i++){
		min_index=i;
		//for finding the smallest element
		for(int j=i+1;j<size;j++){
			if(arr[j]<arr[min_index])
				min_index=j;
		}
		if(min_index!=i) //indicating a change in minimum element
			swap(&arr[i],&arr[min_index]);
	}
}

int main(){
	int size;
	scanf("%d",&size);
	int arr[size];
	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	selection_sort(arr,size);
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
