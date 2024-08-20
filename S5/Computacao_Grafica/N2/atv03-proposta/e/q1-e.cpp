#include <GL/glut.h>
#include <math.h>

void drawLimitLines() {
    glLineWidth(4.0f);

    glBegin(GL_LINES);
        glVertex2f(0, -1);
        glColor3f(0.5, 1, 0);
        glVertex2f(0, 1);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(-1, 0);
        glColor3f(0.5, 1, 0);
        glVertex2f(1, 0);
    glEnd();
}

void drawCircle(double scale, double offsetX, double offsetY, double red, 
                double green, double blue, bool isFilled = true) {
    if(isFilled) {
        glBegin(GL_POLYGON);
            for(int i = 0; i <= 360; i++){
                double angle = 2 * M_PI * i / 360;
                double x = cos(angle);
                double y = sin(angle);
                glColor3f(red, green, blue);
                glVertex2f((x * scale) + offsetX, (y * scale) + offsetY);
            }
        glEnd();
    } else {
        glBegin(GL_LINE_STRIP);
            for(int i = 0; i <= 360; i++){
                double angle = 2 * M_PI * i / 360;
                double x = cos(angle);
                double y = sin(angle);
                glColor3f(red, green, blue);
                glVertex2f((x * scale) + offsetX, (y * scale) + offsetY);
            }
        glEnd();
    }
}

void display() {
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glShadeModel(GL_FLAT);
    drawLimitLines();
    drawCircle(0.3, -0.5, 0.5, 1, 0, 0, false);
    drawCircle(0.3, 0.5, -0.5, 0, 0, 1, true);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(256, 256);

    glutCreateWindow("ATV03/Q1/E - Círculos - Manuel Carlos");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}