#include <GL/glut.h>  
#include <math.h>
#define pi 3.142857
#include "project.h"

// rotaion varables
GLfloat animXRot, animYRot, animZRot = 0;

//camera variables
GLfloat camX = 0, camY = 0, camZ = 0;

//Crain variables - operating Room
GLfloat crainY = 0;
GLfloat crainWidth = 5;
GLfloat crainArm = 0;

// boa6t variables
GLfloat boatY = 360;

//scene variables
GLfloat sceX = 0, sceY = 0, sceZ = 0;

float gridLimit = 56;



// animated boat variables
float boatFrameNum = 0;
float animatedBoat = 0;
float translateBoat = 0;

// animated crain
float crainFrameNum = 0;
GLfloat animCrainY = 0;
GLfloat animCrainWidth = 5;
GLfloat animCrainArm = 0;

GLfloat animBoxY = 0;
GLfloat animBoxX = 0;
GLfloat animBoxX2 = 0;

GLfloat rotBoxY = 0;


void init() {
    glClearColor(0.149, 0.588, 1, 0.5f);
    //glClearColor(0.2f, 1.0f, 1.0f, 1.0f);
    //glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    //glOrtho(-40, 40, -40, 40, -40, 40);
}

void drawGrid() {
    GLint line;
    GLfloat step = 1.0f;
    

    glLineWidth(2);
    glBegin(GL_LINES);

    for (line = -gridLimit; line <= gridLimit; line += step) {
        glVertex3f(line, 0, gridLimit);
        glVertex3f(line, 0, -gridLimit);

        glVertex3f(gridLimit, 0, line);
        glVertex3f(-gridLimit, 0, line);
    }
    glEnd();

}


void drawAxes() {
    glBegin(GL_LINES);
    glColor3f(1.0, 0, .0);
    glVertex3f(0, 0, gridLimit);
    glVertex3f(0, 0, -gridLimit);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0, 1.0, 0);
    glVertex3f(0, gridLimit, 0);
    glVertex3f(0, -gridLimit, -0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0, 0, 1.0);
    glVertex3f(-gridLimit, 0, 0);
    glVertex3f(gridLimit, 0, 0);
    glEnd();
}

