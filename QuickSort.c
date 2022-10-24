#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>

int *geraVetorDecrescente(int n);
int *geraVetorAleatorio(int n);
int *geraVetorCrescente(int n); //Interface da função

int randInt(int n){
	return (int) ((double) n * (double) (rand() / ((double)RAND_MAX + 1)));
}

int *geraVetorAleatorio(int n){
  int i;
  int *A;
  A = malloc(sizeof(int)*n);
  for (i = 0; i < n; i++){
    A[i] = randInt(n*2);
  }
  return A;
}

void imprimeVetor(int *A, int n) {
  int i;
  for(i = 0; i < n; i++)
    printf ("%d ", A[i]);
  printf("\n");
}

int *geraVetorCrescente(int n){
  int i;
  int *A;
  A = malloc(sizeof(int)*n);
  for (i = 0; i < n; i++) {
    A[i] = i;
  }
  return A;
}

int *geraVetorDecrescente(int n){
  int i;
  int *A;
  A = malloc(sizeof(int)*n);
  for (i = 0; i < n; i++) {
    A[i] = n-i;
  }
  return A;
}

int partition(int *A, int p, int r){
  int x = A[r];
  int i = p - 1;
  int aux;
  int j;
  
  for(j = p; j <= r - 1; j++){
    	if(A[j] <= x){
    		i = i + 1;
    		aux = A[i];
    		A[i] = A[j];
    		A[j] = aux;
		}
	}

	aux = A[i + 1];
	A[i + 1] = A[r];
	A[r] = aux;
	
	return i + 1;
}

void quicksort(int *A, int p, int r){
	if(p < r){
		int q = partition(A, p, r);
		quicksort(A, p, q-1);
		quicksort(A, q+1, r);
	}
}

int main(int argc, char ** argv){
	int *A;
  time_t x;
  int n, i;
  int sorted;
  clock_t start; 
  clock_t end; 
  int q;

  //if(argc > 1) 
   n = 10;// n = atoi(argv[1]);

 // srand((int) time(&x));
 rand();

  A = geraVetorAleatorio(n);
  printf("ANTES: ");
  imprimeVetor(A, n);

  start = clock();
  //selecaoR(A,0,n-1);
  quicksort(A, 0, n-1);
//qsort(A, n, sizeof(int), comparaInteiros); 
  //quicksort2(A, 0, n-1);
  end = clock();

  sorted = 1;
  for(i = 0; i < n-1; i++ )
    if(A[i] > A[i+1]){
      sorted = 0;
      break;
    }
  if(sorted){
    printf("OK\n");
  }

 printf("DEPOIS: ");
 imprimeVetor(A, n);

  //printf ("k=%d\n", q);
  printf ("time: %lf\n", (double)(end - start)/(double)CLOCKS_PER_SEC);

  free(A);

	return 0;
}
