/// Created by Phuc Tran 08908184
///
/// File: edge.h
/// Header of Edge Class
/// Encapsulates instance variables to emulate a edge,
/// with functions to manipulate these variables and methods
/// for sorting and output

#ifndef _edge_h_
#define _edge_h_

#include "vertex.h"

#include <string>
#include <iostream>
#include <sstream>

/// Encapsulates instance variables to emulate a vertex,
/// Stores the pointers to a source and destination vertex
/// and the weight between these two vertices, with methods for
/// accessing, comparing and outputting the edge for debugging purposes
class Edge {
    public:

        /// \brief
        ///
        /// No argument, empty default constructor
        Edge();

        /// \brief
        ///
        /// Multiparam constructor
        /// Sets the edge's source vertex, destination vertex, and
        /// weight according the specified values
        /// \param Vertex* source - pointer to source vertex
        /// \param Vertex* destination - pointer to destination vertex
        /// \param Vertex* weight - weight of the edge
        Edge(Vertex* source, Vertex* destination, double weight);

        /// \brief
        ///
        /// Empty destructor, no objects dynamically created from this class
        ~Edge();

        /// \brief
        ///
        /// Simple getter for the edge's source vertex
        /// \return Vertex* - pointer to source vertex
        Vertex* getSource();

        /// \brief
        ///
        /// Simple getter for the edge's destination vertex
        /// \return Vertex* - pointer to destination vertex
        Vertex* getDestination();

        /// \brief
        ///
        /// Simple getter for the edge's weight
        /// \return double - edge's weight
        double getWeight();

        /// \brief
        ///
        /// Boolean operator for comparing edges by their weight
        /// \param Edge* first - pointer to first edge
        /// \param Edge* second - pointer to first edge
        /// \return bool - true if first edge's weight is greater
        bool operator()(Edge* first, Edge* second);

        /// \brief
        ///
        /// Ostream operator overload
        /// Outputs the edge's instance variables for debugging purposes
        /// \param out - output
        /// \param edge - reference to edge
        /// \return ostream& - output string representation of edge
        friend std::ostream& operator<<(std::ostream& out, Edge& edge);

    private:

        // Instance variables storing pointers to the source and destination vertices
        // and the edge's weight
        Vertex* source;
        Vertex* destination;
        double weight;
};

#endif // _edge_h
