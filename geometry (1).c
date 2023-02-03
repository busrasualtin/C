//
// Created by dindar.oz on 12/8/2020.
//

#include "geometry.h"

double areaOfCircle(double r)
{
    return PI * r *r ; // Magic numbers
}



double circumferenceOfCircle( double r)
{
    return 2 * PI * r;
}

double volumeOfSphere(double r)
{
    return (4/3) * PI *r*r*r;
}