#include<stdio.h>

int EvenSum(int zadaneCislo){
    int sum = 0;
    while (zadaneCislo>0)
    {
        if ((zadaneCislo%2) == 0){
            sum = sum + zadaneCislo;
        }
        zadaneCislo -= 1;
    }
    return sum;    
}

void main() {
    int uzivatelovoCislo;
    printf("Zadej cislo: ");
    scanf("%d", &uzivatelovoCislo);
    printf("tve cislo je: %d\n", uzivatelovoCislo);
    printf("\nSoucet je: %d\n", EvenSum(uzivatelovoCislo));
}

