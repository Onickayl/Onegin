#include <stdio.h>
#include <string.h>
#include <TXLib.h>


int main()
{

    FILE *file = fopen("Onegin.txt", "r");

    if (file == NULL)
    {
        perror("������ ��� �������� �����");
        return 1;
    }

    char* array[7] = {};


    for(int i = 0; i < 7; i ++)
    {
        char* buffer = (char*) calloc(500, sizeof(char));
        fgets(buffer, 500, file);     // len of string <= 500
        //printf("%p ", buffer);   // �����, ��� ����� � ������ buff
        //printf("%p ", &buffer); // ����� ������ buff
        //printf("%d ", *buffer);   // ��� ������ ����� ������
        //printf("%c\n", *buffer);        // �������� �����
        //printf("%s", buffer);     // �������� ������
        array[i] = buffer;
        //printf("%c\n", *array[i]);    // �����
        //printf("%p\n", array[i]);
    }

    for(int i = 0; i < 7; i ++)
        printf("%s", array[i]);





    // getchar()


    // ���������� �� ��������
    // strcmp() - ���������, ���������� ������� ����� > 0 ������ ������, < 0 ������ ������



    fclose(file);
    return 0;
}
