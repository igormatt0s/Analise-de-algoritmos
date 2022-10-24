#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void insercao(int *A, int n) {
  int chave, i, j;
  for( j = 1; j < n; j++){
    chave = A[j];
    i = j - 1;
    while(i >= 0 && A[i] >= chave) {
      A[i + 1] = A[i];
      i = i - 1;
    }
    A[i + 1] = chave;
  }
}
/*
int *geraVetorAleatorio(int n) {
  int i;
  int *A;
  A = malloc(sizeof(int)*n);
  for (i = 0; i < n; i++) {
    A[i] = randInt(n*2);
  }
  return A;
}*/

int *geraVetorCrescente(int n) {
  int i;
  int *A;
  A = malloc(sizeof(int)*n);
  for (i = 0; i < n; i++) {
    A[i] = i;
  }
  return A;
}

int *geraVetorDecrescente(int n) {
  int i;
  int *A;
  A = malloc(sizeof(int)*n);
  for (i = 0; i < n; i++) {
    A[i] = n-i;
  }
  return A;
}

void imprimeVetor(int *A, int n) {
  int i;
  for(i = 0; i < n; i++)
    printf ("%d ", A[i]);
  printf("\n");
}

int main (int argc, char ** argv) {
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

  A = geraVetorDecrescente(n);
  //printf("ANTES: ");
  //imprimeVetor(A, n);

  start = clock();
  //selecaoR(A,0,n-1);
  insercao(A, n);
//qsort(A, n, sizeof(int), comparaInteiros); 
  //quicksort2(A, 0, n-1);
  end = clock();

  sorted = 1;
  for(i = 0; i < n-1; i++ )
    if(A[i] > A[i+1]) {
      sorted = 0;
      break;
    }
  if(sorted) {
    printf("OK\n");
  }

 //printf("DEPOIS: ");
 //imprimeVetor(A, n);

  //printf ("k=%d\n", q);
  printf ("time: %lf\n", (double)(end - start)/(double)CLOCKS_PER_SEC);

  free(A);

  return 0;
}
