/*
 * main.c
 * Homework #7
 * Created by Nikita Gusev
 */

#include <stdio.h>
#include <stdlib.h>

#define T char
#define MaxN 10000
#define G 11

int n = 0;
int N = -1;
T Stack [MaxN];
T Graph [G][G];
T color[G];
T Queue [MaxN];
int front = MaxN;
int rear = MaxN;

void solution1 ();
void solution2 ();
void solution3 ();
void menu ();

T pop () {
    if (N != -1) {
        return Stack[N--];
    } else
        printf("Stack is empty");
    return 0;
}

void push (T i){
    if (N < MaxN) {
        N++;
        Stack[N] = i;
    } else
        printf("Stack owerflow");
}

void null () {
    while (N != -1)
        pop ();
    n = 0;
}

T queuepop () {
    if (rear != front) {
        front--;
        return Queue[front];
    } else
        printf("The queue is empty");
    return 0;
}

void queuepush (T p) {
    if (rear != 0){
        rear--;
        Queue[rear] = p;
    } else {
        rear = MaxN;
        queuepush (p);
    }
}

/* Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран */

void matrix (){

    FILE* file = fopen("D://Matrix.txt", "r");
    if (file == NULL) {
        puts("Can't open file!");
        exit(1);
    }

    int count;
    fscanf(file, "%d", &count);
    char Matrix[count][count];
    for (int i=0; i<count && !feof(file); i++)
        for(int j=0; j<count && !feof(file); j++) {
            fscanf(file, "%c", &Matrix[i][j]);
            printf("%c ", Matrix[i][j]);
            Graph [i][j] = Matrix[i][j];
        }
    fclose(file);
    printf("\n");
}

void solution1 () {

    matrix ();
}

/* Написать рекурсивную функцию обхода графа в глубину */

void GraphDepth (T mas[G][G], T a) {

    if (n == 0) {
        color[n] = a;
        n++;
    }

    int i = 1;
    while (mas[i][1] != a && i != G) {
        i++;
    } if (i == G)
        exit(1);

    for (int j = 2; j<G; j++)
        if (mas[i][j] != '0') {
            int g = 0;
            while (color[g] != mas[0][j] && g != n) {
                g++;
            } if (g == n) {
                push (mas[0][j]);
                color[n] = mas[0][j];
                n++;
            }
        }
    printf("%c", a);

    if (N != -1) {
        printf("->");
        GraphDepth (mas, pop());
    }
}

void solution2 () {

    printf("\nTraversing the graph in depth: \n");
    null ();
    GraphDepth (Graph, 'A');
    printf("\n");
    null ();
    GraphDepth (Graph, 'H');
    printf("\n\n");
}

/* Написать функцию обхода графа в ширину */

void GraphWidth (char mas[G][G], char a) {

    if (n == 0) {
        color[n] = a;
        n++;
    }

    int i = 1;
    while (mas[i][1] != a && i != G) {
        i++;
    } if (i == G)
        exit(1);

    for (int j = 2; j<G; j++)
        if (mas[i][j] != '0') {
            int g = 0;
            while (color[g] != mas[0][j] && g != n) {
                g++;
            } if (g == n) {
                queuepush (mas[0][j]);
                color[n] = mas[0][j];
                n++;
            }
        }
    printf("%c", a);

    if (rear != front) {
        printf("->");
        GraphWidth (mas, queuepop());
    }
}

void solution3 () {

    printf("\nTraversing the graph in width: \n");
    null ();
    GraphWidth (Graph, 'A');
    printf("\n");
    null ();
    GraphWidth (Graph, 'H');
    printf("\n\n");
}

void menu () {
    printf ( "\nPlease enter the task number: \n" );
    printf ( "1 - task1\n" );
    printf ( "2 - task2\n" );
    printf ( "3 - task3\n" );
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
    case 3:
    solution3 ();
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
