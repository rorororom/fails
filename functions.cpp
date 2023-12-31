#include "functions.h"
#include <stdio.h>
#include <math.h>

#define EPS 0.000001
enum root{
    NO_ROOTS,
    ONE_ROOTS,
    TWO_ROOTS,
    INFINITY_ROOTS
};


int comparison0(float a)
{
    if (abs(a - 0) < EPS) return 1;// если число равно 0, то выводим истину return 1;
    return 0; // иначе ложь
}


int solve_the_equation(float a, float b, float c, float *x1, float *x2)
{
    if (comparison0(a) == 0) // если а не 0
    {
        float discriminant = b * b - 4 * a * c; // считаем дискриминант;
        if (discriminant > 0) // если дискриминант больше 0
        {
            *x1 = (-b + sqrt(discriminant)) / (2 * a);
            *x2 = (-b - sqrt(discriminant)) / (2 * a);
            return TWO_ROOTS;
        }
        else if (comparison0(discriminant) == 1) // если дискриминант 0
        {
            *x1 = -b / (2 * a);
            return ONE_ROOTS;
        }
        return NO_ROOTS;
    }
    else return solve_linear_r_the_equation(b, c, x1); // случай, если а = 0
}


int solve_linear_r_the_equation(float b, float c, float *x1)
{
    if (comparison0(b) == 1 && comparison0(c) == 1) return INFINITY_ROOTS;
    else if(comparison0(b) == 1) return NO_ROOTS;
    else
    {
        *x1 = -c / b;
        return ONE_ROOTS;
    }
}