void setLightning() {
    /* set material parameters */
    const GLfloat blue[4] = { 0.3, 0.3, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_DIFFUSE, blue);
    const GLfloat matwhite[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glMaterialfv(GL_FRONT, GL_SPECULAR, matwhite);
    glMaterialf(GL_FRONT, GL_SHININESS, 128.0f);

    /* positioned the light source 1 */
    GLfloat position0[] = { 20.0,20.0,20.0,1.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, position0);

    /* set light intensities for light source 1 */
    GLfloat paleYellow[] = { 1.0,1.0,0.75,1.0 };
    glLightfv(GL_LIGHT0, GL_DIFFUSE, paleYellow);
    GLfloat white[] = { 1.0,1.0,1.0,1.0 };
    glLightfv(GL_LIGHT0, GL_SPECULAR, white);
    glEnable(GL_LIGHT0);

    /* positioned the light source 2 */
    GLfloat position1[] = { -20.0,20.0,-20.0,1.0 };
    glLightfv(GL_LIGHT1, GL_POSITION, position1);

    /* set light intensities for light source 2 */
    glLightfv(GL_LIGHT1, GL_DIFFUSE, paleYellow);
    //GLfloat white[] = { 1.0,1.0,1.0,1.0 };
    glLightfv(GL_LIGHT1, GL_SPECULAR, white);
    glEnable(GL_LIGHT1);
}

void floor() {
    glPushMatrix();

    // back floor - left
    glPushMatrix();
    glTranslatef(-49.5, 0, -30);
    glScalef(1, 2, 1);
    drawFloor(1, 40);
    glPopMatrix();

    // back floor - right
    glPushMatrix();
    glTranslatef(49.5, 0, -30);
    glScalef(1, 2, 1);
    drawFloor(1, 40);
    glPopMatrix();

    // back floor - back
    glPushMatrix();
    glTranslatef(0, 0, -49.5);
    glScalef(1, 2, 1);
    drawFloor(98, 1);
    glPopMatrix();

    // back floor - front
    glPushMatrix();
    glTranslatef(40, 0, -9.5);
    glScalef(1, 2, 1);
    drawFloor(18, 1);
    glPopMatrix();

    // back floor - middle
    glPushMatrix();
    glTranslatef(0, 6.4, 0);
    glColor3f(0.427, 0.353, 0.286);
    glBegin(GL_POLYGON);
    glVertex3f(-50, 0, -50);
    glVertex3f(50, 0, -50);
    glVertex3f(50, 0, -9);
    glVertex3f(-50, 0, -9);
    glEnd();
    glPopMatrix();


    // middle floor
    glPushMatrix();
    glTranslatef(-10, 0, -2.5);
    glScalef(1, 2, 1);
    drawFloor(80, 15);
    glPopMatrix();

    //front floor - right
    glPushMatrix();
    glTranslatef(25, 0, 15);
    glScalef(1, 2, 1);
    drawFloor(10, 20);
    glPopMatrix();

    //front floor - left
    glPushMatrix();
    glTranslatef(-5, 0, 15);
    glScalef(1, 2, 1);
    drawFloor(10, 20);
    glPopMatrix();

    // floor steps
    glPushMatrix();
    glTranslatef(2.6, 0, 12);
    glScalef(1, 2, 1);
    drawFloor(5, 15);
    glPopMatrix();

    // boat house angle
    glPushMatrix();
    drawBoatHouseAngle(5, 16.5, 6, 0, 5, 15);
    glPopMatrix();

    glPopMatrix();
}

void fence() {
    glPushMatrix();
    
    // front floor fence - right - long
    glPushMatrix();
    glTranslatef(31, 8, 7);
    glRotatef(90, 0, 1, 0);
    glScalef(3, 3, 3);
    drawFenceRow(12);
    glPopMatrix();

    // front floor fence - left - long
    glPushMatrix();
    glTranslatef(-10, 8, 7);
    glRotatef(90, 0, 1, 0);
    glScalef(3, 3, 3);
    drawFenceRow(12);
    glPopMatrix();

    // back fence
    glPushMatrix();
    glTranslatef(10.5, 8, -10);
    glScalef(2.9, 3, 3);
    drawFenceRow(14);
    glPopMatrix();

    // front small - left- x
    glPushMatrix();
    glTranslatef(-4.5, 8, 25);
    glScalef(2.6, 3, 3);
    drawFenceRow(4);
    glPopMatrix();

    // front small - right - x
    glPushMatrix();
    glTranslatef(25.5, 8, 25);
    glScalef(2.8, 3, 3);
    drawFenceRow(4);
    glPopMatrix();

    // front small - left - y
    glPushMatrix();
    glTranslatef(1, 8, 23);
    glRotatef(90, 0, 1, 0);
    glScalef(2.6, 3, 3);
    drawFenceRow(2);
    glPopMatrix();

    // front small - right - y
    glPushMatrix();
    glTranslatef(20, 8, 15);
    glRotatef(90, 0, 1, 0);
    glScalef(2.6, 3, 3);
    drawFenceRow(8);
    glPopMatrix();

    // steps
    glPushMatrix();
    glTranslatef(5, 8, 12);
    glRotatef(90, 0, 1, 0);
    glScalef(2.3, 3, 3);
    drawFenceRow(6);
    glPopMatrix();

    glPopMatrix();
}

void gates() {
    glPushMatrix();
    
    glPushMatrix();
    glTranslatef(-4, 7, 22);
    glScalef(1.2, 0.8, 1.2);
    drawGate(-30);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(25, 7, 22);
    glScalef(1.2, 0.8, 1.2);
    drawGate(30);
    glPopMatrix();

    glPopMatrix();
}

// set of boxs
void boxeCollection() {
    glPushMatrix();

    glPushMatrix();
    drawBox();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 4.5);
    drawBox();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -4.5);
    drawBox();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 4.2, -4.5/2);
    drawBox();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 4.2, 4.5 / 2);
    drawBox();
    glPopMatrix();

    glPopMatrix();
}

