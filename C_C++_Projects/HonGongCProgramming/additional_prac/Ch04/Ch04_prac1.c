#include <stdio.h>

int main(void)
{
    int meter = 2;
    double inch;
    
    inch = (double)meter * 100.0 / 2.54;
    
    printf("%d미터는 %.1lf인치 입니다.", meter, inch);
    
    return 0;
}