#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int top = -1;
int stack_size = 20;
char stack[20];

void push(char stack[], char value);
void parenthesis(char st[], char formular[]);
char pop(char stack[]);
char peek(char stack[]);
bool isFull();
bool isEmpty();


int main(void) {
    char string[20];
    printf("Enter the formular : ");
    scanf("%s", string);
    parenthesis(stack, string);
    return 0;
}

void push(char stack[], char value) {
    if (top < stack_size && top >= -1) {
        stack[++top] = value;
        printf("Pushed: '%c'\n", value);
    } else {
        printf("Stack Overflow!\n");
    }
}

char pop(char stack[]) {
    if (top < stack_size && top >= 0) {
        printf("popped\n");
        return stack[(top)--];
    } else if(top == -1)  {
        printf("Empty Stack!\n");
        return 1;
    } else {
        printf("Top out of bounds!\n");
        return 1;
    }
}

char peek(char stack[]) {
    if (top < stack_size && top >= 0) {
        return stack[top];
    } else if(top == -1)  {
        printf("Empty Stack!peek\n");
        return 1;
    } else {
        printf("Top out of bounds!\n");
        return 1;
    }
}

bool isEmpty() {
    return (top == -1);
}

bool isFull() {
    return (top >= stack_size - 1);
}

void parenthesis(char st[], char formular[]) {
    int test = 0;
    int i = 0;
    while(1) {
        if (!(formular[i] == '\0')) {
            if (formular[i] == '(') {
                push(st, '(');
            }
            if (formular[i] == ')') {
                if ('(' != pop(st)) {
                    test = 1;
                } 
            }
            if (formular[i] == '{') {
                push(st, '{');
            }
            if (formular[i] == '}') {
                if ('{' != pop(st)) {
                    test = 1;
                } 
            }
            if (formular[i] == '[') {
                push(st, '[');
            } 
            if (formular[i] == ']') {
                if ('[' != pop(st)) {
                    test = 1;
                } 
            }
        } else {
            break;
        }
        i++;
    }
    if ((isEmpty()) && (test == 0)) {
        printf("Expression is with balanced paranthesis.\n");
    } else {
        printf("It is not with balanced parenthesis.\n");
    }
}