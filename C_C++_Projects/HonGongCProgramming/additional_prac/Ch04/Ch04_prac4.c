#include <stdio.h>

int main(void)
{
    int A; 
    scanf("%d", &A);
    (A >= 0)
    ? printf("양수입니다.")
    : printf("음수입니다."); // 조건 연산자 안에 문장(statement)를 쓸때는 세미콜론을 조건연산자 끝에만 쓰면 된다. 
    
    return 0;
}