#include<stdio.h>

void BubbleSort(int [],int );

int main(){

	int a[10],i,j,n;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}

	printf("The entered elements are: \n");
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
	

	BubbleSort(a,n);
	return 0;
}

void BubbleSort(int a[10],int n){
	int k,i,flag,temp;
	for(k=0;k<n-2;k++){
		flag=0;
		for(i=0;i<n-k-1;i++){
			if(a[i]>a[i+1]){
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = temp;
				flag=1;
			}
		}
		if(flag==0)
			break;
	}	

	printf("The sorted array is: \n");
	for(i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
}
