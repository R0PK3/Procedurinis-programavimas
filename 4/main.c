/* Autorius: Robertas Buracevskis
VU, MIF, PS1, 1 kursas, 1 grupe, 1 pogrupis, 4 skyrius, 7 uzduotis
*/

#include<stdio.h> /* Itraukiamos reikalingos bibliotekos ir header failas */
#include<stdlib.h>
#include "Functions.h"
#include <assert.h>
#include <ctype.h>

#define MAX_LIST_SIZE 10
#define ZERO 0
#define MAX_DATA_SIZE 99999
#define MIN_DATA_SIZE -99999

void main_1(); /* Funkcijos deklaravimas */
void main_2(); /* Funkcijos deklaravimas */

int main()    /* Pagrindine funkcija */
{
     //main_1();
     main_2();


     return 0;
}

void main_1() /* Funkcijos apibrezimas */
{
     List *front = NULL; /* Pirmosios strukturos rodykle nukreipta i NULL*/

     Create_singly_linked_list(&front, 1); /* Duodami duomenys sarasui */

     assert(front -> data == 1); /* Tikrinamas gautas rezultatas (ar jis toks, kokio tikimasi) */

     Create_singly_linked_list(&front, 2);

     assert(front -> data == 2);

     Create_singly_linked_list(&front, 15);

     assert(front -> data == 15);

     Create_singly_linked_list(&front, 35);

     assert(front -> data == 35);

     Create_singly_linked_list(&front, 945654);

     assert(front -> data == 945654);

     Create_singly_linked_list(&front, 858940);

     assert(front -> data == 858940);

     Create_singly_linked_list(&front, 0);

     assert(front -> data == 0);


     printf("Sukurto saraso duomenys:\n"); /* Spausdinamas gautas sarasas */
     Print_list(front);
}

void main_2() /* Funkcijos apibrezimas */
{
     int length; /* Sukuriamas length kintamasis int duomenu tipo, kuris savyje saugos saraso ilgi */
     int numbers[MAX_LIST_SIZE] = {0}; /* Sukuriamas masyvas, kuris savyje saugos vartotojo ivestus duomenis, skirtus sarasui */
     int status; /* Status flag'as, naudojamas validacijai */

     List *front = NULL; /* Pirmojo saraso nario rodykle nukreipta i NULL */
     Ui(); /* Krepimasis i Ui funkcija */

     status = scanf("%d",&length); /* Nuskaitomi duomenys ir priskiriamas status flag (0 arba 1) */

     while((status != 1) || (length > MAX_LIST_SIZE) || (length <= ZERO) || (!isspace(getchar()))) /* Ciklas, skirtas validacijai */
     {
         Validation();
         status = scanf("%d",&length);
     }

     Continue(length); /* Kreipinys i funkcija Continue, jam paduodami length reiksme*/

     for(int i = 0; i < length; ++i) /* Ciklas, skirtas vartoto duomenu validacijai */
     {
         status = scanf("%d",&numbers[i]);

         while((status != 1) || (numbers[i] > MAX_DATA_SIZE) || (numbers[i] < MIN_DATA_SIZE) || (!isspace(getchar())))
         {
             Validation_2();
             status = scanf("%d",&numbers[i]);
         }
     }

     for(int i = 0; i < length; ++i)  /* Ciklas, kuris kreipiasi i saraso kurimo funkcija */
     {
         Create_singly_linked_list(&front, numbers[i]);
     }

     printf("Sukurto saraso duomenys:\n");
     Print_list(front);  /* Kreipinys i saraso isspausdinimo funkcija */
     Reverse_list(&front); /* Kreipinis i saraso pertvarkymo funkcija */
     printf("\nApdoroto saraso duomenys:\n");
     Print_list(front); /* Kreipinys i saraso isspausdinimo funkcija */
}
