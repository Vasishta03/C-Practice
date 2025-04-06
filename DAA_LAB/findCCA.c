#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
struct Node* findCCA(struct Node* root, int n1, int n2) {
    if(root == NULL)return NULL;
    if(root->data == n1 || root->data == n2)return root;

    struct Node* leftCCA = findCCA(root->left, n1, n2);
    struct Node* rightCCA = findCCA(root->right, n1, n2);
    if (leftCCA && rightCCA)return root;
    return (leftCCA != NULL) ? leftCCA : rightCCA;
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    int n1 = 4, n2 = 5;
    struct Node* cca = findCCA(root, n1, n2);
    if(cca != NULL)printf("Closest Common Ancestor of %d and %d is: %d\n", n1, n2, cca->data);
    else printf("Nodes not found in the tree.\n");
    
    return 0;
}
