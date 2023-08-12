#include <stdio.h>
//insertion sort is an in-place and stable algorithm
//Time-Complexity : O(n^2) --> worst-case
//Space-Complexity : O(1)
//It's best to use when an array is partially sorted

/*Algorithm:
 * Step1 : START
 * Step2 : iterate from i=1 to i<size
 * Step3 : set key=ar[i]
 * Step4 : set j=i-1
 * Step5 : set ar[j+1]=ar[j]
 * Step6 : do j=j-1
 * Step7 : repeat step5 and step6 while j>=0 & key<=ar[j]
 * Step8 : set ar[j+1]=key;
 * step9 : EXIT
 */

void insertion_sort(int arr[],int size){
	int key;
	int j=0;
	for(int i=1;i<size;i++){
		key=arr[i];
		j=i-1;
		while(j>=0 && key<=arr[j]){
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}
}

int main(){
	int size;
	scanf("%d",&size);
	int arr[size];
	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	insertion_sort(arr,size);
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
