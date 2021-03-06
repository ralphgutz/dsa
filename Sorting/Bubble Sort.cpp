#include <stdio.h>

int bubbleSort(int arr[], int n){
	
	for(int i = 0; i < n-1; i++){
		printf("PASS %d (i=%d)\n", i+1, i);
		
		for(int j = 0; j < n-1-i; j++){  // when i increases, no. of comparison decreases (so n-1-i)
			
			if(arr[j] > arr[j+1]){  // swap positions if arr[0]=16 > arr[1]=14
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
			
			for(int i = 0; i < n; i++)
				printf(" %d", arr[i]);
			
			printf("\n");
		}
		printf("\n");
	}
}

int bubbleSortOptimized(int arr[], int n){
	
	for(int i = 0; i < n-1; i++){
		int flag = 0;  // flag to end
		
		printf("PASS %d (i=%d)\n", i+1, i);
		
		for(int j = 0; j < n-1-i; j++){
			
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				
				// displaying only
				for(int i = 0; i < n; i++)
					printf(" %d", arr[i]);
				
				printf("\n");
				
				flag = 1;  // flag=1 if swapping occured
			}
		}
		printf("\n");
		
		if(flag == 0){  // if no swapping occured, break
			printf(" No swapping needed.\n");
			break;
		}
	}
}

int main(){
	int arr[5] = {16, 14, 5, 6, 8};
	int arr2[5] = {16, 14, 5, 6, 8};
	
	printf("UNOPTIMIZED ==========\n\n");
	bubbleSort(arr, 5);
	
	printf("\nOPTIMIZED ============\n\n");
	bubbleSortOptimized(arr2, 5);
}

/**
	Maximum passes: n-1
	With optimized bubble sort, the loop with no passing needed ends
**/
