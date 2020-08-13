// https://www.youtube.com/watch?v=4IrUAqYKjIA

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int num;
	struct node *next;
}node;

int main(void){
	// make an empty list of nodes
	node *list = NULL;
	
	// allocate a memory for first node
	node *n = (struct node*) malloc(sizeof(node));
	// make sure n will return a memory
	if(n == NULL)
		return 1;
		
	// assign a number, next address to NULL
	n->num = 1;
	n->next = NULL;
	
	// pass the current node to the list
	list = n;
	
	
	// creation of memory for another node
	n = (node*) malloc(sizeof(node));
	
	if(n == NULL)
		return 1;
		
	n->num = 3;
	n->next = NULL;
	
	// nests the list using next address
	list->next = n;
	
	
	n = (node*) malloc(sizeof(node));
	
	if(n == NULL)
		return 1;
		
	n->num = 5;
	n->next = NULL;
	list->next->next = n;
	
	// printing the list
	for(node *tmp = list; tmp != NULL; tmp = tmp->next){
		printf("%d ", tmp->num);
	}
	
	free(n);
}
