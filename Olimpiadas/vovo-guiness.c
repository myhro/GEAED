#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    int aparicoes;
}Pessoa;

int compare(const void* a, const void* b)
{
  return ( ((Pessoa *)a)->id - ((Pessoa *)b)->id );
}

int pesquisa(int id, Pessoa *v,int tam){
    int i;
    for(i=0; i<tam; i++){
        if(id == v[i].id){
            return i;
        }
    }
    return -1;
}


int main (){

    Pessoa *v,tmp;
    int n,m,teste=1,tam=0,i,j,maior,segundomaior,resp;

    while(1){
        tam=0;
        scanf("%d %d",&n,&m);
        if(n == 0 && m == 0)
            break;
        v = (Pessoa*) malloc(n*m*sizeof(Pessoa));
        for(i=0; i<n*m; i++){
            v[i].id=0;
            v[i].aparicoes=0;
        }
        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                scanf("%d",&tmp.id);
                resp = pesquisa(tmp.id,v,tam);
                if(resp != -1){
                    v[resp].aparicoes++;
                }
                else{
                    v[tam].id = tmp.id;
                    v[tam].aparicoes++;
                    tam++;

                }
            }
        }
        maior = 0;
        for(i=0; i<n*m; i++){
            if(v[i].aparicoes > maior)
                maior = v[i].aparicoes;
        }
        segundomaior = 0;
        for(i=0; i<n*m; i++){
            if(v[i].aparicoes > segundomaior && v[i].aparicoes != maior)
                segundomaior = v[i].aparicoes;
        }
        qsort (v, tam, sizeof(Pessoa), compare);
        printf("Teste %d\n",teste);
        for(i=0; i<tam; i++){
            if(v[i].aparicoes == segundomaior)
                printf("%d ",v[i].id);
        }
        printf("\n\n");
        teste++;
        free(v);
    }

    return 0;
}
