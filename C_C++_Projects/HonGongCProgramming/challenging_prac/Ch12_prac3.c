//키보드로 세 단어를 입력하여 사전 순서대로 출력하는 프로그램 

#include <stdio.h>

void wordcmp(char *str1, char *str2, char *str3);

int main(void)
{
    char word1[20], word2[20], word3[20];
    printf("세 단어 입력 :");
    scanf("%s%s%s", word1, word2, word3);
    wordcmp(word1, word2, word3);
    return 0;
}

void wordcmp(char *word1st, char *word2nd, char *word3rd)
{
    char *tmp;
    char cmp;
    char count = 0;
    while(((*word1st == *word2nd) && (*word2nd == *word3rd)) && (*word1st != '\0'))
    {
        word1st++;
        word2nd++;
        word3rd++;
        count++; 
    }
    if (*word1st > *word2nd)
    {
        tmp = word1st;
        word1st = word2nd;
        word2nd = tmp;
    }
    if (*word1st > *word3rd)
    {
        tmp = word1st;
        word1st = word3rd;
        word3rd = tmp;
    }
    if (*word2nd > *word3rd)
    {
        tmp = word2nd;
        word2nd = word3rd;
        word3rd = tmp;
    }
    
    word1st -= count;
    word2nd -= count;
    word3rd -= count;
    
    printf("%s, %s, %s", word1st, word2nd, word3rd);
    return;
}