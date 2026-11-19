/* --------------------------------------------------------------------------
Disciplina  : Algoritmo e Estrutura de Dados 2026S1
Nome        : Maria Thereza Jardim
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1610
Data        : 18/11/2026
Objetivo    : Verificar se existe algum ciclo em um grafo dirigido,
              representando as dependências entre documentos.
Dificuldade : Sintaxe principalmente. (listas de adjacência, ponteiro,
              ponteiro para ponteiro e recursão na DFS).
Uso de IA   : Para elaborar o código e corrigir erros de sintaxe,
              além de ajudar na compreensão da lógica de detecção
              de ciclos.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int w;
    struct cel *prox;
} Cel;

void AdicionaArco(Cel **adj, int a, int b) {
    Cel *novo = (Cel *) malloc(sizeof(Cel));

    novo->w = b;
    novo->prox = adj[a];
    adj[a] = novo;
}

int DfsCiclo(Cel **adj, int v, int pre[], int post[], 
int *cnt, int *cntt) {

    pre[v] = (*cnt)++;
    Cel *p;
    for (p = adj[v]; p != NULL; p = p->prox) {
        int w = p->w;

        if (pre[w] == -1) {
            if (DfsCiclo(adj, w, pre, post, cnt, cntt)) {
                return 1;
            }
        }
        else {
            if (post[w] == -1) {
                return 1;
            }
        }
    }

    post[v] = (*cntt)++;
    return 0;
}

int TemCiclo(Cel **adj, int n) {
    int *pre = (int *) malloc((n + 1) * sizeof(int));
    int *post = (int *) malloc((n + 1) * sizeof(int));

    int cnt = 0;
    int cntt = 0;
    int ciclo = 0;

    for (int v = 1; v <= n; v++) {
        pre[v] = -1;
        post[v] = -1;
    }

    for (int v = 1; v <= n; v++) {
        if (pre[v] == -1) {
            if (DfsCiclo(adj, v, pre, post, &cnt, &cntt)) {
                ciclo = 1;
                break;
            }
        }
    }
    free(pre);
    free(post);
    return ciclo;
}

void LiberaGrafo(Cel **adj, int n) {
    for (int v = 1; v <= n; v++) {
        Cel *p = adj[v];
        while (p != NULL) {
            Cel *lixo = p;
            p = p->prox;
            free(lixo);
        }
    }
    free(adj);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);
        Cel **adj = (Cel **) malloc((N + 1) * sizeof(Cel *));

        for (int v = 1; v <= N; v++) {
            adj[v] = NULL;
        }
        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);

            AdicionaArco(adj, A, B);
        }

        if (TemCiclo(adj, N)) {
            printf("SIM\n");
        }
        else {
            printf("NAO\n");
        }
        LiberaGrafo(adj, N);
    }

    return 0;
}