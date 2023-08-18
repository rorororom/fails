#include <stdio.h>
#include <math.h>
#include "functions.h"


#define EPS 0.000001
enum root{
    NO_ROOTS,
    ONE_ROOTS,
    TWO_ROOTS,
    INFINITY_ROOTS
};


int main()
{
    float a = 0, b = 0, c = 0, x1 = 0, x2 = 0;
    if ((scanf("%f%f%f", &a, &b, &c)) != 3) // проверка на правильность ввода
        printf("Неверное введенное значение");
    else // если корректный ввод, то переходит к решению уравнения
    {
        int number_of_roots = solve_the_equation(a,b,c, &x1, &x2); // запускаем функцию, считающую кол-во корней
        if (number_of_roots == TWO_ROOTS) printf("x1 = %f, x2 = %f\n", x1, x2); //если 2 корня
        else if (number_of_roots == ONE_ROOTS) printf("x1 = %f\n", x1); // если 1 корень
        else if (number_of_roots == NO_ROOTS) printf("корней нет"); // если 0 корней
        else printf("бесконечное кол-во корней");
    }
}
