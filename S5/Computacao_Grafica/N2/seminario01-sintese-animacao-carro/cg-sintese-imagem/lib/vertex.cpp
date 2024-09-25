#ifndef VERTEX
#define VERTEX
#include "polygl.h"

using namespace std;

class Vertex {
private:
    string alias;
    double x;
    double y;
    double z;
    vector<double> color;

public:
    Vertex() : alias(""), x(0.0), y(0.0), z(0.0), color({0.0, 0.0, 0.0}) {
    }

    Vertex(string alias_n, double x_n, double y_n, double z_n, vector<double> color_n = {1.0, 1.0, 1.0}) {
        alias = alias_n;
        x = x_n;
        y = y_n;
        z = z_n;
        color = color_n;
    }

    string get_alias() {
        return alias;
    }

    void set_alias(string alias_n) {
        alias = alias_n;
    }

    double get_x() {
        return x;
    }

    double get_y() {
        return y;
    }

    double get_z() {
        return z;
    }

    void set_x(double x_n) {
        x = x_n;
    }

    void set_y(double y_n) {
        y = y_n;
    }

    void set_z(double z_n) {
        z = z_n;
    }

    vector<double> get_color() {
        return color;
    }

    void set_color(vector<double> color_n) {
        color = color_n;
    }

    void translate(float x_n, float y_n, float z_n = 0) {
        this->x += x_n;
        this->y += y_n;
        this->z += z_n;
    }

    void scale(float x_n = 1, float y_n = 1, float z_n = 1) {
        this->x *= x_n;
        this->y *= y_n;
        this->z *= z_n;
    }
};

#endif
