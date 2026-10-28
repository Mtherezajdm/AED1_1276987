/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Thereza Jardim
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1095
Data        : 27/10/2026
Objetivo    : Apresentar uma sequencia conforme um exemplo (um numero cresce de 3 em 3 e o outro decresce de 5 em 5,
            até chegar ao 0)
Dificuldade : 0
Uso de IA   : 0
-------------------------------------------------------------------------- */


#include <stdio.h>
 
int main() {
    
    int i = 1, j = 60;
    
    while(j >= 0) {
        printf("I=%d J=%d\n", i, j);
        i += 3;
        j -= 5;
    }
 
    return 0;
}