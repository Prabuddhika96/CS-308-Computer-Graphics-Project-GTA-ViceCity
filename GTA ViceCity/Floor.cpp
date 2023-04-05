#include "project.h"
#include <GL/glut.h>  
#include <math.h>

void drawFloorSide() {
	glPushMatrix();

	glPushMatrix();	
	glBegin(GL_POLYGON);
	glColor3f(0.702, 0.435, 0.204);
	glVertex3f(-0.5, 1, 0);
	glVertex3f(0.5, 1, 0);

	glColor3f(0.427, 0.353, 0.286);
	glVertex3f(0.5, -1.6, 0);
	glVertex3f(-0.5, -1.6, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.702, 0.435, 0.204);
	glVertex3f(-0.5, 1, 0);
	glVertex3f(0.5, 1, 0);

	glColor3f(0, 0, 0);
	glVertex3f(0.5, 1.4, 0);
	glVertex3f(-0.5, 1.4, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.427, 0.353, 0.286);
	glBegin(GL_POLYGON);
	glVertex3f(0.5, 1.4, 0);
	glVertex3f(-0.5, 1.4, 0);
	glVertex3f(-0.5, 1.5, 0);
	glVertex3f(0.5, 1.5, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.427, 0.353, 0.286);
	glVertex3f(-0.5, 1.5, 0);
	glVertex3f(0.5, 1.5, 0);

	glColor3f(0, 0, 0);
	glVertex3f(0.5, 1.6, 0);
	glVertex3f(-0.5, 1.6, 0);
	glEnd();
	glPopMatrix();

	glPopMatrix();
}

void drawFloorTop() {
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.427, 0.353, 0.286);
	glVertex3f(-0.5, 0, -0.5);
	glVertex3f(0.5, 0, -0.5);

	glColor3f(0.427, 0.353, 0.286);
	glVertex3f(0.5, 0, 0.5);
	glVertex3f(-0.5, 0, 0.5);
	glEnd();
	glPopMatrix();
}

void drawFloorCube() {
	glPushMatrix();
	
	glPushMatrix();
	for (int i = 0; i < 360; i += 90) {
		glPushMatrix();
		glRotatef(i, 0, 1, 0);
		glTranslatef(0, 0, 0.5);
		drawFloorSide();
		glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.6, 0);
	drawFloorTop();
	glPopMatrix();

	glPopMatrix();
}

void drawFloor(int length, int width) {
	glPushMatrix();
	glTranslatef(0, 1.6, 0);
	glPushMatrix();
	if (length % 2 == 1) {
		int k = (length - 1) / 2;
		if (width % 2 == 1) {			
			int l = (width - 1) / 2;
			for (float i = -(k * 1); i <= (k * 1); i += 1) {
				for (float j = -(l * 1); j <= (l * 1); j += 1) {
					glPushMatrix();
					glTranslatef(i, 0, j);
					drawFloorCube();
					glPopMatrix();
				}
			}
		}
		else {
			int m = 1;
			int l = width / 2;
			for (float i = -(k * 1); i <= (k * 1); i += 1) {
				for (float j = -(l * 1); j < (l * 1); j += 1) {
					glPushMatrix();
					glTranslatef(i, 0, j + (m * 0.5));
					drawFloorCube();
					glPopMatrix();
				}
			}
		}
	}
	else {
		int k = (length) / 2;
		int m = 1;
		int l;
		
		if (width % 2 == 1) {
			int l = (width - 1) / 2;
			for (float i = -(k * 1); i <= (k * 1); i += 1) {
				for (float j = -(l * 1); j <= (l * 1); j += 1) {
					glPushMatrix();
					glTranslatef(i + (m * 0.5), 0, j);
					drawFloorCube();
					glPopMatrix();
				}
			}
		}
		else {
			int m = 1;
			int l = width / 2;
			for (float i = -(k * 1); i <= (k * 1); i += 1) {
				for (float j = -(l * 1); j < (l * 1); j += 1) {
					glPushMatrix();
					glTranslatef(i + (m * 0.5), 0, j + (m * 0.5));
					drawFloorCube();
					glPopMatrix();
				}
			}
		}
	}
	glPopMatrix();
	glPopMatrix();
}

// angle part
void drawBoatHouseSideTriAngle(float x1, float y1, float y2, float z1, float z2) {
	glPushMatrix();
	glColor3f(0.427, 0.353, 0.286);
	glBegin(GL_POLYGON);
	glVertex3f(x1, y1, z1);
	glVertex3f(x1, y2, z1);
	glVertex3f(x1, y2, z2);
	glEnd();
	glPopMatrix();
}

void drawBoatHouseAngle(float x1, float x2, float y1, float y2, float z1, float z2) {
	glPushMatrix();
	glColor3f(0.427, 0.353, 0.286);

	// rectangle part
	glPushMatrix();
	glBegin(GL_POLYGON);
	glVertex3f(x1, y1, z1);
	glVertex3f(x2, y1, z1);
	glVertex3f(x2, y2, z2);
	glVertex3f(x1, y2, z2);
	glEnd();
	glPopMatrix();

	// tri angle - left
	glPushMatrix();
	drawBoatHouseSideTriAngle(x1, y1, y2, z1, z2);
	glPopMatrix();

	// tri angle - right
	glPushMatrix();
	drawBoatHouseSideTriAngle(x2, y1, y2, z1, z2);
	glPopMatrix();

	glPopMatrix();
}