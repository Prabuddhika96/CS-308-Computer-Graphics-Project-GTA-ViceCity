#include "project.h"
#include <GL/glut.h>  
#include <math.h>

const double PI = 3.141592654;

void drawStep() {
	glPushMatrix();
	//glScalef(1, 0.95, 1);
	drawCemntRow(0.102, 0.059, 0, 0.541, 0.318, 0);
	glPopMatrix();
}

void drawStepSide() {
	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex3f(0, 0.5, 0);
	glVertex3f(0, -0.5, 0);
	glVertex3f(0, -0.5, -1);
	glVertex3f(0, 0.5, -1);
	glEnd();
	glPopMatrix();
}

void drawStep_Z_line(int steps) {
	glPushMatrix();
	glTranslatef(0, 0, 0.5);
	glPushMatrix();

	glPushMatrix();
	//glTranslatef(0, -0.05, 0);
	glPushMatrix();
	for (float i = -1+0.05 ; i <= 1+0.05 ; i += 0.1) {
		glPushMatrix();
		glTranslatef(i, 0, 0);
		drawStep();
		glPopMatrix();
	}
	glPopMatrix();
	glPopMatrix();

	// top od ste
	glPushMatrix();
	glColor3f(0.149, 0.09, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-1, 0.4, -1);
	glVertex3f(-1, -0.5, -1);
	glVertex3f(1, -0.5, -1);
	glVertex3f(1, 0.4, -1);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1, 0, 0);
	drawStepSide();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, 0, 0);
	drawStepSide();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.22, 0.129, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-1, 0.5, 0);
	glVertex3f(1, 0.5, 0);
	glVertex3f(1, 0.5, -1);
	glVertex3f(-1, 0.5, -1);
	glEnd();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
}

void drawSteps(int steps) {
	glPushMatrix();
	glScalef(1, 0.5, 1);
	glRotatef(180, 0, 1, 0);
	glPushMatrix();
	glEnable(GL_CLIP_PLANE0);

	double planeEquation[] = { 0,0,-1,steps/5 };
	glClipPlane(GL_CLIP_PLANE0, planeEquation);

	glPushMatrix();
	if (steps % 2 == 1) {
		int k = (steps - 1) / 2;
		int j = steps;
		float n = 0;
		for (float i = -(k * 1); i <= (k * 1); i += 1) {
			glPushMatrix();
			glTranslatef(0, i, n/4);
			glScalef(1, 1, -j);
			drawStep_Z_line(steps);
			glPopMatrix();
			j--;
			n++;
		}
	}
	else {
		int k = (steps) / 2;
		int j = steps;
		float n = 0;
		for (float i = -(k * 1); i < (k * 1); i += 1) {
			glPushMatrix();
			glTranslatef(0, i, n / 4);
			glScalef(1, 1, -j);
			drawStep_Z_line(steps);
			glPopMatrix();
			j--;
			n++;
		}
	}
	glPopMatrix();
	glDisable(GL_CLIP_PLANE0);

	glPopMatrix();
	glPopMatrix();	
}