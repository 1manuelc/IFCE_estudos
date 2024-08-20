#include <iostream>

#ifndef __Vertex__
#define __Vertex__
#endif

using namespace std;

class Vertex {
    private:
        char alias;
        double x;
        double y;
        string color;
    public:
        Vertex(char alias_n, double x_n, 
        double y_n, string color_n = "Empty") { 
            alias = alias_n;
            x = x_n;
            y = y_n;
            color = color_n;
        }

        char get_alias() { return alias; };
        void set_alias(char alias_n) { 
            alias = alias_n;
        };

        double get_x() { return x; }
        double get_y() { return y; }
        void set_x(double x_n) { 
            x = x_n;
        }
        void set_y(double y_n) { 
            y = y_n;
        }

        string get_color() { return color; };
        void set_color(string color_n) { 
            color = color_n;
        };
};
