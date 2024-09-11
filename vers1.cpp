#include <stdio.h>
#include <string.h>


int main()
{
    const char* first_str = "He made keeps to honest systems: By falling ill yet not in jest,";
    const char* second_str = "He made me love him with insistence And couldn’t find some better test.";
    const char* elem = "";

    printf("%s\n", first_str);

    printf("%s\n", second_str);


    if (int cmp = strcmp(first_str, second_str) < 0)
    {
        elem = second_str;
        second_str = first_str;
        first_str = elem;
    }

    printf("\n");

    printf("%s\n", first_str);

    printf("%s\n", second_str);

    return 0;
}
