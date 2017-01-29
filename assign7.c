#include<stdio.h>


int partition(int *a,int start,int end){
	int i,temp=0;	
	int pivot = a[end];
	int partitionIndex = start;
	for(i=start;i<end;i++){
		if(a[i]<=pivot){
			temp = a[i];
			a[i] = a[partitionIndex];
			a[partitionIndex] = temp;
			partitionIndex++;	
		}
	}
	int temp1=0;
	temp1 = a[partitionIndex];
	a[partitionIndex] = a[end];
	a[end] = temp1;
	return partitionIndex;
}

void QuickSort(int *a,int start,int end){

	if(start<end){
		int partitionIndex = partition(a,start,end);
		QuickSort(a,start,partitionIndex-1);
		QuickSort(a,partitionIndex+1,end);
	}
}


int main(){

	int i,a[10],n;
	printf("Enter the number of elements in the array: \n");
	scanf("%d",&n);

	printf("Enter the elements: \n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);		
	}

	printf("The entered elements are: \n");
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);		
	}

	QuickSort(a,0,n-1);
	
	printf("The sorted array is: \n");
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
	return 0;
}


