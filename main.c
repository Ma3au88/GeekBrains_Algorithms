/*
 * main.c
 * Homework #4
 * Created by Nikita Gusev
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i, j, m, n, c[20][20];
char x[20], y[20], b[20][20];

int ARR[8][8];
const int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int s;

void solution1 ();
void solution2 ();
void solution3 ();
void menu ();

/* *Количество маршрутов с препятствиями. Реализовать чтение массива с препятствием и нахождение количество маршрутов */

void solution1 () {

    int N;
    printf("\nEnter the number of lines in the map: ");
    scanf("%i", &N);

    int M;
    printf("Enter the number of columns in the map: ");
    scanf("%i", &M);

    int a[N][M];

    printf("Filling the array with data\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
            a[i][j] = rand() % 2;
    }
    a[0][0] = 1;

    printf("Your map: \n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%i ", a[i][j]);
        }
        printf("\n");
    }

    for (int i = 1; i < N; i++) {
        if (a[i][0] != 0) {
            a[i][0] = a[i - 1][0];
        }
    }

    for (j = 1; j < M; j++) {
        if (a[0][j] != 0) {
            a[0][j] = a[0][j - 1];
        }
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            if (a[i][j] != 0)
                a[i][j] = a[i - 1][j] + a[i][j - 1];
        }
    }

    printf("\nYour map of the numbers of routes a(i, j): \n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%i ", a[i][j]);
        }
        printf("\n");
    }
}

/* Решить задачу о нахождении длины максимальной последовательности с помощью матрицы */

void print(int i, int j) {
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 'c') {
        print(i - 1, j - 1);
        printf("%c", x[i - 1]);
    } else if (b[i][j] == 'u')
        print(i - 1, j);
    else
        print(i, j - 1);
}

void lcs() {
    m = strlen(x);
    n = strlen(y);

    for (i = 0; i <= m; i++)
        c[i][0] = 0;
    for (i = 0; i <= n; i++)
        c[0][i] = 0;

    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++) {
            if (x[i - 1] == y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'c';
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'u';
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'l';
            }
        }
}

void solution2 () {

    printf("\nEnter first sequence: ");
    scanf("%s", x);
    printf("Enter second sequence: ");
    scanf("%s", y);
    printf("\nThe Longest Common Subsequence is ");
    lcs();
    print(m, n);
    printf("\n");
}

/* ***Требуется обойти конем шахматную доску размером NxM, пройдя через все поля доски по одному разу.
 * Здесь алгоритм решения такой же, как в задаче о 8 ферзях. Разница только в проверке положения коня */

void rek (int x, int y, int step)
{
    ARR[x][y] = step;

    int i;

    for (i = 0; i < 8; i++) {
        int x1 = x + dx[i];
        int y1 = y + dy[i];

        if ((x1 >= 0) && (y1 >= 0) && (x1 < 8) && (y1 < 8) && (ARR[x1][y1] == 0)) {
            rek(x1, y1, step + 1);
        }
    }
}

void solution3 () {

    int x, y;

    s = 2;

    for (x = 0; x < 8; x++) {
        for (y = 0; y < 8; y++) {
            ARR[x][y] = 0;
        }
    }

    ARR[0][0] = 1;

    rek (0, 0, 1);

    for (x = 0; x < 8; x++) {
        for (y = 0; y < 8; y++) {
            printf("%4d ", ARR[x][y]);
        }
        printf("\n");
    }
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
