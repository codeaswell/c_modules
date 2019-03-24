#ifndef __STRINGARRAY_H__
#define __STRINGARRAY_H__

#include "../jstr/jstr.h"
#include "../tools/tools.h"


typedef struct stringarray
{
    char **data;
    int len;
    int alloc;
}stringarray;


stringarray *stringarray_create(int len);
stringarray *empty_stringarray_create(void);
void stringarray_destroy(stringarray **ttab);

void stringarray_set(stringarray *tab, int index, jstr *value);
void stringarray_add(stringarray *tab, jstr *value);
void stringarray_debug(stringarray *tab);

void stringarray_resize(stringarray *tab, int newalloc);

#endif