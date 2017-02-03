#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char str1[10],str2[10],temp[10];
	printf("Enter the two strings: \n");
	scanf(" %s %s",str1,str2);
	printf("Before swapping: string1=%s and string2=%s\n",str1,str2); 
	strcpy(temp,str1);
   	strcpy(str1,str2);
   	strcpy(str2,temp);
	printf("After swapping: string1=%s and string2=%s\n",str1,str2);
	
	return 0;
}
