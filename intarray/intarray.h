#ifndef __INTARRAY_H__
#define __INTARRAY_H__

#include "../tools/tools.h"

typedef struct intarray
{
    int *data;
    int len;
    int alloc;
}intarray;


intarray *intarray_create(int len);
intarray *empty_intarray_create(void);
void intarray_destroy(intarray **ttab);

void intarray_set(intarray *tab, int index, int value);
void intarray_add(intarray *tab, int value);
void intarray_debug(intarray *tab);

void intarray_resize(intarray *tab, int newalloc);



#endif