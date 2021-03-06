#include <stdio.h>

int main()
{
//注释 // 或 /* */
//while简写
    while (0)
        printf("do while\n");
//整数除法舍位 5/9 == 0, int与float的运算会自动先把int转换成float
//printf说明
    printf("%6f", 1.23);     //打印宽度为6,不输出小数
    printf("%.1f", 1.23);    //打印宽度不限制,输出1位小数
    printf("%6.1f", 1.23);   //打印宽度为6,输出1位小数
    //%%  %
    //%o  八进制
    //%x  十六进制
    //%c  字符
    //%s  字符串
//for语句先执行循环体,在自增
    for (i = 0; i < 10; i++)
        printf("先打印, 再i++");
//符号常量 #define NAME Tom 替换非字符串中所有出现NAME的位置,没有";"作为语句结束
//文本流:一个或多个字符,以"\n"结束
//getchar从文本流获取一个字符
//putchar输入一个字符
//从输入复制到输出
    int c; //声明为int是因为c要足够大以存储EOF
    while ((c = getchar()) != EOF)
        putchar(c);
//幂函数pow(x,y) x^y
//调用自定义函数需要预先声明,函数参数声明可以省略,例如
    int power([int base, int n]);
//数组参数按引用传递,为数组首元素地址
//内存泄漏:不使用的内存没有free释放,导致无法再次被分配
//内存溢出:访问未被分配的内存地址空间
//'\0'代表字符串结束
//外部变量和函数的extern通常定义在单独的.h头文件中,在函数内部使用外部变量时用extern char line[]声明
//外部变量在定义时就由编译器分配了内存地址
//外部变量的定义 & 使用时的声明 在同一个文件中时,且定义在声明之前,则可以省略extern声明
//外部变量需要谨慎使用,会增加程序的耦合
}