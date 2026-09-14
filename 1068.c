/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Thereza Jardim
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 12/09/2026
Objetivo    : Indicar se a quant de parênteses está correta ou não na expressão.
Dificuldade : Pensar em como fazer tudo com caracteres.
Uso de IA   : Usei IA para lembrar como lia a expressão. Além disso, com ela percebi que fiz a pilha "ao contrário".
Irei refazer com o começo da pilha sendo o caracter que sucede a cabeça.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct exp {
    char cont; // fiz um local de conteúdo mas não precisava usar
    struct exp *prox;
} Exp;
 
int main() {
    int i, certo;
    char expressao[1000];
    Exp *inicio, *novo, *aux, *retira;
    
    while(scanf("%s", expressao) != EOF) { // enquanto se recebe uma expressão:
        inicio = (Exp*) malloc(sizeof(Exp)); //cabeça da pilha
        inicio->prox = NULL;
        certo = 1;
        
        for(i = 0; expressao[i] != '\0'; i++) { //percorre todos os caracteres da expressão
            if(expressao[i] == ')' && inicio->prox == NULL) { // se houver um ')' antes de um '('
                certo = 0; // 0 = "errado"
                break;
            }
            else if(expressao[i] == '(') { //se houver um '('
                novo = (Exp*) malloc(sizeof(Exp)); //cria-se um Exp, que representa um parêntese aberto
                novo->cont = '(';
                novo->prox = NULL;
                aux = inicio;
                while(aux->prox != NULL) {
                    aux = aux->prox;
                }
                aux->prox = novo;
            }
            else if(expressao[i] == ')' && inicio->prox != NULL) { //se houver um ')' que feche um '(' que já estava la
                aux = inicio;
                while(aux->prox != NULL) {
                    retira = aux;
                    aux = aux->prox;
                }
                retira->prox = NULL; // tira o '(' que tinha sido aberto antes
                free(aux);
            }
        }
        if(inicio->prox != NULL) // se sobrar nenhum '(', nem todos foram fechados e, portanto, deu errado
            certo = 0;
        if(certo == 1) { // se não tiver dado nada errado
            printf("correct\n");
        }
        if(certo == 0) {
            printf("incorrect\n");
        }
        while(inicio->prox != NULL) {
            aux = inicio;
            inicio = inicio->prox;
            free(aux); //a partir do inicio, libera-se a memória
        }
        free(inicio);
            
    }
 
    return 0;
}