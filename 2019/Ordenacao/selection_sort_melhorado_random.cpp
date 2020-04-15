#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10  //tamanho maximo do vetor
void selection_sort(int tamanho, int *);
void exibeVetor(int tamanho, int *);
void preencheVetorRandom_int(int tamanho, int maior, int vet[]);
int aleatorio(int);
/*
** A funcao selection_sort rearranja o vetor v[0..n-1]
** em ordem crescente
** Autor: Ed em 10/04/2013
*/
void selection_sort(int tamanho, int vetor[]){
    int i, j, pos_menor, troca;
    for(i=0;i<tamanho-1;i++){
        pos_menor = i;
        for(j=i+1;j<tamanho;j++){
            if(vetor[j]<vetor[pos_menor])
                pos_menor = j;
        }
        if(i!= pos_menor){
            troca = vetor[i];
            vetor[i] = vetor[pos_menor];
            vetor[pos_menor] = troca;
        } //exibicao aqui
    }
    //exibeVetor(tamanho, vetor); printf("\n"); getchar();
}

int main(){
    srand(time(NULL));
    int vetor[TAM]; //declara o vetor
    preencheVetorRandom_int(TAM, 200, vetor);
    printf("\nO vetor digitado eh\n");
    exibeVetor(TAM, vetor);
    getchar();
    selection_sort(TAM, vetor);
    printf("\n\nO vetor ordenado em ordem crescente eh\n");
    exibeVetor(TAM, vetor); getchar();
    /*ordena_bolha_desc_int(TAM, vetor);
    printf("\n\nO vetor ordenado em ordem decrescente eh\n");
    exibe_vetor(TAM, vetor);getchar();*/
    printf("\n\n");
    getchar();
    return 0;
}
void preencheVetor(int tamanho, int vet[]){  // Preenche o vetor
    int i;
    for (i=0;i<tamanho;++i){
        printf("\nDigite o elemento %d do vetor: ", i);
        scanf("%d", &vet[i]);
    }
}
void exibeVetor(int tamanho, int v[]){     //Exibe
    int t;
    for (t=0;t<tamanho;t++)
        printf("%-4d ", v[t]);
}
void preencheVetorRandom_int(int tamanho, int maior, int vet[]){
    int i, valor; // Preenche com valores randomicos melhor
    for (i=0;i<tamanho;++i){
        valor = (1 + aleatorio(maior-1)); 	//gera ate maior
        vet[i]=valor;
    }
}
int aleatorio(int n){      //funcao para gerar aleatorios
    return rand() % n;
}
