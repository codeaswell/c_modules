#include <stdio.h>
#include <stdlib.h>

#include "jstr.h"

/*
* Private function
*/
void jstr_init(jstr *tab)
{
    for(int i = 0; i < tab->alloc; i++)
        tab->data[i] = '\0';
}

/*
* Public function
*/
jstr *jstr_create(int len)
{
    jstr *tab = tools_malloc(sizeof(struct jstr));
    tab->len = (len < 0) ? 0 : len;
    tab->alloc = tab->len;
    tab->data = tools_malloc(tab->alloc * sizeof(char));

    jstr_init(tab);

    return tab;
}

jstr *empty_jstr_create(void)
{
    jstr *tab = tools_malloc(sizeof(struct jstr));
    tab->len = 0;
    tab->alloc = DEFAULT_ALLOC;
    tab->data = tools_malloc(tab->alloc * sizeof(char));

    jstr_init(tab);

    return tab;
}

jstr *regstr_to_jstr(char *str)
{
    jstr *j = empty_jstr_create();
    int i = 0;

    while(str[i] != '\0')
    {
        jstr_add(j, str[i]);
        i++;
    }
    return j;
}

char *jstr_to_regstr(jstr *tab)
{
    char *str = tools_malloc(tab->len * (sizeof(char) + 1));

    for(int i = 0; i < tab->len; i++)
        str[i] = tab->data[i];

    str[tab->len] = '\0';
    
    return str;
}

void jstr_destroy(jstr **ttab)
{
    jstr *tab = *ttab;
    if(tab == NULL)
        return;

    tools_free(tab->data, tab->alloc * sizeof(char));
    tools_free(tab, sizeof(struct jstr));
    *ttab = NULL;
}

void jstr_resize(jstr *tab, int newalloc)
{
    char *newdata = tools_malloc(newalloc * sizeof(char));

    for(int i = 0; i < tab->len; i++)
        newdata[i] = tab->data[i];

    for(int i = tab->len; i <= newalloc; i++)
        newdata[i] = '\0';

    tools_free(tab->data, tab->alloc * sizeof(char));
    tab->data = newdata;
    tab->alloc = newalloc;
}

void jstr_add(jstr *tab, char value)
{
    jstr_set(tab, tab->len, value);
}

void jstr_set(jstr *tab, int index, char value)
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
        jstr_resize(tab, 1 + 2 * index);
    
    tab->data[index] = value;
    
    if(index >= tab->len)
        tab->len = index + 1;
}

void jstr_debug(jstr *tab)
{
    
    for(int i = 0; i < tab->len; i++)
        printf("%c", tab->data[i]);

    //printf("\n Length: %d, Alloc: %d\n", tab->len, tab->alloc);
}
