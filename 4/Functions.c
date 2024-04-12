/* Itraukiamos reikalingos bibliotekos ir header failas */
#include<stdio.h>
#include<stdlib.h>
#include "Functions.h"

void Create_singly_linked_list(List **front, int new_data) /* Funckija, skirta sarasu sukurimui (duomenu patalpinimui i struktura) */
{
    List *new_linked_list = (List*)malloc(sizeof(List)); /* Naujam sarasui isskiriama vieta atmintyje */
    new_linked_list -> data = new_data; /* I sarasa patalpinami duomenys*/
    new_linked_list -> next = *front; /* Naujo saraso strukturoje esanciai rodyklei next priskirta rodykles front reiksme*/
    *front = new_linked_list; /* Rodykles front reiksme pakeiciama, kad ji rodytu i naujo saraso struktura*/
}

void Reverse_list(List **front) /* Funkcija, kuri sarasa perraso atvirkscia tvarka */
{
    List *previous = NULL; /* Rodyklei previous suteikiama reiksme NULL */
    List *current = *front; /* Rodyklei current suteikiamas *front reiksme */
    List *next; /* Sukuriama rodykle next */
    while (current != NULL) /* Ciklas, kuris keicia sarasa iki tol, kol current netampa Null */
    {
        next = current -> next; /* Inicializuojama next reiksme, jai priskiriama current strukturos reiksme next */
        current -> next = previous; /* Inicializuojama strukturos reiksme next, jai priskiriama previous reiksme */
        previous = current; /* Previous reiksmei priskiriama current reiksme */
        current = next; /* Current reiksmei priskiriama next reiksme */
    }
    *front = previous; /* Rodyklei front priskiriama previous reiksme */
}

void Print_list(List *front) /* Funkcija, skirta saraso atspausdinimui */
{
    List *current = front; /* Sukuriama rodykle i struktura current, kuriai priskiriama reiksme front */

    while(current != NULL) /* Ciklas veikia iki tol, kol pasiekiama saraso pabaiga, t.y. kol current netampa NULL */
    {
        printf("%d ", current -> data); /* Spausdinami saraso duomenys esantys data kintamajame */
        current = current -> next; /* Rodyklei current priskiriama nuoroda i sekancia saraso struktura */
    }
}

void Free_memory(List *new_linked_list) /* Funkcija, kuri atlaisvina uzimta atminties vieta */
{
    free(new_linked_list); /* Atlaisvinama atmintis */
}
