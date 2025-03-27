#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1;
int rear = 1;

void insert(int val);
int delete();
int peek();

int main(void) {
    printf("Enter the 10 numbers\n");
	for (int i = 1; i <= 10; i++) {
		int temp;
		printf("Enter Number %d : ", i);
		scanf("%d", &temp);
		insert(temp);
	}
	int key;
	int t = 0;
	printf("\nEnter the Number to search: ");
	scanf("%d", &key);
	for (int i = 0; i < 10; i++) {
		if(key == queue[i]) {
			printf("Value found at index of the queue %d.\n", i);
			t = 1;
		} 
	}
	if (t == 0) 
	printf("Value not found\n");
	for (int i = 1; i <= 10; i++) {
		delete();
	}	
	return 0;	
}

void insert(int val) {
    if (rear >= MAX -1) {
        printf("Queue OVERFLOW!\n");
        return;
    } else if (front == -1){
        front = 0;
        rear = 0;
    } else  {
        rear++;
    }
    queue[rear] = val;
    printf("Inserted: %d\n", val);
}

int delete() { 
    if (front == -1) {  
        printf("Queue EMPTY!\n");
        return -1;
    }
    int val = queue[front];  
    printf("Deleted: %d\n", val);
    if (front == rear) {  
        printf("Queue RESET\n");
        front = -1;
        rear = -1;
    } else {
        (front)++;  
    }
    return val;
}

int peek () {
	if (front == -1){
		printf("Empty Queue\n");
		return -1;
	} else if (front <= MAX - 1) {
		return queue[front];
	} 
    return -1;
}