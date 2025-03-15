#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

int top = -1;
int stack_size = 20;
char stack[20];
char postfix[20];
char operators[] = "-+/*%";

void push(char stack[], char value);
void input(char input[]);
void infix_to_postfix(char st[], char formular[]);
char pop(char stack[]);
char peek(char stack[]);
bool isFull();
bool isEmpty();
int precedence(char operator);


int main(void) {
    char string[20];
    char form[20];
    input(string);
    strncpy(form, string,19);
    infix_to_postfix(stack, string);
    printf("The postfix of %s is : %s\n", form, postfix);
    return 0;
}

void push(char stack[], char value) {
    if (top < stack_size && top >= -1) {
        stack[++top] = value;
    } else {
        printf("Stack Overflow!\n");
    }
}

char pop(char stack[]) {
    if (top < stack_size && top >= 0) {
        return stack[(top)--];
    } else if(top == -1)  {
        printf("Empty Stack!\n");
        return '\0';
    } else {
        printf("Top out of bounds!\n");
        return '\0';
    }
}

char peek(char stack[]) {
    if (top < stack_size && top >= 0) {
        return stack[top];
    } else if(top == -1)  {
        return '\0';
    } else {
        return '\0';
    }
}

bool isEmpty() {
    return (top == -1);
}

bool isFull() {
    return (top >= stack_size - 1);
}

bool isOperator(char ch) {
    return (strchr(operators, ch) != NULL);
}

int precedence(char operator) {
    if ((operator == '-') || (operator == '+')) 
    {
        return 1;
    } 
    else if ((operator == '/') || (operator == '*') || (operator == '%'))
    {
        return 2;
    } else {
        return 0;
    }
}

void infix_to_postfix(char st[], char formular[]) {
    int i = 0;
    int j = 0;
    int k = 0;
    char temp;
    int index_of_operator = 0;
    while (formular[i] != '\0') {
        i++;
    }
    formular[i] = ')';
    formular[i+1] = '\0';
    push(stack, '(');
    while (formular[j] !='\0') {
        if (formular[j] == '(') 
        {
            push(stack, formular[j]);
        } 
        else if (formular[j] == ')') 
        {
            while (peek(stack) != '(') {
                postfix[k++] = pop(stack);
            }
            pop(stack);
        }
        else if ((isalpha(formular[j])) || (isdigit(formular[j])))
        {
            postfix[k++] = formular[j];
        }
        else if (isOperator(formular[j])) 
        {
            while (!isEmpty()) {
                if (peek(stack) != '(' && precedence(formular[j]) <= precedence(peek(stack))) {
                    postfix[k++] = pop(stack);
                } else {
                    break;
                }
            }
            push(stack, formular[j]);
        }
        j++;
    }
}

void input(char input[]) {
    printf("Enter the formula: ");
    fgets(input, stack_size, stdin);
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }
}
