#include <stdio.h>

int insertionSort(int arr[], int n){
	int temp;
	int j;
	
	printf("<-- sorted sublist | unsorted sublist -->\n\n");
	
	for(int i = 1; i < n; i++){
		temp = arr[i];
		j = i-1;
		
		printf("temp: %d\n%d - ", temp, i);
		for(int k = 0; k < n; k++){
			if(k == i){
				printf("| ");
			}
			printf("%d ", arr[k]);
		}
		printf("\n");
		
		
		while(j >= 0 && arr[j] > temp){
			arr[j+1] = arr[j];
			j--;
			
//			for(int i = 0; i < n; i++)
//				printf(" %d", arr[i]);
//			printf("\n");
		}
		
		arr[j+1] = temp;
	
		printf("\n");
	}
	
	for(int i = 0; i < n; i++)
		printf(" %d", arr[i]);
}

int main(){
	int arr[5] = {16, 14, 5, 6, 8};
	insertionSort(arr, 5);
}
