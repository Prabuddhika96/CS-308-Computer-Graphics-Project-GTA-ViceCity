#include "project.h"
#include <GL/glut.h>  
#include <math.h>

const double PI = 3.141592654;

void drawHalfSphere(float r) {
	glPushMatrix();
	glColor3f(1, 1, 1);
	glEnable(GL_CLIP_PLANE0);

	double planeEquation[] = { 0,1,0,0 };
	glClipPlane(GL_CLIP_PLANE0, planeEquation);
	glutSolidSphere(r, 100, 100);

	glDisable(GL_CLIP_PLANE0);

	glPopMatrix();
}

void drawHalfCone(float r, float h) {
	glPushMatrix();
	glColor3f(1, 1, 1);
	glEnable(GL_CLIP_PLANE0);

	double planeEquation[] = { 0,1,0,0 };
	glClipPlane(GL_CLIP_PLANE0, planeEquation);
	glTranslatef(0, h / 2, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidCone(r, h, 100, 100);

	glDisable(GL_CLIP_PLANE0);

	glPopMatrix();
}

void drawGalloonBody(float r, float h) {
	glPushMatrix();

	// cylinder
	glPushMatrix();
	glColor3f(1, 1, 1);
	drawCylinder(r, h);
	glPopMatrix();

	// top half sphere
	glPushMatrix();
	glTranslatef(0, h / 2, 0);
	drawHalfSphere(r);
	glPopMatrix();

	// rings
	glPushMatrix();
	glColor3f(0.361, 0.361, 0.361);
	glTranslatef(0, h / 2, 0);
	drawCylinder(r + 0.05, 0.15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.361, 0.361, 0.361);
	glTranslatef(0, -h / 2, 0);
	drawCylinder(r + 0.05, 0.15);
	glPopMatrix();

	// bottom cone
	glPushMatrix();
	glColor3f(1,1,1);
	glTranslatef(0, -h, 0);
	drawHalfCone(r,h);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 0.71, 0);
	glTranslatef(0, -9*h/8, 0);
	drawCylinder(r, h/4);
	glPopMatrix();

	glPopMatrix();
}

void drawOilGaloon(float r, float h) {
	glPushMatrix();
	for (int i = -1; i <= 1; i += 2) {
		for (int j = -1; j <= 1; j += 2) {
			glPushMatrix();
			glTranslatef(i, 0, j);
			drawGalloonBody(r, h);
			glPopMatrix();
		}
	}
	glPopMatrix();
}