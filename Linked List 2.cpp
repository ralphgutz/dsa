#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct node{
	int value;
	struct node *nextNodeAddress;
};

struct node *createNode(){
	struct node *current;
	current = (struct node*) malloc(sizeof(struct node));
	return (current);
}

void display(struct node *head){
	struct node *t = head;
	while(t != NULL){
		printf("%d ", t->value);
		t = t->nextNodeAddress;
	}
}

void display2(struct node *head){
	for(struct node *t = head; t != NULL; t = t->nextNodeAddress){
		printf("%d ", t->value);
	}
}


// WITH PREV NODE
int main(){
	struct node *head, *tail, *prev;
	head = NULL;
	tail = NULL;
		
	for(int i=0; i<5; i++){
		struct node *current = (struct node*) malloc(sizeof(struct node));
		printf("Enter value: ");
		scanf("%d", &current->value);
		current->nextNodeAddress = NULL;
		
		if(head == NULL){
			head = current;
			tail = current;
		}
		else{
			// assigns the previous node's nextNodeAddress to current
			prev->nextNodeAddress = current;
			printf("Prev: %d %p\n", prev->value, &prev->nextNodeAddress);
		}
		// assigns the current as the previous
		prev = current;
		tail = current;
	}
	
	printf("\nHead: %d, Tail: %d", head->value, tail->value);
	
	printf("\n\nDisplay using while loop: ");
	display(head);
	
	printf("\nDisplay using for loop: ");
	display2(head);
}


// USING WHILE LOOP (TEMP AS TRAVERSAL)
int main2(){
	struct node *current, *head, *tail, *temp;
	
	head = NULL;
	
	for(int i=0; i<5; i++){
		current = createNode();
	
		printf("Enter value: ");
		scanf("%d", &current->value);
		
		current->nextNodeAddress = NULL;
		
		if(head==NULL){
			head = current;
			tail = current;
		}
		else{
			temp = head;
			// gets the last node as temp
			while(temp->nextNodeAddress != NULL){
				temp = temp->nextNodeAddress;
			}
			// assigns the current to the nextNodeAddress of last node
			temp->nextNodeAddress = current;
			tail = current;
		}
	}
	
	printf("\nHead: %d, Tail: %d", head->value, tail->value);
	
	printf("\n\nDisplay using while loop: ");
	display(head);
	
	printf("\nDisplay using for loop: ");
	display2(head);
}
