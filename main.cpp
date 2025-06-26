#include <windows.h> // for MS Windows
#include <GL/glut.h> // GLUT, include glu.h and gl.h
#include<math.h>>
#include <cmath>
#include <cstdlib> // For rand() and RAND_MAX

#include <stdlib.h>
#include <time.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

#define PI 3.14159265358979323846
#define MAX_STARS 100
#define MAX_RAIN 200


typedef enum {
    COVER_PAGE,     // New state for the initial cover page
    INSTRUCTIONS,
    SCENARIO_1,
    SCENARIO_2,
    SCENARIO_3,
    SCENARIO_4,
    SCENARIO_5,
    OPTIONS         // This state is defined but not currently triggered by a key
} ScenarioState;

// Global variable to keep track of the current active page/scenario
ScenarioState currentScenarioState = COVER_PAGE; // Start the application on the cover page

// Function to mark the current window as needing to be redisplayed


void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}
void renderBitmapString(float x,float y, void *font, char *string)
{
    char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}


void renderCenteredString(float x, float y,  void *font, char *string)
{
    renderBitmapString(x,y,font,string);
}

void horizontal_Line(float x1, float y1, float x2, float y2)
{
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}
void verticle_Line(float x1, float y1, float x2, float y2)
{
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}


///====================Cover Page========================================
void display_CoverPage()
{
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to white and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)


    glColor3f(0.0f, 0.0f, 0.0f);
    ///-------Centered information------
    renderCenteredString(330, 680, GLUT_BITMAP_TIMES_ROMAN_24, "American International University-Bangladesh");
    renderCenteredString(425, 620, GLUT_BITMAP_HELVETICA_18, "Faculty of Science & Technology");
    renderCenteredString(424, 590, GLUT_BITMAP_HELVETICA_18, "Department of Computer Science");
    renderCenteredString(445, 560, GLUT_BITMAP_HELVETICA_18, "CSE-4118: Computer Graphics");
    glColor3f(0.0f, 0.0f, 1.0f);
    renderCenteredString(500, 530, GLUT_BITMAP_HELVETICA_18, "Spring 2024-25");
    renderCenteredString(440, 500, GLUT_BITMAP_HELVETICA_18, "Section: J , Group Number: 03");
    glColor3f(0.0f, 0.0f, 0.0f);
    renderCenteredString(515, 460, GLUT_BITMAP_HELVETICA_18, "Submitted to");
    renderCenteredString(500, 430, GLUT_BITMAP_HELVETICA_18, "Mahfujur Rahman");
    renderCenteredString(445, 390, GLUT_BITMAP_HELVETICA_18, "Submission Date: 26/06/2025");
    renderCenteredString(200, 350, GLUT_BITMAP_HELVETICA_18, "Submitted by:");

    ///-----Box-----------
    horizontal_Line(200,340,950,340);
    horizontal_Line(200,300,950,300);
    horizontal_Line(200,260,950,260);
    horizontal_Line(200,220,950,220);
    horizontal_Line(200,180,950,180);
    horizontal_Line(200,140,950,140);
    horizontal_Line(200,100,950,100);

    verticle_Line(200,340,200,100);
    verticle_Line(300,340,300,100);
    verticle_Line(650,340,650,100);
    verticle_Line(830,340,830,100);
    verticle_Line(950,340,950,100);

    ///-------Centered information------
    renderCenteredString(225, 315, GLUT_BITMAP_HELVETICA_18, "Serial");
    renderCenteredString(450, 315, GLUT_BITMAP_HELVETICA_18, "Name");
    renderCenteredString(730, 315, GLUT_BITMAP_HELVETICA_18, "ID");
    renderCenteredString(840, 315, GLUT_BITMAP_HELVETICA_18, "Contribution");

    ///member 1
    renderCenteredString(240, 275, GLUT_BITMAP_HELVETICA_18, "2");
    renderCenteredString(370, 275, GLUT_BITMAP_HELVETICA_18, "NOWRIN BINTA RASHID");
    renderCenteredString(685, 275, GLUT_BITMAP_HELVETICA_18, "21-45957-3");
    renderCenteredString(870, 275, GLUT_BITMAP_HELVETICA_18, "20%");

    ///member 2
    renderCenteredString(235, 235, GLUT_BITMAP_HELVETICA_18, "36");
    renderCenteredString(370, 235, GLUT_BITMAP_HELVETICA_18, "M.A SALEHIN");
    renderCenteredString(685, 235, GLUT_BITMAP_HELVETICA_18, "23-51157-1");
    renderCenteredString(870, 235, GLUT_BITMAP_HELVETICA_18, "20%");

    ///member 3
    renderCenteredString(235, 195, GLUT_BITMAP_HELVETICA_18, "38");
    renderCenteredString(370, 195, GLUT_BITMAP_HELVETICA_18, "TUTUL MAJUMDER");
    renderCenteredString(685, 195, GLUT_BITMAP_HELVETICA_18, "23-51364-1");
    renderCenteredString(870, 195, GLUT_BITMAP_HELVETICA_18, "20%");

    ///member 4
    renderCenteredString(235, 155, GLUT_BITMAP_HELVETICA_18, "39");
    renderCenteredString(370, 155, GLUT_BITMAP_HELVETICA_18, "ANAY SARKER");
    renderCenteredString(685, 155, GLUT_BITMAP_HELVETICA_18, "23-51371-1");
    renderCenteredString(870, 155, GLUT_BITMAP_HELVETICA_18, "20%");

    ///member 5
    renderCenteredString(235, 115, GLUT_BITMAP_HELVETICA_18, "40");
    renderCenteredString(370, 115, GLUT_BITMAP_HELVETICA_18, "ARNOB AICH ANURAG");
    renderCenteredString(685, 115, GLUT_BITMAP_HELVETICA_18, "23-51390-1");
    renderCenteredString(870, 115, GLUT_BITMAP_HELVETICA_18, "20%");


    /// ----Instruction ----
    renderCenteredString(970, 50, GLUT_BITMAP_HELVETICA_18, "For I, instruction");
    glFlush(); // Render now
}

///---------Instruction Page Display Function----------
void display_InstructionPage()
{
    glClearColor(0.2f, 0.3f, 0.4f, 1.0f); // Set background color to a dark blue/grey
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer

    // Draw menu text in white
    glColor3f(1.0f, 1.0f, 1.0f);
    renderCenteredString(480, 500, GLUT_BITMAP_HELVETICA_18, "INSTRUCTION");
    renderCenteredString(480, 450, GLUT_BITMAP_HELVETICA_18, "Press 1 for Scenario 1");
    renderCenteredString(480, 400, GLUT_BITMAP_HELVETICA_18, "Press 2 for Scenario 2");
    renderCenteredString(480, 350, GLUT_BITMAP_HELVETICA_18, "Press 3 for Scenario 3");
    renderCenteredString(480, 300, GLUT_BITMAP_HELVETICA_18, "Press 4 for Scenario 4");
    renderCenteredString(480, 250, GLUT_BITMAP_HELVETICA_18, "Press 5 for Scenario 5");
    renderCenteredString(480, 200, GLUT_BITMAP_HELVETICA_18,  "Press ESC to Exit"); // Added instruction

    glutSwapBuffers(); // Swap the front and back buffers
}





///=============================Arnob=========================

float cloudPosition = 0.0f;
float sunPosition = 350.0f;
bool sunMovingUp = true;
float cloudDirection = 1.0f;
float sunDirection = 1.0f;
bool isNightMode = false;
bool birdsAnimating = true;
bool cloudsAnimating = true;
bool sunAnimating = true;
struct Bird {
    float x;
    float y;
    float speedX;
    float speedY;
    unsigned char r;
    unsigned char g;
    unsigned char b;
};
const int NUM_BIRDS = 4;
Bird birds[NUM_BIRDS];
unsigned char randomColor() {
    return rand() % 256;
}
void initializeBirds() {
    birds[0] = {0.0f, 100.0f, 2.0f, 1.5f, randomColor(), randomColor(), randomColor()};
    birds[1] = {0.0f, 200.0f, 2.0f, 1.0f, randomColor(), randomColor(), randomColor()};
    birds[2] = {1150.0f, 300.0f, -2.0f, 1.5f, randomColor(), randomColor(), randomColor()};
    birds[3] = {1150.0f, 400.0f, -2.0f, 1.0f, randomColor(), randomColor(), randomColor()};
}

void updateBirds(int value) {
    if (birdsAnimating) {
        for (int i = 0; i < NUM_BIRDS; i++) {
            birds[i].x += birds[i].speedX;
            birds[i].y += birds[i].speedY;
            if (birds[i].x < 0.0f || birds[i].x > 1150.0f || birds[i].y > 750.0f) {
                birds[i].x = (birds[i].speedX > 0) ? 0.0f : 1150.0f;
                birds[i].y = rand() % 600;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(20, updateBirds, 0);
}
void updateCloud(int value) {
    if (cloudsAnimating) {
        cloudPosition += 1.9f * cloudDirection;
        if (cloudPosition > 800.0f) {
            cloudPosition = -600.0f;
        } else if (cloudPosition < -600.0f) {
            cloudPosition = 800.0f;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(20, updateCloud, 0);
}

// Modified updateSun function
void updateSun(int value) {
    if (sunAnimating) {
        sunPosition += 1.5f * sunDirection;
        if (sunPosition > 760.0f) {
            sunPosition = 350.0f;
        } else if (sunPosition < 350.0f) {
            sunPosition = 760.0f;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(20, updateSun, 0);
}





void drawBird(float x, float y, float scale, unsigned char r, unsigned char g, unsigned char b, bool isMovingLeft, float wingAngle) {
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(r, g, b);
    glVertex2f(x, y);
    int triangleAmount = 100;
    float twicePi = 2.0f * PI;
    for (int i = 0; i <= triangleAmount; i++) {
        float angle = i * twicePi / triangleAmount;
        float xOffset = isMovingLeft ? -1 : 1;
        glVertex2f(x + (scale * 20.0f * xOffset) * cos(angle), y + (scale * 10.0f * sin(angle)));
    }
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(r, g, b);
    glVertex2f(x + (isMovingLeft ? -scale * 20.0f : scale * 20.0f), y + scale * 5.0f);
    for (int i = 0; i <= triangleAmount; i++) {
        float angle = i * twicePi / triangleAmount;
        glVertex2f(x + (isMovingLeft ? -scale * 20.0f : scale * 20.0f) + (scale * 8.0f * cos(angle)),
                   y + scale * 5.0f + (scale * 8.0f * sin(angle)));
    }
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(255, 165, 0);
    glVertex2f(x + (isMovingLeft ? -scale * 20.0f : scale * 20.0f), y + scale * 5.0f);
    glVertex2f(x + (isMovingLeft ? -scale * 30.0f : scale * 30.0f), y + scale * 8.0f);
    glVertex2f(x + (isMovingLeft ? -scale * 30.0f : scale * 30.0f), y + scale * 2.0f);
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 255, 255);
    glVertex2f(x + (isMovingLeft ? -scale * 22.0f : scale * 22.0f), y + scale * 7.0f);
    for (int i = 0; i <= triangleAmount; i++) {
        float angle = i * twicePi / triangleAmount;
        glVertex2f(x + (isMovingLeft ? -scale * 22.0f : scale * 22.0f) + (scale * 2.0f * cos(angle)),
                   y + scale * 7.0f + (scale * 2.0f * sin(angle)));
    }
    glEnd();
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(x + (isMovingLeft ? -scale * 22.0f : scale * 22.0f), y + scale * 7.0f);
    for (int i = 0; i <= triangleAmount; i++) {
        float angle = i * twicePi / triangleAmount;
        glVertex2f(x + (isMovingLeft ? -scale * 22.0f : scale * 22.0f) + (scale * 1.0f * cos(angle)),
                   y + scale * 7.0f + (scale * 1.0f * sin(angle)));
    }
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(r - 20, g - 20, b - 20);
    glVertex2f(x + (isMovingLeft ? -scale * 5.0f : scale * 5.0f), y + scale * 2.0f);
    glVertex2f(x + (isMovingLeft ? scale * 5.0f : -scale * 5.0f), y + scale * 2.0f);
    float flapOffset = scale * 5.0f * sin(wingAngle);
    glVertex2f(x, y + scale * (10.0f + flapOffset));
    glEnd();

    float tailBaseX = x + (isMovingLeft ? scale * 20.0f : -scale * 20.0f);
    glBegin(GL_LINES);
    glColor3ub(r - 30, g - 30, b - 30);
    glVertex2f(tailBaseX, y);
    glVertex2f(tailBaseX + (isMovingLeft ? scale * 15.0f : -scale * 15.0f), y);
    glVertex2f(tailBaseX, y);
    glVertex2f(tailBaseX + (isMovingLeft ? scale * 12.0f : -scale * 12.0f), y - scale * 5.0f);
    glVertex2f(tailBaseX, y);
    glVertex2f(tailBaseX + (isMovingLeft ? scale * 12.0f : -scale * 12.0f), y + scale * 5.0f);
    glEnd();
}

void drawBirds() {
    if (isNightMode) return; // Skip drawing birds in night mode
    static float wingAngle = 0.0f;
    wingAngle += 0.1f;
    if (wingAngle > 2 * PI) wingAngle -= 2 * PI;
    for (int i = 0; i < NUM_BIRDS; i++) {
        bool isMovingLeft = (birds[i].speedX < 0);
        drawBird(birds[i].x, birds[i].y, 1.0f, birds[i].r, birds[i].g, birds[i].b, isMovingLeft, wingAngle);
    }
}

void drawCircle(float x, float y, float radius, unsigned char rLight, unsigned char gLight, unsigned char bLight, unsigned char rDark, unsigned char gDark, unsigned char bDark) {
    int i;
    int triangleAmount = 100;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub((rLight + rDark) / 2, (gLight + gDark) / 2, (bLight + bDark) / 2);
    glVertex2f(x, y);
    for (i = 0; i <= triangleAmount; i++) {
        float angle = i * twicePi / triangleAmount;
        float vertY = y + (radius * sin(angle));
        float t = (vertY - (y - radius)) / (2.0f * radius);
        unsigned char r = (unsigned char)(rLight + (rDark - rLight) * t);
        unsigned char g = (unsigned char)(gLight + (gDark - gLight) * t);
        unsigned char b = (unsigned char)(bLight + (bDark - bLight) * t);
        glColor3ub(r, g, b);
        glVertex2f(x + (radius * cos(angle)), vertY);
    }
    glEnd();
}


void drawRoundTreeWithMultipleLeaves(float x, float y, float trunkWidth, float trunkHeight, float leafRadius, float smallLeafRadius) {

    glBegin(GL_QUADS);
    glColor3ub(165, 82, 23);
    glVertex2f(x - trunkWidth / 2, y);
    glVertex2f(x + trunkWidth / 2, y);
    glColor3ub(113, 56, 15);
    glVertex2f(x + trunkWidth / 2, y + trunkHeight);
    glVertex2f(x - trunkWidth / 2, y + trunkHeight);
    glEnd();

    drawCircle(x, y + trunkHeight, leafRadius, 0, 153, 0, 0, 102, 0);
    drawCircle(x - leafRadius * 0.5f, y + trunkHeight + leafRadius * 0.5f, smallLeafRadius, 0, 153, 0, 0, 102, 0);
    drawCircle(x + leafRadius * 0.5f, y + trunkHeight + leafRadius * 0.5f, smallLeafRadius, 0, 153, 0, 0, 102, 0);
    drawCircle(x, y + trunkHeight + leafRadius, smallLeafRadius, 0, 153, 0, 0, 102, 0);
}

void drawCloud(float x, float y, float radius) {
    // Cloud 1
    int i5;
    GLfloat x5 = 255 + x; GLfloat y5 = 652 + y; GLfloat radius5 = 45;
    int triangleAmount5 = 100;
    GLfloat twicePi5 = 2.0f * PI;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x5, y5);
        for(i5 = 0; i5 <= triangleAmount5; i5++) {
            glVertex2f( x5 + (radius5 * cos(i5 * twicePi5 / triangleAmount5)),
                        y5 + (radius5 * sin(i5 * twicePi5 / triangleAmount5)) );
        }
    glEnd();

    // Cloud 2
    int i6;
    GLfloat x6 = 190 + x; GLfloat y6 = 652 + y; GLfloat radius6 = 30;
    int triangleAmount6 = 100;
    GLfloat twicePi6 = 2.0f * PI;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x6, y6);
        for(i6 = 0; i6 <= triangleAmount6; i6++) {
            glVertex2f( x6 + (radius6 * cos(i6 * twicePi6 / triangleAmount6)),
                        y6 + (radius6 * sin(i6 * twicePi6 / triangleAmount6)) );
        }
    glEnd();

    // Cloud 3
    int i7;
    GLfloat x7 = 320 + x; GLfloat y7 = 652 + y; GLfloat radius7 = 30;
    int triangleAmount7 = 100;
    GLfloat twicePi7 = 2.0f * PI;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x7, y7);
        for(i7 = 0; i7 <= triangleAmount7; i7++) {
            glVertex2f( x7 + (radius7 * cos(i7 * twicePi7 / triangleAmount7)),
                        y7 + (radius7 * sin(i7 * twicePi7 / triangleAmount7)) );
        }
    glEnd();

    // Cloud 4
    int i8;
    GLfloat x8 = 914 + x; GLfloat y8 = 670 + y; GLfloat radius8 = 25;
    int triangleAmount8 = 100;
    GLfloat twicePi8 = 2.0f * PI;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x8, y8);
        for(i8 = 0; i8 <= triangleAmount8; i8++) {
            glVertex2f( x8 + (radius8 * cos(i8 * twicePi8 / triangleAmount8)),
                        y8 + (radius8 * sin(i8 * twicePi8 / triangleAmount8)) );
        }
    glEnd();

    // Cloud 5
    int i9;
    GLfloat x9 = 945 + x; GLfloat y9 = 670 + y; GLfloat radius9 = 15;
    int triangleAmount9 = 100;
    GLfloat twicePi9 = 2.0f * PI;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x9, y9);
        for(i9 = 0; i9 <= triangleAmount9; i9++) {
            glVertex2f( x9 + (radius9 * cos(i9 * twicePi9 / triangleAmount9)),
                        y9 + (radius9 * sin(i9 * twicePi9 / triangleAmount9)) );
        }
    glEnd();

    // Cloud 6
    int i11;
    GLfloat x11 = 887 + x; GLfloat y11 = 670 + y; GLfloat radius11 = 15;
    int triangleAmount11 = 100;
    GLfloat twicePi11 = 2.0f * PI;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x11, y11);
        for(i11 = 0; i11 <= triangleAmount11; i11++) {
            glVertex2f( x11 + (radius11 * cos(i11 * twicePi11 / triangleAmount11)),
                        y11 + (radius11 * sin(i11 * twicePi11 / triangleAmount11)) );
        }
    glEnd();

    // Cloud 7
    int i12;
    GLfloat x12 = 960 + x; GLfloat y12 = 670 + y; GLfloat radius12 = 10;
    int triangleAmount12 = 100;
    GLfloat twicePi12 = 2.0f * PI;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x12, y12);
        for(i12 = 0; i12 <= triangleAmount12; i12++) {
            glVertex2f( x12 + (radius12 * cos(i12 * twicePi12 / triangleAmount12)),
                        y12 + (radius12 * sin(i12 * twicePi12 / triangleAmount12)) );
        }
    glEnd();

    // Cloud 8
    int i13;
    GLfloat x13 = 500 + x; GLfloat y13 = 680 + y; GLfloat radius13 = 35;
    int triangleAmount13 = 100;
    GLfloat twicePi13 = 2.0f * PI;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x13, y13);
        for(i13 = 0; i13 <= triangleAmount13; i13++) {
            glVertex2f( x13 + (radius13 * cos(i13 * twicePi13 / triangleAmount13)),
                        y13 + (radius13 * sin(i13 * twicePi13 / triangleAmount13)) );
        }
    glEnd();

    // Cloud 9
    int i14;
    GLfloat x14 = 460 + x; GLfloat y14 = 680 + y; GLfloat radius14 = 25;
    int triangleAmount14 = 100;
    GLfloat twicePi14 = 2.0f * PI;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x14, y14);
        for(i14 = 0; i14 <= triangleAmount14; i14++) {
            glVertex2f( x14 + (radius14 * cos(i14 * twicePi14 / triangleAmount14)),
                        y14 + (radius14 * sin(i14 * twicePi14 / triangleAmount14)) );
        }
    glEnd();

    // Cloud 10
    int i15;
    GLfloat x15 = 540 + x; GLfloat y15 = 680 + y; GLfloat radius15 = 20;
    int triangleAmount15 = 100;
    GLfloat twicePi15 = 2.0f * PI;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x15, y15);
        for(i15 = 0; i15 <= triangleAmount15; i15++) {
            glVertex2f( x15 + (radius15 * cos(i15 * twicePi15 / triangleAmount15)),
                        y15 + (radius15 * sin(i15 * twicePi15 / triangleAmount15)) );
        }
    glEnd();

    // Cloud 11
    int i16;
    GLfloat x16 = 700 + x; GLfloat y16 = 660 + y; GLfloat radius16 = 30;
    int triangleAmount16 = 100;
    GLfloat twicePi16 = 2.0f * PI;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x16, y16);
        for(i16 = 0; i16 <= triangleAmount16; i16++) {
            glVertex2f( x16 + (radius16 * cos(i16 * twicePi16 / triangleAmount16)),
                        y16 + (radius16 * sin(i16 * twicePi16 / triangleAmount16)) );
        }
    glEnd();

    // Cloud 12
    int i17;
    GLfloat x17 = 670 + x; GLfloat y17 = 660 + y; GLfloat radius17 = 20;
    int triangleAmount17 = 100;
    GLfloat twicePi17 = 2.0f * PI;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x17, y17);
        for(i17 = 0; i17 <= triangleAmount17; i17++) {
            glVertex2f( x17 + (radius17 * cos(i17 * twicePi17 / triangleAmount17)),
                        y17 + (radius17 * sin(i17 * twicePi17 / triangleAmount17)) );
        }
    glEnd();

    // Cloud 13
    int i18;
    GLfloat x18 = 730 + x; GLfloat y18 = 660 + y; GLfloat radius18 = 15;
    int triangleAmount18 = 100;
    GLfloat twicePi18 = 2.0f * PI;

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLE_FAN);
        glVertex2f(x18, y18);
        for(i18 = 0; i18 <= triangleAmount18; i18++) {
            glVertex2f( x18 + (radius18 * cos(i18 * twicePi18 / triangleAmount18)),
                        y18 + (radius18 * sin(i18 * twicePi18 / triangleAmount18)) );
        }
    glEnd();
}


// Modified drawSun function
void drawSun() {
    int i;
    GLfloat radius = 28.0f;
    int triangleAmount = 100;
    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    if (isNightMode) {
        glColor3ub(200, 200, 200);
    } else {
        glColor3ub(255, 140, 0);
    }
    glVertex2f(570.0f, sunPosition);
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(570.0f + (radius * cos(i * twicePi / triangleAmount)),
                   sunPosition + (radius * sin(i * twicePi / triangleAmount)));
    }
    glEnd();
}

void drawMaynamatiText() {
    GLint viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    int windowWidth = viewport[2];
    int windowHeight = viewport[3];

    float aspect = (float)windowWidth / (float)windowHeight;

    float baseHeight = 750.0f;
    float scalingFactor = (float)windowHeight / baseHeight;

    float textX = windowWidth * 0.5f;
    float textY = windowHeight * 0.95f;

    float fontSize = 24.0f * scalingFactor;
    void* font;

    if (fontSize > 30) font = GLUT_BITMAP_TIMES_ROMAN_24;
    else if (fontSize > 20) font = GLUT_BITMAP_HELVETICA_18;
    else font = GLUT_BITMAP_HELVETICA_12;

    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    gluOrtho2D(0, windowWidth, 0, windowHeight);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    glColor3f(0.1f, 0.1f, 0.1f);
    renderBitmapString(textX - (glutBitmapLength(font, (unsigned char*)"MAYNAMATI")/2) + 1*scalingFactor,
                      textY - 1*scalingFactor, font, "MAYNAMATI");

    glColor3f(0.96f, 0.87f, 0.58f);
    renderBitmapString(textX - (glutBitmapLength(font, (unsigned char*)"MAYNAMATI")/2),
                      textY, font, "MAYNAMATI");

    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
}



float mapX(float x) {
    return 575.0f * x;
}

float mapY(float y) {
    return 375.0f * y;
}
void fsky() {
    glBegin(GL_QUADS);
    if (isNightMode) {
        glColor3ub(25, 25, 112);
        glVertex2f(mapX(0.0f), mapY(0.9f));
        glVertex2f(mapX(2.0f), mapY(0.9f));
        glColor3ub(0, 0, 50);
        glVertex2f(mapX(2.0f), mapY(2.0f));
        glVertex2f(mapX(0.0f), mapY(2.0f));
    } else {
        glColor3ub(175, 226, 255);
        glVertex2f(mapX(0.0f), mapY(0.9f));
        glVertex2f(mapX(2.0f), mapY(0.9f));
        glColor3ub(95, 186, 215);
        glVertex2f(mapX(2.0f), mapY(2.0f));
        glVertex2f(mapX(0.0f), mapY(2.0f));
    }
    glEnd();
}


void fcloud() {
    drawCloud(cloudPosition + 0.2f, 1.85f, 30.0f);
    drawCloud(cloudPosition + 0.23f, 1.88f, 25.0f);
    drawCloud(cloudPosition + 0.18f, 1.82f, 20.0f);
    drawCloud(cloudPosition + 0.6f, 1.7f, 30.0f);
    drawCloud(cloudPosition + 0.58f, 1.73f, 25.0f);
    drawCloud(cloudPosition + 0.62f, 1.68f, 20.0f);
    drawCloud(cloudPosition + 1.4f, 1.8f, 30.0f);
    drawCloud(cloudPosition + 1.42f, 1.83f, 25.0f);
    drawCloud(cloudPosition + 1.38f, 1.73f, 20.0f);
    drawCloud(cloudPosition + 1.41f, 1.85f, 25.0f);
    drawCloud(cloudPosition + 0.8f, 1.65f, 30.0f);
    drawCloud(cloudPosition + 0.78f, 1.68f, 25.0f);
    drawCloud(cloudPosition + 0.82f, 1.63f, 20.0f);
    drawCloud(cloudPosition + 0.79f, 1.67f, 25.0f);
    drawCloud(cloudPosition + 1.6f, 1.75f, 30.0f);
    drawCloud(cloudPosition + 1.62f, 1.78f, 25.0f);
    drawCloud(cloudPosition + 1.58f, 1.73f, 20.0f);

}
void fLeftArc() {
    glBegin(GL_TRIANGLE_FAN);
        glColor3ub(141, 107, 69);
        glVertex2f(mapX(0.525f), mapY(0.932f));
        glVertex2f(mapX(0.565f), mapY(0.932f));
        glVertex2f(mapX(0.594f), mapY(0.92f));
        glVertex2f(mapX(0.639f), mapY(0.92f));
        glVertex2f(mapX(0.665f), mapY(0.92f));
        glVertex2f(mapX(0.699f), mapY(0.908f));
        glVertex2f(mapX(0.732f), mapY(0.92f));
        glVertex2f(mapX(0.763f), mapY(0.936f));
        glVertex2f(mapX(0.839f), mapY(0.979f));
        glVertex2f(mapX(0.874f), mapY(0.991f));
        glVertex2f(mapX(0.879f), mapY(1.019f));
        glVertex2f(mapX(0.937f), mapY(1.015f));
        glVertex2f(mapX(0.941f), mapY(0.964f));
        glVertex2f(mapX(0.968f), mapY(0.979f));
        glVertex2f(mapX(0.972f), mapY(0.908f));
        glVertex2f(mapX(0.941f), mapY(0.912f));
        glVertex2f(mapX(0.937f), mapY(0.924f));
        glVertex2f(mapX(0.941f), mapY(0.632f));
        glVertex2f(mapX(0.919f), mapY(0.596f));
        glVertex2f(mapX(0.899f), mapY(0.6f));
        glVertex2f(mapX(0.899f), mapY(0.647f));
        glVertex2f(mapX(0.852f), mapY(0.643f));
        glVertex2f(mapX(0.859f), mapY(0.695f));
        glVertex2f(mapX(0.852f), mapY(0.742f));
        glVertex2f(mapX(0.794f), mapY(0.746f));
        glVertex2f(mapX(0.672f), mapY(0.742f));
        glVertex2f(mapX(0.510f), mapY(0.734f));
        glVertex2f(mapX(0.001f), mapY(0.734f));
        glVertex2f(mapX(0.0f), mapY(0.889f));
        glVertex2f(mapX(0.048f), mapY(0.924f));
        glVertex2f(mapX(0.083f), mapY(0.9f));
        glVertex2f(mapX(0.128f), mapY(0.912f));
        glVertex2f(mapX(0.197f), mapY(0.908f));
        glVertex2f(mapX(0.241f), mapY(0.912f));
        glVertex2f(mapX(0.265f), mapY(0.912f));
        glVertex2f(mapX(0.288f), mapY(0.932f));
        glVertex2f(mapX(0.334f), mapY(0.932f));
        glVertex2f(mapX(0.345f), mapY(0.916f));
        glVertex2f(mapX(0.359f), mapY(0.908f));
        glVertex2f(mapX(0.368f), mapY(0.904f));
        glVertex2f(mapX(0.381f), mapY(0.904f));
        glVertex2f(mapX(0.401f), mapY(0.92f));
        glVertex2f(mapX(0.457f), mapY(0.932f));
        glVertex2f(mapX(0.468f), mapY(0.916f));
        glVertex2f(mapX(0.485f), mapY(0.916f));
    glEnd();


    glColor3ub(92, 64, 25);


    float bricksStartY = 0.75f;
    float bricksHeight = 0.17f;
    float brickHeight = 0.04f;
    float brickWidth = 0.1f;
    int rows = (int)(bricksHeight / brickHeight);

    float actualBrickHeight = bricksHeight / rows;


    for(int row = 0; row < rows; ++row) {
        float y = bricksStartY + row * actualBrickHeight;
        float xOffset = (row % 2) * (brickWidth / 2.0f);
        float startX = 0.0f + xOffset;
        float endX = 0.9f;

        for(float x = startX; x <= endX; x += brickWidth) {

            float xStart = x;
            float xEnd = x + brickWidth * 0.95f;
            if (xEnd > endX) xEnd = endX;

            glBegin(GL_LINES);
                glVertex2f(mapX(xStart), mapY(y));
                glVertex2f(mapX(xEnd), mapY(y));
            glEnd();


            if (xEnd < endX) {
                glBegin(GL_LINES);
                    glVertex2f(mapX(xEnd), mapY(y));
                    glVertex2f(mapX(xEnd), mapY(y + actualBrickHeight * 0.95f));
                glEnd();
            }


            glBegin(GL_LINES);
                glVertex2f(mapX(xStart), mapY(y + actualBrickHeight * 0.95f));
                glVertex2f(mapX(xEnd), mapY(y + actualBrickHeight * 0.95f));
            glEnd();
        }
    }
}

