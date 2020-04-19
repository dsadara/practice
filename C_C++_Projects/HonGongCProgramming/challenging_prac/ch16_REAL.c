/* 소수 계산 프로그램 : 2부터 입력한수 - 1 까지의 모든 소수를 출력
소수가 아닌 수는 X 를 출력, 입력한 수에 따라 적절한 크기의 배열을 동적할당하여 사용 
*/

#include <stdio.h>
#include <stdlib.h>

void basic_PrimeAlgo(int num, int *pi);
void Eratosthenes_PrimeAlgo(int num, int *pi);

int main(void)
{
    int n_num, i, count = 1;
    int * pi;       // 동적할당공간을 가리킬 포인터 
    printf("Enter the natural number : ");
    scanf("%d", &n_num);
    pi = (int *)malloc(sizeof(int)*n_num);
    if(pi == NULL)              // 메모리 부족 예외처리 
    {
        printf("out of memory!");
        exit(1);
    }

    printf("Not using Prime Algorithms : \n");

    for ( i = 2 ; i < n_num ; i++ )
    {
        basic_PrimeAlgo(i, pi);
        if(pi[i] == 1)
            printf("%5d", i);
        else if(pi[i] == 0)
            printf("    X");
        if((count++) == 5)
        {
            count = 1;


            printf("\n");
        }
    }   
    printf("Using Prime Algorithms : \n");
    for(int i = 0 ; i < n_num ; i++)
    {
        pi[i] = i+2;
    }

    free(pi);

    return 0;
}

void basic_PrimeAlgo(int num, int * pi)
{
    for(int i = 2 ; i < num ; i++)
    {
        if((num % i) == 0)
        {
            pi[num] = 0; 
            return;
        }
    }
    pi[num] = 1;
}

void Eratosthenes_PrimeAlgo(int num, int *pi)
{
    for(int i = num ; pi[i] != NULL ; i++)
    {
        while((ap[i] == 0) && (i < (num - 2)))       //'ap[i] == 0' 배열 요소가 소수이고,  'i < (num -2)' 입력한 양수 미만 일떄

           {

                i++;

           }
           
    }
}