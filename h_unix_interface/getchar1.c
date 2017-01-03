#include "syscalls.h"

/* getchar函数：无缓冲的单字符输入 */
int getchar(void)
{
	char c;

	return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}