#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <math.h>
#include<iostream>
using namespace std;

#define NUM_DROPS 40

float carOffset1 = 0.0f;    // upper car
float carOffset2 = 0.0f;    // lower car
float trainOffset = -60.0f; // metro
float cloudOffset1 = 0.0f;  // clouds  group A drifts right
float cloudOffset2 = 0.0f;  // clouds group B drifts left

int isNight = 0; // 0 = day, 1 = night
                                                        //moti day night rain
                                                        //uttara day night rain
int isRain = 0;
float rainX[NUM_DROPS];
float rainY[NUM_DROPS];

int stationIndex = 0; // 0 = Motijheel, 1 = Uttara Uttar

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'n' || key == 'N') {
        isNight = 1;
            PlaySound("n2.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
    }
    if (key == 'd' || key == 'D') {
        isNight = 0;
        PlaySound("d.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
    }
    if (key == 'r' || key == 'R') {
        isRain = !isRain;
        if (isRain)
                PlaySound("r.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);
        else
            PlaySound(NULL, NULL, 0);
    }
    glutPostRedisplay();
}
void initGL() {
	glClearColor(0.25f, 0.6f, 0.03f, 1.0f);

    for (int i = 0; i < NUM_DROPS; i++) {
        rainX[i] = (float)(rand() % 200);
        rainY[i] = (float)(rand() % 140);
    }
}


void drawRain()
{
    glColor3ub(190, 205, 220);
    glLineWidth(1.5f);
    glBegin(GL_LINES);
    for (int i = 0; i < NUM_DROPS; i++) {
        glVertex2f(rainX[i], rainY[i]);
        glVertex2f(rainX[i] - 1.5f, rainY[i] - 6.0f);
    }
    glEnd();

}

void drawDullSky()
{
    glColor3ub(120, 125, 130);
    glBegin(GL_QUADS);
    glVertex2f(0.0f, 98.0f);
    glVertex2f(200.0f, 98.0f);
    glVertex2f(200.0f, 140.0f);
    glVertex2f(0.0f, 140.0f);
    glEnd();
}
void drawCircle(float cx, float cy, float r, int segments)
{
    glBegin(GL_TRIANGLE_FAN);
    //glColor3f(0,0,0);
    glVertex2f(cx, cy);
    for (int i = 0; i <= segments; i++) {
        float theta = 2.0f * 3.14159265f * i / segments;
        glVertex2f(cx + r * cosf(theta), cy + r * 0.6f * sinf(theta));
    }
    glEnd();
}

void drawRect(float x1, float y1, float x2, float y2)
{
    glBegin(GL_QUADS);
    glVertex2f(x1, y1);
    glVertex2f(x2, y1);
    glVertex2f(x2, y2);
    glVertex2f(x1, y2);
    glEnd();
}

void drawMoon(float cx, float cy, float r)
{
    glColor3ub(240, 240, 225);
    drawCircle(cx, cy, r, 24);

    glColor3ub(210, 210, 195);          // craters
    drawCircle(cx - r*0.3f, cy + r*0.2f, r*0.18f, 10);
    drawCircle(cx + r*0.25f, cy - r*0.15f, r*0.14f, 10);
}

void bg()                   //day scenario of Motijheel Part
{


// ---------------- SKY
glBegin(GL_QUADS);
    glColor3ub(120, 190, 235);      //deep sky blue at top
    glVertex2f(0.0f, 140.0f);
    glVertex2f(200.0f, 140.0f);
    glColor3ub(255, 232, 205);     //warm at bottom
    glVertex2f(200.0f, 50.0f);
    glVertex2f(0.0f, 50.0f);
glEnd();

//----------------------Sun
glColor3ub(255, 244, 190);
drawCircle(166.67f, 128.0f, 9.0f, 24);   // outer glow

glColor3ub(255, 221, 120);
drawCircle(166.67f, 128.0f, 6.0f, 24);   /* sun core   */

                        //---------------------------Buildings
glBegin(GL_QUADS);
    glColor3ub(150, 165, 185);
    glVertex2f(6.67f, 50.0f);  glVertex2f(26.67f, 50.0f);
    glVertex2f(26.67f, 86.0f); glVertex2f(6.67f, 86.0f);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(130, 145, 168);
    glVertex2f(31.67f, 50.0f);  glVertex2f(51.67f, 50.0f);
    glVertex2f(51.67f, 98.0f);  glVertex2f(31.67f, 98.0f);
glEnd();


glBegin(GL_QUADS);
    glColor3ub(135, 150, 172);
    glVertex2f(150.0f, 50.0f);  glVertex2f(170.0f, 50.0f);
    glVertex2f(170.0f, 92.0f);  glVertex2f(150.0f, 92.0f);
glEnd();

glBegin(GL_QUADS);
    glColor3ub(155, 168, 188);
    glVertex2f(175.0f, 50.0f); glVertex2f(196.67f, 50.0f);
    glVertex2f(196.67f, 80.0f); glVertex2f(175.0f, 80.0f);
glEnd();


glBegin(GL_QUADS);
    glColor3ub(210, 207, 195);
    glVertex2f(58.33f, 50.0f); glVertex2f(83.33f, 50.0f);
    glVertex2f(83.33f, 72.0f); glVertex2f(58.33f, 72.0f);
glEnd();


glBegin(GL_QUADS);
    glColor3ub(210, 207, 195);
    glVertex2f(116.67f, 50.0f); glVertex2f(141.67f, 50.0f);
    glVertex2f(141.67f, 68.0f); glVertex2f(116.67f, 68.0f);
glEnd();


glBegin(GL_QUADS);
    glColor3ub(225, 222, 210);
    glVertex2f(83.33f, 50.0f); glVertex2f(116.67f, 50.0f);
    glVertex2f(116.67f, 95.0f); glVertex2f(83.33f, 95.0f);
glEnd();


glColor3ub(225, 222, 210);
drawCircle(100.0f, 95.0f, 10.0f, 24);

glColor3ub(60, 60, 55);
drawCircle(91.67f, 80.0f, 1.8f, 12);
drawCircle(108.33f, 85.0f, 1.8f, 12);

glBegin(GL_TRIANGLES);
    glColor3ub(60, 60, 55);
    glVertex2f(96.67f, 65.0f);
    glVertex2f(103.33f, 65.0f);
    glVertex2f(100.0f, 70.0f);
glEnd();
}

void bgNight()
{
    // ---------------- NIGHT SKY
    glBegin(GL_QUADS);
        glColor3ub(10, 15, 45);
        glVertex2f(0.0f, 140.0f);
        glVertex2f(200.0f, 140.0f);
        glColor3ub(45, 40, 75);
        glVertex2f(200.0f, 50.0f);
        glVertex2f(0.0f, 50.0f);
    glEnd();

    //---------------------- Moon
    drawMoon(166.67f, 128.0f, 7.0f);      //moon function calling

                            //---------------------------Buildings (darkened)
    glBegin(GL_QUADS);
        glColor3ub(60, 66, 74);
        glVertex2f(6.67f, 50.0f);  glVertex2f(26.67f, 50.0f);
        glVertex2f(26.67f, 86.0f); glVertex2f(6.67f, 86.0f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(52, 58, 67);
        glVertex2f(31.67f, 50.0f);  glVertex2f(51.67f, 50.0f);
        glVertex2f(51.67f, 98.0f);  glVertex2f(31.67f, 98.0f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(54, 60, 69);
        glVertex2f(150.0f, 50.0f);  glVertex2f(170.0f, 50.0f);
        glVertex2f(170.0f, 92.0f);  glVertex2f(150.0f, 92.0f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(62, 67, 75);
        glVertex2f(175.0f, 50.0f); glVertex2f(196.67f, 50.0f);
        glVertex2f(196.67f, 80.0f); glVertex2f(175.0f, 80.0f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(84, 83, 78);
        glVertex2f(58.33f, 50.0f); glVertex2f(83.33f, 50.0f);
        glVertex2f(83.33f, 72.0f); glVertex2f(58.33f, 72.0f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(84, 83, 78);
        glVertex2f(116.67f, 50.0f); glVertex2f(141.67f, 50.0f);
        glVertex2f(141.67f, 68.0f); glVertex2f(116.67f, 68.0f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(90, 89, 84);
        glVertex2f(83.33f, 50.0f); glVertex2f(116.67f, 50.0f);
        glVertex2f(116.67f, 95.0f); glVertex2f(83.33f, 95.0f);
    glEnd();

    glColor3ub(90, 89, 84);
    drawCircle(100.0f, 95.0f, 10.0f, 24);

    glColor3ub(255, 221, 120);           // eyes lit up at night
    drawCircle(91.67f, 80.0f, 1.8f, 12);
    drawCircle(108.33f, 85.0f, 1.8f, 12);

    glBegin(GL_TRIANGLES);
        glColor3ub(30, 30, 28);
        glVertex2f(96.67f, 65.0f);
        glVertex2f(103.33f, 65.0f);
        glVertex2f(100.0f, 70.0f);
    glEnd();

                            //---------------------------Lit windows
    glColor3ub(255, 214, 120);
    drawRect(10.0f, 55.0f, 13.0f, 58.0f);
    drawRect(20.0f, 55.0f, 23.0f, 58.0f);
    drawRect(10.0f, 68.0f, 13.0f, 71.0f);

    glColor3ub(255, 196, 90);
    drawRect(20.0f, 68.0f, 23.0f, 71.0f);
    drawRect(10.0f, 78.0f, 13.0f, 81.0f);

    glColor3ub(255, 214, 120);
    drawRect(36.0f, 56.0f, 39.0f, 59.0f);
    drawRect(44.0f, 56.0f, 47.0f, 59.0f);
    drawRect(36.0f, 70.0f, 39.0f, 73.0f);

    glColor3ub(0,0,0);
    drawRect(44.0f, 70.0f, 47.0f, 73.0f);
    drawRect(36.0f, 84.0f, 39.0f, 87.0f);

    glColor3ub(255, 214, 120);
    drawRect(154.0f, 56.0f, 157.0f, 59.0f);
    drawRect(162.0f, 56.0f, 165.0f, 59.0f);
    drawRect(154.0f, 70.0f, 157.0f, 73.0f);

    glColor3ub(255, 196, 90);
    drawRect(162.0f, 70.0f, 165.0f, 73.0f);

    glPushMatrix();
    for(int i=5; i<=10; i=i+5){
    glTranslated(0,i,0);
    drawRect(162.0f, 70.0f, 165.0f, 73.0f);
    }
    glPopMatrix();

    glPushMatrix();
    for(int i=5; i<=10; i=i+5){
    glTranslated(0,i,0);
    drawRect(155.0f, 70.0f, 158.0f, 73.0f);
    }
    glPopMatrix();

    glPushMatrix();
    for(int i=5; i<=10; i=i+5){
    glTranslated(0,i,0);
    drawRect(180.0f, 56.0f, 183.0f, 59.0f);
    drawRect(188.0f, 56.0f, 191.0f, 59.0f);
    }
    glPopMatrix();

}


void stationa()
{
/* =========================================
       DHAKA METRO STATION STYLE (Motijheel)
       ========================================= */

    /* 1. MAIN BRICK WALL (Backdrop) */
    glBegin(GL_QUADS);
        glColor3ub(165, 75, 55); // Brick Red color
        glVertex2f(0.0f, 71.0f);
        glVertex2f(55.0f, 71.0f);
        glVertex2f(55.0f, 95.0f);
        glVertex2f(0.0f, 95.0f);
    glEnd();

    /* 2. HORIZONTAL LOUVERS / WINDOW BANDS */
    // Unrolled for efficiency
    glBegin(GL_QUADS);
        glColor3ub(50, 60, 70); // Dark grey glass/louvers

        // Bottom Band
        glVertex2f(0.0f, 74.0f); glVertex2f(55.0f, 74.0f);
        glVertex2f(55.0f, 77.0f); glVertex2f(0.0f, 77.0f);

        // Middle Band
        glVertex2f(0.0f, 81.0f); glVertex2f(55.0f, 81.0f);
        glVertex2f(55.0f, 84.0f); glVertex2f(0.0f, 84.0f);

        // Top Band
        glVertex2f(0.0f, 88.0f); glVertex2f(55.0f, 88.0f);
        glVertex2f(55.0f, 91.0f); glVertex2f(0.0f, 91.0f);
    glEnd();

    /* 3. HEAVY VERTICAL CONCRETE PILLARS */
    glBegin(GL_QUADS);
        glColor3ub(170, 175, 180); // Light Concrete Grey

        // Column 1
        glVertex2f(0.0f, 50.0f);  glVertex2f(4.0f, 50.0f);
        glVertex2f(4.0f, 97.0f);  glVertex2f(0.0f, 97.0f);

        // Column 2
        glVertex2f(17.0f, 50.0f); glVertex2f(21.0f, 50.0f);
        glVertex2f(21.0f, 97.0f); glVertex2f(17.0f, 97.0f);

        // Column 3
        glVertex2f(34.0f, 50.0f); glVertex2f(38.0f, 50.0f);
        glVertex2f(38.0f, 97.0f); glVertex2f(34.0f, 97.0f);

        // Column 4
        glVertex2f(51.0f, 50.0f); glVertex2f(55.0f, 50.0f);
        glVertex2f(55.0f, 97.0f); glVertex2f(51.0f, 97.0f);
    glEnd();

    /* 4. TOP HORIZONTAL CONCRETE BEAM */
    glBegin(GL_QUADS);
        glColor3ub(190, 195, 200); // Lighter Concrete
        glVertex2f(0.0f, 95.0f);  glVertex2f(55.0f, 95.0f);
        glVertex2f(55.0f, 97.0f); glVertex2f(0.0f, 97.0f);
    glEnd();

    /* 5. ELEVATED TRACK VIADUCT (Base for the train) */
    glBegin(GL_QUADS);
        glColor3ub(150, 150, 155); // Solid grey base
        glVertex2f(0.0f, 50.0f);   glVertex2f(55.0f, 50.0f);
        glVertex2f(55.0f, 69.0f);  glVertex2f(0.0f, 69.0f);

        glColor3ub(130, 130, 135); // Shadow/Track bed edge
        glVertex2f(0.0f, 69.0f);   glVertex2f(55.0f, 69.0f);
        glVertex2f(55.0f, 71.0f);  glVertex2f(0.0f, 71.0f);
    glEnd();

    /* 6. STEEL TRUSS ROOF SUPPORTS */
    glLineWidth(2.5f);
    glBegin(GL_LINES);
        glColor3ub(130, 135, 140); // Steel grey

        // V-Shape 1
        glVertex2f(2.0f, 97.0f);   glVertex2f(8.5f, 104.0f);
        glVertex2f(15.0f, 97.0f);  glVertex2f(8.5f, 104.0f);
        glVertex2f(8.5f, 97.0f);   glVertex2f(8.5f, 104.0f); // Center support

        // V-Shape 2
        glVertex2f(19.0f, 97.0f);  glVertex2f(25.5f, 106.5f);
        glVertex2f(32.0f, 97.0f);  glVertex2f(25.5f, 106.5f);
        glVertex2f(25.5f, 97.0f);  glVertex2f(25.5f, 106.5f); // Center support

        // V-Shape 3
        glVertex2f(36.0f, 97.0f);  glVertex2f(42.5f, 106.5f);
        glVertex2f(49.0f, 97.0f);  glVertex2f(42.5f, 106.5f);
        glVertex2f(42.5f, 97.0f);  glVertex2f(42.5f, 106.5f); // Center support
    glEnd();

    /* 7. CURVED GREEN CORRUGATED ROOF */
    // Using GL_QUAD_STRIP to smoothly draw the arch without loops
    glBegin(GL_QUAD_STRIP);
        glColor3ub(35, 120, 65); // Iconic Metro Green
        glVertex2f(0.0f, 100.0f);  glVertex2f(0.0f, 103.0f);
        glVertex2f(15.0f, 105.0f); glVertex2f(15.0f, 108.0f);
        glVertex2f(27.5f, 107.0f); glVertex2f(27.5f, 110.0f); // Peak at Y=110
        glVertex2f(40.0f, 105.0f); glVertex2f(40.0f, 108.0f);
        glVertex2f(55.0f, 100.0f); glVertex2f(55.0f, 103.0f);
    glEnd();

    /* 8. WHITE STATION SIGNBOARD (Hanging Style) */
    // Hanging Rods
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glColor3ub(50, 50, 50);
        glVertex2f(23.0f, 97.0f); glVertex2f(23.0f, 94.0f);
        glVertex2f(38.0f, 97.0f); glVertex2f(38.0f, 94.0f);
    glEnd();

    // Board Background
    glBegin(GL_QUADS);
        glColor3ub(250, 250, 250); // White
        glVertex2f(14.0f, 89.0f);  glVertex2f(47.0f, 89.0f);
        glVertex2f(47.0f, 94.0f);  glVertex2f(14.0f, 94.0f);

        // Fake Metro Logo on the board (Red & Green Blocks)
        glColor3ub(200, 30, 30); // Red part
        glVertex2f(15.5f, 90.0f);  glVertex2f(17.5f, 90.0f);
        glVertex2f(17.5f, 93.0f);  glVertex2f(15.5f, 93.0f);

        glColor3ub(0, 150, 70); // Green part
        glVertex2f(17.5f, 90.0f);  glVertex2f(19.5f, 90.0f);
        glVertex2f(19.5f, 93.0f);  glVertex2f(17.5f, 93.0f);
    glEnd();


    glColor3ub(0, 0, 0); // Black Text
    glRasterPos2f(21.0f, 90.5f); // Positioned next to the logo block
    const char* stationName = "MOTIJHEEL";
    for (int i = 0; stationName[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, stationName[i]);
    }

    //PlaySound("utt.wav", NULL,SND_ASYNC|SND_FILENAME);
}


/* ======================================================
                UTTARA UTTAR DAY BACKGROUND
   ====================================================== */
void bgUttara()
{
    // ---------------- SKY
    glBegin(GL_QUADS);
        glColor3ub(85, 175, 230);
        glVertex2f(0.0f, 140.0f);
        glVertex2f(200.0f, 140.0f);
        glColor3ub(205, 230, 240);
        glVertex2f(200.0f, 50.0f);
        glVertex2f(0.0f, 50.0f);
    glEnd();

    // ---------------- SUN
    glColor3ub(255, 245, 190);
    drawCircle(174.0f, 127.0f, 9.0f, 30);
    glColor3ub(255, 215, 90);
    drawCircle(174.0f, 127.0f, 6.0f, 30);

    // ---------- Building 1
    glColor3ub(215, 205, 190);
    drawRect(3.0f, 50.0f, 23.0f, 90.0f);
    glColor3ub(185, 180, 170);
    drawRect(2.0f, 89.0f, 24.0f, 92.0f);
    glColor3ub(70, 110, 135);
    drawRect(6, 56, 10, 61);
    drawRect(15, 56, 19, 61);
    drawRect(6, 66, 10, 71);
    drawRect(15, 66, 19, 71);
    drawRect(6, 76, 10, 81);
    drawRect(15, 76, 19, 81);

    // ---------- Building 2
    glColor3ub(185, 200, 210);
    drawRect(28.0f, 50.0f, 48.0f, 110.0f);
    glColor3ub(150, 165, 175);
    drawRect(27.0f, 108.0f, 49.0f, 112.0f);
    glColor3ub(160, 175, 185);
    drawRect(34.0f, 112.0f, 42.0f, 117.0f);
    glColor3ub(60, 100, 125);
    drawRect(31, 56, 35, 62);
    drawRect(40, 56, 44, 62);
    drawRect(31, 68, 35, 74);
    drawRect(40, 68, 44, 74);
    drawRect(31, 80, 35, 86);
    drawRect(40, 80, 44, 86);
    drawRect(31, 92, 35, 98);
    drawRect(40, 92, 44, 98);

    // ---------- Building 3
    glColor3ub(230, 220, 195);
    drawRect(54.0f, 50.0f, 76.0f, 84.0f);
    glColor3ub(200, 185, 165);
    drawRect(53.0f, 82.0f, 77.0f, 86.0f);
    glColor3ub(85, 115, 130);
    drawRect(58, 56, 62, 61);
    drawRect(68, 56, 72, 61);
    drawRect(58, 67, 62, 72);
    drawRect(68, 67, 72, 72);

    // ---------- Building 4
    glColor3ub(195, 190, 180);
    drawRect(82.0f, 50.0f, 108.0f, 103.0f);
    glColor3ub(160, 125, 110);
    drawRect(82.0f, 50.0f, 87.0f, 103.0f);
    glColor3ub(165, 160, 150);
    drawRect(81.0f, 101.0f, 109.0f, 105.0f);
    glColor3ub(55, 90, 115);
    drawRect(90, 57, 94, 63);
    drawRect(99, 57, 103, 63);
    drawRect(90, 69, 94, 75);
    drawRect(99, 69, 103, 75);
    drawRect(90, 81, 94, 87);
    drawRect(99, 81, 103, 87);
    drawRect(90, 93, 94, 99);
    drawRect(99, 93, 103, 99);

    // ---------- Building 5
    glColor3ub(205, 215, 220);
    drawRect(114.0f, 50.0f, 139.0f, 113.0f);
    glColor3ub(155, 170, 180);
    drawRect(113.0f, 110.0f, 140.0f, 114.0f);
    glColor3ub(100, 130, 140);
    drawRect(122.0f, 114.0f, 131.0f, 119.0f);
    glColor3ub(55, 100, 130);
    drawRect(118, 57, 123, 63);
    drawRect(130, 57, 135, 63);
    drawRect(118, 70, 123, 76);
    drawRect(130, 70, 135, 76);
    drawRect(118, 83, 123, 89);
    drawRect(130, 83, 135, 89);
    drawRect(118, 96, 123, 102);
    drawRect(130, 96, 135, 102);

    // ---------- Building 6
    glColor3ub(220, 200, 175);
    drawRect(145.0f, 50.0f, 165.0f, 89.0f);
    glColor3ub(185, 165, 145);
    drawRect(144.0f, 87.0f, 166.0f, 91.0f);
    glColor3ub(70, 105, 125);
    drawRect(149, 56, 153, 61);
    drawRect(158, 56, 162, 61);
    drawRect(149, 67, 153, 72);
    drawRect(158, 67, 162, 72);
    drawRect(149, 78, 153, 83);
    drawRect(158, 78, 162, 83);

    // ---------- Building 7
    glColor3ub(185, 200, 205);
    drawRect(172.0f, 50.0f, 198.0f, 104.0f);
    glColor3ub(145, 160, 170);
    drawRect(171.0f, 102.0f, 199.0f, 106.0f);
    glColor3ub(55, 95, 120);
    drawRect(176, 57, 181, 63);
    drawRect(188, 57, 193, 63);
    drawRect(176, 69, 181, 75);
    drawRect(188, 69, 193, 75);
    drawRect(176, 81, 181, 87);
    drawRect(188, 81, 193, 87);
    drawRect(176, 93, 181, 99);
    drawRect(188, 93, 193, 99);

    // ---------------- DISTANT GREEN BELT
    glColor3ub(70, 135, 65);
    drawRect(0, 50, 200, 54);
    glColor3ub(40, 100, 50);
    drawCircle(12, 55, 4, 20);
    drawCircle(25, 54, 3, 20);
    drawCircle(52, 55, 4, 20);
    drawCircle(72, 54, 3, 20);
    drawCircle(105, 55, 4, 20);
    drawCircle(143, 54, 3, 20);
    drawCircle(168, 55, 4, 20);
    drawCircle(190, 54, 3, 20);
}

/* ======================================================
                UTTARA UTTAR NIGHT BACKGROUND
   ====================================================== */
void bgNightUttara()
{
    // ---------------- NIGHT SKY
    glBegin(GL_QUADS);
        glColor3ub(5, 15, 45);
        glVertex2f(0.0f, 140.0f);
        glVertex2f(200.0f, 140.0f);
        glColor3ub(32, 52, 78);
        glVertex2f(200.0f, 50.0f);
        glVertex2f(0.0f, 50.0f);
    glEnd();

    // ---------------- MOON
    drawMoon(174.0f, 127.0f, 7.0f);

    // ---------- Building 1
    glColor3ub(65, 62, 60);
    drawRect(3.0f, 50.0f, 23.0f, 90.0f);
    glColor3ub(45, 45, 45);
    drawRect(2.0f, 89.0f, 24.0f, 92.0f);
    glColor3ub(255, 210, 100);
    drawRect(6, 56, 10, 61);
    drawRect(15, 66, 19, 71);
    drawRect(6, 76, 10, 81);
    glColor3ub(20, 28, 38);
    drawRect(15, 56, 19, 61);
    drawRect(6, 66, 10, 71);
    drawRect(15, 76, 19, 81);

    // ---------- Building 2
    glColor3ub(52, 60, 68);
    drawRect(28.0f, 50.0f, 48.0f, 110.0f);
    glColor3ub(38, 44, 50);
    drawRect(27.0f, 108.0f, 49.0f, 112.0f);
    glColor3ub(45, 52, 58);
    drawRect(34.0f, 112.0f, 42.0f, 117.0f);
    glColor3ub(255, 215, 120);
    drawRect(31, 56, 35, 62);
    drawRect(40, 68, 44, 74);
    drawRect(31, 80, 35, 86);
    drawRect(40, 92, 44, 98);
    glColor3ub(15, 25, 35);
    drawRect(40, 56, 44, 62);
    drawRect(31, 68, 35, 74);
    drawRect(40, 80, 44, 86);
    drawRect(31, 92, 35, 98);

    // ---------- Building 3
    glColor3ub(70, 65, 55);
    drawRect(54.0f, 50.0f, 76.0f, 84.0f);
    glColor3ub(48, 45, 40);
    drawRect(53.0f, 82.0f, 77.0f, 86.0f);
    glColor3ub(255, 195, 90);
    drawRect(58, 56, 62, 61);
    drawRect(68, 67, 72, 72);
    glColor3ub(20, 27, 35);
    drawRect(68, 56, 72, 61);
    drawRect(58, 67, 62, 72);

    // ---------- Building 4
    glColor3ub(58, 55, 55);
    drawRect(82.0f, 50.0f, 108.0f, 103.0f);
    glColor3ub(55, 38, 35);
    drawRect(82.0f, 50.0f, 87.0f, 103.0f);
    glColor3ub(40, 40, 40);
    drawRect(81.0f, 101.0f, 109.0f, 105.0f);
    glColor3ub(255, 220, 120);
    drawRect(90, 57, 94, 63);
    drawRect(99, 69, 103, 75);
    drawRect(90, 81, 94, 87);
    drawRect(99, 93, 103, 99);
    glColor3ub(15, 23, 32);
    drawRect(99, 57, 103, 63);
    drawRect(90, 69, 94, 75);
    drawRect(99, 81, 103, 87);
    drawRect(90, 93, 94, 99);

    // ---------- Building 5
    glColor3ub(50, 60, 66);
    drawRect(114.0f, 50.0f, 139.0f, 113.0f);
    glColor3ub(38, 45, 50);
    drawRect(113.0f, 110.0f, 140.0f, 114.0f);
    glColor3ub(45, 58, 65);
    drawRect(122.0f, 114.0f, 131.0f, 119.0f);
    glColor3ub(255, 205, 100);
    drawRect(118, 57, 123, 63);
    drawRect(130, 70, 135, 76);
    drawRect(118, 83, 123, 89);
    drawRect(130, 96, 135, 102);
    glColor3ub(14, 24, 34);
    drawRect(130, 57, 135, 63);
    drawRect(118, 70, 123, 76);
    drawRect(130, 83, 135, 89);
    drawRect(118, 96, 123, 102);

    // ---------- Building 6
    glColor3ub(65, 57, 48);
    drawRect(145.0f, 50.0f, 165.0f, 89.0f);
    glColor3ub(45, 40, 35);
    drawRect(144.0f, 87.0f, 166.0f, 91.0f);
    glColor3ub(255, 215, 110);
    drawRect(149, 56, 153, 61);
    drawRect(158, 67, 162, 72);
    drawRect(149, 78, 153, 83);
    glColor3ub(18, 25, 32);
    drawRect(158, 56, 162, 61);
    drawRect(149, 67, 153, 72);
    drawRect(158, 78, 162, 83);

    // ---------- Building 7
    glColor3ub(50, 58, 63);
    drawRect(172.0f, 50.0f, 198.0f, 104.0f);
    glColor3ub(38, 44, 48);
    drawRect(171.0f, 102.0f, 199.0f, 106.0f);
    glColor3ub(255, 205, 100);
    drawRect(176, 57, 181, 63);
    drawRect(188, 69, 193, 75);
    drawRect(176, 81, 181, 87);
    drawRect(188, 93, 193, 99);
    glColor3ub(15, 24, 32);
    drawRect(188, 57, 193, 63);
    drawRect(176, 69, 181, 75);
    drawRect(188, 81, 193, 87);
    drawRect(176, 93, 181, 99);

    // ---------- DARK GREEN BELT
    glColor3ub(25, 65, 38);
    drawRect(0, 50, 200, 54);
    glColor3ub(15, 45, 28);
    drawCircle(12, 55, 4, 20);
    drawCircle(25, 54, 3, 20);
    drawCircle(52, 55, 4, 20);
    drawCircle(72, 54, 3, 20);
    drawCircle(105, 55, 4, 20);
    drawCircle(143, 54, 3, 20);
    drawCircle(168, 55, 4, 20);
    drawCircle(190, 54, 3, 20);
}

void stationUttara()
{
    /* =========================================
       DHAKA METRO STATION STYLE (Uttara Uttar)
       ========================================= */

    /* 1. MAIN BRICK WALL */
    glBegin(GL_QUADS);
        glColor3ub(165, 75, 55);
        glVertex2f(0.0f, 71.0f);
        glVertex2f(55.0f, 71.0f);
        glVertex2f(55.0f, 95.0f);
        glVertex2f(0.0f, 95.0f);
    glEnd();

    /* 2. HORIZONTAL LOUVERS */
    glBegin(GL_QUADS);
        glColor3ub(50, 60, 70);
        glVertex2f(0.0f, 74.0f); glVertex2f(55.0f, 74.0f);
        glVertex2f(55.0f, 77.0f); glVertex2f(0.0f, 77.0f);
        glVertex2f(0.0f, 81.0f); glVertex2f(55.0f, 81.0f);
        glVertex2f(55.0f, 84.0f); glVertex2f(0.0f, 84.0f);
        glVertex2f(0.0f, 88.0f); glVertex2f(55.0f, 88.0f);
        glVertex2f(55.0f, 91.0f); glVertex2f(0.0f, 91.0f);
    glEnd();

    /* 3. VERTICAL PILLARS */
    glBegin(GL_QUADS);
        glColor3ub(170, 175, 180);
        glVertex2f(0.0f, 50.0f);  glVertex2f(4.0f, 50.0f);
        glVertex2f(4.0f, 97.0f);  glVertex2f(0.0f, 97.0f);
        glVertex2f(17.0f, 50.0f); glVertex2f(21.0f, 50.0f);
        glVertex2f(21.0f, 97.0f); glVertex2f(17.0f, 97.0f);
        glVertex2f(34.0f, 50.0f); glVertex2f(38.0f, 50.0f);
        glVertex2f(38.0f, 97.0f); glVertex2f(34.0f, 97.0f);
        glVertex2f(51.0f, 50.0f); glVertex2f(55.0f, 50.0f);
        glVertex2f(55.0f, 97.0f); glVertex2f(51.0f, 97.0f);
    glEnd();

    /* 4. TOP BEAM */
    glBegin(GL_QUADS);
        glColor3ub(190, 195, 200);
        glVertex2f(0.0f, 95.0f);  glVertex2f(55.0f, 95.0f);
        glVertex2f(55.0f, 97.0f); glVertex2f(0.0f, 97.0f);
    glEnd();

    /* 5. ELEVATED TRACK */
    glBegin(GL_QUADS);
        glColor3ub(150, 150, 155);
        glVertex2f(0.0f, 50.0f);   glVertex2f(55.0f, 50.0f);
        glVertex2f(55.0f, 69.0f);  glVertex2f(0.0f, 69.0f);
        glColor3ub(130, 130, 135);
        glVertex2f(0.0f, 69.0f);   glVertex2f(55.0f, 69.0f);
        glVertex2f(55.0f, 71.0f);  glVertex2f(0.0f, 71.0f);
    glEnd();

    /* 6. STEEL TRUSS */
    glLineWidth(2.5f);
    glBegin(GL_LINES);
        glColor3ub(130, 135, 140);
        glVertex2f(2.0f, 97.0f);   glVertex2f(8.5f, 104.0f);
        glVertex2f(15.0f, 97.0f);  glVertex2f(8.5f, 104.0f);
        glVertex2f(8.5f, 97.0f);   glVertex2f(8.5f, 104.0f);
        glVertex2f(19.0f, 97.0f);  glVertex2f(25.5f, 106.5f);
        glVertex2f(32.0f, 97.0f);  glVertex2f(25.5f, 106.5f);
        glVertex2f(25.5f, 97.0f);  glVertex2f(25.5f, 106.5f);
        glVertex2f(36.0f, 97.0f);  glVertex2f(42.5f, 106.5f);
        glVertex2f(49.0f, 97.0f);  glVertex2f(42.5f, 106.5f);
        glVertex2f(42.5f, 97.0f);  glVertex2f(42.5f, 106.5f);
    glEnd();

    /* 7. GREEN ROOF */
    glBegin(GL_QUAD_STRIP);
        glColor3ub(35, 120, 65);
        glVertex2f(0.0f, 100.0f);  glVertex2f(0.0f, 103.0f);
        glVertex2f(15.0f, 105.0f); glVertex2f(15.0f, 108.0f);
        glVertex2f(27.5f, 107.0f); glVertex2f(27.5f, 110.0f);
        glVertex2f(40.0f, 105.0f); glVertex2f(40.0f, 108.0f);
        glVertex2f(55.0f, 100.0f); glVertex2f(55.0f, 103.0f);
    glEnd();

    /* 8. STATION SIGNBOARD */
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glColor3ub(50, 50, 50);
        glVertex2f(23.0f, 97.0f); glVertex2f(23.0f, 94.0f);
        glVertex2f(38.0f, 97.0f); glVertex2f(38.0f, 94.0f);
    glEnd();

    glBegin(GL_QUADS);
        glColor3ub(250, 250, 250);
        glVertex2f(14.0f, 89.0f);  glVertex2f(47.0f, 89.0f);
        glVertex2f(47.0f, 94.0f);  glVertex2f(14.0f, 94.0f);

        glColor3ub(200, 30, 30);
        glVertex2f(15.5f, 90.0f);  glVertex2f(17.5f, 90.0f);
        glVertex2f(17.5f, 93.0f);  glVertex2f(15.5f, 93.0f);

        glColor3ub(0, 150, 70);
        glVertex2f(17.5f, 90.0f);  glVertex2f(19.5f, 90.0f);
        glVertex2f(19.5f, 93.0f);  glVertex2f(17.5f, 93.0f);
    glEnd();

    glColor3ub(0, 0, 0);
    glRasterPos2f(21.0f, 90.5f);
    const char* stationName = "UTTARA UTTAR";
    for (int i = 0; stationName[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, stationName[i]);
    }
    //PlaySound("moti.wav", NULL,SND_ASYNC|SND_FILENAME);
}
void pilar()
{

    glBegin(GL_QUADS);
    glColor3ub(200,200,150);
    glVertex2d(160,25);
    glVertex2d(175,25);
    glVertex2d(177,52);
    glVertex2d(158,52);

    glVertex2d(150,60);
    glVertex2d(158,52);
    glVertex2d(177,52);
    glVertex2d(185,60);

    glVertex2d(150,65);
    glVertex2d(150,60);
    glVertex2d(185,60);
    glVertex2d(185,65);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(103,93,40);
    glVertex2d(177,52);
    glVertex2d(164,52);

    glVertex2d(185,60);
    glVertex2d(158,60);
    glEnd();

}

void metrorail()
{

    //Main Body
    glBegin(GL_QUADS);
        glColor3ub(245, 245, 242);
        glVertex2f(90.0f, 71.0f);
        glVertex2f(160.0f, 71.0f);
        glVertex2f(160.0f, 95.0f);
        glVertex2f(90.0f, 95.0f);
    glEnd();

    //front
    glBegin(GL_POLYGON);
        glColor3ub(245, 245, 242);
        glVertex2f(160.0f, 71.0f);
        glVertex2f(168.0f, 71.0f);
        glVertex2f(170.0f, 78.0f);
        glVertex2f(168.0f, 92.0f);
        glVertex2f(160.0f, 95.0f);
    glEnd();

    //Green Top
    glBegin(GL_QUADS);
        glColor3ub(0, 150, 120);
        glVertex2f(90.0f, 91.0f);  glVertex2f(162.0f, 91.0f);
        glVertex2f(160.0f, 95.0f); glVertex2f(90.0f, 95.0f);
    glEnd();

    //Red Lower
    glBegin(GL_QUADS);
        glColor3ub(220, 35, 45);
        glVertex2f(90.0f, 72.0f);  glVertex2f(167.0f, 72.0f);
        glVertex2f(168.0f, 75.0f); glVertex2f(90.0f, 75.0f);
    glEnd();

    //Doors - Unrolled for efficiency (No loops needed)
    glBegin(GL_QUADS);
        glColor3ub(180, 35, 40); // Red door frame

        // Door 1
        glVertex2f(93.0f, 75.0f);
        glVertex2f(97.0f, 75.0f);
        glVertex2f(97.0f, 89.0f);
        glVertex2f(93.0f, 89.0f);
        // Door 2
        glVertex2f(104.0f, 75.0f);
        glVertex2f(108.0f, 75.0f);
        glVertex2f(108.0f, 89.0f);
        glVertex2f(104.0f, 89.0f);
        // Door 3
        glVertex2f(115.0f, 75.0f);
        glVertex2f(119.0f, 75.0f);
        glVertex2f(119.0f, 89.0f);
        glVertex2f(115.0f, 89.0f);
        // Door 4
        glVertex2f(126.0f, 75.0f);
        glVertex2f(130.0f, 75.0f);
        glVertex2f(130.0f, 89.0f);
        glVertex2f(126.0f, 89.0f);
        // Door 5
        glVertex2f(137.0f, 75.0f);
        glVertex2f(141.0f, 75.0f);
        glVertex2f(141.0f, 89.0f);
        glVertex2f(137.0f, 89.0f);
        // Door 6
        glVertex2f(148.0f, 75.0f);
        glVertex2f(152.0f, 75.0f);
        glVertex2f(152.0f, 89.0f);
        glVertex2f(148.0f, 89.0f);
    glEnd();

    //Windows
    glBegin(GL_QUADS);
        glColor3ub(30, 45, 50); // Dark glass

        // Window 1
        glVertex2f(98.0f, 80.0f);
        glVertex2f(103.0f, 80.0f);
        glVertex2f(103.0f, 89.0f);
        glVertex2f(98.0f, 89.0f);
        // Window 2
        glVertex2f(109.0f, 80.0f);
        glVertex2f(114.0f, 80.0f);
        glVertex2f(114.0f, 89.0f);
        glVertex2f(109.0f, 89.0f);
        // Window 3
        glVertex2f(120.0f, 80.0f);
        glVertex2f(125.0f, 80.0f);
        glVertex2f(125.0f, 89.0f);
        glVertex2f(120.0f, 89.0f);
        // Window 4
        glVertex2f(131.0f, 80.0f);
        glVertex2f(136.0f, 80.0f);
        glVertex2f(136.0f, 89.0f);
        glVertex2f(131.0f, 89.0f);
        // Window 5
        glVertex2f(142.0f, 80.0f);
        glVertex2f(147.0f, 80.0f);
        glVertex2f(147.0f, 89.0f);
        glVertex2f(142.0f, 89.0f);
        // Window 6
        glVertex2f(153.0f, 80.0f);
        glVertex2f(158.0f, 80.0f);
        glVertex2f(158.0f, 89.0f);
        glVertex2f(153.0f, 89.0f);
    glEnd();

    // Front Windshield
    glBegin(GL_POLYGON);
        glColor3ub(30, 45, 50);
        glVertex2f(162.0f, 80.0f);
        glVertex2f(167.0f, 80.0f);
        glVertex2f(165.0f, 89.0f);
        glVertex2f(162.0f, 89.0f);
    glEnd();

    // Pair 1
    drawCircle(97.0f, 72.0f, 2.0f, 20);
    drawCircle(104.0f, 72.0f, 2.0f, 20);

    // Pair 2
    drawCircle(114.0f, 72.0f, 2.0f, 20);
    drawCircle(121.0f, 72.0f, 2.0f, 20);

    // Pair 3
    drawCircle(132.0f, 72.0f, 2.0f, 20);
    drawCircle(139.0f, 72.0f, 2.0f, 20);

    // Pair 4
    drawCircle(149.0f, 72.0f, 2.0f, 20);
    drawCircle(156.0f, 72.0f, 2.0f, 20);

}
void car()
{
    glBegin(GL_QUADS);
    glColor3ub(255,10,0);
    glVertex2d(15,45);
    glVertex2d(10,40);
    glVertex2d(25,40);
    glVertex2d(20,45);

    glColor3ub(255,100,10);
    glVertex2d(4,40);
    glVertex2d(4,31);
    glVertex2d(30,31);
    glVertex2d(30,40);


    glColor3ub(100,100,255);
    glVertex2d(16,44);
    glVertex2d(12,41);
    glVertex2d(23,41);
    glVertex2d(19,44);

    glEnd();
    glColor3f(0,0,0);
    drawCircle(10,31,2,20);
    drawCircle(25,31,2,20);
}
void drawCloud(float cx, float cy, float scale)
{
    glColor3f(0.94f, 0.98f, 0.97f);
    drawCircle(cx,            cy,        0.18f * scale, 24);
    drawCircle(cx + 0.18f*scale, cy + 0.05f*scale, 0.14f * scale, 24);
    drawCircle(cx - 0.16f*scale, cy + 0.03f*scale, 0.13f * scale, 24);
}

void drawCloudRain(float cx, float cy, float scale)
{
    glColor3f(0.35f, 0.37f, 0.40f);
    drawCircle(cx,            cy,        0.18f * scale, 24);
    drawCircle(cx + 0.18f*scale, cy + 0.05f*scale, 0.14f * scale, 24);
    drawCircle(cx - 0.16f*scale, cy + 0.03f*scale, 0.13f * scale, 24);
}

void drawTree(float x, float y, float scale)
{
    glColor3f(0.36f, 0.24f, 0.14f);
    drawRect(x - 0.03f*scale, y - 0.35f*scale, x + 0.03f*scale, y);

    glColor3f(0.12f, 0.40f, 0.22f);
    drawCircle(x, y + 0.18f*scale, 0.24f*scale, 24);
    glColor3f(0.08f, 0.32f, 0.18f);
    drawCircle(x - 0.16f*scale, y + 0.08f*scale, 0.18f*scale, 24);
    drawCircle(x + 0.16f*scale, y + 0.08f*scale, 0.18f*scale, 24);
    glColor3f(0.16f, 0.46f, 0.26f);
    drawCircle(x, y + 0.34f*scale, 0.16f*scale, 24);
}

void drawTrees()
{
    drawTree(20, -1.15f, 30);
    drawTree(40, -1.15f, 35);
    drawTree(80, -1.15f, 40);
    drawTree(120, -1.15f, 30);
    drawTree(140, -1.15f, 40);
    drawTree(160, -1.15f, 35);
    drawTree(190, -1.15f, 30);

    drawTree(40, 37, 35);
    drawTree(80, 38, 40);
    drawTree(140, 38, 40);
    drawTree(160, 37, 35);
}

void update(int value)
{
    carOffset1 += 0.8f;
    if (carOffset1 > 200.0f) carOffset1 = -30.0f;

    carOffset2 -= 0.8f;
    if (carOffset2 < -200.0f) carOffset2 = 30.0f;

    trainOffset += 0.25f;
    if (trainOffset > 120.0f) {
        trainOffset = -60.0f;
        stationIndex = !stationIndex;
         if (stationIndex == 0)
        PlaySound("utt.wav", NULL, SND_ASYNC | SND_FILENAME);
    else
        PlaySound("moti.wav", NULL, SND_ASYNC | SND_FILENAME);
    }

    cloudOffset1 += 0.15f;
    if (cloudOffset1 > 60.0f) cloudOffset1 = -60.0f;

    cloudOffset2 -= 0.15f;
    if (cloudOffset2 < -60.0f) cloudOffset2 = 60.0f;

    if (isRain) {                                    // <-- add
        for (int i = 0; i < NUM_DROPS; i++) {
            rainY[i] -= 3.0f;
            if (rainY[i] < -4.0f) {
                rainY[i] = 140.0f;
                rainX[i] = (float)(rand() % 200);
            }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

void display() {
    //glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0,200,-4,140);
                                                      //ROAD STARTS
    glBegin(GL_QUADS);
    glColor3ub(80,80,100);
    glVertex2d(0,0);
    glVertex2d(200,0);
    glVertex2d(200,50);
    glVertex2d(0,50);

    glColor3ub(65,152,10);
    glVertex2d(0,22);
    glVertex2d(200,22);
    glVertex2d(200,28);
    glVertex2d(0,28);
    glEnd();
                                                     //ROAD ENDS
                                                    //ROAD DEVIDER STARTS
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2d(20,39);
    glVertex2d(35,39);
    glVertex2d(35,41);
    glVertex2d(20,41);

    glVertex2d(50,39);
    glVertex2d(65,39);
    glVertex2d(65,41);
    glVertex2d(50,41);

    glVertex2d(80,39);
    glVertex2d(95,39);
    glVertex2d(95,41);
    glVertex2d(80,41);

    glVertex2d(110,39);
    glVertex2d(125,39);
    glVertex2d(125,41);
    glVertex2d(110,41);

    glVertex2d(140,39);
    glVertex2d(155,39);
    glVertex2d(155,41);
    glVertex2d(140,41);

    glVertex2d(170,39);
    glVertex2d(185,39);
    glVertex2d(185,41);
    glVertex2d(170,41);
    glEnd();

    glPushMatrix();
    glTranslatef(0,-29,0);

    glBegin(GL_QUADS);

    glVertex2d(20,39);
    glVertex2d(35,39);
    glVertex2d(35,41);
    glVertex2d(20,41);

    glVertex2d(50,39);
    glVertex2d(65,39);
    glVertex2d(65,41);
    glVertex2d(50,41);

    glVertex2d(80,39);
    glVertex2d(95,39);
    glVertex2d(95,41);
    glVertex2d(80,41);

    glVertex2d(110,39);
    glVertex2d(125,39);
    glVertex2d(125,41);
    glVertex2d(110,41);

    glVertex2d(140,39);
    glVertex2d(155,39);
    glVertex2d(155,41);
    glVertex2d(140,41);

    glVertex2d(170,39);
    glVertex2d(185,39);
    glVertex2d(185,41);
    glVertex2d(170,41);

    glEnd();
    glPopMatrix();
    //glLoadIdentity();


                                                        //----------------------CARS

       glPushMatrix();
    glTranslated(carOffset1, 0, 0);
    car();
    glPopMatrix();

    glPushMatrix();
    glTranslated(120 + carOffset2, -29, 0);  ;
    car();
    glPopMatrix();
                                                    //-------------------------END of cars calling

        if (stationIndex == 0)
            bg();
        else bgUttara();          //Background function calling


                                                    //------------------------------------------Pilars
        pilar();
        glPushMatrix();
        glTranslated(-70,0,0);
        pilar();
        glPopMatrix();

        /*pilar();
        glPushMatrix();
        glTranslated(-140,0,0);
        pilar();
        glPopMatrix();
*/
        glBegin(GL_QUADS);
        glColor3ub(200,200,150);
        glVertex2d(0,65);
        glVertex2d(200,65);
        glVertex2d(200,70);
        glVertex2d(0,70);
        glEnd();
                                                    //--------------------------------End of pilars

        glPushMatrix();
    glTranslatef(trainOffset, 17, 0);
    glScalef(0.7f, 0.75f, 1.0f);
    metrorail();
        glPopMatrix();                               //-----------------metro

        if (stationIndex == 0)
            stationa();
        else stationUttara();          //station function calling


    if (isRain) {
        drawCloudRain(60 + cloudOffset1, 120, 30);
        drawCloudRain(100 + cloudOffset1, 120, 40);
        drawCloudRain(130 + cloudOffset2, 130, 40);
        drawCloudRain(40 + cloudOffset2, 115, 40);
        drawCloudRain(180 + cloudOffset1, 115, 40);
    }
    else {
        drawCloud(60 + cloudOffset1, 120, 30);
        drawCloud(100 + cloudOffset1, 120, 40);
        drawCloud(130 + cloudOffset2, 130, 40);
        drawCloud(40 + cloudOffset2, 115, 40);
        drawCloud(180 + cloudOffset1, 115, 40);
    }

    drawTrees();

    if (isRain) drawRain();
    glLoadIdentity();
    glFlush();

    drawTrees();                                            //------------Trees



        glLoadIdentity();
        glFlush();
}

void displayNight() {
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0,200,-4,140);

    glBegin(GL_QUADS);
    glColor3ub(80,80,100);
    glVertex2d(0,0);
    glVertex2d(200,0);
    glVertex2d(200,50);
    glVertex2d(0,50);

    glColor3ub(65,152,10);
    glVertex2d(0,22);
    glVertex2d(200,22);
    glVertex2d(200,28);
    glVertex2d(0,28);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2d(20,39); glVertex2d(35,39); glVertex2d(35,41); glVertex2d(20,41);
    glVertex2d(50,39); glVertex2d(65,39); glVertex2d(65,41); glVertex2d(50,41);
    glVertex2d(80,39); glVertex2d(95,39); glVertex2d(95,41); glVertex2d(80,41);
    glVertex2d(110,39); glVertex2d(125,39); glVertex2d(125,41); glVertex2d(110,41);
    glVertex2d(140,39); glVertex2d(155,39); glVertex2d(155,41); glVertex2d(140,41);
    glVertex2d(170,39); glVertex2d(185,39); glVertex2d(185,41); glVertex2d(170,41);
    glEnd();

    glPushMatrix();
    glTranslatef(0,-29,0);
    glBegin(GL_QUADS);
    glVertex2d(20,39); glVertex2d(35,39); glVertex2d(35,41); glVertex2d(20,41);
    glVertex2d(50,39); glVertex2d(65,39); glVertex2d(65,41); glVertex2d(50,41);
    glVertex2d(80,39); glVertex2d(95,39); glVertex2d(95,41); glVertex2d(80,41);
    glVertex2d(110,39); glVertex2d(125,39); glVertex2d(125,41); glVertex2d(110,41);
    glVertex2d(140,39); glVertex2d(155,39); glVertex2d(155,41); glVertex2d(140,41);
    glVertex2d(170,39); glVertex2d(185,39); glVertex2d(185,41); glVertex2d(170,41);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(carOffset1, 0, 0);
    car();
    glPopMatrix();

    glPushMatrix();
    glTranslated(120 + carOffset2, -29, 0);
    car();
    glPopMatrix();

    if (stationIndex == 0) bgNight(); else bgNightUttara();

    pilar();
    glPushMatrix();
    glTranslated(-70,0,0);
    pilar();
    glPopMatrix();

    glBegin(GL_QUADS);
    glColor3ub(200,200,150);
    glVertex2d(0,65); glVertex2d(200,65); glVertex2d(200,70); glVertex2d(0,70);
    glEnd();

    glPushMatrix();
    glTranslatef(trainOffset, 17, 0);
    glScalef(0.7f, 0.75f, 1.0f);
    metrorail();
    glPopMatrix();

    if (stationIndex == 0) stationa(); else stationUttara();

        if (isRain) {
        drawCloudRain(60 + cloudOffset1, 120, 30);
        drawCloudRain(100 + cloudOffset1, 120, 40);
        drawCloudRain(130 + cloudOffset2, 130, 40);
        drawCloudRain(40 + cloudOffset2, 115, 40);
        drawCloudRain(180 + cloudOffset1, 115, 40);
    } else {
        drawCloud(60 + cloudOffset1, 120, 30);
        drawCloud(100 + cloudOffset1, 120, 40);
        drawCloud(130 + cloudOffset2, 130, 40);
        drawCloud(40 + cloudOffset2, 115, 40);
        drawCloud(180 + cloudOffset1, 115, 40);
    }

    drawTrees();

    if (isRain) {
        drawRain();
    }
    glLoadIdentity();
    glFlush();

    drawTrees();


    glLoadIdentity();

    glFlush();
}

void renderScene()
{
    if (isNight)
        displayNight();
    else
        display();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Metro Era");
    glutInitWindowSize(1000, 700);
    glutInitWindowPosition(50, 50);
    initGL();
	glutDisplayFunc(display);
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, update, 0);
    cout<<"Welcome to Metro Era."<<endl;
    cout<<"Press D for Day Scene"<<endl<<"Press N for Night Scene"<<endl<<"Press R for Rainy Scene";
    glutMainLoop();

	return 0;
}
