#include "Point.hpp"

using namespace ariel;

Point::Point(double x__, double y__) : x__(x__), y__(y__){};

double Point::distance(ariel::Point other) {
    return 1.1;
}

Point Point::moveTowards(ariel::Point src, ariel::Point dst, int dist) {
    return Point(1.1,2.2);
}

void Point::Print() {

}

bool Point::operator==(const ariel::Point other) const {
    return this->x__ == other.x__ && this->y__ == other.y__;
}