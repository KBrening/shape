//Project: Shape
//Name: Randi Al.
//Last modified: 3/9/18

#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <GL/glx.h>

#define PI 3.14159265358979323846264338327950

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
void printToConsole() {
	printf("Test\n");fflush(stdout);
}
struct Shape {
	float vertices[32][2];
	int n;
	Shape() {
		n = 32;
		float angle = 0.0f;
		float increment = (2.0 * PI)/ (float)n;
		for (int i = 0; i < n; i++) {
			vertices[i][0] = sin(angle);
			vertices[i][1] = cos(angle);
			angle += increment;
		}
	}
	void updatePosition() { }

	void changeVelocity() { }

	void Square(int sideLength) {
		glBegin(GL_QUADS);
			glVertex2i(-sideLength, 0);
			glVertex2i(-sideLength, 2*sideLength);
			glVertex2i( sideLength, 2*sideLength);
			glVertex2i( sideLength, 0);
		glEnd();
	}

	void Circle(float radius) {
		glBegin(GL_TRIANGLE_FAN);
		for (int i = 0; i < n; i++) {
			glVertex2f(vertices[i][0]*radius, vertices[i][1]*radius);
		}
		glEnd();
	}

	void Kite(int baseModifier) {
		glBegin(GL_QUADS);
			glVertex2i(-baseModifier, 2*baseModifier);
			glVertex2i(0, 3*baseModifier);
			glVertex2i(baseModifier, 2*baseModifier);
			glVertex2i(0,0);
		glEnd();

	}

	void Star(int scale) {
		glBegin(GL_TRIANGLE_FAN);
			glVertex2i(0, 4*scale);
			glVertex2i(-7*scale, 0);
			glVertex2i(-4*scale, 6*scale);
			glVertex2i(-10*scale, 10*scale);
			glVertex2i(-2*scale, 10*scale);
			glVertex2i(0, 16*scale);
			glVertex2i(2*scale, 10*scale);
			glVertex2i(10*scale, 10*scale);
			glVertex2i(4*scale, 6*scale);
			glVertex2i(7*scale, 0);
		glEnd();
	}

} shape;

struct Collision {
	
};
void drawSquare(int sideLength) 
{
	shape.Square(sideLength);
}
void drawCircle(float radius) 
{
	shape.Circle(radius);
}
void drawKite(int baseModifier) 
{
	shape.Kite(baseModifier);
}
void drawStar(int scale) 
{
	shape.Star(scale);
}
