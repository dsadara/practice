//반복을 사용한 조합 계산
#include <stdio.h>

int combination(int n, int k)
{
    if(n < k)
        return 0;
    int t1 = 1, t2 = 1, t3 = 1;
    for(int i = 1; i<=n ; i++)
        t1 *= i;
    for(int i = 1; i<=k ; i++)
        t2 *= i;
    for(int i = 1; i<=n-k; i++)
        t3 *= i;
    return t1/(t2*t3);
};

int main(void)
{
    int n, k, res;
    printf("Enter the n, k of nCr : ");
    scanf("%d%d", &n, &k);
    res = combination(n, k);
    if(!res)
        printf("n must be bigger then k!!");
    else 
        printf("result : %d", res);
    return 0;
}