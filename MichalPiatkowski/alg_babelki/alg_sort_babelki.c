#include <stdio.h>
#include <stdlib.h>

int main()
{  
    int rozmiar;
    
    printf("Podaj ilość liczb do posortowania: \n");
    scanf("%d", &rozmiar);

    int* tab;
    tab = malloc(rozmiar * sizeof(*tab));
    
    int x = rozmiar-1;
    int y = rozmiar-1;
    
    printf("Podaj dowolne liczby całkowite do posortowania (po każdej naciśnij \"enter\"):\n");
        for(int j=0; j<rozmiar; j++)
        {
            scanf("%d", &tab[j]);
        }

    printf("Następujące liczby zostaną posortowane od najmniejszej do największej:\n\n");
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
               
        /*
            printf("\n podgląd sortowania liczb:\n");
            for(int n=0; n<rozmiar; n++)
            {
                printf("%d ", tab[n]);
            }   
        */
        }
        
        if(limIter == 0)
		{
			break;
		}  		
        x--;
           
    }

    printf("\n\n\n WYNIK SORTOWANIA:\n");
        for(int n=0; n<rozmiar; n++)
        {
            printf("%d ", tab[n]);
        }
    printf("\n");
    free(tab);
    return 0;
}

