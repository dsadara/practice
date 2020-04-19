#include <stdio.h>

int main(void)
{
    int num, prime, count = 0;
    printf("2 이상의 정수를 입력하세요 : ");
    scanf("%d", &num);
    for(int i = 2 ; i <= num ; i++)             // 2부터 입력한 수(num)까지의 반복문
    {
        if(count == 5 )                         //한줄에 소수 5개씩 출력하기 위해서, count가 5의 배수이면 line feed  
         {
            printf("\n");
            count = 0;
         }
        prime = 1;                              // prime에 1(true)를 넣어서 일단 소수라고 가정
        for(int j = 2 ; j < i ; j++)            // 2부터 i까지의 반복문
        {
            if((i%j) == 0)                      // i를 j로 나눠서 나누어 떨어지면, i는 소수가 아님 
            {
                prime = 0;                      // 소수가 아니므로 prime에 0(false)를 넣음
                break;                          // 더이상 반복 할 필요 없으므로 if문과 겉에 반복문 탈출
            }
        }
        if(prime == 1)                          // i가 소수이면
        {
            printf("%5.d", i);                // 빈칸 4칸과 i한칸 출력
            count++;                            // 소수 하나를 출력했으므로 count 1증감
        }
    }
    return 0;
}