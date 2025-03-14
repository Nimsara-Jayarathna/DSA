#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int top = -1;
int stack_size = 15;
char string1[15] = "ABCDEFGHIJ";
char a[15];

void push(char stack[], char value);
void reverse(char st[]);
char pop(char stack[]);
char peek(char stack[]);
bool isFull();
bool isEmpty();


int main(void) {
    char stack[stack_size];
    printf("String is : %s\n", string1);
    reverse(string1);
    return 0;
}

void push(char stack[], char value) {
    if (top < stack_size && top >= -1) {
        stack[++top] = value;
        printf("Pushed: %c\n", value);
    } else {
        printf("Stack Overflow!\n");
    }
}

char pop(char stack[]) {
    if (top < stack_size && top >= 0) {
        return stack[(top)--];
    } else if(top == -1)  {
        printf("Empty Stack!pop\n");
        return -99;
    } else {
        printf("Top out of bounds!\n");
        return -99;
    }
}

char peek(char stack[]) {
    if (top < stack_size && top >= 0) {
        return stack[top];
    } else if(top == -1)  {
        printf("Empty Stack!peek\n");
        return -99;
    } else {
        printf("Top out of bounds!\n");
        return -99;
    }
}

bool isEmpty() {
    return (top == -1);
}

bool isFull() {
    return (top >= stack_size - 1);
}

void reverse(char st[]) {
    int i = 0;
    while(1) {
        if((!isFull()) && (isalpha(string1[i]))) {
            push(st,string1[i]);
            i++;
        } else {
            if(isFull()) 
                printf("Stack overflow!\n");
            if(!isalpha(string1[i]))
                printf("Charcters of the string were all pushed.\n");
            break;
        }     
    }
    i = 0;
    while(1) {
        if(!isEmpty()) {
            a[i] = pop(st);
        } else {            
            printf("Empty stack!\n");
            break;
        } 
        i++;
    }
    printf("Reversed stack is %s\n", a);
}