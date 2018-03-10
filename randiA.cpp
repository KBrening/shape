//Project: Shape
//Name: Randi Al.
//Last modified: 3/9/18

#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double firstFunc() {
    static double acc = 0.0;
    struct timespec first, second;
    int total = 0;
    clock_gettime(CLOCK_REALTIME, &first);
    for (int i = 0; i < 5000000; i++)
	total++;
    clock_gettime(CLOCK_REALTIME, &second);
    acc += (double)(second.tv_sec - first.tv_sec) + 
	  (double)(second.tv_nsec - first.tv_nsec) / 1e9;
    return acc;
}

double secondFunc() {
    static double acc = 0.0;
    struct timespec first, second;
    int n = 5000000;
    clock_gettime(CLOCK_REALTIME, &first);
    n = 0.5 * n * (n + 1);
    clock_gettime(CLOCK_REALTIME, &second);
    acc += (double)(second.tv_sec - first.tv_sec) + 
	  (double)(second.tv_nsec - first.tv_nsec) / 1e9;
    return acc;
}
	 
struct Shape {
	float vel[2];
	float pos[2];
	
	Shape(int posX, int posY) {
		pos[0] = posX;
		pos[1] = posY;
		vel[0] = 0.0f;
		vel[1] = 0.0f;
	}

	void updatePosition() {
	    	pos[0] += pos[0] + vel[0];
	    	pos[1] += pos[1] + vel[1];
	}

	void changeVelocity(int x, int y) {
		vel[0] = x;
		vel[1] = y;	
	}

};

struct Collision {
	
};

void printToConsole() {
	printf("Test\n");fflush(stdout);
}
