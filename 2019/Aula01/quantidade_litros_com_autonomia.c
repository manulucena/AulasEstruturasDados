#include<stdio.h>
#include<stdlib.h>

int main(){
    //declarar as variaveis
    float distancia, tempo, velocidade_media, litros_usados, autonomia, preco_combustivel;
    //ENTRADA
   printf("Qual a velocidade média do percurso? ");  scanf(" %f", &velocidade_media);
   printf("Qual o tempo gasto na viagem? "); scanf(" %f", &tempo);
   printf("Qual a autonomia do automóvel? "); scanf(" %f", &autonomia);
   printf("Qual o preço desse combustível? "); scanf(" %f", &preco_combustivel);
    //PROCESSAMENTO
   distancia = tempo * velocidade_media;
   litros_usados = distancia / autonomia;
    //SAIDA
    printf("O automovel que faz %.2f km/l percorre uma distancia de: %.3f quilômetros\n", autonomia, distancia);
    printf("Em %.2f horas gastando aproximadamente %.3f litros de combustível\n", tempo, litros_usados);
    printf("Em uma velocidade média de %.2f km/h\n", velocidade_media);  
    printf("E o motorista gastou R$ %-10.2f\n\n", litros_usados * preco_combustivel);
    system("pause");
}
