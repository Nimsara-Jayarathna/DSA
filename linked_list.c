#include <stdio.h>
#include <stdlib.h>

struct linked_list {
    int data;
    struct linked_list *next;
};

struct linked_list *head = NULL;

void insert_beginning(int val);
void insert_ending(int val);
void insert_before_node(int key, int val);
void insert_after_node(int key, int val);

int delete_first_node();
int delete_last_node();
int delete_after_node(int key);

void traverse();

int main(){
    insert_beginning(10);
    insert_beginning(5);
    insert_beginning(0);
    insert_after_node(10,20);
    insert_before_node(20,15);
    insert_ending(25);
    traverse();
    delete_first_node();
    traverse();
    delete_last_node();
    traverse();
    delete_after_node(10);
    traverse();
}

void insert_beginning(int val){
    struct linked_list *new_node = (struct linked_list*)malloc(sizeof(struct linked_list));
    new_node->data = val;
    new_node->next = head;
    head = new_node;
}

void insert_ending(int val){
    struct linked_list *new_node = (struct linked_list*)malloc(sizeof(struct linked_list));
    new_node->data = val;
    new_node->next = NULL;
    if (head == NULL) {
        head = new_node;
    } else {
        struct linked_list *temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void insert_before_node(int key, int val){
    if (head == NULL) {
        printf("Empty Linked List");
        return;
    }
    struct linked_list *temp = head;
    struct linked_list *previous = NULL;
    while ((temp != NULL) && (temp->data != key)) {
        previous = temp;
        temp = temp->next;
    }
    if (temp == NULL){
        printf("Key was't found!\n");
        return;
    }
    struct linked_list *new_node = (struct linked_list*)malloc(sizeof(struct linked_list));
    new_node->data = val;
    new_node->next = temp;
    if (previous == NULL){
        head = new_node;
    } else {
        previous->next = new_node;
    }
    printf("Key Found! Inserted %d before %d\n", val, key);
}

void insert_after_node(int key, int val){
    if (head == NULL) {
        printf("Empty Linked List");
        return;
    }
    struct linked_list *temp = head;
    while ((temp != NULL) && (temp->data != key)) {
        temp = temp->next;
    }
    if (temp == NULL){
        printf("Key was't found!\n");
        return;
    }
    struct linked_list *new_node = (struct linked_list*)malloc(sizeof(struct linked_list));
    new_node->data = val;
    new_node->next = temp->next;
    temp->next = new_node;
    printf("Key Found! Inserted %d after %d\n", val, key);
}

int delete_first_node(){
    if (head == NULL) {
        printf("Empty Linked List\n");
        return -1;
    }
    struct linked_list *temp = head;
    int val = head->data;
    head = head->next;
    free(temp);
    return val;
}

int delete_last_node() {
    if (head == NULL) {
        printf("Empty Linked List\n");
        return -1;
    }
    struct linked_list *temp = head;
    struct linked_list *previous = NULL;
    while(temp->next != NULL){
        previous = temp;
        temp = temp->next;
    }
    int val = temp->data;
    if (previous == NULL) {
        head = NULL;
    } else {
        previous->next = NULL;
    }
    free(temp);
    return val;
}

int delete_after_node(int key) {
    int val = -1;
    if (head == NULL) {
        printf("Empty Linked List\n");
        return val;
    }
    struct linked_list *temp = head;
    struct linked_list *next_node = NULL;
    while ((temp != NULL) && (temp->data != key)) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key was't found!\n");
    } else if (temp->next == NULL) {
        printf("Key was found at the last node!\n");
    } else {
        next_node = temp->next;
        val = next_node->data;
        temp->next = temp->next->next;
        free(next_node);
    }
    return val;
}

void traverse() {
    if (head == NULL) {
        printf("Empty Linked List\n");
        return;
    }
    struct linked_list *temp = head;
    int i = 1;
    while(temp->next != NULL){
        printf("Value of the %d linked list is %d.\n", i++, temp->data);
        temp = temp->next;
    }
    printf("Value of the %d linked list is %d.\n\n", i, temp->data);
}
