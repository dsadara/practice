#include <stdio.h>

int main(void)
{
    int op1, op2, res;
    char operator;
    
    printf("사칙연산 입력(정수) : ");
    scanf("%d%c%d", &op1, &operator, &op2); 
    // printf("\n"); -> scanf에서 엔터를 치면 터미널 상에서 LineFeed 문자가 생성되어 다음줄로 넘어간다
    if (operator == '+')
        res = op1 + op2;
    else if (operator == '-')
        res = op1 - op2;
    else if (operator == '*')
        res = op1 * op2;
    else if (operator == '/')
        res = op1 / op2;
    else printf("올바르지 않은 입력값입니다");
    printf("%d%c%d = %d\n", op1, operator, op2, res);
    
    return 0;
}