#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#include <stdint.h>
#include <sys/types.h>
#include <stdio.h>

#define MAX_CHAR 50

// a função getNome deve colocar o seu nome no vetor
// seu nome pode ter no máximo MAX_CHAR_NOME - 1 caracteres
void getNome(char nome[]);

// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR();

void preencherAleatorio(int vetor[], int inicio, int fim, int maxVal);

void escreveVetor(int vetor[], int inicio, int fim);

// Cada uma das funções deve ordenar o vetor passado como parâmetro

// O retorno das funções de ordenação é o número de comparações
// entre elementos do vetor

uint64_t mergeSort(int vetor[], size_t tam);

uint64_t quickSort(int vetor[], size_t tam);

uint64_t heapSort(int vetor[], size_t tam);

#endif  // ORDENACAO_H_
