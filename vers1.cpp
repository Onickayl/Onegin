#include <stdio.h>
#include <string.h>


int main()
{
    const char* first_str = "My uncle keeps to honest systems: By falling ill yet not in jest,";
    const char* second_str = "He made me love him with insistence And couldn’t find some better test.";

    printf("%c - %d\n", first_str[0], first_str[0]);

    printf("%c - %d\n", second_str[0], second_str[0]);

    int m = first_str[0] - second_str[0];

    int cmp = strcmp(first_str, second_str);

    printf("%d %d\n", m, cmp);

    return 0;
}
