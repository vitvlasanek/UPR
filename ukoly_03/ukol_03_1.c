#include<stdio.h>

void pocty(float *a, float *b, float *c, float *d){
    (*c) = (*a) + (*b);
    *d = *a - *b;
}


void main(){
    float num1 = 5;
    float num2 = 8;
    float sum;
    float diff;
    pocty(&num1, &num2, &sum, &diff);
    printf("soucet je: %2.2f\n", sum);
    printf("rozdil je: %2.2f\n", diff);
}