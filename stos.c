#include <stdio.h>
#include "stos.h"

int czyPustyStos( stos *s) {		                        //funkcja sprawdza czy stos z znakami jest pusty
	if(s->top==-1)					                        //jesli top wskazuje -1 to stos jest pusty
		return 1;
	return 0;
}

void pustyStos( stos *s) {			                        //funkcja czysci stos
	s->top=-1;						                        //ustawia top na -1
}

void na_stos( stos *s,char x) {		                        //funkcja wrzuca znak na stos
    if(s->top == (MAX-1)) {			                        //jesli top jest równy MAX-1 to oznacza ze tablica jest pelna
        printf("\nSTOS PELEN");
    }
    else {
        ++s->top;					                        //zwieksza wysokosc stosu o 1
        s->dane[s->top]=x;                                  //wrzuca zmienna x na stos
    }
}

char ze_stosu( stos* s)	{			                        //funkcja pobiera znak ze stosu
    if(!czyPustyStos(s)) {			                        //sprawdza czy stos jest pusty
        char znak= s->dane[s->top];	                        //pobiera znak ze stosu
        --s->top;					                        //zmniejsza wysokosc stosu o 1
		return znak;				                        //zwraca znak
    }
    return 0;
}
