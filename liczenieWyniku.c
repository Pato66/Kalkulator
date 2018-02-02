#include <stdio.h>
#include <math.h>
#include "stos.h"
#include "stosLiczbowy.h"
#include "liczenieWyniku.h"
#include "operacjeZmienne.h"

double silnia(double liczba1) {								//funkcja liczy silnie
	int x,i,wynik=1;
	if(liczba1==0)
		return 1;
	if(liczba1>0) {
		x=(int)(liczba1+0.5);
		for(i=1;i<=x;i++) {
			wynik*=i;
		}
		return wynik;
	}
}

double licz(char wejscie[], int rozmiar, zmienna zmienne[]){//funkcja liczy wynik z otrzymanej tablicy z ONP
	int i=0,j=0;
	double liczba1, liczba2, wynik;
	stosL liczby;
	pustyStosL(&liczby);						            //ustawia pusty stos z liczbami
	char pomoc[rozmiar];						            //dodatkowa tablica znakowa do zamiany ciagu znakow na double
	while(i<rozmiar && wejscie[i]!='=') {		            //dopóki nie dojdzie do konca tablicy lub znaku '='
		if(wejscie[i]=='_') {		                        //znak _ oznacza liczbe ujemna
			pomoc[j]='-';
			j++;
		}
		if(czyLiczba(wejscie[i])) {				            //sprawdza czy znak na wejsciu jest liczba
			while(czyLiczba(wejscie[i]) ) {		            //jesli tak to dopóki na wejsciu znak jest liczba kopiuje znak do tablicy 
				pomoc[j]=wejscie[i];
				j++;
				i++;
			}
			pomoc[j]='\0';						            //dopisuje znak konca tablicy
			double pom = atof(pomoc);			            //zamienia tablice na double za pomoca funkcji atof()
			na_stosL(&liczby,pom);				            //wrzuca liczbe na stos
			j=0;
		}
		if(wejscie[i]=='#') { 					            //sprawdza czy znak na wejsciu to prawy nawias
     		i++;
     		while((wejscie[i]>='a' && wejscie[i]<='z') || (wejscie[i]>='A' && wejscie[i]<='Z')) {	//przepisuje litery do tablicy
     			pomoc[j]=wejscie[i];
				j++;
				i++;
			}
			pomoc[j]='\0';						            //dodaje znak konca tablicy
			j=0;
			na_stosL(&liczby,wczytaj(pomoc,zmienne));		//wrzuca na stos liczbe z tablicy zmiennych o nazwie zawarta w tablicy pomoc
     	}
		if(czyOperator(wejscie[i])) {						//jesli na wejsciu jest operator
			liczba2=ze_stosuL(&liczby);						//pobiera 2 liczby ze stosu
			liczba1=ze_stosuL(&liczby);
			if(wejscie[i]=='+') {wynik=liczba1+liczba2;}	//wykonuje operacje odpowiadajaca danemu operatorowi
			if(wejscie[i]=='-') {wynik=liczba1-liczba2;}
			if(wejscie[i]=='*') {wynik=liczba1*liczba2;}
			if(wejscie[i]=='/') {if(liczba2!=0)wynik=liczba1/liczba2;}
			if(wejscie[i]=='^') {wynik=pow(liczba1,liczba2);}
			na_stosL(&liczby, wynik);						//wynik operacji wrzuca na stos
		}
		else if(czyFunkcja(wejscie[i])) {					//jesli na wejsciu jest funkcja
			liczba1=ze_stosuL(&liczby);						//pobiera liczbe ze stosu
			if(wejscie[i]=='s') {wynik=sin(liczba1);}		//wykonuje okreslona funkcje
			if(wejscie[i]=='c') {wynik=cos(liczba1);}
			if(wejscie[i]=='t') {wynik=tan(liczba1);}
			if(wejscie[i]=='v') {if(liczba1>0)wynik=sqrt(liczba1);}
			na_stosL(&liczby, wynik);						//wrzuca wynik funkcji na stos
		}
		else if(wejscie[i]=='!') {							//jesli na wejsciu jest operator silnii
			liczba1=ze_stosuL(&liczby);                      //pobiera liczbe ze stosu
			wynik=silnia(liczba1);                          //wykonuje funkcje
			na_stosL(&liczby, wynik);                       //wrzuca wynik funkcji na stos
		}
		else if(wejscie[i]=='(')							//jesli napotkalo na lewy nawias to oznacza ze brakowalo prawego nawiasu
			printf("Brakuje nawiasu zamykajacego\n");
		i++;
	}
	wynik = ze_stosuL(&liczby);				                //bierze ostateczny wynik ze stosu
	
	if(wejscie[i]=='=') {					                //jesli na wejsciu jest znak '='
		i++;
		while(i<rozmiar) {					                //przepisuje nazwe zmiennej do pomocniczej zmiennej
			pomoc[j]=wejscie[i];
			j++;
			i++;
		}
		pomoc[j]='\0';						                //dodaje znak konca tablicy
		zapisz(pomoc,wynik,zmienne);		                //zapisuje wynik w zmiennej o nazwie zawartej w tablicy pomoc
	}
	return wynik;
}
