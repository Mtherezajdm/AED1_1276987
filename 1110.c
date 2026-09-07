/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Maria Thereza Jardim
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 06/09/2026
Objetivo    : Há uma pilha de cartas (MAX 50). Deve-se descartar a primeira e mover a nova primeira
para o final da pilha repetidas vezes. Fazer esse procedimento até haver apenas 1 carta na pilha.
Deve-se imprimir as cartas descartadas em ordem e a última carta restante no baralho.
Dificuldade : tirar a primeira carta e colocá-la no final da pilha de cartas; liberar a memória de uma fila.
Uso de IA   : Usei IA para entender essas partes que eu tive mais dificuldade. Ela melhorou o meu raciocínio.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct cel { // defini uma estrutura cel e a apelidei de Carta (cada uma tem seu número e uma próxima)
    int num;
    struct cel *prox;
}Carta;
 
int main() {
    
    int n, i, qntlst, qntdesc;
    Carta *lst, *aux, *novo, *descartes;
    scanf("%d", &n);
    while(n != 0 && n <= 50) { // caso o número de cartas estiver entre 1 e 50, fazer esse procedimento:
        lst = NULL; // criação da lista no NULL
        
        for(i = 0; i < n; i++){ // cria n cartas, cada uma com o seu número e sempre sendo botadas logo antes do NULL
            novo = (Carta *) malloc(sizeof(Carta)); 
            
            if(novo == NULL) return 1;
            
            novo->num = i + 1;
            novo->prox = NULL;
            if(lst == NULL) { // se for a primeira carta, ela será o começo da lista
                lst = novo;
            }
            else { // se não for a primeira carta
                aux = lst;
                while(aux->prox != NULL) { // auxiliar vai até o final da lista
                    aux = aux->prox;
                }
                aux->prox = novo; // bota nova carta no final da lista (depois do aux)
            }
        }
        
        qntlst = n;
        descartes = NULL;
        qntdesc = 0;
        while(qntlst > 1) {
            novo = lst;
            lst = lst->prox; //tira a primeira carta (lst vira lst->prox)
            novo->prox = NULL; // a ex primeira carta fica sozinha, ela só tem o valor dela e o NULL como próx
            if(descartes == NULL) {
                descartes = novo; // coloca ela nas descartadas caso seja a primeira a ser descartada
            }
            else {
                aux = descartes;
                while(aux->prox != NULL) {
                    aux = aux->prox;
                }
                aux->prox = novo; // coloca ela nas descartadas caso ela não seja a primeira a ser descartada
            }
            
            qntdesc++; // pilha de descartadas aumenta
            qntlst--; // pillha da lista original diminui
            
            if(qntlst > 1) { // se houver +1 carta na lista original, a do topo vira a última
            
                novo = lst; // faz isso deixando a carta do topo completamente sozinha
                lst = lst->prox;
                novo->prox = NULL;
            
                aux = lst;
                while(aux->prox != NULL) {
                    aux = aux->prox;
                }
                aux->prox = novo; // e depois colocando-a no final da lista
            }
        }
        
        
        if(descartes == NULL) {
            printf("Discarded cards:"); // se a lista inicial tivesse apenas 1 carta, não haveria descarte
        }
        else {
            aux = descartes;
            printf("Discarded cards: %d", aux->num);
            while(aux->prox != NULL) {
                aux = aux->prox;
                printf(", %d", aux->num);
            }
        }
        
        printf("\nRemaining card: %d\n", lst->num);
        
        
        free(lst);
        while(descartes != NULL) {
            aux = descartes->prox; //usa dois ponteiros para liberar a memória
            free(descartes);
            descartes = aux;
        }
        
        
        scanf("%d", &n);
        
    }
    
    return 0;
}