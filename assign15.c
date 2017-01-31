#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* prev;
	struct node* next;
};

struct node* head;
struct node* last;
int n = 0;

struct node* GetNewNode(int x){
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void addLast(int x){
	struct node* newNode = GetNewNode(x);	
	if(head==last && head==NULL){//head==last condition is for the addition of the second element
 	  head = last = newNode;
	  head->next = last->next = NULL;
	  head->prev = last->prev = NULL;
	  return;
	}
	last->next = newNode;
	newNode->prev = last;
	last = newNode;
	head->prev = last;
	last->next = head;	
}

void deleteFirst(){
	if(head==last && head == NULL){
	  printf("The list is empty\n");
	}	
	else{
	  n--;
	  struct node* temp = head;
	  head = temp->next;
	  last->next = head;
	  head->prev = last;
	  free(temp);
	}
}

void display(){
	int i;
	if(head==last && head == NULL){
	  printf("The list is empty\n");
	}
	else{
	  struct node* temp = head;
	  printf("The list is: \n");
	  for(i=0;i<n;i++){
	    printf("%d\t",temp->data);
	    temp = temp->next;
	  }
	  printf("\n");
	}
}

int main(){
	int x,i;
	head = NULL;
	last = NULL;
	printf("How many numbers to be inserted: \n");
	scanf("%d",&n);
	printf("Enter the elements: \n");
	for(i=0;i<n;i++){
  	  scanf("%d",&x);
	  addLast(x);
	}
	display();
	deleteFirst();
	display();
}
