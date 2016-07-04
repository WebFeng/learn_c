#include <stdio.h>

int strlen1(char *p);

int main()
{
    char *s = "abcdef";
    printf("strlen:%d\n", strlen1(s));
}

int strlen1(char *s)
{
    char *p = s;
    while (*p != '\0')
        p++;
    return p - s;
}