/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Thereza Jardim
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1062
Data        : 11/10/2026
Objetivo    : Checar se determinada saída é possível, com uma entrada "pre-estabelecida", implementacao
            de pilha em lista encadeada. Obs: vagões em uma ferrovia.
Dificuldade : Fazer a lógica e a função Possivel
Uso de IA   : Usei para terminar a última função e para ver se realmente da certo
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct cel {
    int cont;
    struct cel *prox;
} Cel;

void Empilha(Cel *topo, int x) {
    Cel *nova;
    nova = (Cel *) malloc(sizeof(Cel));
    if (nova == NULL) return; // se não conseguir alocar memória, interrompe a função

    nova->cont = x;
    nova->prox = topo->prox;
    topo->prox = nova; // a nova célula passa a ser o topo da pilha
}

int Desempilha(Cel *topo) {
    Cel *lixo;
    int x;
    if (topo->prox == NULL) return -1; // se a pilha estiver vazia, não há vagão para retirar

    lixo = topo->prox;
    x = lixo->cont; // guarda o número do vagão antes de liberar a célula
    topo->prox = lixo->prox;
    free(lixo);

    return x; // retorna o número do vagão retirado
}

int Vazia(Cel *topo) {
    if (topo->prox == NULL)
        return 1;
    return 0; // se houver alguma célula, a pilha não está vazia
}

int Possivel(int v[], int N) {
    Cel *topo;
    int prox, x, i;

    topo = (Cel *) malloc(sizeof(Cel)); // cria a cabeça da pilha
    if (topo == NULL) return 0;
    topo->prox = NULL;

    prox = 1;

    for (i = 0; i < N; i++) { // percorre a sequência desejada de saída
        x = v[i]; // vagão que precisa sair neste momento
        while (prox <= N && (Vazia(topo) || topo->prox->cont != x)) {
            Empilha(topo, prox); // coloca na pilha o próximo vagão que chega
            prox++;
        }

        if (!Vazia(topo) && topo->prox->cont == x) { // se o vagão desejado estiver no topo
            Desempilha(topo); // retira esse vagão da pilha
        } else { // se o vagão desejado não estiver no topo e não houver mais vagões para empilhar
            while (!Vazia(topo))
                Desempilha(topo); // libera as células restantes da pilha

            free(topo); // libera a cabeça da pilha
            return 0; // a sequência desejada não pode ser obtida
        }
    }
    free(topo); // libera a cabeça depois de verificar toda a sequência
    return 1;
}


int main() {
    int N, i;
    int v[MAX];

    scanf("%d", &N); // lê a quantidade de vagões

    while (N != 0) {
        while (1) { // lê as várias sequências de saída para esse N
            scanf("%d", &v[0]);
            if (v[0] == 0) // se o primeiro número for zero, termina o bloco atual
                break;

            for (i = 1; i < N; i++) { 
                scanf("%d", &v[i]); // lê os demais números da sequência
            }

            if (Possivel(v, N)) // verifica se é possível obter a sequência usando a pilha
                printf("Yes\n");
            else
                printf("No\n");
        }
        printf("\n"); // separa os resultados dos blocos de tamanhos diferentes

        scanf("%d", &N); // lê o próximo tamanho de bloco
    }

    return 0;
}