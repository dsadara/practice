#include <stdio.h>

int main(void)
{
    int kg;
    double cm, BMI, m;
    
    printf("몸무게(kg)와 키(cm)입력: ");
    scanf("%d %lf", &kg, &cm);
    printf("\n");
    m = cm / 100;    //미터 변환
    BMI = ((double)kg) / (m*m);
    printf("%s\n", ((BMI >= 20.0)&&(BMI < 25.0)) ? "표준입니다" : "체중관리가 필요합니다");
    return 0;
}