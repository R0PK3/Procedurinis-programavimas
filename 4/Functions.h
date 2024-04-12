/*Header failas */
#ifndef FUNCTIONS_H_INCLUDED /* Failo apsauga "guard'as" */
#define FUNCTIONS_H_INCLUDED


typedef struct Singly_linked_list /* Aprasoma  struktura, kurioje yra patalpinti duomenys ir nuoroda (adresas) i kita saraso struktura */
{
    int data; /* Int duomenu tipo kintamasis, kuriame saugomi ivesti duomenys */
    struct Singly_linked_list *next; /* Saraso elementas - nuoroda i kita saraso struktura */
} List; /* Strukturai suteiktas duomenu tipo vardas (strukturos sutrumpintas pavadinimas) */

void Create_singly_linked_list(List **front, int new_data); /* Funckija, skirta saraso sukurimui (duomenu patalpinimui i struktura) */
void Reverse_list(List **front); /* Funkcija, skirta perrasyti sarasa atvirkstine tvarka */
void Print_list(List *front); /* Funkcija, skirta sarasui atspausdinti */
void Ui(); /* Funkcija kuri isspausdina user interface */
void Bad_input(); /* Funkcija kuri isspausdina klaidos pranesima */
void Bad_input_2(); /* Funkcija, kuri isspausdina klaidos pranesima */
void Validation(); /* Funkcija, kuri skirta naudotojo ivedimo validaciajai */
void Validation_2(); /* Funkcija, kuri skirta naudoto ivedimo validacijai */
void Continue(int length); /* Funkcija, kuri skirta isspausdinti papildoma pranesima, ka toliau reikia vesti vartotojui */
void Free_memory(List *new_linked_list); /* Funkcija, kuri atlaisvina uzimta atminties vieta */



#endif // FUNCTIONS_H_INCLUDED
