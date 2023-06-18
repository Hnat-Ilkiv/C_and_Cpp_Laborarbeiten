#include <stdio.h>

int in_asc_order(int arr[], int size) {
	for (int i = 0; i < size-1; i++) {
		if (arr[i] > arr[i+1]) return 0;
	}
	return 1;
}

void printArray(int arr[], int size) 
{ 
	printf("in_asc_order({ ");
	for (int i=0; i < size; i++) {
		printf("%d ", arr[i]);
		}
	switch(in_asc_order(arr, size)) {
		case 0: printf("}, %d); //false\n", size); 
			break;
		case 1: printf("}, %d); //treu\n", size); 
			break;
		default:  printf("}, %d); //NaN\n", size);
			break;
		}
} 

void main(void){
	int size;
	do {
	printf("int size = ");
	scanf("%d", &size);
	} while(size <= 0);

	int arr[size];
	for (int i = 0; i < size; i++)
	{
		printf("arr[%d] = ", i);
		scanf("%d", &arr[i]);
	}

	printArray(arr, size);
}
