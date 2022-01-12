#include <stdlib.h>
#include <stdio.h>
#include "ordenacao.h"

int partition(int c, int f, int v[]) {
     /* c - indice do comeco do (sub)arranjo no arranjo v.
        f - indice do fim do (sub)arranjo no arranjo v.
        v - arranjo de entrada desordenado entre os indices c e f.  */
    int pivot,Pindex,i;
    pivot=v[f];
    Pindex=c;
    for(i=c; i<f; i++){
        if(v[i]<=pivot){
            Swap(&v[i],&v[Pindex]);
            Pindex++;
        }
    }
    Swap(&v[f],&v[Pindex]);
    return(Pindex);
}

void quickSort(int c, int f, int v[]) {
     /* c - indice do comeco do (sub)arranjo no arranjo v.
        f - indice do fim do (sub)arranjo no arranjo v.
        v - arranjo que se deseja ordenar.  */
    int Pindex;
    if(c<f){
        Pindex= partition(c,f,v);
        quickSort(c, Pindex-1, v);
        quickSort(Pindex+1, f, v);
    }
}

void bubbleSort( int n, int*v){
    /*  n - tamanho do arranjo v.
        v - arranjo de entrada desordenado. */
    int i, j,troca;
    for(i=0; i<(n-1); i++){
        troca=0;
        for(j=0;j<((n-1)-i);j++){
            if(v[j]>v[j+1]){
                Swap(&v[j], &v[j+1]);   //Realiza a troca entre os elementos.
                troca=1;
            }
        }
        if (troca==0){
            break;
        }
    }
}

void selectionSort(int n, int v[]){
    /* n - tamanho do arranjo v.
       v - arranjo de entrada desordenado. */
    int i, j, min;
    for (i=0; i<(n-1); i++){
        min=i;
		for (j=(i+1); j<n; j++)
		{
            if(v[j]<v[min])
				min = j;
		}
		if (i!=min)
			Swap(&v[i], &v[min]); //Realiza a troca entre os elementos, de maneira a deixar v[min] ordenado.
    }
}

void merge(int c, int m, int f, int v[]){
    /*  c - indice do comeco do (sub)arranjo no arranjo v.
        f - indice do fim do (sub)arranjo no arranjo v.
        v - arranjo de entrada desordenado entre os indices c e f.  */

	int i,j,n;  //variaveis auxiliares/contadores
	int* TemporaryVec; //Vetor temporário que auxilia a ordenação
    i = c;
	j = m+1;
	n = 0;
	TemporaryVec = (int *)malloc((f-c+1)*sizeof(int));
	while(i<=m || j<=f)
	{
		if (i == m+1) {
            /*Como i passou do final da primeira metade dos elementos entao pega-se v[j]*/
			TemporaryVec[n] = v[j];
			j++;
			n++;
		}
		else{
			if (j == f+1){
			 /*Como j passou do final da segunda metade dos elementos entao pega-se v[i]*/
				TemporaryVec[n] = v[i];
				i++;
				n++;
			}
			else{
                if (v[i] < v[j]){
                    TemporaryVec[n] = v[i];
                    i++;
                    n++;
                }
                else{
                    TemporaryVec[n] = v[j];
                    j++;
                    n++;
                }
            }
        }
    }
    // copia o vetor ordenado para o vetor original
    for(i = c; i <= f; i++){
        v[i] = TemporaryVec[i-c];
    }
    free(TemporaryVec); //Libera a memória alocada dinamicamente
}


void mergeSort(int c, int f, int v[]){
	/*	c - indice do comeco do (sub)arranjo no arranjo v.
		f - indice do fim do (sub)arranjo no arranjo v.
		v - arranjo de entrada desordenado entre os indices c e f.	*/
    int middle;
	if (c==f)
        return;
	// ordenacao recursiva de cada uma das metades
	middle = (c+f)/2;
	mergeSort(c, middle, v);
	mergeSort(middle+1, f, v);
	merge(c, middle,f , v);
}


void insertionSort(int n, int v[]){
    /*  n { tamanho do arranjo v.
        v { arranjo de entrada desordenado. */
    int i, i_hole, TBI;
    /*  i_hole - buraco.
        TBI - to be inserted.  */
    for(i=1; i<n; i++)
    {
        TBI = v[i];
        i_hole = i;
        while(i_hole > 0 && v[i_hole-1] > TBI)
        {
			v[i_hole] = v[i_hole-1];
            i_hole--;
        }
        v[i_hole] = TBI;
    }
}

void Swap(int* A, int* B){
    //Realiza a troca de valores de 2 variáveis
    int temporary;
    temporary = *A;
    *A = *B;
    *B = temporary;
}
