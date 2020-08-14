#include <stdio.h>
#define SIZE 4

int top = -1;
int stack[SIZE];

void push(){
	int value;
	
	if(top == SIZE-1){
		printf("\nStack will overflow.\n");
	}
	else{
		printf("\nEnter value: ");
		scanf("%d", &value);
		
		top = top + 1;
		stack[top] = value;	
	}
	
	printf("\n======================================\n");
}

void pop(){
	if(top == -1){
		printf("\nStack will underflow.\n");
	}
	else{
		printf("\nPopped value is %d.\n", stack[top]);
		top = top - 1;
	}
	
	printf("\n======================================\n");
}

void display(){
	printf("\nStack:\n");
	
	if(top == -1){
		printf("\n  Stack is empty.\n");
	}
	else{
		for(int i = top; i >= 0; i--){
			if(i == top){
				printf("  %d (Top)\n", stack[i]);
				continue;
			}
				
			printf("  %d\n", stack[i]);
		}	
	}
	
	printf("\n======================================\n");
}

int main(){
	int choice;
	
	printf("\n1 - Push\n2 - Pop\n3 - Display\n\n>");
	scanf("%d", &choice);
	
	switch(choice){
		case 1: push();
			main();
			break;
		case 2: pop();
			main();
			break;
		case 3: display();
			main();
			break;
		default:
			return 0;
	}
}
