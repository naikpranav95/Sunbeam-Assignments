#include<stdio.h>

int main(){
	int i,a[5],j;
	printf("Enter the elements: ");
	
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}

	printf("The enetered numbers are: \n");
	for(i=0;i<5;i++)
	{
		printf("%d\n",a[i]);
	}
	
	int temp;
	for(i=0;i<5;i++){
		for(j=i+1;j<5;j++){
			if(a[i]>a[j]){
				temp = a[i];
				a[i] = a[j];	
				a[j] = temp;
			}
		}
	}

	printf("The sorted numbers are: \n");
	for(i=0;i<5;i++){
		printf("%d\n",a[i]);
	}

	return 0;
}
