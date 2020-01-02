#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "generuj.h"

int generuj(int rozmiar, int *tab) 
{
    srand(time(0));
    for(int i=0; i<rozmiar; i++)
        {
             tab[i]=rand()%1000;
        }
        
    return *tab;
}
