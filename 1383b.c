/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Thereza Jardim
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1383 (outra versão)
Data        : 01/09/2026
Objetivo    : Dizer se a matriz lida é a solução de um problema de Sudoku ou não usando alocação dinâmica de matriz.
            (num matrizes é dado, imprime Instancia k\nSIM/NAO\n\n).
Dificuldade : Entender aonde colocar as funções malloc e free.
Uso de IA   : Usei IA para checar aonde a função free deveria estar.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
 
int main() {
 
    int i, j, k, n, x, a, b, c, d, repetido = 0; 
    int **m;
    printf("Digite o número de sudokus a serem analisados: ");
    scanf("%d", &n); // leitura do número de matrizes

    for(x = 0; x < n; x++) { // percorre a qnt de matrizes

        m = (int **) malloc(9 * sizeof(int *)); // alocando vetor de ponteiros (linhas)
        if(m == NULL) {
            printf("Erro de alocação!\n");
            return 1;
        }

        for(i = 0; i < 9; i++) { // alocando colunas para cada linha
            m[i] = (int *) malloc(9 * sizeof(int));
            if(m[i] == NULL) {
                printf("Erro de alocação!\n");
                return 1;
            }
        }

        printf("Digite os números contidos na matriz: ");
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
        
        for(i = 0; i < 9; i++) {
            free(m[i]);
        }
        free(m);

        repetido = 0;
    }

    return 0;
}