void fRightArc() {
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(141, 107, 69);
    glVertex2f(mapX(1.459f), mapY(0.948f));
    glVertex2f(mapX(1.497f), mapY(0.964f));
    glVertex2f(mapX(1.523f), mapY(0.94f));
    glVertex2f(mapX(1.572f), mapY(0.948f));
    glVertex2f(mapX(1.599f), mapY(0.96f));
    glVertex2f(mapX(1.623f), mapY(0.956f));
    glVertex2f(mapX(1.639f), mapY(0.94f));
    glVertex2f(mapX(1.688f), mapY(0.948f));
    glVertex2f(mapX(1.732f), mapY(0.964f));
    glVertex2f(mapX(1.761f), mapY(0.944f));
    glVertex2f(mapX(1.808f), mapY(0.948f));
    glVertex2f(mapX(1.863f), mapY(0.968f));
    glVertex2f(mapX(1.881f), mapY(0.96f));
    glVertex2f(mapX(1.905f), mapY(0.948f));
    glVertex2f(mapX(1.957f), mapY(0.956f));
    glVertex2f(mapX(2.003f), mapY(0.96f));
    glVertex2f(mapX(2.003f), mapY(0.766f));
    glVertex2f(mapX(1.825f), mapY(0.754f));
    glVertex2f(mapX(1.177f), mapY(0.726f));
    glVertex2f(mapX(1.185f), mapY(0.675f));
    glVertex2f(mapX(1.132f), mapY(0.671f));
    glVertex2f(mapX(1.088f), mapY(0.675f));
    glVertex2f(mapX(1.072f), mapY(0.916f));
    glVertex2f(mapX(1.019f), mapY(0.908f));
    glVertex2f(mapX(1.019f), mapY(0.968f));
    glVertex2f(mapX(1.043f), mapY(0.972f));
    glVertex2f(mapX(1.043f), mapY(0.991f));
    glVertex2f(mapX(1.072f), mapY(0.995f));
    glVertex2f(mapX(1.088f), mapY(1.015f));
    glVertex2f(mapX(1.114f), mapY(1.011f));
    glVertex2f(mapX(1.154f), mapY(1.011f));
    glVertex2f(mapX(1.168f), mapY(0.995f));
    glVertex2f(mapX(1.143f), mapY(0.979f));
    glVertex2f(mapX(1.174f), mapY(0.983f));
    glVertex2f(mapX(1.217f), mapY(0.96f));
    glVertex2f(mapX(1.245f), mapY(0.936f));
    glVertex2f(mapX(1.350f), mapY(0.94f));
    glVertex2f(mapX(1.381f), mapY(0.956f));
    glVertex2f(mapX(1.399f), mapY(0.948f));
    glVertex2f(mapX(1.421f), mapY(0.94f));
    glEnd();
    glColor3ub(92, 64, 25);


    float bricksStartY = 0.76f;
    float bricksHeight = 0.19f;
    float brickHeight = 0.04f;
    float brickWidth = 0.1f;


    int rows = (int)(bricksHeight / brickHeight);


    float actualBrickHeight = bricksHeight / rows;


    float minX = 1.1f;
    float maxX = 6.0f;

    for(int row = 0; row < rows; ++row) {
        float y = bricksStartY + row * actualBrickHeight;


        float xOffset = (row % 2) * (brickWidth / 2.0f);


        float startX = minX + xOffset;
        float endX = maxX - 0.1f;

        for(float x = startX; x <= endX; x += brickWidth) {

            float xStart = x;
            float xEnd = x + brickWidth * 0.95f;
            if (xEnd > endX) xEnd = endX;

            glBegin(GL_LINES);
                glVertex2f(mapX(xStart), mapY(y));
                glVertex2f(mapX(xEnd), mapY(y));
            glEnd();


            if (xEnd < endX) {
                glBegin(GL_LINES);
                    glVertex2f(mapX(xEnd), mapY(y));
                    glVertex2f(mapX(xEnd), mapY(y + actualBrickHeight * 0.95f));
                glEnd();
            }


            glBegin(GL_LINES);
                glVertex2f(mapX(xStart), mapY(y + actualBrickHeight * 0.95f));
                glVertex2f(mapX(xEnd), mapY(y + actualBrickHeight * 0.95f));
            glEnd();
        }
    }

}

void fGreenField() {
    glBegin(GL_QUADS);
    glColor3ub(80, 120, 0);
    glVertex2f(mapX(0.00f), mapY(0.9f));
    glVertex2f(mapX(2.5f), mapY(0.9f));
    glColor3ub(150, 200, 60);
    glVertex2f(mapX(2.5f), mapY(0.0f));
    glVertex2f(mapX(0.00f), mapY(0.0f));
    glEnd();
}

