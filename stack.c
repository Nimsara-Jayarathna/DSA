#include <stdio.h>
#include <stdlib.h>


void push(int *top1, int stack[], int value, int stack_size);
int pop(int *top1, int stack[], int stack_size);
int peek(int top1, int stack[], int stack_size);


int main(void) {
    int stack_size;
    int top = -1;
    printf("Enter the stack size: ");
    scanf("%d", &stack_size);
    int arr[stack_size];
    
    for (int i = 0; i < stack_size; i++) {
        int temp;
        printf("Enter value %d: ", i+1);
        scanf("%d", &temp);
        push(&top, arr, temp,stack_size);
    }
    printf("Peek: %d\n", peek(top, arr,stack_size));
    for (int i = 0; i < stack_size; i++) {
        int temp;
        temp = pop(&top, arr,stack_size);
        printf("Pop %d: %d\n", i+1, temp);
        printf("Peeking while popping: %d\n", peek(top, arr,stack_size));
    }
    printf("Peekl: %d\n", peek(top, arr,stack_size));
    return 0;
}

void push(int *top1, int stack[], int value, int stack_size) {
    if (*top1 < stack_size && *top1 >= -1) {
        stack[++*top1] = value;
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