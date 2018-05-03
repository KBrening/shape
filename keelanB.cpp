//Project: Shape
//Name: Keelan Brening
//Last Modified: 3/22/18

#include "time.h"
#include "fonts.h"
#include <GL/glx.h>
#include <time.h>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <math.h>
#include <fstream>

//static float timeoffunction = 0;

typedef double Flt;
typedef Flt	Matrix[4][4];

class kb_set_time 
{
	public:
		TimeMilli t;
		int sec_count;
		int milli_count;
		int holder, finish;	
		bool stoptime, finish_time;
		int s_cooldown, c_cooldown, k_cooldown, star_cooldown;
		bool sc, cc, kc, starc;
	kb_set_time() {
	    	stoptime = false;
		sec_count = 0;
		milli_count = 0;
		holder = 0;
		finish = 0;
	       	finish_time = false;
		//cool downs for change
		s_cooldown = c_cooldown = k_cooldown = 2;
		star_cooldown = 60;
		sc = cc = kc = starc = false;
	}
	int kb_sec() {
	    	if (stoptime != true) {
		    	milli_count = t.inc_timer();
	
		    	if (milli_count == 59)
			{
		    		t.reset();
				milli_count = 0;
				sec_count = sec_count + 1;
			}

			return sec_count;
		}
		return sec_count;
	}
	int kb_milli() {
		if(stoptime != true) {
		    	if (milli_count == 59)
			{
				milli_count = 0;
			}
			return milli_count;
		}
		return milli_count;
	}
	void kb_reset() {
		sec_count = 0;
		milli_count = 0;
		stoptime = false;
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

void KB_reset_timer()
{
	distimer.kb_reset();
}

void KB_display_time(int x, int y)
{
	Rect r;
	unsigned int c = 0x00ffff44;
	r.bot = y - 20;
	r.left = x/2 - 20;
	r.center = 0;
	ggprint13(&r, 16, c, "Time : %i sec %i mill", display_sec(), display_milli());
}

void KB_GameOver(int x, int y)
{
	Rect r;
	unsigned int c = 0x00ffff44;
	r.bot = y - 300;
	r.left = x/2 - 10;
	r.center = 0;
	ggprint16(&r, 16, c, "GAME OVER");
	
	r.bot = y - 320;
	r.left = x/2;
	
	ggprint10(&r, 16, c, "Press ESC to exit");
	ggprint10(&r, 16, c, "Press R to restart");
	
}

void KB_Finish(int x, int y)
{
 	int sec, mil = 0;	
	int score[10][2] = {0};

	glClearColor(0.1, 0.1, 0.1, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
		glColor3f(0.2, 0.2, 0.2);
		glVertex2i(0, 220);
		glVertex2i(x, 220);
		glColor3f(0.4, 0.4, 0.4);
		glVertex2i(x, 0);
		glVertex2i(0, 0);
	glEnd();
	
	Rect r;
	unsigned int c = 0x00ffff44;
	r.bot = y/2 + 200;
	r.left = x/2 - 200;
	r.center = 0;
	ggprint16(&r, 32, c, "-------CONGRATS YOU FINISHED-------");
	
	r.bot = y/2 + 150;
	r.left = x/2 - 135;	
	ggprint13(&r, 16, c, "Your Time was %i sec %i milli", distimer.kb_sec(), distimer.kb_milli());
	
	r.bot = y/2 + 130;
	r.left = x/2 - 135;	
	ggprint10(&r, 16, c, "Press ESC to exit");
	ggprint10(&r, 16, c, "Press R to restart level");
	
	r.bot = r.bot - 20;
	ggprint13(&r, 32, c, "-------HIGH SCORE-------");

	/*ifstream fin;
	fin.open("highscore1.txt");
	if (fin.fail()) {
	    	r.bot = r.bot - 20;
		ggprint10(&r, 16, c, "Failed to open file");	
	}
	
	int i, j = 0;
	fin >> sec;
	while (!fin.eof()) {
		if (i < 11) {
	    		fin >> mil;
			score[i][j++] = sec;
			score[i++][j] = mil;
			fin >> sec;
			j=0;
		}
	}
	fin.close();*/

}

void KB_stoptimer()
{
	distimer.stoptime = true;
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
		case 6:					//6 is o
			glBegin(GL_TRIANGLES);	
				glVertex2i( 0,  0);
				//glVertex2i( tx, 0);
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
