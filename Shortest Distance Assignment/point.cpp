/// Created by Phuc Tran 08908184
///
/// File: point.cpp
/// Implementation of Point class
/// Encapsulates coordinates to represent a point in
/// 2D space and a method for calculating distance
/// between points

#include <cmath>

#include "point.h"

/// Encapsulates x and y coordinates to emulate a point in 2 dimensional
/// space, also contains method for calculating distance between points

/// \brief
///
/// Constructor, initializes x and y
/// \param double x - point on x-axis
/// \param double y - point on y-axis
Point::Point(double x, double y) {
   this->x = x;
   this->y = y;
}

/// \brief
///
/// Calculates Euclidean distance between this point to another
/// \param Point* - pointer to the other Point
double Point::distanceTo(Point* other) {
   double dx = x - other->x;
   double dy = y - other->y;
   return sqrt(dx * dx + dy * dy);
}


/// \brief
///
/// Outstram operator overload
/// Outputs the string represenation of the point
/// \param ostream& - reference to operator
/// \param point& - reference of point to be outputted
std::ostream& operator<<(std::ostream& out, Point& point) {
   out << "[" << point.x << ", " << point.y << "]";
   return out;
}
