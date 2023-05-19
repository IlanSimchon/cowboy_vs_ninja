#ifndef CPP_EX4_POINT_HPP
#define CPP_EX4_POINT_HPP
#include <string>
using namespace std;

namespace ariel {
    class Point {
    private:
        double _x_;
        double _y_;

    public:
        Point(double _x_, double _y_);

        Point();
        double distance(Point other);

        static Point moveTowards(Point src, Point dst, double dist);

        string Print();

        bool operator==(const Point& other) const;

    };
}



#endif
