#ifndef POLYGON
#define POLYGON
#endif

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

        void draw2d(GLenum renderPrimitive, double scale = 1) {
            glBegin(renderPrimitive);
            for (int i = 0; i < num_vertexes; i++) {
                glColor3f(vertexes[i].get_color()[0], vertexes[i].get_color()[1], vertexes[i].get_color()[2]);
                glVertex2f(vertexes[i].get_x() * scale, vertexes[i].get_y() * scale);
            }
            glEnd();
        }
        
        void draw3d(GLenum renderPrimitive, double scale = 1) {
            glBegin(renderPrimitive);
            for (int i = 0; i < num_vertexes; i++) {
                glColor3f(vertexes[i].get_color()[0], vertexes[i].get_color()[1], vertexes[i].get_color()[2]);
                glVertex3f(vertexes[i].get_x() * scale, vertexes[i].get_y() * scale, 
                vertexes[i].get_z() * scale);
            }
            glEnd();
        }
};