#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_FLAT);
    glBegin(GL_POLYGON);

    glColor3f(2.0, 2.0, 2.0);
    glVertex3f(-0.5, -0.5, 0.0);

    glColor3f(2.0, 2.0, 2.0);
    glVertex3f(-0.5, 0.5, 0.0);

    glColor3f(2.0, 2.0, 2.0);
    glVertex3f(0.5, 0.5, 0.0);

    glColor3f(2.0, 2.0, 2.0);
    glVertex3f(0.5, -0.5, 0.0);

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