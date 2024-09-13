#include <stdio.h>
#include <string.h>
#include <TXLib.h>


int main()
{

    FILE *file = fopen("Onegin.txt", "r");

    if (file == NULL)
    {
        perror("ќшибка при открытии файла");
        return 1;
    }

    char* array[7] = {};


    for(int i = 0; i < 7; i ++)
    {
        char* buffer = (char*) calloc(500, sizeof(char));
        fgets(buffer, 500, file);     // len of string <= 500
        //printf("%p ", buffer);   // адрес, что лежит в €чейке buff
        //printf("%p ", &buffer); // адрес €чейки buff
        //printf("%d ", *buffer);   // код первой буквы строки
        //printf("%c\n", *buffer);        // печатает букву
        //printf("%s", buffer);     // печатает строку
        array[i] = buffer;
        //printf("%c\n", *array[i]);    // буква
        //printf("%p\n", array[i]);
    }

    for(int i = 0; i < 7; i ++)
        printf("%s", array[i]);





    // getchar()


    // сортировка по алфавиту
    // strcmp() - сравнение, возвращает разницу чисел > 0 первое больше, < 0 второе больше



    fclose(file);
    return 0;
}
