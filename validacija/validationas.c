#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main()
{
    int number = 1;

    bool isPrime = false;

    printf("Please enter a number in order to determine whether it is a prime number \n");

    while (number != 0)
        {
            if (scanf("%9d", &number) && isspace(getchar()))
            {
                if (number > 1)
                {

                    for (int i = 2; i <= number; ++i)
                    {
                        if (number % i == 0)
                        {
                            if (i == number)
                            {
                                printf("%d is a prime number\n", number);
                                isPrime = true;
                            }
                            else
                            {
                                isPrime = false;
                                printf("%d is not a prime number\n", number);
                                break;
                            }

                        }
                    }

                    if(!isPrime)
                    {
                        int lower, higher;
                        int temporary = number - 1;

                        while(temporary)
                        {
                            for(int i = 2; i <= temporary; i++)
                            {
                                if(temporary % i == 0)
                                {
                                    if(i == temporary)
                                    {
                                        lower = temporary;
                                        temporary = 1;
                                        break;
                                    }
                                    else break;
                                }
                            }
                            temporary--;
                        }

                        temporary = number;

                        while(temporary)
                        {
                            for(int i = 2; i <= temporary; i++)
                            {
                                if(temporary % i == 0)
                                {
                                    if(i == temporary)
                                    {
                                        higher = temporary;
                                        temporary = -1;
                                        break;
                                    }
                                    else break;
                                }
                            }
                            temporary++;
                        }
                        if (abs(number - higher) < number - lower)
                        {
                            printf("%d is the nearest prime number to %d\n", higher, number);
                        }
                        else if (abs(number - higher) > number - lower)
                        {
                            printf("%d is the nearest prime number to %d\n", lower, number);
                        }
                        else if (abs(number - higher) == number - lower)
                        {
                            printf("%d and %d are the nearest prime numbers to %d\n", higher, lower, number);

                        }
                    }
                }
                else if (number == 1)
                {
                    printf("%d is not prime, closest prime is 2\n", number);
                }
                else if (number == 0)
                {
                    printf("Program finished\n");

                    break;
                }
                else if (number < 0)
                {
                    printf("Bad input %d\n", number);
                }

            }
            else
            {
                printf("Bad input\n");

                number = 1;

                while (!isspace(getchar()))
                    ;
            }
    }
    return 0;
}
