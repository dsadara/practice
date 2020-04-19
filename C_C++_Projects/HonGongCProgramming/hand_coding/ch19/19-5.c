// #과 ##을 사용한 매크로 함수  (# : 매크로 함수의 인수를 문자열로 치환,
// ## : 두인수를 붙여서 치환 -> 정확히는 2개의 토큰을 붙여서 하나로 만드는 연산자
// 토큰이란? 프로그램에서 독립된 의미를 갖는 하나의 단위)
#include <stdio.h>
#define PRINT_EXPR(x) printf(#x " = %d\n", x)
#define NAME_CAT(x, y) (x ## y)

int main(void)
{
    int a1, a2;

    NAME_CAT(a, 1) = 10;    //a1 = 10;
    NAME_CAT(a, 2) = 20;    //a2 = 20;
    PRINT_EXPR(a1 + a2);        // printf("a1 +a2" " = %d\n", a1 + a2); 로 치환됨
    printf("a1 + a2" " = %d\n", a1 + a2);
    PRINT_EXPR(a2 - a1);

    return 0;
}