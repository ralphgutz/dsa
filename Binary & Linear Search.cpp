#include <stdio.h>

int linearSearch(int arr[], int n, int data){
	
	for(int i = 0; i < n; i++){
		if(arr[i] == data){
			return i;
		}
	}
	
	return -1;
}

int binarySearch(int arr[], int n, int data){
	int left = 0;
	int right = n-1;
	int mid;
	
	while(left <= right){  // better to illustrate (https://youtu.be/V_T5NuccwRA?list=PLdo5W4Nhv31bbKJzrsKfMpo_grxuLl8LU)
		mid = (left + right) / 2;
		
		if(data == arr[mid])
			return mid;
			
		else if(data < arr[mid])
			right = mid - 1;
			
		else
			left = mid + 1;
	}
	
	return -1;
}

int main(){
	int arr[6] = {3,1,11,9,6,7};
	int arr2[6] = {1,3,5,7,9,11};
	
	int a = linearSearch(arr, 6, 7);
	int b = binarySearch(arr2, 6, 7);
	
	printf("%d\n", a);
	printf("%d", b);
}
