/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Thereza Jardim
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1080
Data        : 24/08/2026
Objetivo    : Apresentar o maior valor lido e sua posição dentre 100 inteiros lidos.
Dificuldade : Percorrer o vetor e achar o maior valor.
Uso de IA   : Não usei IA.
-------------------------------------------------------------------------- */

#include <stdio.h>
 
int main() {
 
        int v[100], i, maior, pos;
             
        for(i = 0; i < 100; i++) {
            scanf("%d\n", &v[i]); // leitura do vetor
        }
        
        maior = v[0];
        pos = 0;

        for(i = 1; i < 100; i++) { // a partir do segundo termo, compara o maior com o atual
            if(v[i] > maior) { // se houver algum maior que o "maior", o valor é substituido
                maior = v[i];
                pos = i;
            }
        }
        printf("%d\n%d\n", maior, pos + 1); // imprime o maior número e sua posição
 
    return 0;
}