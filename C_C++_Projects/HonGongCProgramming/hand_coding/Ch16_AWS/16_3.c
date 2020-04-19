// calloc, realloc 함수를 사용한 양수 입력 

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *pi;
    int size = 5;   // 저장 공간의 크기 (배열 요소의 개수)
    int count = 0;  // 현재 입력된 양수의 개수
    int num;        // 양수를 입력할 변수
    int i;
    
    pi = (int *)calloc(size, sizeof(int));
    
    while(1)
    {
        printf("양수만 입력하세요 =>");
        scanf("%d", &num);
        if (num <= 0) break;                 // 입력한 양수가 0 또는 음수이면 종료
        if (count == size)                   // 저장 공간을 모두 사용하면
        {
            size += 5;
            pi = (int *)realloc(pi, size * sizeof(int));
        }
        pi[count++] = num;
    }
    
    for ( i=0 ; i < count ; i++)
    {
        printf("%5d", pi[i]);
    }
    
    free(pi);
    
    return 0;
}