void fRoad() {
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(185, 157, 73);
    glVertex2f(mapX(1.163f), mapY(0.442f));
    glVertex2f(mapX(1.452f), mapY(0.442f));
    glVertex2f(mapX(1.617f), mapY(0.434f));
    glVertex2f(mapX(1.705f), mapY(0.383f));
    glVertex2f(mapX(1.201f), mapY(0.367f));
    glVertex2f(mapX(1.412f), mapY(0.0f));
    glVertex2f(mapX(0.659f), mapY(0.003f));
    glVertex2f(mapX(0.794f), mapY(0.268f));
    glVertex2f(mapX(0.808f), mapY(0.28f));
    glVertex2f(mapX(0.812f), mapY(0.3f));
    glVertex2f(mapX(0.859f), mapY(0.383f));
    glVertex2f(mapX(0.857f), mapY(0.398f));
    glVertex2f(mapX(0.879f), mapY(0.442f));
    glVertex2f(mapX(0.910f), mapY(0.497f));
    glVertex2f(mapX(1.123f), mapY(0.505f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(0.938f), mapY(0.498f));
    glVertex2f(mapX(0.722f), mapY(0.0f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(1.336f), mapY(0.0f));
    glVertex2f(mapX(1.098f), mapY(0.506f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(0.931f), mapY(0.474f));
    glVertex2f(mapX(1.111f), mapY(0.478f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(0.909f), mapY(0.431f));
    glVertex2f(mapX(1.127f), mapY(0.443f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(0.882f), mapY(0.379f));
    glVertex2f(mapX(1.153f), mapY(0.391f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(0.867f), mapY(0.328f));
    glVertex2f(mapX(1.176f), mapY(0.34f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(0.840f), mapY(0.273f));
    glVertex2f(mapX(1.202f), mapY(0.289f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(0.809f), mapY(0.198f));
    glVertex2f(mapX(1.236f), mapY(0.213f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(0.771f), mapY(0.134f));
    glVertex2f(mapX(1.267f), mapY(0.15f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(0.751f), mapY(0.071f));
    glVertex2f(mapX(1.296f), mapY(0.087f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(1.020f), mapY(0.494f));
    glVertex2f(mapX(1.024f), mapY(0.462f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(0.958f), mapY(0.431f));
    glVertex2f(mapX(0.960f), mapY(0.379f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(1.020f), mapY(0.379f));
    glVertex2f(mapX(1.027f), mapY(0.336f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(1.100f), mapY(0.332f));
    glVertex2f(mapX(1.100f), mapY(0.277f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(0.960f), mapY(0.277f));
    glVertex2f(mapX(0.949f), mapY(0.261f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(0.949f), mapY(0.265f));
    glVertex2f(mapX(0.947f), mapY(0.198f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(1.007f), mapY(0.206f));
    glVertex2f(mapX(1.013f), mapY(0.142f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(1.073f), mapY(0.154f));
    glVertex2f(mapX(1.076f), mapY(0.087f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(0.840f), mapY(0.067f));
    glVertex2f(mapX(0.838f), mapY(0.0f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(1.158f), mapY(0.383f));
    glVertex2f(mapX(1.671f), mapY(0.399f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(1.198f), mapY(0.435f));
    glVertex2f(mapX(1.224f), mapY(0.375f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(1.251f), mapY(0.431f));
    glVertex2f(mapX(1.264f), mapY(0.387f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(1.307f), mapY(0.431f));
    glVertex2f(mapX(1.331f), mapY(0.387f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(1.371f), mapY(0.435f));
    glVertex2f(mapX(1.391f), mapY(0.395f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(1.436f), mapY(0.435f));
    glVertex2f(mapX(1.458f), mapY(0.395f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(1.487f), mapY(0.435f));
    glVertex2f(mapX(1.504f), mapY(0.391f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(1.531f), mapY(0.431f));
    glVertex2f(mapX(1.549f), mapY(0.391f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(123, 92, 29);
    glVertex2f(mapX(1.580f), mapY(0.435f));
    glVertex2f(mapX(1.598f), mapY(0.395f));
    glEnd();
}

void fSideRoad() {
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(149, 119, 56);
    glVertex2f(mapX(0.708f), mapY(0.188f));
    glVertex2f(mapX(0.670f), mapY(0.192f));
    glVertex2f(mapX(0.695f), mapY(0.153f));
    glVertex2f(mapX(0.637f), mapY(0.105f));
    glVertex2f(mapX(0.646f), mapY(0.097f));
    glVertex2f(mapX(0.660f), mapY(0.109f));
    glVertex2f(mapX(0.611f), mapY(0.05f));
    glVertex2f(mapX(0.584f), mapY(0.002f));
    glVertex2f(mapX(0.584f), mapY(0.0f));
    glVertex2f(mapX(0.653f), mapY(0.0f));
    glVertex2f(mapX(0.908f), mapY(0.5f));
    glVertex2f(mapX(0.882f), mapY(0.496f));
    glVertex2f(mapX(0.866f), mapY(0.445f));
    glVertex2f(mapX(0.835f), mapY(0.453f));
    glVertex2f(mapX(0.824f), mapY(0.421f));
    glVertex2f(mapX(0.824f), mapY(0.394f));
    glVertex2f(mapX(0.806f), mapY(0.39f));
    glVertex2f(mapX(0.800f), mapY(0.362f));
    glVertex2f(mapX(0.784f), mapY(0.334f));
    glVertex2f(mapX(0.780f), mapY(0.307f));
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(149, 119, 56);
    glVertex2f(mapX(1.160f), mapY(0.445f));
    glVertex2f(mapX(1.186f), mapY(0.449f));
    glVertex2f(mapX(1.148f), mapY(0.508f));
    glVertex2f(mapX(1.124f), mapY(0.504f));
    glEnd();

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(149, 119, 56);
    glVertex2f(mapX(1.455f), mapY(0.358f));
    glVertex2f(mapX(1.437f), mapY(0.358f));
    glVertex2f(mapX(1.404f), mapY(0.362f));
    glVertex2f(mapX(1.286f), mapY(0.358f));
    glVertex2f(mapX(1.237f), mapY(0.311f));
    glVertex2f(mapX(1.211f), mapY(0.366f));
    glVertex2f(mapX(1.700f), mapY(0.374f));
    glVertex2f(mapX(1.688f), mapY(0.358f));
    glVertex2f(mapX(1.571f), mapY(0.358f));
    glVertex2f(mapX(1.520f), mapY(0.358f));
    glEnd();
}

void fstaircaseLine() {
    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(0.94f), mapY(0.905f));
    glVertex2f(mapX(1.073f), mapY(0.909f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(1.073f), mapY(0.909f));
    glVertex2f(mapX(1.076f), mapY(0.87f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(0.936f), mapY(0.913f));
    glVertex2f(mapX(0.933f), mapY(0.866f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(0.933f), mapY(0.866f));
    glVertex2f(mapX(1.078f), mapY(0.87f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(1.076f), mapY(0.866f));
    glVertex2f(mapX(1.078f), mapY(0.834f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(1.078f), mapY(0.834f));
    glVertex2f(mapX(0.931f), mapY(0.834f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(0.933f), mapY(0.87f));
    glVertex2f(mapX(0.933f), mapY(0.83f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(0.936f), mapY(0.838f));
    glVertex2f(mapX(0.933f), mapY(0.787f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(0.936f), mapY(0.787f));
    glVertex2f(mapX(1.078f), mapY(0.791f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(1.076f), mapY(0.834f));
    glVertex2f(mapX(1.078f), mapY(0.787f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(0.933f), mapY(0.794f));
    glVertex2f(mapX(0.931f), mapY(0.739f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(0.936f), mapY(0.743f));
    glVertex2f(mapX(1.087f), mapY(0.747f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(1.078f), mapY(0.794f));
    glVertex2f(mapX(1.084f), mapY(0.743f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(0.931f), mapY(0.739f));
    glVertex2f(mapX(0.933f), mapY(0.684f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(0.933f), mapY(0.684f));
    glVertex2f(mapX(1.087f), mapY(0.692f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(1.087f), mapY(0.755f));
    glVertex2f(mapX(1.089f), mapY(0.692f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(0.936f), mapY(0.715f));
    glVertex2f(mapX(1.093f), mapY(0.715f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(0.936f), mapY(0.652f));
    glVertex2f(mapX(1.107f), mapY(0.652f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(1.100f), mapY(0.696f));
    glVertex2f(mapX(1.104f), mapY(0.648f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(0.936f), mapY(0.684f));
    glVertex2f(mapX(0.931f), mapY(0.628f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(0.933f), mapY(0.636f));
    glVertex2f(mapX(0.898f), mapY(0.589f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(0.907f), mapY(0.597f));
    glVertex2f(mapX(0.911f), mapY(0.498f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(1.102f), mapY(0.66f));
    glVertex2f(mapX(1.131f), mapY(0.597f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(1.129f), mapY(0.597f));
    glVertex2f(mapX(1.138f), mapY(0.486f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(0.922f), mapY(0.613f));
    glVertex2f(mapX(1.122f), mapY(0.617f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(0.902f), mapY(0.589f));
    glVertex2f(mapX(1.133f), mapY(0.597f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(0.911f), mapY(0.526f));
    glVertex2f(mapX(1.140f), mapY(0.526f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 26);
    glVertex2f(mapX(0.909f), mapY(0.549f));
    glVertex2f(mapX(1.138f), mapY(0.549f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(86, 68, 29);
    glVertex2f(mapX(1.082f), mapY(0.7f));
    glVertex2f(mapX(1.104f), mapY(0.68f));
    glEnd();
}

void fBox() {

    unsigned char rLight = 220, gLight = 214, bLight = 216;
    unsigned char rDark = 160, gDark = 154, bDark = 156;
    float yMin = 0.35f, yMax = 0.706f;

    glBegin(GL_POLYGON);
    // Vertex 0: Bottom-left
    float y = 0.35f;
    float t = (y - yMin) / (yMax - yMin);
    glColor3ub((unsigned char)(rDark + (rLight - rDark) * t),
               (unsigned char)(gDark + (gLight - gDark) * t),
               (unsigned char)(bDark + (bLight - bDark) * t));
    glVertex2f(mapX(1.695f), mapY(0.35f));

    // Vertex 1: Bottom-right
    y = 0.358f;
    t = (y - yMin) / (yMax - yMin);
    glColor3ub((unsigned char)(rDark + (rLight - rDark) * t),
               (unsigned char)(gDark + (gLight - gDark) * t),
               (unsigned char)(bDark + (bLight - bDark) * t));
    glVertex2f(mapX(1.762f), mapY(0.358f));

    // Vertex 2: Top-right
    y = 0.706f;
    t = (y - yMin) / (yMax - yMin);
    glColor3ub((unsigned char)(rDark + (rLight - rDark) * t),
               (unsigned char)(gDark + (gLight - gDark) * t),
               (unsigned char)(bDark + (bLight - bDark) * t));
    glVertex2f(mapX(1.757f), mapY(0.706f));

    // Vertex 3: Top-middle-right
    y = 0.706f;
    t = (y - yMin) / (yMax - yMin);
    glColor3ub((unsigned char)(rDark + (rLight - rDark) * t),
               (unsigned char)(gDark + (gLight - gDark) * t),
               (unsigned char)(bDark + (bLight - bDark) * t));
    glVertex2f(mapX(1.722f), mapY(0.706f));

    // Vertex 4: Top-middle-left
    y = 0.706f;
    t = (y - yMin) / (yMax - yMin);
    glColor3ub((unsigned char)(rDark + (rLight - rDark) * t),
               (unsigned char)(gDark + (gLight - gDark) * t),
               (unsigned char)(bDark + (bLight - bDark) * t));
    glVertex2f(mapX(1.695f), mapY(0.706f));

    // Vertex 5: Middle-left
    y = 0.528f;
    t = (y - yMin) / (yMax - yMin);
    glColor3ub((unsigned char)(rDark + (rLight - rDark) * t),
               (unsigned char)(gDark + (gLight - gDark) * t),
               (unsigned char)(bDark + (bLight - bDark) * t));
    glVertex2f(mapX(1.624f), mapY(0.528f));

    // Vertex 6: Bottom-middle-left
    y = 0.437f;
    t = (y - yMin) / (yMax - yMin);
    glColor3ub((unsigned char)(rDark + (rLight - rDark) * t),
               (unsigned char)(gDark + (gLight - gDark) * t),
               (unsigned char)(bDark + (bLight - bDark) * t));
    glVertex2f(mapX(1.624f), mapY(0.437f));

    // Vertex 7: Bottom-middle
    y = 0.421f;
    t = (y - yMin) / (yMax - yMin);
    glColor3ub((unsigned char)(rDark + (rLight - rDark) * t),
               (unsigned char)(gDark + (gLight - gDark) * t),
               (unsigned char)(bDark + (bLight - bDark) * t));
    glVertex2f(mapX(1.657f), mapY(0.421f));
    glEnd();
}

void fSideLeftArc()
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143, 115, 55);
    glVertex2f(mapX(2.0f - 0.892f), mapY(0.486f));
    glVertex2f(mapX(2.0f - 0.912f), mapY(0.486f));
    glVertex2f(mapX(2.0f - 1.525f), mapY(0.664f));
    glVertex2f(mapX(2.0f - 1.336f), mapY(0.664f));
    glVertex2f(mapX(2.0f - 1.252f), mapY(0.648f));
    glVertex2f(mapX(2.0f - 1.114f), mapY(0.676f));
    glVertex2f(mapX(2.0f - 1.630f), mapY(0.534f));
    glVertex2f(mapX(2.0f - 1.791f), mapY(0.565f));
    glVertex2f(mapX(2.0f - 1.784f), mapY(0.751f));
    glVertex2f(mapX(2.0f - 1.749f), mapY(0.81f));
    glEnd();

}

void fStaircase(){

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(149, 114, 67);
    glVertex2f(mapX(1.088f), mapY(0.663f));
    glVertex2f(mapX(1.130f), mapY(0.663f));
    glVertex2f(mapX(1.130f), mapY(0.584f));
    glVertex2f(mapX(0.914f), mapY(0.592f));
    glVertex2f(mapX(0.939f), mapY(0.628f));
    glVertex2f(mapX(0.937f), mapY(0.92f));
    glVertex2f(mapX(0.943f), mapY(0.916f));
    glVertex2f(mapX(0.934f), mapY(0.916f));
    glVertex2f(mapX(1.072f), mapY(0.912f));
    glEnd();

        glBegin(GL_TRIANGLE_FAN);
    glColor3ub(149, 114, 67);
    glVertex2f(mapX(0.948f), mapY(0.655f));
    glVertex2f(mapX(0.897f), mapY(0.576f));
    glVertex2f(mapX(0.903f), mapY(0.489f));
    glVertex2f(mapX(1.177f), mapY(0.501f));
    glVertex2f(mapX(1.103f), mapY(0.695f));
    glEnd();


}


void fSideRightArc(){
     glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143, 115, 55);
    glVertex2f(mapX(0.892f), mapY(0.486f));
    glVertex2f(mapX(0.643f), mapY(0.004f));
    glVertex2f(mapX(0.667f), mapY(0.0f));
    glVertex2f(mapX(0.912f), mapY(0.486f));
    glVertex2f(mapX(1.525f), mapY(0.664f));
    glVertex2f(mapX(1.336f), mapY(0.664f));
    glVertex2f(mapX(1.252f), mapY(0.648f));
    glVertex2f(mapX(1.114f), mapY(0.676f));
    glVertex2f(mapX(1.176f), mapY(0.498f));
    glVertex2f(mapX(1.254f), mapY(0.534f));
    glVertex2f(mapX(1.359f), mapY(0.526f));
    glVertex2f(mapX(1.487f), mapY(0.553f));
    glVertex2f(mapX(1.607f), mapY(0.553f));
    glVertex2f(mapX(1.630f), mapY(0.534f));
    glVertex2f(mapX(1.625f), mapY(0.545f));
    glVertex2f(mapX(1.692f), mapY(0.711f));
    glVertex2f(mapX(1.763f), mapY(0.708f));
    glVertex2f(mapX(1.763f), mapY(0.573f));
    glVertex2f(mapX(1.841f), mapY(0.565f));
    glVertex2f(mapX(1.834f), mapY(0.751f));
    glVertex2f(mapX(1.799f), mapY(0.81f));
    glVertex2f(mapX(1.723f), mapY(0.791f));
    glVertex2f(mapX(1.685f), mapY(0.783f));
    glVertex2f(mapX(1.625f), mapY(0.739f));
    glEnd();


    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(143, 115, 55);
    glVertex2f(mapX(1.693f), mapY(0.378f));
    glVertex2f(mapX(1.710f), mapY(0.339f));
    glVertex2f(mapX(1.386f), mapY(0.374f));
    glEnd();


}

void drawMultipleGrasses() {
    int positions[10][2] = {
        {256, 111},
        {350, 171},
        {746, 111},
        {1100, 111},
        {56, 120},
        {980, 30},
        {400, 150},
        {990, 110},
        {150, 60}
    };
    for (int i = 0; i < 9; i++) {
        int dx = positions[i][0];
        int dy = positions[i][1];

        glBegin(GL_POLYGON);
        glColor3f(0.0f, 0.6f, 0.0f);
        glVertex2f(dx + 0, dy + 0);
        glVertex2f(dx + 0, dy + 20);
        glVertex2f(dx + 14, dy + 3);
        glVertex2f(dx + 25, dy + 17);
        glVertex2f(dx + 25, dy - 1);
        glVertex2f(dx + 45, dy + 6);
        glVertex2f(dx + 29, dy - 10);
        glVertex2f(dx - 10, dy - 10);
        glVertex2f(dx - 28, dy + 6);
        glEnd();
    }
}

void display_Scenario2() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    fsky();
    drawSun();
    fGreenField();
    fcloud();
    fLeftArc();
    fRightArc();
    fRoad();
    fSideRoad();
    fSideLeftArc();
    fstaircaseLine();
    fSideRightArc();
    fStaircase();
    drawRoundTreeWithMultipleLeaves(142, 66, 10, 60, 30, 20);
    drawRoundTreeWithMultipleLeaves(850, 70, 10, 60, 30, 20);
    drawRoundTreeWithMultipleLeaves(250, 153, 10, 60, 30, 20);
    drawRoundTreeWithMultipleLeaves(200, 103, 10, 60, 30, 20);
    fstaircaseLine();
    fBox();
    drawMultipleGrasses();
    drawBirds();

    drawMaynamatiText();

    glFlush();
}

void sound()
{

    PlaySound("sound.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}

///----------------------Salehin-----------------

float boatOffsetX = 0.0f;
float cloudOffsetX = 0.0f;
float boatSpeed = 2.0f;
bool boatMoving = true;
bool isDay = true;
bool isRaining = false;

struct Star {
    float x, y;
    float brightness;
    float flickerSpeed;
};

struct RainDrop {
    float x, y, speed;
};

Star stars[MAX_STARS];
RainDrop rain[MAX_RAIN];

void initStars() {
    srand(time(NULL));
    for (int i = 0; i < MAX_STARS; i++) {
        stars[i].x = rand() % 1150;
        stars[i].y = 480 + rand() % 270;  // Only in the sky area
        stars[i].brightness = ((float)(rand() % 100)) / 100.0f;
        stars[i].flickerSpeed = 0.02f + ((float)(rand() % 10) / 500.0f);
    }
}

void initRain() {
    for (int i = 0; i < MAX_RAIN; i++) {
        rain[i].x = rand() % 1150;
        rain[i].y = rand() % 750;
        rain[i].speed = 5 + rand() % 5;
    }
}

void drawStars() {
    glPointSize(2.0f);
    glBegin(GL_POINTS);
    for (int i = 0; i < MAX_STARS; i++) {
        float flicker = 0.5f + 0.5f * sin(stars[i].brightness);
        glColor3f(flicker, flicker, flicker);
        glVertex2f(stars[i].x, stars[i].y);
        stars[i].brightness += stars[i].flickerSpeed;
    }
    glEnd();
}

void drawRain() {
    glColor3f(0.7f, 0.7f, 1.0f);
    glBegin(GL_LINES);
    for (int i = 0; i < MAX_RAIN; i++) {
        glVertex2f(rain[i].x, rain[i].y);
        glVertex2f(rain[i].x, rain[i].y - 10);
    }
    glEnd();
}


void LITTLE_BOAT() {
    glPushMatrix();
    glTranslatef(boatOffsetX, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3f(0.6f, 0.4f, 0.2f);
    glVertex2f(960, 380); glVertex2f(1020, 335);
    glVertex2f(1080, 335); glVertex2f(1140, 380);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.65f, 0.16f, 0.16f);
    glVertex2f(1020, 380); glVertex2f(1020, 405);
    glVertex2f(1050, 415); glVertex2f(1080, 405);
    glVertex2f(1080, 380);
    glEnd();

    glPopMatrix();
}

void BOAT() {
    glBegin(GL_POLYGON);
    glColor3f(0.55f, 0.20f, 0.02f);
    glVertex2f(320, 120); glVertex2f(520, 40);
    glVertex2f(470, 120); glVertex2f(280, 200);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.3f, 0.2f, 0.1f);
    glVertex2f(280, 200); glVertex2f(340, 195);
    glVertex2f(395, 210); glVertex2f(415, 250);
    glVertex2f(620, 175); glVertex2f(600, 130);
    glVertex2f(520, 100); glVertex2f(470, 120);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.65f, 0.16f, 0.16f);
    glVertex2f(620, 175); glVertex2f(600, 130);
    glVertex2f(520, 100); glVertex2f(470, 120);
    glVertex2f(520, 40); glVertex2f(615, 85);
    glEnd();
}

void AIR() {
    glBegin(GL_POLYGON);
    if (isDay && !isRaining) glColor3f(0.53f, 0.81f, 0.92f);
    else if (isDay && isRaining) glColor3f(0.4f, 0.5f, 0.6f); // Rainy day
    else if (!isDay && !isRaining) glColor3f(0.0f, 0.0f, 0.3f);
    else glColor3f(0.05f, 0.05f, 0.15f); // Rainy night
    glVertex2f(0, 480); glVertex2f(1150, 440);
    glVertex2f(1150, 750); glVertex2f(0, 750);
    glEnd();
}

void LAND_BOUNDARY() {
    glColor3f(0.486f, 0.988f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0); glVertex2f(0, 142);
    glVertex2f(1150, 240); glVertex2f(1150, 0);
    glEnd();
}

void drawCircle(float cx, float cy, float r, int segments = 100) {
    float angle;
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        angle = 2.0f * 3.1415926f * i / segments;
        glVertex2f(cx + cos(angle) * r, cy + sin(angle) * r);
    }
    glEnd();
}

void CLOUD(float x, float y) {
    glPushMatrix();
    glTranslatef(cloudOffsetX, 0.0f, 0.0f);
    glColor3f(0.95f, 0.95f, 0.95f);
    drawCircle(x, y, 30); drawCircle(x - 20, y, 25);
    drawCircle(x + 20, y, 25); drawCircle(x - 10, y + 20, 20);
    drawCircle(x + 10, y + 20, 20);
    glPopMatrix();
}

void SUN() {
    if (!isDay) return;

    float cx = 1000, cy = 600, r = 35;
    float twicePi = 2.0f * 3.1415926f;

    glColor3f(1.0f, 0.843f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i <= 100; i++) {
        float angle = i * twicePi / 100;
        glVertex2f(cx + r * cos(angle), cy + r * sin(angle));
    }
    glEnd();

    glColor3f(1.0f, 0.8f, 0.0f);
    glLineWidth(2.0);
    glBegin(GL_LINES);
    for (int i = 0; i < 16; i++) {
        float angle = i * twicePi / 16.0f;
        float x1 = cx + r * cos(angle);
        float y1 = cy + r * sin(angle);
        float x2 = cx + (r + 20) * cos(angle);
        float y2 = cy + (r + 20) * sin(angle);
        glVertex2f(x1, y1); glVertex2f(x2, y2);
    }
    glEnd();
}

void MOON() {
    if (isDay) return;
    float cx = 1000, cy = 600, r = 30;
    glColor3f(1.0f, 1.0f, 0.9f);
    drawCircle(cx, cy, r);
    glColor3f(0.0f, 0.0f, 0.3f);
    drawCircle(cx + 10, cy + 5, r - 5);
}

void RIVER() {
    glBegin(GL_POLYGON);
    glColor3f(0.5f, 0.7f, 0.8f);
    glVertex2f(0, 142); glVertex2f(1150, 240);
    glVertex2f(1150, 440); glVertex2f(0, 480);
    glEnd();
}

void TREE(float x, float y) {
    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_POLYGON);
    glVertex2f(x - 15, y); glVertex2f(x + 15, y);
    glVertex2f(x + 15, y + 100); glVertex2f(x - 15, y + 100);
    glEnd();

    glColor3f(0.0f, 0.6f, 0.1f);
    drawCircle(x, y + 130, 40); drawCircle(x - 30, y + 120, 35);
    drawCircle(x + 30, y + 120, 35); drawCircle(x - 20, y + 100, 30);
    drawCircle(x + 20, y + 100, 30);
}

void BUSH(float x, float y) {
    glColor3f(0.0f, 0.6f, 0.1f);
    drawCircle(x, y, 15); drawCircle(x - 10, y - 5, 13);
    drawCircle(x + 10, y - 5, 13); drawCircle(x - 15, y, 10);
    drawCircle(x + 15, y, 10);
}
void WOODEN_SIGNBOARD(float x, float y) {
    // Draw wooden plank
    glColor3f(0.55f, 0.27f, 0.07f);  // Brown color
    glBegin(GL_POLYGON);
    glVertex2f(x - 100, y);
    glVertex2f(x + 100, y);
    glVertex2f(x + 90, y + 40);
    glVertex2f(x - 90, y + 40);
    glEnd();

    // Draw plank border
    glColor3f(0.36f, 0.20f, 0.09f);
    glLineWidth(3);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x - 100, y);
    glVertex2f(x + 100, y);
    glVertex2f(x + 90, y + 40);
    glVertex2f(x - 90, y + 40);
    glEnd();

    // Draw two vertical wooden posts
    glColor3f(0.45f, 0.23f, 0.07f);
    glBegin(GL_POLYGON);
    glVertex2f(x - 80, y - 80);
    glVertex2f(x - 60, y - 80);
    glVertex2f(x - 60, y);
    glVertex2f(x - 80, y);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(x + 60, y - 80);
    glVertex2f(x + 80, y - 80);
    glVertex2f(x + 80, y);
    glVertex2f(x + 60, y);
    glEnd();

    // Render text on plank (centered)
    char text[] = "Monpura";
    glColor3f(1.0f, 1.0f, 1.0f);  // White text
    void* font = GLUT_BITMAP_TIMES_ROMAN_24;

    // Calculate starting position for centering the text
    int len = (int)strlen(text);
    float textWidth = 12.0f * len;  // Approximate width per char
    float startX = x - textWidth / 2;
    float startY = y + 12;  // Slightly above plank bottom

    glRasterPos2f(startX, startY);
    for (int i = 0; i < len; i++) {
        glutBitmapCharacter(font, text[i]);
    }
}

void PARK_BENCH(float x, float y) {
    // Seat
    glColor3f(0.6f, 0.3f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(x - 40, y);
    glVertex2f(x + 40, y);
    glVertex2f(x + 40, y + 10);
    glVertex2f(x - 40, y + 10);
    glEnd();

    // Backrest
    glBegin(GL_POLYGON);
    glVertex2f(x - 40, y + 20);
    glVertex2f(x + 40, y + 20);
    glVertex2f(x + 40, y + 30);
    glVertex2f(x - 40, y + 30);
    glEnd();

    // Bench legs
    glColor3f(0.3f, 0.2f, 0.1f);
    glLineWidth(4.0f);
    glBegin(GL_LINES);
    glVertex2f(x - 35, y); glVertex2f(x - 35, y - 20);
    glVertex2f(x + 35, y); glVertex2f(x + 35, y - 20);
    glEnd();

    // Backrest supports
    glBegin(GL_LINES);
    glVertex2f(x - 35, y + 10); glVertex2f(x - 35, y + 20);
    glVertex2f(x + 35, y + 10); glVertex2f(x + 35, y + 20);
    glEnd();
}

void COTTAGE(float x, float y) {
    // Main house body
    glColor3f(0.85f, 0.53f, 0.10f); // Orange-brown
    glBegin(GL_POLYGON);
    glVertex2f(x - 40, y);
    glVertex2f(x + 40, y);
    glVertex2f(x + 40, y + 50);
    glVertex2f(x - 40, y + 50);
    glEnd();

    // Roof
    glColor3f(0.5f, 0.1f, 0.1f); // Dark red
    glBegin(GL_TRIANGLES);
    glVertex2f(x - 50, y + 50);
    glVertex2f(x + 50, y + 50);
    glVertex2f(x, y + 80);
    glEnd();

    // Door
    glColor3f(0.4f, 0.2f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(x - 10, y);
    glVertex2f(x + 10, y);
    glVertex2f(x + 10, y + 25);
    glVertex2f(x - 10, y + 25);
    glEnd();

    // Doorknob
    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(x + 7, y + 12, 2);

    // Windows
    glColor3f(0.7f, 0.9f, 1.0f); // Light blue windows
    glBegin(GL_POLYGON); // Left window
    glVertex2f(x - 30, y + 30);
    glVertex2f(x - 15, y + 30);
    glVertex2f(x - 15, y + 45);
    glVertex2f(x - 30, y + 45);
    glEnd();

    glBegin(GL_POLYGON); // Right window
    glVertex2f(x + 15, y + 30);
    glVertex2f(x + 30, y + 30);
    glVertex2f(x + 30, y + 45);
    glVertex2f(x + 15, y + 45);
    glEnd();

    // Window cross lines
    glColor3f(0.3f, 0.3f, 0.3f);
    glLineWidth(1.0f);
    glBegin(GL_LINES);
    glVertex2f(x - 22.5f, y + 30); glVertex2f(x - 22.5f, y + 45);
    glVertex2f(x - 30, y + 37.5f); glVertex2f(x - 15, y + 37.5f);

    glVertex2f(x + 22.5f, y + 30); glVertex2f(x + 22.5f, y + 45);
    glVertex2f(x + 15, y + 37.5f); glVertex2f(x + 30, y + 37.5f);
    glEnd();
}


void FLOWER(float x, float y) {
    glColor3f(1.0f, 0.5f, 0.7f);
    drawCircle(x + 5, y, 6); drawCircle(x - 5, y, 6);
    drawCircle(x, y + 5, 6); drawCircle(x, y - 5, 6);
    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(x, y, 4);
}

void display_Scenario1()  {
    glClear(GL_COLOR_BUFFER_BIT);
    renderBitmapString(535, 735, GLUT_BITMAP_HELVETICA_18, "Monpura");

    AIR();
    LAND_BOUNDARY();
    RIVER();
    LITTLE_BOAT();
    SUN();
    MOON();
    if (!isDay) drawStars(); // Draw stars only at night

    if (isRaining) drawRain(); // Draw rain on top if raining

    BOAT();
    CLOUD(450, 580); CLOUD(700, 680); CLOUD(150, 650);
    TREE(200, 90); TREE(1080, 180);
    TREE(920, 150); TREE(720, 40);
    BUSH(100, 50);
    BUSH(280, 60); BUSH(850, 160);
    FLOWER(100, 50);
    FLOWER(280, 60); FLOWER(850, 160);

    WOODEN_SIGNBOARD(880, 80);
    PARK_BENCH(90, 90);
    COTTAGE(1080, 75);  // Cottage 1 on left



    glFlush();
}

void updateScene(int value) {
    if (boatMoving && boatSpeed > 0.0f) {
        boatOffsetX -= boatSpeed;
        if (boatOffsetX < -1200) boatOffsetX = 0;
    }

    cloudOffsetX += 0.5f;
    if (cloudOffsetX > 1200) cloudOffsetX = -200;

    if (isRaining) {
        for (int i = 0; i < MAX_RAIN; i++) {
            rain[i].y -= rain[i].speed;
            if (rain[i].y < 0) {
                rain[i].x = rand() % 1150;
                rain[i].y = 750 + rand() % 100;
            }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(50, updateScene, 0);
}

///----------------------Tutul-------------

// Global variables for sun, moon, and cloud positions
float sunny = 660;
float moony = 160;
float stary=230;
float cloudXOffset = -1000.0;
bool is_Day = true;
bool cloudMovingRight = true;
float boatXOffset = -540.0; // Start boat from left

bool boatMovingRight = true;
bool animateSunMoon = false;
bool sunToDown = false; // Controls the sun's movement direction
bool moonToUp = false;  // Controls the moon's movement direction

void renderBitmapString(float x, float y, float z, void *font, char *string) {
    char *c;
    glRasterPos3f(x, y,z);
    for (c=string; *c != '\0'; c++)
    {
        glutBitmapCharacter(font, *c);
    }
}

void circle(GLfloat rx,GLfloat ry,GLfloat cx,GLfloat cy)///radius_x,radius_y,centre_position_x,centre_position_y///
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx,cy);
    for(int i=0; i<=360; i++)
    {
        float angle = 3.1416f * i/180;
        float x = rx * cosf(angle);
        float y = ry * sinf(angle);
        glVertex2f((x+cx),(y+cy));
    }
    glEnd();


}

void draw_cow(){


    //back leg right
    glColor3ub(103,53,53);
    glBegin(GL_POLYGON);
    glVertex2f(200.9889416216369, 311.6979444467439);
    glVertex2f(205.9478953623819, 300.4187555462257);
    glVertex2f(210.0732212181757, 300.3706328933863);
    glVertex2f(206.9202392331162, 311.7951788338173);
    glVertex2f(210.8955153703008, 319.2833983922638);
    glVertex2f(205.3450298434564, 322.7781485387955);
    glVertex2f(199.280315919974, 318.1310957586579);
    glEnd();


    //front leg right
    //glColor3ub(126,69,52);
    glBegin(GL_POLYGON);
    glVertex2f(240, 320);
    glVertex2f(246.4597374497118, 301.8096476596052);
    glVertex2f(251.4482065210318, 301.431184348333);
    glVertex2f(247.8987522159307, 319.9001190063576);
    glEnd();

    //body
    //glColor3ub(126,69,52);
    glBegin(GL_POLYGON);
    glVertex2f(205.3450298434564, 322.778148538795);
    glVertex2f(191.3660292573295, 326.4784722233584);
    glVertex2f(190.7493086432357, 343.7466494179857);
    glVertex2f(196.6895591526281, 350.270147853563);
    glVertex2f(203.4948680011749, 354.4364733956121);
    glVertex2f(235.7699134720853, 355.2587675477373);
    glVertex2f(242.1426931510549, 354.4364733956121);
    glVertex2f(247.7895022498455, 350.6642590846395);
    glVertex2f(252.092169484715, 344.8556583175657);
    glVertex2f(255.8324768848619, 339.13144296727);
    glVertex2f(260, 335);
    glVertex2f(265.4239802836268, 331.343907220958);
    glVertex2f(230, 320);
    glVertex2f(210.8955153703008, 319.2833983922638);
    //back leg left
    //glColor3ub(126,69,52);
    glBegin(GL_POLYGON);
    glVertex2f(192.322271947887, 311.9497212400165);
    glVertex2f(191.9461436238077, 300.3215211591523);
    glVertex2f(187.3349964820344, 300.314707519748);
    glVertex2f(187.4733618184299, 317.6292420582233);
    glVertex2f(191.3627373013671, 326.5);
    glVertex2f(205.3450298434564, 322.7781485387955);
    glEnd();
    //front leg left
    //glColor3ub(126,69,52);
    glBegin(GL_POLYGON);
    glVertex2f(233.6330765190305, 300.7985665473156);
    glVertex2f(230.0038334864105, 300.9714731597484);
    glVertex2f(230, 320);
    glVertex2f(240,320);
    glEnd();

    //head
    //glColor3ub(126,69,52);
    glBegin(GL_POLYGON);
    glVertex2f(265.6071649606033, 330.9683908037026);
    glVertex2f(220.9889416216369, 319.6979444467439);
    glVertex2f(240, 320);
    glVertex2f(253.2436642047439, 319.2833983922638);
    glVertex2f(266.4003706387456, 308.1824273385748);
    glVertex2f(273.3605415408282, 308.5417422760039);
    glVertex2f(270.8595769898058, 327.4613381451167);
    glVertex2f(268.5738631755348, 330.2283429146692);
    glEnd();

    //horn
    //glColor3ub(126,69,52);
    glBegin(GL_POLYGON);
    glVertex2f(268.5738631755348, 330.2283429146692);
    glVertex2f(273.849082128284, 336.3885557609812);
    glVertex2f(273.4122201990361, 332.4806815290577);
    glVertex2f(270.8595769898058, 327.4613381451167);
    glEnd();





}

void draw_road(){


    glColor3ub(219,179,79);
    glBegin(GL_POLYGON);
    glVertex2f(522, 257);
    glVertex2f(648, 291);
    glVertex2f(734, 293);
    glVertex2f(608, 243);
    glEnd();

    glBegin(GL_POLYGON);

    glVertex2f(648, 291);
    glVertex2f(734, 293);
    glVertex2f(613, 345);
    glVertex2f(565, 334);
    glEnd();

    glBegin(GL_POLYGON);


    glVertex2f(630, 330);
    glVertex2f(565, 334);
    glVertex2f(670.5, 372.5);
    glVertex2f(700, 373);
    glEnd();

}

void draw_day_field(){

    //main field
   // glColor3ub(137,172,49);
    glBegin(GL_POLYGON);
    glVertex2f(0, 300);
    glVertex2f(0, 372);
    glVertex2f(1150, 372);
    glVertex2f(1150, 200);
    glVertex2f(466, 270);
    glVertex2f(225, 271);
    glEnd();

    draw_cow();
    draw_road();

    glTranslated(700,10,0);
    draw_cow();
}
void draw_night_field(){

    //main field
   // glColor3ub(137,172,49);
    glBegin(GL_POLYGON);
    glVertex2f(0, 300);
    glVertex2f(0, 372);
    glVertex2f(1150, 372);
    glVertex2f(1150, 200);
    glVertex2f(466, 270);
    glVertex2f(225, 271);
    glEnd();
}


void draw_river_bank(){

    glColor3ub(142,97,70);
    glBegin(GL_POLYGON);
    glVertex2f(472, 282);
    glVertex2f(1150, 240);
    glVertex2f(1150, 196);
    glVertex2f(468, 260);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(468, 260);
    glVertex2f(220, 260);
    glVertex2f(232, 282);
    glVertex2f(472, 282);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(220, 260);
    glVertex2f(0, 289);
    glVertex2f(0, 310);
    glVertex2f(232, 282);
    glEnd();

    glLineWidth(7);
    glColor3ub(114,69,44);
    glBegin(GL_LINES);
    glVertex2f(0, 289);
    glVertex2f(232, 260);
    glEnd();
    glColor3ub(114,69,44);
    glBegin(GL_LINES);
    glVertex2f(232, 260);
    glVertex2f(472, 260);
    glEnd();
    glColor3ub(114,69,44);
    glBegin(GL_LINES);
    glVertex2f(472, 260);
    glVertex2f(1150, 200);
    glEnd();

}

void draw_day_boat(){
    glPushMatrix();
    glTranslatef(boatXOffset, 0.0, 0.0);


    glColor3ub(27,125,178);//shadow
    circle(140,10,320,68);

///-----Lower part-----
    glColor3ub(187,79,53);
    glBegin(GL_POLYGON);
    glVertex2f(441, 104);
    glVertex2f(459, 114);
    glVertex2f(418.5, 104);
    glVertex2f(305, 99);
    glVertex2f(195.5, 103.5);
    glVertex2f(224, 69);
    glVertex2f(409, 69);
    glEnd();

    ///-----Lower part shade-----
    glColor3ub(147,63,37);
    glBegin(GL_POLYGON);
    glVertex2f(224, 69);
    glVertex2f(409, 69);
    glVertex2f(424, 83.5);
    glVertex2f(213, 83.5);


    glEnd();

    ///-----Middle part-----
    glColor3ub(223,115,36);
    glBegin(GL_POLYGON);
    glVertex2f(169, 122);
    glVertex2f(178, 106);
    glVertex2f(195.5, 103);
    glVertex2f(418.5, 104);
    glVertex2f(459, 114);
    glVertex2f(494.5, 122);
    glVertex2f(494.5, 125);
    glEnd();

    ///-----Upper part-----
    glColor3ub(110,49,35);
    glBegin(GL_POLYGON);
    glVertex2f(177, 130);
    glVertex2f(184, 116);
    glVertex2f(274, 110);
    glVertex2f(358, 110);
    glVertex2f(467, 119);
    glVertex2f(473.9, 122);
    glVertex2f(473.9, 125);
    glVertex2f(385, 135);
    glVertex2f(253, 135);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(473.9, 125);
    glVertex2f(544, 132);
    glEnd();


    ///-----Sail-----

    //frame line
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(360, 155);
    glVertex2f(250, 155);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(360, 240);
    glVertex2f(250, 240);
    glEnd();



    //sail
    glBegin(GL_POLYGON);
    glColor3ub(252,196,62);
    glVertex2f(360, 240);
    glVertex2f(360, 155);
    glVertex2f(250,155);
    glVertex2f(250, 240);
    glEnd();

    //poll
    glColor3ub(110,49,35);
    glBegin(GL_POLYGON);
    glVertex2f(302, 250);
    glVertex2f(306, 250);
    glVertex2f(310.5, 122.5);
    glVertex2f(302, 122.5);
    glEnd();

    //Line

    glLineWidth(2);
    glColor3ub(110,49,35);
    glBegin(GL_LINES);
    glVertex2f(305, 220);
    glVertex2f(470, 120);
    glEnd();

    glLineWidth(2);
    glColor3ub(110,49,35);
    glBegin(GL_LINES);
    glVertex2f(305, 230);
    glVertex2f(500, 128);
    glEnd();

    glLineWidth(2);
    glColor3ub(110,49,35);
    glBegin(GL_LINES);
    glVertex2f(305, 238);
    glVertex2f(530, 130);
    glEnd();


    ///------hood-----
    glColor3ub(254, 3, 16);//red
    glBegin(GL_QUADS);
    glVertex2f(265, 160);
    glVertex2f(380, 160);
    glVertex2f(400, 114);
    glVertex2f(280, 110);
    glEnd();

    glColor3ub(200,100,0);//brown
    glBegin(GL_TRIANGLES);
    glVertex2f(265, 160);
    glVertex2f(240, 132);
    glVertex2f(280, 110);
    glEnd();

    glPopMatrix();
}

void draw_night_boat(){
    glPushMatrix();
    glTranslatef(boatXOffset, 0.0, 0.0);


    glColor3ub(20,20,116);//shadow
    circle(140,10,320,68);

///-----Lower part-----
    glColor3ub(187,79,53);
    glBegin(GL_POLYGON);
    glVertex2f(441, 104);
    glVertex2f(459, 114);
    glVertex2f(418.5, 104);
    glVertex2f(305, 99);
    glVertex2f(195.5, 103.5);
    glVertex2f(224, 69);
    glVertex2f(409, 69);
    glEnd();

    ///-----Lower part shade-----
    glColor3ub(147,63,37);
    glBegin(GL_POLYGON);
    glVertex2f(224, 69);
    glVertex2f(409, 69);
    glVertex2f(424, 83.5);
    glVertex2f(213, 83.5);


    glEnd();

    ///-----Middle part-----
    glColor3ub(223,115,36);
    glBegin(GL_POLYGON);
    glVertex2f(169, 122);
    glVertex2f(178, 106);
    glVertex2f(195.5, 103);
    glVertex2f(418.5, 104);
    glVertex2f(459, 114);
    glVertex2f(494.5, 122);
    glVertex2f(494.5, 125);
    glEnd();

    ///-----Upper part-----
    glColor3ub(110,49,35);
    glBegin(GL_POLYGON);
    glVertex2f(177, 130);
    glVertex2f(184, 116);
    glVertex2f(274, 110);
    glVertex2f(358, 110);
    glVertex2f(467, 119);
    glVertex2f(473.9, 122);
    glVertex2f(473.9, 125);
    glVertex2f(385, 135);
    glVertex2f(253, 135);
    glEnd();

    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(473.9, 125);
    glVertex2f(544, 132);
    glEnd();


    ///-----Sail-----

    //frame line
    glLineWidth(4);
    glBegin(GL_LINES);
    glVertex2f(360, 155);
    glVertex2f(250, 155);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(360, 240);
    glVertex2f(250, 240);
    glEnd();



    //sail
    glBegin(GL_POLYGON);
    glColor3ub(252,196,62);
    glVertex2f(360, 240);
    glVertex2f(360, 155);
    glVertex2f(250,155);
    glVertex2f(250, 240);
    glEnd();

    //poll
    glColor3ub(110,49,35);
    glBegin(GL_POLYGON);
    glVertex2f(302, 250);
    glVertex2f(306, 250);
    glVertex2f(310.5, 122.5);
    glVertex2f(302, 122.5);
    glEnd();

    //Line

    glLineWidth(2);
    glColor3ub(110,49,35);
    glBegin(GL_LINES);
    glVertex2f(305, 220);
    glVertex2f(470, 120);
    glEnd();

    glLineWidth(2);
    glColor3ub(110,49,35);
    glBegin(GL_LINES);
    glVertex2f(305, 230);
    glVertex2f(500, 128);
    glEnd();

    glLineWidth(2);
    glColor3ub(110,49,35);
    glBegin(GL_LINES);
    glVertex2f(305, 238);
    glVertex2f(530, 130);
    glEnd();


    ///------hood-----
    glColor3ub(254, 3, 16);//red
    glBegin(GL_QUADS);
    glVertex2f(265, 160);
    glVertex2f(380, 160);
    glVertex2f(400, 114);
    glVertex2f(280, 110);
    glEnd();

    glColor3ub(200,100,0);//brown
    glBegin(GL_TRIANGLES);
    glVertex2f(265, 160);
    glVertex2f(240, 132);
    glVertex2f(280, 110);
    glEnd();

    glPopMatrix();
}

void draw_day_river(){

    ///------------River--------------
    glColor3ub(41,169,221);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(1150, 0);
    glVertex2f(1150, 200);
    glVertex2f(0, 300);
    glVertex2f(225, 271);
    glVertex2f(466, 270);
    glEnd();

    glLineWidth(7);
    glColor3ub(122,202,238);
    glBegin(GL_LINES);
    glVertex2f(0, 284);
    glVertex2f(232, 255);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(232, 255);
    glVertex2f(472, 255);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(472, 255);
    glVertex2f(1150, 195);
    glEnd();

}

void draw_night_river(){

    ///------------River--------------
    glColor3ub(10,10,50);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(1150, 0);
    glVertex2f(1150, 200);
    glVertex2f(0, 300);
    glVertex2f(225, 271);
    glVertex2f(466, 270);
    glEnd();

    glLineWidth(7);
    glColor3ub(56,112,118);
    glBegin(GL_LINES);
    glVertex2f(0, 284);
    glVertex2f(232, 255);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(232, 255);
    glVertex2f(472, 255);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(472, 255);
    glVertex2f(1150, 195);
    glEnd();

}

void draw_tree() {

    ///------leaf 3rd layer shade-------
    glColor3ub(53,127,11);
    circle(25,25,630, 495);
    circle(18,18,600, 480);
    circle(18,18,580, 460);
    circle(18,18,570, 440);
    circle(18,18,590, 420);
    circle(18,18,615, 410);
    circle(18,18,640, 415);
    circle(20,20,666, 420);
    circle(20,20,695, 415);
    circle(20,20,725, 415);
    circle(20,20,750, 425);
    circle(20,20,750, 445);
    circle(20,20,735, 470);
    circle(20,20,710, 490);
    circle(30,30,670, 500);

    ///------leaf 2nd layer shade-------
    glColor3ub(98,169,41);
    circle(20,20,730, 445);
    glColor3ub(53,127,11);
    circle(18,18,720, 445);
    glColor3ub(98,169,41);
    circle(18,18,710, 445);
    glColor3ub(98,169,41);
    circle(15,15,730, 470);
    glColor3ub(98,169,41);
    circle(18,18,705, 485);
    glColor3ub(98,169,41);
    circle(30,30,670, 485);
    glColor3ub(53,127,11);
    circle(25,18,695, 460);
    glColor3ub(98,169,41);
    circle(18,18,695, 465);

    glColor3ub(142,205,68);
    circle(25,15,670, 490);

    glColor3ub(98,169,41);
    circle(15,15,700, 435);
    glColor3ub(98,169,41);
    circle(18,18,680, 430);


    glColor3ub(142,205,68);
    circle(25,15,670, 490);
    circle(18,18,620, 480);
    circle(18,18,600, 460);
    circle(18,18,590, 440);
    circle(18,18,610, 430);
    circle(18,18,630, 430);
    circle(18,18,630, 450);
    circle(18,18,650, 450);
    circle(18,18,660, 455);
    circle(18,18,640, 470);


    glColor3ub(53,127,11);
    circle(20,20,600, 445);
    glColor3ub(142,205,68);
    circle(18,18,610, 445);

    glColor3ub(53,127,11);
    circle(20,20,650, 445);
    glColor3ub(142,205,68);
    circle(18,18,655, 445);

    glColor3ub(209,245,134);
    circle(10,5,630, 470);

    glColor3ub(209,245,134);
    circle(10,5,620, 430);

    glColor3ub(209,245,134);
    circle(5,2,670, 490);


    ///------wood-------------
    glBegin(GL_POLYGON);
    glColor3ub(177,125,76);
    glVertex2f(672, 392);
    glVertex2f(665, 405);
    glVertex2f(667, 408);
    glVertex2f(676, 399);
    glVertex2f(682, 411);
    glVertex2f(684, 409);
    glVertex2f(680, 395);
    glVertex2f(681, 360);
    glVertex2f(672, 360);
    glEnd();

}

void draw_forest() {

    ///------mountain bush--------

    glBegin(GL_POLYGON);
    glColor3ub(65,160,70);
    glVertex2f(1150, 372);
    glVertex2f(1150, 450);
    glVertex2f(600, 372);

    glEnd();

    /// ---------------------
    glColor3ub(65,160,70);
    circle(18,18,0,380);
    circle(18,18,30,380);
    circle(72,25,100,380);
    circle(18,28,180,380);
    circle(18,18,200,380);
    circle(25,25,240,380);
    circle(18,18,280,380);
    circle(30,30,320,380);
    circle(20,20,365,380);
    circle(25,18,405,380);
    circle(36,36,450,370);
    circle(20,36,500,380);
    circle(18,18,530,380);
    circle(20,20,560,380);
    circle(20,20,590,360);
    circle(20,10,600,380);
    circle(18,10,620,380);
    circle(20,20,650,370);
    circle(20,20,680,370);
    circle(20,30,700,370);
    circle(20,30,720,370);
    circle(20,30,740,370);
    circle(20,40,760,380);
    circle(40,20,790,380);
    circle(40,30,810,380);



    ///------First tree --------
    draw_tree();
    ///------second tree --------
    glPushMatrix();
    glTranslated(190,10,0);
    draw_tree();
    glPopMatrix();

    ///------third tree --------
    glPushMatrix();
    glTranslated(380,0,0);
    draw_tree();

}

void draw_day_sky() {
    ///----------------Sky-------------
    glBegin(GL_POLYGON);
    glColor3ub(255, 255, 147);
    glVertex2f(0, 300);
    glVertex2f(1150, 300);
    glColor3ub(102, 204, 255);
    glVertex2f(1150, 750);
    glVertex2f(0, 750);
    glEnd();
}

void draw_night_sky() {
    ///----------------Sky-------------
    glBegin(GL_POLYGON);
    glColor3ub(0, 0, 64);
    glVertex2f(0, 300);
    glVertex2f(1150, 300);
    glColor3ub(32, 32, 64);
    glVertex2f(1150, 750);
    glVertex2f(0, 750);
    glEnd();
}

void draw_sun() {
    /// ---------Sun------------
    glColor3ub(253, 183, 77);
    circle(36,36,750,sunny);
}

void draw_moon() {
    /// ---------moon------------
    glColor3ub(255, 255, 170);
    circle(36,36,750,moony);
}

void draw_star() {

    glColor3ub(255, 255, 255);

    circle(2,2.3,50, stary);
    circle(2,2.3,337, stary);
    circle(2,2.3,625, stary);
    circle(2,2.3,912, stary);

    circle(2.5,2.3,193.5, stary-40);
    circle(2.5,2.3,481, stary-40);
    circle(2.5,2.3,798, stary-40);
    circle(2.5,2.3,1056, stary-40);
    circle(2.5,2.3,700, stary-40);


    circle(2.5,2.3,103.5, stary-80);
    circle(2.5,2.3,301, stary-80);
    circle(2.5,2.3,568, stary-80);
    circle(2.5,2.3,906, stary-80);
    circle(2.5,2.3,1115, stary-80);

    circle(2.5,2.3,203.5, stary-120);
    circle(2.5,2.3,401, stary-120);
    circle(2.5,2.3,1000, stary-120);
}


void draw_cloud(){

    ///--------------cloud drawing--------

    ///--------sun covering by cloud-------
    glColor3ub(254,255,254);
    circle(30,30,1000+ cloudXOffset,640);
    circle(30,20,965+ cloudXOffset,665);
    circle(35,35,930+ cloudXOffset,670);
    circle(20,18,890+ cloudXOffset,675);
    circle(20,20,865+ cloudXOffset,680);
    circle(30,30,830+ cloudXOffset,680);
    circle(20,20,800+ cloudXOffset,665);
    circle(10,10,780+ cloudXOffset,650);
    circle(20,10,770+ cloudXOffset,640);
    circle(20,10,740+ cloudXOffset,630);
    circle(20,10,810+ cloudXOffset,640);
    circle(20,20,810+ cloudXOffset,640);
    glColor3ub(232,241,255);
    circle(20,5,740+ cloudXOffset,625);
    circle(12,12,762+ cloudXOffset,630);
    circle(20,20,785+ cloudXOffset,630);
    circle(12,12,810+ cloudXOffset,625);
    circle(20,20,835+ cloudXOffset,615);
    circle(20,20,865+ cloudXOffset,620);
    circle(15,15,890+ cloudXOffset,615);
    circle(30,30,920+ cloudXOffset,625);
    circle(15,15,955+ cloudXOffset,625);
    circle(30,20,990+ cloudXOffset,625);
    circle(15,15,1012+ cloudXOffset,630);
    circle(15,15,1016+ cloudXOffset,639);
    circle(15,15,835+ cloudXOffset,639);
    circle(20,15,865+ cloudXOffset,640);
    circle(20,20,890+ cloudXOffset,645);
    circle(15,20,855+ cloudXOffset,655);
    circle(30,19,890+ cloudXOffset,655);
    circle(30,19,950+ cloudXOffset,635);


    ///--------cloud-------

    ///--------BASE---------
    glColor3ub(254,255,254);
    circle(30,30,300+ cloudXOffset,640);
    circle(30,20,265+ cloudXOffset,665);
    circle(35,35,230+ cloudXOffset,670);
    circle(20,18,190+ cloudXOffset,675);
    circle(20,20,165+ cloudXOffset,680);
    circle(30,30,130+ cloudXOffset,680);
    circle(20,20,100+ cloudXOffset,665);
    circle(10,10,80+ cloudXOffset,650);
    circle(20,20,70+ cloudXOffset,625);
    circle(20,10,110+ cloudXOffset,640);
    circle(20,20,110+ cloudXOffset,640);
    circle(20,20,65+ cloudXOffset,610);
    circle(20,20,200+ cloudXOffset,640);
    ///------Second layer-----
    glColor3ub(232,241,255);
    circle(20,20,70+ cloudXOffset,610);
    circle(20,20,90+ cloudXOffset,630);
    circle(20,20,100+ cloudXOffset,620);
    circle(20,20,100+ cloudXOffset,610);
    circle(12,12,110+ cloudXOffset,625);
    circle(20,20,135+ cloudXOffset,615);
    circle(20,20,165+ cloudXOffset,620);
    circle(30,30,130+ cloudXOffset,610);
    circle(15,15,190+ cloudXOffset,615);
    circle(30,30,220+ cloudXOffset,625);
    circle(15,15,255+ cloudXOffset,625);
    circle(30,20,290+ cloudXOffset,625);
    circle(15,15,312+ cloudXOffset,630);
    circle(15,15,316+ cloudXOffset,639);
    circle(15,15,135+ cloudXOffset,639);
    circle(20,15,165+ cloudXOffset,640);
    circle(20,20,190+ cloudXOffset,645);
    circle(15,20,155+ cloudXOffset,655);
    circle(30,19,190+ cloudXOffset,655);
    circle(30,19,250+ cloudXOffset,635);
    circle(40,20,220+ cloudXOffset,610);
    circle(20,20,260+ cloudXOffset,610);
    circle(15,15,180+ cloudXOffset,600);
    ///------third layer-----
    glColor3ub(254,255,254);
    circle(30,10,180+ cloudXOffset,660);
    circle(30,10,270+ cloudXOffset,635);
    circle(30,10,110+ cloudXOffset,635);

}

void display_Scenario4() {
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT); // Clear the color buffer (background)

    if (is_Day) {
        draw_day_sky(); // Light blue sky

    } else {
        draw_night_sky(); // Dark night sky

    }
    // Draw the sun or moon based on the current state
    draw_sun();
    draw_moon();
    draw_star();
    draw_cloud();

    draw_forest();

    glLoadIdentity();

    if (is_Day) {
        glColor3ub(137,172,49);
        draw_day_field();
    } else {
        glColor3ub(17,75,16);
        draw_night_field();
    }

    glLoadIdentity();

    if (is_Day) {
        draw_day_river();
    } else {
        draw_night_river();
    }
        draw_river_bank();
    glLoadIdentity();
    if (is_Day) {
        draw_day_boat();
    } else {
        draw_night_boat();
    }





    glFlush(); // Render now
}


void updateAnimation(int value)
{
    // Update sun and moon positions only if animateSunMoon is true
    if (animateSunMoon) {
        if (sunToDown && sunny > 160) {
            sunny -= 10.0f;
        } else if (!sunToDown && sunny < 660) {
            sunny += 10.0f;
        }

        if (moonToUp && moony < 660) {
            moony += 10.0f;
            stary += 10.0;
        } else if (!moonToUp && moony > 160) {
            moony -= 10.0f;
            stary -=10.0f;
        }

        // Stop animation when sun and moon reach their positions
        if ((sunToDown && sunny <= 160) || (!sunToDown && sunny >= 660)) {
            animateSunMoon = false;
        }
        if ((moonToUp && moony >= 660) || (!moonToUp && moony <= 160)) {
            animateSunMoon = false;
        }
    }

    // Cloud animation
    if (cloudMovingRight) {
        cloudXOffset += 2.0f;
        if (cloudXOffset > 1150) cloudXOffset = -1000;
    } else {
        cloudXOffset -= 2.0f;
        if (cloudXOffset < -1150) cloudXOffset = 1000;
    }

    // Boat animation
    if (boatMovingRight) {
        boatXOffset += 4.5f;
        if (boatXOffset > 1150) boatXOffset = -540;
    } else {
        boatXOffset -= 4.5f;
        if (boatXOffset < -700) boatXOffset = 1040;
    }

    glutPostRedisplay();
    glutTimerFunc(40, updateAnimation, 0); // Schedule the next update at a fixed interval
}








/// -----------Anay------------



GLfloat car_position = 0.0f;
GLfloat car_speed = 10;
GLfloat cloud_Position = 0.0f;

GLfloat sun_position = 0.0f;
bool cloud_MovingRight = true;

bool backimage_pointer = true;
GLfloat bird_Position = 0.0f;
bool bird_pointer = true;
GLfloat angle = 180.0f;

void bird(){

if(bird_pointer )
{
   //bird 1

   glPushMatrix();
glTranslatef(bird_Position,0, 0.0f);

glBegin(GL_POLYGON);
glColor3f(0.94f, 0.87f, 0.73f);  // RGB: (240, 222, 186)
    glVertex2f(8+1087-800, 6+200+380);
    glVertex2f(14.6171+1087-800, 5.14569+200+380);
    glVertex2f(22.1048+1087-800, 5.02227+200+380);
    glVertex2f(29.42794+1087-800, 5.76281+200+380);

       glVertex2f(31.6907+1087-800, 6.58564+200+380);
    glVertex2f(33.5832+1087-800, 9.5478+200+380);
    glVertex2f(33.21293+1087-800, 13.08595+200+380);
    glVertex2f(30.45647+1087-800, 17.11778+200+380);

      glVertex2f(25.84865+1087-800, 18.76343+200+380);
    glVertex2f(19.55405+1087-800, 19.29827+200+380);
    glVertex2f(16.87987+1087-800, 19.33941+200+380);
    glVertex2f(11.49037+1087-800, 18.26974+200+380);

       glVertex2f(6.84141+1087-800, 16.58295+200+380);
    glVertex2f(4.90778+1087-800, 14.97844+200+380);
    glVertex2f(3.13871+1087-800, 11.72829+200+380);
    glVertex2f(5.19577+1087-800, 9.05411+200+380);
    glEnd();

int i7079;

GLfloat x7079 = 297-9;
GLfloat y7079 = 586+3+4+1;
GLfloat radius7079 =2+2;
int triangleAmount7079 = 100;

GLfloat twicePi7079 = 2.0f * PI;

glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x7079, y7079);
    for(i7079 = 0; i7079 <= triangleAmount7079; i7079++) {
        glVertex2f(
            x7079 + (radius7079 * cos(i7079 * twicePi7079 / triangleAmount7079)),
            y7079 + (radius7079 * sin(i7079 * twicePi7079 / triangleAmount7079))
        );
    }
glEnd();

int i1101;

GLfloat x1101 = 297 - 9;
GLfloat y1101 = 586 + 3 + 4 + 1;
GLfloat radius1101 = 2 + 2-1-0.4;
int triangleAmount1101 = 100;

GLfloat twicePi1101 = 2.0f * PI;

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1101, y1101);
    for(i1101 = 0; i1101 <= triangleAmount1101; i1101++) {
        glVertex2f(
            x1101 + (radius1101 * cos(i1101 * twicePi1101 / triangleAmount1101)),
            y1101 + (radius1101 * sin(i1101 * twicePi1101 / triangleAmount1101))
        );
    }
glEnd();







    glBegin(GL_POLYGON);
glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
    glVertex2f(33.21293-2+1087-800, 13.08595+3+200+380);
    glVertex2f(33.21293+10+1087-800, 13.08595+3+200+380);
    glVertex2f(33.21293+3+1087-800, 13.08595-3.5+3+200+380);
    glVertex2f(33.21293+10+1087-800, 13.08595-7+3+200+380);
    glVertex2f(31.6907+1087-800, 6.58564+3+200+380);
    glEnd();

    glBegin(GL_TRIANGLES);
   glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
      //glColor3ub(255, 255, 147);
    glVertex2f(11.49037+1087-800, 18.26974+200+380);
    glVertex2f(11.49037+1087-800, 18.26974+15+200+380);
    glVertex2f(19.55405+1087-800, 19.29827+200+380);
    //glVertex2f(8+200, 15+500);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
      //glColor3ub(255, 255, 147);
    glVertex2f(14.6171+1087-800, 5.14569+200+380);
    glVertex2f(22.47507+1087-800, 5.10455-15+200+380);
    glVertex2f(22.47507+1087-800, 5.10455+200+380);
    //glVertex2f(8+200, 15+500);
    glEnd();



 //bird 2


    //glTranslatef(0.0f, 200, 0.0f);

glBegin(GL_POLYGON);
glColor3f(0.76f, 0.69f, 0.50f);  // RGB: (194, 176, 128)
    glVertex2f(8+1087-65-800, 6+4+200+380);
    glVertex2f(14.6171+1087-65-800, 5.14569+4+200+380);
    glVertex2f(22.1048+1087-65-800, 5.02227+4+200+380);
    glVertex2f(29.42794+1087-65-800, 5.7628+4+200+380);

       glVertex2f(31.6907+1087-65-800, 6.58564+4+200+380);
    glVertex2f(33.5832+1087-65-800, 9.5478+4+200+380);
    glVertex2f(33.21293+1087-65-800, 13.08595+4+200+380);
    glVertex2f(30.45647+1087-65-800, 17.11778+4+200+380);

      glVertex2f(25.84865+1087-65-800, 18.76343+4+200+380);
    glVertex2f(19.55405+1087-65-800, 19.29827+4+200+380);
    glVertex2f(16.87987+1087-65-800, 19.33941+4+200+380);
    glVertex2f(11.49037+1087-65-800, 18.26974+4+200+380);

       glVertex2f(6.84141+1087-65-800, 16.58295+4+200+380);
    glVertex2f(4.90778+1087-65-800, 14.97844+4+200+380);
    glVertex2f(3.13871+1087-65-800, 11.72829+4+200+380);
    glVertex2f(5.19577+1087-65-800, 9.05411+4+200+380);
    glEnd();

    int i7709;

GLfloat x7709 = 230-9;
GLfloat y7709 = 590 + 3 + 4;
GLfloat radius7709 = 2+2;
int triangleAmount7709 = 100;

GLfloat twicePi7709 = 2.0f * PI;

glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x7709, y7709);
    for(i7709 = 0; i7709 <= triangleAmount7709; i7709++) {
        glVertex2f(
            x7709 + (radius7709 * cos(i7709 * twicePi7709 / triangleAmount7709)),
            y7709 + (radius7709 * sin(i7709 * twicePi7709 / triangleAmount7709))
        );
    }
glEnd();



int i7897;

GLfloat x7897 = 230 - 9;
GLfloat y7897 = 590 + 3 + 4;
GLfloat radius7897 = 2 + 2-1.4;
int triangleAmount7897 = 100;

GLfloat twicePi7897 = 2.0f * PI;

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x7897, y7897);
    for(i7897 = 0; i7897 <= triangleAmount7897; i7897++) {
        glVertex2f(
            x7897 + (radius7897 * cos(i7897 * twicePi7897 / triangleAmount7897)),
            y7897 + (radius7897 * sin(i7897 * twicePi7897 / triangleAmount7897))
        );
    }
glEnd();

    glBegin(GL_POLYGON);
glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
    glVertex2f(33.21293-2+1087-65-800, 13.08595+3+4+200+380);
    glVertex2f(33.21293+10+1087-65-800, 13.08595+3+4+200+380);
    glVertex2f(33.21293+3+1087-65-800, 13.08595-3.5+3+4+200+380);
    glVertex2f(33.21293+10+1087-65-800, 13.08595-7+3+4+200+380);
    glVertex2f(31.6907+1087-65-800, 6.58564+3+200+380);
    glEnd();

    glBegin(GL_TRIANGLES);
   glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
      //glColor3ub(255, 255, 147);
    glVertex2f(11.49037+1087-65-800, 18.26974+4+200+380);
    glVertex2f(11.49037+1087-65-800, 18.26974+15+4+200+380);
    glVertex2f(19.55405+1087-65-800, 19.29827+4+200+380);
    //glVertex2f(8+200, 15+500);
    glEnd();

    glBegin(GL_TRIANGLES);
     glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
      //glColor3ub(255, 255, 147);
    glVertex2f(14.6171+1087-65-800, 5.14569+4+200+380);
    glVertex2f(22.47507+1087-65-800, 5.10455-15+4+200+380);
    glVertex2f(22.47507+1087-65-800, 5.10455+4+200+380);
    //glVertex2f(8+200, 15+500);
    glEnd();


 //bird 3




glBegin(GL_POLYGON);
glColor3f(0.87f, 0.72f, 0.53f);  // RGB: (222, 183, 135)
    glVertex2f(8+1087-65-65-800, 6+4-10-2+200+380);
    glVertex2f(14.6171+1087-65-65-800, 5.14569+4-10-2+200+380);
    glVertex2f(22.1048+1087-65-65-800, 5.02227+4-10-2+200+380);
    glVertex2f(29.42794+1087-65-65-800, 5.7628+4-10-2+200+380);

       glVertex2f(31.6907+1087-65-65-800, 6.58564+4-10-2+200+380);
    glVertex2f(33.5832+1087-65-65-800, 9.5478+4-10-2+200+380);
    glVertex2f(33.21293+1087-65-65-800, 13.08595+4-10-2+200+380);
    glVertex2f(30.45647+1087-65-65-800, 17.11778+4-10-2+200+380);

      glVertex2f(25.84865+1087-65-65-800, 18.76343+4-10-2+200+380);
    glVertex2f(19.55405+1087-65-65-800, 19.29827+4-10-2+200+380);
    glVertex2f(16.87987+1087-65-65-800, 19.33941+4-10-2+200+380);
    glVertex2f(11.49037+1087-65-65-800, 18.26974+4-10-2+200+380);

       glVertex2f(6.84141+1087-65-65-800, 16.58295+4-10-2+200+380);
    glVertex2f(4.90778+1087-65-65-800, 14.97844+4-10-2+200+380);
    glVertex2f(3.13871+1087-65-65-800, 11.72829+4-10-2+200+380);
    glVertex2f(5.19577+1087-65-65-800, 9.05411+4-10-2+200+380);
    glEnd();

    int i7909;

GLfloat x7909 = 165-9;
GLfloat y7909 = 578 + 3 + 4;
GLfloat radius7909 = 2+2;
int triangleAmount7909 = 100;

GLfloat twicePi7909 = 2.0f * PI;

glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x7909, y7909);
    for(i7909 = 0; i7909 <= triangleAmount7909; i7909++) {
        glVertex2f(
            x7909 + (radius7909 * cos(i7909 * twicePi7909 / triangleAmount7909)),
            y7909 + (radius7909 * sin(i7909 * twicePi7909 / triangleAmount7909))
        );
    }
glEnd();

int i7689;

GLfloat x7689 = 165 - 9;
GLfloat y7689 = 578 + 3 + 4;
GLfloat radius7689 = 2 + 2-1.4;
int triangleAmount7689 = 100;

GLfloat twicePi7689 = 2.0f * PI;

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x7689, y7689);
    for(i7689 = 0; i7689 <= triangleAmount7689; i7689++) {
        glVertex2f(
            x7689 + (radius7689 * cos(i7689 * twicePi7689 / triangleAmount7689)),
            y7689 + (radius7689 * sin(i7689 * twicePi7689 / triangleAmount7689))
        );
    }
glEnd();

    glBegin(GL_POLYGON);
glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
    glVertex2f(33.21293-2+1087-65-65-800, 13.08595+3+4-10-2+200+380);
    glVertex2f(33.21293+10+1087-65-65-800, 13.08595+3+4-10-2+200+380);
    glVertex2f(33.21293+3+1087-65-65-800, 13.08595-3.5+3+4-10-2+200+380);
    glVertex2f(33.21293+10+1087-65-65-800, 13.08595-7+3+4-10-2+200+380);
    glVertex2f(31.6907+1087-65-65-800, 6.58564+3-10-2+200+380);
    glEnd();

    glBegin(GL_TRIANGLES);
     glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
      //glColor3ub(255, 255, 147);
    glVertex2f(11.49037+1087-65-65-800, 18.26974+4-10-2+200+380);
    glVertex2f(11.49037+1087-65-65-800, 18.26974+15+4-10-2+200+380);
    glVertex2f(19.55405+1087-65-65-800, 19.29827+4-10-2+200+380);
    //glVertex2f(8+200, 15+500);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
      //glColor3ub(255, 255, 147);
    glVertex2f(14.6171+1087-65-65-800, 5.14569+4-10-2+200+380);
    glVertex2f(22.47507+1087-65-65-800, 5.10455-15+4-10-2+200+380);
    glVertex2f(22.47507+1087-65-65-800, 5.10455+4-10-2+200+380);
    //glVertex2f(8+200, 15+500);
    glEnd();




    //bird 6


//glTranslatef(0.0f, 380, 0.0f);
glBegin(GL_POLYGON);
glColor3f(0.65f, 0.50f, 0.39f);  // RGB: (166, 127, 100)
    glVertex2f(8+1087, 6+200+380);
    glVertex2f(14.6171+1087, 5.14569+200+380);
    glVertex2f(22.1048+1087, 5.02227+200+380);
    glVertex2f(29.42794+1087, 5.76281+200+380);

       glVertex2f(31.6907+1087, 6.58564+200+380);
    glVertex2f(33.5832+1087, 9.5478+200+380);
    glVertex2f(33.21293+1087, 13.08595+200+380);
    glVertex2f(30.45647+1087, 17.11778+200+380);

      glVertex2f(25.84865+1087, 18.76343+200+380);
    glVertex2f(19.55405+1087, 19.29827+200+380);
    glVertex2f(16.87987+1087, 19.33941+200+380);
    glVertex2f(11.49037+1087, 18.26974+200+380);

       glVertex2f(6.84141+1087, 16.58295+200+380);
    glVertex2f(4.90778+1087, 14.97844+200+380);
    glVertex2f(3.13871+1087, 11.72829+200+380);
    glVertex2f(5.19577+1087, 9.05411+200+380);
    glEnd();

    int i9799;

GLfloat x9799 = 1095-9;
GLfloat y9799 = 586 + 3 + 4;
GLfloat radius9799 = 2+2;
int triangleAmount9799 = 100;

GLfloat twicePi9799 = 2.0f * PI;

glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x9799, y9799);
    for(i9799 = 0; i9799 <= triangleAmount9799; i9799++) {
        glVertex2f(
            x9799 + (radius9799 * cos(i9799 * twicePi9799 / triangleAmount9799)),
            y9799 + (radius9799 * sin(i9799 * twicePi9799 / triangleAmount9799))
        );
    }
glEnd();

int i9299;

GLfloat x9299 = 1095 - 9;
GLfloat y9299 = 586 + 3 + 4;
GLfloat radius9299 = 2 + 2-1.4;
int triangleAmount9299 = 100;

GLfloat twicePi9299 = 2.0f * PI;

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x9299, y9299);
    for(i9299 = 0; i9299 <= triangleAmount9299; i9299++) {
        glVertex2f(
            x9299 + (radius9299 * cos(i9299 * twicePi9299 / triangleAmount9299)),
            y9299 + (radius9299 * sin(i9299 * twicePi9299 / triangleAmount9299))
        );
    }
glEnd();

    glBegin(GL_POLYGON);
glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
    glVertex2f(33.21293-2+1087, 13.08595+3+200+380);
    glVertex2f(33.21293+10+1087, 13.08595+3+200+380);
    glVertex2f(33.21293+3+1087, 13.08595-3.5+3+200+380);
    glVertex2f(33.21293+10+1087, 13.08595-7+3+200+380);
    glVertex2f(31.6907+1087, 6.58564+3+200+380);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
      //glColor3ub(255, 255, 147);
    glVertex2f(11.49037+1087, 18.26974+200+380);
    glVertex2f(11.49037+1087, 18.26974+15+200+380);
    glVertex2f(19.55405+1087, 19.29827+200+380);
    //glVertex2f(8+200, 15+500);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
      //glColor3ub(255, 255, 147);
    glVertex2f(14.6171+1087, 5.14569+200+380);
    glVertex2f(22.47507+1087, 5.10455-15+200+380);
    glVertex2f(22.47507+1087, 5.10455+200+380);
    //glVertex2f(8+200, 15+500);
    glEnd();



 //bird 5


    //glTranslatef(0.0f, 200, 0.0f);

glBegin(GL_POLYGON);
	glColor3f(0.87f, 0.72f, 0.53f);  // RGB: (222, 183, 135)
    glVertex2f(8+1087-65, 6+4+200+380);
    glVertex2f(14.6171+1087-65, 5.14569+4+200+380);
    glVertex2f(22.1048+1087-65, 5.02227+4+200+380);
    glVertex2f(29.42794+1087-65, 5.7628+4+200+380);

       glVertex2f(31.6907+1087-65, 6.58564+4+200+380);
    glVertex2f(33.5832+1087-65, 9.5478+4+200+380);
    glVertex2f(33.21293+1087-65, 13.08595+4+200+380);
    glVertex2f(30.45647+1087-65, 17.11778+4+200+380);

      glVertex2f(25.84865+1087-65, 18.76343+4+200+380);
    glVertex2f(19.55405+1087-65, 19.29827+4+200+380);
    glVertex2f(16.87987+1087-65, 19.33941+4+200+380);
    glVertex2f(11.49037+1087-65, 18.26974+4+200+380);

       glVertex2f(6.84141+1087-65, 16.58295+4+200+380);
    glVertex2f(4.90778+1087-65, 14.97844+4+200+380);
    glVertex2f(3.13871+1087-65, 11.72829+4+200+380);
    glVertex2f(5.19577+1087-65, 9.05411+4+200+380);
    glEnd();

    int i9899;

GLfloat x9899 = 1030-9;
GLfloat y9899 = 590 + 3 + 4;
GLfloat radius9899 = 2+2;
int triangleAmount9899 = 100;

GLfloat twicePi9899 = 2.0f * PI;

glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x9899, y9899);
    for(i9899 = 0; i9899 <= triangleAmount9899; i9899++) {
        glVertex2f(
            x9899 + (radius9899 * cos(i9899 * twicePi9899 / triangleAmount9899)),
            y9899 + (radius9899 * sin(i9899 * twicePi9899 / triangleAmount9899))
        );
    }
glEnd();

int i88123;

GLfloat x88123 = 1030 - 9;
GLfloat y88123 = 590 + 3 + 4;
GLfloat radius88123 = 2 + 2-1.4;
int triangleAmount88123 = 100;

GLfloat twicePi88123 = 2.0f * PI;

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x88123, y88123);
    for(i88123 = 0; i88123 <= triangleAmount88123; i88123++) {
        glVertex2f(
            x88123 + (radius88123 * cos(i88123 * twicePi88123 / triangleAmount88123)),
            y88123 + (radius88123 * sin(i88123 * twicePi88123 / triangleAmount88123))
        );
    }
glEnd();


    glBegin(GL_POLYGON);
glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
    glVertex2f(33.21293-2+1087-65, 13.08595+3+4+200+380);
    glVertex2f(33.21293+10+1087-65, 13.08595+3+4+200+380);
    glVertex2f(33.21293+3+1087-65, 13.08595-3.5+3+4+200+380);
    glVertex2f(33.21293+10+1087-65, 13.08595-7+3+4+200+380);
    glVertex2f(31.6907+1087-65, 6.58564+3+200+380);
    glEnd();

    glBegin(GL_TRIANGLES);
     glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
      //glColor3ub(255, 255, 147);
    glVertex2f(11.49037+1087-65, 18.26974+4+200+380);
    glVertex2f(11.49037+1087-65, 18.26974+15+4+200+380);
    glVertex2f(19.55405+1087-65, 19.29827+4+200+380);
    //glVertex2f(8+200, 15+500);
    glEnd();

    glBegin(GL_TRIANGLES);
     glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
      //glColor3ub(255, 255, 147);
    glVertex2f(14.6171+1087-65, 5.14569+4+200+380);
    glVertex2f(22.47507+1087-65, 5.10455-15+4+200+380);
    glVertex2f(22.47507+1087-65, 5.10455+4+200+380);
    //glVertex2f(8+200, 15+500);
    glEnd();


 //bird 4




glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.75f, 1.0f);
    glVertex2f(8+1087-65-65, 6+4-10-2+200+380);
    glVertex2f(14.6171+1087-65-65, 5.14569+4-10-2+200+380);
    glVertex2f(22.1048+1087-65-65, 5.02227+4-10-2+200+380);
    glVertex2f(29.42794+1087-65-65, 5.7628+4-10-2+200+380);

       glVertex2f(31.6907+1087-65-65, 6.58564+4-10-2+200+380);
    glVertex2f(33.5832+1087-65-65, 9.5478+4-10-2+200+380);
    glVertex2f(33.21293+1087-65-65, 13.08595+4-10-2+200+380);
    glVertex2f(30.45647+1087-65-65, 17.11778+4-10-2+200+380);

      glVertex2f(25.84865+1087-65-65, 18.76343+4-10-2+200+380);
    glVertex2f(19.55405+1087-65-65, 19.29827+4-10-2+200+380);
    glVertex2f(16.87987+1087-65-65, 19.33941+4-10-2+200+380);
    glVertex2f(11.49037+1087-65-65, 18.26974+4-10-2+200+380);

       glVertex2f(6.84141+1087-65-65, 16.58295+4-10-2+200+380);
    glVertex2f(4.90778+1087-65-65, 14.97844+4-10-2+200+380);
    glVertex2f(3.13871+1087-65-65, 11.72829+4-10-2+200+380);
    glVertex2f(5.19577+1087-65-65, 9.05411+4-10-2+200+380);
    glEnd();

    int i9989;

GLfloat x9989 = 965-9;
GLfloat y9989 = 578 + 3 + 4;
GLfloat radius9989 = 2+2;
int triangleAmount9989 = 100;

GLfloat twicePi9989 = 2.0f * PI;

glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x9989, y9989);
    for(i9989 = 0; i9989 <= triangleAmount9989; i9989++) {
        glVertex2f(
            x9989 + (radius9989 * cos(i9989 * twicePi9989 / triangleAmount9989)),
            y9989 + (radius9989 * sin(i9989 * twicePi9989 / triangleAmount9989))
        );
    }
glEnd();

int i1467;

GLfloat x1467 = 965 - 9;
GLfloat y1467 = 578 + 3 + 4;
GLfloat radius1467 = 2 + 2-1.4;
int triangleAmount1467 = 100;

GLfloat twicePi1467 = 2.0f * PI;

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1467, y1467);
    for(i1467 = 0; i1467 <= triangleAmount1467; i1467++) {
        glVertex2f(
            x1467 + (radius1467 * cos(i1467 * twicePi1467 / triangleAmount1467)),
            y1467 + (radius1467 * sin(i1467 * twicePi1467 / triangleAmount1467))
        );
    }
glEnd();


    glBegin(GL_POLYGON);
glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
    glVertex2f(33.21293-2+1087-65-65, 13.08595+3+4-10-2+200+380);
    glVertex2f(33.21293+10+1087-65-65, 13.08595+3+4-10-2+200+380);
    glVertex2f(33.21293+3+1087-65-65, 13.08595-3.5+3+4-10-2+200+380);
    glVertex2f(33.21293+10+1087-65-65, 13.08595-7+3+4-10-2+200+380);
    glVertex2f(31.6907+1087-65-65, 6.58564+3-10-2+200+380);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
      //glColor3ub(255, 255, 147);
    glVertex2f(11.49037+1087-65-65, 18.26974+4-10-2+200+380);
    glVertex2f(11.49037+1087-65-65, 18.26974+15+4-10-2+200+380);
    glVertex2f(19.55405+1087-65-65, 19.29827+4-10-2+200+380);
    //glVertex2f(8+200, 15+500);
    glEnd();

glBegin(GL_TRIANGLES);
     glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
      //glColor3ub(255, 255, 147);
    glVertex2f(14.6171+1087-65-65, 5.14569+4-10-2+200+380);
    glVertex2f(22.47507+1087-65-65, 5.10455-15+4-10-2+200+380);
    glVertex2f(22.47507+1087-65-65, 5.10455+4-10-2+200+380);
    //glVertex2f(8+200, 15+500);
    glEnd();
 glPopMatrix();
}
else{
    //bird 1


//glTranslatef(0.0f, 380, 0.0f);
   glPushMatrix();
//glTranslatef(bird_Position,0, 0.0f);

glBegin(GL_POLYGON);
glColor3f(0.94f, 0.87f, 0.73f);  // RGB: (240, 222, 186)
    glVertex2f(8+1087-800, 6+200+380);
    glVertex2f(14.6171+1087-800, 5.14569+200+380);
    glVertex2f(22.1048+1087-800, 5.02227+200+380);
    glVertex2f(29.42794+1087-800, 5.76281+200+380);

       glVertex2f(31.6907+1087-800, 6.58564+200+380);
    glVertex2f(33.5832+1087-800, 9.5478+200+380);
    glVertex2f(33.21293+1087-800, 13.08595+200+380);
    glVertex2f(30.45647+1087-800, 17.11778+200+380);

      glVertex2f(25.84865+1087-800, 18.76343+200+380);
    glVertex2f(19.55405+1087-800, 19.29827+200+380);
    glVertex2f(16.87987+1087-800, 19.33941+200+380);
    glVertex2f(11.49037+1087-800, 18.26974+200+380);

       glVertex2f(6.84141+1087-800, 16.58295+200+380);
    glVertex2f(4.90778+1087-800, 14.97844+200+380);
    glVertex2f(3.13871+1087-800, 11.72829+200+380);
    glVertex2f(5.19577+1087-800, 9.05411+200+380);
    glEnd();

int i7079;

GLfloat x7079 = 297;
GLfloat y7079 = 586+3+4;
GLfloat radius7079 =2;
int triangleAmount7079 = 100;

GLfloat twicePi7079 = 2.0f * PI;

glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x7079, y7079);
    for(i7079 = 0; i7079 <= triangleAmount7079; i7079++) {
        glVertex2f(
            x7079 + (radius7079 * cos(i7079 * twicePi7079 / triangleAmount7079)),
            y7079 + (radius7079 * sin(i7079 * twicePi7079 / triangleAmount7079))
        );
    }
glEnd();
    glBegin(GL_POLYGON);
glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
    glVertex2f(33.21293-2+1087-800, 13.08595+3+200+380);
    glVertex2f(33.21293+10+1087-800, 13.08595+3+200+380);
    glVertex2f(33.21293+3+1087-800, 13.08595-3.5+3+200+380);
    glVertex2f(33.21293+10+1087-800, 13.08595-7+3+200+380);
    glVertex2f(31.6907+1087-800, 6.58564+3+200+380);
    glEnd();

    glBegin(GL_TRIANGLES);
   glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
      //glColor3ub(255, 255, 147);
    glVertex2f(11.49037+1087-800, 18.26974+200+380);
    glVertex2f(11.49037+1087-800, 18.26974+15+200+380);
    glVertex2f(19.55405+1087-800, 19.29827+200+380);
    //glVertex2f(8+200, 15+500);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
      //glColor3ub(255, 255, 147);
    glVertex2f(14.6171+1087-800, 5.14569+200+380);
    glVertex2f(22.47507+1087-800, 5.10455-15+200+380);
    glVertex2f(22.47507+1087-800, 5.10455+200+380);
    //glVertex2f(8+200, 15+500);
    glEnd();



 //bird 2


    //glTranslatef(0.0f, 200, 0.0f);

glBegin(GL_POLYGON);
glColor3f(0.76f, 0.69f, 0.50f);  // RGB: (194, 176, 128)
    glVertex2f(8+1087-65-800, 6+4+200+380);
    glVertex2f(14.6171+1087-65-800, 5.14569+4+200+380);
    glVertex2f(22.1048+1087-65-800, 5.02227+4+200+380);
    glVertex2f(29.42794+1087-65-800, 5.7628+4+200+380);

       glVertex2f(31.6907+1087-65-800, 6.58564+4+200+380);
    glVertex2f(33.5832+1087-65-800, 9.5478+4+200+380);
    glVertex2f(33.21293+1087-65-800, 13.08595+4+200+380);
    glVertex2f(30.45647+1087-65-800, 17.11778+4+200+380);

      glVertex2f(25.84865+1087-65-800, 18.76343+4+200+380);
    glVertex2f(19.55405+1087-65-800, 19.29827+4+200+380);
    glVertex2f(16.87987+1087-65-800, 19.33941+4+200+380);
    glVertex2f(11.49037+1087-65-800, 18.26974+4+200+380);

       glVertex2f(6.84141+1087-65-800, 16.58295+4+200+380);
    glVertex2f(4.90778+1087-65-800, 14.97844+4+200+380);
    glVertex2f(3.13871+1087-65-800, 11.72829+4+200+380);
    glVertex2f(5.19577+1087-65-800, 9.05411+4+200+380);
    glEnd();

    int i7709;

GLfloat x7709 = 230;
GLfloat y7709 = 590 + 3 + 4;
GLfloat radius7709 = 2;
int triangleAmount7709 = 100;

GLfloat twicePi7709 = 2.0f * PI;

glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x7709, y7709);
    for(i7709 = 0; i7709 <= triangleAmount7709; i7709++) {
        glVertex2f(
            x7709 + (radius7709 * cos(i7709 * twicePi7709 / triangleAmount7709)),
            y7709 + (radius7709 * sin(i7709 * twicePi7709 / triangleAmount7709))
        );
    }
glEnd();

    glBegin(GL_POLYGON);
glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
    glVertex2f(33.21293-2+1087-65-800, 13.08595+3+4+200+380);
    glVertex2f(33.21293+10+1087-65-800, 13.08595+3+4+200+380);
    glVertex2f(33.21293+3+1087-65-800, 13.08595-3.5+3+4+200+380);
    glVertex2f(33.21293+10+1087-65-800, 13.08595-7+3+4+200+380);
    glVertex2f(31.6907+1087-65-800, 6.58564+3+200+380);
    glEnd();

    glBegin(GL_TRIANGLES);
   glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
      //glColor3ub(255, 255, 147);
    glVertex2f(11.49037+1087-65-800, 18.26974+4+200+380);
    glVertex2f(11.49037+1087-65-800, 18.26974+15+4+200+380);
    glVertex2f(19.55405+1087-65-800, 19.29827+4+200+380);
    //glVertex2f(8+200, 15+500);
    glEnd();

    glBegin(GL_TRIANGLES);
     glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
      //glColor3ub(255, 255, 147);
    glVertex2f(14.6171+1087-65-800, 5.14569+4+200+380);
    glVertex2f(22.47507+1087-65-800, 5.10455-15+4+200+380);
    glVertex2f(22.47507+1087-65-800, 5.10455+4+200+380);
    //glVertex2f(8+200, 15+500);
    glEnd();


 //bird 3




glBegin(GL_POLYGON);
glColor3f(0.87f, 0.72f, 0.53f);  // RGB: (222, 183, 135)
    glVertex2f(8+1087-65-65-800, 6+4-10-2+200+380);
    glVertex2f(14.6171+1087-65-65-800, 5.14569+4-10-2+200+380);
    glVertex2f(22.1048+1087-65-65-800, 5.02227+4-10-2+200+380);
    glVertex2f(29.42794+1087-65-65-800, 5.7628+4-10-2+200+380);

       glVertex2f(31.6907+1087-65-65-800, 6.58564+4-10-2+200+380);
    glVertex2f(33.5832+1087-65-65-800, 9.5478+4-10-2+200+380);
    glVertex2f(33.21293+1087-65-65-800, 13.08595+4-10-2+200+380);
    glVertex2f(30.45647+1087-65-65-800, 17.11778+4-10-2+200+380);

      glVertex2f(25.84865+1087-65-65-800, 18.76343+4-10-2+200+380);
    glVertex2f(19.55405+1087-65-65-800, 19.29827+4-10-2+200+380);
    glVertex2f(16.87987+1087-65-65-800, 19.33941+4-10-2+200+380);
    glVertex2f(11.49037+1087-65-65-800, 18.26974+4-10-2+200+380);

       glVertex2f(6.84141+1087-65-65-800, 16.58295+4-10-2+200+380);
    glVertex2f(4.90778+1087-65-65-800, 14.97844+4-10-2+200+380);
    glVertex2f(3.13871+1087-65-65-800, 11.72829+4-10-2+200+380);
    glVertex2f(5.19577+1087-65-65-800, 9.05411+4-10-2+200+380);
    glEnd();

    int i7909;

GLfloat x7909 = 165;
GLfloat y7909 = 578 + 3 + 4;
GLfloat radius7909 = 2;
int triangleAmount7909 = 100;

GLfloat twicePi7909 = 2.0f * PI;

glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x7909, y7909);
    for(i7909 = 0; i7909 <= triangleAmount7909; i7909++) {
        glVertex2f(
            x7909 + (radius7909 * cos(i7909 * twicePi7909 / triangleAmount7909)),
            y7909 + (radius7909 * sin(i7909 * twicePi7909 / triangleAmount7909))
        );
    }
glEnd();

    glBegin(GL_POLYGON);
glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
    glVertex2f(33.21293-2+1087-65-65-800, 13.08595+3+4-10-2+200+380);
    glVertex2f(33.21293+10+1087-65-65-800, 13.08595+3+4-10-2+200+380);
    glVertex2f(33.21293+3+1087-65-65-800, 13.08595-3.5+3+4-10-2+200+380);
    glVertex2f(33.21293+10+1087-65-65-800, 13.08595-7+3+4-10-2+200+380);
    glVertex2f(31.6907+1087-65-65-800, 6.58564+3-10-2+200+380);
    glEnd();

    glBegin(GL_TRIANGLES);
     glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
      //glColor3ub(255, 255, 147);
    glVertex2f(11.49037+1087-65-65-800, 18.26974+4-10-2+200+380);
    glVertex2f(11.49037+1087-65-65-800, 18.26974+15+4-10-2+200+380);
    glVertex2f(19.55405+1087-65-65-800, 19.29827+4-10-2+200+380);
    //glVertex2f(8+200, 15+500);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
      //glColor3ub(255, 255, 147);
    glVertex2f(14.6171+1087-65-65-800, 5.14569+4-10-2+200+380);
    glVertex2f(22.47507+1087-65-65-800, 5.10455-15+4-10-2+200+380);
    glVertex2f(22.47507+1087-65-65-800, 5.10455+4-10-2+200+380);
    //glVertex2f(8+200, 15+500);
    glEnd();




    //bird 6


//glTranslatef(0.0f, 380, 0.0f);
glBegin(GL_POLYGON);
glColor3f(0.65f, 0.50f, 0.39f);  // RGB: (166, 127, 100)
    glVertex2f(8+1087, 6+200+380);
    glVertex2f(14.6171+1087, 5.14569+200+380);
    glVertex2f(22.1048+1087, 5.02227+200+380);
    glVertex2f(29.42794+1087, 5.76281+200+380);

       glVertex2f(31.6907+1087, 6.58564+200+380);
    glVertex2f(33.5832+1087, 9.5478+200+380);
    glVertex2f(33.21293+1087, 13.08595+200+380);
    glVertex2f(30.45647+1087, 17.11778+200+380);

      glVertex2f(25.84865+1087, 18.76343+200+380);
    glVertex2f(19.55405+1087, 19.29827+200+380);
    glVertex2f(16.87987+1087, 19.33941+200+380);
    glVertex2f(11.49037+1087, 18.26974+200+380);

       glVertex2f(6.84141+1087, 16.58295+200+380);
    glVertex2f(4.90778+1087, 14.97844+200+380);
    glVertex2f(3.13871+1087, 11.72829+200+380);
    glVertex2f(5.19577+1087, 9.05411+200+380);
    glEnd();

    int i9799;

GLfloat x9799 = 1095;
GLfloat y9799 = 586 + 3 + 4;
GLfloat radius9799 = 2;
int triangleAmount9799 = 100;

GLfloat twicePi9799 = 2.0f * PI;

glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x9799, y9799);
    for(i9799 = 0; i9799 <= triangleAmount9799; i9799++) {
        glVertex2f(
            x9799 + (radius9799 * cos(i9799 * twicePi9799 / triangleAmount9799)),
            y9799 + (radius9799 * sin(i9799 * twicePi9799 / triangleAmount9799))
        );
    }
glEnd();

    glBegin(GL_POLYGON);
glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
    glVertex2f(33.21293-2+1087, 13.08595+3+200+380);
    glVertex2f(33.21293+10+1087, 13.08595+3+200+380);
    glVertex2f(33.21293+3+1087, 13.08595-3.5+3+200+380);
    glVertex2f(33.21293+10+1087, 13.08595-7+3+200+380);
    glVertex2f(31.6907+1087, 6.58564+3+200+380);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
      //glColor3ub(255, 255, 147);
    glVertex2f(11.49037+1087, 18.26974+200+380);
    glVertex2f(11.49037+1087, 18.26974+15+200+380);
    glVertex2f(19.55405+1087, 19.29827+200+380);
    //glVertex2f(8+200, 15+500);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
      //glColor3ub(255, 255, 147);
    glVertex2f(14.6171+1087, 5.14569+200+380);
    glVertex2f(22.47507+1087, 5.10455-15+200+380);
    glVertex2f(22.47507+1087, 5.10455+200+380);
    //glVertex2f(8+200, 15+500);
    glEnd();



 //bird 5


    //glTranslatef(0.0f, 200, 0.0f);

glBegin(GL_POLYGON);
	glColor3f(0.87f, 0.72f, 0.53f);  // RGB: (222, 183, 135)
    glVertex2f(8+1087-65, 6+4+200+380);
    glVertex2f(14.6171+1087-65, 5.14569+4+200+380);
    glVertex2f(22.1048+1087-65, 5.02227+4+200+380);
    glVertex2f(29.42794+1087-65, 5.7628+4+200+380);

       glVertex2f(31.6907+1087-65, 6.58564+4+200+380);
    glVertex2f(33.5832+1087-65, 9.5478+4+200+380);
    glVertex2f(33.21293+1087-65, 13.08595+4+200+380);
    glVertex2f(30.45647+1087-65, 17.11778+4+200+380);

      glVertex2f(25.84865+1087-65, 18.76343+4+200+380);
    glVertex2f(19.55405+1087-65, 19.29827+4+200+380);
    glVertex2f(16.87987+1087-65, 19.33941+4+200+380);
    glVertex2f(11.49037+1087-65, 18.26974+4+200+380);

       glVertex2f(6.84141+1087-65, 16.58295+4+200+380);
    glVertex2f(4.90778+1087-65, 14.97844+4+200+380);
    glVertex2f(3.13871+1087-65, 11.72829+4+200+380);
    glVertex2f(5.19577+1087-65, 9.05411+4+200+380);
    glEnd();

    int i9899;

GLfloat x9899 = 1030;
GLfloat y9899 = 590 + 3 + 4;
GLfloat radius9899 = 2;
int triangleAmount9899 = 100;

GLfloat twicePi9899 = 2.0f * PI;

glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x9899, y9899);
    for(i9899 = 0; i9899 <= triangleAmount9899; i9899++) {
        glVertex2f(
            x9899 + (radius9899 * cos(i9899 * twicePi9899 / triangleAmount9899)),
            y9899 + (radius9899 * sin(i9899 * twicePi9899 / triangleAmount9899))
        );
    }
glEnd();

    glBegin(GL_POLYGON);
glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
    glVertex2f(33.21293-2+1087-65, 13.08595+3+4+200+380);
    glVertex2f(33.21293+10+1087-65, 13.08595+3+4+200+380);
    glVertex2f(33.21293+3+1087-65, 13.08595-3.5+3+4+200+380);
    glVertex2f(33.21293+10+1087-65, 13.08595-7+3+4+200+380);
    glVertex2f(31.6907+1087-65, 6.58564+3+200+380);
    glEnd();

    glBegin(GL_TRIANGLES);
     glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
      //glColor3ub(255, 255, 147);
    glVertex2f(11.49037+1087-65, 18.26974+4+200+380);
    glVertex2f(11.49037+1087-65, 18.26974+15+4+200+380);
    glVertex2f(19.55405+1087-65, 19.29827+4+200+380);
    //glVertex2f(8+200, 15+500);
    glEnd();

    glBegin(GL_TRIANGLES);
     glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
      //glColor3ub(255, 255, 147);
    glVertex2f(14.6171+1087-65, 5.14569+4+200+380);
    glVertex2f(22.47507+1087-65, 5.10455-15+4+200+380);
    glVertex2f(22.47507+1087-65, 5.10455+4+200+380);
    //glVertex2f(8+200, 15+500);
    glEnd();


 //bird 4




glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.75f, 1.0f);
    glVertex2f(8+1087-65-65, 6+4-10-2+200+380);
    glVertex2f(14.6171+1087-65-65, 5.14569+4-10-2+200+380);
    glVertex2f(22.1048+1087-65-65, 5.02227+4-10-2+200+380);
    glVertex2f(29.42794+1087-65-65, 5.7628+4-10-2+200+380);

       glVertex2f(31.6907+1087-65-65, 6.58564+4-10-2+200+380);
    glVertex2f(33.5832+1087-65-65, 9.5478+4-10-2+200+380);
    glVertex2f(33.21293+1087-65-65, 13.08595+4-10-2+200+380);
    glVertex2f(30.45647+1087-65-65, 17.11778+4-10-2+200+380);

      glVertex2f(25.84865+1087-65-65, 18.76343+4-10-2+200+380);
    glVertex2f(19.55405+1087-65-65, 19.29827+4-10-2+200+380);
    glVertex2f(16.87987+1087-65-65, 19.33941+4-10-2+200+380);
    glVertex2f(11.49037+1087-65-65, 18.26974+4-10-2+200+380);

       glVertex2f(6.84141+1087-65-65, 16.58295+4-10-2+200+380);
    glVertex2f(4.90778+1087-65-65, 14.97844+4-10-2+200+380);
    glVertex2f(3.13871+1087-65-65, 11.72829+4-10-2+200+380);
    glVertex2f(5.19577+1087-65-65, 9.05411+4-10-2+200+380);
    glEnd();

    int i9989;

GLfloat x9989 = 965;
GLfloat y9989 = 578 + 3 + 4;
GLfloat radius9989 = 2;
int triangleAmount9989 = 100;

GLfloat twicePi9989 = 2.0f * PI;

glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x9989, y9989);
    for(i9989 = 0; i9989 <= triangleAmount9989; i9989++) {
        glVertex2f(
            x9989 + (radius9989 * cos(i9989 * twicePi9989 / triangleAmount9989)),
            y9989 + (radius9989 * sin(i9989 * twicePi9989 / triangleAmount9989))
        );
    }
glEnd();

    glBegin(GL_POLYGON);
glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
    glVertex2f(33.21293-2+1087-65-65, 13.08595+3+4-10-2+200+380);
    glVertex2f(33.21293+10+1087-65-65, 13.08595+3+4-10-2+200+380);
    glVertex2f(33.21293+3+1087-65-65, 13.08595-3.5+3+4-10-2+200+380);
    glVertex2f(33.21293+10+1087-65-65, 13.08595-7+3+4-10-2+200+380);
    glVertex2f(31.6907+1087-65-65, 6.58564+3-10-2+200+380);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
      //glColor3ub(255, 255, 147);
    glVertex2f(11.49037+1087-65-65, 18.26974+4-10-2+200+380);
    glVertex2f(11.49037+1087-65-65, 18.26974+15+4-10-2+200+380);
    glVertex2f(19.55405+1087-65-65, 19.29827+4-10-2+200+380);
    //glVertex2f(8+200, 15+500);
    glEnd();

glBegin(GL_TRIANGLES);
     glColor3f(0.15f, 0.15f, 0.15f);  // RGB: (38, 38, 38)
      //glColor3ub(255, 255, 147);
    glVertex2f(14.6171+1087-65-65, 5.14569+4-10-2+200+380);
    glVertex2f(22.47507+1087-65-65, 5.10455-15+4-10-2+200+380);
    glVertex2f(22.47507+1087-65-65, 5.10455+4-10-2+200+380);
    //glVertex2f(8+200, 15+500);
    glEnd();
 glPopMatrix();

}
}


void backimage(){
if(backimage_pointer){
    glBegin(GL_POLYGON);
glColor3ub(255, 255, 147);
    glVertex2f(0, 300);
    glVertex2f(1150, 300);
glColor3ub(102, 204, 255);
    glVertex2f(1150, 750);
    glVertex2f(0, 750);
    glEnd();
}
else{
    glBegin(GL_POLYGON);
glColor3ub(0, 0, 0);
    glVertex2f(0, 300);
    glVertex2f(1150, 300);
glColor3ub(102, 204, 255);
    glVertex2f(1150, 750);
    glVertex2f(0, 750);
    glEnd();

}

}

void update_bird(int value)
{


  bird_Position -= 1.9f; // Move the cloud horizontally
    if (bird_Position < -1100.0f) {
        bird_Position = 1109.0f; // Reset position when it goes off-screen
    }
    glutPostRedisplay(); // Request a redraw
    glutTimerFunc(20, update_bird, 0); // Call this function again after 20 ms





}

void update_Cloud(int value) {

   if(cloud_MovingRight)
{
 cloud_Position += 1.9f; // Move the cloud horizontally
    if (cloud_Position > 800.0f) {
        cloud_Position = -900.0f; // Reset position when it goes off-screen
    }
    glutPostRedisplay(); // Request a redraw
    glutTimerFunc(20, update_Cloud, 0); // Call this function again after 20 ms
}

else{
    cloud_Position -= 1.9f; // Move the cloud horizontally
    if (cloud_Position < -960.0f) {
        cloud_Position = 1200.0f; // Reset position when it goes off-screen
    }
    glutPostRedisplay(); // Request a redraw
    glutTimerFunc(20, update_Cloud, 0); // Call this function again after 20 ms
}


}



void update_sun(int value) {
    sun_position += 0.8f; // Move the cloud horizontally
    if (sun_position > 338.0f) {

        sun_position = -200.0f; // Reset position when it goes off-screen
        backimage_pointer = true;
    }
    if (sun_position > 138.0f) {
        //sun_position = -200.0f; // Reset position when it goes off-screen
       backimage_pointer = false;
    }

    glutPostRedisplay(); // Request a redraw
    glutTimerFunc(20, update_sun, 0); // Call this function again after 20 ms

}




void update_car(int value)
{

if(car_speed>0){
    if(car_position < -450)
            car_position = 1150;

    car_position -= car_speed;
	glutPostRedisplay();
	glutTimerFunc(30, update_car, 0);
}
else{
    glPushMatrix();
glColor3f(0.0f, 0.2f, 0.6f);
glBegin(GL_QUADS);
glVertex2f(150, 100-34);
glVertex2f(450, 100-34);
glVertex2f(450, 160-34);
glVertex2f(150, 160-34);
glEnd();

glColor3f(0.0f, 0.2f, 0.6f);
glBegin(GL_QUADS);
glVertex2f(150, 160-34);
glVertex2f(100, 160-15-34);
glVertex2f(100, 100-34);
glVertex2f(150, 100-34);
glEnd();

//Light
glColor3f(1.0f, 0.4f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(120, 140-34);
glVertex2f(100, 140-34);
glVertex2f(100, 100+10+10-34);
glVertex2f(120, 100+10+10-34);
glEnd();

//Light 2

glColor3f(1.0f, 0.4f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(450, 140+5-34);
glVertex2f(435, 140+5-34);
glVertex2f(435, 100+10+10-34);
glVertex2f(450, 100+10+10-34);
glEnd();

glColor3f(0.0f, 0.2f, 0.6f);
glBegin(GL_QUADS);
glVertex2f(200, 200-34);
glVertex2f(400, 200-34);
glVertex2f(400, 160-34);
glVertex2f(200, 160-34);
glEnd();

glColor3f(0.0f, 0.2f, 0.6f);
glBegin(GL_TRIANGLES);
glVertex2f(200, 200-34);
glVertex2f(150, 160-34);
glVertex2f(200, 160-34);
glEnd();


glColor3f(0.0f, 0.2f, 0.6f);
glBegin(GL_TRIANGLES);
glVertex2f(400, 200-34);
glVertex2f(400, 160-34);
glVertex2f(450, 160-34);
glEnd();

//Window
glColor4f(0.6f, 0.8f, 1.0f, 0.4f);
glBegin(GL_QUADS);
glVertex2f(210, 196-5-34);
glVertex2f(290, 196-5-34);
glVertex2f(290, 160-34);
glVertex2f(170, 160-34);
glEnd();
//Window
glColor4f(0.6f, 0.8f, 1.0f, 0.4f);
glBegin(GL_QUADS);
glVertex2f(300, 196-5-34);
glVertex2f(400-10, 196-5-34);
glVertex2f(400+18+7+6, 160-34);
glVertex2f(300, 160-34);
glEnd();

int i195;
GLfloat x195 = 200;
GLfloat y195 = 100-34;
GLfloat radius195 = 32;
int triangleAmount195 = 100;

GLfloat twicePi195 = 2.0f * PI;

glColor3f(0.0f, 0.00f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x195, y195);
    for(i195 = 0; i195 <= triangleAmount195; i195++) {
        glVertex2f(
            x195 + (radius195 * cos(i195 * twicePi195 / triangleAmount195)),
            y195 + (radius195 * sin(i195 * twicePi195 / triangleAmount195))
        );
    }
glEnd();

int i196;
GLfloat x196 = 380;
GLfloat y196 = 100-34;
GLfloat radius196 = 32;
int triangleAmount196 = 100;

GLfloat twicePi196 = 2.0f * PI;

glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x196, y196);
    for(i196 = 0; i196 <= triangleAmount196; i196++) {
        glVertex2f(
            x196 + (radius196 * cos(i196 * twicePi196 / triangleAmount196)),
            y196 + (radius196 * sin(i196 * twicePi196 / triangleAmount196))
        );
    }
glEnd();



int i197;
GLfloat x197 = 200;
GLfloat y197 = 100 - 34;
GLfloat radius197 = 32-13;
int triangleAmount197 = 100;

GLfloat twicePi197 = 2.0f * PI;

glColor3f(1.0f, 1.00f, 1.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x197, y197);
    for(i197 = 0; i197 <= triangleAmount197; i197++) {
        glVertex2f(
            x197 + (radius197 * cos(i197 * twicePi197 / triangleAmount197)),
            y197 + (radius197 * sin(i197 * twicePi197 / triangleAmount197))
        );
    }
glEnd();

int i198;
GLfloat x198 = 380;
GLfloat y198 = 100 - 34;
GLfloat radius198 = 32-13;
int triangleAmount198 = 100;

GLfloat twicePi198 = 2.0f * PI;

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x198, y198);
    for(i198 = 0; i198 <= triangleAmount198; i198++) {
        glVertex2f(
            x198 + (radius198 * cos(i198 * twicePi198 / triangleAmount198)),
            y198 + (radius198 * sin(i198 * twicePi198 / triangleAmount198))
        );
    }
glEnd();

 glPopMatrix();


}
}


void init()
{
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}



/**........................................ Back ground...........................................**/
void Back_ground(){
glBegin(GL_QUADS);
     glColor3f(0.53f, 0.81f, 0.98f);

    glVertex2f(0, 300);
    glVertex2f(1150,300);
    glVertex2f(1150,750);
    glVertex2f(0,750);
    glEnd();

    // Back ground

glBegin(GL_QUADS);
    glColor3f(0.53f, 0.81f, 0.98f);
    glVertex2f(0, 300);
    glVertex2f(1150,300);
    glVertex2f(1150,750);
    glVertex2f(0,750);
    glEnd();
}

/**........................................ HIll ...........................................**/
void HIll(){
int i134;
GLfloat x134 = 4.60238;
GLfloat y134 = 300;
GLfloat radius134 = 100-20;
int triangleAmount134 = 100;

GLfloat twicePi134 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x134, y134);
    for(i134 = 0; i134 <= triangleAmount134; i134++) {
        glVertex2f(
            x134 + (radius134 * cos(i134 * twicePi134 / triangleAmount134)),
            y134 + (radius134 * sin(i134 * twicePi134 / triangleAmount134))
        );
    }
glEnd();

int i135;
GLfloat x135 = 4.60238+100;
GLfloat y135 = 300;
GLfloat radius135 = 55;
int triangleAmount135 = 100;

GLfloat twicePi135 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x135, y135);
    for(i135 = 0; i135 <= triangleAmount135; i135++) {
        glVertex2f(
            x135 + (radius135 * cos(i135 * twicePi135 / triangleAmount135)),
            y135 + (radius135 * sin(i135 * twicePi135 / triangleAmount135))
        );
    }
glEnd();

int i136;
GLfloat x136 = 4.60238+100+100+20;
GLfloat y136 = 300;
GLfloat radius136 = 89;
int triangleAmount136 = 100;

GLfloat twicePi136 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x136, y136);
    for(i136 = 0; i136 <= triangleAmount136; i136++) {
        glVertex2f(
            x136 + (radius136 * cos(i136 * twicePi136 / triangleAmount136)),
            y136 + (radius136 * sin(i136 * twicePi136 / triangleAmount136))
        );
    }
glEnd();

int i137;
GLfloat x137 = 4.60238+100+100+20+140+20;
GLfloat y137 = 300;
GLfloat radius137 = 89+20+9;
int triangleAmount137 = 100;

GLfloat twicePi137 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x137, y137);
    for(i137 = 0; i137 <= triangleAmount137; i137++) {
        glVertex2f(
            x137 + (radius137 * cos(i137 * twicePi137 / triangleAmount137)),
            y137 + (radius137 * sin(i137 * twicePi137 / triangleAmount137))
        );
    }
glEnd();


int i138;
GLfloat x138 = 1150-4.60238;
GLfloat y138 = 300;
GLfloat radius138 = 100-20;
int triangleAmount138 = 100;

GLfloat twicePi138 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x138, y138);
    for(i138 = 0; i138 <= triangleAmount138; i138++) {
        glVertex2f(
            x138 + (radius138 * cos(i138 * twicePi138 / triangleAmount138)),
            y138 + (radius138 * sin(i138 * twicePi138 / triangleAmount138))
        );
    }
glEnd();

int i139;
GLfloat x139 = 1150-4.60238-100;
GLfloat y139 = 300;
GLfloat radius139 = 55;
int triangleAmount139 = 100;

GLfloat twicePi139 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x139, y139);
    for(i139 = 0; i139 <= triangleAmount139; i139++) {
        glVertex2f(
            x139 + (radius139 * cos(i139 * twicePi139 / triangleAmount139)),
            y139 + (radius139 * sin(i139 * twicePi139 / triangleAmount139))
        );
    }
glEnd();

int i140;
GLfloat x140 = 1150-4.60238-100-100-20;
GLfloat y140 = 300;
GLfloat radius140 = 89;
int triangleAmount140 = 100;

GLfloat twicePi140 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x140, y140);
    for(i140 = 0; i140 <= triangleAmount140; i140++) {
        glVertex2f(
            x140 + (radius140 * cos(i140 * twicePi140 / triangleAmount140)),
            y140 + (radius140 * sin(i140 * twicePi140 / triangleAmount140))
        );
    }
glEnd();

int i141;
GLfloat x141 = 1150-4.60238-100-100-20-140-20;
GLfloat y141 = 300;
GLfloat radius141 = 89+20+9;
int triangleAmount141 = 100;

GLfloat twicePi141 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x141, y141);
    for(i141 = 0; i141 <= triangleAmount141; i141++) {
        glVertex2f(
            x141 + (radius141 * cos(i141 * twicePi141 / triangleAmount141)),
            y141 + (radius141 * sin(i141 * twicePi141 / triangleAmount141))
        );
    }
glEnd();

if(backimage_pointer)
{

    glBegin(GL_QUADS);
    glColor3f(0.39, 0.8, 0.13);
    glVertex2f(0, 0);
    glVertex2f(1150,0);
    glVertex2f(1150,320);
    glColor3f(0.8196f, 0.6157f, 0.2039f);
    glVertex2f(0,320);
    glEnd();


}
else{

  glBegin(GL_QUADS);
    glColor3ub(17,75,16);
    glVertex2f(0, 0);
    glVertex2f(1150,0);
    glVertex2f(1150,320);

    glVertex2f(0,320);
    glEnd();
    }








}

/**........................................ Tree1 ...........................................**/
void Tree1(){
    glBegin(GL_QUADS);
    glColor3f(0.55, 0.27, 0.07);
    glVertex2f(266, 300);
    glVertex2f(296,300);
    glVertex2f(296,400);
    glVertex2f(266,400);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(231, 370);
    glVertex2f(331,370);
    glVertex2f(296,402);
     glColor3f(0.8588f, 0.8078f, 0.0588f);
    glVertex2f(266,402);
    glEnd();

    glBegin(GL_TRIANGLES);
   glColor3f(0.0f, 0.6f, 0.0f);
    glVertex2f(238, 400);
    glColor3f(0.8588f, 0.8078f, 0.0588f);
    glVertex2f(326,400);
    glVertex2f(280,455);
    glEnd();
}

/**........................................ Grass1 ...........................................**/
void Grass1(){
    glBegin(GL_POLYGON);
  glColor3f(0.0f, 0.6f, 0.0f);

    glVertex2f(275-120,310);
    glVertex2f(275-120,330);
    glVertex2f(289-120,313);
    glVertex2f(300-120,327);
    glVertex2f(300-120,309);
    //glColor3f(1.0f, 1.0f, 0.0f);
    glColor3f(0.8588f, 0.8078f, 0.0588f);
    glVertex2f(320-120,316);

    glVertex2f(304-120,300);

    glVertex2f(265-120,300);
    glVertex2f(247-120,316);
    glEnd();
}


/**........................................ Rose ...........................................**/
void Rose(){
int i143;
GLfloat x143 = 200+10;
GLfloat y143 = 316;
GLfloat radius143 = 10;
int triangleAmount143 = 100;

GLfloat twicePi143 = 2.0f * PI;

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x143, y143);
    for(i143 = 0; i143 <= triangleAmount143; i143++) {
        glVertex2f(
            x143 + (radius143 * cos(i143 * twicePi143 / triangleAmount143)),
            y143 + (radius143 * sin(i143 * twicePi143 / triangleAmount143))
        );
    }
glEnd();

int i144;
GLfloat x144 = 200-10;
GLfloat y144 = 316;
GLfloat radius144 = 10;
int triangleAmount144 = 100;

GLfloat twicePi144 = 2.0f * PI;

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x144, y144);
    for(i144 = 0; i144 <= triangleAmount144; i144++) {
        glVertex2f(
            x144 + (radius144 * cos(i144 * twicePi144 / triangleAmount144)),
            y144 + (radius144 * sin(i144 * twicePi144 / triangleAmount144))
        );
    }
glEnd();

int i145;
GLfloat x145 = 200;
GLfloat y145 = 316+10;
GLfloat radius145 = 10;
int triangleAmount145 = 100;

GLfloat twicePi145 = 2.0f * PI;

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x145, y145);
    for(i145 = 0; i145 <= triangleAmount145; i145++) {
        glVertex2f(
            x145 + (radius145 * cos(i145 * twicePi145 / triangleAmount145)),
            y145 + (radius145 * sin(i145 * twicePi145 / triangleAmount145))
        );
    }
glEnd();

int i146;
GLfloat x146 = 200;
GLfloat y146 = 316-10;
GLfloat radius146 = 10;
int triangleAmount146 = 100;

GLfloat twicePi146 = 2.0f * PI;

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x146, y146);
    for(i146 = 0; i146 <= triangleAmount146; i146++) {
        glVertex2f(
            x146 + (radius146 * cos(i146 * twicePi146 / triangleAmount146)),
            y146 + (radius146 * sin(i146 * twicePi146 / triangleAmount146))
        );
    }
glEnd();

    int i142;
GLfloat x142 = 200;
GLfloat y142 = 316;
GLfloat radius142 = 10;
int triangleAmount142 = 100;

GLfloat twicePi142 = 2.0f * PI;

glColor3f(1.0f, 1.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x142, y142);
    for(i142 = 0; i142 <= triangleAmount142; i142++) {
        glVertex2f(
            x142 + (radius142 * cos(i142 * twicePi142 / triangleAmount142)),
            y142 + (radius142 * sin(i142 * twicePi142 / triangleAmount142))
        );
    }
glEnd();





//

int i160;
GLfloat x160 = 200+10+15+10;
GLfloat y160 = 316+15+5;
GLfloat radius160 = 5;
int triangleAmount160 = 100;

GLfloat twicePi160 = 2.0f * PI;

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x160, y160);
    for(i160 = 0; i160 <= triangleAmount160; i160++) {
        glVertex2f(
            x160 + (radius160 * cos(i160 * twicePi160 / triangleAmount160)),
            y160 + (radius160 * sin(i160 * twicePi160 / triangleAmount160))
        );
    }
glEnd();

int i161;
GLfloat x161 = 200-10+15+10;
GLfloat y161 = 316+15+5;
GLfloat radius161 = 5;
int triangleAmount161 = 100;

GLfloat twicePi161 = 2.0f * PI;

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x161, y161);
    for(i161 = 0; i161 <= triangleAmount161; i161++) {
        glVertex2f(
            x161 + (radius161 * cos(i161 * twicePi161 / triangleAmount161)),
            y161 + (radius161 * sin(i161 * twicePi161 / triangleAmount161))
        );
    }
glEnd();

int i162;
GLfloat x162 = 200+15+10;
GLfloat y162 = 316+10+15+5;
GLfloat radius162 = 5;
int triangleAmount162 = 100;

GLfloat twicePi162 = 2.0f * PI;

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x162, y162);
    for(i162 = 0; i162 <= triangleAmount162; i162++) {
        glVertex2f(
            x162 + (radius162 * cos(i162 * twicePi162 / triangleAmount162)),
            y162 + (radius162 * sin(i162 * twicePi162 / triangleAmount162))
        );
    }
glEnd();




int i163;
GLfloat x163 = 200+15+10;
GLfloat y163 = 316-10+15+5;
GLfloat radius163 = 5;
int triangleAmount163 = 100;

GLfloat twicePi163 = 2.0f * PI;

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x163, y163);
    for(i163 = 0; i163 <= triangleAmount163; i163++) {
        glVertex2f(
            x163 + (radius163 * cos(i163 * twicePi163 / triangleAmount163)),
            y163 + (radius163 * sin(i163 * twicePi163 / triangleAmount163))
        );
    }
glEnd();

int i164;
GLfloat x164 = 200+15+10;
GLfloat y164 = 316+15+5;
GLfloat radius164 = 5;
int triangleAmount164 = 100;

GLfloat twicePi164 = 2.0f * PI;

glColor3f(1.0f, 1.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x164, y164);
    for(i164 = 0; i164 <= triangleAmount164; i164++) {
        glVertex2f(
            x164 + (radius164 * cos(i164 * twicePi164 / triangleAmount164)),
            y164 + (radius164 * sin(i164 * twicePi164 / triangleAmount164))
        );
    }
glEnd();



//

int i165;
GLfloat x165 = 200+10+15+10-90;
GLfloat y165 = 316+15+5;
GLfloat radius165 = 5;
int triangleAmount165 = 100;

GLfloat twicePi165 = 2.0f * PI;

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x165, y165);
    for(i165 = 0; i165 <= triangleAmount165; i165++) {
        glVertex2f(
            x165 + (radius165 * cos(i165 * twicePi165 / triangleAmount165)),
            y165 + (radius165 * sin(i165 * twicePi165 / triangleAmount165))
        );
    }
glEnd();

int i166;
GLfloat x166 = 200-10+15+10-90;
GLfloat y166 = 316+15+5;
GLfloat radius166 = 5;
int triangleAmount166 = 100;

GLfloat twicePi166 = 2.0f * PI;
glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x166, y166);
    for(i166 = 0; i166 <= triangleAmount166; i166++) {
        glVertex2f(
            x166 + (radius166 * cos(i166 * twicePi166 / triangleAmount166)),
            y166 + (radius166 * sin(i166 * twicePi166 / triangleAmount166))
        );
    }
glEnd();

int i167;
GLfloat x167 = 200+15+10-90;
GLfloat y167 = 316+10+15+5;
GLfloat radius167 = 5;
int triangleAmount167 = 100;

GLfloat twicePi167 = 2.0f * PI;

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x167, y167);
    for(i167 = 0; i167 <= triangleAmount167; i167++) {
        glVertex2f(
            x167 + (radius167 * cos(i167 * twicePi167 / triangleAmount167)),
            y167 + (radius167 * sin(i167 * twicePi167 / triangleAmount167))
        );
    }
glEnd();

int i168;
GLfloat x168 = 200+15+10-90;
GLfloat y168 = 316-10+15+5;
GLfloat radius168 = 5;
int triangleAmount168 = 100;

GLfloat twicePi168 = 2.0f * PI;

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x168, y168);
    for(i168 = 0; i168 <= triangleAmount168; i168++) {
        glVertex2f(
            x168 + (radius168 * cos(i168 * twicePi168 / triangleAmount168)),
            y168 + (radius168 * sin(i168 * twicePi168 / triangleAmount168))
        );
    }
glEnd();

int i169;
GLfloat x169 = 200+15+10-90;
GLfloat y169 = 316+15+5;
GLfloat radius169 = 6.5;
int triangleAmount169 = 100;

GLfloat twicePi169 = 2.0f * PI;
glColor3f(1.0f, 1.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x169, y169);
    for(i169 = 0; i169 <= triangleAmount169; i169++) {
        glVertex2f(
            x169 + (radius169 * cos(i169 * twicePi169 / triangleAmount169)),
            y169 + (radius169 * sin(i169 * twicePi169 / triangleAmount169))
        );
    }
glEnd();



//


int i170;
GLfloat x170 = 200+10+15+10-90-115;
GLfloat y170 = 316+15+5;
GLfloat radius170 = 5;
int triangleAmount170 = 100;

GLfloat twicePi170 = 2.0f * PI;

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x170, y170);
    for(i170 = 0; i170 <= triangleAmount170; i170++) {
        glVertex2f(
            x170 + (radius170 * cos(i170 * twicePi170 / triangleAmount170)),
            y170 + (radius170 * sin(i170 * twicePi170 / triangleAmount170))
        );
    }
glEnd();

int i171;
GLfloat x171 = 200-10+15+10-90-115;
GLfloat y171 = 316+15+5;
GLfloat radius171 = 5;
int triangleAmount171 = 100;

GLfloat twicePi171 = 2.0f * PI;

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x171, y171);
    for(i171 = 0; i171 <= triangleAmount171; i171++) {
        glVertex2f(
            x171 + (radius171 * cos(i171 * twicePi171 / triangleAmount171)),
            y171 + (radius171 * sin(i171 * twicePi171 / triangleAmount171))
        );
    }
glEnd();

int i172;
GLfloat x172 = 200+15+10-90-115;
GLfloat y172 = 316+10+15+5;
GLfloat radius172 = 5;
int triangleAmount172 = 100;

GLfloat twicePi172 = 2.0f * PI;

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x172, y172);
    for(i172 = 0; i172 <= triangleAmount172; i172++) {
        glVertex2f(
            x172 + (radius172 * cos(i172 * twicePi172 / triangleAmount172)),
            y172 + (radius172 * sin(i172 * twicePi172 / triangleAmount172))
        );
    }
glEnd();

int i173;
GLfloat x173 = 200+15+10-90-115;
GLfloat y173 = 316-10+15+5;
GLfloat radius173 = 5;
int triangleAmount173 = 100;

GLfloat twicePi173 = 2.0f * PI;

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x173, y173);
    for(i173 = 0; i173 <= triangleAmount173; i173++) {
        glVertex2f(
            x173 + (radius173 * cos(i173 * twicePi173 / triangleAmount173)),
            y173 + (radius173 * sin(i173 * twicePi173 / triangleAmount173))
        );
    }
glEnd();

int i174;
GLfloat x174 = 200+15+10-90-115;
GLfloat y174 = 316+15+5;
GLfloat radius174 = 6.5;
int triangleAmount174 = 100;

GLfloat twicePi174 = 2.0f * PI;

glColor3f(1.0f, 1.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x174, y174);
    for(i174 = 0; i174 <= triangleAmount174; i174++) {
        glVertex2f(
            x174 + (radius174 * cos(i174 * twicePi174 / triangleAmount174)),
            y174 + (radius174 * sin(i174 * twicePi174 / triangleAmount174))
        );
    }
glEnd();

//


//

int i175;
GLfloat x175 = 200+10+15+10-90-115+900-30;
GLfloat y175 = 316+15+5;
GLfloat radius175 = 5;
int triangleAmount175 = 100;

GLfloat twicePi175 = 2.0f * PI;

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x175, y175);
    for(i175 = 0; i175 <= triangleAmount175; i175++) {
        glVertex2f(
            x175 + (radius175 * cos(i175 * twicePi175 / triangleAmount175)),
            y175 + (radius175 * sin(i175 * twicePi175 / triangleAmount175))
        );
    }
glEnd();

int i176;
GLfloat x176 = 200-10+15+10-90-115+900-30;
GLfloat y176 = 316+15+5;
GLfloat radius176 = 5;
int triangleAmount176 = 100;

GLfloat twicePi176 = 2.0f * PI;

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x176, y176);
    for(i176 = 0; i176 <= triangleAmount176; i176++) {
        glVertex2f(
            x176 + (radius176 * cos(i176 * twicePi176 / triangleAmount176)),
            y176 + (radius176 * sin(i176 * twicePi176 / triangleAmount176))
        );
    }
glEnd();

int i177;
GLfloat x177 = 200+15+10-90-115+900-30;
GLfloat y177 = 316+10+15+5;
GLfloat radius177 = 5;
int triangleAmount177 = 100;

GLfloat twicePi177 = 2.0f * PI;

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x177, y177);
    for(i177 = 0; i177 <= triangleAmount177; i177++) {
        glVertex2f(
            x177 + (radius177 * cos(i177 * twicePi177 / triangleAmount177)),
            y177 + (radius177 * sin(i177 * twicePi177 / triangleAmount177))
        );
    }
glEnd();

int i178;
GLfloat x178 = 200+15+10-90-115+900-30;
GLfloat y178 = 316-10+15+5;
GLfloat radius178 = 5;
int triangleAmount178 = 100;

GLfloat twicePi178 = 2.0f * PI;

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x178, y178);
    for(i178 = 0; i178 <= triangleAmount178; i178++) {
        glVertex2f(
            x178 + (radius178 * cos(i178 * twicePi178 / triangleAmount178)),
            y178 + (radius178 * sin(i178 * twicePi178 / triangleAmount178))
        );
    }
glEnd();

int i179;
GLfloat x179 = 200+15+10-90-115+900-30;
GLfloat y179 = 316+15+5;
GLfloat radius179 = 6.5;
int triangleAmount179 = 100;

GLfloat twicePi179 = 2.0f * PI;

glColor3f(1.0f, 1.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x179, y179);
    for(i179 = 0; i179 <= triangleAmount179; i179++) {
        glVertex2f(
            x179 + (radius179 * cos(i179 * twicePi179 / triangleAmount179)),
            y179 + (radius179 * sin(i179 * twicePi179 / triangleAmount179))
        );
    }
glEnd();

//


//

int i180;
GLfloat x180 = 200+10+15+10-90-115+900+180;
GLfloat y180 = 316+15+5;
GLfloat radius180 = 5;
int triangleAmount180 = 100;

GLfloat twicePi180 = 2.0f * PI;

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x180, y180);
    for(i180 = 0; i180 <= triangleAmount180; i180++) {
        glVertex2f(
            x180 + (radius180 * cos(i180 * twicePi180 / triangleAmount180)),
            y180 + (radius180 * sin(i180 * twicePi180 / triangleAmount180))
        );
    }
glEnd();

int i181;
GLfloat x181 = 200-10+15+10-90-115+900+180;
GLfloat y181 = 316+15+5;
GLfloat radius181 = 5;
int triangleAmount181 = 100;

GLfloat twicePi181 = 2.0f * PI;

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x181, y181);
    for(i181 = 0; i181 <= triangleAmount181; i181++) {
        glVertex2f(
            x181 + (radius181 * cos(i181 * twicePi181 / triangleAmount181)),
            y181 + (radius181 * sin(i181 * twicePi181 / triangleAmount181))
        );
    }
glEnd();

int i182;
GLfloat x182 = 200+15+10-90-115+900+180;
GLfloat y182 = 316+10+15+5;
GLfloat radius182 = 5;
int triangleAmount182 = 100;

GLfloat twicePi182 = 2.0f * PI;

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x182, y182);
    for(i182 = 0; i182 <= triangleAmount182; i182++) {
        glVertex2f(
            x182 + (radius182 * cos(i182 * twicePi182 / triangleAmount182)),
            y182 + (radius182 * sin(i182 * twicePi182 / triangleAmount182))
        );
    }
glEnd();

int i183;
GLfloat x183 = 200+15+10-90-115+900+180;
GLfloat y183 = 316-10+15+5;
GLfloat radius183 = 5;
int triangleAmount183 = 100;

GLfloat twicePi183 = 2.0f * PI;

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x183, y183);
    for(i183 = 0; i183 <= triangleAmount183; i183++) {
        glVertex2f(
            x183 + (radius183 * cos(i183 * twicePi183 / triangleAmount183)),
            y183 + (radius183 * sin(i183 * twicePi183 / triangleAmount183))
        );
    }
