#include <stdio.h>

int main()
{
/*标准输入/输出*/
    int getchar(void);//从标准输入获取一个字符,若遇到文件结尾返回 EOF<stdio.h>
//用<实现输入重定向
    prog <infile //<info不会包含在 argv的命令行参数中
//标准输入用|(pipe)实现重定向
    otherprog | prog //otherprog的标准输入重定向到prog的标准输入
int putchar(int);//将字符送至标准输出,正常返回字符,错误返回EOF
//prog >输出文件名
//prog | antherprog
//可以通过 重定向和管道将标准输出重定向
//<stdio.h>的<>,如果是UNIX系统,预处理器会在/usr/include中查找文件
//<stdio.h>中的getchar和putchar
//<ctype.h>中的tolower
//一般都是宏,避免函数调用的开销

/*格式化输出--printf函数*/
int printf(char *format, arg1, arg2, ...)
//字符%后的转换符号的顺序
//负号  左对齐输出
//数    最小字段宽度,默认右对齐,用空格补齐
//.     把字段宽度和精度分开
//数    用于指定精度,字符串中要打印的字符数,浮点数小数点后的位数,整型最小输出的数字数目
//h[l]  h表示将整数作为short类型打印,l表示将整数作为long类型打印
//打印"hello, world"12个字符,用":"做边界
:%s:          :hello, world:
:%10s:        :hello, world:
:%.10s:       :hello, wor:
:%-10s:       :hello, world:
:%.15s:       :hello, world:
:%-15s:       :hello, world   :
:%15.10s:     :     hello, wor:
:%-15.10s:    :hello, wor     :
//宽度和精度可以用*表示,*需要指定int类型,例如打印最多max个字符
printf(%.*s, max, s);
//sprintf将打印的字符串保存到字符指针中(字符指针必须足够存下字符串), 返回打印长度
int sprintf(char *string, char *format, arg1, arg2, ...)
printf(s); //如果s中有%号将报错
printf("%s", s);//正确

/*变长参数表*/
//函数printf的正确声明形式
    int printf(char *fmt, ...);
//省略号表示参数的数量和类型是可变的,省略号只能在尾部
//<stdarg.h>中包含一组宏定义,它们对如何遍历参数表进行了定义
//va_list用于声明一个变量,该变量一次引用各个参数,
    va_list ap;
//宏va_start将ap初始化为指向第一个无名参数的指针
//每次调用va_arg,该函数都将返回一个参数,并将ap指向下一个参数
//最后用va_end做清理工作

/*格式化输入--scanf函数*/
int scanf(char *format, ...)
//扫描标准输入按format格式把内容分配到变量中,变量列表必须是指针
//扫描完格式串或与格式串中的格式控制不匹配时函数终止,返回成功匹配并赋值的输入项的个数作为返回值
//如果到达文件末尾函数返回EOF
//从一个字符串而不是标准输入中读取字符序列
int sscanf(char *string, char *format, ...);
//格式串转换说明
//空格或制表符被忽略
//普通字符(不包括%)用于匹配输入流中下一个非空白符字符
//转换说明,依次由一个%,一个可选的赋值禁止字符*,一个可选的数值(指定字段的最大宽度),一个可选的hl(指定目标对象的宽度)以及一个转换字符组成
//赋值禁止字符*或跳过相应的字段
//输入字段定义一个不包括空白符的字符串,如果其边界定义到下一个空白符,表示scanf函数将跨行读取输入
//计算器
    double sum, v;
    sum = 0;
    while (scanf("%lf", &v) == 1)
        printf("\t%.2f\n", sum += v);
//如果输入格式不固定最好每次读取一行
    int month,day,year;
    char monthname[20];
    while (getline(line, sizeof(line))> 0) {
        if (sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
            printf("valid: %s\n", line);
        else if (sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
            printf("valid: %s\n", line);
        else
            printf("invalid: %s\n", line);
    }

/*文件访问*/
//<stdio.h>中定义了包含文件信息(文件读写状态,是否EOF,缓冲区位置...)结构FILE
//声明文件指针
    FILE *fp;
//fopen说明
    FILE *fopen(char *name, char *mode);
//FILE是通过typedef定义的
//文件mode,"r","w","a","b"
//fopen打开文件失败(没权限,文件找不到)返回NULL
//getc返回fp指向的输入流中的下一个字符,到达末尾或发生错误返回EOF
    int getc(FILE *fp);
//putc将字符写入到fp指向的文件中,并返回写入的字符,出错返回EOF
    int putc(int c, FILE *fp);
//getc 和 putc 是宏
//启动一个c程序时,操作系统负责打开三个文件,并把这三个文件的指针提供给该程序,分别为
//stdin,stdout,stderr <stdio.h>中定义
//getchar putchar 的定义
    #define getchar() getc(stdin)
    #define putchar(c) putc((c), stdout)
//文件的格式化输入和输出可以使用
    int fscanf(FILE *fp, char *format, ...);
    int fprintf(FILE *fp, char *format, ...);
//一个程序可以同时打开的文件是有限制的,所以使用完的文件需要用fclose关闭
//使用fclose还可以把缓冲区内容写入文件
//如果不需要stdin stdout可以用fclose关闭,用freopen重新打开

/*错误处理--stderr和exit*/
//在调用各种输入输出函数（如putc.getc.fread.fwrite)时，如果出现错误，除了函数返回值有所反映外，还可以用error函数检查。
//如果ferror返回值为0，表示未出错
//如果返回值为非0，表示出错。
//对同一个文件 每一次调用输入输出函数，均产生一个新的ferror函数值，因此，应当在调用一个输入输出函数后立即检查ferror函数的值，否则信息会丢失。
//在执行fopen函数时，ferror函数的初始值自动置为0.
int ferror(FILE *fp);
//feof()和EOF的用法—— C中文件结尾的判断
//http://blog.csdn.net/bingqing07/article/details/5785080/

/*行输入和行输出*/
//fget最多可以读取maxline-1个字符,读取的行以'\0'结尾,发生错误或文件结束返回NULL
char *fgets(char *line, int maxline, FILE *fp);
//出错返回EOF
int fputs(char *line, FILE *fp);
//gets和puts是对stdio和stdout操作,读取时自动删除换行符,写入时自动增加换行符

/*其它函数*/
<string.h>
strlen,strcpy,strncpy,strcat,strncat,strcmp,strncmp,strchr,strrchr
<ctype.h>
isalpha,isupper,islower,isdigit,isalnum,isspace,toupper,tolower
int ungetc(int c, FILE *fp);
//执行系统命名
system(char *s)
//存储管理
//分配成功时返回一个指针,指向n字节长度的未初始化的存储空间,否则返回NULL,
void *malloc(size_t n);
//分配成功时返回一个指针,指向空闲空间足以容纳由n个指定长度的对象组成的数组,否则返回NULL,该存储空间被初始化为0
int *ip;
ip = (int *)malloc(n, sizeof(int));
freep(p)释放p指向的空间,p必须是由malloc或calloc得到的指针
//以下错误
for (p = head; p != NULL; p = p->next)
    free(p);
//以下正确
for (p = head; p != NULL; p = q) {
    q = p->next;
    free(p);
//数学
//sin,cos,atan2,exp{e^x},log{e为底x的对数},log10,pow,sqrt,fabs{绝对值}
//随机数
rand();//生成0~RAND_MAX之间的伪随机数,RAND_MAX在 <stdlib.h>中定义
//0~1随机数
#define frand() ((double)rand() / (RAND_MAX+1.0))

}