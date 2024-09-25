#ifndef PRISMA3D
#define PRISMA3D

#include "polygl.h"
using namespace std;
class Polygon;

class Prisma {
    private:
        int segments;
        vector<Vertex> top_base_vtxs;
        vector<Vertex> bottom_base_vtxs;
        vector<vector<Vertex>> lateral_faces_vtxs;
        double z_bottom, z_top;

        vector<Vertex> drawPrismaBase(double z, double scale = 1) {
            vector<Vertex> vtxs_v;
            vector<double> vtx_color;

            for(int i = 0; i < segments; i++){
                double angle = 2 * M_PI * i / segments;
                double x = cos(angle);
                double y = sin(angle);

                if(i % 2 == 0) vtx_color = {0.9, 0.9, 0.9};
                else vtx_color = {0.4, 0.4, 0.4};

                Vertex vtx_n("vtx_" + i, x, y, z, vtx_color);
                vtxs_v.push_back(vtx_n);
            }

            return vtxs_v;
        }

        vector<vector<Vertex>> drawPrismaLateralFaces(vector<Vertex> bottom_base_vtxs, vector<Vertex> top_base_vtxs) {
            vector<vector<Vertex>> lat_vtxs_v(segments, vector<Vertex>(4));

            for(int i = 0; i < top_base_vtxs.size(); i++) {
                int next = (i + 1) % top_base_vtxs.size();

                vector<Vertex> face_vtxs = {
                    Vertex("vtx_" + std::to_string(i) + "_0",
                        bottom_base_vtxs[next].get_x(),
                        bottom_base_vtxs[next].get_y(),
                        bottom_base_vtxs[next].get_z(),
                        {0.4, 0.4, 0.4}),

                    Vertex("vtx_" + std::to_string(i) + "_1",
                        bottom_base_vtxs[i].get_x(),
                        bottom_base_vtxs[i].get_y(),
                        bottom_base_vtxs[i].get_z(),
                        {0.9, 0.9, 0.9}),

                    Vertex("vtx_" + std::to_string(i) + "_2",
                        top_base_vtxs[i].get_x(),
                        top_base_vtxs[i].get_y(),
                        top_base_vtxs[i].get_z(),
                        {0.4, 0.4, 0.4}),

                    Vertex("vtx_" + std::to_string(i) + "_3",
                        top_base_vtxs[next].get_x(),
                        top_base_vtxs[next].get_y(),
                        top_base_vtxs[next].get_z(),
                        {0.9, 0.9, 0.9})
                };

                lat_vtxs_v[i] = face_vtxs;
            }

            return lat_vtxs_v;
        }

    public:
        Prisma(int segments_n, double z_bottom, double z_top, double scale = 1) {
            segments = segments_n;
            top_base_vtxs = drawPrismaBase(z_top);
            bottom_base_vtxs = drawPrismaBase(z_bottom);
            lateral_faces_vtxs = drawPrismaLateralFaces(bottom_base_vtxs, top_base_vtxs);
        }

        void render3d(GLenum renderPrimitive) {
            glShadeModel(GL_SMOOTH);

            Polygon bottom_base(segments, bottom_base_vtxs);
            bottom_base.render3d(renderPrimitive);

            Polygon top_base(segments, top_base_vtxs);
            top_base.render3d(renderPrimitive);

            if(renderPrimitive == GL_POLYGON || renderPrimitive == GL_QUADS) {
                glBegin(GL_QUADS);
            } else {
                glBegin(GL_LINE_LOOP);
            }

            for(int i = 0; i < lateral_faces_vtxs.size(); i++) {
                for(int j = 0; j < lateral_faces_vtxs[0].size(); j++) {
                    glColor3f(lateral_faces_vtxs[i][j].get_color()[0], lateral_faces_vtxs[i][j].get_color()[1], lateral_faces_vtxs[i][j].get_color()[2]);
                    glVertex3f(lateral_faces_vtxs[i][j].get_x(), lateral_faces_vtxs[i][j].get_y(), lateral_faces_vtxs[i][j].get_z());
                }
            }
            glEnd();
        }
    };

#endif
