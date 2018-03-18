//Project: Shape
//Name: Keelan Brening
//Last Modified: 2/25/18

#include "time.h"
#include "fonts.h"
#include <GL/glx.h>
#include <time.h>
#include <stdio.h>

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
/*
//Class Made by Gordan Griesel
class Level {
public:
	unsigned char arr[16][80];
	int nrows, ncols;
	int tilesize[2];
	Flt ftsz[2];
	Flt tile_base;
	Level() {
		//Log("Level constructor\n");
		tilesize[0] = 32;
		tilesize[1] = 32;
		ftsz[0] = (Flt)tilesize[0];
		ftsz[1] = (Flt)tilesize[1];
		tile_base = 220.0;
		//read level
		//Will change to make it compatible for mutiple levels
		//EX: FILE *fpi = fopen("level"+r+".txt", "r");
		FILE *fpi = fopen("level1.txt", "r");
		if (fpi) {
			nrows = 0;
			char line[100];
			while (fgets(line, 100, fpi) != NULL) {
				removeCrLf(line);
				int slen = strlen(line);
				ncols = slen;
				//Log("line: %s\n", line);
				for (int j = 0; j<slen; j++) {
					arr[nrows][j] = line[j];
				}
				++nrows;
			}
			fclose(fpi);
			//printf("nrows of background data: %i\n", nrows);
		}
		for (int i = 0; i<nrows; i++) {
			for (int j = 0; j<ncols; j++) {
				printf("%c", arr[i][j]);
			}
			printf("\n");
		}
	}
	void removeCrLf(char *str) {
		//remove carriage return and linefeed from a Cstring
		char *p = str;
		while (*p) {
			if (*p == 10 || *p == 13) {
				*p = '\0';
				break;
			}
			++p;
		}
	}
} lev;
*/


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

/* This is test code for the level system for our game
//========================
//Render the tile system
//========================
void KB_Level_Display() {
	tx = lev.tilesize[0];
	int ty = lev.tilesize[1];
	Flt dd = lev.ftsz[0];
	Flt offy = lev.tile_base;
	int ncols_to_render = gl.xres / lev.tilesize[0] + 2;
	int col = (int)(gl.camera[0] / dd);
	col = col % lev.ncols;
	//Partial tile offset must be determined here.
	//The leftmost tile might be partially off-screen.
	//cdd: camera position in terms of tiles.
	Flt cdd = gl.camera[0] / dd;
	//flo: just the integer portion
	Flt flo = floor(cdd);
	//dec: just the decimal portion
	Flt dec = (cdd - flo);
	//offx: the offset to the left of the screen to start drawing tiles
	Flt offx = -dec * dd;
	//Log("gl.camera[0]: %lf   offx: %lf\n",gl.camera[0],offx);
	for (int j=0; j<ncols_to_render; j++) {
		int row = lev.nrows-1;
		for (int i=0; i<lev.nrows; i++) {
			if (lev.arr[row][col] == 'w') {
				glColor3f(0.8, 0.8, 0.6);
				glPushMatrix();
				//put tile in its place
				glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
				glBegin(GL_QUADS);
					glVertex2i( 0,  0);
					glVertex2i( 0, ty);
					glVertex2i(tx, ty);
					glVertex2i(tx,  0);
				glEnd();
				glPopMatrix();
			}
			if (lev.arr[row][col] == 'b') {
				glColor3f(0.9, 0.2, 0.2);
				glPushMatrix();
				glTranslated((Flt)j*dd+offx, (Flt)i*lev.ftsz[1]+offy, 0);
				glBegin(GL_QUADS);
					glVertex2i( 0,  0);
					glVertex2i( 0, ty);
					glVertex2i(tx, ty);
					glVertex2i(tx,  0);
				glEnd();
				glPopMatrix();
			}
			--row;
		}
	col = (col+1) % lev.ncols;
	}
	glColor3f(1.0, 1.0, 0.1);
	glPushMatrix();
}
*/

/*Puts player Into place in game
void startingposition()
{
	glTranslated(gl.ball_pos[0], lev.tile_base+gl.ball_pos[1], 0);
	glBegin(GL_QUADS);
		glVertex2i(-10, 0);
		glVertex2i(-10, 20);
		glVertex2i( 10, 20);
		glVertex2i( 10, 0);
	glEnd();
	glPopMatrix();
}
*/