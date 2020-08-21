#include <stdio.h>

int swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int selectionSort(int arr[], int n){
	printf("<-- sorted sublist | unsorted sublist -->\n\n");
	
	for(int i = 0; i < n-1; i++){
		int min = i;  // container of min value in unsorted sublist
		
		for(int j = i+1; j < n; j++){  // linear search to find pos of min, i+1 to traverse unsorted sublist
			
			if(arr[j] < arr[min]){  // if arr[1] < arr[0] then set min to arr[1]'s pos
				min = j;
			}
		}
		
		if(min != i)  // if min is in its pos, no swap needed
			swap(&arr[i], &arr[min]);
	
	
		// displaying only
		printf("PASS %d (i=%d) - ", i+1, i);
		for(int k = 0; k < n; k++){
			printf(" %d", arr[k]);
			
			if(k == i)
				printf(" |");
		}
		printf("\n");
	}
	
	// displaying only
	for(int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	
}

int main(){
	int arr[5] = {5, 1, 3, 7, 2};
	
	selectionSort(arr, 5);
}

/**
	Maximum passes: n-1
	We need to perform pass by ref in swap because if not, after the swap func, old data will still be used
	No swap happens in pass #3 because 3 is in its position
	Sorting starts with no value in unsorted sublist unlike insertion sort
**/
