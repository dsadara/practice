// �̷� Ž�� ���α׷�
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
//��ġ�� ���ÿ� ����
void push_loc(Stacktype *s, int r, int c)
{
    if (r < 0 || c < 0) return;
    if (maze[r][c] != '1' && maze[r][c] != '.') // �����Ϸ��� ��ġ�� ���� �̹� ������ ��ġ�� �ƴ϶��
    {
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);
    }
}

// �̷θ� ȭ�鿡 ���
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
    printf("�ⱸ���� �Ա����� ��� ��� \n");
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
    Stacktype s;    // �̵��� ������ ĭ���� ��ġ�� �����ϴ� ����
    Stacktype path; // �Ա����� �ⱸ������ ����� ��ġ�� �����ϴ� ����
    init_stack(&path);
    init_stack(&s);
    here = entry;   // ???  ������ġ�� ������������ �Ѵٰ� ����ϴ� �� ���� 
    while(maze[here.r][here.c] != 'x') { // ������ġ�� �ⱸ�� ������ �� ���� �ݺ� 
        r = here.r;
        c = here.c;
        maze[r][c] = '.';
        push(&path, here);  // ������ ��θ� path ���ÿ� ����
        maze_printf(maze);
        push_loc(&s, r - 1, c); // ��
        push_loc(&s, r + 1, c); // �Ʒ�
        push_loc(&s, r, c - 1); // ����
        push_loc(&s, r, c + 1); // ������ ������ ���ÿ� ����
        if(is_empty(&s))    // ������ ������� ���и� ���
        {
            printf("����\n");
            return 0;
        }
        else                // ������ ������� �ʾ����� ���ÿ��� �ϳ��� ��ġ�� ������ ���� ��ġ�� ����
        {
            here = pop(&s);
        }
    }
    printf("����\n");
    print_path(&path);
    return 0;
}