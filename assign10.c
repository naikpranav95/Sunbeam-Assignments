#include<stdio.h>


int BinSearch(int *a,int low,int high,int key){

	while(low<=high){
		int mid = low + (high-low)/2;//(low+high) may overflow

		if(a[mid]==key)
			return mid;
		else if(key<a[mid])
			high = mid-1;
		else
			low = mid+1;
	}	
	return -1;
}


int main(){
	int a[10],n;
	printf("Enter the number of elements to be added: \n");
	scanf("%d",&n);

	printf("Enter the elements: \n");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	printf("The entered elements are: \n");
	for(int i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
	
	int temp;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]>a[j]){
				temp = a[i];
				a[i] = a[j];	
				a[j] = temp;
			}
		}
	}

	printf("The sorted numbers are: \n");
	for(int i=0;i<n;i++){
		printf("%d\n",a[i]);
	}

	int key;
	printf("Enter the number to be searched: \n");
	scanf("%d",&key);

	int low=0,high=n-1;
	int search = BinSearch(a,low,high,key);

	if(search>=0)
		printf("The number is in the array and at position %d\n",search+1);
	else
		printf("The number is not in the array\n");
	return 0;
}
