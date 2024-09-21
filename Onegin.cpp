#include <stdio.h>
#include <string.h>
#include <TXLib.h>
#include <ctype.h>


struct Arr_Ptr        // i need copy!
{
    char* ptr[3] = {};   //7
};



// разбиение на функции и файлы. ассерты


int My_strcmp(Arr_Ptr arr, int num_str, int num_next_str);
Arr_Ptr Permutator_str(Arr_Ptr* array);
void Output(Arr_Ptr* array);
Arr_Ptr* Write_in_array(FILE* file, Arr_Ptr* array);
Arr_Ptr Enchantix(Arr_Ptr* arr, int num_str);


int main()
{
    FILE *file = fopen("Onegin.txt", "r");

    if (file == NULL)
    {
        perror("Ошибка при открытии файла");
        return 1;
    }

   // printf("%p - array_main\n", array);
    //printf("%p - &array_main\n", &array);

    Arr_Ptr array;

    // read file and full of array
    Write_in_array(file, &array);

    //printf("%p - after read array_main\n", array);
    //printf("%p - after read &array_main\n", &array);

    printf("Исходник\n");
    Output(&array);


    printf("\n\n");


    // перестановщик
    Permutator_str(&array);


    printf("Отсортированный\n");
    Output(&array);


    fclose(file);
    return 0;

}


int My_strcmp(Arr_Ptr arr, int num_str, int num_next_str)
{


    //printf("first_str = %s\n", array.ptr[num_str]);
    //printf("second_str = %s\n", array.ptr[num_next_str]);


    Enchantix(&arr, num_str);


    Enchantix(&arr, num_next_str);

   // printf("%p - array_my\n", array);
    //printf("%p - &array_my\n", &array);

    int compare = strcmp(arr.ptr[num_str], arr.ptr[num_next_str]);
    return compare;

}

Arr_Ptr Permutator_str(Arr_Ptr* array)
{


    Arr_Ptr arr;


    for(int i = 0; i < 3; i++)    //7
    {
        arr.ptr[i] = array->ptr[i];
    }

    for(int i = 0; i < 3; i++)    //7
    {
        printf("%s\n", arr.ptr[i]);
    }

   /* printf("%p - array_per\n", array);
    printf("%p - &array_per\n", &array);
    printf("%p - *array_per\n", *array);
    printf("%p - arr_per\n", arr);
    printf("%p - &arr_per\n", &arr);
   // printf("%p - ptr[]", array->ptr[]);
    printf("%p - array->ptr\n", array->ptr);
    //printf("%p - *ptr[]", array->ptr[]);    */

    char* free_str = "";

    for(int j = 0; j < 3; j++)          //7
    {
        for(int i = 0; i + 1 < 3 ; i++)        //6
        {
            //printf("array[i] = %s\n", array->ptr[i]);
            //printf("array[i+1] = %s\n", array->ptr[i+1]);

            if(My_strcmp(arr, i, i+1) > 0)
            {
                printf ("SWAP\n");
                free_str = array->ptr[i+1];
                array->ptr[i+1] = array->ptr[i];
                array->ptr[i] = free_str;
            }
        }
    }

    return *array;
}

void Output(Arr_Ptr* array)
{
    for(int i = 0; i < 3; i++)    //7
    {
        printf("%s\n", array->ptr[i]);
    }
}


Arr_Ptr* Write_in_array(FILE* file, Arr_Ptr* array)
{

    for(int i = 0; i < 3; i++)   //7
    {
        char* buffer = (char*) calloc (500, sizeof(char));      // null

        if (buffer == NULL)
        {
            puts("He удалось выделить память. Программа завершена.");
            return 0;
        }

        fgets(buffer, 500, file);

        array->ptr[i] = buffer;

    }

    return array;
}


Arr_Ptr Enchantix(Arr_Ptr* arr, int num_str)
{

    for(int times = 0; times < 85; times++)
    {
        for(int i = 0; i < 85; i++)
        {
            arr->ptr[num_str][i] = tolower(arr->ptr[num_str][i]);     // small letters

            int if_letter = isalpha(arr->ptr[num_str][i]);

            int k = i;

            if (if_letter == 0)
            {
                for(k; k+1 <= 85; k++)
                    arr->ptr[num_str][k] = arr->ptr[num_str][k+1];
            }
        }
    }

    return *arr;

}
