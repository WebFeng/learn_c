#include <stdio.h>
#include <stdlib.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

int main()
{
    int year;
    int month;
    int day;
    int yearday;

//指针必须初始化才能使用,未初始化指针指向的地址是不可用地址
/*
    int *pmonth = (int *)malloc(4);
    int *pday = (int *)malloc(4);
*/

    int *pmonth;
    int *pday;
    int month_, day_;
    pmonth = &month_;
    pday = &day_;


    year = 2016;
    month = 6;
    day = 30;
    yearday = 182;

    printf("%d-%d-%d is %dth day\n", year, month, day, day_of_year(year, month, day));
    month_day(year, yearday, pmonth, pday);
    printf("%d year %dth day is %d-%d-%d\n", year, yearday, year, *pmonth, *pday);
//手动malloc的内存地址必须手动释放
/*
    if (pmonth)
        free(pmonth);
    if (pday)
        free(pday);
*/
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
int day_of_year(int year, int month, int day)
{
    int i, leap;

    leap = (year%4 == 0 && year%100 != 0) || year %400 == 0;
    for (i = 1; i < month; i++)
        day += daytab[leap][i];
    return day;
}
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = (year%4 == 0 && year%100 != 0) || year %400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}