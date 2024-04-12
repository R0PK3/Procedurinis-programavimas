#include <stdio.h>
#include <math.h>
int main()
{
    int numbers, counter, counter_temp1, counter_temp2;             //variables
    int temp1, temp2;

                                                                        //user interface
    printf("This program determine whether entered number is prime.\n"
           "If it's not, then program says that entered number is not a prime and output the nearest prime number(s).\n"
           "If you want to end program, enter 0.\n"
           "Now, please enter the positive integer (up to 9 digits):");



    while(1)
    {
       if (scanf("%9d", &numbers) && isspace(getchar()))        //validation
       {
            counter = 1;

            temp1 = numbers - 1; temp2 = numbers + 1;

            if(numbers < 0)                                                   //result output
            {
                printf("Bad input\nPlease enter a positive integer (up to 9 digits):\n");

                while (!isspace(getchar()))
                    ;
            }
            if(numbers == 0)
            {
                printf("Program finished!\n");

                break;
            }

            for(int i = 1; i <= floor(sqrt(numbers)); ++i)              //calculating the dividers
            {
                if(numbers % i == 0)
                {
                    counter++;
                }
            }

            if(numbers == 1)
            {
                printf("Entered number: %d is composite. Nearest prime number is 2.\n",numbers);     //result output
            }
            else if(numbers == 2)
            {
                printf("Entered number: %d is prime.\n", numbers);
            }
            else if(counter == 2)
            {
                printf("Entered number: %d is prime.\n",numbers);
            }
            else if (counter > 2)
            {
                while(1)
                {

                    counter_temp1 = 1; counter_temp2 = 1;                       //calculating the dividers if entered number is composite

                    for(int i = 1; i <= floor(sqrt(temp1)); ++i)
                    {
                        if( temp1 % i == 0)
                        {
                            counter_temp1++;
                        }
                    }

                    for(int i = 1; i <= floor(sqrt(temp2)); ++i)
                    {
                        if( temp2 % i == 0)
                        {
                            counter_temp2++;
                        }
                    }

                    if((counter_temp1 == 2) || (counter_temp2 == 2))
                    {
                        if((counter_temp1 == 2) && (counter_temp2 == 2))
                        {
                            if((numbers - temp1 ) < (temp2 - numbers))                              //result output
                            {
                                printf("Entered number: %d is composite. Nearest prime number is: %d\n",numbers,temp2);
                            }
                            if((temp2 - numbers) < (numbers - temp1))
                            {
                                printf("Entered number: %d is composite. Nearest prime number is: %d\n",numbers,temp1);
                            }
                            else
                            {
                                printf("Entered number: %d is composite. Nearest prime numbers are: %d and %d\n",numbers,temp1,temp2);
                            }
                        }
                        else if(counter_temp1 < counter_temp2)
                        {
                            printf("Entered number: %d is composite. Nearest prime number is: %d\n",numbers,temp1);
                        }
                        else
                        {
                            printf("Entered number: %d is composite. Nearest prime number is: %d\n",numbers,temp2);
                        }

                        break;
                    }
                    else
                    {
                        temp1 = temp1 - 1;        //increasing numbers
                        temp2 = temp2 + 1;
                    }

                }

            }
       }
       else
       {
           printf("Bad input\nPlease enter a positive integer (up to 9 digits):\n");   //validation

           while (!isspace(getchar()))
                    ;
       }
    }

    return 0;
}



