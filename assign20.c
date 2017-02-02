#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
	struct node *temp,*prev = rootPtr;	
	if(rootPtr==NULL){
          rootPtr = GetNewNode(x);
        }
	else
	{
	  struct node* parent = NULL;
	  struct node* newNode = GetNewNode(x);
	  struct node* curr = rootPtr;
	  while(curr != NULL){
	    parent = curr;
	    if(curr->data <= newNode->data){
	      curr = curr->right;
	    }
	    else{
	      curr = curr->left;
	    }
	  }
	  if(parent->data <= newNode->data){
	    parent->right = newNode;	
	  }
	  else{
	    parent->left = newNode;
	  }
	}
	  return rootPtr;
}

void displayInorder(struct node* rootPtr){
	if(rootPtr != NULL){
	  displayInorder(rootPtr->left);
	  printf("%d\t",rootPtr->data);
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
	printf("\n");
	return 0;
}
