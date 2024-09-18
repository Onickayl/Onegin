#include <stdio.h>
#include <string.h>
#include <TXLib.h>
#include <ctype.h>



// разбиение на функции и файлы. ассерты


int My_strcmp(char* array[7]);


// Возвращает true, если с - буква:   int isalpha(int с);


int main()
{
   // int if_letter = 0;

    FILE *file = fopen("Onegin.txt", "r");

    if (file == NULL)
    {
        perror("Ошибка при открытии файла");
        return 1;
    }


    // создаю массив указателей array

    char* array[7] = {};


    printf("Исходник\n");

    // read file and full of array

    for(int i = 0; i < 7; i ++)
    {
        char* buffer = (char*) calloc(500, sizeof(char));
        fgets(buffer, 500, file);

        printf("%s", buffer);

        array[i] = buffer;

    }

    printf("\n\n");

    char* free_str = "";

    for(int j = 0; j < 7; j ++)
    {
        for(int i = 0; i < 6; i ++)
        {
            if(My_strcmp(array) > 0)        // my_strcmp
            {
                free_str = array[i+1];
                array[i+1] = array[i];
                array[i] = free_str;
            }
        }
    }



    // отсортированный текст

    printf("Отсортированный\n");
    for(int j = 0; j < 7; j ++)
        printf("%s", array[j]);


    fclose(file);
    return 0;

}




int My_strcmp(char* array[7])
{

    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 100; j++)
        {
            array[i][j] = tolower(array[i][j]);     // small letters


            int if_letter = isalpha(array[i][j]);

            if (if_letter == 0)
            {
                for(int k = 0; k < 100; ++k)
                {
                    array[i][k - 1] = array[i][k];
                }
            }
        }
    }



    for(int i = 0; i < 7; i++)
    {
        int compare = strcmp(array[i], array[i+1]);
        return compare;
    }

}

