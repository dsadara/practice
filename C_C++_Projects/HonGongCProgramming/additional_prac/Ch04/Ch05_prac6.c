#include <stdio.h>

int main(void)
{
    int spd, dist, min, hour;
    double second, time;
    
    printf("거리와 속력 입력 : ");
    scanf("%d%d", &dist, &spd);
    
    time = (double)dist / spd;
    hour = (int)time / 1;
    time = 60 * (time - hour);
    min = (int)(time) / 1;
    time -= min;
    second = (time * 60);
    
    printf("소요시간은 %d시간 %d분 %.3lf초 입니다.", hour, min, second);
    
    return 0;
}