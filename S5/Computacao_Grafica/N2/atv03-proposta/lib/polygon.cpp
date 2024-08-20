#include "vertex.cpp"
#include <GL/glut.h>
#include <vector>
#include <stdio.h>

#ifndef __Polygon__
#define __Polygon__
#endif

using namespace std;

class Polygon {
    private:
        vector<Vertex> vertexes;
        int num_vertexes;
    public:
        Polygon() {};
        Polygon(int num_vtx) {
            num_vertexes = num_vtx;
        }
        Polygon(int num_vtx, vector<Vertex> vtx_arr_ext) {
            vertexes = vtx_arr_ext;
            num_vertexes = num_vtx;
        }
        void print_vtxs() {
            printf("[\n");
            for(int i = 0; i < num_vertexes; i++) {
                printf("%c = (%g, %g)\n", vertexes[i].get_alias(), vertexes[i].get_x(), 
                vertexes[i].get_y());
            }
            printf("]");
        }

        void draw(GLenum mode, double scale) {
            glBegin(mode);
            for (int i = 0; i < num_vertexes; i++) {
                glVertex2f(vertexes[i].get_x() * scale, vertexes[i].get_y() * scale);
            }
            glEnd();
        }

        void set_vertexes(vector<Vertex>& vtx_arr_ext) {
            vertexes = vtx_arr_ext;
        }
};
