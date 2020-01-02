/* Kalkulator v.1.0, projekt i wykonanie Michał Piątkowski all rights reserved ;-) */
/* nie kopiowałem ani nie podglądałem innych kalkulatorów(poza jednym małym warunkiem:-P), wszystkie podobieństwa są dziełem przypadku :-) */

/* PLAN PROGRAMU Kalkulator:
1. deklaracja zmiennych;
2. deklaracja funkcji;
3. określenie działań w postaci funkcji aby było łatwiej i czytelniej(na końcu programu za  funkcją main();
  (wiem, że to przerost formy nad treścią ale to w ramach ćwiczeń)
4. w funkcji main():
	- wczytywanie liczb z klawiatury,
	- wybór działania,
	- zbudowanie konstrukcji switch dla poszczególnych działań,
	- warunki przy dzieleniu oraz wyjście z programu po wybraniu takiej opcji przez użytkownika,
	- zapetlenie w przypadku wybrania złego działania,
	- zapętlenie w obliczeniach,
	- zapętlenie w przypadku dzielenie przez 0 z możliwością zmiany liczb,
5. w funkcjach działania matematyczne;
6. */

#include <stdio.h>
#include <stdlib.h>


	double liczba_1=0; /*deklaracje i inicjalizacje zmiennych*/
	
	double liczba_2=0;

	double wynik=0;

	int dzialanie=0;

	double dodawanie(double liczba_1,double liczba_2); /*deklaracje funcji*/

	double odejmowanie(double liczba_1,double liczba_2);
	
	double mnozenie(double liczba_1,double liczba_2);

	double dzielenie(double liczba_1,double liczba_2);

	char wybor;
	



int main()
{

	printf("\n\n\nversion \"1.0\"\n\n");
	printf("\n\t\t###############\n\t\t #############\n\t\t  ###########\n\t\t   #########\n\t\t    #######\n\t\t     #####\n\t\t      ###\n\t\t       #\n"); 
	printf("\n\n\t TO TWÓJ ULUBIONY KALKULATOR!\n RAZ ZACZNIESZ A NIE PRZESTANIESZ GO UŻYWAĆ :-)\n\n\n\n");
	/*pętla ponownych obliczeń oraz przy wybraniu dzielenia przez 0 */
  do{ 

	printf("Podaj proszę pierwszą liczbę: \n\n"); /* zczytywanie liczb */
	scanf("%lf", &liczba_1); 
	

	printf("\nPodaj proszę drugą liczbę: \n\n");
	scanf("%lf", &liczba_2);
	
		/* pętla w razie wybrania złegfo działania */
	do{ 

		printf("\n\nJakie działanie chcesz wykonać? :\n(wybierz odpowiednią liczbę)\n\n 1 - dodawanie, \n 2 - odejmowanie, \n 3 - mnożenie, \n 4 - dzielenie, \n 5 - wyjście z programu. \n\n");
		scanf("%d", &dzialanie);
		getchar();
		printf("\n");
		if (dzialanie !=1 && dzialanie !=2 && dzialanie !=3 && dzialanie !=4 && dzialanie!=5){
			printf("Wybrano nieprawidłowe działanie!!\n");
			printf("\n");
			}
	
	  }while  (dzialanie !=1 && dzialanie !=2 && dzialanie !=3 && dzialanie !=4 && dzialanie!=5);

	/* konstrukcja switch dla poszczególnych działań, można rozbudowywać o kolejne działania, można by to
	jeszcze pewnie uprościć albo wywalić pod funkcje ale już mało czasu było */
		
	switch (dzialanie){
				case 1:
					dodawanie(liczba_1, liczba_2);
					printf("Wybrałeś dodawanie, oto Twoje obliczenia: \n\n");
					printf("%10.10lf + %10.10lf = %10.10lf \n\n", liczba_1, liczba_2, wynik);
					printf("Czy chcesz wykonać ponowne obliczenia? T/N?? \n");
					scanf("%c", &wybor);
				break;

				case 2:
					odejmowanie(liczba_1, liczba_2);
					printf("Wybrałeś odejmowanie, oto Twoje obliczenia: \n\n");
					printf("%10.10lf - %10.10lff = %10.10lf \n\n", liczba_1, liczba_2, wynik);
					printf("Czy chcesz wykonać ponowne obliczenia? T/N?? \n");
					scanf("%c", &wybor);
				break;
		
				case 3:
					mnozenie(liczba_1, liczba_2);
					printf("Wybrałeś mnożenie, oto Twoje obliczenia: \n\n");
					printf("%10.10lf * %10.10lf = %10.10lf \n\n", liczba_1, liczba_2, wynik);
					printf("Czy chcesz wykonać ponowne obliczenia? T/N?? \n");
					scanf("%c", &wybor);
				break;

				case 4:		/* warunek nie dzielenia przez 0 */ 
					if (liczba_2==0){			
									
						printf("Nie dzielimy przez 0!!!! Podaj ponownie liczby:\n\n");
						}	

					else {
						dzielenie(liczba_1, liczba_2);
						printf("Wybrałeś dzielenie, oto Twoje obliczenia: \n\n");
						printf("%10.10lf / %10.10lf = %10.10lf \n", liczba_1, liczba_2, wynik);
						printf("Czy chcesz wykonać ponowne obliczenia? T/N?? \n");
						scanf("%c", &wybor);
						}
				break;

				case 5:
					printf("Program został zamknięty prawidłowo!\n\n");
					exit(0);
				break;
			}		

		
				
				
  }while (wybor!='N' && wybor!='n');
	

	
		
return 0;

}
	/* definicje funckji*/

	double dodawanie(double liczba_1, double liczba_2){
		
		wynik=liczba_1+liczba_2;

	return wynik;

	}

	double odejmowanie(double liczba_1,double liczba_2){
			
		wynik=liczba_1-liczba_2;
			
	return wynik;
			
	}
	double mnozenie(double liczba_1,double liczba_2){
			
		wynik=liczba_1*liczba_2;
			
	return wynik;
			
	}
	double dzielenie(double liczba_1,double liczba_2){
 		
		wynik=liczba_1/liczba_2;
			
	return wynik;
			
	}
		
