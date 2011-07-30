/*
 Universidade Estadual de Montes Claros - Unimontes
 GEAED - Grupo de Estudos em Algoritmos e Estruturas de Dados

 Descrição: Verifica se uma determinada frase é um palindromo,
            percorrendo o vetor da direita para a esquerda e vice-versa
            comparando letra por letra enquanto as variaveis que o
            percorrem nao se encontrem (meio da palavra).
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

// Funcao que verifica o palindromo
int palindromo(char *frase){
    int i,j;

    //printf("\n %d \n", strlen(frase));
    for(i=0,j=(strlen(frase)-1); i!=j && j>=i; i++,j--){

            if(frase[i] != frase[j]){
                return(1);
            }
    }
    return(0);
}


int main(){
    char frase[100];

    printf("\n\t Teste: Palindromo \n\n");
    printf(" Digite uma frase: ");
    gets(frase); fflush(stdin);

    if(palindromo(frase)){
        printf("\n Nao e um palindromo... :( ");
    }
    else{
        printf("\n :D  Palindromoo!!!");
    }

    printf("\n\n Fim do programa. \n\n");
    system("pause");
    return(0);
}
