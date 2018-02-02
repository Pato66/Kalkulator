#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stos.h"
#include "zamiana.h"
#include "liczenieWyniku.h"

int main() {
    
    printf("\n\n\n\t- - - - -\n\t| Projekt: KALKULATOR NAUKOWY\n\t| Wykonanie: PATRYK HUDY, KRYSTIAN JEDRZEJCZYK, MACIEJ KLIMCZYK\n\t- - - - -\n");
    
	char tab[MAX];
	char RPN[MAX];
	zmienna zmienne[MAX];
	double wynik;
	printf("\n\n\n\n\n");
	do {
	    printf("Dzialanie: ");
		gets(tab);								            //wczytuje tablice
		zamien(tab,strlen(tab),RPN);			            //zamienia tablice tab na ONP i zapisuje ja do tablicy RPN
		wynik = licz(RPN,strlen(RPN),zmienne);	            //oblicza wynik
		printf("Wynik = %lf\n\n",wynik);		            //wypisuje wynik
	}
	while(tab[0]!='\0');						            //powtarza operacje dopóki podana tablica znakow bedzie pusta
	return 0;
}
