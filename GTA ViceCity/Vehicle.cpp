#include "project.h"
#include <GL/glut.h>  
#include <math.h>
#define pi 3.142857

void drawContainerBoxPartSquare() {
	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex3f(-0.125, 2, 0);
	glVertex3f(0.125, 2, 0);
	glVertex3f(0.125, -2, 0);
	glVertex3f(-0.125, -2, 0);
	glEnd();
	glPopMatrix();
}

void drawContainerBoxPart() {
	glPushMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -0.25);
	drawContainerBoxPartSquare();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glTranslatef(0, 0, -0.125);
	glScalef(2, 1, 1);
	drawContainerBoxPartSquare();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.369, 0, 0);
	glRotatef(-90, 0, 1, 0);
	glTranslatef(0, 0, -0.125);
	glScalef(2, 1, 1);
	drawContainerBoxPartSquare();
	glPopMatrix();

	glPopMatrix();
}

void drawContainerBoxPiece(float r, float g, float b) {
	glPushMatrix();

	glPushMatrix();
	glColor3f(r,g,b);
	glTranslatef(-0.125, 0, 0);
	drawContainerBoxPart();
	glPopMatrix();

	glPushMatrix();
	glColor3f(r,g,b);
	glRotatef(180, 0, 1, 0);
	glTranslatef(-0.125, 0, 0);
	drawContainerBoxPart();
	glPopMatrix();

	glPopMatrix();
}

void drawContainerBoxRow(float r, float g, float b) {
	float l = 6 - 0.25;
	glPushMatrix();
	glScalef(1, 1, 0.5);
	glPushMatrix();
	for (float i = -l; i <= l; i += 0.5) {
		glPushMatrix();
		glTranslatef(i, 0, 0);
		drawContainerBoxPiece(r,g,b);
		glPopMatrix();
	}
	glPopMatrix();
	glPopMatrix();
	
}

void drawContainerBoxSide(float r, float g, float b) {
	float l = 2 - 0.25;
	glPushMatrix();
	glScalef(1, 1, 0.5);
	glPushMatrix();
	for (float i = -l; i <= l; i += 0.5) {
		glPushMatrix();
		glTranslatef(i, 0, 0);
		drawContainerBoxPiece(r,g,b);
		glPopMatrix();
	}
	glPopMatrix();
	glPopMatrix();

}

void drawContainerBoxFrame(float r, float g, float b) {
	glPushMatrix();

	// frame right
	glPushMatrix();
	glColor3f(r, g, b);
	for (float i = 0; i <= 360; i += 90) {
		glPushMatrix();
		glRotatef(i, 1, 0, 0);
		glTranslatef(6, 0, 2);
		glScalef(0.3, 4.25, 0.3);
		glutSolidCube(1);
		glPopMatrix();
	}
	glPopMatrix();

	// frame left
	glPushMatrix();
	glColor3f(r, g, b);
	for (float i = 0; i <= 360; i += 90) {
		glPushMatrix();
		glRotatef(i, 1, 0, 0);
		glTranslatef(-6, 0, 2);
		glScalef(0.3, 4.25, 0.3);
		glutSolidCube(1);
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix();
	glColor3f(r, g, b);
	for (float i = 0; i <= 360; i += 90) {
		glPushMatrix();
		glRotatef(i, 1, 0, 0);
		glTranslatef(0, 2, 2);
		glScalef(12, 0.3, 0.3);
		glutSolidCube(1);
		glPopMatrix();
	}
	glPopMatrix();

	glPopMatrix();
}



// vehicle face

void drawVehicleBox() {
	glPushMatrix();

	glPushMatrix();
	glEnable(GL_CLIP_PLANE0);
	double planeEquation[] = { -1,-1,0,1.5 };
	glClipPlane(GL_CLIP_PLANE0, planeEquation);

	glPushMatrix();
	glScalef(4, 3, 3.6);
	glutSolidCube(1);
	glPopMatrix();

	glDisable(GL_CLIP_PLANE0);
	glPopMatrix();

	glPopMatrix();
}

void drawVehicleWindowFrame(float r, float g, float b) {
	glPushMatrix();
	glColor3f(r, g, b);

	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex3f(-0.9, 0.5, 0);
	glVertex3f(0.9, 0.5, 0);
	glVertex3f(0.7, 0.3, 0);
	glVertex3f(-0.7, 0.3, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex3f(0.9, 0.5, 0);
	glVertex3f(0.9, -0.5, 0);
	glVertex3f(0.7, -0.3, 0);
	glVertex3f(0.7, 0.3, 0);
	glEnd();
	glPopMatrix();

	glPopMatrix();
}

void drawVehicleWindow(float r, float g, float b) {
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glPushMatrix();

	// frame
	glPushMatrix();
	drawVehicleWindowFrame(r,g,b);
	glPopMatrix();

	glPushMatrix();
	glRotatef(180, 0, 0, 1);
	drawVehicleWindowFrame(r,g,b);
	glPopMatrix();

	// window
	glPushMatrix();
	glColor4f(0, 0, 0, 0.7);
	glBegin(GL_POLYGON);
	glVertex3f(-0.7, 0.3, 0);
	glVertex3f(0.7, 0.3, 0);
	glVertex3f(0.7, -0.3, 0);
	glVertex3f(-0.7, -0.3, 0);
	glEnd();
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
}

void drawFullWindow(float r, float g, float b) {
	glPushMatrix();
	
	glPushMatrix();
	glTranslatef(0, 0, 0.9);
	drawVehicleWindow(r,g,b);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -0.9);
	drawVehicleWindow(r,g,b);
	glPopMatrix();

	glPopMatrix();
}

void drawDoorWindow() {
	glPushMatrix();
	glEnable(GL_CLIP_PLANE0);
	glEnable(GL_CLIP_PLANE1);
	double planeEquation[] = { -1,-1,0,1.2 };
	double planeEquation1[] = { 0,1,0,-0.2 };
	glClipPlane(GL_CLIP_PLANE0, planeEquation);
	glClipPlane(GL_CLIP_PLANE1, planeEquation1);

	glPushMatrix();
	glColor4f(0, 0, 0, 0.7);
	glScalef(3.6, 2.6, 3.7);
	glutSolidCube(1);
	glPopMatrix();

	glDisable(GL_CLIP_PLANE0);
	glDisable(GL_CLIP_PLANE1);
	glPopMatrix();
}

void drawUnderWindowPart(float r, float g, float b) {
	glPushMatrix();
	glColor3f(r,g,b);
	glBegin(GL_POLYGON);
	glVertex3f(1.5, 0, 1.8);
	glVertex3f(1.5, 0, -1.8);
	glVertex3f(2, -0.5, -1.8);
	glVertex3f(2, -0.5, 1.8);
	glEnd();
	glPopMatrix();
}

void drawTyre() {
	glPushMatrix();
	
	glPushMatrix();
	glColor3f(0, 0, 0);
	glRotatef(90, 1, 0, 0);
	drawCylinder(1, 0.7);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1, 1, 1);
	glRotatef(90, 1, 0, 0);
	drawCylinder(0.8, 0.8);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	for (float i = 0; i < 360; i += 30) {
		glPushMatrix();
		glRotatef(i, 0, 0, 1);
		glPushMatrix();
		glTranslatef(0, 0.5, 0);
		glRotatef(90, 1, 0, 0);
		drawCylinder(0.08, 0.85);
		glPopMatrix();
		glPopMatrix();
	}	
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glRotatef(90, 1, 0, 0);
	drawCylinder(0.3, 0.85);
	glPopMatrix();

	glPopMatrix();
}

