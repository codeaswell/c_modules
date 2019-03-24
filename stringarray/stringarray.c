#include <stdio.h>
#include <stdlib.h>

#include "stringarray.h"

/*
* Private function
*/
void stringarray_init(stringarray *tab)
{
    for(int i = 0; i < tab->alloc; i++)
        tab->data[i] = NULL;
}

/*
* Public function
*/
stringarray *stringarray_create(int len)
{
    stringarray *tab = tools_malloc(sizeof(struct stringarray));
    tab->len = (len < 0) ? 0 : len;
    tab->alloc = tab->len;
    tab->data = tools_malloc(tab->alloc * sizeof(struct jstr));

    stringarray_init(tab);

    return tab;
}

stringarray *empty_stringarray_create(void)
{
    stringarray *tab = tools_malloc(sizeof(struct stringarray));
    tab->len = 0;
    tab->alloc = DEFAULT_ALLOC;
    tab->data = tools_malloc(tab->alloc * sizeof(struct jstr));

    stringarray_init(tab);

    return tab;
}

void stringarray_destroy(stringarray **ttab)
{
    stringarray *tab = *ttab;
    if(tab == NULL)
        return;

    for(int i = 0; i < tab->len; i++)
        jstr_destroy(&tab->data[i]);

    tools_free(tab->data, tab->alloc * sizeof(struct jstr));
    tools_free(tab, sizeof(struct stringarray));
    *ttab = NULL;
}

void stringarray_resize(stringarray *tab, int newalloc)
{
    char **newdata = tools_malloc(newalloc * sizeof(struct jstr));

    for(int i = 0; i < tab->len; i++)
        newdata[i] = tab->data[i];

    for(int i = tab->len; i <= newalloc; i++)
        newdata[i] = NULL;

    tools_free(tab->data, tab->alloc * sizeof(struct jstr));

    tab->data = newdata;
    tab->alloc = newalloc;
}

void stringarray_add(stringarray *tab, jstr *value)
{
    stringarray_set(tab, tab->len, value);
}

void stringarray_set(stringarray *tab, int index, jstr *value)
{
    if(index < 0) 
    {
        fprintf(stderr, "Index invalide.\n");
        return;
    }

    if(index < tab->len) 
    {
        if(tab->data[index] != NULL)
            jstr_destroy(&tab->data[index]);

        tab->data[index] = value;   
        return;
    }

    if(index >= tab->alloc) 
        stringarray_resize(tab, 1 + 2 * index);
    
    if(tab->data[index] != NULL)
            jstr_destroy(&tab->data[index]);

    tab->data[index] = value;
    
    if(index >= tab->len)
        tab->len = index + 1;
}

void stringarray_debug(stringarray *tab)
{
    
    for(int i = 0; i < tab->len; i++)
    {
        jstr_debug(tab->data[i]);
        printf("\n");
    }
        
    //printf("\n Length: %d, Alloc: %d\n", tab->len, tab->alloc);
}
