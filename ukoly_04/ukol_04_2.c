//Úkol č.2
//– Vytvořte pole o 20 prvcích a naplňte ho náhodnými čísly
//– Jak na náhodná čísla?
//#include <stdlib.h>
//#include<stdio.h>
//#include <time.h>
//int main() {
//  srand(time(NULL)); // na začátek main
//  int r = rand() % 30; // náhodné číslo z intervalu 0 až 29
//}
//– Vytvořte funkci, která vrátí maximální a minimální hodnotu z pole a hodnoty vytiskněte

#include <stdlib.h>
#include<stdio.h>
#include <time.h>
	
void minmax(int pole[], int *polemin, int *polemax) {
	for (int i = 0; i < 20; i++) {
		if (pole[i] < *polemin) {
			*polemin = pole[i];
		}
		else if(pole[i] > *polemax){
			*polemax = pole[i];
		}
		else {
		}
	}
}

int main() {
	int pole[20];
	int polemin = 30;
	int polemax = 0;
	srand(time(NULL)); // na začátek main
	for (int i = 0; i < 20; i++) {
		int r = rand() % 30; // náhodné číslo z intervalu 0 až 29
		pole[i] = r;
		printf("%d\n", r);
	}
	minmax(pole, &polemin, &polemax);
	printf("\nmax je: %d\n", polemax);
	printf("min je: %d\n", polemin);
	return 0;

}
