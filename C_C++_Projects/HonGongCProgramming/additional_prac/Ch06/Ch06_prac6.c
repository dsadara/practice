#include <stdio.h>


void print_space(int space);

int main(void)
{
    int i, j, num_of_num, space;
    for(i = 0; i < 5 ; i++)
    {
        space = 4 - i;
        print_space(space);
        for(j = 0; j < 2*i + 1 ; j++)
        {
            printf("%d", j+1);
        }
        printf("\n");
    }
    
    return 0;
}

void print_space(int space)
{
    int k;
    for(k = 0 ; k < space ; k++)
        printf(" ");
    return;
}