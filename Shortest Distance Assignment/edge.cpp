/// Created by Phuc Tran 08908184
///
/// File: edge.cpp
/// Implementation of Edge Class
/// Encapsulates instance variables to emulate a edge,
/// with functions to manipulate these variables and methods
/// for sorting and output
#include "edge.h"

/// Encapsulates instance variables to emulate a vertex,
/// Stores the pointers to a source and destination vertex
/// and the weight between these two vertices, with methods for
/// accessing, comparing and outputting the edge for debugging purposes
Edge::Edge() {
}

/// \brief
///
/// Multiparam constructor
/// Sets the edge's source vertex, destination vertex, and
/// weight according the specified values
/// \param Vertex* source - pointer to source vertex
/// \param Vertex* destination - pointer to destination vertex
/// \param Vertex* weight - weight of the edge
Edge::Edge(Vertex* source, Vertex* destination, double weight){
    this->source = source;
    this->destination = destination;
    this->weight = weight;
}

/// \brief
///
/// Empty destructor, no objects dynamically created from this clas
Edge::~Edge(){
}

/// \brief
///
/// Simple getter for the edge's source vertex
/// \return Vertex* - pointer to source vertex
Vertex* Edge::getSource(){
    return source;
}

/// \brief
///
/// Simple getter for the edge's destination vertex
/// \return Vertex* - pointer to destination vertex
Vertex* Edge::getDestination(){
    return destination;
}

/// \brief
///
/// Simple getter for the edge's weight
/// \return double - edge's weight
double Edge::getWeight(){
    return weight;
}

/// \brief
///
/// Boolean operator for comparing edges by their weight
/// \param Edge* first - pointer to first edge
/// \param Edge* second - pointer to first edge
/// \return bool - true if first edge's weight is greater
bool Edge::operator() (Edge* first, Edge* second){
    return first->getWeight() > second->getWeight();
}

/// \brief
///
/// Ostream operator overload
/// Outputs the edge's instance variables for debugging purposes
/// \param out - output
/// \param edge - reference to edge
/// \return ostream& - output string representation of edge
std::ostream& operator<<(std::ostream& out, Edge& edge) {
    out << "E:" << edge.source->getPredecessorId()
    << "--[" << edge.getWeight() << "]-->"
    << edge.getDestination();
    return out;
}
