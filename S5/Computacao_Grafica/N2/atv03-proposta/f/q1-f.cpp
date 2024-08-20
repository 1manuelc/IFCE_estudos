#include <GL/glut.h>

void drawPolygon(const double (*coordinates)[2], int lines, double scale) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < lines; i++) {
        glVertex2f(coordinates[i][0] * scale, coordinates[i][1] * scale);
    }
    glEnd();
}

void drawCross() {
    constexpr double outerRectangleV[4][2] = {
        {-0.25, 0.75},
        {0.25, 0.75},
        {0.25, -0.75},
        {-0.25, -0.75},
    };
    constexpr double outerRectangleH[4][2] = {
        {-0.75, 0.25},
        {0.75, 0.25},
        {0.75, -0.25},
        {-0.75, -0.25},
    };
    constexpr double innerRectangleV[4][2] = {
        {-0.125, 0.75}, {0.125, 0.75},
        {0.125, -0.75}, {-0.125, -0.75},
    };
    constexpr double innerRectangleH[4][2] = {
        {-0.75, 0.125}, {0.75, 0.125},
        {0.75, -0.125}, {-0.75, -0.125}
    };
    constexpr double trapezoidT[4][2] = {
        {-0.5, 1},
        {0.5, 1},
        {0.25, 0.75},
        {-0.25, 0.75},
    };
    constexpr double trapezoidR[4][2] = {
        {0.75, 0.25},
        {1, 0.5},
        {1, -0.5},
        {0.75, -0.25},
    };
    constexpr double trapezoidB[4][2] = {
        {-0.25, -0.75},
        {0.25, -0.75},
        {0.5, -1},
        {-0.5, -1},
    };
    constexpr double trapezoidL[4][2] = {
        {-0.75, 0.25},
        {-1, 0.5},
        {-1, -0.5},
        {-0.75, -0.25},
    };

    glColor3f(0.92, 0, 0);
    drawPolygon(outerRectangleV, 4, 0.75);
    drawPolygon(outerRectangleH, 4, 0.75);
    drawPolygon(trapezoidT, 4, 0.75);
    drawPolygon(trapezoidR, 4, 0.75);
    drawPolygon(trapezoidB, 4, 0.75);
    drawPolygon(trapezoidL, 4, 0.75);

    glColor3f(1, 1, 1);
    drawPolygon(innerRectangleV, 4, 0.75);
    drawPolygon(innerRectangleH, 4, 0.75);
}

void display() {
    glClearColor(0.1, 0.1, 0.1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glShadeModel(GL_FLAT);
    drawCross();
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(256, 256);

    glutCreateWindow("ATV03/Q1/F - Cruz da ordem de Cristo  - Manuel Carlos");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
