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
    gets(frase); fflush(stdin);
    inverte(frase);
    printf("\n\n\t");
    puts(frase);
    return(0);
}
