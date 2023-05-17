#ifndef CPP_EX4_POINT_HPP
#define CPP_EX4_POINT_HPP
namespace ariel {
    class Point {
    private:
        double x__;
        double y__;

    public:
        Point(double x__, double y__);

        double distance(Point other);

        static Point moveTowards(Point src, Point dst, int dist);

        void Print();

        bool operator==(const Point other) const;

    };
}



#endif //CPP_EX4_POINT_HPP
