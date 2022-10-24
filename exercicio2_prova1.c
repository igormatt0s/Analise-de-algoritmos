#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void ordena(int *A, int n) {
  int m, i, k, j;
  k = 0;
  m = 0;
  j = 0;
  int h = 0;
  int w = 0;
  
  int P[n], I[n];
  
  for(i = 0; i < n; i++){
    	if((A[i]%2) == 0){
    		P[k] = A[i];
    		k = k + 1;
		}else{
			I[m] = A[i];
			m = m + 1;
		}
	}
	printf("\npar %d", k);
	printf("\nimpar %d\n", m);
	imprimeVetor(P, k);
	imprimeVetor(I, m);
	while(h < k && w < m){
      	if(P[h] < I[w]){
      		A[j] = P[h];
      		h++;
		}else{
			A[j] = I[w];
			w++;
		}
		j++;
    }
    while(h < k){
    	A[j] = P[h];
    	h++;
    	j++;
	}
	while(w < m){
		A[j] = I[w];
    	w++;
    	j++;
	}
}

void imprimeVetor(int *A, int n) {
  int i;
  for(i = 0; i < n; i++)
    printf ("%d ", A[i]);
  printf("\n");
}

int main(int argc, char ** argv){
	int A[] = {2, 1, 4, 6, 3, 8, 10, 5, 12, 14, 7};
  int n;
  
  n = sizeof(A)/sizeof(int);
  printf("%d", n);
  
  printf("\n Antes\n");
  imprimeVetor(A, n);

  ordena(A, n);
  
  printf("\n Depois\n");
 imprimeVetor(A, n);

  free(A);

	return 0;
}
