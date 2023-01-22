#include "project.h"
#include <GL/glut.h>  
#include <math.h>
#define pi 3.142857


void drawWindSqure() {
    glLineWidth(7);
    glBegin(GL_LINES);
    for (float i = 1; i <= 2; i += 0.25) {
        glVertex3f(-1.2, 1, i);
        glVertex3f(-0.4, 1, i);

        glVertex3f(1.2, 1, i);
        glVertex3f(0.4, 1, i);
    }

    glVertex3f(1.2, 1, 1);
    glVertex3f(1.2, 1, 2);

    glVertex3f(0.4, 1, 1);
    glVertex3f(0.4, 1, 2);

    glVertex3f(-1.2, 1, 1);
    glVertex3f(-1.2, 1, 2);

    glVertex3f(-0.4, 1, 1);
    glVertex3f(-0.4, 1, 2);
    glEnd();
}

void drawWindBrcakets() {
    glColor3f(0.0, 0.0, 0);
    drawWindSqure();
}


void drawBoatTop(float R, float G, float B) {
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
        if (-2.84<=j && j <= 0.1) {
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
    
    drawWindBrcakets();
}

void drawBoatSideRectangle(float x1, float boatHeight) {
    
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

void drawBoatSide(float boatHeight, float R, float G, float B) {
    glColor3f((R-0.2), G, B);
    for (float i = 0; i <= 2.99; i += 0.01) {
        drawBoatSideRectangle(i, boatHeight);
    }

    glColor3f((R - 0.4), G, B);
    for (float i = -3; i <= -0.01; i += 0.01) {
        drawBoatSideRectangle(i, boatHeight);
    }
}

void drawBoatBack(float boatHeight, float R, float G, float B) {
    glColor3f((R - 0.6), G, B);
    glBegin(GL_POLYGON);
    glVertex3f(-3, 1, -4);
    glVertex3f(3, 1, -4);
    glVertex3f(0, boatHeight, -4);
    glEnd();
}



void drawSpoiler(float R, float G, float B) {
    glColor3f(0.5, 0.5, 0.5);
    // right arm
    //front
    glBegin(GL_POLYGON);
    glVertex3f(2.05, 1, -1);
    glVertex3f(2.35, 1, -1);
    glVertex3f(2.3, 3, -3);
    glVertex3f(2.1, 3, -3);
    glEnd();

    //right
    glBegin(GL_POLYGON);
    glVertex3f(2.35, 1, -1);
    glVertex3f(2.55, 1, -2);
    glVertex3f(2.5, 3, -3.5);
    glVertex3f(2.3, 3, -3);
    glEnd();

    //back
    glBegin(GL_POLYGON);
    glVertex3f(2.25, 1, -2);
    glVertex3f(2.55, 1, -2);
    glVertex3f(2.5, 3, -3.5);
    glVertex3f(2.3, 3, -3.5);
    glEnd();

    //left
    glBegin(GL_POLYGON);
    glVertex3f(2.05, 1, -1);
    glVertex3f(2.25, 1, -2);
    glVertex3f(2.3, 3, -3.5);
    glVertex3f(2.1, 3, -3);
    glEnd();

    // left arm
    //front
    glBegin(GL_POLYGON);
    glVertex3f(-2.05, 1, -1);
    glVertex3f(-2.35, 1, -1);
    glVertex3f(-2.3, 3, -3);
    glVertex3f(-2.1, 3, -3);
    glEnd();

    //right
    glBegin(GL_POLYGON);
    glVertex3f(-2.35, 1, -1);
    glVertex3f(-2.55, 1, -2);
    glVertex3f(-2.5, 3, -3.5);
    glVertex3f(-2.3, 3, -3);
    glEnd();

    //back
    glBegin(GL_POLYGON);
    glVertex3f(-2.25, 1, -2);
    glVertex3f(-2.55, 1, -2);
    glVertex3f(-2.5, 3, -3.5);
    glVertex3f(-2.3, 3, -3.5);
    glEnd();

    //left
    glBegin(GL_POLYGON);
    glVertex3f(-2.05, 1, -1);
    glVertex3f(-2.25, 1, -2);
    glVertex3f(-2.3, 3, -3.5);
    glVertex3f(-2.1, 3, -3);
    glEnd();

    //top arm
    glColor3f((R - 0.2), G, B);
    //right
    glBegin(GL_POLYGON);
    glVertex3f(2.3, 3, -3);
    glVertex3f(2.5, 3, -3.5);
    glVertex3f(2.3, 3.2, -3.5);
    glVertex3f(2.1, 3.2, -3);
    glEnd();

    //left
    glBegin(GL_POLYGON);
    glVertex3f(-2.3, 3, -3);
    glVertex3f(-2.5, 3, -3.5);
    glVertex3f(-2.3, 3.2, -3.5);
    glVertex3f(-2.1, 3.2, -3);
    glEnd();

    //top
    glBegin(GL_POLYGON);
    glVertex3f(2.3, 3.2, -3.5);
    glVertex3f(2.1, 3.2, -3);
    glVertex3f(-2.1, 3.2, -3);
    glVertex3f(-2.3, 3.2, -3.5);
    glEnd();

    //bottom
    glBegin(GL_POLYGON);
    glVertex3f(2.3, 3, -3);
    glVertex3f(2.5, 3, -3.5);
    glVertex3f(-2.5, 3, -3.5);
    glVertex3f(-2.3, 3, -3);
    glEnd();

    //front
    glBegin(GL_POLYGON);
    glVertex3f(2.3, 3, -3);
    glVertex3f(2.1, 3.2, -3);
    glVertex3f(-2.1, 3.2, -3);
    glVertex3f(-2.3, 3, -3);
    glEnd();

    //back
    glBegin(GL_POLYGON);
    glVertex3f(2.3, 3.2, -3.5);
    glVertex3f(2.5, 3, -3.5);
    glVertex3f(-2.5, 3, -3.5);
    glVertex3f(-2.3, 3.2, -3.5);
    glEnd();
}

void drawControlRoomTopBorders() {
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
}

void drawControlRoomWalls(float depth) {    
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

void drawSingleSeat() { 
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

void drawSeats(float depth) {
    glPushMatrix();
    glTranslatef(0.7, depth, -1.2);
    drawSingleSeat();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.7, depth, -1.2);
    drawSingleSeat();
    glPopMatrix();
}

void drawSteeringWheel() {
    
    glPushMatrix();
    glColor3f(0,0,0);
    glPushMatrix();
    glRotatef(30, 1, 0, 0);
    float r = 0.3;
    float x, y, i;
    glBegin(GL_POLYGON);
    for (i = 0; i < (2 * pi); i += 0.001){
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

    glPopMatrix();
}

void drawControlRoom(float depth) {
    glColor3f(1.0, 1.0, 1.0);
    drawControlRoomTopBorders();
    drawControlRoomWalls(depth);
    drawSeats(depth);
    glPushMatrix();
    glTranslatef(0.7, 1.2, -0.8);
    drawSteeringWheel();
    glPopMatrix();
}


void drawBoat(float R, float G, float B) {
    float boatHeight = -1;
    float depth = 0.5;

    glScalef(0.8, 0.8, 0.9);
    glPushMatrix();
    drawBoatTop(R,G,B);

    drawBoatSide(boatHeight, R, G, B);

    drawBoatBack(boatHeight, R, G, B);

    drawControlRoom(depth);

    drawSpoiler(R, G, B);

    glPopMatrix();
}


