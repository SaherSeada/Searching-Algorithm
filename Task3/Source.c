#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int * insertionSort(int array[], int size) {
	int j, key;
	for (int i = 1; i < size; i++) {
		j = i - 1;
		key = array[i];
		while (j >= 0 && key < array[j]) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = key;
	}
	return array;
}

int binarySearch(int* array, int size, int elementToSearch) {
	int start = 0, mid = 0, end = size - 1;
	while (start <= end) {
		mid = floor((start + end) / 2);
		if (array[mid] == elementToSearch) {
			return mid;
		}
		else if (array[mid] < elementToSearch) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return -1;
}

int main() {
	int array[50];
	int size, element, elementToSearch;
	printf("Please enter the number of elements in the array (No more than 50)\n");
	scanf_s("%d", &size);
	for (int i = 0; i < size; i++) {
		printf("\nPlease enter element number %d\n", i+1);
		scanf_s("%d", &element);
		array[i] = element;
	}
	printf("\nPlease enter the number to search for in the array:\n");
	scanf_s("%d", &elementToSearch);
	int* sortedArray = insertionSort(array, size);
	printf("\nSorted Array: \n");
	for (int i = 0; i < size; i++) {
		printf("%d ", sortedArray[i]);
	}
	int index = binarySearch(sortedArray, size, elementToSearch);
	if (index == -1) {
		printf("\nThe element doesn't exist in the array.\n\n");
	}
	else {
		printf("\nThe element is at index number %d in the sorted array\n\n", index);
	}
}