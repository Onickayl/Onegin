#include <stdio.h>
#include <string.h>
#include <TXLib.h>
#include <ctype.h>


struct Arr_Ptr        // i need copy!
{
    char* ptr[3] = {};   //7
};



// разбиение на функции и файлы. ассерты


int My_strcmp(char* first_str, char* second_str);
Arr_Ptr Permutator_str(Arr_Ptr array);
void output(Arr_Ptr array);


int main()
{
    FILE *file = fopen("Onegin.txt", "r");

    if (file == NULL)
    {
        perror("Ошибка при открытии файла");
        return 1;
    }


    // создаю массив указателей array

    Arr_Ptr array;



    // read file and full of array

    for(int i = 0; i < 3; i++)   //7
    {
        char* buffer = (char*) calloc (500, sizeof(char));      // null

        if (buffer == NULL)
        {
            puts("He удалось выделить память. Программа завершена.");
            return 0;
        }

        fgets(buffer, 500, file);

        array.ptr[i] = buffer;

    }

    printf("Исходник\n");
    output(array);

    printf("\n\n");

    // перестановщик
    Permutator_str(array);


    // отсортированный текст

    printf("Отсортированный\n");
    output(array);


    fclose(file);
    return 0;

}




int My_strcmp(Arr_Ptr array, int i, int j)
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

Arr_Ptr Permutator_str(Arr_Ptr array)
{

    char* free_str = "";

    for(int j = 0; j < 3; j++)          //7
    {
        for(int i = 0; i + 1 < 3 ; i++)        //6
        {
            printf("array[i] = %s\n", array.ptr[i]);
            printf("array[i+1] = %s\n", array.ptr[i+1]);


            if(My_strcmp(array, i, i+1) > 0)        // my_strcmp
            {
                //printf("%d %d\n", i, j);
                printf ("SWAP\n");
                free_str = array.ptr[i+1];
                array.ptr[i+1] = array.ptr[i];
                array.ptr[i] = free_str;
            }
        }
    }

    return array;
}

void output(Arr_Ptr array)
{
    for(int i = 0; i < 3; i++)    //7
    {
        printf("%s\n", array.ptr[i]);
    }
}
