#include <stdio.h>
#include "ordenacao.h"

void imprime(int n, int v[]) {
	int i;

	for (i=0;i<n;i++)
		printf("%d ", v[i]);
	printf("\n");
}

int main() {
	int vet[MAX];
	int i,n;
	char op;

	scanf ("%c ", &op);

	scanf ("%d", &n);

	for (i=0;i<n;i++)
		scanf ("%d", &(vet[i]));

  imprime(n,vet);

  switch(op) {
	case 'b':
		printf("BUBBLE\n");
		bubbleSort(n,vet);
		break;

	case 'q':
		printf("QUICK\n");
		quickSort(0,n-1,vet);
		break;

	case 's':
		printf("SELECTION\n");
		selectionSort(n,vet);
		break;

	case 'm':
		printf("MERGE\n");
		mergeSort(0,n-1,vet);
		break;

	case 'i':
		printf("INSERTION\n");
		insertionSort(n, vet);
		break;
        default:
		break;
  }

  imprime(n,vet);

  return 0;
}
