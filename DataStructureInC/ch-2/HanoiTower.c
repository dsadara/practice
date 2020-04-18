#include <stdio.h>

void hanoi_tower(int n, char from, char tmp, char to)
{
    if (n==1) printf("원판 1을 %c 에서 %c으로 옮긴다\n", from, to);
    else {
        hanoi_tower(n-1, from, to , tmp);                           // 먼저 n-1 개의 원판을 2번막대에 옮긴후
        printf("원판 %d을 %c에서 %c으로 옮긴다.\n", n, from, to);     // n 번원판을 3번원판으로 옮긴다
        hanoi_tower(n-1, tmp, from, to);                            // 그다음 2번막대에 있는 n-1개의 원판을 3번원판으로 옮긴다     
    }
}

int main(void)
{
    hanoi_tower(4, 'A', 'B', 'C');
    return 0; 
}