#include <GL/glut.h>

void drawLimitLines() {
    glLineWidth(6.0f);
    glColor3f(0.5, 1, 0);

    glBegin(GL_LINES);
        glVertex2f(0, -1);
        glVertex2f(0, 1);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(-1, 0);
        glVertex2f(1, 0);
    glEnd();
}

void drawTriangle() {
    glLineWidth(4.0f);
    glColor3f(1, 0, 0);
    
    glBegin(GL_LINE_LOOP);
        glVertex2f(0, 0);
        glVertex2f(1, 0);
        glVertex2f(0.5, 1);
    glEnd();
}

void display() {
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glShadeModel(GL_FLAT);
    drawLimitLines();
    drawTriangle();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(256, 256);

    glutCreateWindow("ATV03/Q1/C/B - Cartesiano - Manuel Carlos");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}