#include <stdio.h>
#include <string.h>
#include <TXLib.h>
#include <ctype.h>


struct arr_prt
{

};



// разбиение на функции и файлы. ассерты


int My_strcmp(char* first_str, char* second_str);


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

    char* array[3] = {};       //7



    // read file and full of array

    for(int i = 0; i < 3; i++)   //7
    {
        char* buffer = (char*) calloc (500, sizeof(char));      // null
        fgets(buffer, 500, file);

        array[i] = buffer;

    }

    printf("Исходник\n");
    for(int i = 0; i < 3; i++)    //7
    {
        printf("%s", array[i]);
    }

    printf("\n\n");

    char* free_str = "";

    for(int j = 0; j < 3; j++)          //7
    {
        for(int i = 0; i + 1 < 3 ; i++)        //6
        {
            printf("array[i] = %s\n", array[i]);
            printf("array[i+1] = %s\n", array[i+1]);


            if(My_strcmp(array[i], array[i + 1]) > 0)        // my_strcmp
            {
                //printf("%d %d\n", i, j);
                printf ("SWAP\n");
                free_str = array[i+1];
                array[i+1] = array[i];
                array[i] = free_str;
            }
        }
    }



    // отсортированный текст

    printf("Отсортированный\n");
    for(int j = 0; j < 3; j ++)     //7
        printf("%s\n", array[j]);


    fclose(file);
    return 0;

}




int My_strcmp(char* first_str, char* second_str)
{

    printf("first_str = %s\n", first_str);
    printf("second_str = %s\n", second_str);


    for(int times = 0; times < 85; times++)
    {
        for(int i = 0; i < 85; i++)
        {
            first_str[i] = tolower(first_str[i]);     // small letters

            int if_letter = isalpha(first_str[i]);

            int k = i;

            if (if_letter == 0)
            {
                for(k; k+1 <= 85; k++)
                    first_str[k] = first_str[k+1];
            }
        }
    }

 /*   0 1 2 3 4 5 6 7
    - T o o   ? M U
    0 1 1 1 0 0 1 1
    - t o o   ? m u
1)  t o o   ? m u
4)  t o o ? m u      */



    for(int times = 0; times < 85; times++)
    {
        for(int i = 0; i < 85; i++)
        {
            second_str[i] = tolower(second_str[i]);     // small letters

            int if_letter = isalpha(second_str[i]);

            int k = i;

            if (if_letter == 0)
            {
                for(k; k+1 <= 85; k++)
                    second_str[k] = second_str[k+1];
            }
        }
    }


    int compare = strcmp(first_str, second_str);
    //printf("lala %d lala\n", compare);
    return compare;

}

