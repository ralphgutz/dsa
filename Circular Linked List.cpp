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

int insertSpecific(int data, int pos){
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

void deleteBeginning(){
	struct node *temp;
	
	if(head == NULL && tail == NULL){
		printf("\nList is empty.\n");
	}
	else{
		temp = head;
		head = head->nextaddress;
		free(temp);
		tail->nextaddress = head;
	}
}

void deleteEnd(){
	struct node *temp, *beforetail;
	
	if(head == NULL && tail == NULL){
		printf("\nList is empty.\n");
	}
	else{
		beforetail = head;
		while(beforetail->nextaddress != tail){  // gets the node before tail
			beforetail = beforetail->nextaddress;
		}
		
		beforetail->nextaddress = tail->nextaddress;
		temp = tail;
		free(temp);
		tail = beforetail;
	}
}

void deleteSpecific(int pos){
	struct node *temp, *todelete;
	
	if(head == NULL && tail == NULL){
		printf("\nList is empty.\n");
	}
	else{
		temp = head;
		for(int i = 0; i < pos-1; i++){
			temp = temp->nextaddress;
		}  // temp will be the node before todelete

		if(temp == head && pos == 0){
			printf("\nDeleting %d (%p)\n", temp->value, temp);
			tail->nextaddress = temp->nextaddress;
			head = temp->nextaddress;
			free(temp);
		}
		else{
			printf("\nDeleting %d (%p)\n", temp->nextaddress->value, temp->nextaddress);
			todelete = temp->nextaddress;
			
			if(temp->nextaddress == tail){  // deleting tail
				tail = temp;
			}
			else if(temp == tail){  // deleting head after 1 revolution
				head = head->nextaddress;
			}
			
			temp->nextaddress = todelete->nextaddress;  // assigning temp's nextaddress to todelete's nextaddress
			free(todelete);
		}
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
		while(temp->nextaddress != head){  // so it won't display forever
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

/**  TO GET THE SPECIFIC NODE IN TEMP:
	for(int i = 0; i < pos; i++){
		temp = temp->nextaddress;
	}
**/
