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

struct Node* search(struct Node *root, int val)
{
    if(root == NULL || root->data == val)
        return root;
    
    if(val < root->data)
        return search(root->left, val);
    
    return search(root->right, val);
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
    int n, val, i, searchVal;
    
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
    
    printf("\nEnter value to search: ");
    scanf("%d", &searchVal);
    
    struct Node *result = search(root, searchVal);
    
    if(result != NULL)
        printf("%d found in BST\n", searchVal);
    else
        printf("%d not found in BST\n", searchVal);
    
    return 0;
}