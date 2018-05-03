//Project: shape
////Name: Miguel N.
////Last modified: 2/23/18

#include <GL/glx.h>
#include "fonts.h"
#include <ctime>
#include "time.h"

// Lab 7 stuff

double mn_loop1() {
    static double time = 0.0;
    int sum1 = 0;
    clock_t start;
    start = clock();
    for (int i = 0; i < 100; i++) {
	for (int j = 0; j < 100; j++) {
	    sum1 = sum1 + 1; 
	}
    }
    time += (clock() - start) / (double)CLOCKS_PER_SEC;
    return time; 
}
double mn_loop2() {
    static double time2 = 0.0;
    int sum2 = 0;
    clock_t start2;
    start2 = clock();
    int a, b = 0;
    while (a < 101) {
	a++;
	while (b < 101) {
	    b++;
	    sum2 = sum2 + 1;
	}
    }
    time2 += (clock() - start2) / (double) CLOCKS_PER_SEC;   
    return time2;
}
