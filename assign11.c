#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};//Definition of node

struct node* head;

void addFirst(int x){
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->data = x;//temp is a pointer variable, we are dereferencing it to modify the value of this particular node
	temp->next = head;//It will help to point the link of first node to NULL
	head = temp;
}

void display(){
	struct node* temp = head;//using temp because we do not want to modify head
	while(temp!=NULL){
	  printf("%d\t",temp->data);
	  temp = temp->next;
	}
	printf("\n");
}

int main(){
	int n,i,x;
	head = NULL;//Empty list
	printf("How many numbers to be inserted: \n");
	scanf("%d",&n);

	printf("Enter the numbers: \n");
	for(i=0;i<n;i++){
	  scanf("%d",&x);
	  addFirst(x);	
	}
	display();

	return 0;
}


