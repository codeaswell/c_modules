#include "charray2d.h"

void charray_alloc(charray *A)
{
    A->data = tools_malloc(sizeof(char) * A->w * A->h);
    A->pixel = tools_malloc(sizeof(char*) * A->h);
    for(int j = 0; j < A->h; j++)
        A->pixel[j] = A->data + j * A->w;
}

charray *charray_create(int w, int h, char bg)
{
    charray *A = tools_malloc(sizeof(struct charray));
    A->w = w;
    A->h = h;
    A->bg = bg;

    charray_alloc(A);
    charray_fill(A);

    return A;
}

void charray_fill(charray *A)
{
    char *ptr = A->data;
    for(int j = 0; j < A->h; j++) 
    {
        for(int i = 0; i < A->w; i++) 
        {
            *ptr = A->bg;
            ptr++;
        }
    }
}

void charray_destroy(charray **ttab)
{
    charray *A = *ttab;

    if(A == NULL)
        return;

    tools_free(A->pixel, sizeof(char*) * A->h);
    tools_free(A->data, sizeof(char) * A->w * A->h );
    tools_free(A, sizeof(struct charray));

    *ttab = NULL;
}

void charray_debug(charray *A)
{
    char *ptr = A->data;

    for(int j = 0; j < A->h; j++)
    {
        for(int i = 0; i < A->w; i++) 
        {
            printf(" %c ", *ptr);
            ptr++;
        }
        printf("\n");
    }
}

void charray_set(charray *A, int x, int y, char bg)
{
    if(x < 0 || x >= A->w || y < 0 || y >= A->h)
    {
        printf("\nOut of bounds: [ %d, %d ]\n", x, y);
        return;
    }
    A->pixel[y][x] = bg;
    //A->data[A->w * y + x] = bg;
}

void charray_copy(charray *src, int sx, int sy, charray *tar, int tx, int ty, int w, int h)
{
    int error = 0;


    if(src == tar)
    {
        fprintf(stderr, "charray_copy : src and tar are the same charray.\n");
        return;
    }

    int ex = sx + w - 1;
    int ey = sy + h - 1;

    int_normalize_and_warn(&sx, 0, src->w - 1);
    int_normalize_and_warn(&sy, 0, src->h - 1);
    int_normalize_and_warn(&ex, 0, src->w - 1);
    int_normalize_and_warn(&ey, 0, src->h - 1);

    w = ex - sx + 1;
    h = ey - sy + 1;

    for(int j = 0; j < h; j++)
    {
        for(int i = 0; i < w; i++)
        {
            if( (tx + i < tar->w) && (tx + i >= 0)  && (ty + j < tar->h) && (ty + j >= 0) ) 
            {
                tar->pixel[ty + j][tx + i] = src->pixel[sy + j][sx + i];
            }
            else 
            {
                error = 1;
            }
        }
    }

    if(error) 
    {
        printf("\nWarning: out of bounds in destination array [ %d, %d ]\n", tx, ty);
    }
}