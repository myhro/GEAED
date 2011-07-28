/*
 Universidade Estadual de Montes Claros - Unimontes
 GEAED - Grupo de Estudos em Algoritmos e Estrutura de Dados
 Descri��o: Algoritmo que inverte a ordem de uma frase
*/

#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void inverte( char *frase ){
    char tmp;
    int i,j;

    for( i=0, j=(strlen(frase)-1); /*i<=j && */j>=i; i++, j-- ){
        tmp=frase[i];
        frase[i]=frase[j];
        frase[j]=tmp;
    }
}

int main(){
    char frase[100];

    printf("\n\t Invertendo uma frase \n\n");

    printf(" Digite uma frase: ");
    gets(frase); fflush(stdin);

    inverte(frase);
    printf("\n Frase invertida: ");
    printf("\n\n\t");
    puts(frase);

    printf("\n Fim do programa. \n\n");
    return(0);
}
