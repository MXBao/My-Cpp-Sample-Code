/// Created by Phuc Tran 08908184
///
/// File: point.h
/// Header of Point class
/// Encapsulates coordinates to represent a point in
/// 2D space and a method for calculating distance
/// between points

#include <iostream>

#ifndef _point_h
#define _point_h

/// Encapsulates x and y coordinates to emulate a point in 2 dimensional
/// space, also contains method for calculating distance between points
class Point {

    public:

        /// \brief
        ///
        /// Constructor, initializes x and y
        /// \param double x - point on x-axis
        /// \param double y - point on y-axis
        Point(double x, double y);

        /// \brief
        ///
        /// Calculates Euclidean distance between this point to another
        /// \param Point* - pointer to the other Point
        double distanceTo(Point*);

        /// \brief
        ///
        /// Outstram operator overload
        /// Outputs the string represenation of the point
        /// \param ostream& - reference to operator
        /// \param point& - reference of point to be outputted
        friend std::ostream& operator<<(std::ostream& out, Point& point);

    private:

        // Instance variables emulating axii values
        double x;
        double y;
};

#endif // _point_h
