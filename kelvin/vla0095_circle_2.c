#include <stdio.h>
#include <math.h>

struct Point2
{
    float x;
    float y;
};

typedef struct Circle_
{
    struct Point2 * center;
    float radius;
}Circle;


Circle * array_cerate_new (const int i) {
    Circle * arr = NULL;
    arr = (Circle *)malloc( sizeof(Circle) );

    arr->center[i] = (float *)malloc( 2 * sizeof( float ) );
    arr->radius[i] = 0;

    return arr;
}
    
}

int main(){
    Circle kruh[1];
    struct Point2 coordinates[1];
    for (int i = 0; i < 2; i++)
    {
        Array * a = array_create_new (i);
        kruh[i].center = &coordinates[i];
        scanf("%f",&kruh[i].center->x);
        scanf("%f",&kruh[i].center->y);
        scanf("%f",&kruh[i].radius);   
    }
    

    //printf("%.2f",circle_circumference(&self));
    for (int i = 0; i < 2; i++)
    {
        printf("\n%f %f",kruh[i].center->x,kruh[i].center->y);

    }
    
    return 0;
}