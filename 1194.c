/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Thereza Jardim
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1194
Data        : 14/11/2026
Objetivo    : Imprimir uma árvore binária de busca do modo posfixo tendo apenas sua ordem
            infixa e prefixa.
Dificuldade : Fazer a recursão principal corretamente.
Uso de IA   : Para arrumar a lógica da minha recursão
-------------------------------------------------------------------------- */


#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char cont;
    struct no *esq;
    struct no *dir;
}No;

void LePos(No *r) {
    if(r == NULL) {
        return;
    }
    LePos(r->esq);
    LePos(r->dir);
    printf("%c", r->cont);
}


No *Cria(char x) {
    No *novo;
    novo = (No *) malloc(sizeof(No));
    if(novo == NULL) return NULL;

    novo->cont = x;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}


No *Constroi(char *pref, char *inf, int n) {
    No *r;
    int i;
    if(n == 0) return NULL;

    r = Cria(pref[0]);
    if(r == NULL) return NULL;

    for(i = 0; i < n; i++) {
        if(inf[i] == pref[0]) break; // i = qnt nós da subárvore esquerda e n-i-1, a da direita
    }
    r->esq = Constroi(pref + 1, inf, i);
    r->dir = Constroi(pref + i + 1, inf + i + 1, n - i - 1);
    return r;
}


void Libera(No *r) {
    if(r != NULL) {
        Libera(r->esq);
        Libera(r->dir);
        free(r);
    }
}

 
int main() {
    int C, N;
    No *r;
    char pref[53], inf[53]; // alfabetos (52) + '\0'
    
    scanf("%d", &C);
    while(C > 0) {
        scanf("%d", &N);
        
        scanf("%s %s", pref, inf);
        r = Constroi(pref, inf, N);

        LePos(r);
        printf("\n");
        C--;
        Libera(r);
    }
    
    return 0;
}