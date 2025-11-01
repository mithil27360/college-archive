#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    int height;
};

struct Node* createNode(int val)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int height(struct Node *node)
{
    if(node == NULL)
        return 0;
    return node->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int getBalance(struct Node *node)
{
    if(node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct Node* rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    
    return x;
}

struct Node* leftRotate(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    
    return y;
}

struct Node* insert(struct Node *node, int val)
{
    if(node == NULL)
        return createNode(val);
    
    if(val < node->data)
        node->left = insert(node->left, val);
    else if(val > node->data)
        node->right = insert(node->right, val);
    else
        return node;
    
    node->height = 1 + max(height(node->left), height(node->right));
    
    int balance = getBalance(node);
    
    if(balance > 1 && val < node->left->data)
        return rightRotate(node);
    
    if(balance < -1 && val > node->right->data)
        return leftRotate(node);
    
    if(balance > 1 && val > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    
    if(balance < -1 && val < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    
    return node;
}

void preorder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    int n, val, i;
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter values: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &val);
        root = insert(root, val);
    }
    
    printf("\nPreorder: ");
    preorder(root);
    printf("\n");
    
    printf("Inorder: ");
    inorder(root);
    printf("\n");
    
    printf("Height of tree: %d\n", height(root));
    
    return 0;
}