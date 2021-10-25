/* 
Vít Vlašánek
VŠB - FEI
ID: VLA0095
úkol 3 - softmax 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//funkce na sečtení prvku v poli
float suma_pole(const float * vstupni_vektor, int len){
	float suma = 0;

	for (int i = 0; i < len; i++){
		suma = suma + (exp(vstupni_vektor[i]));
	}	
	return suma;

}

//funkce na zjištění největšího prvku pole
int argmax( const float * nove_pole, const int len ){
    int maximum_pozice = 0;
    float maximum_hodnota = 0;
    for (int i = 0; i < len; i++){
        if (nove_pole[i] > maximum_hodnota){
            maximum_hodnota = nove_pole [i];
            maximum_pozice = i;
        }
    }
    return maximum_pozice;    
}

//funkce softmax
float * softmax( const float * vstupni_vektor, const int len ){
    float * nove_pole = (float*)malloc(sizeof(float)*len);

    if (nove_pole == NULL){
        fprintf(stderr, "Pamet nebyla alokovana\n");
        exit(-1);
    }
    
    for (int i = 0; i < len; i++){
        nove_pole[i] = exp(vstupni_vektor[i]) / suma_pole(vstupni_vektor, len);
    }

    printf("\n%d", argmax(nove_pole, len));
    for (int i = 0; i < len; i++){
        printf(" %.4f", nove_pole[i]);
    }
    free(nove_pole);
    return nove_pole;
    
}

int main() {
    int pocet_radku = 0;
    scanf("%d",&pocet_radku);
    int len = 10;
    float * vstupni_vektor = (float*)malloc(sizeof(float)*len);
    //chyba
    if (vstupni_vektor == NULL) {
        fprintf(stderr, "Pamet nebyla alokovana\n");
    return -1;
    }

    for (int i = 0; i < pocet_radku; i++)
    {
        printf("\n\nvstup:\n");
        for (int i = 0; i < len; i++)
        {
            scanf("%f", &vstupni_vektor[i]);
        }
        printf("\n\nvýstup:");
        softmax(vstupni_vektor,len);
        // for (int i = 0; i < len; i++){
        //     printf(" %.4f\n", softmax(vstupni_vektor,len)[i]);
        // }
    }

    printf("\n");
    free(vstupni_vektor);
    return 0;
}
