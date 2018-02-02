#ifndef STOS_H
#define STOS_H


#define MAX 50

//----------------------------STOS--------------------------

typedef struct stos {
	char dane[MAX];											//wartosci stosu
	int top;												//indeks najwy¿szego elementu
} stos;
typedef struct stosL {
	double dane[MAX];				                        //wartosci stosu
	int top;						                        //indeks najwy¿szego elementu
} stosL;
typedef struct zmienna {
	double wartosc;					                        //wartosc zmiennej
	char nazwa[MAX];				                        //nazwa zmiennej
} zmienna;

int czyPustyStos( stos *s);			                        //funkcja sprawdza czy stos z znakami jest pusty
void pustyStos( stos *s);			                        //funkcja czysci stos
void na_stos( stos *s,char x); 		                        //funkcja wrzuca znak na stos
char ze_stosu( stos* s);			                        //funkcja pobiera znak ze stosu

#endif
