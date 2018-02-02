#include <stdio.h>
#include "stos.h"
#include "stosLiczbowy.h"

int czyPustyStosL( stosL *s) {			                    //funkcja sprawdza czy stos z liczbami jest pusty
	if(s->top==-1)						                    //jesli top wskazuje -1 to stos jest pusty
		return 1;
	return 0;
}

void pustyStosL( stosL *s) {			                    //funkcja czysci stos
	s->top=-1;							                    //ustawia top na -1
}

void na_stosL( stosL *s,double x) {		                    //wrzuca liczbe na stos
    if(s->top == (MAX-1)) {				                    //jesli top jest równy MAX-1 to oznacza ze tablica jest pelna
        printf("\nSTOS PELEN");
    }
    else {
        ++s->top;						                    //zwieksza wysokosc stosu o 1
        s->dane[s->top]=x;				                    //wrzuca zmienna x na stos
    }
}

double ze_stosuL( stosL* s) {			                    //funkcja pobiera liczbe ze stosu
    if(!czyPustyStosL(s)) {				                    //sprawdza czy stos jest pusty
        double liczba= s->dane[s->top];                     //pobiera liczbe ze stosu
        --s->top;						                    //zmniejsza wysokosc stosu o 1
		return liczba;					                    //zwraca liczbe
    }
    return 0;
}
