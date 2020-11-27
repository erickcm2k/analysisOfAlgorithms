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
struct node *search(node *root, int key);
struct node *search(node *root, int key);
int main(int argc, char *argv[])
{

    double utime0, stime0, wtime0, utime1, stime1, wtime1, currentN;
    double numsToFind[20] = {322486, 14700764, 3128036, 6337399, 61396, 10393545, 2417445644, 1295390003, 450057883, 187645041, 1980098116, 152503, 5000, 1493283650, 214826, 1843349527, 1360839354, 2109248666, 2147470852, 0};

    if (argc != 2)
    {
        printf("Se deben ingresar exactamente dos argumentos.\n\n");
        return -1;
    }
    else
    {
        currentN = atoi(argv[1]);
    }

    numbers = (int *)malloc(sizeof(int) * currentN);
    node *root = NULL;

    printf("\n\nLeyendo numeros...\n");

    for (int i = 0; i < currentN; ++i)
    {
        scanf("%d", &numbers[i]);
        root = insert(root, numbers[i]);
    }

    printf("\n%-16s %-16s %-16s %-16s\n\n", "Numero", "N", "Tiempo", "Encontrado");
    for (int i = 0; i < 20; i++)
    {
        // // algorithm begin
        uswtime(&utime0, &stime0, &wtime0);
        node *toFind = search(root, numsToFind[i]);
        if (!toFind)
        {
            printf("%10.0f \t %.0f \t%.10e \t NO\n", numsToFind[i], currentN, wtime1 - wtime0);
        }
        else
        {
            printf("%10.0f \t %.0f \t%.10e \t SI\n", numsToFind[i], currentN, wtime1 - wtime0);
        }
        uswtime(&utime1, &stime1, &wtime1);
        // algorithm end
    }
    printf("\n");
        /*
    //Cálculo del tiempo de ejecución del programa
    printf("\n");
    printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
    printf("user (Tiempo de procesamiento en CPU) %.10f s\n", utime1 - utime0);
    printf("sys (Tiempo en acciónes de E/S)  %.10f s\n", stime1 - stime0);
    printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
    printf("\n");

    //Mostrar los tiempos en formato exponecial
    printf("\n");
    printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
    printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
    printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", stime1 - stime0);
    printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
    printf("\n");
*/
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
        printf("%d\n", root->value);
        numbers[i++] = root->value;
        saveInorder(root->right);
    }
}

struct node *search(node *root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->value == key)
        return root;

    // Key is greater than root's key
    if (root->value < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}
