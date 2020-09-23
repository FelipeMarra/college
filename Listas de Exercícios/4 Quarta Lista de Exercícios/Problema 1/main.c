#include <stdio.h>
#include <stdlib.h>

int main () {
int i, i2 = 0;
for (i = 0; i < 10; i++) {
    printf ("FOR:  ");
    printf ("i = %d", i );
    printf ("\n");
}

while(i2 < 10){
    printf ("WHILE:");
    printf ( "i = %d", i2 );
    printf ("\n");
    i2++;
}

return 0 ;
}
