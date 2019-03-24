#ifndef __TOOLS_H__
#define __TOOLS_H__


#define DEFAULT_ALLOC 8
int GLOBAL_ALLOC_MEMORY;

void init_memory();
void *tools_malloc(int alloc);
void tools_free(void *ptr, int alloc);
void check_memory_at_end_of_app();

void int_normalize_and_warn(int *n, int minv, int maxv);

#endif