#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM_REG 10
#define TAM_NAME 40

typedef struct //struct da data de nascimento do aluno  
{
    int day; 
    int moth;
    int year;
}Date;

typedef struct //struct da ficha do aluno
{
    char resgitration[TAM_REG]; //matricula
    char name[TAM_NAME];//nome
    Date birth;//nascimento
    float average;//media das notas
    struct student *next; // proximo aluno
}student;


int Void(student *list) //Verefica se a lista é vazia
{
    if(list != NULL) return 0;
    else return 1;
}

student *Delete(student *first)//Deleta um elemento na lista
{
    student *assistant, *previous;
    int confere, cont;
    char delete_reg[TAM_REG]; 
    scanf("%s", delete_reg); //Le o elemento para deletar
    if(Void(first))
    {
        printf("Lista vazia!\n"); //Verefica se a lista é vazia
        return NULL;
    }
    else
    {
        for(assistant=first; assistant != NULL; assistant = assistant->next)//for para percorrer a lista
        {
            confere =strcmp(delete_reg, assistant->resgitration); //Compara os valores, se for 0 sao iguais
            if(confere == 0) //Verifica se os elementos sao iguais
            {
                confere = 1;
                if (assistant == first)//Verifica se assistant e igual a first 
                {
                    if(first->next == NULL)
                    {
                        //free(assistant);
                        return NULL;
                    }
                    else
                    {
                        first = first->next; // first aponta para proximo se forem iguais
                        free(assistant);
                        return first;
                    }
                }
                else 
                {
                    for(previous=first;previous!=NULL; previous=previous->next) //For para comparar qual é igual depois do primeiro e deletar
                    {
                        if(previous->next == assistant) //Verifica se o proximo de previous é igual a assistant
                        {
                            previous->next = assistant->next; //o proximo de previous recebe o proximo de assistant
                            free(assistant);//Deleta elemento da lista
                            return first;
                        }
                    }
                }
            }   
        }
        if(confere != 0) return first;     
    }
}

void print_Student(student *people) //Emprime os estudantes cadastrados
{
    if(Void(people)) printf("Lista vazia!\n");
    else
    {
        student *i;
        for(i=people;i!=NULL;i=i->next)
        {
            printf("%s, %s", i->resgitration, i->name);
            printf(", %i/%i/%i", i->birth.day, i->birth.moth, i->birth.year);
            printf(", %.2f\n", i->average);
        }    
    }
}

void print_reverse(student *first) //Impime a lista em ordem inversa
{
    if(first==NULL) return; //Verifica se first é NULL para parar a recursao
    else
    {
        print_reverse(first->next); //aponta para o proximo elemento da lista
        printf("%s, %s", first->resgitration, first->name);
        printf(", %i/%i/%i", first->birth.day, first->birth.moth, first->birth.year);
        printf(", %.2f\n", first->average);     
    }//apos final que ira retorna o print de forma inversa
}


int count_student(student *first) //Conta quantos cadastros tem na lista
{
        student *i;
        int count=0;
        for(i=first;i!=NULL;i=i->next) count++; // percorre a lista e faz o acrescimo de 1 na variavel count
        return count; //Retorna a contagem
}

void freeMemory(student *first) //Libera o espaço na memoria
{
    student *previous=first, *assistant; //Variavel previous aponta para first
    while(previous !=NULL) //While que ira caminha o previous 
    {
        assistant = previous->next; //assistant aponta para o proximo de previous
        free(previous); //previous é apagado
        previous = assistant; //previous aponta para o proximo da lista
        printf("-");
    }
    printf("\n");
}


int main()
{
    student *people , *assistant, *first=NULL, *previous=first, *i;
    char resg[TAM_REG], name[TAM_NAME];
    int opc, stop = 1, cont;
    while (stop !=0)
    {    
        scanf("%i", &opc);
        switch (opc)
        {
            case 1: //Adicionar elementos a lista
                people = (student *)malloc(sizeof(student));//aloca a memoria
                scanf("%s", people->resgitration);
                scanf("%s", people->name);
                scanf("%d/%d/%d", &people->birth.day, &people->birth.moth, &people->birth.year);
                scanf("%f", &people->average);
                people->next = NULL;
                if(first == NULL) //Se first == NULL first e assistant ira apontar pra people
                {
                    first = people;
                    assistant =people;    
                }
                else //Assistant->next aponta para people e depois recebe os dados
                {
                    assistant->next = people;
                    assistant = people; 
                }
                break;
            case 2: //Deletar elementos
                    first = Delete(first); //Funcao para deletar o elemento se a lista nao for vazia
                    assistant = first; //assistant aponta para o primeiro elemento da lista
                    if(first !=NULL)
                    {
                        while (assistant->next != NULL)
                        {
                            assistant = assistant->next; //atualiza o valor de assistant
                        }
                    }                
                break;
            case 3:    
                print_Student(first); //Imprime os estudantes na ordem de inclusao
                break;
            case 4:
                if(Void(first))printf("Lista vazia!\n");
                else print_reverse(first); //Imprime os estudantes na ordem reversa de inclusao
                break;
            case 5:
                cont = count_student(first);
                printf("%i\n", cont);
                break;
            default: 
                stop = 0;
                break;
        }
    }
    freeMemory(first); //Libera a memoria
    return 0;
}
