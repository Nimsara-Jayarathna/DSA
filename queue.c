#include <stdio.h>

#define MAX1 10
#define MAX2 20

void insert(int queue[], int val, int *rear, int *front, int max);
int delete(int queue[], int *rear, int *front);
int peek(int queue[], int front);

int queue1[MAX1];
int queue2[MAX2];

int front1 = -1;
int front2 = -1;
int rear1 = -1;
int rear2 = -1;

int main(void) {
}

void insert(int queue[], int val, int *rear, int *front, int max) {
    if (*rear >= max -1) {
        printf("Queue OVERFLOW!\n");
        return;
    } else if (*front == -1){
        *front = 0;
        *rear = 0;
    } else  {
        (*rear)++;
    }
    queue[*rear] = val;
    printf("Inserted: %d\n", val);
}

int delete(int queue[], int *rear, int *front) { 
    if (*front == -1) {  
        printf("Queue EMPTY!\n");
        return -1;
    }
    int val = queue[*front];  
    printf("Deleted: %d\n", val);
    if (*front == *rear) {  
        *front = -1;
        *rear = -1;
    } else {
        (*front)++;  
    }
    return val;
}

int peek(int queue[], int front) { 
    if (front == -1) {  
        printf("Queue EMPTY!\n");
        return -1;
    }
    return queue[front];
}