#include <stdio.h>

void strcpy1(char *s, char *t);
void strcpy2(char *s, char *t);
void strcpy3(char *s, char *t);
void strcpy4(char *s, char *t);

int main()
{
    char s[5], *t = "abcd";
    strcpy1(s, t);
    strcpy2(s, t);
    strcpy3(s, t);
    strcpy4(s, t);
    printf("s:%s\n", s);
}

void strcpy1(char *s, char *t)
{
    int i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}
void strcpy2(char *s, char *t)
{
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}
void strcpy3(char *s, char *t)
{
    while ((*s++ = *t++) != '\0')
        ;
}
void strcpy4(char *s, char *t)
{
    while ((*s++ = *t++))
        ;
}
