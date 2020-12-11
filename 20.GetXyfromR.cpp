#include <math.h>
#include <iostream>
 #include <stdlib.h>

typedef double custem_t;
#define PI 3.14159265359

custem_t degreetoRad(custem_t deg)
{
    return deg*(PI/180);
}

int main(int argc, char** argv)
{
    std::cout<<"Start calculate x,y position from radius 30 and degree"<<std::endl;
    double x = 0,y = 0,distance = 30;
    double degree =strtod(argv[1],'\n');
    x = 30*cos(degreetoRad(degree));
    y = 30*cos(degreetoRad(degree));
}