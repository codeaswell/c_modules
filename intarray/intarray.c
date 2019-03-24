#include <stdio.h>
#include <stdlib.h>

#include "intarray.h"

/*
* Private function
*/
void intarray_init(intarray *tab)
{
    for(int i = 0; i < tab->alloc; i++)
        tab->data[i] = 0;
}

/*
* Public function
*/
intarray *intarray_create(int len)
{
    intarray *tab = tools_malloc(sizeof(struct intarray));
    tab->len = (len < 0) ? 0 : len;
    tab->alloc = tab->len;
    tab->data = tools_malloc(tab->alloc * sizeof(int));

    intarray_init(tab);

    return tab;
}

intarray *empty_intarray_create(void)
{
    intarray *tab = tools_malloc(sizeof(struct intarray));
    tab->len = 0;
    tab->alloc = DEFAULT_ALLOC;
    tab->data = tools_malloc(tab->alloc * sizeof(int));

    intarray_init(tab);

    return tab;
}

void intarray_destroy(intarray **ttab)
{
    intarray *tab = *ttab;
    if(tab == NULL)
        return;

    tools_free(tab->data, tab->alloc * sizeof(int));
    tools_free(tab, sizeof(struct intarray));
    *ttab = NULL;
}

void intarray_resize(intarray *tab, int newalloc)
{
    int *newdata = tools_malloc(newalloc * sizeof(int));

    for(int i = 0; i < tab->len; i++)
        newdata[i] = tab->data[i];

    for(int i = tab->len; i <= newalloc; i++)
        newdata[i] = 0;

    tools_free(tab->data, tab->alloc * sizeof(int));
    tab->data = newdata;
    tab->alloc = newalloc;
}

void intarray_add(intarray *tab, int value)
{
    intarray_set(tab, tab->len, value);
}

void intarray_set(intarray *tab, int index, int value)
{
    if(index < 0) 
    {
        fprintf(stderr, "Index invalide.\n");
        return;
    }

    if(index < tab->len) 
    {
        tab->data[index] = value;
        return;
    }

    if(index >= tab->alloc) 
        intarray_resize(tab, 1 + 2 * index);
    
    tab->data[index] = value;
    
    if(index >= tab->len)
        tab->len = index + 1;
}

void intarray_debug(intarray *tab)
{
    printf("[ ");

    for(int i = 0; i < tab->len; i++)
        {
            if(i == tab->len - 1)
                printf("%d", tab->data[i]);
            else
                printf("%d, ", tab->data[i]);
        }

    printf(" ]");

    //printf("\n Length: %d, Alloc: %d\n", tab->len, tab->alloc);
}
