#include <stdio.h>
//Merge sort is an out-place and stable algorithm, though it can be made in-place
//Time Complexity : O(nLogn) in all three cases
//Space Complexity : O(N)
//merge sort is used for large datasets
//when it comes to linked list sorting, merge sort is your answer

/*Algorithm:
 * Step1 : START
 * Step2 : calculate mid=high+low/2
 * Step3 : recursively perform merge_sort on left array
 * Step4 : recursively perform merge sort on right array
 * Step5 : then merge the two sorted sub-arrays
 * Step6 : EXIT
 */


void merge(int arr[],int low,int mid,int high){
	int i,j,k;
	int n1=mid-low+1;
	int n2=high-mid;

	int l1[n1];
	int l2[n2];
	
	for(i=0;i<n1;i++){
		l1[i]=arr[low+i];
	}
	for(j=0;j<n2;j++){
		l2[j]=arr[mid+j+1];
	}
	i=0;j=0;k=low;
	while(i<n1 && j<n2){
		if(l1[i]<=l2[j]){
			arr[k]=l1[i];
			i++;
		}
		else{
			arr[k]=l2[j];
			j++;
		}
		k++;
	}
	//remaining elements
	while(i<n1){
		arr[k]=l1[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k]=l2[j];
		j++;
		k++;
	}
}

void merge_sort(int arr[],int low,int high){
	if(low<high){
		int mid=low+(high-low)/2;

		merge_sort(arr,low,mid);
		merge_sort(arr,mid+1,high);

		merge(arr,low,mid,high);
	}
}

int main(){
	int size;
	scanf("%d",&size);
	int arr[size];
	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	merge_sort(arr,0,size-1);
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
