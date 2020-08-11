#include <stdio.h>
#include <malloc.h>

struct node{
	struct node *left;
	int value;
	struct node *right;
};


struct node *head, *tail = NULL;

struct node *createNode(){
	struct node *newnode = (struct node*) malloc(sizeof(struct node));
	newnode->left = NULL;
	newnode->right = NULL;
	
	printf("Enter value: ");
	scanf("%d", &newnode->value);
	
	return newnode;
}

void display();
struct node *findByPos();
struct node *findByValue();


void insertBeginning(){
	struct node *current;
	printf("\nInserting at the beginning\n");
	current = createNode();
	
	if(head == NULL){
		head = current;
		tail = current;
	}
	else{
		head->left = current;
		current->right = head;
		head = current;
	}
}

void insertEnd(){
	struct node *current;
	printf("\nInserting at the end\n");
	current = createNode();
	
	if(head == NULL){
		head = current;
		tail = current;
	}
	else{
		tail->right = current;
		current->left = tail;
		tail = current;
	}
}

int insertSpecific(){
	struct node *newnode, *old;
	int pos;
	
	printf("\nInsert node at position: ");
	scanf("%d", &pos);
	
	if(head == NULL){
		printf("\nList is empty.");
	}
	else{
		old = head;
		for(int i = 0; i < pos; i++){
			if(old->right == NULL){
				printf("\nPosition out of bounds.\n");
				return 0;
			}
			old = old->right;
			
		}
	}
	
	printf("\nFound:%p\t%d(%p)\t%p\n", old->left, old->value, old, old->right);
	
	newnode = createNode();
	
	if(old == NULL){
		printf("\nInsertion is invalid.");
	}
	else{
		if(old == head)
			head = newnode;
		
		if(old->left != NULL){
			newnode->left = old->left;
			old->left->right = newnode;
			old->left = newnode;
		}
		
		newnode->right = old;
	}
}

void deleteBeginning(){
	struct node *current;
	
	if(head == NULL){
		printf("\nList is empty.");
	}
	else{
		current = head;
		head = current->right;
		head->left = NULL;
		free(current);
	}
}

void deleteEnd(){
	struct node *current;
	
	if(head == NULL){
		printf("\nList is empty.");
	}
	else{
		current = tail;
		tail = current->left;
		tail->right = NULL;
		free(current);
	}
}

int deleteSpecific(){
	struct node *current;
	int pos;
	
	printf("\nDelete node at position: ");
	scanf("%d", &pos);
	
	if(head == NULL){
		printf("\nList is empty.");
	}
	else{
		current = head;
		for(int i = 0; i < pos; i++){
			if(current->right == NULL){
				printf("\nPosition out of bounds.");
				return 0;
			}
			current = current->right;
		}
	}
	
	if(current == NULL){
		printf("\nDeletion is invalid.\n");
	}
	else{
		if(current == head){
			head = current->right;
			current->right->left = NULL;
			free(current);
			return 0;
		}
		if(current == tail){
			tail = current->left;
			current->left->right = NULL;
			free(current);
			return 0;
		}

		current->left->right = current->right;
		current->right->left = current->left;
		free(current);
		return 0;	
	}
}

int main(){
	struct node *current, *temp;
	
	for(int i=0; i<2; i++){
		current = createNode();
		current->left = NULL;
		current->right = NULL;
		
		if(head == NULL){
			head = current;
			tail = current;
		}
		else{
			temp = head;
			while(temp->right != NULL){
				temp = temp->right;
			}
			temp->right = current;
			current->left = temp;
			tail = current;
		}
	}
	
	insertBeginning();
	insertEnd();
//	struct node *foundValue = findByValue();
//	if(foundValue != 0)
//		printf("\nFound:%p\t%d(%p)\t%p\n", foundValue->left, foundValue->value, foundValue, foundValue->right);
//	else
//		printf("Not found.\n");
	display();
	deleteSpecific();
	
	
	display();
	struct node *foundPos = findByPos();
	if(foundPos != 0)
		printf("\n\nFound:%p\t%d(%p)\t%p\n", foundPos->left, foundPos->value, foundPos, foundPos->right);
	
}


struct node *findByPos(){
	struct node *t;
	int pos;
	
	printf("\nEnter position to find: ");
	scanf("%d", &pos);
	
	if(head == NULL){
		printf("\nList is empty.");
	}
	else{
		t = head;
		for(int i = 0; i < pos; i++){
			if(t->right == NULL){
				printf("\nPosition out of bounds.\n");
				return 0;
			}
			t = t->right;
		}
		return t;
	}
}

struct node *findByValue(){
	struct node *t;
	int data;
	
	printf("\nEnter value to find: ");
	scanf("%d", &data);
	
	if(head == NULL){
		printf("\nList is empty.");
	}
	else{
		t = head;
		while(t != NULL){
			if(t->value == data){
				return t;
			}
			
			t = t->right;
		}
		return 0;
	}
}


void display(){
	struct node *t = head;
	
	printf("\nHead: %d, Tail: %d\n\n", head->value, tail->value);
	
	printf("Left Node\t\tValue(Node)\t\tRight Node\n");
	
	while(t != NULL){
		printf("%p\t%d(%p)\t%p\n", t->left, t->value, t, t->right);
		t = t->right;
	}
}
