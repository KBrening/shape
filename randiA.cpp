//Project: Shape
//Name: Randi Al.
//Last modified: 2/23/18

#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
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
