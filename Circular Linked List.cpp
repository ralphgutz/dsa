#include <stdio.h>
#include <malloc.h>

struct node{
	int value;
	struct node *nextaddress;
};

struct node *head, *tail = NULL;

struct node *createNode(){
	struct node *newnode = (struct node*) malloc(sizeof(struct node));
	return(newnode);
}

void insertBeginning(int data){
	struct node *newnode = createNode();
	
	newnode->nextaddress = NULL;
	newnode->value = data;
	
	if(head == NULL && tail == NULL){
		head = tail = newnode;
	}
	else{
		newnode->nextaddress = head;
		head = newnode;
	}
	
	tail->nextaddress = head;
}

void insertEnd(int data){
	struct node *newnode = createNode();
	
	newnode->nextaddress = NULL;
	newnode->value = data;
	
	if(head == NULL && tail == NULL){
		head = tail = newnode;
	}
	else{
		tail->nextaddress = newnode;
		newnode->nextaddress = head;
		tail = newnode;
	}
	
	tail->nextaddress = head;
}

void insertSpecific(int data, int pos){
	struct node *newnode, *temp;
	newnode = createNode();
	
	newnode->nextaddress = NULL;
	newnode->value = data;
	
	if(head == NULL && tail == NULL){
		head = tail = newnode;
		newnode->nextaddress = head;
	}
	else{
		temp = head;
		for(int i = 0; i < pos-1; i++){ // 1<3
			temp = temp->nextaddress;
		}
		
		printf("%d (%p)\t%p\n", temp->value, temp, temp->nextaddress);

		if(temp == head && pos == 0){
			newnode->nextaddress = temp;
			head = newnode;
		}
		else if(temp == tail){
			newnode->nextaddress = temp->nextaddress;
			temp->nextaddress = newnode;
			head = newnode;
			tail = temp;
		}
		else{
			newnode->nextaddress = temp->nextaddress;
			temp->nextaddress = newnode;
		}

		tail->nextaddress = head;
	}
}

void display(){
	struct node *temp;
	
	if(head == NULL && tail == NULL){
		printf("\nList is empty.\n");
	}
	else{
		
		printf("\nHead: %d, Tail: %d\n", head->value, tail->value);
		
		printf("\nValue(Node)\t\tNext Node\n");
		
		temp = head;
		while(temp->nextaddress != head){
			printf("%d (%p)\t%p\n", temp->value, temp, temp->nextaddress);
			temp = temp->nextaddress;
		}
		printf("%d (%p)\t%p\n", temp->value, temp, temp->nextaddress);
	}
}

int main(){
	insertEnd(1);
	insertEnd(2);
	insertEnd(3);
	insertEnd(4);
	insertSpecific(69, 8);
	display();
}
