#include<stdio.h>

int suma(int cislo){
    int sum = 0;
    while (cislo>0){
        sum = cislo + sum;
        cislo -= 1;
    }
    return sum;
}

void main()
{
    int x;
    printf("zadej cislo: ", x);
    scanf("%d", &x);
    printf("suma je: %d\n", suma(x));
}

