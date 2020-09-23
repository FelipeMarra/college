#include <stdio.h>
#include <stdlib.h>

int main()
{
    int var1, var2;
    
    printf("Var 1: ");
    scanf("%d", &var1);
    printf("Var 2: ");
    scanf("%d", &var2);

    if (&var1 > &var2)
        printf("var1 (%d) > var2(%d)", &var1, &var2);
    else 
        printf("var2 (%d) > var1(%d)", &var2, &var1);

    return 0;
}
