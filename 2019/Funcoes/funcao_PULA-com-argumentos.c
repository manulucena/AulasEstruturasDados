#include <stdio.h>
#include <stdlib.h>
/*  Funçăo : Pula quantidade x de linhas
    Autor : Edkallenn  -  Data : 03/10/2013
    Observaçőes:
*/

void pula(int); //pula n linhas

int main(){

    printf("Teste da funcao");
    pula(10);
    printf("Deve pular uma linha");
    pula(15);
    getchar();
}
void pula(int x){
    int i;
    for(i=1;i<=x;i++)
        printf("\n");
}
