/*
 * main.c
 * Homework #2
 * Created by Nikita Gusev
 */

#include <stdio.h>

void solution1 ();
void solution2 ();
void solution3 ();
void menu ();

/* Реализовать функцию перевода из десятичной системы в двоичную, используя рекурсию */

void function (int Number) {
    if (Number > 1) {
        function (Number / 2);
    }
    printf("%d", Number % 2);
}

void solution1 () {

    int a;

    printf ("\nEnter a number: ");
    scanf ("%d", &a);
    printf("Your number in the binary system: ");
    function(a);
    printf ("\n");
}

/* Реализовать функцию возведения числа a в степень b:
    a. без рекурсии;
    b. рекурсивно;
    c. *рекурсивно, используя свойство четности степени */

double extent1 (int a, int b) {
    if (b > 1)
        return a * extent1(a, b - 1);
    else
        return a;
}

double extent2 (int a, int b) {
    if (b > 1) {
        if (b % 2 == 0)
            return extent2(a * a, b / 2);
        else
            return a * extent2(a * a, (b - 1) / 2);
    } else
        return a;
}

void solution2 () {

    int a;
    int b;

    printf ("\nEnter a number: ");
    scanf ("%d", &a);
    printf ("Enter a extent: ");
    scanf ("%d", &b);

    //    b. рекурсивно;

    printf("\nRecursively: %d to the extent of %d = ", a, b);
    if (a == 0 && b != 0)
        printf("0\n");
    else if (b > 0)
        printf("%0.1f\n", extent1(a, b));
    else if (b < 0)
        printf("%.101f\n", 1 / extent1(a, -b));
    else if (a != 0 && b == 0)
        printf("1\n");
    else
        printf("It is impossible to calculate!\n");

    //    c. *рекурсивно, используя свойство четности степени

    printf("Recursively through degree parity: %d to the extent of %d = ", a, b);
    if (a == 0 && b != 0)
        printf("0\n");
    else if (b > 0)
        printf("%0.1f\n", extent2(a, b));
    else if (b < 0)
        printf("%.101f\n", 1 / extent2(a, -b));
    else if (a != 0 && b == 0)
        printf("1\n");
    else
        printf("It is impossible to calculate!\n");

    //     a. без рекурсии;

    double extent = a;

    printf("%d to the extent of %d = ", a, b);
    if (a == 0 && b != 0)
        printf("0\n");
    else if (b > 0) {
        while (b > 1) {
            extent *= a;
            b--;
        }
        printf("%0.1f\n", extent);
    } else if (b < 0) {
        while (b < -1) {
            extent *= a;
            b++;
        }
        printf("%.101f\n", 1 / extent);
    } else if (a != 0 && b == 0)
        printf("1\n");
    else
        printf("It is impossible to calculate!\n");
}

/* Исполнитель Калькулятор преобразует целое число, записанное на экране. У исполнителя две команды, каждой команде присвоен номер:
        Прибавь 1
        Умножь на 2
    Первая команда увеличивает число на экране на 1, вторая увеличивает это число в 2 раза.
    Сколько существует программ, которые число 3 преобразуют в число 20?
        а) с использованием массива;
        б) с использованием рекурсии.
    Реализовать меню с выбором способа заполнения массива: из файла, случайными числами, с клавиатуры */

int calculator_array (int a, int b) {

    if (a > b)
        return 0;
    if (b > 100)
        return 0;
    int array[100] = {0};
    array[a] = 1;
    for (int i = a + 1; i <= b; i++) {
        array[i] = array[i - 1];
        if (i % 2 == 0)
            array[i] += array[i / 2];
    }
    return array[b];
}

int calculator_recurs (int a, int b) {

    if (a > b)
        return 0;
    if (b - a == 0)
        return 1;
    if (b % 2 > 0)
        return calculator_recurs(a, b - 1);
    else
        return calculator_recurs(a, b - 1) + calculator_recurs(a, b / 2);
}

void solution3 () {

    int a;
    int b;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    if (a > 0 && b > 0) {

    printf("\nCalculator using an array: %d\n", calculator_array(a, b));
    printf("Calculator using an recursion: %d\n", calculator_recurs(a, b));
    } else {
        printf("\nWrong numbers!\n");
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
