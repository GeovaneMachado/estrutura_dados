#include <stdio.h>

int main() 
{
    int numbers[3], i, maior, menor, meio;
    for(i =0; i<3;i++)
    {
        scanf("%i",&numbers[i]);
    }
    if(numbers[0] < numbers[2] && numbers[0] < numbers[1])
    {
        menor = numbers[0];
        if(numbers[1]< numbers[2])
        {
            meio = numbers[1];
            maior = numbers[2];
        }
        else
        {
            maior = numbers[1];
            meio = numbers[2];
        }
    }
    else if(numbers[1] < numbers[0] && numbers[1] < numbers[2])
    {
        menor = numbers[1];
        if(numbers[0]< numbers[2])
        {
            meio = numbers[0];
            maior = numbers[2];
        }
        else
        {
            meio = numbers[2];
            maior = numbers[0];
        }
    }
    else if(numbers[2] < numbers[1] && numbers[2] < numbers[0])
    {
        menor = numbers[2];
        if(numbers[0]< numbers[1])
        {
            meio = numbers[0];
            maior = numbers[1];
        }
        else
        {
            maior = numbers[0];
            meio = numbers[1];
        }
    }
    printf("%i\n%i\n%i\n\n", menor, meio, maior);
    for(i = 0; i<3; i++)
    {
        printf("%i\n", numbers[i]);
    }
    printf("\n");
    return 0;
}
