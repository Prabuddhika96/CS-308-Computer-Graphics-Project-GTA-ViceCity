#include "project.h"
#include <GL/glut.h>  
#include <math.h>

void drawNetHalf() {
	glPushMatrix();
	glColor3f(0, 0, 0);
	glLineWidth(1.5);
	for (float i = -0.5; i <= 0.5; i += 0.25) {
		glPushMatrix();
		glBegin(GL_LINES);
		glVertex3f(i, 0.5, 0);
		glVertex3f(-0.5, -i, 0);
		glEnd();
		glPopMatrix();
	}
	glLineWidth(1);
	glPopMatrix();
}

void drawNet() {
	glPushMatrix();

	glPushMatrix();
	drawNetHalf();
	glPopMatrix();

	glPushMatrix();
	glRotatef(180, 0, 0, 1);
	drawNetHalf();
	glPopMatrix();

	glPopMatrix();
}

void drawLine_Y(float y1, float y2) {
	glPushMatrix();
	glLineWidth(1.5);
	glBegin(GL_LINES);
	glVertex3f(0, y1, 0);
	glVertex3f(0, y2, 0);
	glEnd();
	glLineWidth(1);
	glPopMatrix();
}

void drawLine_X(float x1, float x2) {
	glPushMatrix();
	glLineWidth(1.5);
	glBegin(GL_LINES);
	glVertex3f(x1, 0, 0);
	glVertex3f(x2, 0, 0);
	glEnd();
	glLineWidth(1);
	glPopMatrix();
}

void drawFence() {
	glPushMatrix();

	glPushMatrix();
	drawNet();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 0, 1);
	drawNet();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, 0, 0);
	drawLine_Y(0.7, -0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 0, 0);
	drawLine_Y(0.7, -0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -0.5, 0);
	drawLine_X(-0.5, 0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.5, 0);
	drawLine_X(-0.5, 0.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.6, 0);
	drawLine_X(-0.5, 0.5);
	glPopMatrix();

	glPopMatrix();
}

void drawFenceRow(int number) {
	glPushMatrix();

	if (number % 2 == 1) {
		int k = (number - 1) / 2;
		for (float i = -(k * 1); i <= (k * 1); i += 1) {
			glPushMatrix();
			glTranslatef(i, 0, 0);
			drawFence();
			glPopMatrix();
		}
	}
	else {
		int k = (number) / 2;
		int j = 1;
		int l;
		for (float i = -(k * 1); i < (k * 1); i += 1) {
			glPushMatrix();
			glTranslatef(i + (j * 0.5), 0, 0);
			drawFence();
			glPopMatrix();

		}
	}
	glPopMatrix();
}