/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Thereza Jardim
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1200
Data        : 15/11/2026
Objetivo    : Fazer uma árvora binária de busca baseada nos comandos dados até EOF e 
            imprimi-la por meio de três percursos: prefixo, infixo e posfixo (além de procurar).
Dificuldade : Me confundi na função insere e ao mexer com strings também.
Uso de IA   : Para mexer com strings (lembrar funções que já existem e usá-las)
-------------------------------------------------------------------------- */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char cont;
    struct no *esq;
    struct no *dir;
}No;

void Imprime(char x, int *primeiro) {
    if(*primeiro == 0) printf(" ");

    printf("%c", x);
    *primeiro = 0;
}

void ListaInf(No *r, int *primeiro) {
    if(r != NULL) {
        ListaInf(r->esq, primeiro);
        Imprime(r->cont, primeiro);
        ListaInf(r->dir, primeiro);
    }
}

void ListaPref(No *r, int *primeiro) {
    if(r != NULL) {
        Imprime(r->cont, primeiro);
        ListaPref(r->esq, primeiro);
        ListaPref(r->dir, primeiro);
    }
}

void ListaPosf(No *r, int *primeiro) {
    if(r != NULL) {
        ListaPosf(r->esq, primeiro);
        ListaPosf(r->dir, primeiro);
        Imprime(r->cont, primeiro);
    }
}

int Pesquisa(No *r, char x) { // precisa do *, mas como não vai modificar a raiz nem nada não precisa de **
    if(r == NULL) {
        return 0;
    }
    else if(x == r->cont) {
        return 1;
    }
    else if(x < r->cont) {
        return Pesquisa(r->esq, x);
    }
    else {
        return Pesquisa(r->dir, x);
    }
}

No *CriaNo(char x) { //precisa do *
    No *novo;
    novo = (No *) malloc(sizeof(No));
    if(novo == NULL) return NULL;
    
    novo->cont = x;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void Insere(No **r, char x) { //  FUNÇÃO MUITO IMPORTANTE!
    if(*r == NULL) {
        *r = CriaNo(x);
    }
    else if(x < (*r)->cont) {
        Insere(&(*r)->esq, x);
    }
    else {
        Insere(&(*r)->dir, x);
    }
} 
 
 
int main() {
    No *r = NULL;
    char x, comando[10];
    int primeiro;

    while(scanf("%s", comando) != EOF) { // lê a string e armazena-a em comando
        if(strcmp(comando, "I") == 0) { // se comando e "I" forem iguais
            scanf(" %c", &x);
            Insere(&r, x);
        }

        else if(strcmp(comando, "P") == 0) {
            scanf(" %c", &x);

            if(Pesquisa(r, x)) {
                printf("%c existe\n", x);
            }
            else {
                printf("%c nao existe\n", x);
            }
        }

        else if(strcmp(comando, "INFIXA") == 0) {
            primeiro = 1;
            ListaInf(r, &primeiro);
            printf("\n");
        }

        else if(strcmp(comando, "PREFIXA") == 0) {
            primeiro = 1;
            ListaPref(r, &primeiro);
            printf("\n");
        }

        else if(strcmp(comando, "POSFIXA") == 0) {
            primeiro = 1;
            ListaPosf(r, &primeiro);
            printf("\n");
        }
    }

    return 0;
}