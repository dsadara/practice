//��ȯ�� ����� ���� ��� ���� �� �Լ��� 2���� �Լ��� ����ϱ� O(2^n) ���� �����
#include <stdio.h>

int combination(int n, int k)
{
    if(k == 0 || k == n)
        return 1;
    else if( 0 < k && k < n)
        return combination(n-1, k-1) + combination(n-1, k);
    else return 0;
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