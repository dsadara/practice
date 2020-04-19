#include <stdio.h>

int leap_year(int a);
void print_template(int a, int b);
int print_space(int a);


int main(void)
{
    int i, input_year, input_month, total_day,
        input_years_day, day_of_the_week, count = 0,
        num_of_day_in_month;
        while(1)
        {
            total_day = 0;
            count = 0;
            printf("년, 월을 입력하세요(종료는 0) : ");
            scanf("%d%d", &input_year, &input_month);
            if(input_year == 0)
                break;
            print_template(input_year, input_month);
            for(i = 1 ; i < input_year ; i++)
                total_day += leap_year(i);
            input_years_day = leap_year(input_year);
            for(i = 1 ; i <= input_month ; i++)
            {
                switch(i)
                {
                    case 1: 
                    if(i == input_month)
                    {
                        total_day += 1;
                        num_of_day_in_month = 31;
                        break;
                    }
                    num_of_day_in_month = 31;
                    total_day += num_of_day_in_month;
                    break;
                    case 2:
                    if(input_years_day == 366)
                    {
                        if(i == input_month)
                        {
                            total_day += 1;
                            num_of_day_in_month = 29;
                            break;
                        }
                        num_of_day_in_month = 29;
                    }
                    else if(input_years_day == 365)
                    {
                        if(i == input_month)
                        {
                            total_day += 1;
                            num_of_day_in_month = 28;
                            break;
                        }
                        num_of_day_in_month = 28;
                    }
                    total_day += num_of_day_in_month;
                    break;
                    case 3:
                    if(i == input_month)
                    {
                        total_day += 1;
                        num_of_day_in_month = 31;
                        break;
                    }
                    num_of_day_in_month = 31;
                    total_day += num_of_day_in_month;
                    break;
                    case 4:
                    if(i == input_month)
                    {
                        total_day += 1;
                        num_of_day_in_month = 30;
                        break;
                    }
                    num_of_day_in_month = 30;
                    total_day += num_of_day_in_month;
                    break;
                    case 5:
                    if(i == input_month)
                    {
                        total_day += 1;
                        num_of_day_in_month = 31;
                        break;
                    }
                    num_of_day_in_month = 31;
                    total_day += num_of_day_in_month;
                    break;
                    case 6:
                    if(i == input_month)
                    {
                        total_day += 1;
                        num_of_day_in_month = 30;
                        break;
                    }
                    num_of_day_in_month = 30;
                    total_day += num_of_day_in_month;
                    break;
                    case 7:
                    if(i == input_month)
                    {
                        total_day += 1;
                        num_of_day_in_month = 31;
                        break;
                    }
                    num_of_day_in_month = 31;
                    total_day += num_of_day_in_month;
                    break;
                    case 8:
                    if(i == input_month)
                    {
                        total_day += 1;
                        num_of_day_in_month = 31;
                        break;
                    }
                    num_of_day_in_month = 31;
                    total_day += num_of_day_in_month;
                    break;
                    case 9:
                    if(i == input_month)
                    {
                        total_day += 1;
                        num_of_day_in_month = 30;
                        break;
                    }
                    num_of_day_in_month = 30;
                    total_day += num_of_day_in_month;
                    break;
                    case 10:
                    if(i == input_month)
                    {
                        total_day += 1;
                        num_of_day_in_month = 31;
                        break;
                    }
                    num_of_day_in_month = 31;
                    total_day += num_of_day_in_month;
                    break;
                    case 11:
                    if(i == input_month)
                    {
                        total_day += 1;
                        num_of_day_in_month = 30;
                        break;
                    }
                    num_of_day_in_month = 30;
                    total_day += num_of_day_in_month;
                    break;
                    case 12:
                    if(i == input_month)
                    {
                        total_day += 1;
                        num_of_day_in_month = 31;
                        break;
                    }
                    num_of_day_in_month = 31;
                    total_day += num_of_day_in_month;
                    break;
                }
            }
            day_of_the_week = total_day % 7;
            switch(day_of_the_week)
            {
                case 0:
                break;
                case 1:
                count += print_space(day_of_the_week);
                break;
                case 2:
                count += print_space(day_of_the_week);
                break;
                case 3:
                count += print_space(day_of_the_week);
                break;
                case 4:
                count += print_space(day_of_the_week);
                break;
                case 5:
                count += print_space(day_of_the_week);
                break;
                case 6:
                count += print_space(day_of_the_week);
                break;
            }
            
            for(i = 1 ; i <= num_of_day_in_month ; i++)
            {
                printf("%5d", i);
                count += 5;
                if(count == 35)
                {
                    count = 0;
                    printf("  \n");
                }
            }
            printf("\n");
        }
    return 0;
}

int leap_year(int a)
{
    if((a % 4) == 0)
    {
        if((a % 100) == 0)
        {
            if((a % 400) == 0)
                return 366;
            return 365;
        }
        return 366;
    }
    else
        return 365;
}

void print_template(int a, int b)
{
    printf("           %d년  %d월           \n", a, b);
    printf("           ==========           \n");
    printf("- - - - - - - - - - - - - - - - - - - -\n");
    printf("  SUN  MON  TUE  WED  THU  FRI  SAT\n");
    printf("- - - - - - - - - - - - - - - - - - - -\n");
    return;
}

int print_space(int a)
{
    int i;
    int num = a*5;
    for(i = 0; i < num ; i++)
        printf(" ");
    return num;
}