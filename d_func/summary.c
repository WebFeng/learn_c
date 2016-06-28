#include <stdio.h>
//可以把常量的定义,变量的声明,函数的声明统一放到单独的头文件中,在主文件引入头文件
#include "demo.h"
//#include "文件" 在源文件的目录查找文件
//#include <文件> 在系统目录查找头文件
//宏替换在编译时进行
//定义一个新的无限循环
#define forever for (;;)
//定义一个max, 但在max(i++, j++)时会出错
#define max(A, B) ((A) > (B) ? (A) : (B))
//取消宏定义, 则之后的使用函数getchar
#undefine getchar
int getchar(void) {//...}
//宏替换只能替换符号,不能替换文本,替换文本时需要'#'
#define dprint(expr) printf(#expr " = %g\n", expr)
//则drpint(x/y)展开为 printf("x/y" " = %g\n", x/y);
//宏替换参数名 '##'
#define paste(front, back) front ## back
//则paste(name, 1)的结果将建立记号 name1;##会自动删除左右空白.'##'替换详情很复杂,参见附录A
//条件包含,在编译时执行
#if !defined(HDR) //该代码实现仅仅包含一次,if后面可以是常量整形表达式,不是可以包含sizeof,类型转换符或enum
#define HDR
/* hdr.h 文件内容*/
#endif
//还有#ifdef #ifndef #endif

int main()
{
//库函数字符串查找
    strstr();
//库函数字符串转float <stdlib.h>
    atof(char s[]);
//             外部变量&静态变量        自动变量&寄存器变量
//初始化次数        1次             每次进入函数或程序块都会初始化
//未初始化时的值     0                      未定义
//初始化表达式    必须为常量表达式        可以为已定义的值或函数调用
//数组没有初始化的部分默认为0
int days[10] = {1, 3};
//字符数组的初始化
char str1 = "world";
char str2[] = {'w', 'o', 'r', 'l', 'd'};
//库函数排序
    qsort();
}

//静态变量与函数 static
static char buf[BUFSIZE];
static int bufp = 0; //则该变量只能在同文件的定义处后面的函数使用
static int getch(void) //函数声明为static则只有当前文件可以调用该函数
{
    static int num = 0;//函数内部变量声明为staitc则变量不会随函数的终止而被清除
}

int f(register unsigned m)
{
    //寄存器变量优点是访问快,只适用于函数的形式参数或自动变量
    //无法访问寄存器变量的地址
    //是否真的被分配到寄存器有赖于不同的机器和编译器实现
    //寄存器变量对变量的类型也有要求
    register int i;

    //程序块内的自动变量只在程序块内有效
    while (1) {
        int i; //i在{}内有效,可以加static关键字,则每次进入{}变量都不重新初始化
    }
}