glEnd();

int i184;
GLfloat x184 = 200+15+10-90-115+900+180;
GLfloat y184 = 316+15+5;
GLfloat radius184 = 6.5;
int triangleAmount184 = 100;

GLfloat twicePi184 = 2.0f * PI;

glColor3f(1.0f, 1.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x184, y184);
    for(i184 = 0; i184 <= triangleAmount184; i184++) {
        glVertex2f(
            x184 + (radius184 * cos(i184 * twicePi184 / triangleAmount184)),
            y184 + (radius184 * sin(i184 * twicePi184 / triangleAmount184))
        );
    }
glEnd();




//


//
int i147;
GLfloat x147 = 200+10+780;
GLfloat y147 = 316;
GLfloat radius147 = 10;
int triangleAmount147 = 100;

GLfloat twicePi147 = 2.0f * PI;

glColor3f(1.0f, 1.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x147, y147);
    for(i147 = 0; i147 <= triangleAmount147; i147++) {
        glVertex2f(
            x147 + (radius147 * cos(i147 * twicePi147 / triangleAmount147)),
            y147 + (radius147 * sin(i147 * twicePi147 / triangleAmount147))
        );
    }
glEnd();

int i148;
GLfloat x148 = 200-10+780;
GLfloat y148 = 316;
GLfloat radius148 = 10;
int triangleAmount148 = 100;

