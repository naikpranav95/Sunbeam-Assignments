#include<stdio.h>


void Merge(int *a,int *left,int lSize,int *right,int rSize){
	
	int i=0,j=0,k=0;
	while(i<lSize && j<rSize){
		if(left[i]<right[j]){
			a[k] = left[i];
			i++;
			k++;
		}
		else{
			a[k] = right[j];
			j++;
			k++;
		}
	}
	while(i<lSize){
		a[k] = left[i];
		k++;
		i++;
	}

	while(j<rSize){
		a[k] = right[j];
		k++;
		j++;
	}	
		
}

void MergeSort(int *a,int n){
	
	if(n<2){
		return;
	}//base condition for the recursion, if array has less than 2 elements
 	int mid = n/2;
	int left[mid],right[n-mid];
	for(int i=0;i<mid;i++){
		left[i] = a[i];
	}
	
	for(int i=mid;i<n;i++){
		right[i-mid] = a[i];
	}

	/*printf("The left array is: \n");
	for(int i=0;i<mid;i++){
		printf("%d\n",left[i]);
	}

	printf("The right array is: \n");
	for(int i=0;i<mid;i++){
		printf("%d\n",right[i]);
	}*/

	MergeSort(left,mid);
	MergeSort(right,n-mid);
	Merge(a,left,mid,right,n-mid);
}

int main(){
	int n,i,a[10];
	printf("Enter the number of elements for the array: \n");
	scanf("%d",&n);

	printf("Enter the elements: \n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	printf("The entered elements are: \n");
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}	
	
	MergeSort(a,n);	
	
	printf("The sorted array is: \n");
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);	
	}
	
	return 0;
}
