#include <stdio.h>
#include <string.h>
#include <TXLib.h>



// А может все маленькие:   int tolower(int с);

// Возвращает true, если с - буква:   int isalpha(int с);


int main()
{

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
        fgets(buffer, 500, file);     // len of string <= 500

        //printf("%p ", buffer);   // адрес, что лежит в ячейке buff
        //printf("%p ", &buffer); // адрес ячейки buff

        //printf("%d ", *buffer);   // код первой буквы строки
        //printf("%c\n", *buffer);        // печатает букву

        printf("%s", buffer);

        // превращение в маленькие
        for(int k = 0; k < 500; k++)
        {
            buffer[k] = tolower(buffer[k]);
            //printf("%c ", buffer[k]);
        }


        //printf("%s", buffer);     // печатает строку

        array[i] = buffer;

        //printf("%c\n", *array[i]);    // буква
        //printf("%p\n", array[i]);
    }


    printf("\n\n");

    // исходный текст

    printf("Маленькие\n");
    for(int j = 0; j < 7; j ++)
        printf("%s", array[j]);

    // текст в больших буквах

    //int toupper(int *buffer);

    // сортировка

    char* free_str = "";


    for(int j = 0; j < 7; j ++)
    {
        for(int i = 0; i < 6; i ++)
        {
            if(strcmp(array[i], array[i+1]) > 0)
            {
                free_str = array[i+1];
                array[i+1] = array[i];
                array[i] = free_str;
            }
        }
    }

    printf("\n\n");


    // отсортированный текст
    printf("Отсортированный\n");
    for(int j = 0; j < 7; j ++)
        printf("%s", array[j]);


    fclose(file);
    return 0;

}





    // getchar()


    // сортировка по алфавиту
    // strcmp() - сравнение, возвращает разницу чисел > 0 первое больше, < 0 второе больше
