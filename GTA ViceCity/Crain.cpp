#include "project.h"
#include <GL/glut.h>  
#include <math.h>

const double PI = 3.141592654;

void drawLeg() {
	glPushMatrix();
	glColor3f(0.6, 0.3, 0);
	glTranslatef(2, 0, -2);
	glRotatef(20, 1, 0, 1);
	glScalef(0.5, 5, 0.5);
	glutSolidCube(1);
	glPopMatrix();
}

void drawX_Leg() {
	glColor3f(0.6, 0.3, 0);
	glPushMatrix();
	glTranslatef(2, 0, -0.5);
	glRotatef(15, 0, 0, 1);
	glRotatef(42, 1, 0, 0);
	glScalef(0.5, 6.2, 0.5);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2, 0, 0.5);
	glRotatef(15, 0, 0, 1);
	glRotatef(-42, 1, 0, 0);
	glScalef(0.5, 6.2, 0.5);
	glutSolidCube(1);
	glPopMatrix();
}

void drawLatterPart() {
	glPushMatrix();

	glPushMatrix();
	for (int i = 0; i <= 360; i += 90) {
		glRotatef(i, 0, 1, 0);
		drawLeg();
		drawX_Leg();
	}
	glPopMatrix();

	glPopMatrix();
}

void topStage() {
	glColor3f(0.8, 0.8, 0.8);
	glPushMatrix();
	glTranslatef(0, 2.35, 0);
	glScalef(4.5, 0.25, 4.5);
	glutSolidCube(1);
	glPopMatrix();
}

void drawCircle(float radius) {
	glPushMatrix();
	glBegin(GL_POLYGON);
	for (int i = 0; i < 32; i++) {
		double angle = 2 * (PI / 32) * i;
		glVertex2f(radius * cos(angle), radius * sin(angle));
	}
	glEnd();
	glPopMatrix();
}

void drawCylinder(float r, float h) {
	glPushMatrix();

	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0, -h / 2);
	glPushMatrix();
	GLUquadricObj* quadratic;
	quadratic = gluNewQuadric();
	gluCylinder(quadratic, r, r, h, 100, 100);
	drawCircle(r);

	glPushMatrix();
	glTranslatef(0, 0, h);
	drawCircle(r);
	glPopMatrix();

	glPopMatrix();

	glPopMatrix();
}

void drawCylinderWithoutCircles(float r, float h) {
	glPushMatrix();

	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0, -h / 2);
	glPushMatrix();
	GLUquadricObj* quadratic;
	quadratic = gluNewQuadric();
	gluCylinder(quadratic, r, r, h, 100, 100);

	glPopMatrix();

	glPopMatrix();
}



void drawControlRoomWindowsSide() {
	glPushMatrix();

	// window wall
	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3);
	// down
	glBegin(GL_POLYGON);
	glVertex3f(-1.5, -0.8, 1.5);
	glVertex3f(1.5, -0.8, 1.5);
	glVertex3f(1.2, -0.6, 1.5);
	glVertex3f(-1.2, -0.6, 1.5);
	glEnd();

	//up
	glBegin(GL_POLYGON);
	glVertex3f(-1.5, 0.8, 1.5);
	glVertex3f(1.5, 0.8, 1.5);
	glVertex3f(1.2, 0.6, 1.5);
	glVertex3f(-1.2, 0.6, 1.5);
	glEnd();

	//right
	glBegin(GL_POLYGON);
	glVertex3f(1.5, 0.8, 1.5);
	glVertex3f(1.5, -0.8, 1.5);
	glVertex3f(1.2, -0.6, 1.5);
	glVertex3f(1.2, 0.6, 1.5);
	glEnd();

	//left
	glBegin(GL_POLYGON);
	glVertex3f(-1.5, 0.8, 1.5);
	glVertex3f(-1.5, -0.8, 1.5);
	glVertex3f(-1.2, -0.6, 1.5);
	glVertex3f(-1.2, 0.6, 1.5);
	glEnd();

	glPopMatrix();

	//left window
	glPushMatrix();
	//transparent
	glColor4f(0, 0, 0, 0.5);

	glTranslatef(0, 0, 1.5);
	glScalef(2.4, 1.2, 0.1);
	glutSolidCube(1);
	//glDisable(GL_BLEND);
	glPopMatrix();

	// roof
	glPushMatrix();
	glColor3f(0.6, 0.3, 0);
	glTranslatef(0, 0.88, 0);
	glScalef(4, 0.16, 4);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
}

void drawControlRoomWindows() {
	glPushMatrix();
	for (int i = 0; i <= 360; i += 90) {
		glRotatef(i, 0, 1, 0);
		drawControlRoomWindowsSide();
	}
	glPopMatrix();
}

