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

struct Node* findMin(struct Node *root)
{
    while(root->left != NULL)
        root = root->left;
    return root;
}

struct Node* deleteNode(struct Node *root, int val)
{
    if(root == NULL)
        return root;
    
    if(val < root->data)
        root->left = deleteNode(root->left, val);
    else if(val > root->data)
        root->right = deleteNode(root->right, val);
    else
    {
        if(root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        
        struct Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
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

int main()
{
    struct Node *root = NULL;
    int n, val, i, delVal;
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    printf("Enter values: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &val);
        root = insert(root, val);
    }
    
    printf("\nBefore deletion - Inorder: ");
    inorder(root);
    printf("\n");
    
    printf("\nEnter value to delete: ");
    scanf("%d", &delVal);
    
    root = deleteNode(root, delVal);
    
    printf("\nAfter deletion - Inorder: ");
    inorder(root);
    printf("\n");
    
    return 0;
}