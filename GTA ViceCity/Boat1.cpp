#include "project.h"
#include <GL/glut.h>  
#include <math.h>
#define pi 3.142857


void drawWindSqure1() {
    // middle lines
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(0, 1, 0);
    glutSolidCone(0.13, 5, 100, 100);
    glutSolidSphere(0.13, 100, 100);
    glPopMatrix();
}

void drawWindBrcakets1() {
    glColor3f(0.0, 0.0, 0);
    drawWindSqure1();
}


void drawBoatTop1(float R, float G, float B) {
    glColor3f(R, G, B);
    glBegin(GL_POLYGON);
    for (float i = -3; i <= 3; i += 0.01) {
        float j = -pow(i, 2);
        j = j + 5;
        if (j >= 0) {
            glVertex3f(i, 1, j);
        }
    }
    glEnd();

    // back
    glBegin(GL_POLYGON);
    glVertex3f(-3, 1, -4);
    glVertex3f(3, 1, -4);
    glVertex3f(2.8, 1, -2.84);
    glVertex3f(-2.8, 1, -2.84);
    glEnd();

    //left
    glBegin(GL_POLYGON);
    for (float i = -2.8; i <= -2; i += 0.01) {
        float j = -pow(i, 2);
        j = j + 5;
        if (-2.84 <= j && j <= 0.1) {
            glVertex3f(i, 1, j);
        }
    }
    glVertex3f(-1.7, 1, 0.1);
    glVertex3f(-2.3, 1, -2.84);
    glEnd();

    //right
    glBegin(GL_POLYGON);
    glVertex3f(2.3, 1, -2.84);
    glVertex3f(1.7, 1, 0.1);

    for (float i = 2; i <= 2.8; i += 0.01) {
        float j = -pow(i, 2);
        j = j + 5;
        if (-2.84 <= j && j <= 0.1) {
            glVertex3f(i, 1, j);
        }
    }
    glEnd();

    drawWindBrcakets1();
}

void drawBoatSideRectangle1(float x1, float boatHeight) {

    glBegin(GL_POLYGON);
    float x2 = x1 + 0.01;
    float z1 = -pow(x1, 2) + 5;
    float z2 = -pow(x2, 2) + 5;

    glVertex3f(x1, 1, z1);
    glVertex3f(x2, 1, z2);

    glVertex3f(0, boatHeight, z2);
    glVertex3f(0, boatHeight, z1);

    glEnd();
}

void drawBoatSide1(float boatHeight, float R, float G, float B) {
    glColor3f((R - 0.2), G, B);
    for (float i = 0; i <= 2.99; i += 0.01) {
        drawBoatSideRectangle1(i, boatHeight);
    }

    glColor3f((R - 0.4), G, B);
    for (float i = -3; i <= -0.01; i += 0.01) {
        drawBoatSideRectangle1(i, boatHeight);
    }
}

void drawEngine() {

}

void drawBoatBack1(float boatHeight, float R, float G, float B, float depth) {
    glPushMatrix();
    // body
    glPushMatrix();
    glColor3f((R - 0.6), G, B);
    glBegin(GL_POLYGON);
    glVertex3f(-3, 1, -4);
    glVertex3f(3, 1, -4);
    glVertex3f(0, boatHeight, -4);
    glEnd();
    glPopMatrix();

    // tube - right
    glPushMatrix();
    glColor3f(0, 0, 0);
    glTranslatef(1.5, 1, -2.54);
    glutSolidTorus(0.15, 0.3, 100, 100);
    glPopMatrix();

    

    glPopMatrix();
}





void drawControlRoomTopBorders1() {
    //left
    glBegin(GL_POLYGON);
    glVertex3f(-2.3, 1, -2.84);
    glVertex3f(-2, 1, -2.64);
    glVertex3f(-1.5, 1, -0.2);
    glVertex3f(-1.8, 1, 0.1);
    glEnd();

    //right
    glBegin(GL_POLYGON);
    glVertex3f(2.3, 1, -2.84);
    glVertex3f(2, 1, -2.64);
    glVertex3f(1.5, 1, -0.2);
    glVertex3f(1.8, 1, 0.1);
    glEnd();

    //back
    glBegin(GL_POLYGON);
    glVertex3f(-2.3, 1, -2.84);
    glVertex3f(-2, 1, -2.64);
    glVertex3f(2, 1, -2.64);
    glVertex3f(2.3, 1, -2.84);
    glEnd();

    //front
    glBegin(GL_POLYGON);
    glVertex3f(-1.5, 1, -0.2);
    glVertex3f(-1.8, 1, 0.1);
    glVertex3f(1.8, 1, 0.1);
    glVertex3f(1.5, 1, -0.2);
    glEnd();

    // front glass
    glPushMatrix();
    glColor4f(0, 0, 0, 0.7);

    glBegin(GL_POLYGON);
    glVertex3f(-1.4, 2, -0.25);
    glVertex3f(-1.6, 1.5, -0.15);
    glVertex3f(-1.8, 1, 0.1);
    glVertex3f(1.8, 1, 0.1);
    glVertex3f(1.6, 1.5, -0.15);
    glVertex3f(1.4, 2, -0.25);
    glEnd();
    //glDisable(GL_BLEND);
    glPopMatrix();
}

