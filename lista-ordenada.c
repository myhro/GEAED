#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

// Criando a estrutura pessoa, correspondente ao conteudo da celula
typedef struct{
    int Idade;
    char Nome[51];
}Pessoa;

// Criando o tipo Apontador, que é um ponteiro que aponta para o tipo celula
typedef struct celula *Apontador;

//Redefine celula e define a estrutura , criando o tipo Celula
typedef struct celula{
    Pessoa Item;
    Apontador Prox;
    Apontador Ant;
}Celula;

//Cria a estrutura TipoLista, que terá dois apontadores para ter
// a referência do inicio e fim da lista
typedef struct{
    Apontador Primeiro;
    Apontador Ultimo;
}TipoLista;

//Função que inicializa a lista (deve ser utilizada no inicio do main)
void IniciarLista(TipoLista *Lista){
	//Aloca(cria) a celula cabeça
    Lista->Primeiro = (Apontador) malloc(sizeof(Celula));
    // O ponteiro Prox do Primeiro ainda nao aponta a lugar algum
    Lista->Primeiro->Prox = NULL;
    // O ponteiro Ant do Primeiro ainda nao aponta a lugar algum
    Lista->Primeiro->Ant = NULL;
    // Ultimo aponta para o mesmo lugar que o Primeiro
    Lista->Ultimo = Lista->Primeiro;
}

//Função que testa se a lista possui celulas além da cabeça
int TesteListaVazia(TipoLista Lista){
	//Caso a lista esteja "vazia" retorna 1, caso contrário, 0
	return(Lista.Primeiro == Lista.Ultimo);
}

//Função que insere uma celula à lista
//Como a lista será alterada é necessário um ponteiro
//O segundo parâmetro terá o conteúdo (Item) da nova célula
void Insere(TipoLista *Lista, Pessoa X){
    Apontador aux, novo, tmp;

    if(TesteListaVazia(*Lista) == 1){
        aux=Lista->Ultimo;
		Lista->Ultimo->Prox = (Apontador) malloc(sizeof(Celula));
		Lista->Ultimo = Lista->Ultimo->Prox;
		Lista->Ultimo->Ant = aux;
		Lista->Ultimo->Item = X;
		Lista->Ultimo->Prox= NULL;
        return;
    }

	aux=Lista->Primeiro->Prox;

    while (aux != NULL && X.Idade > aux->Item.Idade) {
    	aux=aux->Prox;
    	if (aux == NULL) {
			aux = Lista->Ultimo;
    		Lista->Ultimo->Prox = (Apontador) malloc(sizeof(Celula));
			Lista->Ultimo = Lista->Ultimo->Prox;
			Lista->Ultimo->Ant = aux;
			Lista->Ultimo->Item = X;
			Lista->Ultimo->Prox= NULL;
			return;
    	}
    }

    tmp = aux->Ant;
    novo = (Apontador) malloc(sizeof(Celula));
    tmp->Prox = novo;
    aux->Ant = novo;
    novo->Ant = tmp;
    novo->Prox = aux;
    novo->Item = X;
}

//Função que imprime a lista do Primeiro ao Ultimo
void Imprime(TipoLista Lista){
    Apontador aux;
    // o "i" será utilizado para mostrar a posição da célula
    int i=1;

    if(TesteListaVazia(Lista) == 1){
        printf("\n Lista vazia!!\n");
        return;
    }

    // aux aponta para o próximo da lista cabeça
    aux = Lista.Primeiro->Prox;

    //loop que percorre a lista enquanto aux não apontar para NULL(fim da lista)
    while(aux !=NULL){
        printf("\n\n Celula %d \n Idade: %d\n Nome : %s ",i,aux->Item.Idade,aux->Item.Nome);
        i++;
        //aux apontará para a célula seguinte
        aux = aux->Prox;
    }
}

void Retira(TipoLista *Lista, char *nome){
    Apontador aux,tmp,q;
    int op;

    if(TesteListaVazia(*Lista) == 1){
        printf("\n Lista vazia!!\n");
        return;
    }

    tmp = Lista->Primeiro;
    aux = tmp->Prox;
    while(aux!=NULL){
        if(strcmpi(aux->Item.Nome,nome) == 0){
            printf("\n Nome: %s \n Idade: %d\n Deseja retirar? \n [1] Sim \t [2] Nao",nome,aux->Item.Idade);
            while(1){
                if( scanf("%d",&op) == 0 ){
                    fflush(stdin);
                    printf("\n Digite novamente: ");
                    continue;
                }

                if(op == 1){
                    tmp->Prox = aux->Prox;
                    q = aux;

                    if (aux->Prox == NULL) {
						Lista->Ultimo = tmp;
					}
					else {
						aux = aux->Prox;
						aux->Ant = q->Ant;
					}

                    //aux = aux->Prox;
                    //aux->Ant= tmp;
                    free(q);
                    printf("\n Celula retirada.");
                    return;
                }
                else if(op == 2){

                    break;
                }
                else{
                    printf("\n Digite novamente");
                }
            }

        }
        tmp = aux;
        aux = aux->Prox;
    }
    printf("\n Item nao encontrado.");
}

void DesalocarLista(TipoLista *Lista, int op){
    Apontador aux,tmp;

    if(TesteListaVazia(*Lista) == 1){
        printf("\n Lista vazia!!\n");
        return;
    }

    tmp = Lista->Ultimo;
    aux = tmp->Ant;
    while(aux != NULL){
        Lista->Ultimo = aux;
        aux = aux->Ant;
        free(tmp);
        tmp = Lista->Ultimo;
        printf("\n ok");
    }
    free(tmp);
    if (op != 0) {
		IniciarLista(Lista);
    }
    printf("\n Lista desalocada.");
}


int main() {
    int i,j,op;
    Pessoa cadastro;
    TipoLista Relacao;

    IniciarLista(&Relacao);

    while(1){

        system("cls");
        printf("\n Menu \n\n [1] Cadastrar \n [2] Remover Cadastro \n [3] Listar cadastros \n [4] Limpar \n [5] Sair \n\n Opcao: ");

        while(1){
            if( scanf("%d",&op) == 0){
                printf("\n Tente novamente");
                fflush(stdin);
                continue;
            }
            if(op >=1 && op <=5 ){
                break;
            }
            printf("\n Tente novamente");
        }
        if (op == 1){
            system("cls");
            printf("\n Digite: \n Nome: ");
            fflush(stdin);
            scanf("%50[^\n]",cadastro.Nome);
            printf("\n Idade: ");
            fflush(stdin);
            scanf("%d",&cadastro.Idade);

            Insere(&Relacao,cadastro);
            getch();
        }
        if( op == 2){
            system("cls");
            printf("\n Digite o nome do cadastro que deseja remover: ");
            fflush(stdin);
            scanf("%50[^\n]",cadastro.Nome);
            Retira(&Relacao,cadastro.Nome);
            getch();
        }
        if( op == 3){
            Imprime(Relacao);
            getch();
        }
        if( op == 4){
            DesalocarLista(&Relacao,1);
            getch();
        }
        if( op == 5){
            break;
        }
    }

    DesalocarLista(&Relacao,0);
	return(0);
}
