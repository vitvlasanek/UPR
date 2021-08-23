//Vypište pomocí cyklu for druhé mocniny čísel od 0 po číslo x, které zadá uživatel

#include<stdio.h>
#include<math.h>

void main(){
    int x;
    printf("zadej cislo: ");
    scanf("%d",&x);
    printf("\n");
    int x2 = 0;
    for (int i = 0; i <= x; ++i){
        x2 = pow(i, 2);
        printf("%d\n",x2);
    }
}