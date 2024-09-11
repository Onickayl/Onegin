#include <stdio.h>
#include <string.h>

int main()
{

    char s4[] = "la";
    char s5[] = "ab";

    char s1 = 'a';
    char s2 = 'b';
    char s3 = 'l';

    printf("%d %d %d\n", s1, s2, s3);

    int r = strcmp(s4, s5);

    int m = s4[0] - s5[0];

    printf("%d", m);


    return 0;
}
