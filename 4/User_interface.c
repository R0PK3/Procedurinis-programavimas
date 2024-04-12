#include<stdio.h>
#include<stdlib.h>
#include "Functions.h"

#define ZERO 0
#define MAX_LIST_SIZE 10
#define MAX_DATA_SIZE 99999
#define MIN_DATA_SIZE -99999

void Ui() /* Funkcija kuri isspausdina user interface */
{
    printf("Sveiki, si programa nuskaito jusu ivestus (int duomenu tipo) duomenis bei sukuria vienpusi sarasa,\n"
           "kuri perraso atvirkstine tvarka. Noredami pradeti programos darba, iveskite naturaluji skaiciu n,\n"
           "kuris reiks jusu norimo saraso ilgi, jo reziai yra (0 iki %d].\n",MAX_LIST_SIZE);
}

void Bad_input() /* Funkcija kuri isspausdina klaidos pranesima */
{
    printf("Bloga ivestis! Prasome ivesti saraso ilgi n, kuris telpa i rezius (0 iki %d]!\n",MAX_LIST_SIZE);
}

void Bad_input_2() /* Funkcija kuri isspausdina klaidos pranesima */
{
    printf("Bloga ivestis! Prasome ivesti sveikuosius skaicius, kurie telpa i rezius [%d iki %d]!\n",MIN_DATA_SIZE,MAX_DATA_SIZE);
}

void Validation() /* Funkcija, kuri isspausdina klaidos pranesima */
{
    int temp;

    while(((temp = getchar()) != EOF) && (temp != '\n'));
    Bad_input();
}

void Validation_2() /* Funkcija, kuri isspausdina klaidos pranesima */
{
        int temp;

    while(((temp = getchar()) != EOF) && (temp != '\n'));
    Bad_input_2();
}

void Continue(int length) /* Funkcija, kuri skirta isspausdinti papildoma pranesima, ka toliau reikia vesti vartotojui */
{
    printf("Ivestis teisinga! Dabar iveskite %d sveikuju skaiciu (kurie bus skaitomi kaip saraso duomenys):\n", length);
}
