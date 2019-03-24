#include <stdio.h>
#include <stdlib.h>

#include "tools.h"


void init_memory()
{
    GLOBAL_ALLOC_MEMORY = 0;
}

void *tools_malloc(int alloc)
{
    void *ptr =  malloc(alloc);
    GLOBAL_ALLOC_MEMORY += alloc;
    return ptr;
}

void tools_free(void *ptr, int alloc)
{
    free(ptr);
    GLOBAL_ALLOC_MEMORY -= alloc;
}

void check_memory_at_end_of_app()
{
    if(GLOBAL_ALLOC_MEMORY > 0)
        fprintf(stderr, "\n\nMemory leak detected. {%d} bytes were not released\n\n", GLOBAL_ALLOC_MEMORY);
    else
        fprintf(stderr, "No memory leaks");
}

void int_normalize_and_warn(int *n, int minv, int maxv)
{
    if(*n < minv )
    {
        fprintf(stderr, "%d is normalize to %d\n", *n, minv);
        *n = minv;
    }

    if(*n > maxv)
    {
         fprintf(stderr, "%d is normalize to %d\n", *n, maxv);
        *n = maxv;
    }
}
