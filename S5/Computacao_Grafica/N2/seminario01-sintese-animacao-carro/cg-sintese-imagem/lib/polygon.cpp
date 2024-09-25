#ifndef POLYGON
#define POLYGON

#include "polygl.h"

class Vertex;
using namespace std;

class Polygon {
private:
    vector<Vertex> vertexes;
    int num_vertexes;

    vector<Vertex> drawBase(double scale = 1) {
        vector<Vertex> vtxs_v;
        vector<double> vtx_color;

        for (int i = 0; i < num_vertexes; i++) {
            double angle = 2 * M_PI * i / num_vertexes;
            double x = cos(angle) * scale;
            double y = sin(angle) * scale;

            if (i % 2 == 0)
                vtx_color = {0.9, 0.9, 0.9};
            else
                vtx_color = {0.4, 0.4, 0.4};

            Vertex vtx_n("vtx_" + i, x, y, 0, vtx_color);
            vtxs_v.push_back(vtx_n);
        }

        return vtxs_v;
    }

public:
    Polygon() {
    };

    Polygon(int num_vtx, float scale = 1) {
        num_vertexes = num_vtx;
        vertexes = drawBase(scale);
    }

    Polygon(int num_vtx, vector<Vertex> vtx_arr_ext) {
        num_vertexes = num_vtx;
        vertexes = vtx_arr_ext;
    }

    void print_vtxs() {
        printf("[\n");
        for (int i = 0; i < num_vertexes; i++) {
            cout << vertexes[i].get_alias()
                    << " (" << vertexes[i].get_x() << ", "
                    << vertexes[i].get_y() << ", "
                    << vertexes[i].get_z() << ")\n";
        }
        printf("]");
    }

    void set_vertexes(vector<Vertex> vtx_arr_ext) {
        vertexes = vtx_arr_ext;
    }

    void render2d(GLenum renderPrimitive, GLenum colorPrimitive = GL_SMOOTH, double scale = 1) {
        glShadeModel(colorPrimitive);
        glBegin(renderPrimitive);
        for (int i = 0; i < num_vertexes; i++) {
            glColor3f(vertexes[i].get_color()[0], vertexes[i].get_color()[1], vertexes[i].get_color()[2]);
            glVertex2f(vertexes[i].get_x() * scale, vertexes[i].get_y() * scale);
        }
        glEnd();
    }

    void render3d(GLenum renderPrimitive, GLenum colorPrimitive = GL_SMOOTH, double scale = 1) {
        glShadeModel(colorPrimitive);
        glBegin(renderPrimitive);
        for (int i = 0; i < num_vertexes; i++) {
            glColor3f(vertexes[i].get_color()[0], vertexes[i].get_color()[1], vertexes[i].get_color()[2]);
            glVertex3f(vertexes[i].get_x() * scale, vertexes[i].get_y() * scale,
                       vertexes[i].get_z() * scale);
        }
        glEnd();
    }

    void translate(float x = 0, float y = 0, float z = 0) {
        for (int i = 0; i < num_vertexes; i++) {
            vertexes[i].translate(x, y, z);
        }
    }

    void scale(float x = 1, float y = 1, float z = 1) {
        for (int i = 0; i < num_vertexes; i++) {
            vertexes[i].scale(x, y, z);
        }
    }
};

#endif