GLfloat twicePi148 = 2.0f * PI;

glColor3f(1.0f, 1.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x148, y148);
    for(i148 = 0; i148 <= triangleAmount148; i148++) {
        glVertex2f(
            x148 + (radius148 * cos(i148 * twicePi148 / triangleAmount148)),
            y148 + (radius148 * sin(i148 * twicePi148 / triangleAmount148))
        );
    }
glEnd();

int i149;
GLfloat x149 = 200+780;
GLfloat y149 = 316+10;
GLfloat radius149 = 10;
int triangleAmount149 = 100;

GLfloat twicePi149 = 2.0f * PI;

glColor3f(1.0f, 1.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x149, y149);
    for(i149 = 0; i149 <= triangleAmount149; i149++) {
        glVertex2f(
            x149 + (radius149 * cos(i149 * twicePi149 / triangleAmount149)),
            y149 + (radius149 * sin(i149 * twicePi149 / triangleAmount149))
        );
    }
glEnd();

int i150;
GLfloat x150 = 200+780;
GLfloat y150 = 316-10;
GLfloat radius150 = 10;
int triangleAmount150 = 100;

GLfloat twicePi150 = 2.0f * PI;

glColor3f(1.0f, 1.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x150, y150);
    for(i150 = 0; i150 <= triangleAmount150; i150++) {
        glVertex2f(
            x150 + (radius150 * cos(i150 * twicePi150 / triangleAmount150)),
            y150 + (radius150 * sin(i150 * twicePi150 / triangleAmount150))
        );
    }
