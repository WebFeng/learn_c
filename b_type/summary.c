#include <stdio.h>

int main()
{
//char 1Byte=8bit
//int 通常为 16bit或32bit
//short int 通常为 16bit
//long int 通常为 32bit
//signed&unsigned 限定 char/int, unsigned遵守算术模定律2^n, unsigned char为0~255
//整数常量 uU lL
    long steps = 14591209ul;
//浮点常量 fF lL
    float price1 = 23.23f;
    float price2 = 2323e-2;
//整数常量表示
    int num1 = 31;   //10进制
    int num2 = 037;  //8进制
    int num3 = 0x1f; //16进制
//字符常量是整数
//#define VTAB '\013'
//#define Bell '\x7'
//字符串常量[字符数组], 以'\0'结束, strlen(str)返回不包括'\0'的字符串长度
    char str1[] = "hello, world";
//字符串拼接
    char str2[] = "hello," " world";
//枚举值默认是0,自动递增,T3=0,T4=1
    enum types {T1 = 'a', T2 = 'b', T3, T4};
//const限定符,限定变量不允许被修改
    const char msg[] = "warning: ";//字符数组的每一项都不能被修改
    int strlen(const char[]); //strlen不能修改参数
//运算符优先级
//高   --->   低
//{指针 *  &  增减  ++  --}  {算数  *  /  %}  {算数 +  -}  {关系  >  >=  <  <=}  {关系  ==  !=}  {逻辑  &&  ||}  {赋值  =}
//类型隐式转换规则:比较窄的操作数转为比较宽的操作数 int转成float, ...
//转小写 tolower(c) ctype.h
//检测数字[0-9] isdigit(c) ctype.h
//不同机器存储的char类型高位可能为1[signed]或0[unsigned]
//强制类型转换, 如果事先声明函数, 则不需要强制转换
    sqrt((double) n);
//字符串t接到s尾部, 假设s够长
    strcat(s, t);
//位运算
//& 屏蔽二进制位
//| 将某些二进制位置为1
//^ 异或 不同置为1,相同置为0
//<< 左移
//>> 右移
//~  取反
}