#include "project.h"
#include <GL/glut.h>  
#include <math.h>

#include <ctime>

// Define the constants for the linear congruential generator
const unsigned int A = 1103515245;
const unsigned int C = 12345;
const unsigned int M = 1 << 31;

// Seed the generator with the current time
unsigned int seed = static_cast<unsigned int>(time(nullptr));

// Generate a random integer between 0 and RAND_MAX
int randomInt() {
	seed = (A * seed + C) % M;
	return static_cast<int>(seed);
}


void colorPicker(int choice) {
	if (choice == 1) {
		glColor3f(0, 0.514, 1);
	}
	else {
		glColor3f(0.58, 0.91, 1);
	}
}

void drawSeaSqure(int tl, int tr, int br, int bl) {
	glPushMatrix();
	glBegin(GL_POLYGON);
	colorPicker(tl);
	glVertex3f(-0.5, 0, -0.5);

	colorPicker(tr);
	glVertex3f(0.5, 0, -0.5);

	colorPicker(br);
	glVertex3f(0.5, 0, 0.5);

	colorPicker(bl);
	glVertex3f(-0.5, 0, 0.5);
	glEnd();
	glPopMatrix();
}

void drawTexture1() {
	glPushMatrix();

	glPushMatrix();
	glTranslatef(-0.5, 0, -0.5);
	drawSeaSqure(1, 1, 0, 0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 0, -0.5);
	drawSeaSqure(1, 1, 0, 0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 0, 0.5);
	drawSeaSqure(1, 0, 1, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, 0, 0.5);
	drawSeaSqure(1, 1, 1, 0);
	glPopMatrix();

	glPopMatrix();
}

void drawTexture2() {
	glPushMatrix();

	glPushMatrix();
	glTranslatef(-0.5, 0, -0.5);
	drawSeaSqure(1, 0, 1, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 0, -0.5);
	drawSeaSqure(0, 1, 1, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 0, 0.5);
	drawSeaSqure(0, 0, 1, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, 0, 0.5);
	drawSeaSqure(0, 0, 1, 1);
	glPopMatrix();

	glPopMatrix();
}

void drawTexture3() {
	glPushMatrix();

	glPushMatrix();
	glTranslatef(-0.5, 0, -0.5);
	drawSeaSqure(1, 1, 0, 0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 0, -0.5);
	drawSeaSqure(1, 1, 0, 0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 0, 0.5);
	drawSeaSqure(0, 0, 1, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, 0, 0.5);
	drawSeaSqure(0, 0, 1, 1);
	glPopMatrix();

	glPopMatrix();
}

void drawTexture4() {
	glPushMatrix();

	glPushMatrix();
	glTranslatef(-0.5, 0, -0.5);
	drawSeaSqure(0, 0, 1, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 0, -0.5);
	drawSeaSqure(0, 0, 1, 1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.5, 0, 0.5);
	drawSeaSqure(1, 1, 0, 0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.5, 0, 0.5);
	drawSeaSqure(1, 1, 0, 0);
	glPopMatrix();

	glPopMatrix();
}

void texturePicker(int choice) {
	if (choice == 0) {
		drawTexture1();
	}
	else if (choice == 1) {
		drawTexture2();
	}
	else if (choice == 2) {
		drawTexture3();
	}
	else {
		drawTexture4();
	}
}

void drawSea(int length) {
	glPushMatrix();
	for (int i = -length - 1; i <= length - 1; i += 2) {
		for (int j = -length - 1; j <= length - 1; j += 2) {
			glPushMatrix();
			glTranslatef(i, 0, j);

			//int random = round(length / abs(i + j - 1));
			 //int random = rand() % 10;
			//int random = abs(i + j);
			int random = randomInt();

			texturePicker(random % 4);
			glPopMatrix();
		}
	}
	glPopMatrix();
}