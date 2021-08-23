//Minule jste měli úkol vypsat pomocí cyklu sudá čísla od 10 do 0 a spočítat jejich sumu
//● Upravte úkol tak, že tento kód přesunete do funkce a tato funkce vrátí onu sumu čísel
//● Parametrem funkce bude hodnota, od které se bude počítat (tzn. ne od čísla 10, ale od nějakého zadaného čísla > 0)
//● V mainu zavolejte funkci a vytiskněte sumu


#include<stdio.h>
#include<stdbool.h>

void main(){
    float a, b, c;
    printf("zadejte 3 cisla: ");
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    if ((a > b) && (a > c)){
        printf("Prvni cislo je nejvetsi\n");
    }
    else if((b > a) && (b > c)){
        printf("Druhe cislo je nejvetsi\n");
    }
    else{
        printf("Treti cislo je nejvetsi\n");
    }
}
