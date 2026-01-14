#include "ordenacao.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {

	// inicialziando a semente aleatoria
	srand(time(NULL));
	
	clock_t start, end;  // variáveis do tipo clock_t
	double total;
	
	
	char nome[MAX_CHAR];
	long int numComp;
	size_t tamVetor = 1000000;
	int max = 1000; 
	int* vetor = (int*)malloc(tamVetor * sizeof(int));
    	if (vetor == NULL) {
        	printf("Falha fatal. Impossível alocar memoria.");
        return 1;
	}

	
	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());
	
	//MergeSort:
	preencherAleatorio(vetor, 0, tamVetor, max);
	printf("\nMergeSort:\n");
	start = clock();  // start recebe o "ciclo" corrente
	
	numComp = mergeSort(vetor, tamVetor);
	
	end = clock();  // end recebe o "ciclo" corrente
	// o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start) / CLOCKS_PER_SEC;

	printf("O número de comparacoes foi: %ld\n", numComp);
	printf("Tempo total: %f segundos\n", total);	
	
	//QuickSort:
	preencherAleatorio(vetor, 0, tamVetor, max);
	printf("\nQuickSort:\n");
	start = clock();  // start recebe o "ciclo" corrente
	
	numComp = quickSort(vetor, tamVetor);
	
	end = clock();  // end recebe o "ciclo" corrente
	// o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start) / CLOCKS_PER_SEC;

	printf("O número de comparacoes foi: %ld\n", numComp);
	printf("Tempo total: %f segundos\n", total);	
	
	//HeapSort:
	preencherAleatorio(vetor, 0, tamVetor, max);
	printf("\nHeapSort:\n");
	start = clock();  // start recebe o "ciclo" corrente
	
	numComp = heapSort(vetor, tamVetor);
	
	end = clock();  // end recebe o "ciclo" corrente
	// o tempo total é a diferença dividia pelos ciclos por segundo
	total = ((double)end - start) / CLOCKS_PER_SEC;

	printf("O número de comparacoes foi: %ld\n", numComp);
	printf("Tempo total: %f segundos\n", total);	

	free(vetor);

	return 0;
}
