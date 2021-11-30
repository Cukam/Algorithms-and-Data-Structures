
#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




void ucitajMatricu(int mat[8][8]) {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%i", &mat[i][j]);
		}
	}
}

bool ispitatiValidnostMatrice(int mat[8][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (!(mat[i][j] == 0 || mat[i][j] == 1)) {
				return false;
			}
		}
	}
	return true;
}

bool daLiIma8Topova(int mat[8][8]) {
	int suma = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (mat[i][j] == 1) {
				suma++;
			}
		}
	}

	return suma == 8;
}


bool ispitatiDaLiSeDvaTopaNeTuku(int mat[8][8]) {
	
	for (int i = 0; i < 8; i++) {
		int suma = 0;
		for (int j = 0; j < 8; j++) {
			suma += mat[i][j];
		}
		if (suma > 2) {
			return false;
		}
	}
	for (int i = 0; i < 8; i++) {
		int suma = 0;
		for (int j = 0; j < 8; j++) {
			suma += mat[j][i];
		}
		if (suma > 2) {
			return false;
		}
	}
	return true;
}


void umetniUNiz(int array[], int n,int value) {
	for (int i = n-1; i >= 0; i--) {
		if (value < array[i]) {
			array[i+1] = array[i];
			array[i] = value;
		}
	}
}

double prosekParnih(int array[], int n) {
	double suma = 0.0;
	int brojParnih = 0;
	for (int i = 0; i < n; i++) {
		if (array[i] % 2 == 0) {
			suma += array[i];
			brojParnih++;
		}
	}
	if (brojParnih == 0) {
		return suma;
	}
	else {
		return (double)suma / brojParnih;
	}
}


void napraviTreciNiz(int a[], int b[], int c[], int n, int m) {
	
	for (int i = 0; i < n; i++) {
		umetniUNiz(c, n + m, a[i]);
		
	}

	for (int i = 0; i < m; i++) {
		umetniUNiz(c, n + m, b[i]);

	}
}

int main() {

	/* Zadatak za  Topove */ 
	/*
	
	int mat[8][8];

	ucitajMatricu(mat);
	ispitatiValidnostMatrice(mat);
	daLiIma8Topova(mat);
	ispitatiDaLiSeDvaTopaNeTuku(mat);
	
	*/
	/* Zadatak za swapovanje */
	/*
	FILE* f = fopen("zadatak.txt", "r");
	int n;
	int trenutnaDuzina = 0;
	int array[100];

	fscanf(f, "%i", &n);

	for (int i = 0; i < n; i++) {
		fscanf(f, "%i", &array[i]);
		umetniUNiz(array, trenutnaDuzina,array[i]);
		trenutnaDuzina++;
	}

	for (int i = 0; i < n; i++) {
		printf("%i ", array[i]);
	}
	
	FILE* f2 = fopen("zadatak2.txt", "r");
	int brojElemenata;
	fscanf(f2, "%i", &brojElemenata);
	int array2[100];

	for (int i = 0; i < brojElemenata; i++) {
		fscanf(f2, "%i", &array[i]);
	}

	printf("%lf", prosekParnih(array2, brojElemenata));

	*/


	FILE* f3 = fopen("zadatak3.txt", "r");
	int array3[100];
	int array4[100];
	int array5[100];
	
	int brojElemenataArraya3;
	int brojElemenataArraya4;
	fscanf(f3, "%i %i", &brojElemenataArraya3, &brojElemenataArraya4);

	napraviTreciNiz(array3, array4, array5, brojElemenataArraya3, brojElemenataArraya4);

	for (int i = 0; i < brojElemenataArraya3 + brojElemenataArraya4; i++) {
		printf("%i ", array5[i]);
	}
	



	return 0;
}