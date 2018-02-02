#include <stdio.h>
#include <string.h>
#include "stos.h"
#include "stosLiczbowy.h"
#include "operacjeZmienne.h"

void zapisz(char nazwa[], double x,zmienna tab[]) {	        //funkcja zapisuje nazwe zmiennej i wartoscia do tablicy z zmiennymi
	int i;
	for(i=0;i<MAX;i++) {
		if(strcmp(tab[i].nazwa,nazwa)==0) {			        //uzywa funkcje strcmp() do porownania dwoch ciagow znakowych
			tab[i].wartosc=x;						        //jesli sa rowne to zastepuje zmienna nowa wartoscia
			return;
		}
	}
	for(i=0;i<MAX;i++) {
		if(tab[i].nazwa[0]=='\0') {					        //jesli nazwa jest pusta
			strcpy(tab[i].nazwa,nazwa);				        //uzywa funkcji strcpy() do skopiowania nazwy nowej zmiennej do pustego pola
			tab[i].wartosc=x;						        //i nadaje jej wartosc
			return;
		}	
	}
}
double wczytaj(char nazwa[], zmienna tab[]) {		        //funkcja wczytuje wartosc zmiennej o podanej nazwie z tablicy z zmiennymi
	int i;
	for(i=0;i<MAX;i++) {
		if(strcmp(tab[i].nazwa,nazwa)==0)			        //uzywa funkcje strcmp() do porownania dwoch ciagow znakowych
			return tab[i].wartosc;					        //jesli sa rowne to zwraca wartosc porownanej zmiennej
	}
	return 0;
}
