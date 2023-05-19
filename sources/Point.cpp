#include "Point.hpp"
#include <math.h>
#include <iostream>

using namespace ariel;
using namespace std;

Point::Point(double _x_, double _y_) : _x_(_x_), _y_(_y_){}

Point::Point() :_x_(0) , _y_(0){}

double Point::distance(Point other) {
    return sqrt(pow(this->_x_-other._x_,2)+ pow(this->_y_-other._y_ , 2));

}

Point Point::moveTowards(Point src, Point dst, double dist) {
    if(dist < 0)
        throw invalid_argument("Distance cannot be a negative");
    double curr_dist = src.distance(dst);
    if (dist >= curr_dist)
        return Point(dst);
    double ratio = dist / curr_dist;
    double newX = src._x_ + (dst._x_ - src._x_) * ratio;
    double newY = src._y_ + (dst._y_ - src._y_) * ratio;

    return Point(newX, newY);
}

string Point::Print() {
    return "x = " + to_string(this->_x_) + " , y = " + to_string(this->_y_);
}

bool Point::operator==(const Point& other) const {
    return this->_x_ == other._x_ && this->_y_ == other._y_;
}