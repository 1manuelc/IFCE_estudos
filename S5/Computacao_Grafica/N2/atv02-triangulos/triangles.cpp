#include <GL/glut.h>

#include <iostream>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_FLAT);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-0.9, -0.5, 0.0);
    glColor3f(-1.0, 1.0, 0.0);
    glVertex3f(-0.9, 0.5, 0.0);
    glColor3f(0.0, 0.0, 2.0);
    glVertex3f(-0.1, -0.5, 0.0);
    glEnd();

    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.9, -0.5, 0.0);
    glColor3f(-1.0, 1.0, 0.0);
    glVertex3f(0.1, 0.5, 0.0);
    glColor3f(0.0, 0.0, 2.0);
    glVertex3f(0.1, -0.5, 0.0);
    glEnd();

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(256, 256);

    glutCreateWindow("Atividade 01 - Manuel Carlos");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}