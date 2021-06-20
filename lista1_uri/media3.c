#include<stdio.h>
int main()
{
    float nota1, nota2, nota3, nota4, media, exame;
    scanf("%f %f %f %f", &nota1, &nota2, &nota3, &nota4);
    media = (nota1 * 0.2 + nota2 * 0.3 + nota3 * 0.4 + nota4 * 0.1);
    if (media >= 7.0)
    {
        printf("Media: %.1f\nAluno aprovado.\n", media);
    }
    else if (media < 5.0)
    {
        printf("Media: %.1f\nAluno reprovado.\n", media);
    }
    else
    {
        printf("Media: %.1f\nAluno em exame.\n", media);
        scanf("%f", &exame);
        printf("Nota do exame: %.1f\n", exame);
        media = (media + exame)/2;
        if (media >= 5.0)
        {
            printf("Aluno aprovado.\n");         
        }
        else
        {
            printf("Aluno reprovado.\n");
        }
         printf("Media final: %.1f\n", media);
    }
    return 0;
}