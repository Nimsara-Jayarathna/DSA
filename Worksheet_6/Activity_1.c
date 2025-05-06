#include<stdio.h>
#define SIZE 10

void selectionSort(int array[], int size);  //function declaration

int main() {
    int arr[SIZE];
    for (int i = 1; i <= SIZE; i++) {   //obtaining input from STDIO
        printf("Enter number %d: ",i);
        scanf("%d",&arr[i-1]);
    }
    printf("Array before sorting: ");   //display before sorting
    for (int i = 0; i < SIZE; i++) {
        printf("%d ",arr[i]);
    }
    selectionSort(arr,SIZE);    //sorting
    printf("\nArray after sorting: ");    //display after sorting
    for (int i = 0; i < SIZE; i++) {
        printf("%d ",arr[i]);
    }
}

void selectionSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int smallest = i;
        for (int j = i + 1; j < size; j++) {
            if (array[j]< array[smallest]) {
                smallest = j;   //finding the lowest
            }
        }
        int temp = array[i];    //exachanging
        array[i] = array[smallest];
        array[smallest] = temp;
    }
}