glEnd();

int i151;
GLfloat x151 = 200+780;
GLfloat y151 = 316;
GLfloat radius151 = 10;
int triangleAmount151 = 100;

GLfloat twicePi151 = 2.0f * PI;

glColor3f(1.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x151, y151);
    for(i151 = 0; i151 <= triangleAmount151; i151++) {
        glVertex2f(
            x151 + (radius151 * cos(i151 * twicePi151 / triangleAmount151)),
            y151 + (radius151 * sin(i151 * twicePi151 / triangleAmount151))
        );
    }
glEnd();

}


/**........................................ Grass3 Left most ...........................................**/
void Grass3_Left_most(){
glBegin(GL_POLYGON);
glColor3f(0.0f, 0.6f, 0.0f);

glVertex2f(0, 310);
glVertex2f(0, 330);
glVertex2f(14, 313);
glVertex2f(25, 327);
glColor3f(0.8588f, 0.8078f, 0.0588f);
glVertex2f(25, 309);
glVertex2f(45, 316);
glVertex2f(29, 300);
glVertex2f(-10, 300);
glVertex2f(-28, 316);
glEnd();

}

/**........................................ Tree2 ...........................................**/
void Tree2(){
glBegin(GL_QUADS);
glColor3f(0.55, 0.27, 0.07);
glVertex2f(800, 300);
glVertex2f(830, 300);
glVertex2f(830, 400);
glVertex2f(800, 400);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.6f, 0.0f);
glVertex2f(765, 370);
glVertex2f(865, 370);
glVertex2f(830, 402);
glColor3f(0.8588f, 0.8078f, 0.0588f);
glVertex2f(800, 402);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.0f, 0.6f, 0.0f);
glVertex2f(772, 400);
glVertex2f(860, 400);
glColor3f(0.8588f, 0.8078f, 0.0588f);
glVertex2f(814, 455);
glEnd();
}

/**........................................ Tree3 Wright most ...........................................**/
void Tree3_Wright_most(){
glBegin(GL_QUADS);
glColor3f(0.55, 0.27, 0.07);
glVertex2f(1120, 300);
glVertex2f(1150, 300);
glVertex2f(1150, 400);
glVertex2f(1120, 400);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.0f, 0.6f, 0.0f);
glVertex2f(1085, 370);
glVertex2f(1185, 370);
glVertex2f(1150, 402);
glVertex2f(1120, 402);
glEnd();

glBegin(GL_TRIANGLES);
glColor3f(0.0f, 0.6f, 0.0f);
glVertex2f(1092, 400);
glVertex2f(1180, 400);
glVertex2f(1134, 455);
glEnd();

}

/**........................................ Small tree Rightmost ...........................................**/
void Small_tree_Rightmost(){
glBegin(GL_QUADS);
glColor3f(0.55, 0.27, 0.07);
glVertex2f(1035, 300);
glVertex2f(1050, 300);
glVertex2f(1050, 331);
glVertex2f(1035, 331);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.0f, 0.6f, 0.0f);
glVertex2f(1043, 350);
glVertex2f(1050, 369);
glVertex2f(1050, 331);
glVertex2f(1035, 331);
glVertex2f(1035, 369);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.0f, 0.6f, 0.0f);
glVertex2f(1067, 338.5);
glVertex2f(1085, 346);
glVertex2f(1050, 346);
glVertex2f(1050, 331);
glVertex2f(1085, 331);
glEnd();

glBegin(GL_POLYGON);
glColor3f(0.0f, 0.6f, 0.0f);
glVertex2f(1017.5, 338.5);
glVertex2f(1000, 331);
glVertex2f(1035, 331);
glVertex2f(1035, 346);
glVertex2f(1000, 346);
glEnd();

}

/**........................................ HOUSE ...........................................**/
void HOUSE(){
glColor3f(0.235f, 0.816f, 0.784f);
glBegin(GL_QUADS);
glVertex2f(497, 480+10);
glVertex2f(630,480+10);
glVertex2f(630,300);
glVertex2f(497,300);
glEnd();

glColor3f(0.349f, 0.204f, 0.129f);
glBegin(GL_TRIANGLES);
glVertex2f(560,530+10);
glVertex2f(497,480+10);
glVertex2f(630,480+10);
glEnd();



glColor3f(0.235f, 0.816f, 0.784f);
glBegin(GL_TRIANGLES);
glVertex2f(497, 450);
glVertex2f(497,421);
glVertex2f(431-10,421);
glEnd();



glColor3f(0.235f, 0.816f, 0.784f);
glBegin(GL_TRIANGLES);
glVertex2f(630, 450);
glVertex2f(630,421);
glVertex2f(696+10,421);
glEnd();



glColor3f(0.235f, 0.816f, 0.784f);
glBegin(GL_QUADS);
glVertex2f(630,421);
glVertex2f(706,421);
glVertex2f(706,300);
glVertex2f(630,300);
glEnd();




//Door Right
glColor3f(0.36f, 0.17f, 0.02f);
glBegin(GL_QUADS);
glVertex2f(650,300+30+15);
glVertex2f(686,300+30+15);
glVertex2f(686,340+40+15);
glVertex2f(650,340+40+15);
glEnd();

glLineWidth(5.0f);
glColor3f(0.95f, 0.61f, 0.07f);
glBegin(GL_LINES);
glVertex2f(650+18,345);
glVertex2f(686-18,395);
glEnd();

glLineWidth(5.0f);
glColor3f(0.95f, 0.61f, 0.07f);
glBegin(GL_LINES);
glVertex2f(650,345+25);
glVertex2f(686,345+25);
glEnd();

glColor3f(0.235f, 0.816f, 0.784f);
glBegin(GL_QUADS);
glVertex2f(497,421);
glVertex2f(431-10,421);
glVertex2f(421,300);
glVertex2f(497,300);
glEnd();

//Door Left
glColor3f(0.36f, 0.17f, 0.02f);
glBegin(GL_QUADS);
glVertex2f(441,300+30+15);
glVertex2f(477,300+30+15);
glVertex2f(477,340+40+15);
glVertex2f(441,340+40+15);
glEnd();

glLineWidth(5.0f);
glColor3f(0.95f, 0.61f, 0.07f);
glBegin(GL_LINES);
glVertex2f(441+18,345);
glVertex2f(477-18,395);
glEnd();

glLineWidth(5.0f);
glColor3f(0.95f, 0.61f, 0.07f);
glBegin(GL_LINES);
glVertex2f(441,345+25);
glVertex2f(477,345+25);
glEnd();

glLineWidth(5.0f);
glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_LINES);
glVertex2f(497,480+10);
glVertex2f(630,480+10);
glEnd();

glLineWidth(5.0f);
glColor3f(0.141f, 0.490f, 0.470f);
glBegin(GL_LINES);
glVertex2f(497-1, 450);
glVertex2f(497-1,300);
glEnd();

glLineWidth(5.0f);
glColor3f(0.349f, 0.204f, 0.129f);
glBegin(GL_LINES);
glVertex2f(497, 450);
glVertex2f(431-10,421);
glEnd();

glLineWidth(5.0f);
//glColor3f(0.95f, 0.61f, 0.07f);
glColor3f(0.141f, 0.490f, 0.470f);
glBegin(GL_LINES);
glVertex2f(630+2,450);
glVertex2f(630+2,300);
glEnd();


glLineWidth(5.0f);
glColor3f(0.349f, 0.204f, 0.129f);
glBegin(GL_LINES);
glVertex2f(630, 450);
glVertex2f(696+10,421);
glEnd();

//glColor3f(0.349f, 0.204f, 0.129f
glColor3f(0.95f, 0.61f, 0.07f);
glBegin(GL_QUADS);
glVertex2f(507,440-15);
glVertex2f(620,440-15);
glVertex2f(620,300);
glVertex2f(507,300);
glEnd();



int i100;
GLfloat x100 = 563.5; GLfloat y100 = 440-15; GLfloat radius100 = 56.5;
int triangleAmount100 = 100;

GLfloat twicePi100 = 2.0f * PI;


//glColor3f(0.349f, 0.204f, 0.129f);
glColor3f(0.95f, 0.61f, 0.07f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x100, y100);
    for(i100 = 0; i100 <= triangleAmount100; i100++) {
        glVertex2f(
            x100 + (radius100 * cos(i100 * twicePi100 / triangleAmount100)),
            y100 + (radius100 * sin(i100 * twicePi100 / triangleAmount100))
        );
    }
glEnd();

glColor3f(0.349f, 0.204f, 0.129f);
//glColor3f(0.95f, 0.61f, 0.07f);
glBegin(GL_QUADS);
glVertex2f(507+8,440-15);
glVertex2f(620-8,440-15);
glVertex2f(620-8,300);
glVertex2f(507+8,300);
glEnd();
int i1200;
GLfloat x1200 = 563.5; GLfloat y1200 = 440-15; GLfloat radius1200 = 56.5-8;
int triangleAmount1200 = 100;

GLfloat twicePi1200 = 2.0f * PI;


glColor3f(0.349f, 0.204f, 0.129f);
//glColor3f(0.95f, 0.61f, 0.07f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1200, y1200);
    for(i1200 = 0; i1200 <= triangleAmount1200; i1200++) {
        glVertex2f(
            x1200 + (radius1200 * cos(i1200 * twicePi1200 / triangleAmount1200)),
            y1200 + (radius1200 * sin(i1200 * twicePi1200 / triangleAmount1200))
        );
    }
glEnd();


 glColor3f(0.4f, 0.2f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(421, 300);
    glVertex2f(706,300);
    glVertex2f(731,280);
    glVertex2f(396,280);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(731,280);
    glVertex2f(396,280);
    glVertex2f(396,280-10);
    glVertex2f(731,280-10);
    glEnd();


}


/**........................................ railing ...........................................**/
void railing(){
//Right most
glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(706, 300);
glVertex2f(721, 300);
glVertex2f(721, 350);
glVertex2f(706, 350);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLES);
glVertex2f(721, 350);
glVertex2f(706, 350);
glVertex2f(713.5,360);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(726, 300);
glVertex2f(726, 350);
glVertex2f(741, 350);
glVertex2f(741, 300);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLES);
glVertex2f(726, 350);
glVertex2f(741, 350);
glVertex2f(726+7.5,360);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(746, 300);
glVertex2f(746, 350);
glVertex2f(761, 350);
glVertex2f(761, 300);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLES);
glVertex2f(746, 350);
glVertex2f(761, 350);
glVertex2f(746+7.5,360);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(766, 300);
glVertex2f(766, 350);
glVertex2f(781, 350);
glVertex2f(781, 300);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLES);
glVertex2f(766, 350);
glVertex2f(781, 350);
glVertex2f(766+7.5,360);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(786, 300);
glVertex2f(786, 350);
glVertex2f(801, 350);
glVertex2f(801, 300);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLES);
glVertex2f(786, 350);
glVertex2f(801, 350);
glVertex2f(786+7.5,360);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(806, 300);
glVertex2f(806, 350);
glVertex2f(821, 350);
glVertex2f(821, 300);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLES);
glVertex2f(806, 350);
glVertex2f(821, 350);
glVertex2f(806+7.5,360);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(826, 300);
glVertex2f(826, 350);
glVertex2f(841, 350);
glVertex2f(841, 300);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLES);
glVertex2f(826, 350);
glVertex2f(841, 350);
glVertex2f(826+7.5,360);
glEnd();

glLineWidth(5.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(706, 300+17);
glVertex2f(841, 300+17);
glEnd();


glLineWidth(5.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(706, 300+17+17);
glVertex2f(841, 300+17+17);
glEnd();

//Left Most

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(421, 300);
glVertex2f(406, 300);
glVertex2f(406, 350);
glVertex2f(421, 350);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLES);
glVertex2f(406, 350);
glVertex2f(421, 350);
glVertex2f(406+7.5,360);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(401, 300);
glVertex2f(386, 300);
glVertex2f(386, 350);
glVertex2f(401, 350);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLES);
glVertex2f(386, 350);
glVertex2f(401, 350);
glVertex2f(386+7.5,360);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(381, 300);
glVertex2f(366, 300);
glVertex2f(366, 350);
glVertex2f(381, 350);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLES);
glVertex2f(366, 350);
glVertex2f(381, 350);
glVertex2f(366+7.5,360);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(361, 300);
glVertex2f(346, 300);
glVertex2f(346, 350);
glVertex2f(361, 350);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLES);
glVertex2f(346, 350);
glVertex2f(361, 350);
glVertex2f(346+7.5,360);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(341, 300);
glVertex2f(326, 300);
glVertex2f(326, 350);
glVertex2f(341, 350);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLES);
glVertex2f(326, 350);
glVertex2f(341, 350);
glVertex2f(326+7.5,360);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(321, 300);
glVertex2f(306, 300);
glVertex2f(306, 350);
glVertex2f(321, 350);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLES);
glVertex2f(306, 350);
glVertex2f(321, 350);
glVertex2f(306+7.5,360);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(301, 300);
glVertex2f(286, 300);
glVertex2f(286, 350);
glVertex2f(301, 350);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLES);
glVertex2f(286, 350);
glVertex2f(301, 350);
glVertex2f(286+7.5,360);
glEnd();

glLineWidth(5.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(406, 300+17);
glVertex2f(286, 300+17);
glEnd();


glLineWidth(5.0f);
glBegin(GL_LINES);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(406, 300+17+17);
glVertex2f(286, 300+17+17);
glEnd();

}


/**........................................ Plus sign ...........................................**/
void Plus_sign(){
glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(507, 300);
glVertex2f(620, 300);
glVertex2f(620, 318);
glVertex2f(507, 318);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(524, 318);
glVertex2f(604, 318);
glVertex2f(604, 343);
glVertex2f(524, 343);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(536, 343);
glVertex2f(590, 343);
glVertex2f(590, 369);
glVertex2f(536, 369);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(552, 369);
glVertex2f(572, 369);
glVertex2f(572, 453);
glVertex2f(552, 453);
glEnd();

glBegin(GL_QUADS);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex2f(529, 421);
glVertex2f(596, 421);
glVertex2f(596, 440);
glVertex2f(529, 440);
glEnd();

}

/**........................................ First vertical line ...........................................**/
void First_vertical_line(){
glLineWidth(3.0f);
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(562, 443);
glVertex2f(562, 385);
glEnd();
}

/**........................................ Second horizontal line ...........................................**/
void Second_horizontal_line(){
glBegin(GL_LINES);
glColor3f(0.0f, 0.0f, 0.0f);
glVertex2f(552, 430.5);
glVertex2f(572, 430.5);
glEnd();

glColor3f(0.4f, 0.2f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(202+305+7.5, 183 + 135);
glVertex2f(208+305+7.5, 183 + 135);
glVertex2f(208+305+7.5, 165 + 135);
glVertex2f(202+305+7.5, 165 + 135);
glEnd();

int i31;
GLfloat x31 = 202+305+7.5; GLfloat y31 = 318; GLfloat radius31 = 10;
int triangleAmount31 = 100;

GLfloat twicePi31 = 2.0f * PI;


glColor3f(1.0f, 0.5f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x31, y31);
    for(i31 = 0; i31 <= triangleAmount31; i31++) {
        glVertex2f(
            x31 + (radius31 * cos(i31 * twicePi31 / triangleAmount31)),
            y31 + (radius31 * sin(i31 * twicePi31 / triangleAmount31))
        );
    }
glEnd();

int i32;
GLfloat x32 = 213+305+7.5; GLfloat y32 = 318; GLfloat radius32 = 10;
int triangleAmount32 = 100;

GLfloat twicePi32 = 2.0f * PI;
glColor3f(1.0f, 0.5f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x32, y32);
    for(i32 = 0; i32 <= triangleAmount32; i32++) {
        glVertex2f(
            x32 + (radius32 * cos(i32 * twicePi32 / triangleAmount32)),
            y32 + (radius32 * sin(i32 * twicePi32 / triangleAmount32))
        );
    }
glEnd();

int i33;
GLfloat x33 = 207+305+7.5; GLfloat y33 = 323; GLfloat radius33 = 10;
int triangleAmount33 = 100;

GLfloat twicePi33 = 2.0f * PI;

glColor3f(1.0f, 0.5f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x33, y33);
    for(i33 = 0; i33 <= triangleAmount33; i33++) {
        glVertex2f(
            x33 + (radius33 * cos(i33 * twicePi33 / triangleAmount33)),
            y33 + (radius33 * sin(i33 * twicePi33 / triangleAmount33))
        );
    }
glEnd();


glColor3f(0.4f, 0.2f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(202+305+7.5+25, 183 + 135);
glVertex2f(208+305+7.5+25, 183 + 135);
glVertex2f(208+305+7.5+25, 165 + 135);
glVertex2f(202+305+7.5+25, 165 + 135);
glEnd();

int i37;
GLfloat x37 = 202 + 305 + 7.5+25; GLfloat y37 = 318; GLfloat radius37 = 10;
int triangleAmount37 = 100;

GLfloat twicePi37 = 2.0f * PI;


glColor3f(0.54f, 0.17f, 0.89f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x37, y37);
    for(i37 = 0; i37 <= triangleAmount37; i37++) {
        glVertex2f(
            x37 + (radius37 * cos(i37 * twicePi37 / triangleAmount37)),
            y37 + (radius37 * sin(i37 * twicePi37 / triangleAmount37))
        );
    }
glEnd();

int i38;
GLfloat x38 = 213 + 305 + 7.5+25; GLfloat y38 = 318; GLfloat radius38 = 10;
int triangleAmount38 = 100;

GLfloat twicePi38 = 2.0f * PI;


glColor3f(0.54f, 0.17f, 0.89f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x38, y38);
    for(i38 = 0; i38 <= triangleAmount38; i38++) {
        glVertex2f(
            x38 + (radius38 * cos(i38 * twicePi38 / triangleAmount38)),
            y38 + (radius38 * sin(i38 * twicePi38 / triangleAmount38))
        );
    }
glEnd();

int i39;
GLfloat x39 = 207 + 305 + 7.5+25; GLfloat y39 = 323; GLfloat radius39 = 10;
int triangleAmount39 = 100;

GLfloat twicePi39 = 2.0f * PI;


glColor3f(0.54f, 0.17f, 0.89f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x39, y39);
    for(i39 = 0; i39 <= triangleAmount39; i39++) {
        glVertex2f(
            x39 + (radius39 * cos(i39 * twicePi39 / triangleAmount39)),
            y39 + (radius39 * sin(i39 * twicePi39 / triangleAmount39))
        );
    }
glEnd();

glColor3f(0.4f, 0.2f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(202+305+7.5+25+25, 183 + 135);
glVertex2f(208+305+7.5+25+25, 183 + 135);
glVertex2f(208+305+7.5+25+25, 165 + 135);
glVertex2f(202+305+7.5+25+25, 165 + 135);
glEnd();

int i40;
GLfloat x40 = 202 + 305 + 7.5 + 25 + 25; GLfloat y40 = 318; GLfloat radius40 = 10;
int triangleAmount40 = 100;

GLfloat twicePi40 = 2.0f * PI;

glColor3f(1.0f, 0.87f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x40, y40);
    for(i40 = 0; i40 <= triangleAmount40; i40++) {
        glVertex2f(
            x40 + (radius40 * cos(i40 * twicePi40 / triangleAmount40)),
            y40 + (radius40 * sin(i40 * twicePi40 / triangleAmount40))
        );
    }
glEnd();

int i41;
GLfloat x41 = 213 + 305 + 7.5 + 25 + 25; GLfloat y41 = 318; GLfloat radius41 = 10;
int triangleAmount41 = 100;

GLfloat twicePi41 = 2.0f * PI;

glColor3f(1.0f, 0.87f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x41, y41);
    for(i41 = 0; i41 <= triangleAmount41; i41++) {
        glVertex2f(
            x41 + (radius41 * cos(i41 * twicePi41 / triangleAmount41)),
            y41 + (radius41 * sin(i41 * twicePi41 / triangleAmount41))
        );
    }
glEnd();

int i42;
GLfloat x42 = 207 + 305 + 7.5 + 25 + 25; GLfloat y42 = 323; GLfloat radius42 = 10;
int triangleAmount42 = 100;

GLfloat twicePi42 = 2.0f * PI;

glColor3f(1.0f, 0.87f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x42, y42);
    for(i42 = 0; i42 <= triangleAmount42; i42++) {
        glVertex2f(
            x42 + (radius42 * cos(i42 * twicePi42 / triangleAmount42)),
            y42 + (radius42 * sin(i42 * twicePi42 / triangleAmount42))
        );
    }
glEnd();

glColor3f(0.4f, 0.2f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(202+305+7.5+25+25+25, 183 + 135);
glVertex2f(208+305+7.5+25+25+25, 183 + 135);
glVertex2f(208+305+7.5+25+25+25, 165 + 135);
glVertex2f(202+305+7.5+25+25+25, 165 + 135);
glEnd();

int i43;
GLfloat x43 = 202 + 305 + 7.5 + 25 + 25 + 25; GLfloat y43 = 318; GLfloat radius43 = 10;
int triangleAmount43 = 100;

GLfloat twicePi43 = 2.0f * PI;

glColor3f(0.2f, 0.8f, 0.2f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x43, y43);
    for(i43 = 0; i43 <= triangleAmount43; i43++) {
        glVertex2f(
            x43 + (radius43 * cos(i43 * twicePi43 / triangleAmount43)),
            y43 + (radius43 * sin(i43 * twicePi43 / triangleAmount43))
        );
    }
glEnd();

int i44;
GLfloat x44 = 213 + 305 + 7.5 + 25 + 25 + 25; GLfloat y44 = 318; GLfloat radius44 = 10;
int triangleAmount44 = 100;

GLfloat twicePi44 = 2.0f * PI;

glColor3f(0.2f, 0.8f, 0.2f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x44, y44);
    for(i44 = 0; i44 <= triangleAmount44; i44++) {
        glVertex2f(
            x44 + (radius44 * cos(i44 * twicePi44 / triangleAmount44)),
            y44 + (radius44 * sin(i44 * twicePi44 / triangleAmount44))
        );
    }
glEnd();

int i45;
GLfloat x45 = 207 + 305 + 7.5 + 25 + 25 + 25; GLfloat y45 = 323; GLfloat radius45 = 10;
int triangleAmount45 = 100;

GLfloat twicePi45 = 2.0f * PI;

glColor3f(0.2f, 0.8f, 0.2f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x45, y45);
    for(i45 = 0; i45 <= triangleAmount45; i45++) {
        glVertex2f(
            x45 + (radius45 * cos(i45 * twicePi45 / triangleAmount45)),
            y45 + (radius45 * sin(i45 * twicePi45 / triangleAmount45))
        );
    }
glEnd();


glColor3f(0.4f, 0.2f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(202+305+103, 183 + 135);
glVertex2f(208+305+103, 183 + 135);
glVertex2f(208+305+103, 165 + 135);
glVertex2f(202+305+103, 165 + 135);
glEnd();

int i34;
GLfloat x34 = 202 + 305 + 103; GLfloat y34 = 318; GLfloat radius34 = 10;
int triangleAmount34 = 100;

GLfloat twicePi34 = 2.0f * PI;

glColor3f(0.53f, 0.81f, 0.92f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x34, y34);
    for(i34 = 0; i34 <= triangleAmount34; i34++) {
        glVertex2f(
            x34 + (radius34 * cos(i34 * twicePi34 / triangleAmount34)),
            y34 + (radius34 * sin(i34 * twicePi34 / triangleAmount34))
        );
    }
glEnd();

int i35;
GLfloat x35 = 213 + 305 + 103; GLfloat y35 = 318; GLfloat radius35 = 10;
int triangleAmount35 = 100;

GLfloat twicePi35 = 2.0f * PI;

glColor3f(0.53f, 0.81f, 0.92f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x35, y35);
    for(i35 = 0; i35 <= triangleAmount35; i35++) {
        glVertex2f(
            x35 + (radius35 * cos(i35 * twicePi35 / triangleAmount35)),
            y35 + (radius35 * sin(i35 * twicePi35 / triangleAmount35))
        );
    }
glEnd();

int i36;
GLfloat x36 = 207 + 305 + 103; GLfloat y36 = 323; GLfloat radius36 = 10;
int triangleAmount36 = 100;

GLfloat twicePi36 = 2.0f * PI;

glColor3f(0.53f, 0.81f, 0.92f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x36, y36);
    for(i36 = 0; i36 <= triangleAmount36; i36++) {
        glVertex2f(
            x36 + (radius36 * cos(i36 * twicePi36 / triangleAmount36)),
            y36 + (radius36 * sin(i36 * twicePi36 / triangleAmount36))
        );
    }
glEnd();

}

/**........................................ Tree Circle 1 ...........................................**/
void Tree_Circle_1(){

glBegin(GL_POLYGON);
    glColor3f(0.55, 0.27, 0.07);


glVertex2f(107.58516, 386.69995);
glVertex2f(111.83184, 391.65442);
glVertex2f(117.49409, 396.60888);
glVertex2f(126, 400);
glVertex2f(131.64971, 400.14779);
glVertex2f(128.11081, 395.66517);
glVertex2f(121.26892, 390.23885);
glVertex2f(116.07853, 384.10475);
glVertex2f(113.95519, 374.19581);
glVertex2f(113.95519, 359.56834);
glVertex2f(113.95519+4, 326.30263);
glVertex2f(115.13482, 314.97813);
glVertex2f(118.67373, 308.6081);
glVertex2f(126, 300);
glVertex2f(96.17357, 300.51697);
glVertex2f(100.50734, 308.37217);
glVertex2f(102.39476, 314.97813);
glVertex2f(103.5744, 326.53855);
glVertex2f(104.5181-4, 360.04019);
glVertex2f(103.10254, 374.19581);
glVertex2f(99.56364, 385.75624);
glVertex2f(93.42953, 395.42925);
glVertex2f(90.12655-2, 400.61964+6);
glVertex2f(96, 400);
glVertex2f(100, 400);
glVertex2f(102.63069, 394.72147);
glVertex2f(104.5181, 390.23885);




glEnd();

    int i;

	GLfloat x=120; GLfloat y=433; GLfloat radius =40;
	int triangleAmount = 100;

	GLfloat twicePi = 2.0f * PI;

	glColor3f(0.0f, 0.6f, 0.0f);

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x, y);
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f( x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)) );
		}
glEnd();

int i1;

	GLfloat x1=60; GLfloat y1=446; GLfloat radius1 =40;
	int triangleAmount1 = 100;

	GLfloat twicePi1 = 2.0f * PI;

	 glColor3f(0.0f, 0.6f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x1, y1);
		for(i1 = 0; i1 <= triangleAmount1;i1++) {
			glVertex2f( x1 + (radius1 * cos(i1 *  twicePi1 / triangleAmount1)),
                        y1 + (radius1 * sin(i1 * twicePi1 / triangleAmount1)) );
		}
glEnd();

int i2;

	GLfloat x2=174; GLfloat y2=417; GLfloat radius2 =40;
	int triangleAmount2 = 100;

	GLfloat twicePi2 = 2.0f * PI;

	 glColor3f(0.0f, 0.6f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x2, y2);
		for(i2 = 0; i2 <= triangleAmount2;i2++) {
			glVertex2f( x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
                        y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2)) );
		}
