#include <GL/glut.h>

void display() {
    glClearColor(1, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_FLAT);

    glBegin(GL_POLYGON);

    glVertex2f(0.0, 1.0);
    glVertex2f(-1.0, 0.0);
    glColor3f(1, 1, 1);
    glVertex2f(1.0, 0.0);

    glEnd();

    glShadeModel(GL_SMOOTH);
    glBegin(GL_POLYGON);

    glColor3f(0, 0, 1);
    glVertex2f(0.0, -1.0);
    glColor3f(1, 1, 1);
    glVertex2f(-1.0, 0.0);
    glColor3f(1, 1, 1);
    glVertex2f(1.0, 0.0);

    glEnd();

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(256, 256);

    glutCreateWindow("ATV03/Q1/A - Quadrado - Manuel Carlos");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}