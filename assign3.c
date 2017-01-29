#include<stdio.h>
#include<string.h>

void main(){
	
	char string1[10];
	printf("Enter the string: ");
	scanf("%s",string1);
	
	printf("The reversed string is: %s",strrev(string1));

	
}
