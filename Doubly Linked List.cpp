#include <stdio.h>
#include <malloc.h>

struct node{
	struct node *left;
	int value;
	struct node *right;
};


struct node *head, *tail = NULL;

int menu();

struct node *createNode(){
	struct node *newnode = (struct node*) malloc(sizeof(struct node));
	newnode->left = NULL;
	newnode->right = NULL;
	
	printf("Enter value: ");
	scanf("%d", &newnode->value);
	
	return newnode;
}


void insertBeginning(){
	struct node *current;
	printf("\nInserting at the beginning\n");
	current = createNode();
	
	if(head == NULL){
		head = current;
		tail = current;
	}
	else{
		// head's left address to newnode, newnode's right address to head, assign newnode as new head
		head->left = current;
		current->right = head;
		head = current;
	}
	
	menu();
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
		// tail's right address to newnode, newnode's left address to tail, assign newnode as new tail
		tail->right = current;
		current->left = tail;
		tail = current;
	}
	
	menu();
}


int insertSpecific(){
	struct node *newnode, *old;
	int pos;
	
	printf("\nInsert node at position: ");
	scanf("%d", &pos);
	
	if(head == NULL){
		printf("\nList is empty.\n");
	}
	else{
		// old as traversal
		old = head;
		for(int i = 0; i < pos; i++){
			
			// if old's right address is NULL (if it is beyond tail), return 0
			if(old->right == NULL){
				printf("\nPosition out of bounds.\n");
				menu();
				return 0;
			}
			
			// old becomes old's right address (counter/traversal). after loop, old is pos == node's position
			old = old->right;
		}
	}
	
	printf("\nFound:%p\t%d(%p)\t%p\n", old->left, old->value, old, old->right);
	
	newnode = createNode();
	
	if(old == NULL){
		printf("\nInsertion is invalid.\n");
	}
	else{
		if(old == head)  // if old node is the head, assign newnode as new head
			head = newnode;
		
		if(old->left != NULL){  // if old node is not the head (better to illustrate)
			// newnode's left address to old's left node, old's left node's right address to newnode, old's left address to newnode
			newnode->left = old->left;
			old->left->right = newnode;
			old->left = newnode;
		}
		
		newnode->right = old;  // newnode's right address to old
	}
	
	menu();
}


void deleteBeginning(){
	// head_temp is the node to be deleted
	struct node *head_temp;
	
	if(head == NULL){
		printf("\nList is empty.\n");
	}
	else{
		// head_temp as temp node of head, new head becomes temp's (head's) right node, temp's (head's) left address to NULL, free temp's memory
		head_temp = head;
		head = head_temp->right;
		head->left = NULL;
		free(head_temp);
	}
	
	menu();
}


void deleteEnd(){
	// tail_temp is the node to be deleted
	struct node *tail_temp;
	
	if(head == NULL){
		printf("\nList is empty.\n");
	}
	else{
		// tail_temp as temp node of tail, new tail becomes temp's (tail's) left node, temp's (tail's) right address to NULL, free temp's memory
		tail_temp = tail;
		tail = tail_temp->left;
		tail->right = NULL;
		free(tail_temp);
	}
	
	menu();
}


int deleteSpecific(){
	// todelete is the node to be deleted
	struct node *todelete;
	int pos;
	
	printf("\nDelete node at position: ");
	scanf("%d", &pos);
	
	if(head == NULL){
		printf("\nList is empty.\n");
	}
	else{
		// todelete as traversal
		todelete = head;
		
		for(int i = 0; i < pos; i++){
			// if todelete's right address is NULL (if its is beyond tail), return 0
			if(todelete->right == NULL){
				printf("\nPosition out of bounds.\n");
				menu();
				return 0;
			}
			
			// todelete to todelete's right (next) address (counter/traversal)
			todelete = todelete->right;
		}
	}
	
	if(todelete == NULL){
		printf("\nDeletion is invalid.\n");
	}
	else{
		if(todelete == head){  // same function as deleteBeginning
			head = todelete->right;
			todelete->right->left = NULL;
			free(todelete);
			menu();
			return 0;
		}
		if(todelete == tail){  // same function as deleteEnd
			tail = todelete->left;
			todelete->left->right = NULL;
			free(todelete);
			menu();
			return 0;
		}

		// if todelete is in between head & tail 
		todelete->left->right = todelete->right;  // left node's right address of todelete sets to todelete's right node
		todelete->right->left = todelete->left;  // right node's left address of todelete sets to todeletes's left node
		free(todelete);
		menu();
		return 0;	
	}
}


struct node *findByPos(){
	struct node *t;
	int pos;
	
	printf("\nEnter position to find: ");
	scanf("%d", &pos);
	
	if(head == NULL){
		printf("\nList is empty.\n");
	}
	else{
		// same as other traversals
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
		printf("\nList is empty.\n");
	}
	else{
		// same as other traversals
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


int display(){
	struct node *t = head;
	
	if(head == NULL){
		printf("\nList is empty.\n");
		return 0;
	}
	
	printf("\nHead: %d, Tail: %d\n\n", head->value, tail->value);
	
	printf("Left Node\t\tValue(Node)\t\tRight Node\n");
	
	while(t != NULL){
		printf("%p\t%d(%p)\t%p\n", t->left, t->value, t, t->right);
		t = t->right;
	}
	
	printf("\n=================================================================================\n");
}


int menu(){
	struct node *foundPos, *foundVal;
	int choice;
	
	display();
	
	printf("\n1 - Insert at the Beginning \n2 - Insert at the End \n3 - Insert Specific\n");
	printf("\n4 - Delete Beginning \n5 - Delete End \n6 - Delete Specific\n");
	printf("\n7 - Find by Position \n8 - Find by Value \n9 - Display Values\n\n>");
	
	scanf("%d", &choice);
	
	switch(choice){
		case 1: insertBeginning();
			break;
		case 2: insertEnd();
			break;
		case 3: insertSpecific();
			break;
		case 4: deleteBeginning();
			break;
		case 5: deleteEnd();
			break;
		case 6: deleteSpecific();
			break;
		case 7: 
			foundPos = findByPos();
	
			if(foundPos != 0)
				printf("\n\nFound:%p\t%d(%p)\t%p\n", foundPos->left, foundPos->value, foundPos, foundPos->right);
			else
				printf("\nNot found.\n");
				
			menu();
			break;
		case 8: 
			foundVal = findByValue();
			
			if(foundVal != 0)
				printf("\n\nFound:%p\t%d(%p)\t%p\n", foundVal->left, foundVal->value, foundVal, foundVal->right);
			else
				printf("\nNot found.\n");
				
			menu();
			break;
		case 9: display();
			menu();
			break;
		default:
			return 0;
	}
}


int main(){
	struct node *current, *temp;
	int num, choice;
	
	printf("Enter number of values: ");
	scanf("%d", &num);
	
	for(int i=0; i<num; i++){
		current = createNode();
		
		// assign first all newnode's left & right addresses to NULL 
		current->left = NULL;
		current->right = NULL;
		
		if(head == NULL){
			head = current;
			tail = current;
		}
		else{
			// temp as traversal
			temp = head;
			
			while(temp->right != NULL)  // traverses to the last node (better to illustrate)
				temp = temp->right;
			
			// temp's right address to newnode, newnode's left address to temp, newnode is the new tail
			temp->right = current;
			current->left = temp;
			tail = current;
		}
	}
	
	menu();
}
