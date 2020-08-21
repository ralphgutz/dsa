#include <stdio.h>

int insertionSort(int arr[], int n){
	int temp;  // storing num to be inserted
	int j;  // to traverse in sorted sublist
	
	printf("<-- sorted sublist | unsorted sublist -->\n\n");
	
	for(int i = 1; i < n; i++){  // arr[0] is automatically in sorted sublist (yet its pos can be changed later), so i=1 to traverse
		temp = arr[i];
		j = i-1;
		
		// displaying only
		printf("temp: %d\nPASS %d - ", temp, i);
		for(int k = 0; k < n; k++){
			if(k == i)
				printf("| ");
			
			printf("%d ", arr[k]);
		}
		printf("\n");
		
		
		while(j >= 0 && arr[j] > temp){  // loop for traversing sorted sublist
			arr[j+1] = arr[j];
			j--;
		}
		
		arr[j+1] = temp;  // insertion
	
		printf("\n");
	}
	
	// displaying only
	for(int i = 0; i < n; i++)
		printf(" %d", arr[i]);
}

int main(){
	int arr[5] = {16, 14, 5, 6, 8};
	insertionSort(arr, 5);
}

/**
	https://youtu.be/yCxV0kBpA6M?list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU
	Maximum passes: n-1
	Sorting starts with first value in unsorted sublist
**/
