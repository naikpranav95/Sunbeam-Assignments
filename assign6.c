#include<stdio.h>

int InsertionSort(int [],int );

int main(){
	int i,n,a[10];
	printf("Enter the number of elements: \n");
	scanf("%d",&n);

	printf("Enter the elements: \n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	printf("The numbers are: \n");
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}

	InsertionSort(a,n);

	return 0;
}

int InsertionSort(int a[10],int n){
	int i,hole,value;

	for(i=1;i<=n-1;i++){
		value = a[i];
		hole = i;
		while(hole>0 && a[hole-1]>value){
			a[hole] = a[hole-1];
			hole = hole-1;
		}
		a[hole] = value;
	}	

	printf("The sorted array is: \n");
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
}
