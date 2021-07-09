#include <stdio.h>

int main() 
{
    int vetor[3], i, ant_sort[3];
    for(i =0; i<3;i++)
    {
        scanf("%i",&vetor[i]);
    }
    printf("%i\t%i\t%i\n", vetor[0], vetor[1], vetor[2]);
    ant_sort[3] = sort(vetor[3]);
    //sort(vetor[3]);
    printf("%i\t%i\t%i\n", ant_sort[0], ant_sort[1], ant_sort[2]);
    for(i = 0; i<3; i++)
    {
        printf("%i\n", vetor[i]);
    }
    for(i = 0; i<3; i++)
    {
        printf("%i\n", ant_sort[i]);
    }
    
    return 0;
}


int sort(int vetor[3])
{
    int menor = vetor[2], maior = vetor[0], medio = vetor[1], i;
    for(i= 0; i < 3; i++)
    {
        if (maior < menor && maior < medio && menor > medio)
        {
            menor = maior;
            medio = menor;
        }
        printf("%i  %i    %i", maior, medio, menor);  
    }

}
/*{
    int *valor[3];
    *valor[0] = &vetor[0];
    *valor[1] = &vetor[1];
    *valor[2] = &vetor[2];
    if(vetor[0] > vetor[2] && vetor[0] > vetor[1])
    {
        *valor[0] = vetor[0];
        if(vetor[1]> vetor[2])
        {
            *valor[1] = vetor[2];
            *valor[2] = vetor[1];
        }
        else
        {
            *valor[2] = vetor[2];
            *valor[1] = vetor[1];
        }
    }
    else if(vetor[1] > vetor[0] && vetor[1] > vetor[2])
    {
        *valor[0] = vetor[1];
        if(vetor[0]> vetor[2])
        {
            *valor[1] = vetor[2];
            *valor[2] = vetor[0];
        }
        else
        {
            *valor[2] = vetor[2];
            *valor[1] = vetor[0];
        }
    }
    else
    {
        *valor[0] = vetor[2];
        if(vetor[0]> vetor[1])
        {
            *valor[1] = vetor[1];
            *valor[2] = vetor[0];
        }
        else
        {
            *valor[2] = vetor[1];
            *valor[1] = vetor[0];
        }
    }
    return vetor[3];
}*/

