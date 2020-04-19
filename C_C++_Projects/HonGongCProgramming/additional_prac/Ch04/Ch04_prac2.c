#include <stdio.h>

int main(void)
{
    int toto =70, ggong = 30, rest,
    sum, change, won500 = 0,
    won100 = 0,won50 = 0, won10 = 0;
    sum = toto*2 + ggong*3;
    change = 1000 - sum;
    rest = change;
    won500 = rest / 500; // 500원 최소 갯수 
    rest -= ((500)*won500);
    won100 = rest / 100; // 100원 최소 갯수
    rest -= ((100)*won100);
    won50 = rest / 50; // 50원 최소 갯수
    rest -= ((50)*won50);
    won10 = rest / 10; // 10원 최소 갯수
    
    printf("또또면 전체 금액 : %d원\n", toto*2);
    printf("꽁꽁바 전체 금액 : %d원\n", ggong*3);
    printf("거스름돈 : %d원\n", change);
    printf("거스름돈 동전의 최소 개수...\n");
    printf("500원 %d개, ", won500);
    printf("100원 %d개, ", won100);
    printf("50원 %d개, ", won50);
    printf("10원 %d개, ", won10);
    
    return 0;
}