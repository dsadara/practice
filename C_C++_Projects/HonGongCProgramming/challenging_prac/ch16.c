/* 소수 계산 프로그램 : 2부터 입력한수 - 1 까지의 모든 소수를 출력
소수가 아닌 수는 X 를 출력, 입력한 수에 따라 적절한 크기의 배열을 동적할당하여 사용 
동적할당 왜했노?... 대신 itoa 함수를 사용했어요
*/

#include <stdio.h>
#include <stdlib.h>

char *prime(int num, char * buf);

int main(void)
{
    char buffer[65] = {0};      // 문자열로 변환된 숫자를 저장할 버퍼 
    int n_num, i, count = 1;
    char * pi;       // 동적할당공간을 가리킬 포인터 
    printf("Enter the natural number : ");
    scanf("%d", &n_num);
    pi = (char *)malloc(sizeof(char)*n_num);

    for ( i = 2 ; i < n_num ; i++ )
    {
        printf("%5s", prime(i, buffer));
        if((count++) == 5)
        {
            count = 1;
            printf("\n");
        }
    }
    return 0;
}

char *prime(int num, char * buf)
{
    if(num == 2)
        return "2";
    for(int i = 2 ; i < num ; i++)
    {
        if((num % i) == 0)
            return "X"; 
    }
    return itoa(num, buf, 10);
}