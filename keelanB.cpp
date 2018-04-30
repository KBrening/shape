//Project: Shape
//Name: Keelan Brening
//Last Modified: 3/22/18

#include "time.h"
#include "fonts.h"
#include <GL/glx.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//static float timeoffunction = 0;

typedef double Flt;
typedef Flt	Matrix[4][4];

class kb_set_time 
{
	public:
		TimeMilli t;
		int sec_count;
		int milli_count;
		int holder;	
	kb_set_time() {
		sec_count = 0;
		milli_count = 0;
		holder = 0;
	}
	int kb_sec() {
	    	milli_count = t.inc_timer();

	    	if (milli_count == 59)
		{
	    		t.reset();
			milli_count = 0;
			sec_count = sec_count + 1;
		}

		return sec_count;
	}
	int kb_milli() {
		if (milli_count == 59)
		{
			milli_count = 0;
		}
		return milli_count;
	}
}distimer;

int display_sec ()
{
	return distimer.kb_sec();
}

int display_milli()
{
	return distimer.kb_milli();
}

void KB_display_time(int y)
{
	Rect r;
	unsigned int c = 0x00ffff44;
	r.bot = y - 20;
	r.left = 400;
	r.center = 0;
	ggprint8b(&r, 16, c, "Time : %i %i", display_sec(), display_milli());
}

void KB_pixel (int num, int j, int i, int tx, int ty, Flt dd, Flt offx, Flt offy, Flt ftsz) 
{
	switch (num) {
	    case 1:
	    	glColor3f(0.9, 0.8, 0.8);	//bottom layer
	    	break;
	    case 2:
	    	glColor3f(0.9, 0.2, 0.2);	//normal
	    	break;
	    case 3:
	    	glColor3f(0.9, 0.9, 0.9);	//finish
		break;
	    case 4:
	    case 5:
	    case 6:
	    case 7:
	    case 8:
	    case 9:
	    	glColor3f(0.9, 0.2, 0.2);
		break;
	}
	
	glPushMatrix();
	glTranslated((Flt)j*dd+offx, (Flt)i*ftsz+offy, 0);
	
	switch (num) {
		case 1: 				//1-3 are squares
		case 2:
		case 3:
			glBegin(GL_QUADS);	
		    		glVertex2i( 0,  0);
				glVertex2i( 0, ty);
				glVertex2i(tx, ty);
				glVertex2i(tx,  0);
			break;
		case 4:					//4 is the start curve to flat
			glBegin(GL_QUADS);	
				glVertex2i( 0,  0);
				glVertex2i( 0, ty);
				glVertex2i(tx, ty/3);
				glVertex2i(tx,  0);
			break;
		case 5:					//5 is end curve to flat
			glBegin(GL_QUADS);	
				glVertex2i( 0,  0);
				glVertex2i( tx/4, 0);
				glVertex2i( tx, 0);
				glVertex2i( 0,  ty/3);
			break;
		case 6:					//6 is 90 degree slant down
			glBegin(GL_QUADS);	
				glVertex2i( 0,  0);
				glVertex2i( tx, 0);
				glVertex2i( tx, 0);
				glVertex2i( 0,  ty);
			break;
		case 7:					//7 is start curve to up
			glBegin(GL_TRIANGLES);	
				glVertex2i( tx,  0);
				glVertex2i( tx, ty/3);
				glVertex2i( 0, 0 );
			break;
		case 8:					//8 is end curve to up
			glBegin(GL_QUADS);	
				glVertex2i( tx,  0);
				glVertex2i( tx, ty);
				glVertex2i( 0, ty/3);
				glVertex2i( 0, 0);
			break;
		case 9:					//9 is 90 degree up
			glBegin(GL_TRIANGLES);	
				glVertex2i( tx,  0);
				glVertex2i( tx, ty);
				glVertex2i( 0, 0);
			break;
	}
	glEnd();
	glPopMatrix();
}

