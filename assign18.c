#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* head;

void addLast(int x){
	struct node* newNode = (struct node*) malloc(sizeof(struct node));
	if(head != NULL){
	  newNode->data = x;
	  struct node* p = head;
	  while(p->next != NULL){
	    p = p->next;
	  }
	  p->next = newNode;
	  newNode->next = NULL;
	}
	else{
	  newNode->data = x;
	  newNode->next = head;
	  head = newNode;	
	}
}

void display(){
	struct node* temp = head;
	while(temp != NULL){
	  printf("%d\t",temp->data);
	  temp = temp->next;
	}
	printf("\n");
}

void middle(){
	
	if(head == NULL){
	  printf("The list is empty");	
	}
	else{
	  struct node *fast,*slow;
	  fast = slow = head;
	  while(fast != NULL && fast->next != NULL){
	    fast = fast->next->next;
	    slow = slow->next;
	  }
	printf("%d\n",slow->data);
	}
}

int main(){
	int n,i,x;
	head = NULL;
	printf("Enter the number of elements to be inserted: \n");
	scanf("%d",&n);
	printf("Enter the elements to be added in the list: \n");
	for(i=0;i<n;i++){
	  scanf("%d",&x);
	  addLast(x);
	}
	display();
	printf("The middle element in the list is: \n");
	middle();
	return 0;
}
