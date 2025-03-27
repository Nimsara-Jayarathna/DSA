#include <stdio.h>
#include <stdlib.h>

struct queue {
    int data;
    struct queue *next;
};

struct queue *front = NULL;
struct queue *rear = NULL;

void insert(int val);
int delete_element();
int peek(); 

int main() {
    int num;
	int key;
	int t = 0;
    int i = 1;
    printf("Enter the number of elements you wish to enter: ");
    scanf("%d", &num);
	for (int i = 1; i <= num; i++) {
		int temp;
		printf("Enter Number %d : ", i);
		scanf("%d", &temp);
		insert(temp);
	}
	printf("\nEnter the Number to search: ");
	scanf("%d", &key);
    struct queue * temp_ptr = front;
	while(temp_ptr != NULL) {
        if (temp_ptr->data == key){
            printf("Value found in the queue.\n");
            printf("\tIndex of the queue %d.\n", i);
            printf("\tPointer of the data is %p.\n", temp_ptr);
            t =1;
        }
        temp_ptr = temp_ptr->next;
        i++;
	}
	if (t == 0) {
        printf("\tValue not found\n");
    }
	while (delete_element() != -1) {
	}	
	return 0;	
}

void insert(int val) {
    struct queue *new_node = (struct queue*)malloc(sizeof(struct queue));
    new_node->data = val;
    new_node->next = NULL;
    if (front == NULL) {
        front = rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
    printf("Inserted : %d\n", rear->data);
}

int delete_element(){
    struct queue *current_node = (struct queue*)malloc(sizeof(struct queue));
    if (front == NULL) {
        printf("Empty QUEUE!\n");
        return -1;
    } else {
        current_node = front;
        int temp_data = front->data;
        printf("Deleting..... : %d\n", temp_data);
        front = front->next;
        free(current_node);
        return temp_data;
    }
}

int peek(){
    if (front == NULL) {
        printf("Empty QUEUE!\n");
        return -1;
    } else {
        return front->data;
    }
}

