/*  
	Generator i sorter liczb losowych
	projekt i wykonanie Michał Piątkowski i Dacjan Kijowski
	version 0.9 
	p.s. na razie oparty na algorytmie bąbelkowym i funkcji generuj 
	będziemy kombinować dalej :)
*/ 


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generuj.h"

int main()
{  
    int rozmiar;
    
    printf("Podaj ilość liczb do posortowania: \n");
    scanf("%d", &rozmiar);

    int *tab;
    tab = malloc(rozmiar * sizeof(*tab));

    generuj(rozmiar, tab);   
    
    int x = rozmiar-1;
    int y = rozmiar-1;
    
    printf("Następujące liczby, wygenerowane losowo, zostaną posortowane od najmniejszej do największej:\n\n");
        for(int n=0; n<rozmiar; n++)
        {
            printf("%d ", tab[n]);
        }
    printf("\n");

    for(int m=0; m<y; m++)
    {
        int limIter=0;
        for(int n=0; n<x; n++)
        {
            if (tab[n]>tab[n+1])
            {        
                  tab[n] = tab[n]^tab[n+1];
                tab[n+1] = tab[n]^tab[n+1];
                  tab[n] = tab[n]^tab[n+1];
                limIter++;
            }
               
        }
        
        if(limIter == 0)
		{
		    break;
		}  		
        x--;
           
    }

    printf("\n\n\n ### WYNIK SORTOWANIA LICZB GENEROWANYCH LOSOWO: ###\n");
        for(int n=0; n<rozmiar; n++)
        {
            printf("%d ", tab[n]);
        }
    printf("\n");
    free(tab);
    return 0;
}
