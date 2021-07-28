/*
 * main.c
 * Homework #1
 * Created by Nikita Gusev
 */

#include <stdio.h>
#include <math.h>

void solution1 ();
void solution2 ();
void solution3 ();
void solution4 ();
void menu ();

/* Ввести вес и рост человека. Рассчитать и вывести индекс массы тела по формуле I=m/(h*h);
 * где m-масса тела в килограммах, h - рост в метрах */

void solution1 () {

    printf ( "\nSolution 1\n" );

    double weight;
    double height;

    printf ("Enter your weight in kilograms: ");
    scanf ("%lf", &weight);
    printf ("Enter your height in meters: ");
    scanf ("%lf", &height);
    printf("Your body mass index: %lf\n", weight / (pow(height, 2)));
}

/* Найти максимальное из четырех чисел. Массивы не использовать */

int MaxNumber (int a, int b) {
    int max = a;
    if (max < b)
        max = b;
    return max;
}

void solution2 () {

    printf ( "\nSolution 2\n" );

    int a;
    int b;
    int c;
    int d;

    printf ("Enter first number: ");
    scanf ("%d", &a);
    printf ("Enter second number: ");
    scanf ("%d", &b);
    printf ("Enter third number: ");
    scanf ("%d", &c);
    printf ("Enter fourth number: ");
    scanf ("%d", &d);

    printf("Max number: %d\n", MaxNumber(MaxNumber((MaxNumber(a, b)), c), d));
}

/* Написать программу обмена значениями двух целочисленных переменных:
    b. *без использования третьей переменной */

void solution3 () {

    printf ( "\nSolution 3\n" );

    int a;
    int b;

    printf ("Enter first number: ");
    scanf ("%d", &a);
    printf ("Enter second number: ");
    scanf ("%d", &b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("a = %d, b = %d\n", a, b);
}

/* Написать программу нахождения корней заданного квадратного уравнения */

void solution4 () {

    printf ( "\nSolution 4\n" );

    double a;
    double b;
    double c;

    printf ("Enter a: ");
    scanf ("%lf", &a);
    printf ("Enter b: ");
    scanf ("%lf", &b);
    printf ("Enter c: ");
    scanf ("%lf", &c);

    double D = pow(b, 2) - 4 * a * c;
    printf ("Discriminant = %g\n", D);

    if (D < 0) {
        printf("No x\n");
    } else if (D == 0) {
        double x = (- b / (2 * a));
        printf("x = %g\n", x);
    } else {
        double x1 = (- b + sqrt(D)) / (2 * a);
        double x2 = (- b - sqrt(D)) / (2 * a);
        printf("x1 = %g, x2 = %g\n", x1, x2);
    }
}

void menu () {
    printf ( "\nPlease enter the task number: \n" );
    printf ( "1 - task1\n" );
    printf ( "2 - task2\n" );
    printf ( "3 - task3\n" );
    printf ( "4 - task4\n" );
    printf ( "0 - exit\n" );
}

int main () {

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
    case 4:
    solution4 ();
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

