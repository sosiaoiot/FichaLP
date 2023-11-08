/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cFiles/main.c to edit this template
 */

/* 
 * File:   main.c
 * Author: jmtg2
 *
 * Created on 27 de outubro de 2023, 13:17
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 
 */
int main() {
    int n_botas = 0, n_sandalias = 0, n_outro = 0, calcado, n_botas_temp, n_sandalias_temp, n_outro_temp;
    long int nif;
    float mao_obra, rest_custos, custo_total, margem, desc_total, valor_total, total_s_desconto;
    char perfis[50], codigo_desconto[] = "vski", codigo[50];
    
    printf("Introduza o seu perfil: \n");
    scanf("%s", perfis);
    
    printf("Introduza o seu nif: \n");
    scanf("%ld", &nif);
    
    do{
        printf("///////////////Menu///////////////\n");
        printf("Qual calcado pretende comprar: \n");
        printf("1 - Botas\n2 - Sandalias\n3 - Outro\n4 - Terminado\n");
        scanf("%d", &calcado);
        switch(calcado){
            case 1:
                do{
                    printf("Introduza o numero de pares de Botas: \n");
                    scanf("%d", &n_botas_temp);
                    if(n_botas_temp <= 0){
                        printf("Numero de pares de Botas invalidos!!!\n");
                    }
                }while(n_botas_temp<=0);
                if(n_botas == 0){
                    n_botas = n_botas_temp;
                } else{
                    n_botas = n_botas + n_botas_temp;
                }
                break;
            case 2:
                do{
                    printf("Introduza o numero de pares de Sandalias: \n");
                    scanf("%d", &n_sandalias_temp);
                    if(n_sandalias_temp <= 0){
                        printf("Numero de pares de Sandalias invalidos!!!\n");
                    }
                }while(n_sandalias_temp<=0);
                if(n_sandalias == 0){
                    n_sandalias = n_sandalias_temp;
                } else{
                    n_sandalias = n_sandalias + n_sandalias_temp;
                }
                break;
            case 3:
                do{
                    printf("Introduza o numero de Outros: \n");
                    scanf("%d", &n_outro_temp);
                    if(n_outro_temp <= 0){
                        printf("Numero de Outros pares invalidos!!!\n");
                    }
                }while(n_outro_temp<=0);
                if(n_outro == 0){
                    n_outro = n_outro_temp;
                } else{
                    n_outro = n_outro + n_outro_temp;
                }
                break;
            case 4:
                printf("Terminado!\n");
                break;
            default:
                printf("Nao existe!!\n");
                break;
        }
    }while(calcado!=4);
      
    mao_obra = ((n_botas * 2) * 7) + ((n_sandalias * 2) * 4) + ((n_outro * 2) * 5);
    rest_custos = (n_botas * 3.5) + (n_sandalias * 3) + (n_outro * 3);
    custo_total = mao_obra + rest_custos;
    margem = (((n_botas * 2) * 7) + (n_botas * 3.5)) * 0.4 + (((n_sandalias * 2) * 7) + (n_sandalias * 3.5)) * 0.25 + (((n_outro * 2) * 7) + (n_outro * 3.5)) * 0.3;
    total_s_desconto = custo_total + margem;
    desc_total = total_s_desconto * 0.10;
    valor_total = total_s_desconto - desc_total;
    
    if (strcmp(perfis, "revendedor") == 0) {
        valor_total = valor_total * 0.90;
    } else if (strcmp(perfis, "cliente") == 0) {
        printf("Introduza o codigo de desconto: \n");
        scanf("%s", codigo);
        if (strcmp(codigo, codigo_desconto) == 0) {
            printf("Codigo valido!!\n");
            valor_total = valor_total * 0.95;
        } else{
            printf("Codigo Invalido!!\n");
        }
    } else {
        printf("Perfil nao identificado!!!");
        return 1; // Retorna um código de erro
    }
    
    printf("///////////////////////////////////////////////////\n");
    printf("NIF: %ld\n", nif);
    printf("///////////////////////////////////////////////////\n");
    printf("Detalhes da compra: \n");
    printf("Numero total de pares de Botas: %d\n", n_botas);
    printf("Numero total de pares de Sandalias: %d\n", n_sandalias);
    printf("Numero total de pares de Outro: %d\n", n_outro);
    printf("///////////////////////////////////////////////////\n");
    printf("Custos:\n");
    printf("Custo da mao de obra: %.2f\n", mao_obra);
    printf("Custo adicional da concecao: %.2f\n", rest_custos);
    printf("Custo Total: %.2f\n", custo_total);
    printf("Lucro: %.2f\n", margem);
    printf("Total sem desconto: %.2f\n", total_s_desconto);
    printf("Desconto obtido pelo cliente: %.2f\n", desc_total);
    printf("Valor a pagar pelo cliente: %.2f\n", valor_total);
    printf("///////////////////////////////////////////////////\n");
    
    return 0;
}

