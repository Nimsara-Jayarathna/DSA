#include <stdio.h>
#include <stdlib.h>

struct queue {
    int data;
    struct queue *next;
};

struct queue *front = NULL;
struct queue *rear = NULL;

void insert(int val);
void delete_element(void);
int peek(void); 

int main(void) {
    for (int i = 1; i <=10; i++) {
        insert(i);
    }
    for (int i = 1; i <=10; i++) {
        printf("Peeked %d\n" , peek());
        delete_element();
    }
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

void delete_element(void){
    struct queue *current_node = (struct queue*)malloc(sizeof(struct queue));
    if (front == NULL) {
        printf("Empty QUEUE!\n");
    } else {
        current_node = front;
        printf("The value being deleted is : %d\n", front->data);
        front = front->next;
        free(current_node);
    }
}

int peek(void){
    if (front == NULL) {
        printf("Empty QUEUE!\n");
        return -1;
    } else {
        return front->data;
    }
}

