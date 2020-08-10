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
struct node *find();


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
	struct node *found = find();
	if(found != 0)
		printf("\nFound:%p\t%d(%p)\t%p\n", found->left, found->value, found, found->right);
	else
		printf("Not found.\n");
	
	display();
}


struct node *find(){
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
