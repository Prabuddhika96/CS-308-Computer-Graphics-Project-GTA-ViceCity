#include "project.h"
#include <GL/glut.h>  
#include <math.h>

const double PI = 3.141592654;

// brick part
void drawFullBrickCube() {
	glPushMatrix();
	glColor3f(0.859, 0.212, 0);
	glScalef(0.9, 0.4, 0.1);
	glutSolidCube(1);
	glPopMatrix();
}

void drawFullBricCement() {
	glPushMatrix();
	glColor3f(0.251, 0.251, 0.251);
	glScalef(1, 0.5, 0.08);
	glutSolidCube(1);
	glPopMatrix();
}

void drawFullBrick() {
	glPushMatrix();

	glPushMatrix();
	drawFullBrickCube();
	glPopMatrix();

	glPushMatrix();
	drawFullBricCement();
	glPopMatrix();

	glPopMatrix();
}

void drawHalfBric() {
	glPushMatrix();
	glPushMatrix();
	//Enble clipping plan 0
	glEnable(GL_CLIP_PLANE0);

	// define the clipping plane equation
	double planeEquation[] = { 1,0,0,0 };
	glClipPlane(GL_CLIP_PLANE0, planeEquation);

	// render object
	drawFullBrick();

	//disable clipping plan 0
	glDisable(GL_CLIP_PLANE0);
	glPopMatrix();

	glPopMatrix();
}

void drawFullBricLine(float width) {
	glPushMatrix();
	for (float j = -width; j <= width; j++) {
		glPushMatrix();
		glTranslatef(j, 0, 0);
		drawFullBrick();
		glPopMatrix();
	}
	glPopMatrix();
}

void drawHalfBricLine(float width) {
	glPushMatrix();

	glPushMatrix();
	for (float j = -width; j <= width; j++) {
		if (j != -width ) {
			glPushMatrix();
			glTranslatef(j - 0.5, 0, 0);
			drawFullBrick();
			glPopMatrix();
		}		
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3, 0, 0);
	drawHalfBric();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3, 0, 0);
	glRotatef(180, 0, 0, 1);
	drawHalfBric();
	glPopMatrix();

	glPopMatrix();
}

void drawLatterPart(float width) {
	glPushMatrix();
	for (float i = -0.5; i <= 0.5; i += 0.5) {
		if (int(i / 0.5) %2 == 0) {
			glPushMatrix();
			glTranslatef(0, i, 0);
			drawFullBricLine(width);
			glPopMatrix();
		}
		else {
			glPushMatrix();
			glTranslatef(0, i, 0);
			drawHalfBricLine(width);
			glPopMatrix();
		}
	}
	glPopMatrix();
}

// cement part
void drawCemntRow(float R, float G, float B, float R1, float G1, float B1) {
	glPushMatrix();
	glBegin(GL_POLYGON);

	glColor3f(R, G, B);
	glVertex3f(0.05, 0.5, 0);
	glVertex3f(0.05, -0.5, 0);

	glColor3f(R1,G1,B1);
	glVertex3f(-0.05, -0.5, 0);
	glVertex3f(-0.05, 0.5, 0);
	glEnd();
	glPopMatrix();
}

void drawCementLine(float R, float G, float B, float R1, float G1, float B1, float width) {
	width += 0.5;
	glPushMatrix();
	for (float i = -width+0.05; i <= width-0.05; i += 0.1) {
		glPushMatrix();
		glTranslatef(i, 0, 0);
		drawCemntRow(R1, G1, B1, R, G, B);
		glPopMatrix();
	}
	glPopMatrix();
}

// down window part
void drawFourWindow() {
	glPushMatrix();

	glPushMatrix();
	glColor4f(0, 0, 0, 0.7);

	glBegin(GL_POLYGON);
	glVertex3f(-2, 1, 0);
	glVertex3f(2, 1, 0);
	glVertex3f(2, -1, 0);
	glVertex3f(-2, -1, 0);
	glEnd();

	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0, 0.5, 0);
	glScalef(4, 0.1, 0.1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0, -0.5, 0);
	glScalef(4, 0.1, 0.1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	for (int i = -2; i <= 2; i++) {
		glPushMatrix();
		glColor3f(0, 0, 0);
		glTranslatef(i, 0, 0);
		glScalef(0.1, 1.1, 0.1);
		glutSolidCube(1);
		glPopMatrix();
	}
	glPopMatrix();

	glPopMatrix();
}

