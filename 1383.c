/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Thereza Jardim
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383
Data        : 24/08/2026
Objetivo    : Dizer se a matriz lida é a solução de um problema de Sudoku ou não.
            (num matrizes é dado, imprime Instancia k\nSIM/NAO\n\n).
Dificuldade : Conferir se tem ou não repetição nos 9 quadradinhos 3x3, um por vez 
Uso de IA   : Usei IA para finalizar o meu raciocínio de checagem dos 9 quadradinhos 3x3.
-------------------------------------------------------------------------- */

#include <stdio.h>
 
int main() {
 
    int i, j, m[9][9], k, n, x, a, b, c, d, repetido = 0; 
    scanf("%d", &n); // leitura do número de matrizes

    for(x = 0; x < n; x++) { // percorre a qnt de matrizes
        for(i = 0; i < 9; i++) {
            for(j = 0; j < 9; j++) {
                scanf("%d", &m[i][j]); // leitura das matrizes
            }
        }

        for(i = 0; i < 9; i++) { // percorre os elementos das linhas
            for(j = 0; j < 9; j++) {
                for(k = j + 1; k < 9; k++) {
                    if(m[i][j] == m[i][k]) {
                        repetido = 1; // se houver um elemento repetido na linha, repetido == 1
                        break;
                    }
                }
                if(repetido == 1) {
                break;
            }
            }
            if(repetido == 1) {
                break;
            }
        }
            

        if(repetido == 0) { // se estiver tudo certo, a verificação continua
            for(j = 0; j < 9; j++) { // percorre os elementos das colunas
                for(i = 0; i < 9; i++) {
                    for(k = i + 1; k < 9; k++) {
                        if(m[i][j] == m[k][j]) {
                            repetido = 1; // se houver um elemento repetido na coluna, repetido == 1
                            break;
                        }
                    }
                    if(repetido == 1) {
                    break;
                }
                }
                if(repetido == 1) {
                    break;
                }
            }
            

            if(repetido == 0) { // se estiver tudo certo, a verificação continua
                for(i = 0; i < 9; i += 3) { // checa os 9 quadradinhos 3x3 um por vez
                    for(j = 0; j < 9; j += 3) {

                        for(a = i; a < i + 3; a++) {
                            for(b = j; b < j + 3; b++) {

                                for(c = i; c < i + 3; c++) {
                                    for(d = j; d < j + 3; d++) {
                                        if(m[a][b] == m[c][d] && (a != c || b != d)) { // se dentro do 3x3 tiver algum repetido (que não seja ele mesmo)
                                            repetido = 1;
                                            break;
                                        }
                                    }
                                    if(repetido == 1) break;
                                }
                                if(repetido == 1) break;
                            }
                            if(repetido == 1) break;
                        }
                        if(repetido == 1) break;
                    }
                    if(repetido == 1) break;
                }
            }
        }

        printf("Instancia %d\n", x + 1);
        if(repetido == 1) {
            printf("NAO\n\n"); // se algum elemento repetiu, imprime NAO
        }
        else printf("SIM\n\n"); // caso contrário, imprime SIM
        repetido = 0;
    }
    return 0;
}