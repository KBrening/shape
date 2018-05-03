//Project: Shape
//Name: Jordan Parks
//1st update: 3/9/18
//2nd update: 5/3/18

#include <iostream>
#include <cstdlib>
#include "fonts.h"
#include "time.h"
#include "stdio.h"
#include <ctime>
#include "GL/glx.h"
#include <cmath>


using namespace std;


void jpSquareColor()
{

glColor3f(0.1, 0.4, 0.8); 

}

void jpKiteColor()
{
glColor3f(0.2, 0.8, 0.6); 

}

void jpStarColor()
{

glColor3f(1.0, 0.11, 0.68); 
}

double jpTest1()
{
    //Factorial using for loop
    static double t = 0.0;
    double n = 2000;
    int total = 1;
    clock_t start;
    start = clock();

    for(int i = 1; i <= n; i++)
        total *= i;
    

    t += (clock() - start ) / (double) CLOCKS_PER_SEC;
    return t;
}

double jpTest2()
{
    //Factorial using while loop
    static double t = 0.0;
    double n = 2000;
    int j = 1;
    int total = 1;
    clock_t start;
    start = clock();

    while (j <= n) {
        total *= j;
        j++;
    }
        
    t += (clock() - start ) / (double) CLOCKS_PER_SEC;
    return t;
}

