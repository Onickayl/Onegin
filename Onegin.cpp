#include <stdio.h>
#include <string.h>
#include <TXLib.h>



// � ����� ��� ���������:   int tolower(int �);

// ���������� true, ���� � - �����:   int isalpha(int �);


int main()
{

    FILE *file = fopen("Onegin.txt", "r");

    if (file == NULL)
    {
        perror("������ ��� �������� �����");
        return 1;
    }


    // ������ ������ ���������� array

    char* array[7] = {};

    printf("��������\n");

    // read file and full of array

    for(int i = 0; i < 7; i ++)
    {
        char* buffer = (char*) calloc(500, sizeof(char));
        fgets(buffer, 500, file);     // len of string <= 500

        //printf("%p ", buffer);   // �����, ��� ����� � ������ buff
        //printf("%p ", &buffer); // ����� ������ buff

        //printf("%d ", *buffer);   // ��� ������ ����� ������
        //printf("%c\n", *buffer);        // �������� �����

        printf("%s", buffer);

        // ����������� � ���������
        for(int k = 0; k < 500; k++)
        {
            buffer[k] = tolower(buffer[k]);
            //printf("%c ", buffer[k]);
        }


        //printf("%s", buffer);     // �������� ������

        array[i] = buffer;

        //printf("%c\n", *array[i]);    // �����
        //printf("%p\n", array[i]);
    }


    printf("\n\n");

    // �������� �����

    printf("���������\n");
    for(int j = 0; j < 7; j ++)
        printf("%s", array[j]);

    // ����� � ������� ������

    //int toupper(int *buffer);

    // ����������

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


    // ��������������� �����
    printf("���������������\n");
    for(int j = 0; j < 7; j ++)
        printf("%s", array[j]);


    fclose(file);
    return 0;

}





    // getchar()


    // ���������� �� ��������
    // strcmp() - ���������, ���������� ������� ����� > 0 ������ ������, < 0 ������ ������
