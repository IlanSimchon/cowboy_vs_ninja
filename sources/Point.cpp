#include "Point.hpp"

using namespace ariel;

Point::Point(double _x_, double _y_) : _x_(_x_), _y_(_y_){}

//Point::Point(const Point &other) {
//    this->x__ = other.x__;
//    this->y__ = other.y__;
//}
Point::Point() :_x_(0) , _y_(0){}

double Point::distance(ariel::Point other) {
    return 1.1;
}

Point Point::moveTowards(ariel::Point src, ariel::Point dst, int dist) {
    return Point(1.1,2.2);
}

void Point::Print() {

}

bool Point::operator==(const Point& other) const {
    return this->_x_ == other._x_ && this->_y_ == other._y_;
}