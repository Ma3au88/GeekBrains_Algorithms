/*
 * main.c
 * Homework #3
 * Created by Nikita Gusev
 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

void solution1 ();
void solution2 ();
void solution3 ();
void menu ();

void swap (int *a, int *b) {
    *a^=*b;
    *b^=*a;
    *a^=*b;
}

void fillArr (int* arr, int length) {
    int i = 0;
    while (i < length) {
        arr[i] = rand()%100;
        i++;
    }
}

void printArr (int* arr, int length) {
    int i = 0;
    while (i < length) {
        printf(" %d ", arr[i]);
        i++;
    }
    printf ("\n");
}

/* Попробовать оптимизировать пузырьковую сортировку. Сравнить количество операций сравнения оптимизированной
 * и не оптимизированной программы. Написать функции сортировки, которые возвращают количество операций */

int BubbleSort (int* arr, int length) {
    int counter = 0;
    for (int i = 0; i < length; i++) {
        for (int j = i + 1; j < length; j++) {
            counter++;
            if (arr[i] > arr[j]) {
                swap (&arr[i], &arr[j]);
            }
        }
    }
    return counter;
}

int BubbleSortOptimized (int* arr, int length) {
    int counter = 0;
    int flag = 0;
    for (int i = 0; i < length; i++) {
        flag = 1;
        for (int j = (i % 2) ? 0 : 1; j < length - 1; j += 2) {
            counter++;
            if (arr[j] > arr[j + 1]) {
                swap (&arr[j], &arr[j + 1]);
                flag = 0;
            }
        }
        if (flag)
            break;
    }
    return counter;
}

void solution1 () {

    int array[SIZE];

    fillArr(array, SIZE);
    printf("\nGenerated array of numbers:\n");
    printArr(array, SIZE);

    printf("\nBubble sorting - %d operations\n", BubbleSort(array, SIZE));
    printArr(array, SIZE);

    printf("\nOptimized bubble sorting - %d operations\n", BubbleSortOptimized(array, SIZE));
    printArr(array, SIZE);
}

/* *Реализовать шейкерную сортировку */

int ShakerSort (int* arr, int length) {
    int counter = 0;
    int left = 0;
    int right = length - 1;
    do {
        for (int i = left; i < right; i++)
            if (arr[i] > arr[i + 1])
                swap (&arr[i], &arr[i + 1]);
        right--;
        counter++;

        for (int i = right; i > left; i--)
            if (arr[i] < arr[i - 1])
                swap (&arr[i], &arr[i - 1]);
        left++;
        counter++;
    } while (left <= right);
    return counter;
}

void solution2 () {

    int array[SIZE];

    fillArr(array, SIZE);
    printf("\nGenerated array of numbers:\n");
    printArr(array, SIZE);

    printf("\nShaker sorting - %d operations\n", ShakerSort(array, SIZE));
    printArr(array, SIZE);
}

/* Реализовать бинарный алгоритм поиска в виде функции, которой передается отсортированный массив.
 * Функция возвращает индекс найденного элемента или -1, если элемент не найден */

int BinarySort (int* arr, int length, int number) {
    int counter = 0;
    int left = 0;
    int rigth = length - 1;
    int middle;
    while (counter < length) {
        counter++;
        middle = (left + rigth) / 2;
        if (arr[middle] == number) {
            break;
        } else if (arr[middle] > number) {
            rigth = middle - 1;
        } else
            left = middle;
    }
    return (arr[middle] == number) ? middle :  -1;
}

void solution3 () {

    int a;
    int array[SIZE];

    printf ("\nEnter a number from 0 to 99: ");
    scanf ("%d", &a);

    if (a >=0 && a < 100) {
    fillArr(array, SIZE);
    printf("\nGenerated array of numbers:\n");
    ShakerSort(array, SIZE);
    printArr(array, SIZE);

    printf("\nBinary sorting: your number - %d, index of the found element - %d\n", a, BinarySort(array, SIZE, a));
    } else {
        printf("\nWrong number!\n");
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
