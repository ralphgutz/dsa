#include <stdio.h>
#define SIZE 4

// initialization
int top = -1;
int stack[SIZE];

void push(int data){
	int value;
	
	if(top == SIZE-1){
		printf("\nStack will overflow.\n");
	}
	else{
		// increment first then use top as array index
		top++;
		stack[top] = data;	
	}
}

void pop(){
	if(top == -1){
		printf("\nStack will underflow.\n");
	}
	else{
		printf("\nPopped value is %d.\n", stack[top]);
		top--;  // goes down below
	}
}

void display(){
	printf("\nStack:\n");
	
	if(top == -1){
		printf("\n  Stack is empty.\n");
	}
	else{
		// decrementing for loop because printing stack is from top (new) to bottom (old)
		for(int i = top; i >= 0; i--){
			if(i == top){
				printf("  %d (Top)\n", stack[i]);
				continue;
			}
				
			printf("  %d\n", stack[i]);
		}	
	}
}

int main(){
	int choice, value;
	
	while(1){
		printf("\n======================================\n");
		printf("\n1 - Push\n2 - Pop\n3 - Display\n\n>");
		scanf("%d", &choice);
		
		switch(choice){
			case 1: 
				printf("\nEnter value: ");
				scanf("%d", &value);
				push(value);
				break;
			case 2: pop();
				break;
			case 3: display();
				break;
			default:
				return 0;
		}
	}
}
