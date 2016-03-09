/// Created by Phuc Tran 08908184
///
/// File: vertex.cpp
/// Implementation file of Vertex Class
/// Encapsulates instance variables to emulate a vertex,
/// with functions to manipulate these variables and methods
/// for sorting and output

#include "vertex.h"

/// Encapsulates instance variables to emulate a vertex,
/// with instance variables for storing the vertex's
/// ID, adjacent vertex IDs, the directly preceding vertex's ID,
/// it's discovery states, the minimum distance between the vertex and
/// a source vertex and functions to alter access these variables, sort vertices
/// and outputting the vertex for debugging purposes
Vertex::Vertex(){
}

/// \brief
///
/// Constructor for creating a vertex with a defined ID
/// \param unsigned int - identifier of vertex to be created
Vertex::Vertex(unsigned int id){
    identifier = id;
}

/// \brief
///
/// Destructor, does not need to delete anything
Vertex::~Vertex(){
}

/// \brief
///
/// Simple getter for the vertex's ID
/// \return unsigned int - vertex's identifier
unsigned int Vertex::getId(){
    return identifier;
}

/// \brief
///
/// Appends the ID of another vertex to the adjacencies collection
/// \param unsigned int - other vertex's ID
void Vertex::addAdjacency(unsigned int a){
    adjacencies.insert(a);
}

/// \brief
///
/// Simple getter for the vertex's collection of adjacencies
/// \return <unsigned int>* - pointer to the adjacencies collection
std::set<unsigned int>* Vertex::getAdjacencies(){
    return &adjacencies;
}

/// \brief
///
/// Mutator for altering the discovered state of the vertex
/// \param bool - true or false for discovered or not
void Vertex::setDiscovered(bool d){
    discovered = d;
}

/// \brief
///
/// Simple getter for the vertice's discovered state
/// \return bool - true or false for discovered or not
bool Vertex::isDiscovered(){
    return discovered;
}

/// \brief
///
/// Mutator for altering the vertex's predeccesor
/// \param unsigned int - preceding vertex's identifier
void Vertex::setPredecessorId(unsigned int p){
    predecessorId = p;
}

/// \brief
///
/// Simple getter for the vertex's predeccesor
/// \return unsigned int - preceding vertex's identifier
unsigned int Vertex::getPredecessorId(){
    return predecessorId;
}

/// \brief
///
/// Mutator for altering minimum distance between the vertex
/// and a source vertex, used in dijkstra's algorithm
/// \param double - minimum distance between this vertex and the source
void Vertex::setMinDistance(double d){
    minDistance = d;
}

/// \brief
///
/// Simple getter for the minimum distance between the vertex
/// and a source vertex, used in dijkstra's algorithm
/// \return double - minimum distance between this vertex and the source
double Vertex::getMinDistance(){
    return minDistance;
}

/// \brief
///
/// Boolean operator for comparing vertices by their minimum distances to the source
/// \param Vertex* source - pointer to first vertex
/// \param Vertex* destination - pointer to second vertex
/// \return bool - true if first vertex's minimum distance is >= second's
bool Vertex::operator()(Vertex* first, Vertex* second) {
    return first->getMinDistance() >= second->getMinDistance();
}

/// \brief
///
/// Ostream operator overload
/// Outputs string representing the vertex in the format:
/// V:identifier:predecessorID:discovered:minDistance:adjacencies
/// e.g. V:1:2:T:1.23:2|3|4|
/// \param out - output
/// \param vertex - reference to the vertex
/// \return ostream& - outputs string representation of vertex
std::ostream& operator<<(std::ostream& out, Vertex& vertex) {

    std::string found;

    // Set string representation of discovery state
    if(vertex.isDiscovered()) {
        found = "T";
    } else {
        found = "F";
    }

    // Output variables
    out << "V:" << vertex.getId()<< ":"
    << vertex.getPredecessorId() << ":"
    << found << ":"
    << vertex.getMinDistance() << ":"
    << vertex.adjacenciesToString();

    return out;
}

/// \brief
///
/// Helper method for converting the adjacency collection
/// to string form for output
/// return string - string representation of adjacent vertex IDs
std::string Vertex::adjacenciesToString(){

    std::string str = "";
    std::stringstream ss;

    // Convert and contenate adjacencies
    for(std::set<unsigned int>::iterator it=adjacencies.begin(); it!=adjacencies.end(); ++it) {
        ss << *it;
        str += ss.str() + "|";
        ss.str("");
    }

    return str;
}
