#include <stdio.h>

int main(void)
{
    double num = 3.7;
    
    printf("버림식 : %d\n", (int)num); // int형변환 연산을 하면 소수 부분이 날라간다
    printf("반올림식 : %d\n", (int)(num + 0.5)); // 소수 부분이 0.5이상이면 0.5를 더하고 int형변환 연산을 하면 반올림된다. 
    printf("반올림식2 : %.0lf\n", num);
    
    //printf("원래 값 : %lf\n", num);
    //printf("소수점을 버림 : %.0lf\n", num);
   // printf("반올림 : ")
    
    return 0;
}