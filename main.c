/*
 * main.c
 * Homework #6
 * Created by Nikita Gusev
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define CMP_LT(a, b) ((a) < (b))
#define CMP_GT(a, b) ((a) > (b))

void solution1 ();
void solution2 ();
void menu ();

/* Реализовать простейшую хеш-функцию. На вход функции подается строка, на выходе сумма кодов символов */

unsigned long Hash (unsigned char *str) {

    unsigned long Hash = 5381;
    int c;

    while (c = *str++)
        Hash = ((Hash << 5) + Hash) + c;

    return Hash;
}

void solution1 () {

    char* String = "Hello, world!";
    printf("\nHello, world! in hash: %lu \n", Hash(String));
}

/* Переписать программу, реализующую двоичное дерево поиска.
    а) Добавить в него обход дерева различными способами;
    б) Реализовать поиск в двоичном дереве поиска */

typedef int T;
typedef struct Node {
    T data;
    struct Node *left;
    struct Node *right;
    struct Node *parent;
} Node;

void printTree(Node *root) {
    if (root)
    {
        printf("%d",root->data);
        if (root->left || root->right)
        {
            printf("(");

            if (root->left)
                printTree(root->left);
            else
                printf("NULL");
            printf(",");

            if (root->right)
                printTree(root->right);
            else
                printf("NULL");
            printf(")");
        }
    }
}

Node* getFreeNode(T value, Node *parent) {
    Node* tmp = (Node*) malloc(sizeof(Node));
    tmp->left = tmp->right = NULL;
    tmp->data = value;
    tmp->parent = parent;
    return tmp;
}

Node* getNodeByValue(Node* root, T value) {
    while (root) {
        if (CMP_GT(root->data, value)) {
            root = root->left;
            continue;
        }
        else if (CMP_LT(root->data, value)) {
            root = root->right;
            continue;
        }
        else
        {
            return root;
        }
    }
    return NULL;
}

void insert(Node **head, int value) {
    Node *tmp = NULL;
    if (*head == NULL)
    {
        *head = getFreeNode(value, NULL);
        return;
    }

    tmp = *head;
    while (tmp)
    {
        if (value> tmp->data)
        {
            if (tmp->right)
            {
                tmp = tmp->right;
                continue;
            }
            else
            {
                tmp->right = getFreeNode(value, tmp);
                return;
            }
        }
        else if (value< tmp->data)
        {
            if (tmp->left)
            {
                tmp = tmp->left;
                continue;
            }
            else
            {
                tmp->left = getFreeNode(value, tmp);
                return;
            }
        }
        else
        {
            exit(2);
        }
    }
}

void preOrderTravers(Node* root) {
    if (root) {
        printf("%d ", root->data);
        preOrderTravers(root->left);
        preOrderTravers(root->right);
    }
}

void inOrderTravers(Node* root) {
    if (root) {
        inOrderTravers(root->left);
        printf("%d ", root->data);
        inOrderTravers(root->right);
    }
}

void postOrderTravers(Node* root) {
    if (root) {
        postOrderTravers(root->left);
        postOrderTravers(root->right);
        printf("%d ", root->data);
    }
}

void solution2 () {

    Node *Tree = NULL;

    FILE* file = fopen("D:\\data.txt", "r");

    if (file == NULL)
    {
        puts("Can't open file!");
        exit(1);
    }

    int count;
    fscanf(file, "%d", &count);

    int i;
    for(i = 0; i < count; i++)
    {
        int value;
        fscanf(file, "%d", &value);
        insert(&Tree, value);
    }
    fclose(file);

    printTree(Tree);

    printf("\nPreOrderTravers:");
    preOrderTravers(Tree);

    printf("\ninOrderTravels: ");
    inOrderTravers(Tree);

    printf("\npostOrderTravels: ");
    postOrderTravers(Tree);
    printf("\n");
}


void menu () {
    printf ( "\nPlease enter the task number: \n" );
    printf ( "1 - task1\n" );
    printf ( "2 - task2\n" );
    printf ( "0 - exit\n" );
}

int main()
{
    int sel = 0;

    do {
    menu ();
    scanf ( "%i" , & sel );
    switch ( sel) {
    case 1:
    solution1 ();
    break;
    case 2:
    solution2 ();
    break;
    case 0:
    printf ( "\nThanks for watching. Bye-bye!" );
    break;
    default:
    printf ( "\nWrong selected\n" );
    }
    } while ( sel != 0 );

    return 0;
}