void drawBuildingDownWall(float R, float G, float B, float R1, float G1, float B1) {
	glPushMatrix();

	glPushMatrix();
	glColor3f(R, G, B);
	//left
	glBegin(GL_POLYGON);
	glColor3f(R1, G1, B1);
	glVertex3f(-3, 1, 0);
	glColor3f(R, G, B);
	glVertex3f(-2, 0.5, 0);
	glVertex3f(-2, -0.5, 0);
	glColor3f(R1, G1, B1);
	glVertex3f(-3, -1, 0);
	glEnd();
	// right
	glBegin(GL_POLYGON);
	glColor3f(R1, G1, B1);
	glVertex3f(3, 1, 0);
	glColor3f(R, G, B);
	glVertex3f(2, 0.5, 0);
	glVertex3f(2, -0.5, 0);
	glColor3f(R1, G1, B1);
	glVertex3f(3, -1, 0);
	glEnd();
	//up
	glBegin(GL_POLYGON);
	glColor3f(R1, G1, B1);
	glVertex3f(-3, 1, 0);
	glVertex3f(3, 1, 0);
	glColor3f(R, G, B);
	glVertex3f(2, 0.5, 0);
	glVertex3f(-2, 0.5, 0);
	glEnd();
	// down
	glBegin(GL_POLYGON);
	glColor3f(R1, G1, B1);
	glVertex3f(-3, -1, 0);
	glVertex3f(3, -1, 0);
	glColor3f(R, G, B);
	glVertex3f(2, -0.5, 0);
	glVertex3f(-2, -0.5, 0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	drawFourWindow();
	glPopMatrix();

	glPopMatrix();
}

void drawLatterPartAndCement() {
	float width = 3;
	glPushMatrix();

	glPushMatrix();
	drawLatterPart(width);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.25, 0);
	drawCementLine(0.2, 0.2, 0.2, 0.9, 0.9, 0.9, width);
	glPopMatrix();

	glPopMatrix();
}

void drawSide(float R, float G, float B, float R1, float G1, float B1) {
	float width = 3;
	glPushMatrix();

	glPushMatrix();
	drawLatterPartAndCement();
	glPopMatrix();

	glPushMatrix();
	glScalef(1.165, 1, 1);
	glTranslatef(0, 2.75, 0);
	drawBuildingDownWall(R, G, B, R1, G1, B1);
	glPopMatrix();

	glPushMatrix();
	glScalef(1.165, 1, 1);
	glTranslatef(0, 4.75, 0);
	drawBuildingDownWall(R, G, B, R1, G1, B1);
	glPopMatrix();

	glPopMatrix();
}

// left and right sides
void drawXSide() {
	glPushMatrix();
	glTranslatef(0, 0, 3.5);
	glScalef(0.85, 1, 1);
	drawLatterPartAndCement();
	glPopMatrix();
}

void drawSideXwall(float R, float G, float B, float R1, float G1, float B1) {
	glPushMatrix();
	glTranslatef(0, 0, 3.5);
	
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(R, G, B);
	glVertex3f(-3, 1.75, 0);
	glColor3f(R1, G1, B1);
	glVertex3f(3, 1.75, 0);
	glColor3f(R, G, B);
	glVertex3f(3, 5.75, 0);
	glColor3f(R1, G1, B1);
	glVertex3f(-3, 5.75, 0);
	glEnd();
	glPopMatrix();

	glPopMatrix();
}

void drawFloor() {
	glPushMatrix();
	glColor3f(0.839, 0.51, 0);

	glBegin(GL_POLYGON);
	glVertex3f(-3.5, 0, -3);
	glVertex3f(3.5, 0, -3);
	glVertex3f(3.5, 0, 3);
	glVertex3f(-3.5, 0, 3);
	glEnd();

	glPopMatrix();
}

