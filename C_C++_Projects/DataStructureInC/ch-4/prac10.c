//  �迭�� ��� �ִ� ������ ������ �Ųٷ� �ϴ� ���α׷�
#include <stdio.h>
#include <string.h>
#include "normal_stack_int_ver.h"
typedef int element;

int main(void)
{
    int num, tmp;
    Stacktype s;
    printf("���� �迭�� ũ�� : ");
    scanf("%d", &num);
    init_stack(&s);
    printf("������ �Է��Ͻÿ� : ");
    for(int i = 0 ; i < num ; i++ )
    {
        scanf("%d", &tmp);
        push(&s, tmp);
    }
    printf("������ ���� �迭 : ");
    for(int i = 0 ; i < num ; i++)
    {
        printf("%d ", pop(&s));
    }
    return 0;
}