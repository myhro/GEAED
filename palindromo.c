/*
 Universidade Estadual de Montes Claros - Unimontes
 GEAED - Grupo de Estudos em Algoritmos e Estrutura de Dados
 Descrição: Verifica se uma determinada frase é um palindromo
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


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
