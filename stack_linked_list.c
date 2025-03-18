#include <stdio.h>
#include <stdlib.h>

struct stack {
    int data;
    struct stack *next;
};

struct stack* top = NULL;


struct stack *pop(struct stack* top);
int peek(struct stack *top);
struct stack *push(struct stack* top, int val);
void display(struct stack* top) ;

int main() {
    for (int i = 0; i < 10; i++) {
        printf("Pushing %d...\n",i);
        top = push(top,i);
    }
    display(top);
    for (int i = 0; i < 10; i++) {
        display(top);
        top = pop(top);
    }
    peek(top);
    return 0;
}


struct stack *push(struct stack* top, int val) {
    struct stack *new_node;
    new_node = (struct stack*)malloc(sizeof(struct stack));
    new_node->data = val;
    if (top == NULL) {
        new_node->next = NULL;
    } else {
        new_node->next = top;
    }
    top = new_node;
    return top;
}

int peek(struct stack *top) {
    if (top == NULL) {
        return -1;
    } else {
        return top->data;
    }
}

struct stack *pop(struct stack* top) {
    struct stack *next_node = top;
    if (top == NULL) {
        printf("Empty stack!\n");
    } else {
        printf("Popping: %d\n", top->data);
        top = top->next;
        free(next_node);
    }
    return top;
}

void display(struct stack* top) {
    if (top == NULL) {
        printf("Empty stack!\n");
    } else {
        while(top != NULL) {
            printf("%d\n", top->data);
            top = top->next;
        }
    }
}