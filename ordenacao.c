#include "ordenacao.h"

#include <stdint.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void getNome(char nome[]) {
    // substitua por seu nome
    strncpy(nome, "Gabriel Bardini Bessa", MAX_CHAR);
    // adicionada terminação manual para caso de overflow
    nome[MAX_CHAR - 1] = '\0';
}

// a função a seguir deve retornar o seu número de GRR
uint32_t getGRR() { return 20232383; }

// Preenche o vetor com valores aleatórios
void preencherAleatorio(int vetor[], int inicio, int fim, int maxVal) {
	for(int i = inicio; i < fim; i++)
		vetor[i] = rand() % maxVal;
}

// Funções relacionadas ao Merge Sort:

// Copia todos os elementos de um vetor para outro
void copiar(int vet[], int aux[], ssize_t a, ssize_t b){
	int i = 0;
	while (i <= b-a){
		vet[a+i] = aux[i];
		i++;
	}   
	
	free(aux);
	return;
}

// Junta dois vetores ordenados em um único vetor ordenado
void merge(int v[], ssize_t a, ssize_t m, ssize_t b, uint64_t* numComp){
	if (a >= b)
		return;

	// Vetor auxiliar para armazenar o resultado 
	int* aux = (int*)malloc((b-a+1) * sizeof(int));
	int i = a; // Indice do primeiro vetor
	int j = m + 1; // Indice do segundo vetor
	int k = 0;	//Indice do vetor auxiliar

	while (k <= b - a) {
		(*numComp)++;
		if (j > b || (i <= m && v[i] <= v[j])) {
			aux[k] = v[i];
			i++;
		} 
		else {
			aux[k] = v[j];
			j++;
		}
		k++;
	}
	
	copiar(v, aux, a, b);
}

// Implementação do Merge Sort
uint64_t mergeSort_impl(int vetor[], ssize_t a, ssize_t b, uint64_t* numComp){
	if (a >= b)
		return *numComp;

	int m = (a + b) / 2;

	mergeSort_impl(vetor, a, m, numComp);

	mergeSort_impl(vetor, m+1, b, numComp);

	merge(vetor, a, m, b, numComp);

	return *numComp;
}

/* Cria a váriavel para o numero de comparações 
e chama a função que faz o MergeSort */
uint64_t mergeSort(int vetor[], size_t tam) {
    	uint64_t numComp = 0;
	return mergeSort_impl(vetor, 0, tam-1, &numComp);
}

// Funções relacionadas ao Quick Sort:

// Troca dois elementos do vetor de posição a partir de seus índices
uint64_t trocar(int vetor[], ssize_t x, ssize_t y){
	ssize_t aux;

	aux = vetor[x];
	vetor[x] = vetor[y];
	vetor[y] = aux;

	return 0;
}

// Garante que o pivô esteja na posição correta
uint64_t particionar(int vetor[], ssize_t a, ssize_t b,uint64_t* numComp){
	ssize_t x = vetor[b]; // Pivô
	ssize_t m = a;	

	for (ssize_t i = a; i <= b - 1; i++){

		(*numComp)++;
		if (vetor[i] <= x){
			trocar(vetor, m, i);
			m++;
		}
	}

	trocar(vetor, m, b);

	return m;
}

// Implementação do Quick Sort
uint64_t quickSort_impl(int vetor[], ssize_t a, ssize_t b,uint64_t* numComp){
	if (a >= b){
		return 0;
	}

	int m = particionar (vetor, a, b, numComp);

	quickSort_impl(vetor, a, m-1,numComp);

	quickSort_impl(vetor, m + 1, b, numComp);

	return *numComp;
}

/* Cria a váriavel para o numero de comparações 
e chama a função que faz o QuickSort */
uint64_t quickSort(int vetor[], size_t tam) {
 	uint64_t numComp = 0;
	return quickSort_impl(vetor, 0, tam-1, &numComp);
}

// Funções relacionadas ao Heap Sort:

/* Acessa o indice do filho que está à direita 
do elemento da heap de posição [i] */
int FilhoDireito(ssize_t i){
	return (i << 1) + 1;
}

/* Acessa o indice do filho que está à esquerda 
do elemento da heap de posição [i] */
int FilhoEsquerdo(ssize_t i){
	return (i << 1);
}

// Faz a função da maxheap de forma iterativa
void maxheap_iterativa(int h[], ssize_t n, ssize_t i, uint64_t* numComp) {
    ssize_t maior = i; 
    ssize_t l, r;
    ssize_t troca = 1; // Variável de controle para saber se houve troca

    while (troca) {
        troca = 0; 
        l = FilhoEsquerdo(i);
        r = FilhoDireito(i);

	
        (*numComp)++;
        
        if (l <= n && h[l] > h[maior])
            maior = l;

        (*numComp)++;
        if (r <= n && h[r] > h[maior])
            maior = r;

	//Se algum dos filhos virou maior troca a raiz com o filho
        if (maior != i) {
            trocar(h , i, maior);
            i = maior; 
            troca = 1; 
        }
    }
}

// Transforma o vetor em uma maxheap
void construir_MH(int h[] , ssize_t n,uint64_t* numComp){

	for (ssize_t i = n/2; i >= 1; i--){
		maxheap_iterativa(h, i, n, numComp);
    }

	return;
}

/* Cria a variavel que controla o número 
de comparações e faz o heapsort */
uint64_t heapSort(int vetor[], size_t tam) {
	uint64_t numComp = 0;

	construir_MH(vetor, tam, &numComp);

	for (int i = tam; i >= 1; i--) {
		trocar(vetor, 1, i);
		maxheap_iterativa(vetor, i - 1, 1, &numComp);
		}

	return numComp;
}
