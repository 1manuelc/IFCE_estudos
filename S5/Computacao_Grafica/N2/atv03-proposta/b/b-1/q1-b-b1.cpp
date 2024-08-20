#include <GL/glut.h>

void display() {
    glClearColor(1, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glShadeModel(GL_FLAT);

    glBegin(GL_POLYGON);

    glVertex3f(0.0, 1.0, 0.0);

    glVertex3f(-1.0, 0.0, 0.0);

    glColor3f(1, 1, 1);
    glVertex3f(1.0, 0.0, 0.0);

    glEnd();

    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(256, 256);

    glutCreateWindow("ATV03/Q1/B/1 - Triangulo - Manuel Carlos");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}