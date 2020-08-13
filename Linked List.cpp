#include <stdio.h>
#include <malloc.h>

struct node{
	int value;
	struct node *nextaddress;
};


struct node *head, *tail;


struct node *createNode(){
	struct node *newnode;
	newnode = (struct node*) malloc(sizeof(struct node));
	newnode->nextaddress = NULL;
	
	printf("Enter value: ");
	scanf("%d", &newnode->value);
	
	return(newnode);
}


void insertBeginning(){
	struct node *newnode;
	newnode = createNode();
	
	if(head == NULL){
		head = newnode;
		tail = newnode;
	}
	else{
		newnode->nextaddress = head;
		head = newnode;
	}
}

void insertEnd(){
	struct node *newnode;
	newnode = createNode();
	
	if(head == NULL){
		head = newnode;
		tail = newnode;
	}
	else{
		tail->nextaddress = newnode;
		tail = newnode;
	}
}

int insertSpecific(){
	struct node *newnode, *temp, *beforetemp;
	int pos;
	
	newnode = createNode();
	
	printf("\nInsert at position: ");
	scanf("%d", &pos);
	
	if(head == NULL){
		head = newnode;
		tail = newnode;
	}
	else{
		temp = head;
		for(int i = 0; i < pos; i++){
			beforetemp = temp;
			
			if(temp->nextaddress == NULL){
				printf("\nInsertion out of bounds.\n");
				return 0;
			}
			
			temp = temp->nextaddress;
		}
		
		if(temp == head){
			newnode->nextaddress = temp;
			head = newnode;
			return 0;
		}
		
		newnode->nextaddress = temp;
		beforetemp->nextaddress = newnode;
	}
}

void deleteBeginning(){
	struct node *temp;
	
	if(head == NULL)
		printf("\nDeletion out of bounds.\n");
	if(head == tail){
		head = NULL;
		tail = NULL;
	}
	else{
		temp = head;
		head = temp->nextaddress;
		free(temp);
	}
}

void deleteEnd(){
	struct node *temp;
	
	if(head == NULL)
		printf("\nDeletion out of bounds.\n");
	if(head == tail){
		head = NULL;
		tail = NULL;
	}
	else{
		temp = head;
		while(temp->nextaddress != tail)
			temp = temp->nextaddress;
			
		free(tail);
		tail = temp;
		temp->nextaddress = NULL;
	}
}

int deleteSpecific(){
	struct node *temp, *beforetemp;
	int pos;
	
	printf("\nDelete position: ");
	scanf("%d", &pos);
	
	if(head == NULL)
		printf("\nDeletion invalid.\n");
	else{
		temp = head;
		for(int i = 0; i < pos; i++){
			beforetemp = temp;
			if(temp->nextaddress == NULL){
				printf("\nPosition out of bounds.\n");
				return 0;
			}
			temp = temp->nextaddress;
		}
		
		if(temp == head){
			head = temp->nextaddress;
			free(temp);
			return 0;
		}
		if(temp == tail){
			tail = beforetemp;
			beforetemp->nextaddress = NULL;
			free(temp);
			return 0;
		}
		
		beforetemp->nextaddress = temp->nextaddress;
		free(temp);
	}
}

int findByPos(){
	struct node *temp;
	int pos;
	
	printf("\nEnter position to find: ");
	scanf("%d", &pos);
	
	if(head == NULL){
		printf("\nList is empty.\n");
		return 0;
	}
	
	temp = head;
	for(int i = 0; i < pos; i++){
		if(temp->nextaddress == NULL){
			printf("\nPosition out of bounds.\n");
			return 0;
		}
		temp = temp->nextaddress;
	}
	
	printf("\nFound %d(%p) %p\n", temp->value, temp, temp->nextaddress);
}


int findByValue(){
	struct node *temp;
	int val, pos = 0;
	
	printf("\nEnter value to find: ");
	scanf("%d", &val);
	
	if(head == NULL){
		printf("\nList is empty.\n");
		return 0;
	}
	
	temp = head;
	while(temp != NULL){
		if(temp->value == val){
			printf("\nFound at position %d: %d(%p) %p\n", pos, temp->value, temp, temp->nextaddress);
			return 0;
		}
		
		pos++;
		temp = temp->nextaddress;
	}
	
	printf("\nNot found.\n");
}


int display(){
	struct node *temp;
	
	if(head == NULL){
		printf("\nList is empty.\n");
		return 0;
	}
	
	printf("\nHead: %d, Tail: %d\n", head->value, tail->value);
	
	printf("\nValue(Node)\t\tNext Node\n");
	
	temp = head;
	while(temp != NULL){
		printf("%d(%p)\t%p\n", temp->value, temp, temp->nextaddress);
		temp = temp->nextaddress;
	}
}

int main(){
	struct node *newnode, *temp;
	
	for(int i = 0; i < 4; i++){
		newnode = createNode();
		
		if(head == NULL){
			head = newnode;
			tail = newnode;
		}
		else{
			temp = head;
			
			while(temp->nextaddress != NULL)
				temp = temp->nextaddress;
			
			temp->nextaddress = newnode;
			tail = newnode;
		}
	}
	
	display();
	//insertSpecific();
	findByValue();
	display();
}
