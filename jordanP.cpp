//Project: Shape
//Name: Jordan Parks
//Last modified: 3/9/18

#include <iostream>
#include <cstdlib>
#include "fonts.h"
#include "time.h"
#include "stdio.h"
#include <ctime>

using namespace std;


/*{
  Rect r;
  r.bot = 120;
  r.left = 10;
  r.center = 0;
  ggprint8b(&r, 16, 0x00ffff44, "Jordan's Time Function");

  }*/


double jpTest1() {


    //Factorial using loop
    static double t = 0.0;
    int n = 0.0;
    clock_t start;
    start = clock();

    for(int i = 1; i <= n; i++)
        t *= i;

    t += (clock() - start ) / (double) CLOCKS_PER_SEC;

    return t;

}

double jpTest2() {
    //Factorial using while loop
    static double t = 0.0;
    int n = 0.0;
    int j = 1;
    clock_t start;
    start = clock();

    while (j <= n)
        t *= j;
        
    t += (clock() - start ) / (double) CLOCKS_PER_SEC;
    return t;

}


/*jp_Menu(int x_res, int y_res)
  {

  }*/