void boxes() {
    glPushMatrix();

    // boxes in boat house
    glPushMatrix();
    glTranslatef(7.5, 8, 0);
    glScalef(0.5, 0.5, 0.5);
    boxeCollection();
    glPopMatrix();

    // boxes in boat right floor
    glPushMatrix();
    glTranslatef(29.5, 8, 15);
    glScalef(0.5, 0.5, 0.5);
    boxeCollection();
    glPopMatrix();

    // boxes near back building
    glPushMatrix();
    glTranslatef(39.5, 8, -20);
    glScalef(0.5, 0.5, 0.5);
    glRotatef(90, 0, 1, 0);
    boxeCollection();
    glPopMatrix();

    // boxes near back building - right corner
    glPushMatrix();
    glTranslatef(45, 8, -10);
    glScalef(0.5, 0.5, 0.5);
    glRotatef(90, 0, 1, 0);
    boxeCollection();
    glPopMatrix();

    // boxes behind boat house
    glPushMatrix();
    glTranslatef(25, 8, -10);
    glScalef(0.5, 0.5, 0.5);
    glRotatef(90, 0, 1, 0);
    boxeCollection();
    glPopMatrix();

    // boxes left to the boat house
    glPushMatrix();
    glTranslatef(-2, 8, -1);
    glScalef(0.5, 0.5, 0.5);
    glRotatef(90, 0, 1, 0);
    boxeCollection();
    glPopMatrix();

    // boxes left front to the boat house
    glPushMatrix();
    glTranslatef(3.5, 8, 10);
    glScalef(0.5, 0.5, 0.5);
    boxeCollection();
    glPopMatrix();

    //animated box
    glPushMatrix();
    glTranslatef(18.5, 2, 10);
    glScalef(0.5, 0.5, 0.5);
    boxeCollection();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(18.5+animBoxX, 6.25+ animBoxY, 10);
    glScalef(0.5, 0.5, 0.5);
    glTranslatef(-animBoxX2, 0, 0);
    glRotatef(rotBoxY, 0, 1, 0);
    glTranslatef(animBoxX2, 0, 0);
    drawBox();
    glPopMatrix();

    glPopMatrix();
}

void corrido() {
    glPushMatrix();

    // corrido left middle
    glPushMatrix();
    glTranslatef(2.8, 0.5, 20);
    glScalef(0.5, 0.5, 0.5);
    glScalef(2.5, 2, 2);
    drawCorrido(30);
    glPopMatrix();

    // corrido right middle
    glPushMatrix();
    glTranslatef(18.2, 0.5, 20);
    glScalef(0.5, 0.5, 0.5);
    glScalef(2.5, 2, 2);
    drawCorrido(30);
    glPopMatrix();

    // corrido left end
    glPushMatrix();
    glTranslatef(-12, 0.5, 15);
    glScalef(0.5, 0.5, 0.5);
    glScalef(2.5, 2, 2);
    drawCorrido(20);
    glPopMatrix();

    // corrido right end
    glPushMatrix();
    glTranslatef(32.8, 0.5, 7);
    glScalef(0.5, 0.5, 0.5);
    glScalef(2.5, 2, 2);
    drawCorrido(35);
    glPopMatrix();

    glPopMatrix();
}

void steps() {
    glPushMatrix();
    
    // right steps
    glPushMatrix();
    glTranslatef(32.65, 3.5, -7);
    glScalef(2, 1, 1);
    drawSteps(13);
    glPopMatrix();

    // left steps
    glPushMatrix();
    glTranslatef(2.6, 3.5, 20.5);
    glScalef(2, 1, 0.5);
    drawSteps(13);
    glPopMatrix();

    glPopMatrix();
}

void buildings() {
    glPushMatrix();

    // back building
    glPushMatrix();
    glTranslatef(20, 8, -30);
    glScalef(2.5, 2.5, 2.5);
    drawBuildingRow(0.8, 0.5, 0.1, 0.6, 0.275, 0, 3);
    glPopMatrix();

    // green building right
    glPushMatrix();
    glTranslatef(-19, 8, -25);
    glRotatef(90, 0, 1, 0);
    glScalef(5, 2.5, 2.5);
    drawBuilding1(0, 1, 0.063, 0, 0.259, 0.016);
    glPopMatrix();

    // green building left
    glPushMatrix();
    glTranslatef(-38, 8, -25);
    glRotatef(90, 0, 1, 0);
    glScalef(5, 2.5, 2.5);
    drawBuilding1(0, 1, 0.063, 0, 0.259, 0.016);
    glPopMatrix();

    glPopMatrix();
}

//oil galoon
void oilGaloon() {
    glPushMatrix();

    // front
    glPushMatrix();
    glTranslatef(-30, 12, -2);
    glScalef(1.5, 1.5, 1.5);
    drawOilGaloon(1, 3);
    glPopMatrix();

    glPopMatrix();
}

void crains() {
    glPushMatrix();

    // front
    glPushMatrix();
    glTranslatef(-18, 9, -2);
    glScalef(2, 2, 2);
    drawCrain(crainY, crainArm, crainWidth);
    glPopMatrix();

    // animated crain
    glPushMatrix();
    glTranslatef(23, 8.5, 10);
    glScalef(1.5, 1.5, 1.5);
    drawCrain(animCrainY, animCrainArm, animCrainWidth);
    glPopMatrix();

    glPopMatrix();
}

