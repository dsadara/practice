#include <stdio.h>

int main(void)
{
    int stuff1, stuff2, stuff3,
        w5000, w1000, w500, w100,
        w50, w10, change;
    printf("세 개의 물건값을 입력하세요 : ");
    scanf("%d%d%d", &stuff1, &stuff2, &stuff3);
    
    change = 10000 - (stuff1 + stuff2 + stuff3);
    printf("거스름돈은 %d원입니다.\n", change);
    
    w5000 = change / 5000;
    change %= 5000;
    w1000 = change / 1000;
    change %= 1000;
    w500 = change / 500;
    change %= 500;
    w100 = change / 100;
    change %= 100;
    w50 = change / 50;
    change %= 50;
    w10 = change / 10;

    printf("오천원권 : %d장\n", w5000);
    printf("천원권 : %d장\n", w1000);
    printf("오백원짜리 동전 : %d개\n", w500);
    printf("백원짜리 동전 : %d개\n", w100);
    printf("오십원짜리 동전 : %d개\n", w50);
    printf("십원짜리 동전 : %d개\n", w10);
    
    return 0;
}