#include <stdio.h>
#include <stdlib.h>

#include "tools/tools.h"
#include "intarray/intarray.h"
#include "jstr/jstr.h"
#include "stringarray/stringarray.h"
#include "charray2d/charray2d.h"


int main()
{
    // system("clear");
    printf("\n\n\n");
    init_memory();
    
    // Code from here
    
    charray *A = charray_create(10, 4, '.');
    charray *B = charray_create(12, 6, '~');

    for(int y = 1; y < 3 ; y++)
    {
        for(int x = 4; x < 8; x++)
            charray_set(A, x, y, '#');
    }
    
    charray_debug(A);
    charray_copy(A, 4, 1, B, 2, 3, 4, 2);

    printf("\n\n");
    charray_debug(B);




    charray_destroy(&A);
    charray_destroy(&B);
    
    check_memory_at_end_of_app();
    printf("\n\n\n");
    return 0;
}