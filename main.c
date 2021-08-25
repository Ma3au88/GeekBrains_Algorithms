/*
 * main.c
 * Homework #8
 * Created by Nikita Gusev
 */

#include <stdio.h>
#include <stdlib.h>

void solution1 ();
void solution2 ();
void menu ();

void printArr (int* arr, int length) {
    int i = 0;
    while (i < length) {
        printf(" %d ", arr[i]);
        i++;
    }
    printf ("\n");
}

/* Реализовать сортировку подсчетом */

void CountSort (int *array, int k) {
    int max = 0;
    for (int i = 0; i < k; i++)
        if (array[i] >= max)
            max = array[i] + 1;

    int counter [max];
    for (int i = 0; i < max; i++)
        counter [i] = 0;
    for (int i = 0; i < k; i++)
        counter[array[i]]++;

    int b = 0;
    for (int j = 0; j < max; j++)
        for (int i = 0; i < counter[j]; i++)
            array[b++] = j;
    for (int i = 0; i < k; i++)
        printf(" %d ", array[i]);

    printf("\n");
}

void solution1 () {

    int array [10] = {2, 5, 7, 11, 15, 23, 6, 8, 44, 1};
    printf("\nArray of numbers: ");
    printArr(array, 10);
    printf("\nSorting an array by counting: ");
    CountSort(array, 10);
}

/* Реализовать быструю сортировку */

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void QuickSort (int *array, int first, int last) {
    int i = first, j = last, x = array [(first + last)/2];
    do {
        while (array[i] < x)
            i++;
        while (array[j] > x)
            j--;
        if (i <= j) {
            if (array [i] > array [j])
                swap (&array[i], &array[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (i < last)
        QuickSort (array, i, last);
    if (first < j)
        QuickSort (array, first, j);
}

void solution2 () {

    int array [10] = {2, 5, 7, 11, 15, 23, 6, 8, 44, 1};
    printf("\nArray of numbers: ");
    printArr(array, 10);
    printf("\nQuick sorting of an array: ");
    QuickSort(array, 0, 10);

    for (int i = 0; i < 11; i++)
        printf(" %d ", array[i]);
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
