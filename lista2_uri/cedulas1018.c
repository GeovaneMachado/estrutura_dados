#include<stdio.h>

int main()
{
    int notas, N, tot_notas[7] = {0, 0, 0, 0, 0, 0, 0}, i = 0, valor;
    scanf("%i", &N);
    valor = N;
    while (N > 0)
    {    
        if(N < 100 && N >= 50)
        {    
            notas = 50;
            i = 1;
        }
        else if(N < 50 && N >= 20)
        {          
            notas = 20;
            i = 2;
        }
        else if(N < 20 && N >= 10)
        {          
            notas = 10;
            i = 3;
        }
        else if(N < 10  && N >= 5)
        {            
            notas = 5;
            i = 4;
        }
        else if(N < 5  && N >= 2)
        {
            notas = 2;
            i = 5;
        }
        else if(N < 2  && N >= 1)
        {      
            notas = 1;
            i = 6;
        }
        else
        {
            notas = 100;
            i= 0;
        }
        N = N - notas;
        tot_notas[i]++;
    }
    printf("%i\n", valor);
    printf("%i nota(s) de R$ 100,00\n", tot_notas[0]);
    printf("%i nota(s) de R$ 50,00\n", tot_notas[1]);
    printf("%i nota(s) de R$ 20,00\n", tot_notas[2]);
    printf("%i nota(s) de R$ 10,00\n", tot_notas[3]);
    printf("%i nota(s) de R$ 5,00\n", tot_notas[4]);
    printf("%i nota(s) de R$ 2,00\n", tot_notas[5]);
    printf("%i nota(s) de R$ 1,00\n", tot_notas[6]);
    return 0;
}