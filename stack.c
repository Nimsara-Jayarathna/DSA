#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


void push(int *top1, int stack[], int value, int stack_size);
int pop(int *top1, int stack[], int stack_size);
int peek(int top1, int stack[], int stack_size);
bool isFull(int top1, int stack_size);
bool isEmpty(int top1);


int main(void) {
    int stack_size = 10;
    int top = -1;
    int stack[stack_size];
    push(&top,stack,30, stack_size);
    push(&top,stack,80, stack_size);
    push(&top,stack,100, stack_size);
    push(&top,stack,25, stack_size);
    printf("\nDeleting all items from the stack...\n\n");
    while (!isEmpty(top)) {
        printf("Popped: %d\n", pop(&top, stack,stack_size ));
    }
    return 0;
}

void push(int *top1, int stack[], int value, int stack_size) {
    if (*top1 < stack_size && *top1 >= -1) {
        stack[++*top1] = value;
        printf("Pushed: %d\n", value);
    } else {
        printf("Stack Overflow!\n");
    }
}

int pop(int *top1, int stack[], int stack_size) {
    if (*top1 < stack_size && *top1 >= 0) {
        return stack[(*top1)--];
    } else if(*top1 == -1)  {
        printf("Empty Stack!pop\n");
        return -99;
    } else {
        printf("Top out of bounds!\n");
        return -99;
    }
}

int peek(int top1, int stack[], int stack_size) {
    if (top1 < stack_size && top1 >= 0) {
        return stack[top1];
    } else if(top1 == -1)  {
        printf("Empty Stack!peek\n");
        return -99;
    } else {
        printf("Top out of bounds!\n");
        return -99;
    }
}

bool isEmpty(int top1) {
    return (top1 == -1);
}

bool isFull(int top1, int stack_size) {
    return (top1 == stack_size - 1);
}