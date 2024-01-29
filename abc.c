#include<stdio.h>
#include <stdlib.h>
#include "wavfile.h"
#include "trabalho2.h"





void mudaGanho (double* dados, int n_amostras, double ganho){
    for (int i = 0; i < n_amostras; i++) {
       dados[i] *= ganho;
   }
}


int contaSaturacoes (double* dados, int n_amostras){
    int cont = 0;

    for (int i = 0; i < n_amostras; i++) {
        if (dados[i] > 1.0 || dados[i] < -1.0) {
            cont++;
        }
    }

    return cont;
}


int hardClipping (double* dados, int n_amostras, double limite){
    int cont = 0;

    for (int i = 0; i < n_amostras; i++) {
        if (dados[i] > limite || dados[i] < -limite) {
            cont++;
            if (dados[i] > 0) {
                dados[i] = limite;
            } else {
                dados[i] = -limite;
            }
        }
    }
    return cont;
}


void limitaSinal (double* dados, int n_amostras, int n_passos){
    int i, j;
    double ganho;
    double min = -1.0, max = 1.0;


    for(i = 0; i < n_amostras; i++){
        if (dados[i]> max)  // Verifica se o vetor na posi��o i � maior do que o maximo;
            {
            dados[i] = max;   // caso seja maior que o maximo, � redefinido para max;

            ganho = max/dados[i]; // ganho � definido pela divis�o do max / vetor na posi��o i

            for(j = 0;j <= n_passos; j++) // Um loop para ir da posi��o inicial at� n_passsos � esquerda e � direita;
            {
                if(i + j < n_amostras) // verifica se n�o ir� estourar o vetor;
                {
                    dados[i + j] *= ganho;   //  multiplica o vetor na posi��o i (posi��o que passou do limite) pela posi��o j(posi��o contando at� n_passsos);

                    ganho += 0.1; // aumenta o ganho de 0.1 em 0.1, de acordo com o especificado;
                }
                if(j - i >= 0){
                    dados[i - j] *= ganho;  //  multiplica o vetor na posi��o i (posi��o que passou do limite) pela posi��o j(posi��o contando at� n_passsos);

                    ganho += 0.1;
                }

            }

        }
         else if(dados[i]<min) // Verifica se o vetor na posi��o i � menor do que o minimo;
            {
            dados[i] = min;  // caso seja menor que o minimo, � redefinido para min;

            ganho = min/dados[i]; // ganho � definido pela divis�o do min / vetor na posi��o i
            for(j = 1;j <= n_passos; j++){

                if(i + j < n_amostras) // verifica se n�o ir� estourar o vetor;
                {
                {
                    dados[i + j] *= ganho;

                    ganho += 0.1;
                }
                if(j - i >= 0){
                    dados[i - j] *= ganho;

                    ganho += 0.1;
                    }

                }
            }
        }
    }

