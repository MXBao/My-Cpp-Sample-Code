/// Created by Phuc Tran 08908184
///
/// File: vertex.h
/// Header of Vertex Class
/// Encapsulates instance variables to emulate a vertex,
/// with functions to manipulate these variables and methods
/// for sorting and output

#include <set>

#ifndef _vertex_h
#define _vertex_h

#include <string>
#include <iostream>
#include <sstream>

/// Encapsulates instance variables to emulate a vertex,
/// Stores the vertex's ID, adjacent vertex IDs, the directly preceding vertex's ID,
/// it's discovery states, the minimum distance between the vertex and
/// a source vertex and functions to alter access these variables, sort vertices
/// and outputting the vertex for debugging purposes
class Vertex{

    public:

        /// \brief
        ///
        /// No argument, empty default constructor
        Vertex();

        /// \brief
        ///
        /// Constructor for creating a vertex with a defined ID
        /// \param unsigned int - identifier of vertex to be created
        Vertex(unsigned int);

        /// \brief
        ///
        /// Destructor, deletes the adjacencies collection
        ~Vertex();

        /// \brief
        ///
        /// Simple getter for the vertex's ID
        /// \return unsigned int - vertex's identifier
        unsigned int getId();

        /// \brief
        ///
        /// Appends the ID of another vertex to the adjacencies collection
        /// \param unsigned int - other vertex's ID
        void addAdjacency(unsigned int);

        /// \brief
        ///
        /// Simple getter for the vertex's collection of adjacencies
        /// \return <unsigned int>* - pointer to the adjacencies collection
        std::set<unsigned int>* getAdjacencies();

        /// \brief
        ///
        /// Mutator for altering the discovered state of the vertex
        /// \param bool - true or false for discovered or not
        void setDiscovered(bool);

        /// \brief
        ///
        /// Simple getter for the vertice's discovered state
        /// \return bool - true or false for discovered or not
        bool isDiscovered();

        /// \brief
        ///
        /// Mutator for altering the vertex's predeccesor
        /// \param unsigned int - preceding vertex's identifier
        void setPredecessorId(unsigned int);

        /// \brief
        ///
        /// Simple getter for the vertex's predeccesor
        /// \return unsigned int - preceding vertex's identifier
        unsigned int getPredecessorId();

        /// \brief
        ///
        /// Mutator for altering minimum distance between the vertex
        /// and a source vertex, used in dijkstra's algorithm
        /// \param double - minimum distance between this vertex and the source
        void setMinDistance(double);

        /// \brief
        ///
        /// Simple getter for the minimum distance between the vertex
        /// and a source vertex, used in dijkstra's algorithm
        /// \return double - minimum distance between this vertex and the source
        double getMinDistance();

        /// \brief
        ///
        /// Boolean operator for comparing vertices by their minimum distances to the source
        /// \param Vertex* source - pointer to first vertex
        /// \param Vertex* destination - pointer to second vertex
        /// \return bool - true if first vertex's minimum distance is >= second's
        bool operator()(Vertex* first, Vertex* second);

        /// \brief
        ///
        /// Ostream operator overload
        /// Outputs string representing the vertex in the format:
        /// V:identifier:predecessorID:discovered:minDistance:adjacencies
        /// e.g. V:1:2:T:1.23:2|3|4|
        /// \param out - output
        /// \param vertex - reference to the vertex
        /// \return ostream& - outputs string representation of vertex
        friend std::ostream& operator<<(std::ostream& out, Vertex& vertex);

    private:

        // Instance variable storing the vertex's ID, adjacencies, discovery
        // state, vertex's predecessor's ID and the vertex's minimum distance to
        // a vertex source
        unsigned int identifier;
        std::set<unsigned int> adjacencies;
        bool discovered;
        unsigned int predecessorId;
        double minDistance;

        /// \brief
        ///
        /// Helper method for converting the adjacency collection
        /// to string form for output
        /// return string - string representation of adjacent vertex IDs
        std::string adjacenciesToString();

};

#endif // _vertex_h
