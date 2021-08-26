//● Úkol č.3
//– Vytvořte dynamické pole o vybrané velikosti a naplňte ho znaky (typ char)
//– Vytvořte funkci int najdi(char znak, char *pole, int velikost), která vrátí první pozici znaku v poli, pokud v poli znak není, tak -1


#include<stdio.h>
#include<stdlib.h>

int najdi(char znak, char *pole, int velikost){
    for (int i = 0; i < velikost; i++){
        if (pole[i] == znak){
            return (i+1);
        }
    }
    return -1;
}

int main(){
    char *arr = (char*) malloc(sizeof(char)*6);
    int n = 10;
    arr = "oscilator";
    char pismeno;
    printf("zadej hledany znak: ");
    scanf("%c", &pismeno);
    printf("Znak %c se nachazi na %d. pozici ve slove %s\n", pismeno, najdi(pismeno, arr, n), arr);
    free(arr);
    return 0;
}