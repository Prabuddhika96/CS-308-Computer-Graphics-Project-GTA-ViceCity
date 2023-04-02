#include "project.h"
#include <GL/glut.h>  
#include <math.h>

void drawWall(float R, float G, float B) {
	glPushMatrix();
	glColor3f(R, G, B);
	glTranslatef(0, 0, -2);
	glScalef(4, 3, 0.1);
	glutSolidCube(1);
	glPopMatrix();
}

void drawHouse(float R, float G, float B) {
	glPushMatrix();

	// back wall
	glPushMatrix();
	drawWall(R, G, B);
	glPopMatrix();

	// right wall
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	drawWall(R, G, B);
	glPopMatrix();

	// left wall
	glPushMatrix();
	glRotatef(-90, 0, 1, 0);
	drawWall(R, G, B);
	glPopMatrix();

	// front wall - left
	glPushMatrix();
	glTranslatef(-1.6, 0, 0);
	glScalef(0.2, 1, 1);
	glRotatef(-180, 0, 1, 0);
	drawWall(R, G, B);
	glPopMatrix();

	// front wall - right
	glPushMatrix();
	glTranslatef(1.6, 0, 0);
	glScalef(0.2, 1, 1);
	glRotatef(-180, 0, 1, 0);
	drawWall(R, G, B);
	glPopMatrix();

	// front wall - middle
	glPushMatrix();
	glTranslatef(0, 0.9, 0);
	glScalef(0.6, 0.4, 1);
	glRotatef(-180, 0, 1, 0);
	drawWall(R, G, B);
	glPopMatrix();

	glPopMatrix();
}

void drawRoofFront() {
	
}

void drawRoof(float R, float G, float B) {	
	glPushMatrix();
	glColor3f(R, G, B);

	// roof front 
	glPushMatrix();
	glTranslatef(0, 0, 2.5);

	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex3f(-2.5, 0, 0);
	glVertex3f(2.5, 0, 0);
	glVertex3f(0, 2, 0);
	glEnd();
	glPopMatrix();
	glPopMatrix();

	// roof back
	glPushMatrix();
	glTranslatef(0, 0, -2.5);

	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex3f(-2.5, 0, 0);
	glVertex3f(2.5, 0, 0);
	glVertex3f(0, 2, 0);
	glEnd();
	glPopMatrix();
	glPopMatrix();

	// roof right
	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex3f(0, 2, 2.5);
	glVertex3f(2.5, 0, 2.5);
	glVertex3f(2.5, 0, -2.5);
	glVertex3f(0, 2, -2.5);
	glEnd();
	glPopMatrix();

	// roof left
	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex3f(0, 2, 2.5);
	glVertex3f(-2.5, 0, 2.5);
	glVertex3f(-2.5, 0, -2.5);
	glVertex3f(0, 2, -2.5);
	glEnd();
	glPopMatrix();

	// cealing
	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex3f(-2.5, 0, 2.5);
	glVertex3f(2.5, 0, 2.5);
	glVertex3f(2.5, -0, 2.5);
	glVertex3f(-2.5, -0, 2.5);
	glEnd();
	glPopMatrix();

	glPopMatrix();
}

void woodRaw() {
	float n = 2;
	glPushMatrix();
	
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.42, 0.251, 0.129);
	glVertex3f(-n, 0, n / 4);

	glColor3f(0.11, 0.047, 0);
	glVertex3f(n, 0, n / 4);

	glColor3f(0.42, 0.251, 0.129);
	glVertex3f(n, 0, -n / 4);

	glColor3f(0.11, 0.047, 0);
	glVertex3f(-n, 0, -n / 4);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glLineWidth(1.5);
	glBegin(GL_LINES);
	glVertex3f(-n, 0, n / 4);
	glVertex3f(n, 0, n / 4);

	glVertex3f(-n, 0, -n / 4);
	glVertex3f(n, 0, -n / 4);

	glVertex3f(n, 0, -n / 4);
	glVertex3f(n, 0, n / 4);

	glVertex3f(-n, 0, -n / 4);
	glVertex3f(-n, 0, n / 4);

	glEnd();
	glLineWidth(1);
	glPopMatrix();

	glPopMatrix();
}

void drawBoxBorder() {
	glPushMatrix();
	glColor3f(0.922, 0.565, 0.314);
	glScalef(4, 0.1, 0.2);
	glutSolidCube(1);
	glPopMatrix();
}

void drawBoxSide() {
	float n = 2;
	glPushMatrix();
	
	glPushMatrix();
	for (float i = -(3 * n / 4); i < n; i += n / 4) {
		glPushMatrix();
		glTranslatef(0, 0, i);
		woodRaw();
		glPopMatrix();
	}		
	glPopMatrix();

	glPushMatrix();
	glRotatef(45, 0, 1, 0);
	glScalef(sqrtf(2), 1, 1);
	drawBoxBorder();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-45, 0, 1, 0);
	glScalef(sqrtf(2), 1, 1);
	drawBoxBorder();
	glPopMatrix();

	glPushMatrix();
	for (float i = 0; i < 360; i += 90) {
		glPushMatrix();
		glRotatef(i, 0, 1, 0);
		glTranslatef(0, 0.05, -2);
		drawBoxBorder();
		glPopMatrix();
	}
	glPopMatrix();

	glPopMatrix();
}

void drawBox() {
	glPushMatrix();
	for (float i = 0; i < 360; i += 90) {
		glPushMatrix();
		glRotatef(i, 0, 0, 1);
		glTranslatef(0, 2, 0);
		drawBoxSide();
		glPopMatrix();
	}

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 2, 0);
	drawBoxSide();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-90, 1, 0, 0);
	glTranslatef(0, 2, 0);
	drawBoxSide();
	glPopMatrix();

	glPopMatrix();
}

void drawBoatHouse(float R, float G, float B) {
	glPushMatrix();
	drawHouse(R, G, B);	

	glPushMatrix();
	glTranslatef(0, 1.2, 0);
	drawRoof(0.549, 0.549, 0.549);
	glPopMatrix();

	glPopMatrix();
}