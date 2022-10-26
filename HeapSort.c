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

void maxheapify(int *A, int m, int i){
	int maior, aux;
	int e = 2 * i + 1;
	int d = 2 * i + 2;
	if((e < m) && (A[e] > A[i])){
		maior = e;
	}else{
		maior = i;
	}
	if((d < m) && (A[d] > A[maior])){
		maior = d;
	}
	if(maior != i){
		aux = A[i];
		A[i] = A[maior];
		A[maior] = aux;
		maxheapify(A, m, maior);
	}
}

void buildmaxheap(int *A, int n){
	int i;
	for(i = n/2; i >= 0; i--){
		maxheapify(A, n, i);
	}
}

void heapsort2(int *A, int n){
	int i, aux;
	buildmaxheap(A, n);
	for(i = n - 1; i >= 1; i--){
		aux = A[0];
		A[0] = A[i];
		A[i] = aux;
		maxheapify(A, i, 0);
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
   n = 100000;// n = atoi(argv[1]);

 // srand((int) time(&x));
 rand();

  A = geraVetorAleatorio(n);
  printf("ANTES: ");
  imprimeVetor(A, n);

  start = clock();
  heapsort2(A, n);
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