void drawBuilding(float R, float G, float B, float R1, float G1, float B1) {
	glPushMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 3);
	drawSide(R, G, B, R1, G1, B1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -3);
	drawSide(R, G, B, R1, G1, B1);
	glPopMatrix();

	// left
	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	drawXSide();
	drawSideXwall(R, G, B, R1, G1, B1);
	glPopMatrix();

	//right
	glPushMatrix();
	glRotatef(-90, 0, 1, 0);
	drawXSide();
	drawSideXwall(R, G, B, R1, G1, B1);
	glPopMatrix();

	// slab - down
	glPushMatrix();
	glColor3f(R1-0.2, G1, B1);
	glTranslatef(0, 3.75, 0);
	glScalef(7.5, 0.1, 6.1);
	glutSolidCube(1);
	glPopMatrix();

	// slab - up
	glPushMatrix();
	glColor3f(R1 - 0.2, G1, B1);
	glTranslatef(0, 5.75, 0);
	glScalef(7.5, 0.1, 6.1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -0.75, 0);
	drawFloor();
	glPopMatrix();

	glPopMatrix();
}

void drawBuildingRow(float R, float G, float B, float R1, float G1, float B1, int number) {
	glPushMatrix();

	if (number % 2 == 1) {
		int k = (number - 1) / 2;
		for (float i = -(k * 7); i <= (k * 7); i += 7) {
			glPushMatrix();
			glTranslatef(i, 0, 0);
			drawBuilding(R, G, B, R1, G1, B1);
			glPopMatrix();
		}
	}
	else {
		int k = (number) / 2;
		int j = 1;
		int l;
		for (float i = -(k * 7); i < (k * 7); i += 7) {
			glPushMatrix();
			glTranslatef(i+(j*3.5), 0, 0);
			drawBuilding(R, G, B, R1, G1, B1);
			glPopMatrix();			
		}
	}
	glPopMatrix();
}

/* ************************************************* Green Bulding ************************************************* */
void drawBuilding_1_FrontWall_X(float R, float G, float B, float R1, float G1, float B1, float width) {
	glPushMatrix();

	glEnable(GL_CLIP_PLANE0);

	double planeEquation[] = { 1,0,0,0.5 };
	glClipPlane(GL_CLIP_PLANE0, planeEquation);

	glTranslatef(-2.5, 0, 0);
	drawCementLine(R, G, B, R1, G1, B1, 2.5);

	glDisable(GL_CLIP_PLANE0);

	glPopMatrix();
}

void drawBuilding_1_FrontWall_Y(float R, float G, float B, float R1, float G1, float B1, float width) {
	glPushMatrix();

	glEnable(GL_CLIP_PLANE0);

	double planeEquation[] = { 1,0,0,2 };
	glClipPlane(GL_CLIP_PLANE0, planeEquation);

	glTranslatef(-1, 0, 0);
	drawCementLine(R, G, B, R1, G1, B1, 2.5);

	glDisable(GL_CLIP_PLANE0);

	glPopMatrix();
}

void draw_Building1_Window_wall_X(float R, float G, float B, float R1, float G1, float B1) {
	glPushMatrix();
	glTranslatef(-0.45, 0, 0);
	drawCemntRow(R, G, B, R1, G1, B1);
	glPopMatrix();
}

void draw_Building1_Window_frame_X() {
	glPushMatrix();
	glColor3f(0.388, 0.388, 0.388);
	glTranslatef(-0.35, 0, 0);
	glScalef(0.1, 1, 0.1);
	glutSolidCube(1);
	glPopMatrix();
}

void draw_Building1_Window_X(float R, float G, float B, float R1, float G1, float B1) {
	glPushMatrix();

	glEnable(GL_CLIP_PLANE0);
	glEnable(GL_CLIP_PLANE1);
	double planeEquation0[] = { -1,-1,0,0 };
	double planeEquation1[] = { -1,1,0,0 };
	glClipPlane(GL_CLIP_PLANE0, planeEquation0);
	glClipPlane(GL_CLIP_PLANE1, planeEquation1);

	glPushMatrix();

	glPushMatrix();
	draw_Building1_Window_wall_X(R, G, B, R1, G1, B1);
	glPopMatrix();

	glPushMatrix();
	draw_Building1_Window_frame_X();
	glPopMatrix();

	glPopMatrix();
	glDisable(GL_CLIP_PLANE0);
	glDisable(GL_CLIP_PLANE1);

	glPopMatrix();
}

