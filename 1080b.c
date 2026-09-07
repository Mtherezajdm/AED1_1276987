/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Thereza Jardim
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080 (outra versão)
Data        : 01/09/2026
Objetivo    : Apresentar o maior valor lido e sua posição dentre 100 inteiros lidos usando alocação dinâmica de vetores.
Dificuldade : Utilizar função malloc corretamente.
Uso de IA   : Usei para conferir a utilização das funções malloc e free.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
 
int main() {
 
    int *v, i, maior, pos, n;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &n); // descobrimos o tamanho do vetor
    v = (int *) malloc(n * sizeof(int)); // ponteiro vai apontar para n inteiros

    if(v == NULL) { // verifica se o malloc não conseguiu alocar a memória
        printf("Erro de alocação!\n");
        return 1;
    }
             
    printf("Digite os números inteiros a serem analisados: ");
    for(i = 0; i < n; i++) {
        scanf("%d\n", &v[i]); // leitura do vetor
    }
        
    maior = v[0];
    pos = 0;

    for(i = 1; i < n; i++) { // a partir do segundo termo, compara o maior com o atual
        if(v[i] > maior) { // se houver algum maior que o "maior", o valor é substituido
            maior = v[i];
            pos = i;
        }
    }
    printf("%d\n%d\n", maior, pos + 1); // imprime o maior número e sua posição
    
    free(v);

    return 0;
}