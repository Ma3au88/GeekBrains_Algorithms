/*
 * main.c
 * Homework #5
 * Created by Nikita Gusev
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>

void solution1 ();
void solution2 ();
void menu ();

/* Реализовать перевод из десятичной в двоичную систему счисления с использованием стека */

typedef struct Node {
    char data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} Stack;

int push (Stack* st, char val) {
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Memory allocation error!\n");   // проверка на выделение памяти
        return 0;
    }

    temp->data = val;
    temp->next = st->head;
    st->head = temp;
    st->size++;
    return 1;
}

char pop (Stack* st) {
    if (st->size == 0) {
        return -1;
    }
    Node* temp = st->head;
    char result = st->head->data;
    st->head = st->head->next;
    st->size--;
    free (temp);
    return result;
}

void solution1 () {

    Stack s;
    s.size = 0;
    s.head = NULL;
    unsigned int a;

    printf("\nEnter a number: ");
    scanf("%d", &a);
    printf("%s ", "Your number in the binary system:");

    for (; a!= 0; a/= 2) {
        if (a % 2)
            push (&s, '1');
        else
            push (&s, '0');
    } while (s.size > 0) {
        printf("%c", pop (&s));
    }
    printf("\n");
}

/* Написать программу, которая определяет, является ли введенная скобочная последовательность правильной.
 * Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]), неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{ */

int brace (const char* s) {

    int i, ds[3];
    const char* p;
    const char begin[] = "({[";
    const char end[] = ")}]";

    memset (ds, 0, sizeof (ds));

    for (; *s; ++s) {
        if ((p = strchr(begin, *s)) != NULL)
            ++ds [p - begin];
        else if ((p = strchr(end, *s)) != NULL) {
            if (--ds [p - end] < 0)
                return 0;
        }
    }

    for (i = 0; i < 3; ++i) {
        if (ds[i] > 0)
            return 0;
    }
    return 1;
}

void solution2 () {

    char s[99];

    printf("\nEnter the sequence: ");
    scanf("%s", s);

    puts(brace(s) ? "Correct sequence" : "Incorrect sequence");
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