glEnd();

int i3;

	GLfloat x3=162; GLfloat y3=476; GLfloat radius3 =40;
	int triangleAmount3 = 100;

	GLfloat twicePi3 = 2.0f * PI;

	 glColor3f(0.0f, 0.6f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x3, y3);
		for(i3 = 0; i3 <= triangleAmount3;i3++) {
			glVertex2f( x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
                        y3 + (radius3 * sin(i3 * twicePi3 / triangleAmount3)) );
		}
glEnd();

int i4;

	GLfloat x4=104; GLfloat y4=483; GLfloat radius4 =40;
	int triangleAmount4 = 100;

	GLfloat twicePi4 = 2.0f * PI;

	 glColor3f(0.0f, 0.6f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x4, y4);
		for(i4 = 0; i4 <= triangleAmount4;i4++) {
			glVertex2f( x4 + (radius4 * cos(i4 *  twicePi4 / triangleAmount4)),
                        y4 + (radius3 * sin(i4 * twicePi4 / triangleAmount4)) );
		}
glEnd();

}

/**........................................ Tree Circle 2 ...........................................**/
void Tree_Circle_2(){


glBegin(GL_POLYGON);
    glColor3f(0.55, 0.27, 0.07);


glVertex2f(939.58516, 386.69995);
glVertex2f(943.83184, 391.65442);
glVertex2f(949.49409, 396.60888);
glVertex2f(958.00000, 400.00000);
glVertex2f(963.64971, 400.14779);
glVertex2f(960.11081, 395.66517);
glVertex2f(953.26892, 390.23885);
glVertex2f(948.07853, 384.10475);
glVertex2f(945.95519, 374.19581);
glVertex2f(945.95519, 359.56834);
glVertex2f(949.95519, 326.30263);
glVertex2f(947.13482, 314.97813);
glVertex2f(950.67373, 308.60810);
glVertex2f(958.00000, 300.00000);
glVertex2f(928.17357, 300.51697);
glVertex2f(932.50734, 308.37217);
glVertex2f(934.39476, 314.97813);
glVertex2f(935.57440, 326.53855);
glVertex2f(932.51810, 360.04019);
glVertex2f(935.10254, 374.19581);
glVertex2f(931.56364, 385.75624);
glVertex2f(925.42953, 395.42925);
glVertex2f(920.12655, 406.61964);
glVertex2f(928.00000, 400.00000);
glVertex2f(932.00000, 400.00000);
glVertex2f(934.63069, 394.72147);
glVertex2f(936.51810, 390.23885);





glEnd();

    int i19;

	GLfloat x19=944; GLfloat y19=433; GLfloat radius19 =40;
	int triangleAmount19 = 100;


	GLfloat twicePi19 = 2.0f * PI;

	 glColor3f(0.0f, 0.6f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x19, y19);
		for(i19 = 0; i19 <= triangleAmount19;i19++) {
			glVertex2f( x19 + (radius19 * cos(i19 *  twicePi19 / triangleAmount19)),
                        y19 + (radius19 * sin(i19 * twicePi19 / triangleAmount19)) );
		}
glEnd();

int i20;

	GLfloat x20=884; GLfloat y20=446; GLfloat radius20 =40;
	int triangleAmount20 = 100;


	GLfloat twicePi20 = 2.0f * PI;

	 glColor3f(0.0f, 0.6f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x20, y20);
		for(i20 = 0; i20 <= triangleAmount20;i20++) {
			glVertex2f( x20 + (radius20 * cos(i20 *  twicePi20 / triangleAmount20)),
                        y20 + (radius20 * sin(i20 * twicePi20 / triangleAmount20)) );
		}
glEnd();

int i21;

	GLfloat x21=998; GLfloat y21=417; GLfloat radius21 =40;
	int triangleAmount21 = 100;

	GLfloat twicePi21 = 2.0f * PI;

	 glColor3f(0.0f, 0.6f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x21, y21);
		for(i21 = 0; i21 <= triangleAmount21;i21++) {
			glVertex2f( x21 + (radius21 * cos(i21 *  twicePi21 / triangleAmount21)),
                        y21 + (radius21 * sin(i21 * twicePi21 / triangleAmount21)) );
		}
glEnd();


int i22;

	GLfloat x22=990; GLfloat y22=476; GLfloat radius22 =40;
	int triangleAmount22 = 100;

	GLfloat twicePi22 = 2.0f * PI;

	 glColor3f(0.0f, 0.6f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x22, y22);
		for(i22 = 0; i22 <= triangleAmount22;i22++) {
			glVertex2f( x22 + (radius22 * cos(i22 *  twicePi22 / triangleAmount22)),
                        y22 + (radius22 * sin(i22 * twicePi22 / triangleAmount22)) );
		}
glEnd();

int i23;

	GLfloat x23=928; GLfloat y23=483; GLfloat radius23 =40;
	int triangleAmount23 = 100;

	GLfloat twicePi23 = 2.0f * PI;

	 glColor3f(0.0f, 0.6f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x23, y23);
		for(i23 = 0; i23 <= triangleAmount23;i23++) {
			glVertex2f( x23 + (radius23 * cos(i23 *  twicePi23 / triangleAmount23)),
                        y23 + (radius23 * sin(i23 * twicePi23 / triangleAmount23)) );
		}
glEnd();

}


/**........................................ Grass2 near tree 2 ...........................................**/
void Grass2_near_tree_2(){
glBegin(GL_POLYGON);
glColor3f(0.0f, 0.6f, 0.0f);
glVertex2f(896, 310);
glVertex2f(896, 330);
glVertex2f(910, 313);
glVertex2f(921, 327);
glVertex2f(921, 309);
glColor3f(0.8588f, 0.8078f, 0.0588f);
glVertex2f(941, 316);
glVertex2f(925, 300);
glVertex2f(886, 300);
glVertex2f(868, 316);
glEnd();
}

/**........................................ Sun ...........................................**/
void Sun(){


    glPushMatrix();
glTranslatef(sun_position,sun_position, 0.0f);
int i10;

	GLfloat x10=770; GLfloat y10=640; GLfloat radius10 =28;
	int triangleAmount10 = 100;
	GLfloat twicePi10 = 2.0f * PI;
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x10, y10);
		for(i10 = 0; i10 <= triangleAmount10;i10++) {
			glVertex2f( x10 + (radius10 * cos(i10 *  twicePi10 / triangleAmount10)),
                        y10 + (radius10 * sin(i10 * twicePi10 / triangleAmount10)) );
		}
glEnd();
glPopMatrix();
}



void Cloud(){

/**........................................ Cloud 1 ...........................................**/

glPushMatrix();

glTranslatef(cloud_Position, 0, 0.0f);

// Circle 1
int i555;
GLfloat x555 = 255; GLfloat y555 = 652; GLfloat radius555 = 55-17;
int triangleAmount555 = 100;
GLfloat twicePi555 = 2.0f * PI;

glColor3f(1, 1, 1);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x555, y555);
    for(i555 = 0; i555 <= triangleAmount555; i555++) {
        glVertex2f(x555 + (radius555 * cos(i555 * twicePi555 / triangleAmount555)),
                   y555 + (radius555 * sin(i555 * twicePi555 / triangleAmount555)));
    }
glEnd();

// Circle 2
int i666;
GLfloat x666 = 190+16; GLfloat y666 = 652; GLfloat radius666 = 37-15;
int triangleAmount666 = 100;
GLfloat twicePi666 = 2.0f * PI;

glColor3f(1, 1, 1);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x666, y666);
    for(i666 = 0; i666 <= triangleAmount666; i666++) {
        glVertex2f(x666 + (radius666 * cos(i666 * twicePi666 / triangleAmount666)),
                   y666 + (radius666 * sin(i666 * twicePi666 / triangleAmount666)));
    }
glEnd();

// Circle 3
int i767;
GLfloat x767 = 320-18; GLfloat y767 = 652; GLfloat radius767 = 38-15;
int triangleAmount767 = 100;
GLfloat twicePi767 = 2.0f * PI;

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x767, y767);
    for(i767 = 0; i767 <= triangleAmount767; i767++) {
        glVertex2f(x767 + (radius767 * cos(i767 * twicePi767 / triangleAmount767)),
                   y767 + (radius767 * sin(i767 * twicePi767 / triangleAmount767)));
    }
glEnd();

glPopMatrix();


/**........................................ Cloud 2 ...........................................**/


glPushMatrix();

glTranslatef(cloud_Position,0, 0.0f);
int i5;

	GLfloat x5=255+200+100; GLfloat y5=652-40; GLfloat radius5 =55-10-10-10;
	int triangleAmount5 = 100;
	GLfloat twicePi5 = 2.0f * PI;

	 glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x5, y5);
		for(i5 = 0; i5 <= triangleAmount5;i5++) {
			glVertex2f( x5 + (radius5 * cos(i5 *  twicePi5 / triangleAmount5)),
                        y5 + (radius5 * sin(i5 * twicePi5 / triangleAmount5)) );
		}
glEnd();

int i6;

	GLfloat x6=190+200+100+20+10+5; GLfloat y6=652-40; GLfloat radius6 =37-10-5-10;
	int triangleAmount6 = 100;

	GLfloat twicePi6 = 2.0f * PI;

	  glColor3f(1, 1, 1);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x6, y6);
		for(i6 = 0; i6 <= triangleAmount6;i6++) {
			glVertex2f( x6 + (radius6 * cos(i6 *  twicePi6 / triangleAmount6)),
                        y6+ (radius6 * sin(i6* twicePi6 / triangleAmount6)) );
		}
glEnd();



int i7;

	GLfloat x7=320+200+100-20-10; GLfloat y7=652-40; GLfloat radius7 =38-10-10;
	int triangleAmount7 = 100;

	GLfloat twicePi7 = 2.0f * PI;

	 glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x7, y7);
		for(i7 = 0; i7 <= triangleAmount7;i7++) {
			glVertex2f( x7 + (radius7 * cos(i7 *  twicePi7 / triangleAmount7)),
                        y7+ (radius7 * sin(i7 * twicePi7 / triangleAmount7)) );
		}
glEnd();

int i777;

	GLfloat x777=320+200+100-20-10-20; GLfloat y777=652-40-10; GLfloat radius777 =38-10-10;
	int triangleAmount777 = 100;

	GLfloat twicePi777 = 2.0f * PI;

	 glColor3f(0.83f, 0.83f, 0.83f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x777, y777);
		for(i777 = 0; i777 <= triangleAmount777;i777++) {
			glVertex2f( x777 + (radius777 * cos(i777 *  twicePi777 / triangleAmount777)),
                        y777+ (radius777 * sin(i777 * twicePi777 / triangleAmount777)) );
		}
glEnd();


int i7778;

	GLfloat x7778=320+200+100-20-10-20; GLfloat y7778=652-40-10+10; GLfloat radius7778 =38-10-10;
	int triangleAmount7778 = 100;

	GLfloat twicePi7778 = 2.0f * PI;

	 glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x7778, y7778);
		for(i7778 = 0; i7778 <= triangleAmount7778;i7778++) {
			glVertex2f( x7778 + (radius7778 * cos(i7778 *  twicePi7778 / triangleAmount7778)),
                        y7778+ (radius7778 * sin(i7778 * twicePi7778 / triangleAmount7778)) );
		}
glEnd();

glPopMatrix();

/**........................................ Cloud 3 ...........................................**/
glPushMatrix();
glTranslatef(cloud_Position,0, 0.0f);
int i8;

	GLfloat x8=914; GLfloat y8=670; GLfloat radius8 =25;
	int triangleAmount8 = 100;

	GLfloat twicePi8 = 2.0f * PI;

	 glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x8, y8);
		for(i8 = 0; i8 <= triangleAmount8;i8++) {
			glVertex2f( x8 + (radius8 * cos(i8 *  twicePi8 / triangleAmount8)),
                        y8 + (radius8 * sin(i8 * twicePi8 / triangleAmount8)) );
		}
glEnd();

int i9;
GLfloat x9=945; GLfloat y9=670; GLfloat radius9 =15;
	int triangleAmount9 = 100;

	GLfloat twicePi9 = 2.0f * PI;

	 glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x9, y9);
		for(i9 = 0; i9 <= triangleAmount9;i9++) {
			glVertex2f( x9 + (radius9 * cos(i9 *  twicePi9 / triangleAmount9)),
                        y9 + (radius9 * sin(i9 * twicePi9 / triangleAmount9)) );
		}
glEnd();


int i11;
GLfloat x11=887; GLfloat y11=670; GLfloat radius11 =15;
	int triangleAmount11 = 100;

	GLfloat twicePi11 = 2.0f * PI;

	 glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x11, y11);
		for(i11 = 0; i11 <= triangleAmount11;i11++) {
			glVertex2f( x11 + (radius11 * cos(i11 *  twicePi11 / triangleAmount11)),
                        y11 + (radius11 * sin(i11 * twicePi11 / triangleAmount11)) );
		}
glEnd();

int i12;
GLfloat x12=960; GLfloat y12=670; GLfloat radius12 =10;
	int triangleAmount12 = 100;

	GLfloat twicePi12 = 2.0f * PI;

	 glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x12, y12);
		for(i12 = 0; i12 <= triangleAmount12;i12++) {
			glVertex2f( x12 + (radius12 * cos(i12 *  twicePi12 / triangleAmount12)),
                        y12 + (radius12 * sin(i12 * twicePi12 / triangleAmount12)) );
		}
glEnd();
glPopMatrix();
//



/**........................................ Cloud 4 ...........................................**/

glPushMatrix();
glTranslatef(cloud_Position,0, 0.0f);
int i378;

GLfloat x378=914-530-28-20; GLfloat y378=670-30; GLfloat radius378 =23;
int triangleAmount378 = 100;

GLfloat twicePi378 = 2.0f * PI;

glColor3f(0.83f, 0.83f, 0.83f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x378, y378);
    for(i378 = 0; i378 <= triangleAmount378; i378++) {
        glVertex2f(x378 + (radius378 * cos(i378 * twicePi378 / triangleAmount378)),
                   y378 + (radius378 * sin(i378 * twicePi378 / triangleAmount378)));
    }
glEnd();

int i389;
GLfloat x389=945-530-28-20; GLfloat y389=670-30; GLfloat radius389 =15;
int triangleAmount389 = 100;

GLfloat twicePi389 = 2.0f * PI;


glColor3f(0.83f, 0.83f, 0.83f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x389, y389);
    for(i389 = 0; i389 <= triangleAmount389; i389++) {
        glVertex2f(x389 + (radius389 * cos(i389 * twicePi389 / triangleAmount389)),
                   y389 + (radius389 * sin(i389 * twicePi389 / triangleAmount389)));
    }
glEnd();

int i381;
GLfloat x381=887-530-28-20; GLfloat y381=670-30; GLfloat radius381 =15;
int triangleAmount381 = 100;

GLfloat twicePi381 = 2.0f * PI;

glColor3f(0.83f, 0.83f, 0.83f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x381, y381);
    for(i381 = 0; i381 <= triangleAmount381; i381++) {
        glVertex2f(x381 + (radius381 * cos(i381 * twicePi381 / triangleAmount381)),
                   y381 + (radius381 * sin(i381 * twicePi381 / triangleAmount381)));
    }
glEnd();

int i382;
GLfloat x382=960-530-28-20; GLfloat y382=670-30; GLfloat radius382 =10;
int triangleAmount382 = 100;

GLfloat twicePi382 = 2.0f * PI;

glColor3f(0.83f, 0.83f, 0.83f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x382, y382);
    for(i382 = 0; i382 <= triangleAmount382; i382++) {
        glVertex2f(x382 + (radius382 * cos(i382 * twicePi382 / triangleAmount382)),
                   y382 + (radius382 * sin(i382 * twicePi382 / triangleAmount382)));
    }
glEnd();

glPopMatrix();

}



/**........................................ Grave 1...........................................**/
void Grave_1(){
glColor3f(0.4f, 0.2f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(20, 215);
glVertex2f(48, 255);
glVertex2f(170, 255);
glVertex2f(170, 215);

glEnd();

glBegin(GL_TRIANGLES);
glColor4f(0.78f, 0.78f, 0.78f, 0.3f);
glVertex2f(170, 255);
glVertex2f(143, 215);
glVertex2f(170, 215);
glEnd();



glColor3f(0.0f, 1.0f, 1.0f);
renderBitmapString(30+17+9-5,235-6,0.0,GLUT_BITMAP_TIMES_ROMAN_24, " ADISON ");

/**........................................ Flower 1_1 ...........................................**/
 glColor3f(0.4f, 0.2f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(32, 183+34+19-15);
    glVertex2f(38, 183+34+19-15);
    glVertex2f(38,165+34+19-15);
    glVertex2f(32,165+34+19-15);
    glEnd();
    int i13;
    GLfloat x13=32; GLfloat y13=183+34+19-15; GLfloat radius13 =10;
	int triangleAmount13 = 100;

	GLfloat twicePi13 = 2.0f * PI;

    glColor3f(1.0f, 0.87f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x13, y13);
		for(i13 = 0; i13 <= triangleAmount13;i13++) {
			glVertex2f( x13 + (radius13 * cos(i13 *  twicePi13 / triangleAmount13)),
                        y13 + (radius13 * sin(i13 * twicePi13 / triangleAmount13)) );
		}
glEnd();

int i14;
    GLfloat x14=43; GLfloat y14=183+34+19-15; GLfloat radius14 =10;
	int triangleAmount14 = 100;

	GLfloat twicePi14 = 2.0f * PI;

   glColor3f(1.0f, 0.87f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x14, y14);
		for(i14 = 0; i14 <= triangleAmount14;i14++) {
			glVertex2f( x14 + (radius14 * cos(i14 *  twicePi14 / triangleAmount14)),
                        y14 + (radius14 * sin(i14 * twicePi14 / triangleAmount14)) );
		}
glEnd();

int i15;
    GLfloat x15=37; GLfloat y15=188+34+19-15; GLfloat radius15 =10;
	int triangleAmount15 = 100;

	GLfloat twicePi15 = 2.0f * PI;

   glColor3f(1.0f, 0.87f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x15, y15);
		for(i15 = 0; i15 <= triangleAmount13;i15++) {
			glVertex2f( x15 + (radius15 * cos(i15 *  twicePi15 / triangleAmount15)),
                        y15 + (radius15 * sin(i15 * twicePi15 / triangleAmount15)) );
		}
glEnd();


 /**........................................ Flower 1_2...........................................**/

    glColor3f(0.4f, 0.2f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(140, 183+34+19-15);
    glVertex2f(146, 183+34+19-15);
    glVertex2f(146,165+34+19-15);
    glVertex2f(140,165+34+19-15);
    glEnd();
    int i16;
    GLfloat x16=140; GLfloat y16=183+34+19-15; GLfloat radius16 =10;
	int triangleAmount16 = 100;
	GLfloat twicePi16 = 2.0f * PI;

    //glColor3f(1.0f, 0.87f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x16, y16);
		for(i16 = 0; i16 <= triangleAmount16;i16++) {
			glVertex2f( x16 + (radius16 * cos(i16 *  twicePi16 / triangleAmount16)),
                        y16 + (radius16 * sin(i16 * twicePi16 / triangleAmount16)) );
		}
glEnd();

int i17;
    GLfloat x17=151; GLfloat y17=183+34+19-15; GLfloat radius17 =10;
	int triangleAmount17 = 100;

	GLfloat twicePi17 = 2.0f * PI;

   //glColor3f(1.0f, 0.87f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x17, y17);
		for(i17 = 0; i17 <= triangleAmount17;i17++) {
			glVertex2f( x17 + (radius17 * cos(i17 *  twicePi17 / triangleAmount17)),
                        y17 + (radius17 * sin(i17 * twicePi17 / triangleAmount17)) );
		}
glEnd();

int i18;
    GLfloat x18=145; GLfloat y18=188+34+19-15; GLfloat radius18 =10;
	int triangleAmount18 = 100;

	GLfloat twicePi18 = 2.0f * PI;

   //glColor3f(1.0f, 0.87f, 0.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x18, y18);
		for(i18 = 0; i18 <= triangleAmount18;i18++) {
			glVertex2f( x18 + (radius18 * cos(i18 *  twicePi18 / triangleAmount18)),
                        y18 + (radius18 * sin(i18 * twicePi18 / triangleAmount18)) );
		}
glEnd();

}

/**.......................................Grave_2...........................................**/
void Grave_2()
{

glColor3f(0.4f, 0.2f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(190+20+5, 177+34+19-15);
glVertex2f(243, 236+34-15);
glVertex2f(340+20+5, 236+34-15);
glVertex2f(313+20+5, 177+34+19-15);
glEnd();

glBegin(GL_TRIANGLES);
glColor4f(0.78f, 0.78f, 0.78f, 0.3f);
glVertex2f(340+20+5, 236+34-15);
glVertex2f(313+20+5, 177+34+19-15);
glVertex2f(340+20+5, 177+34+19-15);
glEnd();

glColor3f(0.0f, 1.0f, 1.0f);
renderBitmapString(243,235-6,0.0,GLUT_BITMAP_TIMES_ROMAN_24, " LINKON ");

/**........................................Flower_21 ...........................................**/
glColor3f(0.4f, 0.2f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(202+20+5, 183+34+19-15);
glVertex2f(208+20+5, 183+34+19-15);
glVertex2f(208+20+5, 165+34+19-15);
glVertex2f(202+20+5, 165+34+19-15);
glEnd();

    int i24;
    GLfloat x24=202+20+5; GLfloat y24=183+34+19-15; GLfloat radius24 =10;
	int triangleAmount24 = 100;


	GLfloat twicePi24 = 2.0f * PI;

    //glColor3f(1.0f, 0.87f, 0.0f);
    glColor3f(1.0f, 0.5f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x24, y24);
		for(i24 = 0; i24 <= triangleAmount24;i24++) {
			glVertex2f( x24 + (radius24 * cos(i24 *  twicePi24/ triangleAmount24)),
                        y24 + (radius24 * sin(i24 * twicePi24 / triangleAmount24)) );
		}
glEnd();

int i25;
    GLfloat x25=213+20+5; GLfloat y25=183+34+19-15; GLfloat radius25 =10;
	int triangleAmount25 = 100;
	GLfloat twicePi25 = 2.0f * PI;

   //glColor3f(1.0f, 0.87f, 0.0f);
   //glColor3f(0.0f, 1.0f, 0.0f);
   glColor3f(1.0f, 0.5f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x25, y25);
		for(i25 = 0; i25 <= triangleAmount25;i25++) {
			glVertex2f( x25 + (radius25 * cos(i25 *  twicePi25 / triangleAmount25)),
                        y25 + (radius25 * sin(i25* twicePi25 / triangleAmount25)) );
		}
glEnd();

int i26;
    GLfloat x26=207+20+5; GLfloat y26=188+34+19-15; GLfloat radius26 =10;
	int triangleAmount26 = 100;

	GLfloat twicePi26 = 2.0f * PI;

   //glColor3f(1.0f, 0.87f, 0.0f);
   glColor3f(1.0f, 0.5f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x26, y26);
		for(i26 = 0; i26 <= triangleAmount26;i26++) {
			glVertex2f( x26 + (radius26 * cos(i26 *  twicePi26 / triangleAmount26)),
                        y26 + (radius26 * sin(i26 * twicePi26 / triangleAmount26)) );
		}
glEnd();

/**........................................Folwer_22 ...........................................**/

glColor3f(0.4f, 0.2f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(310+20+5, 183+34+19-15);
glVertex2f(316+20+5, 183+34+19-15);
glVertex2f(316+20+5, 165+34+19-15);
glVertex2f(310+20+5, 165+34+19-15);
glEnd();

int i27;
    GLfloat x27=310+20+5; GLfloat y27=183+34+19-15; GLfloat radius27 =10;
	int triangleAmount27 = 100;

	GLfloat twicePi27 = 2.0f * PI;
    glColor3f(1.0f, 0.87f, 0.0f);
    //glColor3f(1.0f, 0.5f, 0.0f);

	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x27, y27);
		for(i27 = 0; i27 <= triangleAmount27;i27++) {
			glVertex2f( x27 + (radius27 * cos(i27 *  twicePi27 / triangleAmount27)),
                        y27+ (radius27 * sin(i27 * twicePi27 / triangleAmount27)) );
		}
glEnd();

int i28;
GLfloat x28 = 315+20+5+5; GLfloat y28=183+34+19-15; GLfloat radius28 =10;
	int triangleAmount28 = 100;

	GLfloat twicePi28 = 2.0f * PI;

   glColor3f(1.0f, 0.87f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x28, y28);
		for(i28 = 0; i28 <= triangleAmount28;i28++) {
			glVertex2f( x28 + (radius28 * cos(i28 *  twicePi28 / triangleAmount28)),
                        y28 + (radius28 * sin(i28 * twicePi28 / triangleAmount28)) );
		}
glEnd();

int i29;
    GLfloat x29=315+20+5; GLfloat y29=188+34+19-15; GLfloat radius29 =10;
	int triangleAmount29 = 100;


	GLfloat twicePi29 = 2.0f * PI;

   glColor3f(1.0f, 0.87f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex2f(x29, y29);
		for(i29 = 0; i29 <= triangleAmount29;i29++) {
			glVertex2f( x29 + (radius29* cos(i29 *  twicePi29 / triangleAmount29)),
                        y29 + (radius29* sin(i29 * twicePi29 / triangleAmount29)) );
		}
glEnd();
//int i28;
}


/**........................................Grave 3...........................................**/
void Grave_3(){

glColor3f(0.4f, 0.2f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(772, 177+34+19-15);
glVertex2f(825-25, 236+34-15);
glVertex2f(947-25, 236+34-15);
glVertex2f(920-25, 177+34+19-15);
glEnd();

glBegin(GL_TRIANGLES);
glColor4f(0.78f, 0.78f, 0.78f, 0.3f);
glVertex2f(947-25, 236+34-15);
glVertex2f(920-25, 177+34+19-15);
glVertex2f(947-25, 177+34+19-15);
glEnd();

glColor3f(0.0f, 1.0f, 1.0f);
renderBitmapString(772+16+3+3,235-5-3,0.0,GLUT_BITMAP_TIMES_ROMAN_24, " Dr. JON ");

/**........................................ Flower 31...........................................**/
    glColor3f(0.4f, 0.2f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glBegin(GL_QUADS);
    glVertex2f(32+790-10-25, 183+34+19-15);
    glVertex2f(38+790-10-25, 183+34+19-15);
    glVertex2f(38+790-10-25,165+34+19-15);
    glVertex2f(32+790-10-25,165+34+19-15);
    glEnd();


int i247;
GLfloat x247 = 43 + 790 - 10 - 25 - 4-10;
GLfloat y247 = 183 + 34 + 19 - 15;
GLfloat radius247 = 10;
int triangleAmount247 = 100;

GLfloat twicePi247 = 2.0f * PI;

//glColor3f(1.0f, 0.87f, 0.0f);
glColor3f(0.54f, 0.17f, 0.89f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x247, y247);
    for(i247 = 0; i247 <= triangleAmount247; i247++) {
        glVertex2f(
            x247 + (radius247 * cos(i247 * twicePi247 / triangleAmount247)),
            y247 + (radius247 * sin(i247 * twicePi247 / triangleAmount247))
        );
    }
glEnd();

int i48;
GLfloat x48 = 37 + 790-10-25-4; GLfloat y48 = 188+34+19-15; GLfloat radius48 = 10;
int triangleAmount48 = 100;

GLfloat twicePi48 = 2.0f * PI;

//glColor3f(1.0f, 0.87f, 0.0f);
glColor3f(0.54f, 0.17f, 0.89f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x48, y48);
    for(i48 = 0; i48 <= triangleAmount48; i48++) {
        glVertex2f(
            x48 + (radius48 * cos(i48 * twicePi48 / triangleAmount48)),
            y48 + (radius48 * sin(i48 * twicePi48 / triangleAmount48))
        );
    }
glEnd();

int i47;
GLfloat x47 = 43 + 790-10-25-4; GLfloat y47 = 183+34+19-15; GLfloat radius47 = 10;
int triangleAmount47 = 100;

GLfloat twicePi47 = 2.0f * PI;

//glColor3f(1.0f, 0.87f, 0.0f);
glColor3f(0.54f, 0.17f, 0.89f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x47, y47);
    for(i47 = 0; i47 <= triangleAmount47; i47++) {
        glVertex2f(
            x47 + (radius47 * cos(i47 * twicePi47 / triangleAmount47)),
            y47 + (radius47 * sin(i47 * twicePi47 / triangleAmount47))
        );
    }
glEnd();





/**........................................ Flower 32 ...........................................**/
glColor3f(0.4f, 0.2f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(32+790+119-27-25, 183+34+19-15);
glVertex2f(38+790+119-27-25, 183+34+19-15);
glVertex2f(38+790+119-27-25,165+34+19-15);
glVertex2f(32+790+119-27-25,165+34+19-15);
glEnd();

int i49;
GLfloat x49 = 32 + 790+92-25; GLfloat y49 = 183+34+19-15; GLfloat radius49 = 10;
int triangleAmount49 = 100;

GLfloat twicePi49 = 2.0f * PI;

glColor3f(1.0f, 0.87f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x49, y49);
    for(i49 = 0; i49 <= triangleAmount49; i49++) {
        glVertex2f(
            x49 + (radius49 * cos(i49 * twicePi49 / triangleAmount49)),
            y49 + (radius49 * sin(i49 * twicePi49 / triangleAmount49))
        );
    }
glEnd();

int i50;
GLfloat x50 = 43 + 790+92-25; GLfloat y50 = 183+34+19-15; GLfloat radius50 = 10;
int triangleAmount50 = 100;

GLfloat twicePi50 = 2.0f * PI;

glColor3f(1.0f, 0.87f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x50, y50);
    for(i50 = 0; i50 <= triangleAmount50; i50++) {
        glVertex2f(
            x50 + (radius50 * cos(i50 * twicePi50 / triangleAmount50)),
            y50 + (radius50 * sin(i50 * twicePi50 / triangleAmount50))
        );
    }
glEnd();

int i51;
GLfloat x51 = 37 + 790+92-25; GLfloat y51 = 188+34+19-15; GLfloat radius51 = 10;
int triangleAmount51 = 100;

GLfloat twicePi51 = 2.0f * PI;

glColor3f(1.0f, 0.87f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x51, y51);
    for(i51 = 0; i51 <= triangleAmount51; i51++) {
        glVertex2f(
            x51 + (radius51 * cos(i51 * twicePi51 / triangleAmount51)),
            y51 + (radius51 * sin(i51 * twicePi51 / triangleAmount51))
        );
    }
glEnd();


}

/**........................................Grave 4 ...........................................**/
void Grave_4(){
glColor3f(0.4f, 0.2f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(975, 177+34+19-15);
glVertex2f(1003, 236+34-15);
glVertex2f(1125, 236+34-15);
glVertex2f(1098, 177+34+19-15);
glEnd();

glBegin(GL_TRIANGLES);
glColor4f(0.78f, 0.78f, 0.78f, 0.3f);
glVertex2f(1125, 236+34-15);
glVertex2f(1098, 177+34+19-15);
glVertex2f(1125, 177+34+19-15);
glEnd();

glColor3f(0.0f, 1.0f, 1.0f);
renderBitmapString(975+10+7,235-5-3,0.0,GLUT_BITMAP_TIMES_ROMAN_24, " JONSON ");

/**........................................Flower 4_1 ...........................................**/
    glColor3f(0.4f, 0.2f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(32+790-10+168, 183+34+19-15);
    glVertex2f(38+790-10+168, 183+34+19-15);
    glVertex2f(38+790-10+168,165+34+19-15);
    glVertex2f(32+790-10+168,165+34+19-15);
    glEnd();

int i52;
GLfloat x52 = 32 + 790 - 10 + 168; GLfloat y52 = 183 + 34 + 19-15; GLfloat radius52 = 10;
int triangleAmount52 = 100;

GLfloat twicePi52 = 2.0f * PI;

//glColor3f(1.0f, 0.87f, 0.0f);
//glColor3f(1.0f, 0.55f, 0.0f);
glColor3f(0.53f, 0.81f, 0.92f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x52, y52);
    for(i52 = 0; i52 <= triangleAmount52; i52++) {
        glVertex2f(
            x52 + (radius52 * cos(i52 * twicePi52 / triangleAmount52)),
            y52 + (radius52 * sin(i52 * twicePi52 / triangleAmount52))
        );
    }
glEnd();

int i53;
GLfloat x53 = 43 + 790 - 10 + 168; GLfloat y53 = 183 + 34 + 19-15; GLfloat radius53 = 10;
int triangleAmount53 = 100;

GLfloat twicePi53 = 2.0f * PI;

//glColor3f(1.0f, 0.87f, 0.0f);
//glColor3f(1.0f, 0.55f, 0.0f);
glColor3f(0.53f, 0.81f, 0.92f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x53, y53);
    for(i53 = 0; i53 <= triangleAmount53; i53++) {
        glVertex2f(
            x53 + (radius53 * cos(i53 * twicePi53 / triangleAmount53)),
            y53 + (radius53 * sin(i53 * twicePi53 / triangleAmount53))
        );
    }
glEnd();

int i54;
GLfloat x54 = 37 + 790 - 10 + 168; GLfloat y54 = 188 + 34 + 19-15; GLfloat radius54 = 10;
int triangleAmount54 = 100;

GLfloat twicePi54 = 2.0f * PI;

//glColor3f(1.0f, 0.87f, 0.0f);
glColor3f(1.0f, 0.55f, 0.0f);
glColor3f(0.53f, 0.81f, 0.92f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x54, y54);
    for(i54 = 0; i54 <= triangleAmount54; i54++) {
        glVertex2f(
            x54 + (radius54 * cos(i54 * twicePi54 / triangleAmount54)),
            y54 + (radius54 * sin(i54 * twicePi54 / triangleAmount54))
        );
    }
glEnd();


/**........................................ Flower 42 ...........................................**/
glColor3f(0.4f, 0.2f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(32+790+119-27+95+89, 183+34+19-15);
glVertex2f(38+790+119-27+95+89, 183+34+19-15);
glVertex2f(38+790+119-27+95+89,165+34+19-15);
glVertex2f(32+790+119-27+95+89,165+34+19-15);
glEnd();

int i55;
GLfloat x55 = 32 + 790 + 92 + 95 + 89; GLfloat y55 = 183 + 34 + 19-15; GLfloat radius55 = 10;
int triangleAmount55 = 100;

GLfloat twicePi55 = 2.0f * PI;

//glColor3f(1.0f, 0.87f, 0.0f);
glColor3f(1.0f, 0.41f, 0.71f);
//glColor3f(1.0f, 0.41f, 0.71f);
//glColor3f(0.53f, 0.81f, 0.92f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x55, y55);
    for(i55 = 0; i55 <= triangleAmount55; i55++) {
        glVertex2f(
            x55 + (radius55 * cos(i55 * twicePi55 / triangleAmount55)),
            y55 + (radius55 * sin(i55 * twicePi55 / triangleAmount55))
        );
    }
glEnd();

int i56;
GLfloat x56 = 43 + 790 + 92 + 95 + 89; GLfloat y56 = 183 + 34 + 19-15; GLfloat radius56 = 10;
int triangleAmount56 = 100;

GLfloat twicePi56 = 2.0f * PI;

//glColor3f(1.0f, 0.87f, 0.0f);
glColor3f(1.0f, 0.41f, 0.71f);
//glColor3f(0.53f, 0.81f, 0.92f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x56, y56);
    for(i56 = 0; i56 <= triangleAmount56; i56++) {
        glVertex2f(
            x56 + (radius56 * cos(i56 * twicePi56 / triangleAmount56)),
            y56 + (radius56 * sin(i56 * twicePi56 / triangleAmount56))
        );
    }
glEnd();

int i57;
GLfloat x57 = 37 + 790 + 92 + 95 + 89; GLfloat y57 = 188 + 34 + 19-15; GLfloat radius57 = 10;
int triangleAmount57 = 100;

GLfloat twicePi57 = 2.0f * PI;

//glColor3f(1.0f, 0.87f, 0.0f);
//glColor3f(1.0f, 0.41f, 0.71f);
//glColor3f(0.53f, 0.81f, 0.92f);
glColor3f(1.0f, 0.41f, 0.71f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x57, y57);
    for(i57 = 0; i57 <= triangleAmount57; i57++) {
        glVertex2f(
            x57 + (radius57 * cos(i57 * twicePi57 / triangleAmount57)),
            y57 + (radius57 * sin(i57 * twicePi57 / triangleAmount57))
        );
    }
glEnd();

}

/**........................................ Tree beside road ...........................................**/
void Tree_beside_road(){
 //Tree 1

    glColor3f(0.55, 0.27, 0.07);
    glBegin(GL_QUADS);
    glVertex2f(396-386,140);
    glVertex2f(411-386,140);
    glVertex2f(411-386,210);
    glVertex2f(396-386,210);
    glEnd();


   int i122;
GLfloat x122 = 403.5-386;
GLfloat y122 = 210+18;
GLfloat radius122 = 20;
int triangleAmount122 = 100;

GLfloat twicePi122 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x122, y122);
    for(i122 = 0; i122 <= triangleAmount122; i122++) {
        glVertex2f(
            x122 + (radius122 * cos(i122 * twicePi122 / triangleAmount122)),
            y122 + (radius122 * sin(i122 * twicePi122 / triangleAmount122))
        );
    }
glEnd();

int i123;
GLfloat x123 = 403.5-20-386;
GLfloat y123 = 210+18;
GLfloat radius123 = 15;
int triangleAmount123 = 100;

GLfloat twicePi123 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x123, y123);
    for(i123 = 0; i123 <= triangleAmount123; i123++) {
        glVertex2f(
            x123 + (radius123 * cos(i123 * twicePi123 / triangleAmount123)),
            y123 + (radius123 * sin(i123 * twicePi123 / triangleAmount123))
        );
    }
glEnd();

int i124;
GLfloat x124 = 403.5 + 20-386;
GLfloat y124 = 210+18;
GLfloat radius124 = 15;
int triangleAmount124 = 100;

GLfloat twicePi124 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x124, y124);
    for(i124 = 0; i124 <= triangleAmount124; i124++) {
        glVertex2f(
            x124 + (radius124 * cos(i124 * twicePi124 / triangleAmount124)),
            y124 + (radius124 * sin(i124 * twicePi124 / triangleAmount124))
        );
    }
glEnd();

int i125;
GLfloat x125 = 403.5-386;
GLfloat y125 = 210+20+18;
GLfloat radius125 = 15;
int triangleAmount125 = 100;

GLfloat twicePi125 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x125, y125);
    for(i125 = 0; i125 <= triangleAmount125; i125++) {
        glVertex2f(
            x125 + (radius125 * cos(i125 * twicePi125 / triangleAmount125)),
            y125 + (radius125 * sin(i125 * twicePi125 / triangleAmount125))
        );
    }
glEnd();


    //Tree 2
    glColor3f(0.55, 0.27, 0.07);
    glBegin(GL_QUADS);
    glVertex2f(396-215,140);
    glVertex2f(411-215,140);
    glVertex2f(411-215,210);
    glVertex2f(396-215,210);
    glEnd();


    int i118;
GLfloat x118 = 403.5-215;
GLfloat y118 = 210+18;
GLfloat radius118 = 20;
int triangleAmount118 = 100;

GLfloat twicePi118 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x118, y118);
    for(i118 = 0; i118 <= triangleAmount118; i118++) {
        glVertex2f(
            x118 + (radius118 * cos(i118 * twicePi118 / triangleAmount118)),
            y118 + (radius118 * sin(i118 * twicePi118 / triangleAmount118))
        );
    }
glEnd();

int i119;
GLfloat x119 = 403.5-20-215;
GLfloat y119 = 210+18;
GLfloat radius119 = 15;
int triangleAmount119 = 100;

GLfloat twicePi119 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x119, y119);
    for(i119 = 0; i119 <= triangleAmount119; i119++) {
        glVertex2f(
            x119 + (radius119 * cos(i119 * twicePi119 / triangleAmount119)),
            y119 + (radius119 * sin(i119 * twicePi119 / triangleAmount119))
        );
    }
glEnd();

int i120;
GLfloat x120 = 403.5 + 20-215;
GLfloat y120 = 210+18;
GLfloat radius120 = 15;
int triangleAmount120 = 100;

GLfloat twicePi120 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x120, y120);
    for(i120 = 0; i120 <= triangleAmount120; i120++) {
        glVertex2f(
            x120 + (radius120 * cos(i120 * twicePi120 / triangleAmount120)),
            y120 + (radius120 * sin(i120 * twicePi120 / triangleAmount120))
        );
    }
glEnd();

int i121;
GLfloat x121 = 403.5-215;
GLfloat y121 = 210+20+18;
GLfloat radius121 = 15;
int triangleAmount121 = 100;

GLfloat twicePi121 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x121, y121);
    for(i121 = 0; i121 <= triangleAmount121; i121++) {
        glVertex2f(
            x121 + (radius121 * cos(i121 * twicePi121 / triangleAmount121)),
            y121 + (radius121 * sin(i121 * twicePi121 / triangleAmount121))
        );
    }
glEnd();


    //tree 3
    glColor3f(0.55, 0.27, 0.07);
    glBegin(GL_QUADS);
    glVertex2f(396,140);
    glVertex2f(411,140);
    glVertex2f(411,210);
    glVertex2f(396,210);
    glEnd();

    int i110;
GLfloat x110 = 403.5;
GLfloat y110 = 210+18;
GLfloat radius110 = 20;
int triangleAmount110 = 100;

GLfloat twicePi110 = 2.0f * PI;

 glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x110, y110);
    for(i110 = 0; i110 <= triangleAmount110; i110++) {
        glVertex2f(
            x110 + (radius110 * cos(i110 * twicePi110 / triangleAmount110)),
            y110 + (radius110 * sin(i110 * twicePi110 / triangleAmount110))
        );
    }
glEnd();

int i111;
GLfloat x111 = 403.5-20;
GLfloat y111 = 210+18;
GLfloat radius111 = 15;
int triangleAmount111 = 100;

GLfloat twicePi111 = 2.0f * PI;

 glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x111, y111);
    for(i111 = 0; i111 <= triangleAmount111; i111++) {
        glVertex2f(
            x111 + (radius111 * cos(i111 * twicePi111 / triangleAmount111)),
            y111 + (radius111 * sin(i111 * twicePi111 / triangleAmount111))
        );
    }
glEnd();

int i112;
GLfloat x112 = 403.5 + 20;
GLfloat y112 = 210+18;
GLfloat radius112 = 15;
int triangleAmount112 = 100;

GLfloat twicePi112 = 2.0f * PI;

 glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x112, y112);
    for(i112 = 0; i112 <= triangleAmount112; i112++) {
        glVertex2f(
            x112 + (radius112 * cos(i112 * twicePi112 / triangleAmount112)),
            y112 + (radius112 * sin(i112 * twicePi112 / triangleAmount112))
        );
    }
glEnd();

int i113;
GLfloat x113 = 403.5;
GLfloat y113 = 210+20+18;
GLfloat radius113 = 15;
int triangleAmount113 = 100;

GLfloat twicePi113 = 2.0f * PI;

 glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x113, y113);
    for(i113 = 0; i113 <= triangleAmount113; i113++) {
        glVertex2f(
            x113 + (radius113 * cos(i113 * twicePi113 / triangleAmount113)),
            y113 + (radius113 * sin(i113 * twicePi113 / triangleAmount113))
        );
    }
glEnd();

//tree 4


    glColor3f(0.55, 0.27, 0.07);
    glBegin(GL_QUADS);
    glVertex2f(731,140);
    glVertex2f(716,140);
    glVertex2f(716,210);
    glVertex2f(731,210);
    glEnd();



    int i114;
GLfloat x114 = 723.5;
GLfloat y114 = 210+18;
GLfloat radius114 = 20;
int triangleAmount114 = 100;

GLfloat twicePi114 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x114, y114);
    for(i114 = 0; i114 <= triangleAmount114; i114++) {
        glVertex2f(
            x114 + (radius114 * cos(i114 * twicePi114 / triangleAmount114)),
            y114 + (radius114 * sin(i114 * twicePi114 / triangleAmount114))
        );
    }
