/// Created by Phuc Tran 08908184
///
/// File: graph.h
/// Header of Graph Class
/// Encapsulates instance variables to emulate a graph,
/// with functions finding the shortest distance from
/// to a source vertex from other vertices through
/// dijkstra's algorithm and breadth first search

#include <vector>
#include <queue>

#ifndef _graph_
#define _graph_

#include <iostream>
#include <iomanip>

#include "vertex.h"
#include "edge.h"
#include "disjointset.h"

// Constant representing infinity
const int INFINITY = 9999999;

/// Encapsulates instance variables to emulate a graph;
/// the number of vertices in the graph, a 2-dimensional array
/// to emulate an adjacency matrix, a queue collection to store edges and
/// a set collection to store pointers to vertices.
/// Also includes methods for calculating the minimim spanning tree cost,
/// and shortest distances from vertices towards a source through dijksta's
/// algorithm and breadth width search
class Graph {
    public:

        /// \brief
        ///
        /// Constructor, initializes the number of vertices in the graph
        /// and the adjacency matrix
        /// \param unsigned int - number of vertices
        Graph(unsigned int);

        /// \brief
        ///
        /// Destructor, deletes the adjacency matrix and collections
        ~Graph();

        /// \brief
        ///
        /// Adds vertices to the graph's vertices collection
        /// \param Vertex* - pointer to the vertex to be added
        void addVertex(Vertex*);

        /// \brief
        ///
        /// Getter for a vertex at a specified identifier/index
        /// \param int - identifier/index
        /// \return Vertex* - pointer to the vertex
        Vertex* getVertex(int);

        /// \brief
        ///
        /// Adds vertices to the graph's edge queue collection
        /// \param Edge* - pointer to edge
        void addEdge(Edge*);

        /// \brief
        ///
        /// Calculates the minimum spanning tree cost using the edge queue collection
        /// through Kruskal’s Algorithm
        /// Also sets up the adjacency list for vertices in the graph
        /// \pre - all edges have added to edges queue collection
        /// \param double - minimum spanning tree cost
        double minimumSpanningTreeCost();

        /// \brief
        ///
        /// Calculates and outputs the minimum distance and path
        /// between all vertices towards a specified source using Dijkstra's algorithm
        /// \pre - adjacency matrix initialized
        /// \pre - all vertices have been added to the vertices collection
        /// \param unsigned int - source vertex's ID
        void dijkstra(unsigned int);

        /// \brief
        ///
        /// Calculates and outputs the minimum distance and path
        /// between all vertices towards a specified source through
        /// Breadth Width Search
        /// \pre - adjacency matrix initialized
        /// \pre - all vertices have been added to the vertices collection
        /// \pre - adjacencies of vertices initialized by MST
        /// \param unsigned int - source vertex's ID
        void bfs(unsigned int);

        /// \brief
        ///
        /// Ostream operator overload
        /// Outputs the adjacency matrix
        /// \param ostream - reference to output stream
        /// \param Graph& - reference to graph
        friend std::ostream& operator<<(std::ostream&, Graph&);

    private:

        // Instance variables encapsulating the number of vertices
        // in the graphs, the adjacency matrix, edges queue collection
        // and vector collection
        unsigned int numVertices;
        double** weights;
        std::priority_queue<Edge*, std::vector<Edge*>, Edge> edges;
        std::vector<Vertex*> vertices;

        /// \brief
        ///
        /// Helper method for outputting the path from source point to
        /// a vertice and the distance covered by the path
        /// \pre path strings prepared by the algorithm methods
        /// \param int source - source vertex ID
        /// \param int destination - destination vertex ID
        /// \param double distance - distance covered by the path
        /// \param string path - string representation of the path
        void outputPath(int source, int destination, double distance, std::string path);

        /// \brief
        ///
        /// Simple int to string conversion method
        /// Used to create the path string within the algorithm method
        /// \param int - an integer
        /// \return string - representation of integer
        std::string convertIntToString(int);

};

#endif // _graph_h
