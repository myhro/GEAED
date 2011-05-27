#include <stdio.h>
#include <stdlib.h>

typedef struct no *Apontador;

typedef struct {
	int idade;
	char nome[21];
} Pessoa;

typedef struct no {
	Apontador Esq, Dir;
	Pessoa Item;
} No;

typedef struct {
	Apontador Raiz;
} TipoArvore;

void InicializaArvore(TipoArvore *Arvore) {
	Arvore->Raiz = NULL;
}

int TestaRaiz(TipoArvore *Arvore) {
	if(Arvore->Raiz == NULL) {
		return 1;
	}
	return 0;
}

void InserirNo(TipoArvore *Arvore, Pessoa X) {
	if (TestaRaiz(Arvore)) {
		Arvore->Raiz = (Apontador) malloc(sizeof(No));
		Arvore->Raiz->Item = X;
		Arvore->Raiz->Esq = NULL;
		Arvore->Raiz->Dir = NULL;
		return;
	}
}

int main() {
	return 0;
}
