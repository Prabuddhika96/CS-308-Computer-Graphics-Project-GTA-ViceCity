#include "project.h"
#include <GL/glut.h>  
#include <math.h>
#define pi 3.142857

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
	glColor3f(0.3, 0.1, 0);
	glTranslatef(0, -3.5, 0);
	glScalef(7, 1, 7);
	glRotatef(45, 0, 0, 1);
	glutSolidDodecahedron();
	glPopMatrix();

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

void drawCylinder(GLfloat radius, GLfloat height){
	GLfloat x = 0.0;
	GLfloat y = 0.0;
	GLfloat angle = 0.0;
	GLfloat angle_stepsize = 0.1;

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, 0, -(height / 2));	
	//glRotatef(180, 1, 0, 0);

	/** Draw the tube */
	glBegin(GL_QUAD_STRIP);
	angle = 0.0;
	while (angle < 2 * pi) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, height);
		glVertex3f(x, y, 0.0);
		angle = angle + angle_stepsize;
	}
	glVertex3f(radius, 0.0, height);
	glVertex3f(radius, 0.0, 0.0);
	glEnd();

	/** Draw the circle on top of cylinder */
	glBegin(GL_POLYGON);
	angle = 0.0;
	while (angle < 2 * pi) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, height);
		angle = angle + angle_stepsize;
	}
	glVertex3f(radius, 0.0, height);
	glEnd();

	glBegin(GL_POLYGON);
	angle = 0.0;
	while (angle < 2 * pi) {
		x = radius * cos(angle);
		y = radius * sin(angle);
		glVertex3f(x, y, 0);
		angle = angle + angle_stepsize;
	}
	glVertex3f(radius, 0.0, height);
	glEnd();
	glPopMatrix();
}

void drawCrainArmSide(float crainWidth) {
	//float length = 6;

	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3);

	glPushMatrix();
	glLineWidth(5);
	glBegin(GL_LINES);
	glVertex3f(-0.3, 0.3, 0);
	glVertex3f(-0.1, 0.1, crainWidth);

	glVertex3f(0.3, 0.3, 0);
	glVertex3f(0.1, 0.1, crainWidth);
	glEnd();
	glLineWidth(1);
	glPopMatrix();

	glPopMatrix();
}

void drawCircle(float radius) {
	glPushMatrix();
	glPushMatrix();
	glBegin(GL_POLYGON);
	for (float i = 0; i < 2 * pi; i += 0.01) {
		float x = radius * cos(i);
		float y = radius * sin(i);
		glVertex3f(x, y, 0);
	}
	glEnd();
	glPopMatrix();
	glPopMatrix();
}

void drawKappiArm() {
	glPushMatrix();

	glPushMatrix();
	glTranslatef(0.075, 0, 0.15);
	glScalef(0.03, 0.03, 0.3);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.075, 0, 0.15);
	glScalef(0.03, 0.03, 0.3);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 0.3);
	glRotatef(90, 0, 1, 0);
	glScalef(0.03, 0.03, 0.19);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
}

void drawKappiya(float radius) {
	glColor3f(0.4, 0.4, 0.4);
	glPushMatrix();

	//drawKappiArm();

	glPushMatrix();
		glColor3f(0, 0, 0);

		glPushMatrix();
		glTranslatef(0.05, 0, 0.3);
		glRotatef(90, 0, 1, 0);
		drawCircle(radius);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.05, 0, 0.3);
		glRotatef(90, 0, 1, 0);
		drawCircle(radius);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, 0, 0.3);
		glRotatef(90, 0, 0, 1);
		drawCylinder(radius / 2, 0.09);
		glPopMatrix();
	glPopMatrix();

	glPopMatrix();
}

void drawCrainArm(float crainArm, float crainWidth) {
	glPushMatrix();
		glRotatef(-90, 0, 1, 0);
		glPushMatrix();
			glTranslatef(0, 3.5, 1.7);
			glRotatef(crainArm - 40, 1, 0, 0);
				glPushMatrix();
					for (float i = 0; i <= 350; i += 90) {
						glRotatef(i, 0, 0, 1);
						drawCrainArmSide(crainWidth);
					}
					glPushMatrix();
						glBegin(GL_POLYGON);
						glVertex3f(-0.1, 0.1, crainWidth);
						glVertex3f(0.1, 0.1, crainWidth);
						glVertex3f(0.1, -0.1, crainWidth);
						glVertex3f(-0.1, -0.1, crainWidth);
						glEnd();
					glPopMatrix();

					// crain wheel
					glPushMatrix();
					glColor3f(0.3, 0.3, 0.3);					

						glPushMatrix();
						glColor3f(0, 0, 0);
						glTranslatef(0, 0, crainWidth);

						drawControlRoomUpKappiyaRopePart2(crainArm, crainWidth);
						drawControlRoomUpKappiyaRopePart3(crainArm, crainWidth);

						drawKappiArm();
						drawKappiya(0.2);
						glPopMatrix();

					glPopMatrix();

				glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}

void drawControlRoomUpKappiyaSide(float height) {
	float n = 0.1;
	glPushMatrix();
	
	glPushMatrix();
	glScalef(n, height, n);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -height / 2, -height / 4);
	glRotatef(90, 1, 0, 0);
	glScalef(n, height/2, n);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -height / 4);
	glRotatef(28, 1, 0, 0);
	glScalef(n, ((height / 2) * pow(5, 0.5)), n);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
}