void drawControlRoomWalls1(float depth) {
    glColor3f(0.7, 0.7, 0.7);
    //back
    glBegin(GL_POLYGON);
    glVertex3f(-2, 1, -2.64);
    glVertex3f(2, 1, -2.64);
    glVertex3f(1.9, depth, -2.54);
    glVertex3f(-1.9, depth, -2.54);
    glEnd();

    //front
    glColor3f(0.55, 0.55, 0.55);
    glBegin(GL_POLYGON);
    glVertex3f(2, 1, -2.64);
    glVertex3f(1.9, depth, -2.54);
    glVertex3f(1.4, depth, -0.3);
    glVertex3f(1.5, 1, -0.2);
    glEnd();

    //right
    glColor3f(0.65, 0.65, 0.65);
    glBegin(GL_POLYGON);
    glVertex3f(1.4, depth, -0.3);
    glVertex3f(1.5, 1, -0.2);
    glVertex3f(-1.5, 1, -0.2);
    glVertex3f(-1.4, depth, -0.3);
    glEnd();

    //left
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_POLYGON);
    glVertex3f(-2, 1, -2.64);
    glVertex3f(-1.9, depth, -2.54);
    glVertex3f(-1.4, depth, -0.3);
    glVertex3f(-1.5, 1, -0.2);
    glEnd();

    //floor
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);
    glVertex3f(-1.9, depth, -2.54);
    glVertex3f(1.9, depth, -2.54);
    glVertex3f(1.4, depth, -0.3);
    glVertex3f(-1.4, depth, -0.3);
    glEnd();
}

void drawSingleSeat1() {
    glPushMatrix();
    glPushMatrix();
    glColor3f(0.65, 0.65, 0);
    glTranslatef(0, 1.4, -0.25);
    glScalef(0.15, 0.15, 0.05);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.6, 0.6, 0);
    glTranslatef(0, 0.65, -0.25);
    glScalef(0.3, 0.6, 0.05);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5, 0.5, 0);
    glScalef(0.3, 0.05, 0.3);
    glutSolidCube(2);
    glPopMatrix();
    glPopMatrix();
}

void drawSeats1(float depth) {
    glPushMatrix();
    glTranslatef(0.7, depth, -1.2);
    drawSingleSeat1();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.7, depth, -1.2);
    drawSingleSeat1();
    glPopMatrix();
}

void drawSteeringWheel1() {

    glPushMatrix();
    glColor3f(0, 0, 0);
    glPushMatrix();
    glRotatef(30, 1, 0, 0);
    float r = 0.3;
    float x, y, i;
    glBegin(GL_POLYGON);
    for (i = 0; i < (2 * pi); i += 0.001) {
        x = r * cos(i);
        y = r * sin(i);

        glVertex3f(x, y, 0);
    }
    glEnd();
    glPopMatrix();

    glLineWidth(5);
    glBegin(GL_LINES);

    glVertex3f(0, 0, 0);
    glVertex3f(0, -0.5, 0.5);
    glEnd();
    glLineWidth(1);

    glPopMatrix();
}

void drawControlRoom1(float depth) {
    glColor3f(1.0, 1.0, 1.0);
    drawControlRoomTopBorders1();
    drawControlRoomWalls1(depth);
    drawSeats1(depth);
    glPushMatrix();
    glTranslatef(0.7, 1.2, -0.8);
    drawSteeringWheel1();
    glPopMatrix();
}


void drawBoat1(float R, float G, float B) {
    float boatHeight = -1;
    float depth = 0.5;

    glScalef(0.8, 0.8, 0.9);
    glPushMatrix();
    drawBoatTop1(R, G, B);

    drawBoatSide1(boatHeight, R, G, B);

    drawBoatBack1(boatHeight, R, G, B, depth);

    drawControlRoom1(depth);

    glPopMatrix();
}


