// 연습문제 8 10
#include <stdio.h>

int items = 10;  // 원소 수 개수

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
    array[items - 1] = 0; // 비워진공간 0으로 채우기
    items--;
    return temp;
}

int main(void)
{
    /*
    int n;
    printf("배열의 갯수를 입력하시오 : ");
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
    printf("삭제한 원소 : %d", res);
    return 0;
}