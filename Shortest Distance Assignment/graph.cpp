/// Created by Phuc Tran 08908184
///
/// File: graph.cpp
/// Implementation of Graph Class
/// Encapsulates instance variables to emulate a graph,
/// with functions finding the shortest distance from
/// to a source vertex from other vertices through
/// dijkstra's algorithm and breadth first search

#include "graph.h"

/// Encapsulates instance variables to emulate a graph;
/// the number of vertices in the graph, a 2-dimensional array
/// to emulate an adjacency matrix, a queue collection to store edges and
/// a set collection to store pointers to vertices.
/// Also includes methods for calculating the minimim spanning tree cost,
/// and shortest distances from vertices towards a source through dijksta's
/// algorithm and breadth width search

/// \brief
///
/// Constructor, initializes the number of vertices in the graph
/// and the adjacency matrix
/// \param unsigned int - number of vertices
Graph::Graph(unsigned int N){

    numVertices = N;

    // Initialize 2 dimensional array to emulate the adjacency matrix
    // sets weight values between vertices to infinity by default
    // and zero where vertices are the same
    weights = new double*[N];

    for (unsigned i = 0; i < N; i++) {
        weights[i] = new double[N];

        for (unsigned j = 0; j < N; j++) {
            weights[i][j] = INFINITY;
        }
        weights[i][i] = 0;
    }

}

/// \brief
///
/// Destructor, deletes the adjacency matrix
Graph::~Graph(){

    // Delete the embedded arrays then the array
    for (unsigned i = 0; i < numVertices; i++) {
        delete[] weights[i];
    }

    delete[] weights;

}

/// \brief
///
/// Adds vertices to the graph's vertices collection
/// \param Vertex* - pointer to the vertex to be added
void Graph::addVertex(Vertex* v){
    vertices.push_back(v);
}

/// \brief
///
/// Getter for a vertex at a specified identifier/index
/// \param int - identifier/index
/// \return Vertex* - pointer to the vertex
Vertex* Graph::getVertex(int i){
    return vertices.at(i);
}

/// \brief
///
/// Adds vertices to the graph's edge queue collection
/// \param Edge* - pointer to edge
void Graph::addEdge(Edge* e){

    // Alter the weight values of
    // the adjacency matrix corresponding to weight of edges
    unsigned src = e->getSource()->getId();
    unsigned dst = e->getDestination()->getId();
    double w = e->getWeight();

    weights[src][dst] = w;
    weights[dst][src] = w;

    // Add edge to the edges queue collection
    edges.push(e);
}

/// \brief
///
/// Calculates the minimum spanning tree cost using the edge queue collection
/// through Kruskal’s Algorithm
/// Also sets up the adjacency list for vertices in the graph
/// \pre - all edges have added to edges queue collection
/// \param double - minimum spanning tree cost
double Graph::minimumSpanningTreeCost(){

    // Initializes values disjoint set object
    double minCost = 0;
    DisjointSet ds = DisjointSet(numVertices);
    unsigned int edgeCount = 0;

    // Poll the edges from queue collection,
    // where vertices do not belong to the same subset,
    // generate adjacency list for the vertices making up the edge
    // and increment the minimum cost based on the edge weight
    while(!edges.empty() && edgeCount < numVertices - 1){
        Edge* e = edges.top();
        edges.pop();
        int p = e->getSource()->getId();
        int q = e->getDestination()->getId();
        if(!ds.sameComponent(p, q)){
            edgeCount++;
            ds.join(p, q);
            e->getDestination()->addAdjacency(p);
            e->getSource()->addAdjacency(q);
            minCost = minCost + e->getWeight();
        }
    }
    return minCost;
}

/// \brief
///
/// Calculates and outputs the minimum distance and path
/// between all vertices towards a specified source using Dijkstra's algorithm
/// \pre - adjacency matrix initialized
/// \pre - all vertices have been added to the vertices collection
/// \param unsigned int - source vertex's ID
void Graph::dijkstra(unsigned int sourceId){

    // Initialize the a queue to store vertices
    std::priority_queue<Vertex*, std::vector<Vertex*>, Vertex> vertexQueue;

    // Sets all vertices' predecessor ID and minimum distance to the sourceID
    // and adds them to the queue
    for(std::vector<Vertex*>::iterator it=vertices.begin(); it!=vertices.end(); ++it){

        (*it)->setDiscovered(false);
        (*it)->setPredecessorId(sourceId);
        (*it)->setMinDistance(weights[sourceId][(*it)->getId()]);
        vertexQueue.push(*it);

    }

    while(!vertexQueue.empty()){

        // Poll from queue and set discovered
        Vertex* currentVertex = vertexQueue.top();
        vertexQueue.pop();
        currentVertex->setDiscovered(true);

        // Create local instances of current ID and minDistance
        int currentId = currentVertex->getId();
        double currentMinDistance = currentVertex->getMinDistance();

        // Modify adjacent vertices' min distance and predecessor ID where appropriate
        // and have the same repeated on the qualifying adjacency until all have been processed
        for(unsigned i = 0; i < vertices.size(); i++){

            Vertex* v = vertices.at(i);
            double weight = weights[currentId][v->getId()];

            if(!v->isDiscovered() && v != currentVertex && weight != INFINITY){

                if(currentMinDistance + weight < v->getMinDistance()){

                    v->setMinDistance(currentMinDistance + weight);
                    v->setPredecessorId(currentId);
                    vertexQueue.push(v);
                }

            } //end if adjacent and unfound check

        } // end for

    } // end while

    // Output the minimum distance/path to the source
    // for each vertex that is not the source
    for(unsigned i = 0; i < vertices.size(); i++){

        Vertex* u = vertices.at(sourceId);
        Vertex* v = vertices.at(i);

        if(v != u) {

            int source = u->getId();
            int destination = v->getId();
            double pathDistance = v->getMinDistance();

            std::string pathString;

            // Walk from vertex to source to contenate path
            while(v != u) {
                pathString = convertIntToString(v->getId()) + "  " + pathString;
                v = vertices.at(v->getPredecessorId());
            } // end while

            pathString = convertIntToString(source) + "  " + pathString;
            outputPath(source, destination, pathDistance, pathString);

        } // end if source check

    } // end for
}

