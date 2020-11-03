#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

typedef struct node
{
    int value;
    struct node *left;
    struct node *right;
    int bf;
} node;

int max(int a, int b);
int bf(node *root);
int getBf(node *root);
node *createNode(int value);
node *rightRotation(node *root);
node *leftRotation(node *root);
node *insert(node *root, int value);
void saveInorder(node *root);
int *numbers;
int main(int argc, char *argv[])
{
    double utime0, stime0, wtime0, utime1, stime1, wtime1, n;

    if (argc != 2)
    {
        printf("\nIndique el tamanio del algoritmo.\n", argv[0]);
        exit(1);
    }
    else
    {
        n = atoi(argv[1]);
    }

    numbers = (int *)malloc(sizeof(int) * n);
    printf("\n\nSize of test is: [%.0f]\n\n", n);
    int value, i;
    node *root = NULL;

    // algorithm begin
    uswtime(&utime0, &stime0, &wtime0);

    for (i = 0; i < n; ++i)
    {
        scanf("%d", &numbers[i]);
        root = insert(root, numbers[i]);
    }

    saveInorder(root);

    // algorithm end
    uswtime(&utime1, &stime1, &wtime1);
    //Cálculo del tiempo de ejecución del programa
    printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
    printf("user (Tiempo de procesamiento en CPU) %.10f s\n", utime1 - utime0);
    printf("sys (Tiempo en acciónes de E/S)  %.10f s\n", stime1 - stime0);
    printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));

    return 0;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int bf(node *root)
{
    return (root == NULL) ? 0 : root->bf;
}

node *createNode(int value)
{
    node *root = (node *)malloc(sizeof(node));

    root->value = value;
    root->left = NULL;
    root->right = NULL;
    root->bf = 1;

    return root;
}

node *rightRotation(node *root)
{
    node *next = root->left;
    node *temp = next->right;

    next->right = root;
    root->left = temp;

    root->bf = max(bf(root->left), bf(root->right)) + 1;
    next->bf = max(bf(next->left), bf(next->right)) + 1;

    return next;
}

node *leftRotation(node *root)
{
    node *next = root->right;
    node *temp = next->left;

    next->left = root;
    root->right = temp;

    root->bf = max(bf(root->left), bf(root->right)) + 1;
    next->bf = max(bf(next->left), bf(next->right)) + 1;

    return next;
}

int getBf(node *root)
{
    return (root == NULL) ? 0 : bf(root->left) - bf(root->right);
}

node *insert(node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }

    if (value < root->value)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = insert(root->right, value);
    }
    else
    {
        return root;
    }

    root->bf = max(bf(root->left), bf(root->right)) + 1;

    int balance = getBf(root);

    if (balance > 1 && value < root->left->value)
    {
        return rightRotation(root);
    }

    if (balance < -1 && value > root->right->value)
    {
        return leftRotation(root);
    }

    if (balance > 1 && value > root->left->value)
    {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    if (balance < -1 && value < root->right->value)
    {
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }

    return root;
}

void saveInorder(node *root)
{
    long long i = 0;
    if (root != NULL)
    {
        saveInorder(root->left);
        numbers[i++] = root->value;
        saveInorder(root->right);
    }
}