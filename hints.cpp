// подсказки

// fgetc() - читает по символьно
/*
    int ch;
    while ((ch = fgetc(file)) != EOF)
    {
        putchar(ch); // Вывод символа на экран
    }
*/


// fgets() - читает по строчно

/*
    char buffer[7];
    while (fgets(buffer, sizeof(buffer), file) != NULL)
    {
        printf("%s", buffer); // Вывод строки на экран
    }
*/


#include <stdio.h>
#include <TXLib.h>
#define STLEN 10
int main(void)
{
    char words[STLEN];
    puts("Введите строки (или пустую строку для выхода из программы):");
    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
        fputs(words, stdout);
    puts("Ready.");
    return 0;
}
