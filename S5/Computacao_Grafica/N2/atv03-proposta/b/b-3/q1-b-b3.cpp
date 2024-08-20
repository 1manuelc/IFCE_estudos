#include <GL/glut.h>

void display() {
    glClearColor(0, 1, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glShadeModel(GL_SMOOTH);
    glBegin(GL_LINE_STRIP);
        glColor3f(0, 0, 0);
        glVertex2f(0, -1);
        glColor3f(0, 0, 0);
        glVertex2f(0.5, 0.5);
        glColor3f(0, 1, 0);
        glVertex2f(-0.5, 0);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(256, 256);

    glutCreateWindow("ATV03/Q1/B/3 - Linhas - Manuel Carlos");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
