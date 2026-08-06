/*
Program Name: LInear Search Implememtation
Program Description: Takes THe inputs : {arr, arr size} intializes an Array and Uses LInear Seach Algorithm to find desired number
		     From Array IF it exists
Proram CReation Time: Aug 6th 15:40
Program Creater: Ashwath Raj | AP25110010712
*/

#include<stdio.h>

int linearSearch(int arr[], int n, int key);

void main(void) {
	printf("====================================== \n");
	printf("LINEAR SEARCHING AN ELEMENT FROM UNSORTED ARRAY \n");
	printf("====================================== \n");


	int n = 0;
	printf("Enter Size of array to be Created: ");
	scanf("%d", &n);

	int arr[n];
	for (int i = 0; i < n; i++) {
		printf("enter Elemnt %d in array: ", i);
		scanf("%d", &arr[i]);
	}

	int key = -1;
	printf("-------------------------------------- \n");
	printf("Enter Element to be searched From array \n The idx postion of that elment will be returned IF FOUND \n \n");
	printf("Enter Element: ");
	getchar();
	scanf("%d", &key);


	int idx =  linearSearch(arr, n, key);
	if (idx == -1) {
		printf("No such elment Exits in array!! \n");
	}
	else {
		printf("The elment %d exits in %d index of given array \n", key, idx);
	}
}

int linearSearch(int arr[],int n,  int key) {
	for(int i = 0; i < n; i++) {
		if(arr[i] == key) {
			return i;
		}
	}

	return -1;
}
