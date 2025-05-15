#include<stdio.h>
#define MAX 10

int searching(int array[], int key);

int main(void) {
	int arr[MAX];
	int key;
	for (int i = 0; i < MAX; i++) {
		printf("Enter the number %d: ", i + 1);
		scanf("%d", &arr[i]);
	}
	printf("Enter the key: ");
	scanf("%d", &key);
	int index = searching(arr,key);
	if (index == -1) {
		printf("Key was not found!\n");
	} else {
		printf("Key was found at index %d.\n", index);
	}
	return 0;
}

int searching(int arr[], int key) {
	for (int i = 0; i < MAX; i++) {
		if (arr[i] == key) {
			return i;
		}
	}
	return -1;
} 	
