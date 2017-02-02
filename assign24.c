#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

#define STACK_SIZE 10

typedef struct stack{
	int top;
	struct node* elements[STACK_SIZE];
}stack;

int isempty(stack ms){
	if(ms.top < 0)
	  return 1;
	else 
	  return 0;
}

void push(stack *ms,struct node* element){
	if(ms->top < STACK_SIZE-1){
	  ms->elements[++(ms->top)] = element;
	}
	else{
	  printf("The stack is full\n");
	}
}

struct node* pop(stack *ms){
	if(ms->top > -1)
	  return ms->elements[(ms->top)--];
	else{
	  printf("Stack is empty\n");
	}
}

struct node* GetNewNode(int x){
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = x;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void displayInOrder(struct node* rootPtr){
	stack ms;
	ms.top = -1;

	if(rootPtr == NULL)
	  return;
	
	struct node* curr = rootPtr;
	while(!isempty(ms) || curr){
	  if(curr){
	    push(&ms,curr);
	    curr = curr->left;
	  }
	  else{
	    curr = pop(&ms);
	    printf("%d\t",curr->data);
	    curr = curr->right;
	  }	  
	}
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

int main(){
	int i,n,x;
	struct node* rootPtr = NULL;
	printf("Enter the number of elements to be inserted: \n");
	scanf("%d",&n);
	printf("Enter the elements: \n");
	for(i=0;i<n;i++){
	  scanf("%d",&x);
	  rootPtr = insert(rootPtr,x);
	}
	printf("The inorder traversal is: \n");
	displayInOrder(rootPtr);
	printf("\n");
	return 0;
}
