#include "vla0095_circle_2.h"

Circle * circle_new(){
    Circle * arr = NULL;
    arr = (Circle *) malloc (sizeof(Circle));
    arr->center = (Center *) malloc (sizeof(Center));
}

void circle_free(Circle ** self){
    free ((*self)->center);
    (*self)->center = NULL;
    free(*self);
    *self = NULL;
}

void circle_set(Circle * self, float x, float y, float rad){
    self->radius = rad;
    self->center->x = x;
    self->center->y = y;
}

bool circle_contains_circle(const Circle * self, const Circle * other){
    float x_dist = (self->center->x)-(other->center->x);
    float y_dist = (self->center->y)-(other->center->y);
    float dist = sqrt((pow(x_dist,2))+(pow(y_dist,2)));
    float radius_diff = abs((self->radius)-(other->radius));
    if (dist < radius_diff){
        return false;
    }
    else
    {
        return true;
    }
       
}
