#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};


struct node* GetNewNode(int x){
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = x;
	newNode->left = newNode->right = NULL;
	return newNode;
}

struct node* insert(struct node* rootPtr,int x){
	if(rootPtr == NULL){
	  rootPtr = GetNewNode(x);
	}
	else if(x <= rootPtr->data){
	  rootPtr->left = insert(rootPtr->left,x);
	}
	else{
	  rootPtr->right = insert(rootPtr->right,x);	
	}
	return rootPtr;
}

void displayInorder(struct node* rootPtr){
	if(rootPtr != NULL){
	  displayInorder(rootPtr->left);
	  printf("%d",rootPtr->data);
	  displayInorder(rootPtr->right);
	}
}

int main(){
	int n,i,x;
	struct node* rootPtr = NULL;
	printf("Enter the number of elements to be inserted in the binary search tree: \n");
	scanf("%d",&n);
	printf("Enter the elements: \n");
	for(i=0;i<n;i++){
	  scanf("%d",&x);
	  rootPtr = insert(rootPtr,x);	  	
	}
	displayInorder(rootPtr);
	return 0;
}
