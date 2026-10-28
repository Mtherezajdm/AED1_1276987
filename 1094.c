/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Thereza Jardim
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1094
Data        : 27/10/2026
Objetivo    : Programa que apresente o total de cobaias utilizadas, o total de cada tipo
            de cobaia utilizada e o percentual de cada uma em relação ao total de cobaias
            utilizadas, sendo que o percentual deve ser apresentado com dois dígitos após o ponto.
Dificuldade : 0
Uso de IA   : 0
-------------------------------------------------------------------------- */


#include <stdio.h>
 
int main() {
    
    int N, qnt, qC = 0, qR = 0, qS = 0, i;
    char tipo;
    
    scanf("%d", &N);
    
    for(i = 0; i < N; i++) {
        scanf("%d %c", &qnt, &tipo);
        if(tipo == 'R') qR += qnt;
        else if(tipo == 'S') qS += qnt;
        else if(tipo == 'C') qC += qnt;
    }
    
    printf("Total: %d cobaias\n", qR+qS+qC);
    printf("Total de coelhos: %d\n", qC);
    printf("Total de ratos: %d\n", qR);
    printf("Total de sapos: %d\n", qS);
    printf("Percentual de coelhos: %.2f %%\n", (qC * 100.0) / (qC+qS+qR));
    printf("Percentual de ratos: %.2f %%\n", (qR * 100.0) / (qC+qS+qR));
    printf("Percentual de sapos: %.2f %%\n", (qS * 100.0) / (qC+qS+qR));
    
    return 0;
}