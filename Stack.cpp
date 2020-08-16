#include <stdio.h>
#include <malloc.h>
//#define SIZE 5

struct node{
	int value;
	struct node *link;
};

struct node *top = NULL;
int SIZE, count = 0;

struct node *createNode(){
	struct node *newnode;
	newnode = (struct node*) malloc(sizeof(struct node));
	
	return(newnode);
}

void push(int data){
	struct node *newnode;
	newnode = createNode();
	
	newnode->value = data;
	newnode->link = NULL;
	
	if(count == SIZE){
		printf("\nStack overflow.\n");
	}
	else{
		if(top != NULL){  // if newnode isn't the first node
			newnode->link = top;
		}
		
		top = newnode;  // set newnode as new top, count++
		count++;
	}
}

void pop(){  // pop the top
	struct node *temp;
	
	if(top == NULL){
		printf("\nStack underflow.\n");
	}
	else{
		printf("\nPopped value %d (%p).\n", top->value, top);
		temp = top;  // temp as temporary top
		top = top->link;  // set top's below node to new top
		free(temp);
		count--;
	}
}

void display(){
	struct node *temp;
	printf("\nSTACK:\n");
	
	if(top == NULL){
		printf("\nStack is empty.\n");
	}
	else{
		printf("\n Value Node\t\tLinked Node\n");
	
		temp = top;  // temp as traversal
		while(temp != NULL){
			
			if(temp == top){
				printf(" %d (%p)\t(%p) - Top\n", temp->value, temp, temp->link);
				temp = temp->link;
				continue;
			}
			
			printf(" %d (%p)\t(%p)\n", temp->value, temp, temp->link);
			temp = temp->link;  // counter
		}
	}
}

int main(){
	int choice, val;
	
	printf("\nSize of stack: ");
	scanf("%d", &SIZE);
	
	while(1){
		printf("\n=========================\n");
		printf("\n1 - Push\n2 - Pop\n3 - Display\n\n>");
		scanf("%d", &choice);
		
		switch(choice){
			case 1: 
				printf("\nEnter value: ");
				scanf("%d", &val);
				push(val);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			default:
				return 0;
		}
	}
}
