// ● Úkol č.1
// – Odstraňte \n z konce řetězce (použijte funkci najdi z minulého úkolu)
// – Napište funkci printLowerCharacters(char* str, int velikost), která vytiskne znaky malými písmeny řetězce a oddělené mezerou

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int najdi(char znak, char *pole, int velikost){
    for (int i = 0; i < velikost; i++){
        if (pole[i] == znak){
            return (i+1);
        }
    }
    return -1;
}

void printLowerCharacters(char* str, int velikost){
    for (int i = 0; i < velikost; i++){
        str[i] = tolower(str[i]);
        printf ("%c ", str[i]);
    }
}

int main(){
    char *arr = (char*) malloc(sizeof(char)*6);
    int n = 10;
    arr = "Oscilator";
    char pismeno;
    printf("zadej hledany znak: ");
    scanf("%c", &pismeno);
    int pozice = najdi(pismeno, arr, n);
    printf("Znak %c se nachazi na %d. pozici ve slove %s\n", pismeno, pozice, arr);
    printLowerCharacters(arr, n);
    // arr[pozice] = '\0';
    printf("%s", arr);
    free(arr);    arr[pozice] = '\0';
    printf("%s", arr);
    return 0;
}