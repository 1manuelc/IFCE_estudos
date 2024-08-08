#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(256, 256);
    glutCreateWindow("Atividade 01 - Manuel Carlos");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
