#include<stdio.h>
#define SIZE 10

void bubbleSort(int array[], int size);  //function declaration

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
    bubbleSort(arr,SIZE);    //sorting
    printf("\nArray after sorting: ");    //display after sorting
    for (int i = 0; i < SIZE; i++) {
        printf("%d ",arr[i]);
    }
}

void bubbleSort(int array[], int size) {
    int FLAG;
    for (int pass = 0; pass < size - 1; pass++) {
        FLAG = 0;
        for (int i = 0; i < size - pass - 1; i++) {
            if (array[i] > array[i + 1]) {
                int temp = array[i];    //swapping
                array[i] = array[i + 1];
                array[i + 1] = temp;
                FLAG = 1;
            }
        } 
        if(FLAG == 0) {
            printf("\nArray is already sorted after pass %d.", pass + 1);
            return;
        }
    }
}