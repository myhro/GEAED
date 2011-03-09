#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int palindromo(char *frase){
    int i,j;
    //printf("\n %d \n", strlen(frase));
    for(i=0,j=(strlen(frase)-1);i!=j && j>=i;i++,j--){

            if(frase[i]!=frase[j]){
                return(1);
            }
    }
    return(0);
}


int main(){
    char frase[100];
    gets(frase); fflush(stdin);
    if(palindromo(frase)){
        printf("nao e um palindromo... :( ");
    }
    else{
        printf(":D  palindromoo!!!");
    }
    return(0);
}