/// \brief
///
/// Calculates and outputs the minimum distance and path
/// between all vertices towards a specified source through
/// Breadth Width Search
/// \pre - adjacency matrix initialized
/// \pre - all vertices have been added to the vertices collection
/// \pre - adjacencies of vertices initialized by MST
/// \param unsigned int - source vertex's ID
void Graph::bfs(unsigned int sourceId){

    // Set all vertices to undiscovered
    for(std::vector<Vertex*>::iterator it=vertices.begin(); it!=vertices.end(); ++it){
        (*it)->setDiscovered(false);
    }

    // Initialize a queue, sets the source vertice to discovered and add it to the queue
    std::priority_queue<Vertex*> vertexQueue;
    vertices.at(sourceId)->setDiscovered(true);
    vertexQueue.push(vertices.at(sourceId));

    // Poll the queue and modify the predecessor ID of points adjacent,
    // undiscovered points to the polled vertice and propagate this effect
    // by adding the qualifying vertices into the queue
    while (!vertexQueue.empty()){
        Vertex* u = vertexQueue.top();
        vertexQueue.pop();

        std::set<unsigned int>* adjacencies = u->getAdjacencies();
        for(std::set<unsigned int>::iterator it = adjacencies->begin(); it!=adjacencies->end(); ++it){
            if(!vertices.at(*it)->isDiscovered()){
                vertices.at(*it)->setPredecessorId(u->getId());
                vertices.at(*it)->setDiscovered(true);
                vertexQueue.push(vertices.at(*it));
            }
        } // end for
    } // end while

    // Calculate and output the path and distance travelled by path for
    // each vertice to the source
    for(unsigned i = 0; i < vertices.size(); i++){

        Vertex* u = vertices.at(sourceId);
        Vertex* v = vertices.at(i);

        if(v != u) {

            int source = u->getId();
            int destination = v->getId();

            double pathDistance = 0;
            std::string pathOutPut = "";

            // Walk to source using the vertice's predecessor ID while incrementing
            // the path distance based on edge weight and contenate the path ID for
            // output
            while(v != u) {
                int currentVertexId = v->getId();
                pathOutPut = convertIntToString(currentVertexId) + "  " + pathOutPut;
                pathDistance += weights[currentVertexId][v->getPredecessorId()];
                v = vertices.at(v->getPredecessorId());
            } // end while

            pathOutPut = convertIntToString(source) + "  " + pathOutPut;
            outputPath(source, destination, pathDistance, pathOutPut);

        } // end if
    } // end for

}

/// \brief
///
/// Ostream operator overload
/// Outputs the adjacency matrix
/// \param ostream - reference to output stream
/// \param Graph& - reference to graph
std::ostream& operator<<(std::ostream& out, Graph& graph){

    for (unsigned i = 0; i < graph.numVertices; i++) {
        for (unsigned j = 0; j < graph.numVertices; j++) {
            if (graph.weights[i][j] == INFINITY) {
                out << "      -";
            } else {
                double weight = graph.weights[i][j];
                out << std::fixed;
                out << std::setprecision(2);
                out << std::setw(7) << weight;
            }
        }
        out << std::endl;
    }

    return out;
}

/// \brief
///
/// Helper method for outputting the path from source point to
/// a vertice and the distance covered by the path
/// \pre path strings prepared by the algorithm methods
/// \param int source - source vertex ID
/// \param int destination - destination vertex ID
/// \param double distance - distance covered by the path
/// \param string path - string representation of the path
void Graph::outputPath(int source, int destination, double distance, std::string path){

    if (distance == INFINITY) {
        std::cout << "NO PATH  from ";
        std::cout << source << " to  " << destination;
        std::cout << std::endl;
    } else {
        std::cout << "Distance from ";
        std::cout << source << " to  " << destination;
        std::cout << " = " << std::setw(6) << distance;
        std::cout << " traveling via  " << path << std::endl;
    }
}

/// \brief
///
/// Simple int to string conversion method
/// Used to create the path string within the algorithm method
/// \param int - an integer
/// \return string - representation of integer
std::string Graph::convertIntToString(int i){
    std::stringstream ss;
    ss << i;
    return ss.str();
}
