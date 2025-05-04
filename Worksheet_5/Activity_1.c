#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int id;
    char name[10];
    struct node* next;
};

struct node* create_empty_linked_list();
struct node* delete_node_at_the_head(struct node* head);
struct node* insert_node_at_the_head(struct node* head, int id, char name[]);
void traverse(struct node* head);

int main() {
    struct node* head1;
    struct node* node1 = (struct node*) malloc(sizeof(struct node));
    struct node* node2 = (struct node*) malloc(sizeof(struct node));
    struct node* node3 = (struct node*) malloc(sizeof(struct node));
    head1 = node1;
    node1->id = 100;
    strcpy(node1->name,"Gihan");
    node1->next = node2;
    node2->id = 101;
    strcpy(node2->name,"Chathurika");
    node2->next = node3;
    node3->id = 102;
    strcpy(node3->name,"Kishi");
    node3->next = NULL;
    struct node* head2 = create_empty_linked_list();
    head2 = head1;
    for (int i = 1;i <= 2; i++){
        int id;
        char name[10];
        printf("Enter the ID: ");
        scanf("%d",&id);
        printf("Enter the Name: ");
        scanf("%s",name);
        head2 = insert_node_at_the_head(head2, id, name);
    }
    traverse(head2);
    while(1){
        if (head2 == NULL) {
            break;
        } else {
            printf("Node Deleting... ID: %d\n", head2->id);
            head2 = delete_node_at_the_head(head2);
        }
    }
    traverse(head2);
}

struct node* create_empty_linked_list()  {
    struct node* head_name = NULL;
    return head_name;
}

void traverse(struct node* head){
    if (head == NULL) {
        printf("Empty Linked List\n");
        return;
    } else {
        struct node* temp = head;
        while(temp != NULL){
            printf("ID: %d\tName:%s\n",temp->id, temp->name);
            temp = temp->next;
        }
        printf("Ending of the linked list\n");
    }
}

struct node* insert_node_at_the_head(struct node* head, int id, char name[])  {
    if (head == NULL) {
        printf("Empty Linked List\n");
        return NULL;
    } else {
        struct node* new_node = (struct node*) malloc(sizeof(struct node));
        new_node->id = id;
        strcpy(new_node->name,name);
        new_node->next = head;
        head = new_node;
        return head;
    }
}

struct node* delete_node_at_the_head(struct node* head)  {
    if (head == NULL) {
        printf("Empty Linked List\n");
        return NULL;
    } else {
        struct node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
}