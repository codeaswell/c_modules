#ifndef __JSTR_H__
#define __JSTR_H__

#include "../tools/tools.h"

typedef struct jstr
{
    char *data;
    int len;
    int alloc;
}jstr;


jstr *jstr_create(int len);
jstr *empty_jstr_create(void);
void jstr_destroy(jstr **ttab);

void jstr_set(jstr *tab, int index, char value);
void jstr_add(jstr *tab, char value);
void jstr_debug(jstr *tab);

void jstr_resize(jstr *tab, int newalloc);

jstr *regstr_to_jstr(char *str);
char *jstr_to_regstr(jstr *tab);

#endif