// Robertas Buračevskis, namų darbų 12 užduotis, apskaičiuojanti skaičių seką.
// VU MIF 1 kursas, 1 grupė, 1 pogrupis.

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_NUMBER 9999999
#define MIN_NUMBER -9999999

int main()
{
    int integer;
    int counter;
    bool fill = true;

    printf("Si programa isveda sekos narius iki pirmojo vieneto.\n"
           "Programa sekos elementus skaiciuoja taip:\nXn+1 = Xn/2 (jei lyginis) ir 3Xn+1 (jei nelyginis)\n"
           "Jei norite pradeti, iveskite sveikaji skaciu X0, kuri sudaro ne daugiau nei 7 skaitmenys:\n");

    while(fill)
    {
        if(scanf("%d", & integer) && isspace(getchar()))
        {
            counter = 1;

            if (integer == 1)
            {
                printf("Jusu seka baigta!\nPrograma baigia darba.\n");

                break;
            }

            printf("----------\nRezultatai:\n");


            while(integer != 1)
            {
                if((integer > MAX_NUMBER) || (integer < MIN_NUMBER))
                {
                    printf("Sis skaicius turi daugiau nei 7 skaitmenis! Iveskite sveikaji skaiciu, kuris turi ne daugiau nei 7 skaitmenis:\n");
                    break;
                }
                if(integer == 0)
                {
                    printf("Sis skaicius nera nei lyginis nei nelyginis, pabandykite ivesti kita sveika skaiciu:\n");
                    break;
                }
                if(integer < 0)
                {
                    printf("Si skaiciu seka yra begaline\nIveskite kitokia sveikojo skaiciaus reiksme:\n");
                    break;
                }
                if((integer % 2) == 0)
                {
                    integer = integer / 2;
                    printf("X_%d=%d\n",counter,integer);
                    ++counter;
                }
                else
                {
                    integer = (3 * integer) + 1;
                    printf("X_%d=%d\n",counter,integer);
                    ++counter;
                }
            }

            printf("----------\n");
        }
        else
        {
             printf("Bloga ivestis, iveskite sveikaji skaiciu, kuri sudaro ne daugiau nei 7 skaitmenys!\n");

             while(!isspace(getchar()))
                    ;
        }
    }
    return 0;
}