void draw_Building1_Window_wall_Y(float R, float G, float B, float R1, float G1, float B1) {
	glPushMatrix();
	glTranslatef(0, 0.45, 0);
	glScalef(1, 0.1, 1);
	glPushMatrix();
	for (float i = -0.45; i <= 0.45; i += 0.1) {
		glPushMatrix();
		glTranslatef(i, 0, 0);
		drawCemntRow(R1, G1, B1, R, G, B);
		glPopMatrix();
	}	
	glPopMatrix();
	glPopMatrix();
}
void draw_Building1_Window_frame_Y() {
	glPushMatrix();
	glColor3f(0.388, 0.388, 0.388);
	glScalef(1, 0.1, 0.1);
	glutSolidCube(1);
	glPopMatrix();
}

void draw_Building1_Window_Y(float R, float G, float B, float R1, float G1, float B1) {
	glPushMatrix();

	glEnable(GL_CLIP_PLANE0);
	glEnable(GL_CLIP_PLANE1);
	double planeEquation0[] = { 1,1,0,0 };
	double planeEquation1[] = { -1,1,0,0 };
	glClipPlane(GL_CLIP_PLANE0, planeEquation0);
	glClipPlane(GL_CLIP_PLANE1, planeEquation1);

	glPushMatrix();

	glPushMatrix();
	draw_Building1_Window_wall_Y(R, G, B, R1, G1, B1);
	glPopMatrix();

	glPushMatrix();	
	glTranslatef(0, 0.35, 0);
	draw_Building1_Window_frame_Y();
	glPopMatrix();

	glPopMatrix();
	glDisable(GL_CLIP_PLANE0);
	glDisable(GL_CLIP_PLANE1);

	glPopMatrix();
}

void draw_Building1_Window(float R, float G, float B, float R1, float G1, float B1) {
	glPushMatrix();

	glPushMatrix();
	draw_Building1_Window_X(R, G, B, R1, G1, B1);
	glPopMatrix();

	glPushMatrix();
	glRotatef(180, 0, 0, 1);
	draw_Building1_Window_X(R, G, B, R1, G1, B1);
	glPopMatrix();

	glPushMatrix();
	draw_Building1_Window_Y(R, G, B, R1, G1, B1);
	glPopMatrix();

	glPushMatrix();
	glRotatef(180, 0, 0, 1);
	draw_Building1_Window_Y(R, G, B, R1, G1, B1);
	glPopMatrix();

	// glass
	glPushMatrix();
	glColor4f(1, 1, 1, 0.5);

	glBegin(GL_POLYGON);
	glVertex3f(-0.3, 0.3, 0);
	glVertex3f(0.3, 0.3, 0);
	glVertex3f(0.3, -0.3, 0);
	glVertex3f(-0.3, -0.3, 0);
	glEnd();

	glPopMatrix();

	glPopMatrix();
}

void drawWindowRaw(float R, float G, float B, float R1, float G1, float B1) {
	glPushMatrix();
	for (float i = -1.5; i <= 1.5; i++) {
		glPushMatrix();
		glTranslatef(i, 0, 0);
		draw_Building1_Window(R, G, B, R1, G1, B1);
		glPopMatrix();
	}
	glPopMatrix();
}

