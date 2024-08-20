#include "../lib/polygon.cpp"
#include <GL/glut.h>

void drawPlane() {
    // Plane body vertexes
    Vertex vtx_b_1('C', -0.44, -0.27);
    Vertex vtx_b_2('U', -0.07, 0.12);
    Vertex vtx_b_3('R', 0.30, 0.51);
    Vertex vtx_b_4('Q', 0.64, 0.87);
    Vertex vtx_b_5('P', 0.898, 0.639);
    Vertex vtx_b_6('O', 0.52, 0.28);
    Vertex vtx_b_7('L', 0.13, -0.08);
    Vertex vtx_b_8('K', -0.26, -0.45);
    
    // Plane wings vertexes
    Vertex vtx_uwl_1('S', -0.79, 0.83);
    Vertex vtx_uwl_2('T', -0.93, 0.70);
    Vertex vtx_uwr_1('N', 0.84, -0.80);
    Vertex vtx_uwr_2('M', 0.72, -0.93);
    Vertex vtx_lwl_1('D', -0.90, -0.19);
    Vertex vtx_lwl_2('E', -1.00, -0.29);
    Vertex vtx_lwr_1('J', -0.18, -0.89);
    Vertex vtx_lwr_2('I', -0.28, -1.00);
    
    // Plane tail vertexes
    Vertex vtx_t_1('f', -0.63, -0.52);
    Vertex vtx_t_2('d', -0.657, -0.553);
    Vertex vtx_t_3('c', -0.684, -0.594);
    Vertex vtx_t_4('z', -0.709, -0.646);
    Vertex vtx_t_5('v', -0.722, -0.694);
    Vertex vtx_t_6('g', -0.72, -0.72);
    Vertex vtx_t_7('w', -0.683, -0.721);
    Vertex vtx_t_8('a', -0.634, -0.707);
    Vertex vtx_t_9('b', -0.587, -0.681);
    Vertex vtx_t_10('e', -0.548, -0.653);
    Vertex vtx_t_11('h', -0.52, -0.63);

    // Plane cockpit vertexes
    Vertex vtx_c_1('g', 0.712, 0.933);
    Vertex vtx_c_2('j', 0.797, 0.983);
    Vertex vtx_c_3('k', 0.861, 1.000);
    Vertex vtx_c_4('n', 0.900, 1.000);
    Vertex vtx_c_5('o', 0.935, 0.989);
    Vertex vtx_c_6('p', 0.964, 0.972);
    Vertex vtx_c_7('m', 0.980, 0.947);
    Vertex vtx_c_8('q', 0.991, 0.920);
    Vertex vtx_c_9('l', 1.000, 0.893);
    Vertex vtx_c_10('r', 1.000, 0.862);
    Vertex vtx_c_11('s', 0.992, 0.835);
    Vertex vtx_c_12('i', 0.984, 0.804);
    Vertex vtx_c_13('t', 0.972, 0.770);
    Vertex vtx_c_14('h', 0.951, 0.730);
    Vertex vtx_c_15('u', 0.930, 0.685);

    Polygon plane_upper_wing_left(4, {
        vtx_uwl_1, vtx_b_3, vtx_b_2, vtx_uwl_2      
    });
    Polygon plane_upper_wing_right(4, {
        vtx_b_6, vtx_uwr_1, vtx_uwr_2, vtx_b_7      
    });

    Polygon plane_lower_wing_left(4, {
        vtx_lwl_1, vtx_b_1, vtx_t_1, vtx_lwl_2
    });
    Polygon plane_lower_wing_right(4, {
        vtx_b_8, vtx_lwr_1, vtx_lwr_2, vtx_t_11
    });

    Polygon plane_body(10, {
        vtx_t_1, vtx_b_1, vtx_b_2, vtx_b_3, vtx_b_4,
        vtx_b_5, vtx_b_6, vtx_b_7, vtx_b_8, vtx_t_11
    });
    Polygon plane_tail(11, {
        vtx_t_1, vtx_t_2, vtx_t_3, vtx_t_4, vtx_t_5,
        vtx_t_6, vtx_t_7, vtx_t_8, vtx_t_9, vtx_t_10,
        vtx_t_11,
    });
    Polygon plane_cockpit(17, {
        vtx_b_4, vtx_c_1, vtx_c_2, vtx_c_3, vtx_c_4, vtx_c_5,
        vtx_c_6, vtx_c_7, vtx_c_8, vtx_c_9, vtx_c_10, vtx_c_11,
        vtx_c_12, vtx_c_13, vtx_c_14, vtx_c_15, vtx_b_5
    });

    plane_cockpit.draw(GL_TRIANGLE_FAN, 0.8);
    plane_body.draw(GL_TRIANGLE_FAN, 0.8);
    plane_tail.draw(GL_TRIANGLE_FAN, 0.8);

    plane_upper_wing_left.draw(GL_TRIANGLE_FAN, 0.8);
    plane_upper_wing_right.draw(GL_TRIANGLE_FAN, 0.8);

    plane_lower_wing_left.draw(GL_TRIANGLE_FAN, 0.8);
    plane_lower_wing_right.draw(GL_TRIANGLE_FAN, 0.8);
}

void display() {
    glClearColor(0.1, 0.1, 0.1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glShadeModel(GL_FLAT);
    drawPlane();
    
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(256, 256);

    glutCreateWindow("ATV03/Q1/G - Avião  - Manuel Carlos");
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