void boats() {
    glPushMatrix();
   
    //boat in boat house
    glPushMatrix();
    glTranslatef(13, 7, -1);
    glScalef(1.4, 1.1, 1);
    drawBoat(1.0, 0.0, 0.0);
    glPopMatrix();

    // left boat 1
    glPushMatrix();
    glTranslatef(-17, 0, 22);
    glScalef(1.5, 1.5, 1.5);
    drawBoat1(1, 0.545, 0);
    glPopMatrix();

    // front boat
    glPushMatrix();
    glTranslatef(14, 0, 25);
    glScalef(1.5, 1.5, 1.5);
    drawBoat(0.024, 0.541, 0);
    glPopMatrix();

    // animated boat
    glPushMatrix();
    glRotatef(-translateBoat, 0, 1, 0);
    glTranslatef(45, 0, 15);
    glRotatef(-50 + animatedBoat, 0, 1, 0);
    glScalef(1.5, 1.5, 1.5);
    drawBoat(0.678, 0, 0.769);
    glPopMatrix();

    glPopMatrix();
}

void vehicles() {
    glPushMatrix();
    glTranslatef(30, 6.5, -15);
    drawVehicle(1, 0, 0);
    glPopMatrix();
}

void bushes() {
    glPushMatrix();
    glTranslatef(-43, 7, 0);
    glScalef(2, 1.5, 2);
    drawBush(0.2, 4);
    glPopMatrix();
}

void displayScene() {
    glPushMatrix();

    // sea
    glPushMatrix();
    drawSea(gridLimit);
    glPopMatrix();

    // floor
    glPushMatrix();
    floor();
    glPopMatrix();

    // fence
    glPushMatrix();
    fence();
    glPopMatrix();    

    // buildings
    glPushMatrix();
    buildings();
    glPopMatrix();

    // boat house
    glPushMatrix();
    glTranslatef(11, 10, -2);
    glScalef(3.5, 2.5, 3);
    drawBoatHouse(0.8, 0.5, 0.1);
    glPopMatrix();

    // boat in boat house
    glPushMatrix();
    boats();
    glPopMatrix();

    // gates
    glPushMatrix();
    gates();
    glPopMatrix();

    // boxes
    glPushMatrix();
    boxes();
    glPopMatrix();

    // corrido
    glPushMatrix();
    corrido();
    glPopMatrix();

    // steps
    glPushMatrix();
    steps();
    glPopMatrix();

    // oil galoon
    glPushMatrix();
    oilGaloon();
    glPopMatrix();

    // crains
    glPushMatrix();
    crains();
    glPopMatrix();

    // vehicles
    glPushMatrix();
    vehicles();
    glPopMatrix();

    // Bush
    glPushMatrix();
    bushes();
    glPopMatrix();


    glPopMatrix();
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(37 + camX, 20 + camY, 30 + camZ, 0, 0, 0, 0, 1, 0);
    setLightning();

    glTranslatef(sceX, sceY, sceZ);
    glRotatef(animYRot, 0, 1, 0);
    glPushMatrix();
    //drawAxes();

    glPushMatrix();
    glColor3f(0.0, 0.2, 0.9);
    //drawGrid();
    //drawSea();
    glPopMatrix();


    glPushMatrix();
    //drawBoat(1.0, 0.0, 0.0);
    //drawBoat1(1.0, 0.0, 0.0);
    //glScalef(1, 1, 2);
    //glTranslatef(0, 1.5, 0);
    //drawCrain(crainY, crainArm, crainWidth);
    //drawBoatHouse(0.8, 0.5, 0.1);
    //drawBox();
    //drawBuildingRow(0.8, 0.5, 0.1, 0.6, 0.275, 0, 5);
    //drawBuilding1(0, 1, 0.063, 0, 0.259, 0.016);  // colors - middle color, edge color
    //drawGate(30); // 30 = angle
    //glScalef(2, 1, 1);
    //drawSteps(10);
    //drawOilGaloon(1, 3);
    //drawCorrido(10);
    //drawSea(gridLimit);
    //drawFenceRow(6);
    //drawFloor(6, 5);
    //boxes();
    //drawVehicle(0, 0, 1);
    //drawBush(0.2, 4.5);

    displayScene();
    

    glPopMatrix(); 

    glPopMatrix();

    glutSwapBuffers();
    glFlush();
}

