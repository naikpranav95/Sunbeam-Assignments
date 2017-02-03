#include<stdio.h>
#include<stdlib.h>
#include<math.h>

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

void displayPostOrder(struct node* rootPtr){
	//Creating two stacks	
	stack ms;
	stack ms2;
	ms.top = -1;
	ms2.top = -1;
	
	if(rootPtr == NULL)
	  return;

	  //push root to first stack
	  push(&ms,rootPtr);
	  struct node* temp;
	  
	  //while first stack is not empty
	  while(!isempty(ms)){
	    //pop an item from first stack and push it to second stack
  	    temp = pop(&ms);
	    push(&ms2,temp);
	    //push left and right children of removed element of first stack
	    if(temp->left)
	      push(&ms,temp->left);
	    if(temp->right)
	      push(&ms,temp->right);
	  }
	
	//Printing all the elements from the second stack
	while(!isempty(ms2)){
	  temp = pop(&ms2);
	  printf("%d\t",temp->data);
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
	int i,x,n;
	struct node* rootPtr = NULL;	
	printf("Enter the number of elements to be inserted: \n");
	scanf("%d",&n);
	printf("Enter the elements: \n");
	for(i=0;i<n;i++){
	  scanf("%d",&x);
	  rootPtr = insert(rootPtr,x);
	}
	printf("The postorder is: \n");
	displayPostOrder(rootPtr);
	printf("\n");
	return 0;
}
