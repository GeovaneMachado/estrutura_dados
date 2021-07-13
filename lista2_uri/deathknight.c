#include<stdio.h>
#include<string.h>

int main()
{
    int n_skill, i, j, sum, victory=0;
    char skills[1001];
    scanf("%i", &n_skill);
    for(i = 0; i < n_skill; i++)
    {
        scanf("%s", skills);
        sum = 0;
        for(j = 0; j < strlen(skills); j++)
        {
            if(skills[j] == 'C' && skills[j+1] == 'D') 
            {
                sum++;                
            }
        }
        if(sum == 0)
        {
            victory++;
        }
    }
    printf("%i\n", victory);
    return 0;
}