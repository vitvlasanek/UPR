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
float suma_pole(const float * array, int len){
	float suma = 0;
	for (int i = 0; i < (len-1); i++){
		suma = suma + (array)[i];
	}	
	return suma;
}

//funkce softmax
float * softmax( const float * array, const int len ){
    for (int i = 0; i < (len-1); i++){

        array[i] = exp(array[i]) / suma_pole(array, len);

    }
    return array;
}

//funkce na zjištění největšího prvku pole
int argmax( const float * array, const int len ){
    int maximum = 0;
    for (int i = 0; i < (len-1); i++){

        if (array[i] > maximum){

            maximum = array[i];

        }
        
    }
    return maximum;    
}

int main() {
    int pocet = 0;
    scanf("%d",&pocet);
    int len = 10;
    float * array = (array*)malloc(sizeof(float)*len);

    if (array == NULL) {
        fprintf(stderr, "Pamet nebyla alokovana\n");
    return -1;
    }

    for (int i = 0; i < (pocet-1); i++)
    {
        printf("%d ",argmax (array, len));
        for (int i = 0; i < (len-1); i++){

            printf("%4.f",array[i]);
        }
    }
        
    free(array);
    return 0;
}