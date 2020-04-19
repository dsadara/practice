#include <stdio.h>

int main(void)
{
    int usage, section, base_rate, total = 0;
    
    
    printf("전기 사용량을 입력하세요(kw) : ");
    scanf("%d", &usage);
    
    if((usage >= 1) && (usage <= 100))
    {
        section = 1;
        total += 370;
    }    
    else if((usage >= 101) && (usage <= 200))
    {
        section = 2;
        total += 660;
    }
    else if((usage >= 201) && (usage <= 300))
    {
        section = 3;
        total += 1130;
    }
    else if((usage >= 301) && (usage <= 400))
    {
        section = 4;
        total += 2710;
    }
    else if((usage >= 401) && (usage <= 500))
    {
        section = 5;
        total += 5130;
    }
    else
    {
        section = 6;
        total += 9330;
    }
    
    switch(section)
    {
        case 6:
        total += (double)(usage - 500) * 494.00;
        total += (double)100 * 274.30;
        total += (double)100 * 184.30;
        total += (double)100 * 127.80;
        total += (double)100 * 88.50;
        total += (double)100 * 52.00;
        break;
        case 5: 
        total += (double)(usage - 400) * 274.30;
        total += (double)100 * 184.30;
        total += (double)100 * 127.80;
        total += (double)100 * 88.50;
        total += (double)100 * 52.00;
        break;
        case 4:
        total += (double)(usage - 300) * 184.30;
        total += (double)100 * 127.80;
        total += (double)100 * 88.50;
        total += (double)100 * 52.00;
        break;
        case 3:
        total += (double)(usage - 200) * 127.80;
        total += (double)100 * 88.50;
        total += (double)100 * 52.00;
        break;
        case 2:
        total += (double)(usage - 100) * 88.50;
        total += (double)100 * 52.00;
        break;
        case 1:
        total += (double)usage * 52.00;
        break; 
        default:
        printf("제대로 된 숫자를 입력하세요!");
    }
    
    total = (double)total * 1.09;
    
    printf("이번 달 요금은 %d원입니다. ", total);
    
    
    return 0;
}