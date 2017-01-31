#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* addLast(struct node* head,int x){
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	if(head!=NULL){
	  temp->data = x;
	  struct node* p = head;
	  while(p->next != NULL){
	    p = p->next;
	  }
	  p->next = temp;
	  temp->next = NULL;
	}
	else{
	  temp->data = x;
	  temp->next = head;
 	  head = temp;
	}
	return head;
}

struct node* reverse(struct node* head){
	struct node *current,*next,*prev;
	current = head;
	prev = NULL;
	while(current != NULL){
	  next = current->next;
	  current->next = prev;
	  prev = current;
	  current = next;
	}
	head = prev;
	return head;
}

void display(struct node* head){
	struct node* temp = head;
	while(temp != NULL){
  	  printf("%d\t",temp->data);
	  temp = temp->next;	
	}
	printf("\n");
}

int main(){
	int n,x,i;
	struct node* head = NULL;
	printf("Enter the number of elements to be inserted in the list: \n");
	scanf("%d",&n);

	printf("Enter the elements: \n");	
	for(i=0;i<n;i++){
	  scanf("%d",&x);
	  head = addLast(head,x);
	}
	

	display(head);
	head = reverse(head);
	display(head);
	return 0;
}
