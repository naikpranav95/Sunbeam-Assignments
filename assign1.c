#include<stdio.h>
#include<string.h>

void main(){
	char string1[10],string2[10];
	printf("Enter the first string: ");
	scanf("%s",string1);
	
	printf("Enter the second string: ");
	scanf("%s",string2);
	int test = strcmp(string1,string2);
	
	if(test == 0){
		printf("The strings are equal\n");
	}	
	else{
		printf("The strings are not equal\n");	
	}
}
