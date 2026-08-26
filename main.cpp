#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

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

void bg()
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

void station()
{

    glBegin(GL_QUADS);
        glColor3ub(160, 200, 215); // Light Glass Blue
        glVertex2f(0.0f, 71.0f);
        glVertex2f(55.0f, 71.0f);
        glVertex2f(55.0f, 100.0f);
        glVertex2f(0.0f, 100.0f);

        // Glass Reflection (Diagonal bright stripe)
        glColor3ub(190, 220, 230);
        glVertex2f(10.0f, 71.0f);
        glVertex2f(20.0f, 71.0f);
        glVertex2f(40.0f, 100.0f);
        glVertex2f(30.0f, 100.0f);
    glEnd();

    /* 2. STATION PLATFORM BASE */
    glBegin(GL_QUADS);
        glColor3ub(110, 110, 110); // Dark Concrete
        glVertex2f(0.0f, 50.0f);
        glVertex2f(55.0f, 50.0f);
        glVertex2f(55.0f, 69.0f);
        glVertex2f(0.0f, 69.0f);

        // Yellow safety line at the edge of the platform
        glColor3ub(230, 200, 0);
        glVertex2f(0.0f, 69.0f);
        glVertex2f(55.0f, 69.0f);
        glVertex2f(55.0f, 71.0f);
        glVertex2f(0.0f, 71.0f);
    glEnd();

    /* 3. ROOF SUPPORT PILLARS */
    glBegin(GL_QUADS);
        glColor3ub(140, 140, 150); // Steel Pillars

        // Pillar 1
        glVertex2f(5.0f, 71.0f);  glVertex2f(9.0f, 71.0f);
        glVertex2f(9.0f, 100.0f); glVertex2f(5.0f, 100.0f);

        // Pillar 2
        glVertex2f(25.0f, 71.0f);  glVertex2f(29.0f, 71.0f);
        glVertex2f(29.0f, 100.0f); glVertex2f(25.0f, 100.0f);

        // Pillar 3
        glVertex2f(45.0f, 71.0f);  glVertex2f(49.0f, 71.0f);
        glVertex2f(49.0f, 100.0f); glVertex2f(45.0f, 100.0f);
    glEnd();

    /* 4. STATION ROOF */
    glBegin(GL_QUADS);
        glColor3ub(200, 210, 220); // Main roof color
        glVertex2f(0.0f, 100.0f);  glVertex2f(55.0f, 100.0f);
        glVertex2f(55.0f, 107.0f); glVertex2f(0.0f, 107.0f);

        // Roof Accent (Green Dhaka Metro Motif)
        glColor3ub(0, 150, 120);
        glVertex2f(0.0f, 107.0f);  glVertex2f(55.0f, 107.0f);
        glVertex2f(55.0f, 110.0f); glVertex2f(0.0f, 110.0f);
    glEnd();

    /* 5. STATION SIGNBOARD */
    // Hanging Rods for the board
    glLineWidth(2.0f);
    glBegin(GL_LINES);
        glColor3ub(50, 50, 50);
        glVertex2f(20.0f, 100.0f); glVertex2f(20.0f, 96.0f);
        glVertex2f(35.0f, 100.0f); glVertex2f(35.0f, 96.0f);
    glEnd();

    // The Green Board
    glBegin(GL_QUADS);
        glColor3ub(30, 120, 50); // Dark Green
        glVertex2f(15.0f, 90.0f);  glVertex2f(40.0f, 90.0f);
        glVertex2f(40.0f, 96.0f);  glVertex2f(15.0f, 96.0f);
    glEnd();

    // Text: "MOTIJHEEL"
    glColor3ub(255, 255, 255); // White Text
    glRasterPos2f(18.5f, 91.5f); // Position perfectly inside the green board
    const char* stationName = "MOTIJHEEL";
    for (int i = 0; stationName[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, stationName[i]);
    }
}

void stationa()
{
/* =========================================
       DHAKA METRO STATION STYLE (Motijheel)
       Range: X from 0 to 55, Y from 50 to 110
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

    // Text: "MOTIJHEEL"
    glColor3ub(0, 0, 0); // Black Text
    glRasterPos2f(21.0f, 90.5f); // Positioned next to the logo block
    const char* stationName = "MOTIJHEEL";
    for (int i = 0; stationName[i] != '\0'; i++) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, stationName[i]);
    }
}

void pilar()
{
    glBegin(GL_QUADS);
    glColor3ub(200,200,150);
    glVertex2d(160,25);
    glVertex2d(180,25);
    glVertex2d(182,52);
    glVertex2d(158,52);

    glVertex2d(150,60);
    glVertex2d(158,52);
    glVertex2d(182,52);
    glVertex2d(190,60);

    glVertex2d(150,65);
    glVertex2d(150,60);
    glVertex2d(190,60);
    glVertex2d(190,65);

    glEnd();

    glBegin(GL_LINES);
    glColor3ub(103,93,40);
    glVertex2d(182,52);
    glVertex2d(164,52);

    glVertex2d(190,60);
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



void display() {
    //glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(0,200,0,140);
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

        car();
        glPushMatrix();
        glTranslated(120,-29,0);
        car();
        glPopMatrix();
                                                    //-------------------------END of cars calling

        bg();                                      //Background function calling

        stationa();                                  //station function calling
                                                    //------------------------------------------Pilars
        pilar();
        glPushMatrix();
        glTranslated(-70,0,0);
        pilar();
        glPopMatrix();

        pilar();
        glPushMatrix();
        glTranslated(-140,0,0);
        pilar();
        glPopMatrix();

        glBegin(GL_QUADS);
        glColor3ub(200,200,150);
        glVertex2d(0,65);
        glVertex2d(200,65);
        glVertex2d(200,70);
        glVertex2d(0,70);
        glEnd();
                                                    //--------------------------------End of pilars

        metrorail();


        glLoadIdentity();
        glFlush();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Metro Era");
    glutInitWindowSize(1000, 700);
    glutInitWindowPosition(50, 50);
    initGL();
	glutDisplayFunc(display);

	glutMainLoop();
	return 0;
}
