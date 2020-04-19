//동적 할당 영역을 배열처럼 쓰기

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *pi;
    int i, sum = 0;
    
    pi = (int *)malloc(5 * sizeof(int));    // 배열요소 5개의 배열 크기인 20바이트 할당 
    if (pi == NULL)
    {
        printf("메모리가 부족합니다!\n");
        exit(1);                            // 메모리가 부족할 때 예외처리 구문
    }
    printf("다섯 명의 나이를 입력하세요 : ");
    /*
    for(i = 0 ; i < 5 ; i++)                // 1. 배열요소 표현식 사용 
    {
        scanf("%d", &pi[i]);
        sum += pi[i];
    }
    */
    for(i = 0 ; i < 5 ; i++)                // 2. 포인터 계산식 사용 
    {
        scanf("%d", pi + i);
        sum = sum + *(pi + i);
    }
    printf("다섯 명의 평균 나이 : %.1lf\n", (sum / 5.0));
    free(pi);
    
    return 0;
}