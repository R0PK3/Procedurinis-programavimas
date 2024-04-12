
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define LINE_LENGTH 255

void longest_word_in_line(FILE *input, FILE *output);

int main(int argc, char *argv[])
{
    FILE *input;
    FILE *output;

    char fileName[30];

    if(argc == 1)
    {
        while(1)
        {
            printf("Provide data file name:");
            scanf("%s",fileName);

            input = fopen(fileName,"r");
            output = NULL;

            if(input != NULL)
            {
                break;
            }
        }
    }
    if(argc == 2)
    {
        input = fopen(argv[1],"r");
        output = NULL;
    }
    if(argc > 2 && input == NULL)
    {
        return 0;
    }
    if(argc == 3)
    {
        input = fopen(argv[1],"r");
        output = fopen(argv[2], "w");
    }

    fprintf(output,"The results are:\n");

    longest_word_in_line(input,output);

    fclose(input);
    fclose(output);

    return 0;
}


void longest_word_in_line(FILE *input, FILE *output)
{
    char longest[BUFFER_SIZE];
    int wlen = 0, max_wlen = 0, index = 0, counter = 1;


    char *array = (char*) malloc (BUFFER_SIZE * sizeof(char));


        while(fgets(array, LINE_LENGTH+1, input))
        {
            int overflow = 1;
            if(strcspn(array, "\n") != strlen(array))
            { // if '\n' IS in line
                array[strcspn(array, "\n")] = 0;
                overflow = 0;
            }

        if(overflow)
        {
            int c;
            // if overflow was detected, other symbols from same line will be ignored
            while((c = fgetc(input)) != '\n' && c != EOF)
                continue;
        }

            wlen = 0; max_wlen = 0; index = 0;

            int h = strlen(array);

        for(int i = 0; i <= h; i++)
        {
            if(array[i] != ' ' && array[i] != '\0' && array[i] != '\n')
            {
                wlen++;

                continue;
            }
            if( wlen > max_wlen)
            {
                max_wlen = wlen;
                index = i - max_wlen;
                counter++;
            }
                wlen = 0;

            for(int i = 0; i < max_wlen; i++)
            {
                longest[i] = array[index + i];

            }
        }

            longest[max_wlen] = '\0';

        if(output == NULL)
        {
            printf("%s\n",longest);
        }
        else
        {
            fprintf(output,"%s\n",longest);
        }
    }

    free(array);
}
