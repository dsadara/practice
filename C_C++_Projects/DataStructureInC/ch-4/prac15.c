// 미로 탐색 프로그램
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maze_explore_stack.h"
#define MAZE_SIZE 6


element here = {1, 0}, entry = {1, 0};

char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'1', '1', '1', '1', '1', '1'},
    {'e', '1', '0', '0', '0', '1'},
    {'0', '1', '0', '1', '0', '1'},
    {'0', '1', '0', '1', '0', '1'},
    {'0', '0', '0', '1', '0', 'x'},
    {'1', '1', '1', '1', '1', '1'},
};
//위치를 스택에 삽입
void push_loc(Stacktype *s, int r, int c)
{
    if (r < 0 || c < 0) return;
    if (maze[r][c] != '1' && maze[r][c] != '.') // 삽입하려는 위치가 벽과 이미 지나간 위치가 아니라면
    {
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);
    }
}

// 미로를 화면에 출력
void maze_printf(char maze[MAZE_SIZE][MAZE_SIZE])
{
    printf("\n");
    for (int r = 0 ; r < MAZE_SIZE ; r++)
    {
        for (int c = 0 ; c < MAZE_SIZE ; c++)
        {
            printf("%c", maze[r][c]);
        }
        printf("\n");
    }
}

void print_path(Stacktype *p)
{
    int i, r, c, count = p -> top + 1;
    element e;
    printf("출구에서 입구까지 경로 출력 \n");
    for ( i = 0 ; i < count ; i++)
    {
        e = pop(p);
        r = (int)e.r; c = (int)e.c;
        printf("(%d, %d)\n", r, c);

    }
}

int main(void)
{
    int r, c;
    Stacktype s;    // 이동이 가능한 칸들의 위치를 저장하는 스택
    Stacktype path; // 입구부터 출구까지의 경로의 위치를 저장하는 스택
    init_stack(&path);
    init_stack(&s);
    here = entry;   // ???  현재위치를 시작지점으로 한다고 명시하는 거 같다 
    while(maze[here.r][here.c] != 'x') { // 현재위치가 출구에 도달할 때 까지 반복 
        r = here.r;
        c = here.c;
        maze[r][c] = '.';
        push(&path, here);  // 지나간 경로를 path 스택에 저장
        maze_printf(maze);
        push_loc(&s, r - 1, c); // 위
        push_loc(&s, r + 1, c); // 아래
        push_loc(&s, r, c - 1); // 왼쪽
        push_loc(&s, r, c + 1); // 오른쪽 순서로 스택에 저장
        if(is_empty(&s))    // 스택이 비었으면 실패를 출력
        {
            printf("실패\n");
            return 0;
        }
        else                // 스택이 비어있지 않았으면 스택에서 하나의 위치를 꺼내여 현재 위치로 만듦
        {
            here = pop(&s);
        }
    }
    printf("성공\n");
    print_path(&path);
    return 0;
}