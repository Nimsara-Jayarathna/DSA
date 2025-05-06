#include<stdio.h>
#define SIZE 10  //size of the array
#define MAXVAL 99999999

void mergesort(int array[], int first_index, int last_index);  //function declaration
void merge(int array[], int first_index, int middle_index, int last_index); //function declaration

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
    mergesort(arr, 0,SIZE - 1);    //sorting
    printf("\nArray after sorting: ");    //display after sorting
    for (int i = 0; i < SIZE; i++) {
        printf("%d ",arr[i]);
    }
}

void mergesort(int array[], int first_index, int last_index) {
    if (first_index < last_index) { //check if the first index is less than the last index
        int middle_index = (first_index + last_index) / 2;
        mergesort(array,first_index,middle_index);      //recursive call to the left 
        mergesort(array,middle_index + 1,last_index);   //recursive call to the right
        merge(array, first_index, middle_index, last_index);    //merging the two halves
    } else {
        return;
    }
}

void merge(int array[], int first_index, int middle_index, int last_index) {
    int n1 = middle_index - first_index + 1;
    int n2 = last_index - middle_index;
    int left[n1 + 1];
    int right[n2 + 1];
    for (int i = 0; i < n1;i++) {
        left[i] = array[first_index + i];   //copying the left of the array
    }
    for (int i = 0; i < n2;i++) {
        right[i] = array[middle_index + 1 + i]; //copying the right of the array
    }
    left[n1] = MAXVAL;
    right[n2] = MAXVAL;
    int i = 0, j = 0;
    for(int  k = first_index; k <= last_index; k++) {
        if (left[i] < right[j]) { 
            array[k] = left[i++];   //copying the left of the array to the main array
        } else {
            array[k] = right[j++];  //copying the right of the array to the main array
        }
    }
}