void drawBuilding_1_Side_X(float R, float G, float B, float R1, float G1, float B1) {
	glPushMatrix();

	// green wall
	glPushMatrix();	
	glTranslatef(0, -0.75, 0);
	glScalef(1, 0.5, 1);
	drawCementLine(R, G, B, R1, G1, B1, 2.5);
	glPopMatrix();

	// cement
	glPushMatrix();	
	drawCementLine(0.2, 0.2, 0.2, 0.9, 0.9, 0.9, 2.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-2.5, 1.5, 0);
	glScalef(1, 2, 1);
	drawBuilding_1_FrontWall_X(R, G, B, R1, G1, B1, 2.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.5, 1.5, 0);
	glScalef(1, 2, 1);
	drawBuilding_1_FrontWall_X(R, G, B, R1, G1, B1, 2.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 2.25, 0);
	glScalef(1, 0.5, 1);
	drawBuilding_1_FrontWall_Y(R, G, B, R1, G1, B1, 2.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0.75, 0);
	glScalef(1, 0.5, 1);
	drawBuilding_1_FrontWall_Y(R, G, B, R1, G1, B1, 2.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	drawWindowRaw(R, G, B, R1, G1, B1);
	glPopMatrix();

	glPopMatrix();
}

void drawBuilding_1_Side_Y(float R, float G, float B, float R1, float G1, float B1) {
	float s = 0.67;
	glPushMatrix();
	glTranslatef(0, 0, 3);
	glPushMatrix();

	// green wall
	glPushMatrix();
	glTranslatef(0, -0.75, 0);
	glScalef(s, 0.5, 1);
	drawCementLine(R, G, B, R1, G1, B1, 2.5);
	glPopMatrix();

	// cement	
	glPushMatrix();
	glScalef(s, 1, 1);
	drawCementLine(0.2, 0.2, 0.2, 0.9, 0.9, 0.9, 2.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1.5, 0);
	glScalef(s, 2, 1);
	drawCementLine(R, G, B, R1, G1, B1, 2.5);
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
}

void drawFloor1() {
	glPushMatrix();
	glColor3f(0.839, 0.51, 0);

	glBegin(GL_POLYGON);
	glVertex3f(-3, 0, -2);
	glVertex3f(3, 0, -2);
	glVertex3f(3, 0, 2);
	glVertex3f(-3, 0, 2);
	glEnd();

	glPopMatrix();
}

void drawBuilding1_roof_Y(float R, float G, float B, float R1, float G1, float B1) {
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(R, G, B);
	glVertex3f(0, 1.5, 0);
	glColor3f(R1, G1, B1);
	glVertex3f(0, 0, -2.2);
	glVertex3f(0, 0, 2.2);
	glEnd();
	glPopMatrix();
}

void drawBuilding1_roof_X() {
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3f(0.471, 0.471, 0.471);
	glVertex3f(-3.2, 1.5, 0);
	glVertex3f(3.2, 1.5, 0);

	glColor3f(0, 0, 0);
	glVertex3f(3.2, 0, 2.2);
	glVertex3f(-3.2, 0, 2.2);
	glEnd();
	glPopMatrix();
}

void drawBuilding1_roof(float R, float G, float B, float R1, float G1, float B1) {
	glPushMatrix();
	
	glPushMatrix();
	glColor3f(R1, G1, B1);

	glBegin(GL_POLYGON);
	glVertex3f(-3.2, 0, -2.2);
	glVertex3f(3.2, 0, -2.2);
	glVertex3f(3.2, 0, 2.2);
	glVertex3f(-3.2, 0, 2.2);
	glEnd();

	glPopMatrix();

	glPushMatrix();	
	glTranslatef(-3.2, 0, 0);
	drawBuilding1_roof_Y(R, G, B, R1, G1, B1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.2, 0, 0);
	drawBuilding1_roof_Y(R, G, B, R1, G1, B1);
	glPopMatrix();

	glPushMatrix();
	drawBuilding1_roof_X();
	glPopMatrix();

	glPushMatrix();
	glRotatef(180, 0, 1, 0);
	drawBuilding1_roof_X();
	glPopMatrix();

	glPopMatrix();
}

void drawBuilding1(float R, float G, float B, float R1, float G1, float B1) {
	glPushMatrix();

	glPushMatrix();
	glTranslatef(0, 0, 2);
	drawBuilding_1_Side_X(R, G, B, R1, G1, B1);	
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 0, -2);
	drawBuilding_1_Side_X(R, G, B, R1, G1, B1);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	drawBuilding_1_Side_Y(R, G, B, R1, G1, B1);
	glPopMatrix();

	glPushMatrix();
	glRotatef(-90, 0, 1, 0);
	drawBuilding_1_Side_Y(R, G, B, R1, G1, B1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1, 0);
	drawFloor1();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 2.5, 0);
	drawBuilding1_roof(R, G, B, R1, G1, B1);
	glPopMatrix();

	glPopMatrix();
}