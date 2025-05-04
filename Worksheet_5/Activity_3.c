#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *left;
    int data;
    struct node *right;
};

struct node * recu(struct node * root, struct node * new_node, int val);
struct node * insert(struct node * root, int val) ;
void preorder(struct node * root);
void inorder(struct node * root);
void postorder(struct node * root);

int main() {
    int r;
    struct node * root = (struct node*) malloc(sizeof(struct node));
    printf("Enter the value of the root node: ");
    scanf("%d", &r);
    root->data = r;
    root->left = NULL;
    root->right= NULL;
    int i;
    printf("Enter the value to inserted: ");
    scanf("%d", &i);
    while(i != -1){
        root = insert(root, i);
        printf("Enter the value to inserted: ");
        scanf("%d", &i);
    }
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");
    printf("END!");
}

struct node * insert(struct node * root, int val) {
    struct node * new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = val;
    new_node->left = NULL;
    new_node->right = NULL;
    recu(root, new_node, val);
    return root;
}

struct node * recu(struct node * root, struct node * new_node, int val) {
    if (root->data > val){
        if (root->left == NULL) {
            root->left = new_node;
            printf("%d inserted!\n",val);
            return root;
        } else {
            return recu(root->left,new_node,val);
        }
    } else {
        if (root->right == NULL) {
            root->right = new_node;
            printf("%d inserted!\n",val);
            return root;
        } else {
            return recu(root->right,new_node,val);
        }
    }
}

void preorder(struct node * root) {
    if (root == NULL){
        return;
    }
    printf("%d, ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node * root) {
    if (root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d, ",root->data);
    inorder(root->right);
}

void postorder(struct node * root) {
    if (root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d, ",root->data);
}