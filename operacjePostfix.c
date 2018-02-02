#include <stdio.h>
#include "operacjePostfix.h"

int czyOperator(char znak) {			                    //funkcja sprawdza czy znak jest operatorem matematycznym
    if(znak == '+' || znak == '-' || znak == '*' || znak == '/' || znak == '^')	
        return 1;
    return 0;
}
int czyFunkcja(char znak) {				                    //sprawdza czy znak jest funkcja matematyczna
	if(znak == 's' || znak == 'c' || znak == 't' || znak == 'v')	//s = sinus		c = cosinus 	t = tangens    v = pierwiastek
        return 1;
    return 0;
}
int czyLiczba(char znak) {				                    //sprawdza czy znak jest liczba lub kropka
    if(znak>47 && znak<58 || znak=='.')
        return 1;
    return 0;
}
int czyLewostronny(char znak) {			                    //sprawdza czy operator jest lewostronny
    if(znak == '+' || znak == '-' || znak == '*' || znak == '/' )
        return 1;
    return 0;
}
int priority(char znak) {				                    //ustawia priorytet dla znaku
	if(znak == '+' || znak == '-')
        return 1;
    if(znak == '*' || znak == '/' )
        return 2;
    if(znak =='^')
    	return 3;
    return 0;
}
