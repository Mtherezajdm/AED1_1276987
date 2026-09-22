/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Thereza Jardim
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/2448
Data        : 22/09/2026
Objetivo    : Ver quanto tempo um carteiro demora para entregar todas as suas encomendas. Ele faz na
            ordem que elas chegam e os números das casas das ruas são crescentes, entretanto não necessariamente
            consecutivos.
Dificuldade : Fazer busca binária (principalmente diferenciar as informações que cada vetor estava me dando).
Uso de IA   : Usei IA para saber como deixar um número em módulo, bem como para ajustar a minha busca.
-------------------------------------------------------------------------- */


#include <stdio.h>
#include <stdlib.h>
#define MAX 45000

int busca_casa(int dest, int casa[], int N) {
    int i = -1, f = N, m; 
    while(i < f-1) { 
        m = (i + f)/2; // encontra o elemento do meio
        if(dest > casa[m]) { // se o destino estiver do meio pra frente
            i = m; // o inicio vira esse meio
        }
        else f = m; // caso contrário (destino p trás), final vira o meio
    } 
    return f; // retorna o "final"
    
}
 
int main() {
 
    int N, M, casa[MAX], encomenda[MAX], i;
    int c_atual, dif, tempo = 0;
    
    scanf("%d %d", &N, &M); // lê número de casas e número de encomendas
    for(i = 0; i < N; i++) {
        scanf("%d", &casa[i]); // lê número de cada casa do vetor casa[]
    }
    for(i = 0; i < M; i++) {
        scanf("%d", &encomenda[i]); // lê número onde cada encomenda deve ser entregue no vetor encomenda[]
        
    }
    
    c_atual = 0; // casa que o carteiro está no momento
    for(i = 0; i < M; i++) { // para cada encomenda
        int nova_posicao = busca_casa(encomenda[i], casa, N); // busca a posicao da casa para qual a encomenda é
        dif = abs(c_atual - nova_posicao); // diferença é o módulo entre a distância das casas (1u = 1 elemento do vetor)
        tempo += dif; // soma-se, ao tempo, a diferença encontrada a cada deslocamento
        c_atual = nova_posicao; // posicao atual do carteiro muda
    }
 
    printf("%d\n", tempo); // impressão do tempo total
 
    return 0;
}