// �������� 8 10
#include <stdio.h>

int items = 10;  // ���� �� ����

void ins(int array[], int loc, int value) 
{
    for (int i = items - 1 ; i >= loc ; i--)
    {
        array[i+1] = array[i];
    }
    array[loc] = value;
    items++;
    return;
}

int del(int array[], int loc) 
{
    int temp = array[loc];
    for(int i = loc ; i < items - 1 ; i++)
    {
        array[i] = array[i+1];
    }
    array[items - 1] = 0; // ��������� 0���� ä���
    items--;
    return temp;
}

int main(void)
{
    /*
    int n;
    printf("�迭�� ������ �Է��Ͻÿ� : ");
    scanf("%d", &n);
    */
    int res;
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int i = 0 ; i < 10 ; i++)
        printf("%d ", array[i]);
    puts("\n");
    ins(array, 4, 999);
    for(int i = 0 ; i < 11 ; i++)
        printf("%d ", array[i]);
    puts("\n");
    res = del(array, 4);
    for(int i = 0 ; i < 10 ; i++)
        printf("%d ", array[i]);
    puts("\n");
    printf("������ ���� : %d", res);
    return 0;
}