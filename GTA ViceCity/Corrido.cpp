#include "project.h"
#include <GL/glut.h>  
#include <math.h>

const double PI = 3.141592654;

void drawCorridoSide() {
	glPushMatrix();
	glTranslatef(0, 0.5, 0);
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.529, 0.329, 0); // color middle
	glVertex3f(0, 0, 0.5);
	glVertex3f(0, 0, -0.5);

	glColor3f(0.11, 0.067, 0); // color end
	glVertex3f(1.3, 0, -0.5);
	glVertex3f(1.3, 0, 0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.42, 0.263, 0);
	glVertex3f(1.5, 0, 0.5);
	glVertex3f(1.5, 0, -0.5);
	glVertex3f(1.3, 0, -0.5);
	glVertex3f(1.3, 0, 0.5);
	glEnd();
	glPopMatrix();

	glPopMatrix();
}

void drawCorridoBottom() {
	glPushMatrix();

	glBegin(GL_POLYGON);
	glColor3f(0.42, 0.263, 0);
	glVertex3f(-1.5, 0.5, 0.5);
	glVertex3f(1.5, 0.5, 0.5);
	glVertex3f(1.5, -0.5, 0.5);
	glVertex3f(-1.5, -0.5, 0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.302, 0.188, 0);
	glVertex3f(-1.5, 0.5, -0.5);
	glVertex3f(-1.5, 0.5, 0.5);
	glVertex3f(-1.5, -0.5, 0.5);
	glVertex3f(-1.5, -0.5, -0.5);
	glEnd();
	
	glPopMatrix();
}

void drawCorridoLine() {
	glPushMatrix();
	
	glPushMatrix();
	drawCorridoSide();
	glPopMatrix();

	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	drawCorridoSide();
	glPopMatrix();

	glPushMatrix();
	drawCorridoBottom();
	glPopMatrix();

	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	drawCorridoBottom();
	glPopMatrix();

	glPopMatrix();
}



void drawCorrido(int length) {
	//drawCorridoLine();
	glPushMatrix();

	if (length % 2 == 1) {
		int k = (length - 1) / 2;
		for (float i = -(k * 1); i <= (k * 1); i += 1) {
			glPushMatrix();
			glTranslatef(0, 0, i);
			drawCorridoLine();
			glPopMatrix();
		}
	}
	else {
		int k = (length) / 2;
		int j = 1;
		int l;
		for (float i = -(k * 1); i < (k * 1); i += 1) {
			glPushMatrix();
			glTranslatef(0, 0, i + (j * 0.5));
			drawCorridoLine();
			glPopMatrix();

		}
	}
	glPopMatrix();
}