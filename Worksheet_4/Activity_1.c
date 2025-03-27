#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1;
int rear = 1;

void insert(int val);
int delete();
int peek();



int main(void) {
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
}