void drawCrainArm(float crainArm, float crainWidth) {
	float v = 0.4;
	float angle = 60;
	float midCylinderZpos = 1.5;

	glPushMatrix();
	glPushMatrix();
	glRotatef(-crainArm, 1, 0, 0);
	glLineWidth(3);

	// crain
	glPushMatrix();
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);

	glVertex3f(-v, v, 0);
	glVertex3f(-v / 4, v / 4, crainWidth);

	glVertex3f(v, v, 0);
	glVertex3f(v / 4, v / 4, crainWidth);

	glVertex3f(v, -v, 0);
	glVertex3f(v / 4, -v / 4, crainWidth);

	glVertex3f(-v, -v, 0);
	glVertex3f(-v / 4, -v / 4, crainWidth);

	glEnd();
	glPopMatrix();

	// rope between cylinders
	glPushMatrix();
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(0, -0.19, midCylinderZpos - 0.1);
	glVertex3f(0, 0.2, crainWidth + 0.4);
	glEnd();
	glPopMatrix();

	// end rope
	glPushMatrix();
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(0, 0.2, crainWidth + 0.5);
	glVertex3f(0, -3, crainWidth + 0.5 - (crainArm / 15));
	glEnd();
	glPopMatrix();

	// mid cylinder
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0, 0, midCylinderZpos);
	glRotatef(90, 0, 0, 1);
	drawCylinder(0.2, 0.2);
	glPopMatrix();

	// end cylinder
	glPushMatrix();
	glColor3f(0, 0, 0);
	//glRotatef(-crainArm, 1, 0, 0);
	glTranslatef(0, 0, crainWidth + 0.4);
	glRotatef(90, 0, 0, 1);
	drawCylinder(0.2, 0.2);
	glPopMatrix();

	// end cylinder base
	glPushMatrix();
	glColor3f(0, 0, 0);
	//glRotatef(-crainArm, 1, 0, 0);
	glTranslatef(0, 0, crainWidth);
	glScalef(1, 1, 0.1);
	glutSolidCube(0.4);
	glPopMatrix();
	
	glPopMatrix();

	// control room to mid cylinder rope
	glPushMatrix();
	glColor3f(1, 0, 0);
	glBegin(GL_LINES);
	glVertex3f(0, 4.5, 0.5);
	glVertex3f(0, (midCylinderZpos - 0.25) * sin(crainArm / angle), fabs((midCylinderZpos - 0.2) * cos(crainArm / angle)));
	glEnd();
	glPopMatrix();

	glLineWidth(1);

	glPopMatrix();
}

void drawTopCylinderSideArm() {
	glPushMatrix();
	glColor3f(0, 0, 0);
	glLineWidth(2);

	glPushMatrix();
	glBegin(GL_LINES);
	glVertex3f(0, 0, -1.3);
	glVertex3f(0, 0, 0.4);

	glVertex3f(0, 0, 0.4);
	glVertex3f(0, 4, 0.4);

	glVertex3f(0, 4, 0.4);
	glVertex3f(0, 0, -1.3);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_LINES);
	for (float y = 1; y < 4; y++) {
		float z = ((1.7 * y) / 4) - 1.3;

		glVertex3f(0, y, 0.4);
		glVertex3f(0, y, z);
	}
	glEnd();
	glPopMatrix();

	glLineWidth(1);
	glPopMatrix();
}

void drawTopCylinder() {
	glPushMatrix();

	// side
	glPushMatrix();
	glTranslatef(-1, 0, 0);
	drawTopCylinderSideArm();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, 0, 0);
	drawTopCylinderSideArm();
	glPopMatrix();

	// side bars
	glPushMatrix();
	glLineWidth(2);
	glBegin(GL_LINES);
	for (float y = 0; y <= 4; y++) {
		if (y == 3) {
			continue;
		}
		float z = ((1.7 * y) / 4) - 1.3;

		glVertex3f(-1, y, 0.4);
		glVertex3f(1, y, 0.4);

		glVertex3f(-1, y, z);
		glVertex3f(1, y, z);
	}
	glEnd();
	glLineWidth(1);
	glPopMatrix();

	// top cylynder and cylinder rope
	glPushMatrix();
	glTranslatef(0, 4, 0.4);
	glRotatef(90, 0, 0, 1);
	drawCylinder(0.7, 1);
	glColor3f(1, 0, 0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 4, 0.4);
	glRotatef(90, 0, 0, 1);
	drawCylinder(0.75, 0.15);
	glPopMatrix();


	// middle rope
	glPushMatrix();
	glColor3f(1, 0, 0);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex3f(0, 0, -1.7);
	glVertex3f(0, 4.1, -0.33);
	glEnd();
	glLineWidth(1);
	glPopMatrix();

	glPopMatrix();
}

void drawOperatingRoom(float crainArm, float crainWidth) {
	glPushMatrix();

	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3);
	glTranslatef(0, -1, 0);
	drawCylinder(1.5, 1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.6, 0.3, 0);
	glScalef(2, 0.7, 2);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	drawControlRoomWindows();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 1.5);
	drawCrainArm(crainArm, crainWidth);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 2.5, 1.5);
	glScalef(0.5, 0.5, 0.8);
	glTranslatef(0, 0, -0.4);
	drawTopCylinder();
	glPopMatrix();

	glPopMatrix();
}

void drawCrain(float crainY, float crainArm, float crainWidth) {
	glPushMatrix();
	glScalef(0.6, 0.6, 0.6);
	glPushMatrix();

	glPushMatrix();
	drawLatterPart();
	topStage();
	glPopMatrix();

	glPushMatrix();
	glRotatef(crainY, 0, 1, 0);
	glTranslatef(0, 4, 0);
	drawOperatingRoom(crainArm, crainWidth);
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
}