glEnd();

int i115;
GLfloat x115 = 723.5-20;
GLfloat y115 = 210+18;
GLfloat radius115 = 15;
int triangleAmount115 = 100;

GLfloat twicePi115 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x115, y115);
    for(i115 = 0; i115 <= triangleAmount115; i115++) {
        glVertex2f(
            x115 + (radius115 * cos(i115 * twicePi115 / triangleAmount115)),
            y115 + (radius115 * sin(i115 * twicePi115 / triangleAmount115))
        );
    }
glEnd();

int i116;
GLfloat x116 = 723.5 + 20;
GLfloat y116 = 210+18;
GLfloat radius116 = 15;
int triangleAmount116 = 100;

GLfloat twicePi116 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x116, y116);
    for(i116 = 0; i116 <= triangleAmount116; i116++) {
        glVertex2f(
            x116 + (radius116 * cos(i116 * twicePi116 / triangleAmount116)),
            y116 + (radius116 * sin(i116 * twicePi116 / triangleAmount116))
        );
    }
glEnd();

int i117;
GLfloat x117 = 723.5;
GLfloat y117 = 210+20+18;
GLfloat radius117 = 15;
int triangleAmount117 = 100;

GLfloat twicePi117 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x117, y117);
    for(i117 = 0; i117 <= triangleAmount117; i117++) {
        glVertex2f(
            x117 + (radius117 * cos(i117 * twicePi117 / triangleAmount117)),
            y117 + (radius117 * sin(i117 * twicePi117 / triangleAmount117))
        );
    }
glEnd();



//Tree 5


    glColor3f(0.55, 0.27, 0.07);
    glBegin(GL_QUADS);
    glVertex2f(731+215,140);
    glVertex2f(716+215,140);
    glVertex2f(716+215,210);
    glVertex2f(731+215,210);
    glEnd();


int i126;
GLfloat x126 = 723.5+215;
GLfloat y126 = 210+18;
GLfloat radius126 = 20;
int triangleAmount126 = 100;

GLfloat twicePi126 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x126, y126);
    for(i126 = 0; i126 <= triangleAmount126; i126++) {
        glVertex2f(
            x126 + (radius126 * cos(i126 * twicePi126 / triangleAmount126)),
            y126 + (radius126 * sin(i126 * twicePi126 / triangleAmount126))
        );
    }
glEnd();

int i127;
GLfloat x127 = 723.5-20+215;
GLfloat y127 = 210+18;
GLfloat radius127 = 15;
int triangleAmount127 = 100;

GLfloat twicePi127 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x127, y127);
    for(i127 = 0; i127 <= triangleAmount127; i127++) {
        glVertex2f(
            x127 + (radius127 * cos(i127 * twicePi127 / triangleAmount127)),
            y127 + (radius127 * sin(i127 * twicePi127 / triangleAmount127))
        );
    }
glEnd();

int i128;
GLfloat x128 = 723.5 + 20+215;
GLfloat y128 = 210+18;
GLfloat radius128 = 15;
int triangleAmount128 = 100;

GLfloat twicePi128 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x128, y128);
    for(i128 = 0; i128 <= triangleAmount128; i128++) {
        glVertex2f(
            x128 + (radius128 * cos(i128 * twicePi128 / triangleAmount128)),
            y128 + (radius128 * sin(i128 * twicePi128 / triangleAmount128))
        );
    }
glEnd();

int i129;
GLfloat x129 = 723.5+215;
GLfloat y129 = 210+20+18;
GLfloat radius129 = 15;
int triangleAmount129 = 100;

GLfloat twicePi129 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x129, y129);
    for(i129 = 0; i129 <= triangleAmount129; i129++) {
        glVertex2f(
            x129 + (radius129 * cos(i129 * twicePi129 / triangleAmount129)),
            y129 + (radius129 * sin(i129 * twicePi129 / triangleAmount129))
        );
    }
glEnd();

//Tree 6

 glColor3f(0.55, 0.27, 0.07);
    glBegin(GL_QUADS);
    glVertex2f(731+215+194,140);
    glVertex2f(716+215+194,140);
    glVertex2f(716+215+194,210);
    glVertex2f(731+215+194,210);
    glEnd();

int i130;
GLfloat x130 = 723.5+215+194;
GLfloat y130 = 210+18;
GLfloat radius130 = 20;
int triangleAmount130 = 100;

GLfloat twicePi130 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x130, y130);
    for(i130 = 0; i130 <= triangleAmount130; i130++) {
        glVertex2f(
            x130 + (radius130 * cos(i130 * twicePi130 / triangleAmount130)),
            y130 + (radius130 * sin(i130 * twicePi130 / triangleAmount130))
        );
    }
glEnd();

int i131;
GLfloat x131 = 723.5-20+215+194;
GLfloat y131 = 210+18;
GLfloat radius131 = 15;
int triangleAmount131 = 100;

GLfloat twicePi131 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x131, y131);
    for(i131 = 0; i131 <= triangleAmount131; i131++) {
        glVertex2f(
            x131 + (radius131 * cos(i131 * twicePi131 / triangleAmount131)),
            y131 + (radius131 * sin(i131 * twicePi131 / triangleAmount131))
        );
    }
glEnd();

int i132;
GLfloat x132 = 723.5 + 20+215+194;
GLfloat y132 = 210+18;
GLfloat radius132 = 15;
int triangleAmount132 = 100;

GLfloat twicePi132 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x132, y132);
    for(i132 = 0; i132 <= triangleAmount132; i132++) {
        glVertex2f(
            x132 + (radius132 * cos(i132 * twicePi132 / triangleAmount132)),
            y132 + (radius132 * sin(i132 * twicePi132 / triangleAmount132))
        );
    }
glEnd();

int i133;
GLfloat x133 = 723.5+215+194;
GLfloat y133 = 210+20+18;
GLfloat radius133 = 15;
int triangleAmount133 = 100;

GLfloat twicePi133 = 2.0f * PI;

glColor3f(0.0f, 0.4f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x133, y133);
    for(i133 = 0; i133 <= triangleAmount133; i133++) {
        glVertex2f(
            x133 + (radius133 * cos(i133 * twicePi133 / triangleAmount133)),
            y133 + (radius133 * sin(i133 * twicePi133 / triangleAmount133))
        );
    }
glEnd();



   //
    glLineWidth(45.0f);
    glColor3f(0.0f, 0.4f, 0.0f);
    glBegin(GL_LINES);
    glVertex2f(0,140);
    glVertex2f(1175,140);
    glEnd();


    glColor3f(0.6f, 0.8f, 0.4f);

    glBegin(GL_QUADS);
    glVertex2f(471,270);
    glVertex2f(651,270);
    glVertex2f(716,100+20-2);
    glVertex2f(411,100+20-2);
    glEnd();


}

/**........................................Road ...........................................**/
void Road(){
glColor3f(0.7f, 0.7f, 0.7f);
glBegin(GL_QUADS);
glVertex2f(0, 120);
glVertex2f(1175, 120);
glVertex2f(1175, 140);
glVertex2f(0, 140);
glEnd();

glColor3f(0.4f, 0.4f, 0.4f);
glBegin(GL_QUADS);
glVertex2f(0, 20);
glVertex2f(1175, 20);
glVertex2f(1175, 120);
glVertex2f(0, 120);
glEnd();

glColor3f(0.7f, 0.7f, 0.7f);
glBegin(GL_QUADS);
glVertex2f(0, 20);
glVertex2f(1175, 20);
glVertex2f(1175, 0);
glVertex2f(0, 0);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_QUADS);
glVertex2f(0, 60);
glVertex2f(100, 60);
glVertex2f(100, 80);
glVertex2f(0, 80);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_QUADS);
glVertex2f(200, 60);
glVertex2f(400, 60);
glVertex2f(400, 80);
glVertex2f(200, 80);
glEnd();


glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_QUADS);
glVertex2f(500, 60);
glVertex2f(600, 60);
glVertex2f(600, 80);
glVertex2f(500, 80);
glEnd();

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_QUADS);
glVertex2f(700, 60);
glVertex2f(900, 60);
glVertex2f(900, 80);
glVertex2f(700, 80);
glEnd();


glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_QUADS);
glVertex2f(1000, 60);
glVertex2f(1100, 60);
glVertex2f(1100, 80);
glVertex2f(1000, 80);
glEnd();



glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_QUADS);
glVertex2f(1100, 60);
glVertex2f(1200, 60);
glVertex2f(1200, 80);
glVertex2f(1100, 80);
glEnd();

}

/**........................................Car ...........................................**/
void Car(){
    glLoadIdentity();
glPushMatrix();
glTranslatef(car_position,0, 0.0f);
glColor3f(0.0f, 0.2f, 0.6f);
glBegin(GL_QUADS);
glVertex2f(150, 100-34);
glVertex2f(450, 100-34);
glVertex2f(450, 160-34);
glVertex2f(150, 160-34);
glEnd();

glColor3f(0.0f, 0.2f, 0.6f);
glBegin(GL_QUADS);
glVertex2f(150, 160-34);
glVertex2f(100, 160-15-34);
glVertex2f(100, 100-34);
glVertex2f(150, 100-34);
glEnd();

//Light
glColor3f(1.0f, 0.4f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(120, 140-34);
glVertex2f(100, 140-34);
glVertex2f(100, 100+10+10-34);
glVertex2f(120, 100+10+10-34);
glEnd();

//Light 2

glColor3f(1.0f, 0.4f, 0.0f);
glBegin(GL_QUADS);
glVertex2f(450, 140+5-34);
glVertex2f(435, 140+5-34);
glVertex2f(435, 100+10+10-34);
glVertex2f(450, 100+10+10-34);
glEnd();

glColor3f(0.0f, 0.2f, 0.6f);
glBegin(GL_QUADS);
glVertex2f(200, 200-34);
glVertex2f(400, 200-34);
glVertex2f(400, 160-34);
glVertex2f(200, 160-34);
glEnd();

glColor3f(0.0f, 0.2f, 0.6f);
glBegin(GL_TRIANGLES);
glVertex2f(200, 200-34);
glVertex2f(150, 160-34);
glVertex2f(200, 160-34);
glEnd();


glColor3f(0.0f, 0.2f, 0.6f);
glBegin(GL_TRIANGLES);
glVertex2f(400, 200-34);
glVertex2f(400, 160-34);
glVertex2f(450, 160-34);
glEnd();

//Window
glColor4f(0.6f, 0.8f, 1.0f, 0.4f);
glBegin(GL_QUADS);
glVertex2f(210, 196-5-34);
glVertex2f(290, 196-5-34);
glVertex2f(290, 160-34);
glVertex2f(170, 160-34);
glEnd();
//Window
glColor4f(0.6f, 0.8f, 1.0f, 0.4f);
glBegin(GL_QUADS);
glVertex2f(300, 196-5-34);
glVertex2f(400-10, 196-5-34);
glVertex2f(400+18+7+6, 160-34);
glVertex2f(300, 160-34);
glEnd();

int i195;
GLfloat x195 = 200;
GLfloat y195 = 100-34;
GLfloat radius195 = 32;
int triangleAmount195 = 100;

GLfloat twicePi195 = 2.0f * PI;

glColor3f(0.0f, 0.00f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x195, y195);
    for(i195 = 0; i195 <= triangleAmount195; i195++) {
        glVertex2f(
            x195 + (radius195 * cos(i195 * twicePi195 / triangleAmount195)),
            y195 + (radius195 * sin(i195 * twicePi195 / triangleAmount195))
        );
    }
glEnd();

int i196;
GLfloat x196 = 380;
GLfloat y196 = 100-34;
GLfloat radius196 = 32;
int triangleAmount196 = 100;

GLfloat twicePi196 = 2.0f * PI;

glColor3f(0.0f, 0.0f, 0.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x196, y196);
    for(i196 = 0; i196 <= triangleAmount196; i196++) {
        glVertex2f(
            x196 + (radius196 * cos(i196 * twicePi196 / triangleAmount196)),
            y196 + (radius196 * sin(i196 * twicePi196 / triangleAmount196))
        );
    }
glEnd();



int i197;
GLfloat x197 = 200;
GLfloat y197 = 100 - 34;
GLfloat radius197 = 32-13;
int triangleAmount197 = 100;

GLfloat twicePi197 = 2.0f * PI;

glColor3f(1.0f, 1.00f, 1.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x197, y197);
    for(i197 = 0; i197 <= triangleAmount197; i197++) {
        glVertex2f(
            x197 + (radius197 * cos(i197 * twicePi197 / triangleAmount197)),
            y197 + (radius197 * sin(i197 * twicePi197 / triangleAmount197))
        );
    }
glEnd();

int i198;
GLfloat x198 = 380;
GLfloat y198 = 100 - 34;
GLfloat radius198 = 32-13;
int triangleAmount198 = 100;

GLfloat twicePi198 = 2.0f * PI;

glColor3f(1.0f, 1.0f, 1.0f);
glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x198, y198);
    for(i198 = 0; i198 <= triangleAmount198; i198++) {
        glVertex2f(
            x198 + (radius198 * cos(i198 * twicePi198 / triangleAmount198)),
            y198 + (radius198 * sin(i198 * twicePi198 / triangleAmount198))
        );
    }
glEnd();
glPopMatrix();

}



void display_Scenario3() {


    glClear(GL_COLOR_BUFFER_BIT);

    backimage();
    //Back_ground();//

     Sun();
    HIll();
    Tree1();
    Grass1();
    Rose();
    Grass3_Left_most();
    Tree2();
    Tree3_Wright_most();
    Small_tree_Rightmost();
    HOUSE();
    railing();
    Plus_sign();
    First_vertical_line();
    Second_horizontal_line();
    Tree_Circle_1();
    Tree_Circle_2();
    Grass2_near_tree_2();
    Cloud();
    Grave_1();
    Grave_2();
    Grave_3();
    Grave_4();
    Tree_beside_road();
    Road();
    Car();
    bird();


    glFlush();


}

void displaymenu() {
    switch (currentScenarioState) {
        case COVER_PAGE:
            display_CoverPage();
            break;
        case INSTRUCTIONS:
            display_InstructionPage();
            break;
        case SCENARIO_1:
            display_Scenario1();
            break;
        case SCENARIO_2:
            display_Scenario2();
            break;
        case SCENARIO_3:
            display_Scenario3();
            break;
        case SCENARIO_4:
            display_Scenario4();
            break;
        case SCENARIO_5:
            //display_Scenario5();
            break;
        case OPTIONS:
            // If you implement an options page, call its display function here
            // display_OptionsPage();
            break;
    }
}






void handleKeypress(unsigned char key, int x, int y)
{
    switch (key)
    {
    case '1':
        currentScenarioState = SCENARIO_1;
        break;
    case '2':
        currentScenarioState = SCENARIO_2;
        break;
    case '3':
        currentScenarioState = SCENARIO_3;
        break;
    case '4':
        currentScenarioState = SCENARIO_4;
        break;
    case '5':
        currentScenarioState = SCENARIO_5;
        break;
    case 'i': // Press 'i' to go to the instructions page
        currentScenarioState = INSTRUCTIONS;
        break;
    case 'w': // Press 'w' to go back to the cover page
        currentScenarioState = COVER_PAGE;
        break;
    case 27: // ESC key to exit the application
        exit(0);
        break;

    case 'c': // Toggle cloud animation
        cloudsAnimating = !cloudsAnimating;
        break;
    case 's': // Toggle sun animation
        sunAnimating = !sunAnimating;
        break;
    case 'b': // Toggle bird animation
        birdsAnimating = !birdsAnimating;
        break;
    case '8': // Reverse cloud direction
        cloudDirection = -cloudDirection;
        break;
    case '9': // Reverse sun direction
        sunDirection = -sunDirection;
        break;
    case 'd':
        isNightMode = false;
        isDay = true;
        ///
        is_Day = true;
        animateSunMoon = true;
        sunToDown = false;
        moonToUp = false;

        break;
    case 'n': // Night mode
        isNightMode = true;
        isDay = false;
        ///------
        is_Day = false;
        animateSunMoon = true;
        sunToDown = true;
        moonToUp = true;
        break;
    case 'r':
        cloudMovingRight = true;
        ///----------
        isRaining = !isRaining;
        if (isRaining)
        {
            PlaySound("RAIN.wav", NULL, SND_ASYNC | SND_LOOP);
        }
        else
        {
            PlaySound(NULL, 0, 0);
            // Resume main boat sound if moving
            if (boatMoving) PlaySound("SOUND2.wav", NULL, SND_ASYNC | SND_LOOP);
        }
        break;
    case 'l':  // Move clouds from right to left
        cloudMovingRight = false;
        break;

    case ' ':
        boatMoving = !boatMoving;
        if (boatMoving)
            PlaySound("SOUND2.wav", NULL, SND_ASYNC | SND_LOOP);
        else
            PlaySound(NULL, 0, 0);
        break;


    }
    glutPostRedisplay();

}


void mouse(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN)
    {
        if (button == GLUT_LEFT_BUTTON)
        {
            boatMovingRight = false;
            cloud_MovingRight = false;
        }

        else if (button == GLUT_RIGHT_BUTTON)
        {
            boatMovingRight = true;
            cloud_MovingRight = true;
        }

    }
}
void SpecialInput(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        glutTimerFunc(100, update_car, 0);
        break;

    case GLUT_KEY_DOWN:

        car_speed =0.0f;

        break;

    case GLUT_KEY_LEFT:
        if(car_speed<=0.0f)
        {
            car_speed = 10;
            glutTimerFunc(100, update_car, 0);
        }
        glutTimerFunc(100, update_car, 0);

        if (!boatMoving || boatSpeed <= 0.0f) {
            boatSpeed = 2.0f;
            boatMoving = true;
            PlaySound(NULL, 0, 0);
            PlaySound("SOUND.wav", NULL, SND_ASYNC | SND_LOOP);
        } else {
            boatSpeed *= 1.5f;
        }

        break;

    case GLUT_KEY_RIGHT:
        car_speed=car_speed-5;


        glutTimerFunc(100, update_car, 0);

         boatSpeed /= 1.5f;
        if (boatSpeed <= 0.1f) {
            boatSpeed = 0.0f;
            boatMoving = false;
            PlaySound(NULL, 0, 0);
        }
        break;
    }
    glutPostRedisplay();
}






// Initialization
void initOpenGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 1150, 0, 750, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
}



/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(1150, 750); // Set the window's initial width & height
    glutInitWindowPosition(80, 50);  // Set the window's initial position according to the monitor
    glutCreateWindow("Historical Place in Bangladesh"); // Create a window with the given title
    initOpenGL();
    glutDisplayFunc(displaymenu); // Register display callback handler for window re-paint
    glutIdleFunc(Idle);//glutIdleFunc sets the global idle callback to be func so a GLUT program can perform background processing tasks or continuous animation when window system events are not being received.
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(mouse);
    glutSpecialFunc(SpecialInput);
    ///-----------------Arnob---------------
    sound();
    initializeBirds();
    glutTimerFunc(20, updateCloud, 0);
    glutTimerFunc(20, updateSun, 0);
    glutTimerFunc(20, updateBirds, 0);
    ///------------------Salehin--------------
    initOpenGL();
    initStars();
    initRain();
    glutTimerFunc(1000, updateScene, 0);
    ///------------------Tutul-----------
    glutTimerFunc(40, updateAnimation, 0);

    ///-------------Anay-----------------
    glutTimerFunc(30, update_car, 0);
    glutTimerFunc(20, update_Cloud, 0);
    glutTimerFunc(20, update_sun, 0);
    glutTimerFunc(20, update_bird, 0);


    glutMainLoop(); // Enter the event-processing loop
    return 0;
}
