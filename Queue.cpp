#include <stdio.h>
#include <malloc.h>

struct node{
	int value;
	struct node *link;
};

// front where nodes dequeue, rear where nodes enqueue
struct node *front, *rear = NULL;

struct node *createNode(){
	struct node *newnode = (struct node*) malloc(sizeof(struct node));
	
	newnode->link = NULL;
	
	return(newnode);
}

void enQueue(int data){
	struct node *newnode;
	
	newnode = createNode();
	newnode->value = data;
	
	// for first enqueue, assign newnode as front & rear
	if(front == NULL && rear == NULL){
		front = rear = newnode;
	}
	// rear's next node to newnode, newnode as new rear
	else{
		rear->link = newnode;
		rear = newnode;
	}
}

void deQueue(){
	if(front == NULL && rear == NULL){
		printf("\nQueue is empty.\n");
	}
	else{
		printf("\nDequeued %d (%p)\n", front->value, front);
		
		if(front == rear){
			front = rear = NULL;  // if dequeue node is the last node, assign all to NULL
		}
		else{
			front = front->link;  // front's next node will be the new front (dequeue nth position)
		}
	}
}

void display(){
	// temp as traversal
	struct node *temp = front;
	
	if(front == NULL && rear == NULL){
		printf("\nQueue is empty.\n");
	}
	else{
		printf("\nValue  Node\t\tNext Node");
		while(temp != NULL){
			if(temp == rear && temp == front){
				printf("\n%d  %p\t%p - Front/Rear", temp->value, temp, temp->link);
			}
			else if(temp == front){
				printf("\n%d  %p\t%p - Front", temp->value, temp, temp->link);
			}
			else if(temp == rear){
				printf("\n%d  %p\t%p - Rear", temp->value, temp, temp->link);
			}
			else{
				printf("\n%d  %p\t%p", temp->value, temp, temp->link);
			}
			
			temp = temp->link;  // counter
		}	
	}
}

int main(){
	int choice, val;
	
	while(1){
		printf("\n=================================\n");
		printf("\n1 - Enqueue\n2 - Dequeue\n3 - Display\n\n>");
		scanf("%d", &choice);
		
		switch(choice){
			case 1:
				printf("\nEnter value: ");
				scanf("%d", &val);
				enQueue(val);
				break;
			case 2:
				deQueue();
				break;
			case 3:
				display();
				break;
			default:
				return 0;
		}
	}
}
