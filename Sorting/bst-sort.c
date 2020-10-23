#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    int bf; // Balance Factor
    struct Node *right;
    struct Node *left;
};

struct Node *insert(struct Node *root, int newData);
struct Node *rightRotation(struct Node *unbalancedRoot);
struct Node *leftRotation(struct Node *unbalancedRoot);
int getHeight(struct Node *root);
int getBf(struct Node *root);
int search(struct Node *root, int target);
void inorderTraversal(struct Node *root);

struct Node *insert(struct Node *root, int newData)
{

    struct Node *new = NULL;

    if (root == NULL)
    {

        new = malloc(sizeof(struct Node));
        if (new == NULL)
        {
            return NULL;
        }
        new->data = newData;
        new->bf = 0;
        new->right = NULL;
        new->left = NULL;
        return new;
    }

    if (root->data == newData)
    {

        return root;
    }
    if (newData > root->data)
    {

        root->right = insert(root->right, newData);
    }
    else
    {

        root->left = insert(root->left, newData);
    }
    root->bf = getBf(root);
    if ((root->bf == -2) && (root->left->bf == -1))
    {
        root = rightRotation(root);
        root->bf = getBf(root);
        root->right->bf = getBf(root->right);
        root->left->bf = getBf(root->left);
    }

    if ((root->bf == 2) && (root->right->bf == 1))
    {
        root = leftRotation(root);
        root->bf = getBf(root);
        root->right->bf = getBf(root->right);
        root->left->bf = getBf(root->left);
    }

    if ((root->bf > 1) && (root->right->bf < 0))
    {
        root->right = rightRotation(root->right);
        root = leftRotation(root);
        root->bf = getBf(root);
        root->right->bf = getBf(root->right);
        root->left->bf = getBf(root->left);
    }

    if ((root->bf < -1) && (root->left->bf > 0))
    {
        root->left = leftRotation(root->left);
        root = rightRotation(root);
        root->bf = getBf(root);
        root->right->bf = getBf(root->right);
        root->left->bf = getBf(root->left);
    }

    return root;
}

struct Node *rightRotation(struct Node *unbalancedRoot)
{

    struct Node *aux = unbalancedRoot;
    struct Node *aux2 = NULL;
    unbalancedRoot = unbalancedRoot->left;

    if (unbalancedRoot->right != NULL)
    {

        aux2 = unbalancedRoot->right;
    }

    unbalancedRoot->right = aux;

    unbalancedRoot->right->left = aux2;

    return unbalancedRoot;
}

struct Node *leftRotation(struct Node *unbalancedRoot)
{

    struct Node *aux = unbalancedRoot;
    struct Node *aux2 = NULL;
    unbalancedRoot = unbalancedRoot->right;

    if (unbalancedRoot->left != NULL)
    {

        aux2 = unbalancedRoot->left;
    }

    unbalancedRoot->left = aux;

    unbalancedRoot->left->right = aux2;

    return unbalancedRoot;
}

int getHeight(struct Node *root)
{

    int rightHeight = 0;
    int leftHeight = 0;

    if (root == NULL)
    {
        return -1;
    }

    leftHeight = getHeight(root->left);
    rightHeight = getHeight(root->right);

    if (leftHeight > rightHeight)
    {
        return leftHeight + 1;
    }
    return rightHeight + 1;
}

int getBf(struct Node *root)
{

    int rightHeight = 0;
    int leftHeight = 0;

    if (root == NULL)
    {
        return 0;
    }

    leftHeight = getHeight(root->left);
    rightHeight = getHeight(root->right);

    return rightHeight - leftHeight;
}

int search(struct Node *root, int target)
{

    if (root == NULL)
    {

        return 0;
    }
    else if (root->data == target)
    {

        return 1;
    }
    else if (target < root->data)
    {

        return search(root->left, target);
    }
    else
    {

        return search(root->right, target);
    }
}

void inorderTraversal(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left);
    printf("%d\n", root->data);
    inorderTraversal(root->right);
}

int main(int argc, char const *argv[])
{
    int dsSize;
    int value;
    scanf("%d", &dsSize);
    struct Node *root = NULL;

    for (int i = 0; i < dsSize; i++)
    {
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("Sorted numbers\n");
    inorderTraversal(root);

    return 0;
}
