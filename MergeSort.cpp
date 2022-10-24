#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>

int *geraVetorDecrescente(int n);
int *geraVetorCrescente(int n); //Interface da função

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

void intercala(int *A, int p, int q, int r){
  int n1 = q - p + 1;
  int n2 = r - q;
  
  int L[n1+1], R[n2+1];
  int i, j, k;
  
  for(i = 1; i <= n1; i++){
    	L[i] = A[p+i-1];
	}
	
	for(j = 1; j <= n2; j++){
		R[j] = A[q+j];
	}
	
	L[n1+1] = R[n2+1] = INT_MAX;
	i = j = 1;
	
	for(k = p; k <= r; k++){
		if(L[i] <= R[j]){
			A[k] = L[i];
			i = i + 1;
		}else{
			A[k] = R[j];
			j = j + 1;
		}
	}
}

void mergesort(int *A, int p, int r){
	if(p < r){
		int q = (p + r) / 2;
		mergesort(A, p, q);
		mergesort(A, q+1, r);
		intercala(A, p, q, r);
	}
}

void imprimeVetor(int *A, int n) {
  int i;
  for(i = 0; i < n; i++)
    printf ("%d ", A[i]);
  printf("\n");
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
   n = 400000;// n = atoi(argv[1]);

 // srand((int) time(&x));
 rand();

  A = geraVetorDecrescente(n);
  //printf("ANTES: ");
  //imprimeVetor(A, n);

  start = clock();
  //selecaoR(A,0,n-1);
  mergesort(A, 0, n);
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

 //printf("DEPOIS: ");
 //imprimeVetor(A, n);

  //printf ("k=%d\n", q);
  printf ("time: %lf\n", (double)(end - start)/(double)CLOCKS_PER_SEC);

  free(A);

	return 0;
}
