#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#include <stdio.h>
#include <stdlib.h>


typedef struct Elem {
	int broj;
	struct Elem* sledeci;
}Elem;


int duzinaListe(Elem* lst) {
	int count = 0;
	while (lst != NULL) {
		lst = lst->sledeci;
		count++;
	}
	return count;
}

void ispisiListu(Elem* lst) {
	while (lst != NULL) {
		printf("%i ->", lst->broj);
		lst = lst -> sledeci;
	}
	printf("\n");
}

Elem* dodajNaPocetku(Elem* lst, int b) {
	Elem* novi = (Elem*)malloc(sizeof(Elem));
	novi->broj = b;
	novi->sledeci = lst;
	return novi;
}

Elem* dodajNaKraju(Elem* lst, int b) {
	Elem* tekuci = lst;
	while (tekuci != NULL) {
		tekuci = tekuci->sledeci;
	}
	Elem* noviElement = (Elem*)malloc(sizeof(Elem));
	noviElement->broj = b;
	noviElement->sledeci = NULL;
	tekuci->sledeci = noviElement;

	return lst;
}

Elem* citaj1(int n) {
	Elem* lst = NULL;
	for (int i = 0; i < n; i++) {
		Elem* novi = (Elem*)malloc(sizeof(Elem));
		scanf("%i", &novi->broj);
		novi->sledeci = lst;
		lst = novi;
	}
	return lst;
}

Elem* citaj2(int n) {
	Elem* lst = NULL;
	Elem* tekuci = lst;
	for (int i = 0; i < n; i++) {
		Elem* novi = (Elem*)malloc(sizeof(Elem));
		scanf("%i", novi->broj);
		novi->sledeci = NULL;
		if (!lst) {
			lst = novi;
		}
		else {
			while (tekuci != NULL) {
				tekuci = tekuci->sledeci;
			}
			tekuci->sledeci = novi;
		}
	}
	return lst;
}

Elem* umetni(Elem* lst, int b) {
	Elem* novi = (Elem*)malloc(sizeof(Elem));
	novi->broj = b;
	novi->sledeci = NULL;
	Elem* tekuci = lst;
	Elem* prethodni = NULL;
	while (b < tekuci->broj) {
		prethodni = tekuci;
		tekuci = tekuci->sledeci;
	}
	prethodni->sledeci = novi;
	novi->sledeci = tekuci;

	return lst;
}

void brisi(Elem* lst) {
	while (lst != NULL) {
		
		Elem* stari = lst;
		lst = lst->sledeci;
		free(stari);
		
	}
}


Elem* izostavi(Elem* lst, int b) {

	Elem* tekuci = lst;
	Elem* prethodni = NULL;
	while (tekuci->broj != b) {
		prethodni = tekuci;
		tekuci = tekuci->sledeci;
	}
	Elem* stari = tekuci;
	tekuci = tekuci->sledeci;
	prethodni->sledeci = tekuci;
	free(stari);

	return lst;
}


int vratiBrojElemenata(Elem* lst, int b) {
	int count = 0;
	while (lst != NULL) {
		if (lst->broj > b) {
			count++;
		}
		lst = lst->sledeci;
	}
	return count;
}

int brojPonavljanjaElementa(Elem* lst, int b) {
	int count = 0;
	while (lst != NULL) {
		if (lst->broj == b) {
			count++;
		}
		lst = lst->sledeci;
	}
	return count;
}

Elem* naciNajmanjiElement(Elem* lst) {
	Elem* najmanji = NULL;
	najmanji->broj = 0;
	Elem* trenutni = lst;
	while (trenutni != NULL) {
		if (najmanji->broj > trenutni->broj) {
			najmanji = trenutni;
		}
		trenutni = trenutni->sledeci;
	}
	return najmanji;
}

void izbaciNakonNajmanjeg(Elem* lst) {
	Elem* trenutni = lst;
	Elem* najmanjiElement = naciNajmanjiElement(lst);
	Elem* elementPosleNajmanjegElementaKojiSeNeIzbacuje = (najmanjiElement->sledeci)->sledeci;
	Elem* elementPosleNajmanjegElementaKojiSeIzbacuje = najmanjiElement->sledeci;
	free(elementPosleNajmanjegElementaKojiSeIzbacuje);

	najmanjiElement->sledeci = elementPosleNajmanjegElementaKojiSeNeIzbacuje;
}

int prebrojPozitivne(Elem* lst) {

	if (lst == NULL) {
		return 0;
	}
	else {
		if (lst->broj > 0) {
			return 1 + prebrojPozitivne(lst->sledeci);
		}
		else {
			return prebrojPozitivne(lst->sledeci);
		}
	}

}

void ispisiJedanElement(Elem lst) {
	printf("Ovo je moj broj : %i \n", lst.broj);
	printf("Ovo je moj sledeci broj : %p \n", lst.sledeci);
}

void ispisiElementeKojiSuManjiOdN(Elem* lst, int n) {
	while (lst != NULL) {
		if (lst->broj < n) {
			ispisiJedanElement(*lst);
		}
		lst = lst->sledeci;
	}
}

void izbrisiParneElementeUListi(Elem* lst) {
	Elem* trenutni = lst;
	Elem* prethodni = NULL;

	while (trenutni != NULL) {
		Elem* stari = trenutni;
		if (stari->broj % 2 == 0) {
			free(stari);
			prethodni->sledeci = trenutni->sledeci;
			trenutni = trenutni->sledeci;
		}
		else {
			prethodni = trenutni;
			trenutni = trenutni->sledeci;
		}
		
		
	}
}

//Dodavanje na pocetku ali moramo da krenemo od pocetka prve liste.

Elem* vratiInvertovanuListu(Elem* lst) {
	Elem* invertovanaLista = NULL;
	while (lst != NULL) {
		Elem* novi = (Elem*)malloc(sizeof(Elem));
		novi->broj = lst->broj;
		novi->sledeci = invertovanaLista;
		invertovanaLista = novi;
		lst = lst->sledeci;
	}
	return invertovanaLista;
}

int main() {

	Elem* mojaPrvaLista = NULL;
	mojaPrvaLista = citaj1(4);
	ispisiListu(mojaPrvaLista);
	Elem* mojaDrugaLista = vratiInvertovanuListu(mojaPrvaLista);
	ispisiListu(mojaDrugaLista);
	return 0;
}