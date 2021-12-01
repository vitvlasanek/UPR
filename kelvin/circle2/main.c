#include "vla0095_circle_2.h"
#include <string.h>

int main (){
    Circle * kruh[2];

    for(int i; i < 2; i++){

        kruh[i] = circle_new();
        float circle_parameters[3];

        for(int i; i < 3; i++){
            scanf("%f",&circle_parameters[i]);
        }

        circle_set(kruh[i], circle_parameters[0], circle_parameters[1], circle_parameters[2]);
    }
    if(circle_contains_circle(kruh[0], kruh[1]) == 1){
        printf("True");
    }
    else
    {
        printf("False");
    }

    circle_free(&kruh[1]);    
    circle_free(&kruh[2]);    

    return (0);


}
