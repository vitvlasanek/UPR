#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct Point2 
{
    float x;
    float y;
}
Center;

typedef struct Circle_  {
    Center * center;
    float radius;
}
Circle;

Circle * circle_new ();

void circle_free(Circle ** self);

void circle_set (Circle * self, const float x, const float y, const float rad);

bool circle_contains_circle(const Circle * self, const Circle * other);
