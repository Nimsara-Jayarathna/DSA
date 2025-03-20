#include <stdio.h>
#define MAX 3

int front = -1;
int rear = -1;
int queue[MAX];

void insert(int val);
int delete_element(void);
int peek (void);

int main(void) {
    int choice, value, deletedValue;
    do {
        printf("\n\nCircular Queue Menu:\n");
        printf("\t1. Insert\n");
        printf("\t2. Delete\n");
        printf("\t3. Peek\n");
        printf("\t4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                deletedValue = delete_element();
                if (deletedValue != -1) {
                    printf("\tDeleted element: %d\n", deletedValue);
                }
                break;
            case 3:
                value = peek();
                if (value != -1) {
                    printf("\tFront element: %d\n", value);
                }
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    return 0;
}

void insert(int val) {
    if ((rear + 1) % MAX == front){ 
        printf("\tQueue is FULL!\n");
        return;
    } 
    if ((front == -1) && (rear == -1)) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }
    queue[rear] = val;
    printf("\t\"%d\" inserted to rear[%d]", val, rear);
}

int delete_element(void) {
    int val;
    if ((front == -1) && (rear == -1)) {
        printf("\tEmpty QUEUE!\n");
        return -1;
    } 
    val = queue[front];
    if (front == rear) {
        printf("\tQueue RESET!\n");
        front = rear = -1;
    } else {
        if (front == MAX -1) {
            front = 0;
        } else {
            front++;
        }
    }
    return val;
}

int peek (void) {
    if ((front == -1) && (rear == -1)) {  
        printf("\tQueue EMPTY!\n");
        return -1;
    }
    return queue[front];
}