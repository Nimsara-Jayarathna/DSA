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

