
#include <stdio.h>
#include <stdlib.h>

int * tvorba_pole (const int len){
    int * vystupni_vektor = (int*)malloc(sizeof(int)*len);
    return(vystupni_vektor);
}

void fill_array( int * vstupni_vektor, const int len){
    scanf("%d",&vstupni_vektor[0]);
    int delka = vstupni_vektor[0];
    for (int i = 0; i < delka; i++)
    {
        scanf("%d", &vstupni_vektor[i+1]);
    }
}


int * is_odd(int * vstupni_vektor){
    int delka = vstupni_vektor[0];
    for (int i = 1; i <= delka; i++)
    {
        if (vstupni_vektor[i] % 2 == 0)
            printf ("%d even\n", vstupni_vektor[i]);
        else
            printf ("%d odd\n", vstupni_vektor[i]);
    }
    
    return vstupni_vektor;
}

int main(){
    int len = 50;
    //scanf("%d", &len);
    int * adresa_pole = tvorba_pole(len);
    fill_array(adresa_pole, len);
    is_odd (adresa_pole);
    free(adresa_pole);
}