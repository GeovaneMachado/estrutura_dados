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

int menu(int opc) //Menu do programa
{
    printf("\n*****MENU*****");
    printf("\n[0] Sair\n[1] Adicinar\n[2] Excluir\n[3] Listar em ordem\n[4]Listar ordem inversa\n[5] Contar elementos\n");
    scanf("%i", &opc);
    return opc; //retorna a opcao desejada 
}


int Void(student *list) //Verefica se a lista é vazia
{
    if(list != NULL) return 0;
    else return 1;
}

student *Delete(student *first)//Deleta um elemento na lista
{
    student *assistant, *previous, *nulo= NULL;
    int confere, cont;
    char delete_reg[TAM_REG]; 
    scanf("%s", delete_reg); //Le o elemento para deletar
    for(assistant=first; assistant != NULL; assistant = assistant->next)//for para percorrer a lista
    {
        confere =strcmp(delete_reg, assistant->resgitration); //Compara os valores, se for 0 sao iguais
        if(confere == 0) //Verifica se os elementos sao iguais
        {
            confere = 1;
            if (assistant == first)//Verifica se assistant e igual a first 
            {
                first = first->next; // first aponta para proximo se forem iguais
                free(assistant);
                cont = count_student(first);
                if(cont == 0) return nulo;
                return first;
            }
            else 
            {
                for(previous=first;previous!=NULL; previous=previous->next) //For para comparar qual é igual depois do primeiro e deletar
                {
                    if(previous->next == assistant) //Verifica se o proximo de previous é igual a assistant
                    {
                        previous->next = assistant->next; //o proximo de previous recebe o proximo de assistant
                        free(assistant);//Deleta elemento da lista
                        cont = count_student(first);
                        if(cont == 0) return nulo;
                        return first;
                    }
                }
            }
        }   
    }
    if(confere != 0) return first;     
}

void print_Student(student *people) //Emprime os estudantes cadastrados
{
    if(Void(people)) printf("Lista vazia!");
    else
    {
        student *i;
        for(i=people;i!=NULL;i=i->next)
        {
            printf("\n-------------------------------");
            printf("\nRegistration: %s\nName: %s", i->resgitration, i->name);
            printf("\nNascimento: %i/%i/%i", i->birth.day, i->birth.moth, i->birth.year);
            printf("\nAverage: %.f", i->average);
            printf("\n-------------------------------");
        }    
    }
}

void print_reverse(student *first) //Impime a lista em ordem inversa
{
    if(first==NULL) return; //Verifica se first é NULL para parar a recursao
    else
    {
        print_reverse(first->next); //aponta para o proximo elemento da lista
        printf("\n-------------------------------");
        printf("\nRegistration: %s\nName: %s", first->resgitration, first->name);
        printf("\nNascimento: %i/%i/%i", first->birth.day, first->birth.moth, first->birth.year);
        printf("\nAverage: %.f", first->average);
        printf("\n-------------------------------\n");        
    }//apos final que ira retorna o print de forma inversa
}


int count_student(student *first) //Conta quantos cadastros tem na lista
{
        student *i;
        int count=0;
        for(i=first;i!=NULL;i=i->next) count++; // percorre a lista e faz o acrescimo em 1 na variavel count
        return count; //Retorna a contagem
}

void freeMemory(student *first)
{
    student *previous=first, *assistant;
    for(assistant=first->next;assistant!=NULL;assistant =assistant->next)
    {
        free(previous);
        printf('-');
        previous = assistant;
    }
}