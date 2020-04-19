#include <stdio.h>

int rec_func(int n);

int main(void)
{
    int n = 10, result = 0;

    result = rec_func(10);

    printf("%d", result);

    return 0;
}

int rec_func(int n)
{
    int count = 1;
    if(n == 1)
        return count;
    count = rec_func(n-1);
    return count +n;
}