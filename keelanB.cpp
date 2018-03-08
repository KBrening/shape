//Project: Shape
//Name: Keelan Brening
//Last Modified: 2/25/18

#include "time.h"
#include "fonts.h"
#include <GL/glx.h>
#include <time.h>

//static float timeoffunction = 0;

class kb_set_time 
{
	public:
		Timer t;
		int sec_count;
		int min_count;
		int holder;	
	kb_set_time() {
		sec_count = 0;
		min_count = 0;
		holder = 0;
	}
	int kb_sec() {
		if (sec_count == 59) {
			sec_count = 0;
			min_count += 1;
		}
		else
			sec_count = t.inc_timer();

		return sec_count;
	}
	int kb_min() {
		return min_count;
	}
}distimer;

int display_sec()
{
	return distimer.kb_sec();	
}

double KBdrawBox ()
{
	static clock_t start, end;
	static float total = 0;
	start = clock();
    	glColor3ub(255,0,0);
	glPushMatrix();
	glTranslatef(500.0,500.0,0.0);
	glBegin(GL_QUADS);
		glVertex2i( 0, 0);
		glVertex2i( 0, 100);
		glVertex2i( 100, 100);
		glVertex2i( 100, 0);
	glEnd();
	glPopMatrix();
	end=clock();
	float sec = ((float)end - (float)start)/CLOCKS_PER_SEC;
	total +=sec;
	return total;
}
