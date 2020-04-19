// ackermann ÇÔ¼ö ...
#include <stdio.h>

int ackermann(int a, int b)
{
    if(a == 0)
        return b + 1;
    else if (b == 0)
        return ackermann(a-1, 1);
    else if (a >= 1 && b >= 1)
        return ackermann(a-1, ackermann(a, b-1));
};

int main(void)
{
    int a, b, res;
    printf("Enter the a, b of Ackermann(a, b) : ");
    scanf("%d%d", &a, &b);
    res = ackermann(a, b);
    printf("Ackerman(%d, %d) : %d", a, b, res);
    return 0;
}