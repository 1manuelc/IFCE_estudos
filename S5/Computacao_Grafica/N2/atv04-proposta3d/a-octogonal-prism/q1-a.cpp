#include "../../../lib/polygl.h"

struct CameraPosition {
    float eye_x, eye_y, eye_z;
    float center_x, center_y, center_z;
    float up_x, up_y, up_z;
};

CameraPosition cam1 = {
    -4.0,   4.0,    4.0, 
    0.0,    0.0,    1.0, 
    0.0,    0.0,    1.0
};
CameraPosition cam2 = {
    5.0,    6.0,    8.0, 
    0.0,    0.0,    1.0, 
    0.0,    0.0,    1.0
};
CameraPosition cam3 = {
    4.0,    -6.0,   -1.0, 
    0.0,    0.0,    1.0, 
    0.0,    0.0,    1.0
};

CameraPosition currentCam = cam1;

void configureAndClearBuffers() {
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void config3d(float aspect) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, aspect, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(
        currentCam.eye_x,   currentCam.eye_y,   currentCam.eye_z,
        currentCam.center_x,currentCam.center_y,currentCam.center_z,
        currentCam.up_x,    currentCam.up_y,    currentCam.up_z
    );
}

void resize(int window_width, int window_height) {
    float aspect = 0.0;
    
    if (window_height == 0) {
        window_height = 1;
    }
    
    aspect = (float) window_width / window_height;
    glViewport(0, 0, window_width, window_height);

    config3d(aspect);
}

void renderAxis() {
    glLineWidth(2.0f);
    glShadeModel(GL_FLAT);

    glBegin(GL_LINES);
        glColor3f(1, 0, 0);
        glVertex3f(-100, 0, 0);
        glVertex3f(100, 0, 0);

        glColor3f(0, 1, 0);
        glVertex3f(0, -100, 0);
        glVertex3f(0, 100, 0);

        glColor3f(0, 0, 1);
        glVertex3f(0, 0, -100);
        glVertex3f(0, 0, 100);
    glEnd();
}

void renderGrid(float size, int divisions) {
    float step = size / divisions;
    float half = size / 2.0f;

    glLineWidth(1.0);
    glColor3f(0.3, 0.3, 0.3);

    glBegin(GL_LINES);
    for (int i = 0; i <= divisions; ++i) {
        float pos = i * step - half;

        // Linhas paralelas ao eixo X
        glVertex3f(pos, -half, 0.0f);
        glVertex3f(pos,  half, 0.0f);

        // Linhas paralelas ao eixo Y
        glVertex3f(-half, pos, 0.0f);
        glVertex3f( half, pos, 0.0f);
    }
    glEnd();
}

void renderPrisma() {
   Prisma octogonal_prism(8, 0, 2);
   octogonal_prism.render3d(GL_POLYGON);
}

void render() {
    renderAxis();
    renderGrid(20, 12);
    renderPrisma();
}

void display() {
    glClearColor(0, 0, 0, 1);

    configureAndClearBuffers();

    render();
    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '1':
            currentCam = cam1;
            break;
        case '2':
            currentCam = cam2;
            break;
        case '3':
            currentCam = cam3;
            break;
        default:
            return;
    }

    float aspect = glutGet(GLUT_WINDOW_WIDTH) / (float)glutGet(GLUT_WINDOW_HEIGHT);
    config3d(aspect);
    glutPostRedisplay(); // re-renderiza
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    
    glutInitWindowSize(800, 800);
    glutCreateWindow("ATV04/Q1/A - Prisma Octogonal - Manuel Carlos");
    
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    
    return 0;
}