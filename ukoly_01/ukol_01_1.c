#include<stdio.h>

int main() {
    int i = 10;
    int soucet = 0;
    int uzivatelovoCislo;
    printf("Zadej cislo: ");
    scanf("%d", &uzivatelovoCislo);
    while (i>0){
        if ((i%2) == 0)
        {
            printf("%d\n", i);
        }
        soucet = soucet + i;
        i = i-1;
    }
    printf("\nSoucet je: %d\n", soucet);
    printf("tve cislo je: %d\n", uzivatelovoCislo);
    return 0;
}


