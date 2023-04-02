#include "project.h"
#include <GL/glut.h>  
#include <math.h>

const double PI = 3.141592654;

void drawGateArm(float gateAngle) {
	float h = 7;
	glPushMatrix();
	glColor3f(0.004, 0, 0.459);
	glRotatef(gateAngle, 0, 0, 1);
	glTranslatef(0, h/2, 0);
	drawCylinder(0.1, h);
	glPopMatrix();
}

void drawUpperPart_Z() {
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.271, 0.161, 0);
	glVertex3f(-0.5, 2, 0.5);

	glColor3f(0.004, 0, 0.459);
	glVertex3f(0.5, 2, 0.5);

	glColor3f(0.271, 0.161, 0);
	glVertex3f(1, 0, 1);

	glColor3f(0.004, 0, 0.459);
	glVertex3f(-1, 0, 1);
	glEnd();
	glPopMatrix();
}

void drawUpperPart() {
	glPushMatrix();
	
	glPushMatrix();
	for (int i = 0; i < 360; i += 90) {
		glPushMatrix();
		glRotatef(i, 0, 1, 0);
		drawUpperPart_Z();
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.004, 0, 0.459);
	glBegin(GL_POLYGON);

	glVertex3f(-0.5, 2, -0.5);
	glVertex3f(0.5, 2, -0.5);
	glVertex3f(0.5, 2, 0.5);
	glVertex3f(-0.5, 2, 0.5);

	glEnd();
	glPopMatrix();

	glPopMatrix();
}

void drawLatterPart_Gate() {
	glPushMatrix();
	for (int i = 0; i < 360; i += 90) {
		glPushMatrix();
		glRotatef(i, 0, 1, 0);

		glPushMatrix();
		glBegin(GL_POLYGON);
		glColor3f(0.271, 0.161, 0);
		glVertex3f(1, 0, 1);

		glColor3f(0.004, 0, 0.459);
		glVertex3f(1, -3, 1);
		glVertex3f(-1, -3, 1);
		glVertex3f(-1, 0, 1);
		glEnd();
		glPopMatrix();
		glPopMatrix();
	}

	glPushMatrix();
	glColor3f(0.004, 0, 0.459);
	glBegin(GL_POLYGON);
	glVertex3f(1, -3, 1);
	glVertex3f(-1, -3, 1);
	glVertex3f(-1, -3, -1);
	glVertex3f(1, -3, -1);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.004, 0, 0.459);
	glTranslatef(0, -5, 0);
	glScalef(1, 4, 1);
	glutSolidCube(1);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.004, 0, 0.459);
	glTranslatef(0, -7.1, 0);
	glScalef(3, 0.2, 3);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
}

void drawGate(float gateAngle) {
	glPushMatrix();
	glTranslatef(0, 7, 0);
	glPushMatrix();

	glPushMatrix();
	drawGateArm(gateAngle);
	glPopMatrix();

	glPushMatrix();
	drawUpperPart();
	glPopMatrix();

	glPushMatrix();
	drawLatterPart_Gate();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
}