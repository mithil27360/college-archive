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

int findMin(struct Node *root)
{
    if(root == NULL)
    {
        printf("Tree is empty\n");
        return -1;
    }
    
    while(root->left != NULL)
        root = root->left;
    
    return root->data;
}

int findMax(struct Node *root)
{
    if(root == NULL)
    {
        printf("Tree is empty\n");
        return -1;
    }
    
    while(root->right != NULL)
        root = root->right;
    
    return root->data;
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
    
    printf("\nMinimum element: %d\n", findMin(root));
    printf("Maximum element: %d\n", findMax(root));
    
    return 0;
}