#define WHITE 0
#define BLACK 1
#define YELLOW 2
#include <stdio.h>

int screen[10][10] = {{2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                      {2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
                      {2, 2, 2, 0, 0, 0, 0, 2, 2, 2},
                      {2, 2, 2, 2, 0, 0, 0, 2, 2, 2},
                      {2, 2, 2, 2, 0, 0, 0, 2, 2, 2},
                      {2, 2, 2, 2, 0, 0, 0, 0, 2, 2},
                      {2, 2, 2, 2, 0, 2, 2, 2, 2, 2},
                      {2, 2, 2, 2, 0, 2, 2, 2, 2, 2},
                      {2, 2, 2, 2, 0, 2, 2, 2, 2, 2},
                      {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}};

char read_pixel(int x, int y)
{
    return screen[x][y];
}
void write_pixel(int x, int y, int color)
{
    screen[x][y] = color;
}
//영역 채우기 알고리즘
void flood_fill(int x, int y)
{
    if (read_pixel(x, y) == WHITE)
    {
        write_pixel(x, y, BLACK);
        flood_fill(x+1, y); // 동
        flood_fill(x-1, y); // 서
        flood_fill(x, y+1); // 남
        flood_fill(x, y-1); // 북
    }
}

int main(void)
{
    int i, j;
    for(i = 0 ; i<10 ; i++)
    {
        for(j = 0; j < 10 ; j++)
        {
            printf("%2d",screen[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    flood_fill(4, 5);
    for(i = 0 ; i<10 ; i++)
    {
        for(j = 0; j < 10 ; j++)
        {
            printf("%2d",screen[i][j]);
        }
        printf("\n");
    }
}