// animation timer function
void Timer(int v) {
    boatFrameNum++;
    if (boatFrameNum < 145) {
        if (boatFrameNum < 20) {
            animatedBoat++;
        }
        if( boatFrameNum > 135){
            animatedBoat --;
        }

        translateBoat++;
    }

    if (boatFrameNum > 160 && boatFrameNum < 190) {
        animatedBoat -=5;
    }

    if (boatFrameNum > 200 && boatFrameNum < 345) {
        if (boatFrameNum < 220) {
            animatedBoat--;
        }
        if (boatFrameNum > 335) {
            animatedBoat++;
        }

        translateBoat--;
    }

    if (boatFrameNum == 380) {
        boatFrameNum = 0;
        translateBoat = 0;
        animatedBoat = 0;
    }

    // animated crain
    crainFrameNum++;
    if (crainFrameNum < 90) {
        animCrainY--;
    }

    if (crainFrameNum > 100 && crainFrameNum < 115) {
        animCrainWidth-=0.125;
    }

    if (crainFrameNum > 130 && crainFrameNum < 160) {
        animCrainArm --;
    }

    if (crainFrameNum > 170 && crainFrameNum < 235) {
        animCrainArm++;
        animBoxY += 0.08;
    }

    if (crainFrameNum > 245 && crainFrameNum < 255) {
        animCrainWidth += 0.125;
        animBoxX -= 0.125/2;
    }

    if (crainFrameNum > 265 && crainFrameNum < 355) {
        animCrainY++;
        animBoxX2 = animBoxX- 2*crainWidth;
        rotBoxY++;
        
    }

    if (crainFrameNum > 375 && crainFrameNum < 423) {
        animCrainArm--;
        animBoxY -= 0.08;

    }

    if (crainFrameNum == 435) {
        crainFrameNum = 0;
        animCrainY = 0;
        animCrainWidth = 5;
        animCrainArm = 0;

        animBoxY = 0;
        animBoxX = 0;
        animBoxX2 = 0;

        rotBoxY = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(30, Timer, 0);
}

// keyboardSpecial
void keyboardSpecial(int key, int x, int y) {
    // camera up and down
    if (key == GLUT_KEY_UP) {
        camY += 1;
    }
    if (key == GLUT_KEY_DOWN) {
         camY -= 1;
    }

    // camera left and right
    if (key == GLUT_KEY_LEFT) {
        camX -= 1;
    }
    if (key == GLUT_KEY_RIGHT) {
        camX += 1;
    }

    glutPostRedisplay();
}

// keyboard move object 
void keyboard(unsigned char key, int x, int y) {
    // rotate snow man
    if (key == 'l') {
        animYRot -= 1;
    }
    if (key == 'r') {
        animYRot += 1;
    }

    // operating room
    if (key == 'C') {
        if (crainY == 360) {
            crainY = 0;
        }
        else {
            crainY += 1;
        }
    }
    if (key == 'c') {
        if (crainY == 0) {
            crainY = 360;
        }
        else {
            crainY -= 1;
        }
    }

    // Crain arm
    if (key == 'a') {
        if (crainArm >= 35) {
            crainArm = 35;
        }
        else {
            crainArm += 1;
        }
    }
    if (key == 'A') {
        if (crainArm <= -35) {
            crainArm = -35;
        }
        else {
            crainArm -= 1;
        }
    }
    if (key == 'w') {
        if (crainWidth >= 9) {
            crainWidth = 9;
        }
        else {
            crainWidth += 0.02;
        }
    }
    if (key == 'W') {
        if (crainWidth <= 5.5) {
            crainWidth = 5.5;
        }
        else {
            crainWidth -= 0.02;
        }
    }

    // Move Scene along X axis
    if (key == 'X') {
        sceX -= 1;
    }
    if (key == 'x') {
        sceX += 1;
    }
    // Move Scene along Y axis
    if (key == 'Y') {
        sceY -= 1;
    }
    if (key == 'y') {
        sceY += 1;
    }
    //Move Scene along Z axis
    if (key == 'Z') {
        sceZ -= 1;
    }
    if (key == 'z') {
        sceZ += 1;
    }

    // Control light source 1
    if (key == '1') {
        glEnable(GL_LIGHT0);
    }
    if (key == '!') {
        glDisable(GL_LIGHT0);
    }

    // Control light source 2
    if (key == '2') {
        glEnable(GL_LIGHT1);
    }
    if (key == '@') {
        glDisable(GL_LIGHT1);
    }

    glutPostRedisplay();
}


void reshape(GLsizei w, GLsizei h) {
    glViewport(0, 0, w, h);
    GLfloat aspect_ratio = h == 0 ? w / 1 : (GLfloat)w / (GLfloat)h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(90.0, aspect_ratio, 1.0, 100.0);

}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(150, 150);
    glutCreateWindow("S17426 Project GTA ViceCity");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    // keyboard function activation
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(keyboardSpecial);

    glutTimerFunc(30, Timer, 0);

    glutMainLoop();

    return 0;
}