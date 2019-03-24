#ifndef __CHARRAY2D__H__
#define __CHARRAY2D__H__


#include <stdio.h>
#include <stdlib.h>

#include "../tools/tools.h"

typedef struct charray {
    char *data;
    int w;
    int h;
    char bg;
    char **pixel;
}charray;

charray *charray_create(int w, int h, char bg);
void charray_fill(charray *A);
void charray_destroy(charray **ttab);
void charray_debug(charray *A);
void charray_set(charray *A, int x, int y, char bg);
void charray_copy(charray *src, int sx, int sy, charray *tar, 
                    int tx, int ty, int w, int h);
#endif