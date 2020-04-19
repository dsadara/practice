#include <stdio.h>

void rotate(int *pa, int *pb, int *pc);

int main(void)
{
    int a = 1, b = 2, c = 3;
    char enter;
    while(1)
    {
        printf("%d : %d : %d", a, b, c);
        scanf("%c", &enter);
        if(enter == '\n')
            rotate(&a, &b, &c);
        else if(enter != '\n')
            break;
    }
    return 0;
}

void rotate(int *pa, int *pb, int *pc)
{
    int temp;
    temp = *pa;
    *pa = *pb;
    *pb = *pc;
    *pc = temp;
    return;
}