void drawControlRoomUpKappiya(float height) {
	float n = 0.1;

	glPushMatrix();
	glColor3f(0.4, 0.4, 0.4);
	glTranslatef(0, height / 2, 0);
	glPushMatrix();
	glPushMatrix();
	glTranslatef(height / 4, 0, 0);
	drawControlRoomUpKappiyaSide(height);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-height / 4, 0, 0);
	drawControlRoomUpKappiyaSide(height);
	glPopMatrix();

	glPushMatrix();
	float lineGap = 0.2;
	int k = height / lineGap;
	for (int i = 0; i <= k; i +=1) {
		float l = (height / 2) - (i * lineGap);

		glPushMatrix();
		glLineWidth(5);
		glBegin(GL_LINES);
		if (i != 1) {
			glVertex3f(-height / 4, l, 0);
			glVertex3f(height / 4, l, 0);
		}
		
		float z = ((l / 2) - (height / 4));
		if (i >= 2) {			
			glVertex3f(-height / 4, l, z);
			glVertex3f(height / 4, l, z);
		}

		if (!(i == 0 || i == 1 || i == k)) {
			glVertex3f(-height / 4, l, 0);
			glVertex3f(-height / 4, l, z);

			glVertex3f(height / 4, l, 0);
			glVertex3f(height / 4, l, z);
		}
		glEnd();
		glLineWidth(1);
		glPopMatrix();
	}

	glPushMatrix();
	//glTranslatef(height / 4, 0, 0);
	glScalef(3, 1, 1);
	glTranslatef(0, height / 2 + 0.1, -0.25);
	//glScalef(0.5, 1, 1);
	drawKappiya(height/4);
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}


void drawControlRoomWindowsSide() {
	glPushMatrix();

	// window wall
	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3);
	glBegin(GL_POLYGON);
	glVertex3f(-1.5, -0.8, 1.5);
	glVertex3f(1.5, -0.8, 1.5);
	glVertex3f(1.5, 0.8, 1.5);
	glVertex3f(-1.5, 0.8, 1.5);
	glEnd();
	glPopMatrix();

	glColor3f(0.1, 0.1, 0.1);
	//left window
	glPushMatrix();	
	glTranslatef(0, 0, 1.5);
	glScalef(2.4, 1.2, 0.1);
	glutSolidCube(1);
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

//Crain Rope
void drawControlRoomUpKappiyaRopePart1() {
	glPushMatrix();
	glColor3f(1, 1, 0);


	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex3f(0, 6.2, 0);
	glVertex3f(-1.5, 7.65, 0);
	glEnd();
	glPopMatrix();

	glLineWidth(1);

	glPopMatrix();
}

void drawControlRoomUpKappiyaRopePart2(float crainArm, float crainWidth) {
	glPushMatrix();
	glColor3f(1, 1, 0);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex3f(0, -0.2, 0.3);
	glVertex3f(0, 0, -crainWidth + 3.3);
	glEnd();
	glLineWidth(1);
	glPopMatrix();
}

void drawHook() {
	float cubeSize = 1;
	float n = 0.1 * cubeSize;

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0.1, 0, 0);

	glPushMatrix();
	glTranslatef(0, n, 0);
	glScalef(0.2, 0.01, 0.01);
	glutSolidCube(cubeSize);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-n, 0, 0);
	glRotatef(90, 0, 0, 1);
	glScalef(0.2, 0.01, 0.01);
	glutSolidCube(cubeSize);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -n, 0);
	glScalef(0.2, 0.01, 0.01);
	glutSolidCube(cubeSize);
	glPopMatrix();

	glPopMatrix();
}

void drawControlRoomUpKappiyaRopePart3(float crainArm, float crainWidth) {
	float x = crainArm/50;
	float y = crainWidth;

	if (0.5 < y - 8.5 + (4 * x)) {
		x = 1;
	}
	glPushMatrix();

	glPushMatrix();
	glColor3f(1, 1, 0);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex3f(0, -0.05, 0.5);
	glVertex3f(0, 9.5- y, y -8.5);
	glEnd();
	glLineWidth(1);

	glPushMatrix();
	glTranslatef(0, 9.5 - y, y - 8.5);
	//glTranslatef(0, 5, 0);
	drawHook();
	glPopMatrix();

	glPopMatrix();
}

void drawOperatingRoom(float crainArm, float crainWidth) {
	glPushMatrix();

	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3);
	glTranslatef(0, 2.7, 0);
	drawCylinder(1.5, 0.6);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.6, 0.3, 0);
	glTranslatef(0, 3.7, 0);
	glScalef(2, 0.7, 2);
	glutSolidCube(2);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 5.2, 0);
	drawControlRoomWindows();
	glPopMatrix();

	glPushMatrix();
	drawCrainArm(crainArm, crainWidth);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.5, 6.2, 0);
	glRotatef(-90, 0, 1, 0);
	drawControlRoomUpKappiya(1.2);
	glPopMatrix();

	glPushMatrix();
	drawControlRoomUpKappiyaRopePart1();
	//drawControlRoomUpKappiyaRopePart2(crainArm, crainWidth);
	glPopMatrix();



	glPopMatrix();
}



void drawCrain(float crainY, float crainArm, float crainWidth) {
	glPushMatrix();
	glScalef(0.6, 0.6, 0.6);	
	glPushMatrix();
	drawLatterPart();
	topStage();

	glPushMatrix();
	glRotatef(crainY, 0, 1, 0);
	drawOperatingRoom(crainArm, crainWidth);
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
}