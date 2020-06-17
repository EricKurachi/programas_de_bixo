#include<stdio.h>
#include<math.h>

typedef struct ponto{
    float x;
    float y;
    float z;

} Point;

Point getVector(Point x, Point y){
Point P;

P.x = (y.x)-(x.x);
P.y = (y.y)-(x.y);
P.z = (y.z)-(x.z);

return P;
}

float distancia(Point x, Point y){

float d;

d = sqrt(pow((y.x-x.x), 2) + pow((y.y-x.y), 2) + pow((y.z-x.z), 2));

return d;
}

int main(){
    float d;
    Point P;
    Point a;
    Point b;

    a.x = 1;
    a.y = 2;
    a.z = 3;

    b.x = 4;
    b.y = 5;
    b.z = 6;

    P = getVector(a, b);
    d = distancia(a, b);
    printf("vetor diferenca %f, %f, %f \n", P.x, P.y, P.z);
    printf("distancia %f", d);

    return 0;
}
