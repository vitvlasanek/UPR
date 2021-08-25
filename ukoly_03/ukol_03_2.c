#include<stdio.h>
#include<math.h>

int quadr_roots(float a, float b, float c, float *x1, float *x2){
    float d;
    d = pow(b,2)-(4*a*c);
    if (d > 0){
        *x1 = (-b + sqrt(d))/(2*a);
        *x2 = (-b - sqrt(d))/(2*a);
        return 2;
    }
    else if (d == 0){
        *x1 = *x2 = (-b)/(2*a);
        return 1;
    }
    else{
        return 0;
    }
}

void main(){
    float prvni_x = 0;
    float druhe_x = 0;
    float a = -5;
    float b = 6;
    float c = 3;
    quadr_roots(a, b, c, &prvni_x, &druhe_x);
    printf("x1 = %f\n", prvni_x);
    printf("x2 = %f\n", druhe_x);
    printf("%d-nasobny koren\n", quadr_roots(a, b, c, &prvni_x, &druhe_x));
}
