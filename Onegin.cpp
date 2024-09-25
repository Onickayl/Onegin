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
char* Enchantix(Arr_Ptr* arr, int num_str);


// MAIN//////////////////////////////////////////////////////////////////////////////////////

int main()
{
    FILE *file = fopen("Onegin.txt", "r");

    if (file == NULL)
    {
        perror("Ошибка при открытии файла");
        return 1;
    }

    Arr_Ptr array;

    printf("%p - &array_main\n", &array);


    // read file and full of array
    Write_in_array(file, &array);


    printf("\n\n");
    printf("%p - after read array_main\n", array);
    printf("%p - after read &array_main\n", &array);

    printf("Исходник\n");
    Output(&array);


    printf("\n\n");
    printf("%p - before per array_main\n", array);
    printf("%p - before per &array_main\n", &array);

    // перестановщик
    Permutator_str(&array);

    printf("\n\n");
    printf("%p - after per array_main\n", array);
    printf("%p - after per &array_main\n", &array);

    printf("\n\n");
    printf("Отсортированный\n");
    Output(&array);


    fclose(file);
    return 0;

}

// WRITE_IN_ARRAY//////////////////////////////////////////////////////////////////////////////

Arr_Ptr* Write_in_array(FILE* file, Arr_Ptr* array)
{

    assert (file != 0);
    assert (array != 0);

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

    //printf("array1(w) = %p\n", array);
    //printf("*array1(w) = %p\n", *array);

    return array;
}

// PERMUTATOR//////////////////////////////////////////////////////////////////////////////////////////////

Arr_Ptr Permutator_str(Arr_Ptr* array)
{
    assert (array != 0);

    printf("\n\n");
    printf("%p - array_per\n", array);
    printf("%p - *array_per\n", *array);
    //printf("%p - array->ptr\n", array->ptr);
    //printf("%p - *(array->ptr)\n", *(array->ptr));


    char* free_str = "";

    for(int j = 0; j < 3; j++)          //7
    {
        for(int i = 0; i + 1 < 3 ; i++)        //6
        {
            //printf("array[i] = %s\n", array->ptr[i]);
            //printf("array[i+1] = %s\n", array->ptr[i+1]);

            int res_strcmp = My_strcmp(*array, i, i+1);

            //printf("%d\n", res_strcmp);

            if(res_strcmp > 0)
            {
                printf ("SWAP\n");
                free_str = array->ptr[i+1];
                array->ptr[i+1] = array->ptr[i];
                array->ptr[i] = free_str;
            }
        }
    }


    printf("\n\n");
    printf("%p - after array_per\n", array);
    printf("%p - after *array_per\n", *array);

    return *array;
}


//MY_STRRCMP////////////////////////////////////////////////////////////////////////////////////////////////////////

int My_strcmp(Arr_Ptr array, int num_str, int num_next_str)
{

    printf("\n\n");
    printf("%p - MY &array\n", &array);
    printf("%p - MY array\n", array);


    char* first_str = Enchantix(&array, num_str);



    printf("\n\n");
    printf("first_str = %s\n", first_str);
    printf("first_str = %s\n", array.ptr[num_str]);



    char* second_str = Enchantix(&array, num_next_str);


    printf("\n\n");
    printf("second_str = %s\n", second_str);
    printf("second_str = %s\n", array.ptr[num_next_str]);


    int compare = strcmp(array.ptr[num_str], array.ptr[num_next_str]);



    printf("\n\n");
    printf("%p - after MY &array\n", &array);
    printf("%p - after MY array\n", array);
    printf("%d", compare);

    return compare;

}


// ENCHANTIX//////////////////////////////////////////////////////////////////////////////////////////////////////

char* Enchantix(Arr_Ptr* array, int num_str)
{
    assert (array != 0);

    printf("\n\n");
    printf("%p - EN array\n", array);
    printf("%p - EN *array\n", *array);

    for(int times = 0; times < 85; times++)
    {
        for(int i = 0; i < 85; i++)
        {
            array->ptr[num_str][i] = tolower(array->ptr[num_str][i]);     // small letters

            int if_letter = isalpha(array->ptr[num_str][i]);

            int k = i;

            if (if_letter == 0)
            {
                for(k; k+1 <= 85; k++)
                    array->ptr[num_str][k] = array->ptr[num_str][k+1];
            }
        }
    }

    //printf("\n\n");
    //printf("%s\n", array->ptr[num_str]);

    return array->ptr[num_str];

}

void Output(Arr_Ptr* array)
{
    assert (array != 0);

    for(int i = 0; i < 3; i++)    //7
    {
        printf("%s\n", array->ptr[i]);
    }
}
