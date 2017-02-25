#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *inputFilepointer;
    FILE *outputFilepointer;
    char inputWord[100];
    char searchWord[] = "muhh";
    char changeWord[] = "maehh";
    int compareStrings = 0;

    printf("Hello world!\n");

    inputFilepointer = fopen("file.txt", "r");
    if(inputFilepointer == NULL)  // file pointer error handling
    {
        perror("\nERROR");
        fclose(inputFilepointer);
        inputFilepointer = NULL;
        exit(EXIT_FAILURE);
    }

    outputFilepointer = fopen("file_out.txt", "w");
    if(outputFilepointer == NULL)  // file pointer error handling
    {
        perror("\nERROR");
        fclose(outputFilepointer);
        outputFilepointer = NULL;
        fclose(inputFilepointer);
        inputFilepointer = NULL;
        exit(EXIT_FAILURE);
    }

    while(!feof(inputFilepointer))
    {
        fscanf(inputFilepointer, "%s", inputWord);
        inputWord[strlen(inputWord)] = '\0';
        printf("input %s\n", inputWord);

        while(1)
        {
            compareStrings = strncmp(inputWord, searchWord, strlen(inputWord));
            if(compareStrings == 0)
            {
                fprintf(outputFilepointer, "%s ", changeWord);
                printf("output changed %s \n", changeWord);
                break;
            }
            else
            {
                fprintf(outputFilepointer, "%s ", inputWord);
                printf("output as input %s \n", inputWord);
                break;
            }
        }
    }

    printf("check file_out.txt\n");

    fclose(inputFilepointer);
    fclose(outputFilepointer);


    return 0;
}
