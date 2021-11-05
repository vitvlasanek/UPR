#include <stdio.h>
#include <math.h>

struct Point2
{
    float x;
    float y;
};

struct Circle
{
    struct Point2 * center;
    float radius;
};


float circle_circumference(const struct Circle * self){
    return 2 * self->radius * M_PI;
}

int main(){
    struct Circle self;
    scanf("%f",&self.center->x);
    scanf("%f",&self.center->y);
    scanf("%f",&self.radius);  
    printf("%.2f",circle_circumference(&self));
    printf("\n%f %f",self.center->x,self.center->y);
    return 0;
}