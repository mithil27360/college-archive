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

struct Node* createTree()
{
    int val;
    printf("Enter value (-1 for NULL): ");
    scanf("%d", &val);
    
    if(val == -1)
        return NULL;
    
    struct Node *newNode = createNode(val);
    
    printf("Enter left child of %d\n", val);
    newNode->left = createTree();
    
    printf("Enter right child of %d\n", val);
    newNode->right = createTree();
    
    return newNode;
}

int height(struct Node *root)
{
    if(root == NULL)
        return 0;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

void printLevel(struct Node *root, int level)
{
    if(root == NULL)
        return;
    
    if(level == 1)
        printf("%d ", root->data);
    else
    {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}

void levelOrder(struct Node *root)
{
    int h = height(root);
    int i;
    
    printf("Level Order: ");
    for(i = 1; i <= h; i++)
        printLevel(root, i);
    printf("\n");
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
    
    printf("Create Binary Tree\n");
    root = createTree();
    
    if(root == NULL)
    {
        printf("Tree is empty\n");
        return 0;
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
    
    levelOrder(root);
    
    return 0;
}