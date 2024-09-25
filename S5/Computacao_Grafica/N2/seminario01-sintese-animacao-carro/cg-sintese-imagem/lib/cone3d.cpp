#ifndef CONE3D
#define CONE3D
#include "polygl.h"
class Polygon;
class Cone {
   private:
    int baseSegments;
    float baseRadius;
    Vertex top_vtx;
    double z_floor;

    vector<Vertex> base_vtxs;
    vector<vector<Vertex>> lateral_face_vtxs;

    vector<Vertex> drawConeBase(double z, double scale = 1) {
        vector<Vertex> vtxs_v;
        vector<double> vtx_color;

        for (int i = 0; i < baseSegments; i++) {
            double angle = 2 * M_PI * i / baseSegments;
            double x = baseRadius * cos(angle);
            double y = baseRadius * sin(angle);

            if (i % 2 == 0)
                vtx_color = {0.9, 0.9, 0.9};
            else
                vtx_color = {0.4, 0.4, 0.4};

            Vertex vtx_n("vtx_" + i, x, y, z, vtx_color);
            vtxs_v.push_back(vtx_n);
        }

        return vtxs_v;
    }

    vector<vector<Vertex>> drawConeLateralFaces(Vertex top_vtx,
                                                vector<Vertex> base_vtxs) {
        vector<vector<Vertex>> lat_vtxs_v(baseSegments, vector<Vertex>(3));

        for (int i = 0; i < base_vtxs.size(); i++) {
            int next = (i + 1) % base_vtxs.size();

            vector<Vertex> face_vtxs = {
                Vertex("vtx_" + std::to_string(i) + "_0", base_vtxs[i].get_x(),
                       base_vtxs[i].get_y(), base_vtxs[i].get_z(),
                       {0.9, 0.9, 0.9}),

                Vertex("vtx_" + std::to_string(i) + "_1", top_vtx.get_x(),
                       top_vtx.get_y(), top_vtx.get_z(), {0.4, 0.4, 0.4}),

                Vertex("vtx_" + std::to_string(i) + "_2",
                       base_vtxs[next].get_x(), base_vtxs[next].get_y(),
                       base_vtxs[next].get_z(), {0.9, 0.9, 0.9})};

            lat_vtxs_v[i] = face_vtxs;
        }

        return lat_vtxs_v;
    }

   public:
    Cone(int baseSegments_n, float baseRadius_n, Vertex top_vtx_n,
         double z_floor_n) {
        baseSegments = baseSegments_n;
        baseRadius = baseRadius_n;

        top_vtx = top_vtx_n;
        z_floor = z_floor_n;

        base_vtxs = drawConeBase(z_floor);
        lateral_face_vtxs = drawConeLateralFaces(top_vtx, base_vtxs);
    }

    void render3d(GLenum renderPrimitive) {
        glShadeModel(GL_SMOOTH);

        Polygon base(baseSegments, base_vtxs);
        base.render3d(renderPrimitive);

        if (renderPrimitive == GL_POLYGON || renderPrimitive == GL_QUADS) {
            glBegin(GL_TRIANGLES);
        } else {
            glLineWidth(2.5);
            glBegin(GL_LINE_LOOP);
        }

        for (int i = 0; i < lateral_face_vtxs.size(); i++) {
            for (int j = 0; j < lateral_face_vtxs[0].size(); j++) {
                glColor3f(lateral_face_vtxs[i][j].get_color()[0],
                          lateral_face_vtxs[i][j].get_color()[1],
                          lateral_face_vtxs[i][j].get_color()[2]);
                glVertex3f(lateral_face_vtxs[i][j].get_x(),
                           lateral_face_vtxs[i][j].get_y(),
                           lateral_face_vtxs[i][j].get_z());
            }
        }
        glEnd();
    }
};

#endif
