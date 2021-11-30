#include <stdio.h>
#include <stdlib.h>

typedef float tip;

// Alociranje dinamicke matrice n*n
tip** allocate(int n) {
	tip** mat;
	mat = (tip**)malloc(n * sizeof(tip*));
	for (int i = 0; i < n; i++) {
		mat[i] = (tip*)malloc(n * sizeof(tip));
	}
	return mat;
}

// Dealociranje dinamicke matrice n*n

void deallocate(tip** m, int n) {
	for (int i = 0; i < n; i++) {
		free(m[i]);
	}
	free(m);
}

void ispisiMatricu(tip** m, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("lf ", m[i][j]);
		}
		printf("\n");
	}
}

// Prenos po referenci zato se stavlja trece zvezdica jer menjam matricu.

void unesiMatricu(tip*** m, int n) {
	*m = allocate(n); // Prvo moram da alociram n*n mem prostor.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%lf", &((*m)[i][j]));
		}
	}
}

tip determinanta(tip** matrica, int n) {
	tip** podmatrica;
	tip det = 0;
	if (n == 1) {
		return matrica[0][0];
	}
	podmatrica = allocate(n - 1);
	int znak = 1;
	for (int i = 0; i < n; i++) {
		
		for (int kolona = 0; kolona < i; kolona++) {
			for (int vrsta = 1; vrsta < n; vrsta++) {
				podmatrica[vrsta - 1][kolona] = matrica[vrsta][kolona];
			}
		}
		for (int kolona = i + 1; kolona < n; kolona++) {
			for (int vrsta = 1; vrsta < n; vrsta++) {
				podmatrica[vrsta - 1][kolona - 1] = matrica[vrsta][kolona];
			}
		}
		det += znak * matrica[0][i] * determinanta(podmatrica, n - 1);
		znak *= -1;
	}
	deallocate(podmatrica, n - 1);
	return det;
}

int main() {
	tip** matrica;
	int n;
	scanf("%i", &n);
	unesiMatricu(matrica, n);
	printf("Determinanta je : %f\n", determinanta(matrica, n));

	return 0;
}