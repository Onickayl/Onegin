// ���������

// fgetc() - ������ �� ���������
/*
    int ch;
    while ((ch = fgetc(file)) != EOF)
    {
        putchar(ch); // ����� ������� �� �����
    }
*/


// fgets() - ������ �� �������

/*
    char buffer[7];
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("%s", buffer); // ����� ������ �� �����
    }
*/


#include <stdio.h>
#include <TXLib.h>
#define STLEN 10
int main(void)
{
    char words[STLEN];
    puts("������� ������ (��� ������ ������ ��� ������ �� ���������):");
    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
        fputs(words, stdout);
    puts("Ready.");
    return 0;
}
