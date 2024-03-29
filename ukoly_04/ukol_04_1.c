//Úkol č.1
//Načtěte celá čísla do pole a vytvořte funkci, která vrátí součet čísel v poli
//● Počet čísel zadejte předem pomocí proměnné int soucet_pole(int *pole, int pocet)

#include <stdio.h>

int soucet_pole(int (*pole)[5], int pocet)
{
	int suma = 0;
	for (int i = 0; i < pocet; i++){
		suma = suma + (*pole)[i];
	}	
	return suma;
}

int main() {
	int polea[5] = {1, 2, 6, 6, 8};
	int num = sizeof(polea)/sizeof(int);
	printf("Soucet cisel v poli je: %d\n", soucet_pole(&polea, num));
	return 0;
}
