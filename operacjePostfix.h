#ifndef OPERACJEPOSTFIX_H
#define OPERACJEPOSTFIX_H

//----------------------------OPERACJE-DO-ZAMIANY-NA-POSTFIX--------------------------

int czyOperator(char znak);				                    //funkcja sprawdza czy znak jest operatorem matematycznym
int czyFunkcja(char znak);				                    //sprawdza czy znak jest funkcja matematyczna
int czyLiczba(char znak);				                    //sprawdza czy znak jest liczba lub kropka
int czyLewostronny(char znak);			                    //sprawdza czy operator jest lewostronny
int priority(char znak);				                    //ustawia priorytet dla znaku

#endif
