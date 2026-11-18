/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Thereza Jardim
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1195
Data        : 13/11/2026
Objetivo    : Fazer uma árvora binária de busca e imprimi-la por meio de três 
            percursos: prefixo, infixo e posfixo.
Dificuldade : Sintaxe principalmente. (quando botar ponteiro, ponteiro para ponteiro e &).
Uso de IA   : Para corrigir erros de sintaxe, mas não precisei de ajuda com a lógica.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int cont;
    struct no *dir;
    struct no *esq;
}No;

No *CriaNo(int x) { // precisa ser ponteiro
    No *novo; // precisa ser ponteiro
    novo = (No *) malloc(sizeof(No));
    if(novo == NULL) {
        printf("Erro ao alocar memória!");
        return NULL;
    }
    
    novo->cont = x;
    novo->esq = NULL;
    novo->dir = NULL;
    
    return novo;
}

void Insere(No **r, int x) { // precisa ser ponteiro para ponteiro
    if(*r == NULL) {
        *r = CriaNo(x);
        return;
    }
    
    if((*r)->cont > x) { // precisa desses parenteses no *r
        return Insere(&(*r)->esq, x); // precisa do & e dos parenteses
    }
    else {
        return Insere(&(*r)->dir, x);
    }
}

void LeInfixo(No *r) { // ERD
    if(r != NULL) {
        LeInfixo(r->esq);
        printf(" %d", r->cont);
        LeInfixo(r->dir);
    }
}

void LePrefixo(No *r) { // RED
    if(r != NULL) {
        printf(" %d", r->cont);
        LePrefixo(r->esq);
        LePrefixo(r->dir);
    }
}

void LePosfixo(No *r) { // EDR
    if(r != NULL) {
        LePosfixo(r->esq);
        LePosfixo(r->dir);
        printf(" %d", r->cont);
    }
}

void Livra(No *r) { // precisa ser ponteiro
    if(r != NULL) {
        Livra(r->esq);
        Livra(r->dir);
        free(r); // precisa estar por último nessa ordem
    }
}

 
int main() {
    int C, N, i = 0, j = 0, x;
    No *r = NULL; // declarar corretamente a raiz
    scanf("%d", &C);
    if(C <= 1000) {
        while(i < C) {
            scanf("%d", &N);
            while(j < N) {
                scanf("%d", &x);
                Insere(&r, x); // precisa do &
                j++;
            }
            
            printf("Case %d:\n", i+1);
            printf("Pre.:");
            LePrefixo(r);
            printf("\n");
            printf("In..:");
            LeInfixo(r);
            printf("\n");
            printf("Post:");
            LePosfixo(r);
            printf("\n\n");
            
            
            j = 0;
            i++;
            Livra(r); 
            r = NULL; // precisa pro próximo dar certo
        }
    }
    
 
    return 0;
}