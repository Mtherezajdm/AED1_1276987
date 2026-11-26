/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Thereza Jardim
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1466
Data        : 16/11/2026
Objetivo    : Montar uma árvore binária com valores dados e imprimir na ordem com BFS
Dificuldade : Mexer com as duas structs juntas e percorrer o nivel na ordem correta.
Uso de IA   : Usei IA para fazer funções como remover da fila e para acertar pequenos 
            detalhes necessários para o beecrowd
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int cont;
    struct no *esq;
    struct no *dir;
}No;

typedef struct cel {
    No *item; // ponteiro para um nó da árvore
    struct cel *prox;
}Cel;

No *CriaNo(int x) {
    No *novo;
    novo = (No *) malloc(sizeof(No));
    if(novo == NULL) return NULL;
    
    novo->cont = x;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}


No *Insere(No *r, int x) { // melhor retornar o ponteiro do que void
    if(r == NULL) {
        r = CriaNo(x); // atribua
    }
    else {
        if(x < r->cont) {
            r->esq = Insere(r->esq, x); // atribua
        }
        else {
            r->dir = Insere(r->dir, x);// atribua
        }
    }
    return r; 
}

Cel *CriaCel(No *r) { // tava certo, mas trocamos botar só o valor na fila para botar Nós inteiros
    Cel *novo;
    novo = (Cel *) malloc(sizeof(Cel));
    if(novo == NULL) return NULL;
    
    novo->item = r;
    novo->prox = NULL;
    return novo;
}

void InsereNaFila(Cel *cabeca, No *r) { // conferir os * daq
    Cel *aux = cabeca;

    while(aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = CriaCel(r);
}

Cel *CriaFila(void) { // melhor botar void aí dentro quando a função não recebe argumentos
    Cel *cabeca;
    cabeca = (Cel *) malloc(sizeof(Cel));

    if(cabeca == NULL) return NULL;

    cabeca->item = NULL;
    cabeca->prox = NULL;
    return cabeca;
}

No *RemoveDaFila(Cel *cabeca) {
    Cel *aux = cabeca->prox;
    No *r;
    if(aux == NULL) return NULL;

    cabeca->prox = aux->prox;
    r = aux->item;
    free(aux);
    return r; // r é o item, que é o nó guardado na celula seguinte da cabeça (a 1a)
}

void PercorreNivel(No *r, Cel *cabeca) {
    No *atual;
    int primeiro = 1; // p botar espaço antes dos números que vao ser impressos (só se for o primeiro que nao tem o espaço)
    
    if(r != NULL) {
        InsereNaFila(cabeca, r); // coloca raiz na fila
        while(cabeca->prox != NULL) { // ou seja, enquanto tiver elemento na fila
            atual = RemoveDaFila(cabeca);

            if(primeiro == 0) printf(" ");
            printf("%d", atual->cont);
            primeiro = 0;

            if(atual->esq != NULL) {
                InsereNaFila(cabeca, atual->esq);
            }
            if(atual->dir != NULL) {
                InsereNaFila(cabeca, atual->dir);
            }
        }
    }
}

void LiberaArvore(No *r) {
    if(r == NULL) return;
    LiberaArvore(r->esq);
    LiberaArvore(r->dir);

    free(r);
}
 

int main() {
 
    int C, N, i, x;
    No *r;
    Cel *cabeca;
    
    scanf("%d", &C);
    for(i = 0; i < C; i++) {
        
        r = NULL;
        cabeca = CriaFila();
        scanf("%d", &N);

        while(N > 0) {
            scanf("%d", &x); // não precisa do espaço
            r = Insere(r, x); // tem que botar em algum lugar (r), pq ela retorna a raiz atualizada
            N--;
        }
        
        printf("Case %d:\n", i + 1);
        PercorreNivel(r, cabeca);
        printf("\n\n");
        LiberaArvore(r);
        free(cabeca);   
    }
 
    return 0;
}