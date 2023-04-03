#include "project.h"
#include <GL/glut.h>  
#include <math.h>

void drawBranch(float r, float h) {
	glPushMatrix();
	glColor3f(0.439, 0.275, 0);

	float k = h - 2;
	glEnable(GL_CLIP_PLANE0);
	double planeEquation[] = { 0,-1,0,k };
	glClipPlane(GL_CLIP_PLANE0, planeEquation);

	glRotatef(-90, 1, 0, 0);
	glutSolidCone(r, h, 50, 50);
	glDisable(GL_CLIP_PLANE0);
	glPopMatrix();
}

void drawLeaves(float r, float h) {
	glPushMatrix();
	glScalef(0.4, 0.4, 0.4);
	glRotatef(55, 0, 0, 1);
	glPushMatrix();
	
	glPushMatrix();
	drawBranch(r, h);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 1, 0);
	glTranslatef(0, h-2, 0);
	glutSolidIcosahedron();
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}

void drawBush(float r, float h) {
	//drawBranch(0.3, 5);
	glPushMatrix();

	glPushMatrix();
	drawBranch(r,h);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(0, h - 2, 0);
	glRotatef(-55, 0, 0, 1);
	drawLeaves(r - 0.1, h - 0.5);
	glPopMatrix();

	glPushMatrix();
	for (float i = 0; i < 360; i += 60) {
		glPushMatrix();
		glTranslatef(0, h - 2, 0);
		glRotatef(i, 0, 1, 0);
		drawLeaves(r - 0.1, h - 0.5);
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix();
	for (float i = 0; i < 360; i += 90) {
		glPushMatrix();
		glTranslatef(0, h - 3, 0);
		glRotatef(i, 0, 1, 0);
		glScalef(1.35, 1.35, 1.35);
		drawLeaves(r - 0.1, h - 0.5);
		glPopMatrix();
	}
	glPopMatrix();

	glPopMatrix();
	
}