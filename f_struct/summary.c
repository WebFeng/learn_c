#include <stdio.h>

int main()
{

/*结构简介*/
//结构是多种不同类型变量的集合,可以存储复杂的记录,例如存储一条雇员记录,包括姓名/年龄/地址/工资...
//结构可以拷贝/赋值/传递给函数/函数也可以返回结构

/*结构的声明*/
    struct point {
        int x;
        int y;
    } a, b, c ,d;
    //point为结构标记,可选
    //x/y为结构成员
    //结构成员/结构标记/变量名可以使用相同的名字,不冲突
    //a,b,c,d为结构的变量表,可选
    //如果结构不带变量表则不需要为它分配存储空间,它仅描述了结构的模板
//struct point 类型的变量 dian, 变量的初始化可以省略
    struct point dian = {100, 120};
//访问结构成员
    dian.x = 10;
//结构嵌套
    struct rect {
        struct point pt1;
        struct point pt2;
    };
    struct rect screen;
    screen.pt1.x = 10;
}

/*结构与函数*/
//结构的合法操作: 整体复制与赋值(函数传参或函数返回结构),通过&获取地址,访问其成员
//结构之间不可以比较,可以用常量成员值初始化结构
struct point addpoint(struct point p1, struct pint p2)
{
    p1.x += p2.x;
    p1.y += p2.y;
    return p1;
}
//如果结构很大,指针的方式通常效率更高,访问方式(*pp).x 或 pp->x
    struct point origin, *pp;
    pp = &origin;
    pp-> = (*pp).x;
//以下等价
    struct rect r, *rp = &r;
    r.pt1.x;
    rp->pt1.x;
    (r.pt1).x
    (rp->pt1).x

/*结构数组*/
//定义结构数组,统计关键词数目,内层"{}"可以省略
    struct key {
        char *word;
        int count;
    } keytab[] = {
        {"auto", 0},
        {"break", 0},
        {"case", 0},
    };
//获取结构数组长度
#define NKEYS1 (sizeof keytab / sizeof(struct key))
#define NKEYS2 (sizeof keytab / sizeof(keytab[0]))
//C提供编译时的运算符sizeof 或 sizeof() 用来计算任意对象(变量,数组,结构)或类型(int,double,...,派生类型如结构类型,指针类型)占用的空间字节数
//sizeof返回size_t类型,size_t在<stddef.h>中定义
//#if条件编译语句不能使用sizeof,因为预处理器不对类型名进行分析,所以#define可以使用sizeof

/*指向结构的指针*/
    struct key *binsearch(char *word, struct key *tab, int n) {

    }
//千万不要认为结构的长度等于各成员的长度和,因为不同的对象有不同的对齐要求.
    struct {
        char c;
        int i;
    }
    //假设char类型占用1个字节,int占用4个字节,则该结构可能占用8个字节

/*自引用结构*/
//二叉树自引用结构(以统计单词出现次数为例)
    struct tnode {
        char *word;
        int count;
        struct tnode *left;
        struct tnode *right;
    };
//两个结构互相引用
    struct t {
        struct s *p;
    }
    struct s {
        struct t *q;
    }
//分配结构存储空间
    (struct tnode *)malloc(sizeof(struct tnode));

/*表查找*/
//链表
    struct nlist {
        struct nlist *next;
        char *name;
        char *defn;
    }
//hash表
    static struct nlist *hashtab[100];
//查找链表的标准方法
    for (ptr = head; ptr != NULL; ptr = ptr->next)
        ;

/*类型定义*/
//通常首字母大写标识自定义类型
    typedef int Length;
    Length len, maxlen;
    Length *lengths[];
//定义指针类型
    typedef char *String;
    String p, lineptr, alloc(int);
//声明函数参数类型
    int strcmp(String, String);
//强制转换
    p = (String) malloc(100);
//分配存储空间
    malloc(sizeof(Treenode));
//定义函数
    typedef int (*PFI)(char *, char *);
    PFI strcmp, numcmp;
//typedef作用:
//1.如果数据类型同机器相关,则可以通过typedef在不同机器上定义不同类型,使兼容性更好
//2.typedef可以使复杂的声明更容易理解

/*联合*/
//联合可以在同一变量中保存不同类型的数据
    union u_tag {
        int ival;
        float fval;
        char *sval;
    } u;
//u足够大以保存三种类型中最大的一种
//读取的类型必须和最近一次存入的类型相同
//联合的访问方式
//1.     联合名.成员
//2.     联合指针->成员
//按 整形,浮点,字符串 取值
    printf("%d\n", u.ival);
    printf("%d\n", u.fval);
    printf("%d\n", u.sval);
//联合可嵌套结构,结构也可以嵌套联合
    struct {
        char *name;
        int flags;
        int utype;
        union {
            int ival;
            float fval;
            char *sval;
        }
    } systab[NSYS];
//按整型取值访问
    systab[i].u.ival;
//按字符取值访问
    *systab[i].u.sval;
    systab[i].u.sval[0];
//联合实际上是一种结构,所有成员对于基地址的偏移量都是0
//对联合允许的操作与结构相同 整体赋值,赋值,取地址,访问其成员
//联合只能用其第一个成员类型进行初始化

/*位字段*/
//访问位的方式
//1.通过屏蔽码
#define KEYWORD 01
#define EXTERNAL 02
#define STATIC 04
//将flags中的EXTERNAL和STATIC设置为1
    flags |= EXTERNAL | STATIC;
//将flags中的EXTERNAL和STATIC设置为0
    flags &= ~(EXTERNAL | STATIC);

//2.通过位字段 :后为字段宽度,用二进制表示
struct {
    unsigned int is_keyword : 1;
    unsigned int is_extern : 1;
    unsigned int is_static : 1;
} flags;
    flag.is_extern = flags.is_static = 1;
    flag.is_extern = flags.is_static = 0;
//字段可以不命名,无名字段(只有一个冒号和宽度)起填充作用