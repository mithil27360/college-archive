#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int val)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node *root, int val)
{
    if(root == NULL)
        return createNode(val);
    
    if(val < root->data)
        root->left = insert(root->left, val);
    else if(val > root->data)
        root->right = insert(root->right, val);
    
    return root;
}

void inorder(struct Node *root)
{
    if(root == NULL)
        return;
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void preorder(struct Node *root)
{
    if(root == NULL)
        return;
    
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root)
{
    if(root == NULL)
        return;
    
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
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
    
    printf("\nInorder: ");
    inorder(root);
    printf("\n");
    
    printf("Preorder: ");
    preorder(root);
    printf("\n");
    
    printf("Postorder: ");
    postorder(root);
    printf("\n");
    
    return 0;
}