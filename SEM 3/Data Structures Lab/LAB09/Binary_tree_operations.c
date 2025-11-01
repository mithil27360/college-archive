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
    
    char choice;
    printf("Insert %d to left or right of %d (l/r): ", val, root->data);
    scanf(" %c", &choice);
    
    if(choice == 'l' || choice == 'L')
    {
        if(root->left == NULL)
            root->left = createNode(val);
        else
            root->left = insert(root->left, val);
    }
    else
    {
        if(root->right == NULL)
            root->right = createNode(val);
        else
            root->right = insert(root->right, val);
    }
    return root;
}

void inorderIterative(struct Node *root)
{
    if(root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    
    struct Node *stack[100];
    int top = -1;
    struct Node *curr = root;
    
    while(curr != NULL || top != -1)
    {
        while(curr != NULL)
        {
            stack[++top] = curr;
            curr = curr->left;
        }
        curr = stack[top--];
        printf("%d ", curr->data);
        curr = curr->right;
    }
    printf("\n");
}

void preorderIterative(struct Node *root)
{
    if(root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    
    struct Node *stack[100];
    int top = -1;
    stack[++top] = root;
    
    while(top != -1)
    {
        struct Node *curr = stack[top--];
        printf("%d ", curr->data);
        
        if(curr->right != NULL)
            stack[++top] = curr->right;
        if(curr->left != NULL)
            stack[++top] = curr->left;
    }
    printf("\n");
}

void postorderIterative(struct Node *root)
{
    if(root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    
    struct Node *stack1[100], *stack2[100];
    int top1 = -1, top2 = -1;
    
    stack1[++top1] = root;
    
    while(top1 != -1)
    {
        struct Node *curr = stack1[top1--];
        stack2[++top2] = curr;
        
        if(curr->left != NULL)
            stack1[++top1] = curr->left;
        if(curr->right != NULL)
            stack1[++top1] = curr->right;
    }
    
    while(top2 != -1)
        printf("%d ", stack2[top2--]->data);
    printf("\n");
}

int findParent(struct Node *root, int val, int parent)
{
    if(root == NULL)
        return -1;
    
    if(root->data == val)
        return parent;
    
    int left = findParent(root->left, val, root->data);
    if(left != -1)
        return left;
    
    return findParent(root->right, val, root->data);
}

void printParent(struct Node *root, int val)
{
    if(root == NULL)
    {
        printf("Tree is empty\n");
        return;
    }
    
    if(root->data == val)
    {
        printf("No parent (root node)\n");
        return;
    }
    
    int parent = findParent(root, val, -1);
    if(parent == -1)
        printf("Element not found\n");
    else
        printf("Parent of %d is %d\n", val, parent);
}

int height(struct Node *root)
{
    if(root == NULL)
        return 0;
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int printAncestors(struct Node *root, int val)
{
    if(root == NULL)
        return 0;
    
    if(root->data == val)
        return 1;
    
    if(printAncestors(root->left, val) || printAncestors(root->right, val))
    {
        printf("%d ", root->data);
        return 1;
    }
    
    return 0;
}

int countLeafNodes(struct Node *root)
{
    if(root == NULL)
        return 0;
    
    if(root->left == NULL && root->right == NULL)
        return 1;
    
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main()
{
    struct Node *root = NULL;
    int choice, val, n, i;
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &val);
        if(root == NULL)
            root = createNode(val);
        else
            insert(root, val);
    }
    
    while(1)
    {
        printf("\n1. Inorder (Iterative)\n2. Preorder (Iterative)\n3. Postorder (Iterative)\n");
        printf("4. Print Parent\n5. Print Height\n6. Print Ancestors\n7. Count Leaf Nodes\n8. Exit\nChoice: ");
        scanf("%d", &choice);
        
        if(choice == 1)
        {
            printf("Inorder: ");
            inorderIterative(root);
        }
        else if(choice == 2)
        {
            printf("Preorder: ");
            preorderIterative(root);
        }
        else if(choice == 3)
        {
            printf("Postorder: ");
            postorderIterative(root);
        }
        else if(choice == 4)
        {
            printf("Enter element: ");
            scanf("%d", &val);
            printParent(root, val);
        }
        else if(choice == 5)
        {
            printf("Height: %d\n", height(root));
        }
        else if(choice == 6)
        {
            printf("Enter element: ");
            scanf("%d", &val);
            printf("Ancestors: ");
            if(!printAncestors(root, val))
                printf("Element not found");
            printf("\n");
        }
        else if(choice == 7)
        {
            printf("Leaf nodes: %d\n", countLeafNodes(root));
        }
        else if(choice == 8)
        {
            break;
        }
    }
    
    return 0;
}