#include <stdio.h>
#include <stdlib.h>

// Tree node structure
typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
    int height;
} Node;

// Helper function prototypes
int max(int a, int b);
int height(Node *node);
int balance_factor(Node *node);
Node* create_node(int value);
Node* left_rotate(Node *x);
Node* right_rotate(Node *y);
Node* insert(Node *node, int value);
void preorder(Node *root);

int main() {
    Node *root = NULL;
    
    // Insert sample values
    int values[] = {10, 20, 30, 40, 50, 25};
    for(int i = 0; i < 6; i++) {
        root = insert(root, values[i]);
    }
    
    printf("Preorder traversal:\n");
    preorder(root);
    printf("\n");
    
    return 0;
}

// Utility functions
int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node *node) {
    return node ? node->height : 0;
}

int balance_factor(Node *node) {
    return node ? height(node->left) - height(node->right) : 0;
}

Node* create_node(int value) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->left = new_node->right = NULL;
    new_node->height = 1;
    return new_node;
}

// Rotations (fixed implementation)
Node* left_rotate(Node *x) {
    Node *y = x->right;
    Node *T2 = y->left;
    
    // Perform rotation
    y->left = x;
    x->right = T2;
    
    // Update heights
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));
    
    return y;
}

Node* right_rotate(Node *y) {
    Node *x = y->left;
    Node *T2 = x->right;
    
    // Perform rotation
    x->right = y;
    y->left = T2;
    
    // Update heights
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));
    
    return x;
}

// AVL insertion with balancing
Node* insert(Node *node, int value) {
    // 1. Standard BST insertion
    if (!node) return create_node(value);
    
    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);
    else 
        return node; // Duplicate values not allowed
    
    // 2. Update node height
    node->height = 1 + max(height(node->left), height(node->right));
    
    // 3. Check balance factor
    int bf = balance_factor(node);
    
    // 4. Handle imbalance cases
    // Left-Left Case
    if (bf > 1 && value < node->left->value)
        return right_rotate(node);
    
    // Right-Right Case
    if (bf < -1 && value > node->right->value)
        return left_rotate(node);
    
    // Left-Right Case
    if (bf > 1 && value > node->left->value) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }
    
    // Right-Left Case
    if (bf < -1 && value < node->right->value) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }
    
    return node;
}

void preorder(Node *root) {
    if (root) {
        printf("%d ", root->value);
        preorder(root->left);
        preorder(root->right);
    }
}
