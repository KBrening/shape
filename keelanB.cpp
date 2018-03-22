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

/*This is an example of how to time functions
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
}*/

//--------------------------------------------------------------------------------------------
// These are the color for the pixels in out game
//
void KB_pixel1(int j, int i, int tx, int ty,Flt dd, Flt offx, Flt offy, Flt ftsz)
{
	glColor3f(0.8, 0.8, 0.6);
	glPushMatrix();
	glTranslated((Flt)j*dd+offx, (Flt)i*ftsz+offy, 0);
	glBegin(GL_QUADS);
		glVertex2i( 0,  0);
		glVertex2i( 0, ty);
		glVertex2i(tx, ty);
		glVertex2i(tx,  0);
	glEnd();
	glPopMatrix();
}
void KB_pixel2(int j, int i, int tx, int ty, Flt dd, Flt offx, Flt offy, Flt ftsz) 
{
	glColor3f(0.9, 0.2, 0.2);
	glPushMatrix();
	glTranslated((Flt)j*dd+offx, (Flt)i*ftsz+offy, 0);
	glBegin(GL_QUADS);
		glVertex2i( 0,  0);
		glVertex2i( 0, ty);
		glVertex2i(tx, ty);
		glVertex2i(tx,  0);
	glEnd();
	glPopMatrix();
}
//This indicates the finish line for the level
void KB_pixel3(int j, int i, int tx, int ty, Flt dd, Flt offx, Flt offy, Flt ftsz) 
{
	glColor3f(0.9, 0.9, 0.9);
	glPushMatrix();
	glTranslated((Flt)j*dd+offx, (Flt)i*ftsz+offy, 0);
	glBegin(GL_QUADS);
		glVertex2i( 0,  0);
		glVertex2i( 0, ty);
		glVertex2i(tx, ty);
		glVertex2i(tx,  0);
	glEnd();
	glPopMatrix();
}
//---------------------------------------------------------------------------------------------
