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
    glColor3f(0,0,0);
    glVertex2f(cx, cy);
    for (int i = 0; i <= segments; i++) {
        float theta = 2.0f * 3.14159265f * i / segments;
        glVertex2f(cx + r * cosf(theta), cy + r * 0.6f * sinf(theta));
    }
    glEnd();
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
                                                    //--------------------------------End of pilars


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
