#include <stdio.h>



void swap(int* a, int* b) {
	int c = *a;
	*a = *b;
	*b = c;
}

void printTheArray(int array[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%i, ", array[i]);
	}
}



int main() {
	/* UVOD U POINTERE */
	int x = 3;

	int* px;

	printf("Adresa promenljive x je :%p \n", &x);
	printf("Vrednost promenljive x je :%i\n", x);

	px = &x;

	printf("Vrednost promenljive px je : %p\n", px);
	printf("Adresa samog pointera px je : %p\n", &px);
	printf("Vrednost promenljive na kou ukazuje px je :%i\n", *px);


	*px = 6;
	printf("Vrednost promenljive na koju ukazuje px je :%i \n", *px);
	printf("Vrednost promenljive x je :%i\n", x);


	/* PRENOS PO REFERENCI */
	int a = 3;
	int b = 2;

	printf("A je : %i, dok je B : %i", a, b);

	swap(&a, &b);

	printf("A je : %i, dok je B : %i", a, b);

	

	/* VEZA IZMEDJU POINTERA I NIZOVA*/

	char s[] = "abcde";
	int t[] = { 1,2,3,4,5 };

	char* ps = &s[0];
	int* pt = &t[0];

	/* Razlika izmedju ps i pt je to sto char zauzima tacno 1 bajt dok klasican int zauzima
		tacno 4 bajta i bas zbog toga se memorijske lokacije razlikuju za 1 ili za 4
	*/

	printf("ps = %p\n", ps);
	printf("ps+1= %p\n", ps + 1);
	printf("ps+2=%p\n", ps + 2);
	printf("ps-1=%p\n", ps - 1);
	printf("ps-2=%p\n", ps - 2);

	for (ps = s; *ps; ps++) {
		putchar(*ps);
	}
	// sve dok *ps nije NULL posto string u C se zavrsava sa \0 karakterom 
	putchar('\n');


	printf("pt = %p\n", pt);
	printf("pt+1 = %p\n", pt + 1);
	printf("pt+2 = %p\n", pt + 2);
	printf("pt-1 = %p\n", pt - 1);
	printf("pt-2 = %p\n", pt - 2);

	ps = &s[3];
	printf("s = %p\n", s);
	printf("ps = %p\n", ps);
	printf("ps - s = %i\n", ps - s);
	pt = &t[3];
	printf("t = %p\n", t);
	printf("pt = %p\n", pt);
	printf("pt - t = %i\n", pt - t);


	/* VEZA IZMEDJU POINTERA I ARRAYA */

	int array[] = { 1,2,3,4,5,6,7,8,9,10 };
	int numberOfElements = sizeof(array) / sizeof(int);

	printf("Niz a : %p \n", array);
	printf("Adresa prvog elementa u nizu je : %p \n", &array[0]);

	int* pa = a;

	printf("Pokazivac pa ukazuje na adresu : %p\n", pa);

	printf("array + 3 = %p\n", array + 3);

	printf("&array[3] = %p \n", &array[3]);

	printTheArray(array, numberOfElements);

	



	return 0;




}