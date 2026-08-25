/*Maria Thereza Jardim
Este exercício lê 100 números, apresenta o maior número e a posição dele */

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