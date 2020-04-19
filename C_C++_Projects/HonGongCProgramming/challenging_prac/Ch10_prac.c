#include <stdio.h>

void input_nums(int *lotto_nums);
void print_nums(int *lotto_nums);


int main(void)
{
    int lotto_nums[6] = {0, 0, 0, 0, 0, 0};
    
    input_nums(lotto_nums);
    print_nums(lotto_nums);
    return 0;
}

void input_nums(int *lotto_nums)
{
    int i, j, num, count = 0, redunt = 0;
    while(1)
    {
        printf("번호 입력 : ");
        scanf("%d", &num);
        for(i = 0 ; i < count ; i++)
        {
            if(lotto_nums[i] == num)
            {
                printf("같은 번호가 있습니다!\n");
                redunt = 1;
                break;
            }
        }
        if(redunt != 1)
        {
            lotto_nums[count] = num;
            count++;
        }
        else
        {
            redunt = 0; 
        }
        if(count == 6)
            break;
    }
}

/*
void input_nums(int *lotto_nums)
{
    int i, j, num;
    for(i = 0 ; i < 6 ; i++)
    {
        printf("번호 입력 : ");
        scanf("%d", num);
        for(j = 0 ; j < i ; j++)
        {
            if(num == lotto_nums[j])
            {
                
                printf("같은 번호가 있습니다!");
                i--;
                break;
            }
        }
        lotto_nums[i] = num;
    }
    return;
}
*/

void print_nums(int *lotto_nums)
{
    int i;
    for(i = 0 ; i < 6 ; i++)
    {
        printf("로또 번호 : ");
        printf("%d ", lotto_nums[i]);
    }
    return;
}