void drawWheel(float r, float g, float b) {
	glPushMatrix();
	glColor3f(r, g, b);

	glPushMatrix();
	glScalef(1.5, 0.1, 0.7);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.25, -0.5, 0);
	glRotatef(45, 0, 0, 1);
	glScalef(1.5, 0.1, 0.7);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.25, -0.5, 0);
	glRotatef(-45, 0, 0, 1);
	glScalef(1.5, 0.1, 0.7);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1.2, 0);
	drawTyre();
	glPopMatrix();

	glPopMatrix();
}

void drawVehicleFace(float r, float g, float b) {
	glPushMatrix();
	glColor3f(r, g, b);
	
	glPushMatrix();
	drawVehicleBox();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.75, 0.75, 0);
	glRotatef(45, 0, 0, 1);
	glScalef(1, 2.1, 1);
	drawFullWindow(r,g,b);
	glPopMatrix();

	glPushMatrix();
	drawDoorWindow();
	glPopMatrix();

	glPushMatrix();
	drawDoorWindow();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	for (float i = 0; i <= 0.5; i += 0.1) {
		glPushMatrix();
		glTranslatef(1.5+i, -i, 0);
		glScalef(0.05, 0.05, 3.4);
		glutSolidCube(1);
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix();
	drawUnderWindowPart(r, g, b);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1.35, 2);
	glScalef(0.7, 0.7, 0.7);
	drawWheel(r,g,b);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1.35, -2);
	glScalef(0.7, 0.7, 0.7);
	drawWheel(r, g, b);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.612, 0.612, 0.612);
	glTranslatef(1.7, -1, 1.2);
	glutSolidSphere(0.4, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.612, 0.612, 0.612);
	glTranslatef(1.7, -1, -1.2);
	glutSolidSphere(0.4, 50, 50);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1);
	glTranslatef(2, -1, 0);
	glScalef(0.1, 0.7, 1.6);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
}

void drawContainerBox(float r, float g, float b) {
	glPushMatrix();

	glPushMatrix();
	for (float i = -0; i < 360; i += 90) {
		glPushMatrix();
		glRotatef(i, 1, 0, 0);
		glTranslatef(0, 0, 2);
		drawContainerBoxRow(r, g, b);
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6, 0, 0);
	glRotatef(90, 0, 1, 0);
	drawContainerBoxSide(r, g, b);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-6, 0, 0);
	glRotatef(90, 0, 1, 0);
	drawContainerBoxSide(r, g, b);
	glPopMatrix();

	glPushMatrix();
	drawContainerBoxFrame(r, g, b);
	glPopMatrix();

	// wheel - z +
	glPushMatrix();
	glTranslatef(-4.5, -2.1, 2);
	glScalef(0.7, 0.7, 0.7);
	drawWheel(r, g, b);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2, -2.1, 2);
	glScalef(0.7, 0.7, 0.7);
	drawWheel(r, g, b);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.5, -2.1, 2);
	glScalef(0.7, 0.7, 0.7);
	drawWheel(r, g, b);
	glPopMatrix();

	// wheel - z -
	glPushMatrix();
	glTranslatef(-4.5, -2.1, -2);
	glScalef(0.7, 0.7, 0.7);
	drawWheel(r, g, b);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2, -2.1, -2);
	glScalef(0.7, 0.7, 0.7);
	drawWheel(r, g, b);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.5, -2.1, -2);
	glScalef(0.7, 0.7, 0.7);
	drawWheel(r, g, b);
	glPopMatrix();

	glPopMatrix();
}

void drawVehicle(float r, float g, float b) {
	glTranslatef(0, 3.5, 0);
	glPushMatrix();
	
	glPushMatrix();
	glTranslatef(-2, 0, 0);
	drawContainerBox(r, g, b);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(6.5, -0.75, 0);
	drawVehicleFace(b, r, g);
	glPopMatrix();

	glPopMatrix();
	
}