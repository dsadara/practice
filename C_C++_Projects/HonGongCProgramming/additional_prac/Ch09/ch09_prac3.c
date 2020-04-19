#include <stdio.h>

void assign(int *a);

int main(void)
{
    int a = 0;
    assign(&a);
    printf("%d", a);
    
    return 0;
}

void assign(int * a)
{
    *a = 10;
    return;
}