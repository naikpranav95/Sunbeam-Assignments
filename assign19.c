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

void loop(){
	
	if(head == NULL){
	  printf("The list is empty\n");	
	}
	else{
  	  struct node *fast,*slow;
	  fast = slow = head;
	  while(slow && fast && fast->next != NULL){
  	    fast = fast->next->next;
	    slow = slow->next;
	    if(slow == fast){
	      printf("Found a loop\n");
	      return;
	    }
	  }  	
	}
}

int main(){
	int n,x,i;
	head = NULL; 
	printf("Enter the number of elements you want in the list: \n");
	scanf("%d",&n);
	printf("Enter the elements: \n");
	for(i=0;i<n;i++){
	  scanf("%d",&x);
	  addLast(x);
	}
	printf("The list is: \n");
	display();
	//Created a loop
	head->next->next->next->next = head;
	loop();
	return 0;
}
