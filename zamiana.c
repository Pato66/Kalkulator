#include <stdio.h>
#include "stos.h"
#include "zamiana.h"

void zamien(char wejscie[], int rozmiar, char wyjscie[]) {
     int i = 0,j = 0;
     int czyUjemna = 1;				//##<-=-=-=-=-=-=-=-=-=-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=<><><><><><><><><><><>
     stos s;
     pustyStos(&s);								            //ustawia pusty stos
     while(i<rozmiar && wejscie[i]!='=') {		            //wykonuje operacje do koñca tablicy lub natrafienia znaku zapisu do zmiennej
     	if(wejscie[i]=='#') { 					            //jesli znak to '#' 
     		 czyUjemna = 0;
			 do {									        //wtedy przepisuje znak '=' i wszystkie litery odpowiadajace nazwie zmiennej
     			wyjscie[j]=wejscie[i];
				j++;
				i++;
     		}
     		while((wejscie[i]>='a' && wejscie[i]<='z') || (wejscie[i]>='A' && wejscie[i]<='Z'));
     		wyjscie[j]=' ';
     		j++;
     		if(wejscie[i]=='=' ||  wejscie[i]=='\0')
        		i--;
		}
        else if(czyLiczba(wejscie[i])) {   		            //sprawdza czy znak na wejsciu to liczba
            wyjscie[j]=wejscie[i];				            //jesli jest to dodaje liczbe na wyjscie
            j++;
            czyUjemna = 0;
        }
        else if(wejscie[i]=='!') {							//##<wmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmwmmwmwwmmwmwmwmwmwmwwmmwmwmwmwmwmwmwmwmwmwmmwmwmwmwmwmmwmwmwmwmwm
        	wyjscie[j]=' ';				         
	     	j++;
	     	wyjscie[j]='!';				         
	     	j++;
        }
        else if(wejscie[i]=='(' || czyFunkcja(wejscie[i])) {//sprawdza czy znakiem na wejsciu jest lewy nawias lub funkcja
        	na_stos(&s,wejscie[i]);				            //jesli jest to wrzuca go na stos
        	czyUjemna = 1;
        }
        if(czyOperator(wejscie[i])) {		                //sprawdza czy znak na wejsciu to operator   			
			if(czyUjemna==1){			                    //jesli ostatni znak byl operatorem lub lewym nawiasem oznacza to, ze minus jest unarny
				wyjscie[j]='_';			                    //przepisuje minus unarny
				j++;
			}else {
				wyjscie[j]=' ';						        //oddziela operator od liczb spacja
        		j++;
				while(!czyPustyStos(&s) && (czyLewostronny(wejscie[i]) && priority(wejscie[i]) <= priority(s.dane[s.top])) || //dopóki stos nie jest pusty i jesli operator na wejsciu jest lewostronny
	                ((!czyLewostronny(wejscie[i])) && priority(wejscie[i]) < priority(s.dane[s.top]))) {                      //i priorytet jego jest mniejszy lub równy priorytetowi operatora na stosie
	                 	                                                                                                      //lub operator na wejsciu jest prawostronny i priotytet jego
	                                                                                                                          //jest mniejszy od priorytetu operatora na stosie
						wyjscie[j]=ze_stosu(&s);		    //wyrzuca operator ze stosu i wrzuca go na wyjscie 
						j++;
						wyjscie[j]=' ';				        //robi odstep od kolejnych zmiennych
	     				j++;
					
				}
	        	na_stos(&s,wejscie[i]);				        //wrzuca na stos operator z wejscia
	    	}
        }
        else if(wejscie[i]==')') {				            //sprawdza czy znak na wejsciu to prawy nawias
        	wyjscie[j]=' ';				
        	j++;
        	while(s.dane[s.top]!='(' && !czyPustyStos(&s)) {//dopóki nie znajdzie lewego nawiasu i stos nie jest pusty
	        	wyjscie[j]=ze_stosu(&s);					//na wyjscie wrzuca operatory ze stosu 
				j++;
			}
			if(!czyPustyStos(&s))							//jesli stos nie jest pusty
				ze_stosu(&s);								//usuwa lewy nawias ze stosu
			else
				printf("Brakuje nawiasu otwierajacego\n");	//jesli stos jest pusty i nie znaleziono lewego nawiasu to oznacza ze brakuje nawiasu
			if(czyFunkcja(s.dane[s.top])) {					//jesli na wejsciu jest funkcja to wrzuca ja na stos
				wyjscie[j]=ze_stosu(&s);					//na wyjscie wrzuca operatory ze stosu 
				j++;
			}
        }
        i++;
     }
     while(!czyPustyStos(&s)) {					            //po przejsciu calego wejscia zaczyna opró¿niaæ stos
     	wyjscie[j]=' ';							            //robi odstep od kolejnych operatorów
        j++;
     	wyjscie[j]=ze_stosu(&s);					        //wrzuca na wyjscie operator ze stosu
     	j++;
	 }
	 if(wejscie[i]=='=' && wejscie[i+1]!='\0') {            //jesli znaleziono znak '=' i nastepny znak nie jest '\0'
	 	 wyjscie[j]=' ';
         j++;
         wyjscie[j]='=';
         j++;i++;
		 while(i<rozmiar) {						            //kopiuje litery az dojdzie do konca tablicy
			 if((wejscie[i]>='a' && wejscie[i]<='z') || (wejscie[i]>='A' && wejscie[i]<='Z')) { //kopiuje litery i pomija liczby i znaki specjalne
				wyjscie[j]=wejscie[i];
				j++;
			}
			i++;
		}
	}
	 wyjscie[j]='\0';							            //dopisuje znak konca tablicy znakowej
	 puts(wyjscie);								            //wypisuje tablice

}
