#include <stdlib.h>  
#include <stdio.h>  
#include "insertion.h"  

int main()
{
    float array[25] = {12.00,52.00,67.00,84.00,24.00,65.00,85.00,23.00,24.00,95.00,82.00,96.00,35.00,59.00,6.00,100.00,106.00,610.00,625.00,510.00,962.00,85.00,841.00,56.00,50.00};

    printArray(25, array);

    insertion(25, array);

    printArray(25, array);

    return 0;
}
