/*
Program Name: Binary Search Implementation
Program Description: Takes The inputs : {arr, arr size} initializes an Array and Uses Binary Search Algorithm to find desired number
		     From Array IF it exists
Program Creation Time: Aug 6th 16:00
Program Creator: Ashwath Raj | AP25110010712
*/

#include<stdio.h>

void swap(int* a, int* b);
void sortAnArray(int arr[], int n);
int binarySearch(int arr[], int n, int key);

void main(void) {
	printf("====================================== \n");
	printf("Binary SEARCHING AN ELEMENT FROM UNSORTED ARRAY \n");
	printf("====================================== \n");


	int n = 0;
	printf("Enter Size of array to be Created: ");
	scanf("%d", &n);

	int arr[n];
	for (int i = 0; i < n; i++) {
	  printf("enter Element %d in array: ", i);
	  scanf("%d", &arr[i]);
	}

	int key = -1;
	printf("-------------------------------------- \n");
	printf("Enter Element to be searched From array \n A validation statement will be displayed IF element Exists \n \n");
	printf("Enter Element: ");
	getchar();
	scanf("%d", &key);

        sortAnArray(arr, n);
	int found =  binarySearch(arr, n, key);
	if (found == -1) {
		printf("No such element Exits in array!! \n");
	}
	else {
		printf("The element %d exits in given array \n", key);
	}
}

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void sortAnArray(int arr[], int n) {
  for(int i = 0; i < n; i++) {
    for(int j = 1; j < n; j++) {
      if(arr[j] < arr[j - 1])
        swap(&arr[j], &arr[j - 1]);
    }
  }
}

int binarySearch(int arr[], int n, int key) {
  int left = 0,right = n - 1;      
  
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == key)
      return mid;
    else if(arr[mid] > key)
      right = mid - 1;
    else if (arr[mid] < key)
      left  = mid + 1;  
  }  
  return -1;
}
