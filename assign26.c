#include<stdio.h>
#define SWAP(x,y) int t;t=x;x=y;y=t;
#define SWAP2(x,y) x=x+y;y=x-y;x=x-y;

int main(){
	int a,b;
	printf("Enter the numbers: \n");
	scanf("%d%d",&a,&b);
	printf("Before swapping: a=%d and b=%d\n",a,b);
	SWAP(a,b);
	printf("After swapping: a=%d and b=%d\n",a,b);

	int p,q;
	printf("\nEnter the numbers: \n");
	scanf("%d%d",&p,&q);
	
	printf("Before swapping: p=%d and q=%d\n",p,q);
	printf("By the seacond swap method: \n");
	SWAP2(p,q);
	printf("After the swapping: p=%d and q=%d\n",p,q);
	 
	return 0;
}
