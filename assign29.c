#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* head;

void addLast(int x){
	struct node* temp = (struct node*) malloc(sizeof(struct node));	
	if(head == NULL){
	  
	  temp->data = x;
	  temp->next = head;
	  head = temp;
	}
	else{
	  temp->data = x;
	  struct node* p = head;
	  while(p->next != NULL){
	    p = p->next;
  	  }
	  p->next = temp;
	  temp->next = NULL;
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

void sort(){
	struct node* temp = head;
	struct node* temp1;
	for( ;temp->next != NULL;temp = temp->next){
	  for(temp1 = temp->next; temp1 != NULL; temp1 = temp1 = temp1->next){
	    if(temp->data > temp1->data){
	      int p = temp->data;
	      temp->data = temp1->data;
	      temp1->data = p;
	    }
	  }
	}
}

int main(){
	int n,i,x;
	head = NULL;
	printf("Enter the number of elements to be inserted in the list: \n");
	scanf("%d",&n);
	printf("Enter the elements: \n");
	for(i=0;i<n;i++){
	  scanf("%d",&x);
	  addLast(x);
	}	
	printf("The linked list is: \n");
	display();
	printf("The sorted list is: \n");
	sort();
	display();
	return 0;
}
