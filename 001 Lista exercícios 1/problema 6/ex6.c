#include <stdio.h>
#include <stdlib.h>

int main()
{
    int y, *p, x;
    y = 0 ;
    p = &y;
    x = *p;
    x = 4;
    (*p)++;
    x--;
    (*p) += x;
    printf("y = %d, x = %d, *p = %d", y, x, *p);
    return 0;
}
