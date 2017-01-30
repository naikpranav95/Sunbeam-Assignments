#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* prev;
	struct node* next;
};

struct node* head;
struct node* last;

struct node* GetNewNode(int x){
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void insertAtHead(int x){
	struct node* newNode = GetNewNode(x);
	if(head == NULL){
	  head = newNode;
	  return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}

void deleteLast(){
	struct node* temp = head;
	while(temp->next!=NULL)
	{
	  temp = temp->next;
	}
	temp->prev->next = NULL;
	free(temp);
}

void display(){
	struct node* temp = head;
	while(temp != NULL){
	  printf("%d\t",temp->data);
	  temp = temp->next;
	}
	printf("\n");
}

int main(){
	int n,i,x;
	head = NULL;
	last = NULL;
	printf("How many numbers to be inserted: \n");
	scanf("%d",&n);
	printf("Enter the numbers: \n");
	for(i=0;i<n;i++){
	  scanf("%d",&x);
	  insertAtHead(x);
	}
	printf("The list is: \n");
	display();
	deleteLast();
	printf("The list after deleting the last element: \n");
	display();
	return 0;
}
