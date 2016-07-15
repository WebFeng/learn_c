#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct nlist {            /* 链表项 */
    struct nlist *next;   /* 链表中的下一项 */
    char *name;           /* 定义的名字 */
    char *defn;           /* 替换文本 */
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];

struct nlist *set(char *name, char *defn);
void hashprint(struct nlist *op);

int main()
{
    int i;

    set("feng", "xixi1");
    set("nian", "xixi2");
    set("wang", "xixi3");
    set("web", "xixi4");
    set("tom", "xixi5");
    set("web", "xixi6");
    set("feng", "xixi7");
    set("nian", "xixi8");
    set("juan", "xixi9");
    set("juan", "xixi10");
    set("ai", "xixi11");
    set("feng", "xixi12");

    for (i = 0; i < 101; i++) {
        if (hashtab[i]) {
            hashprint(hashtab[i]);
        }
    }
}

void hashprint(struct nlist *op)
{
    printf("%s:%s\n", op->name, op->defn);
    if (op->next != NULL) {
        hashprint(op->next);
    }
}

unsigned hash(char *s)
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31*hashval;
    return hashval % HASHSIZE;
}

/* lookup函数: 在hashtab中查找s */
struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

/* set函数: 将(name, defn)加入到hashtab中 */
struct nlist *set(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *)malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else
        free((void *) np->defn);
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

