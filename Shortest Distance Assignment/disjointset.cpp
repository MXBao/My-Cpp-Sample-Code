/// Created by Phuc Tran 08908184
///
/// File: disjointset.cpp
/// Implementation of Disjointset class
/// Encapsulates methods to implement a
/// disjoint set data structure

#include "disjointset.h"

/// Encapsulates methods to implement a
/// disjoint set data structure, including union-find algorithms

/// \brief
///
/// Constructor, initializes the disjoint set
/// of a specified size
/// \param int - size of disjoint set
DisjointSet::DisjointSet(int N){
    this->N = N;

    id = new int[N];
    size = new int[N];

    for(int i = 0; i < N; i++){
        id[i] = i;
        size[i] = INITIAL;
    }

}

/// \brief
///
/// Destructor, deletes the arrays created
DisjointSet::~DisjointSet(){
    delete[] id;
    delete[] size;
}

/// \brief
///
/// Algorithm for determining which subset an element is in
/// \param int i - element
/// \return int - subset
int DisjointSet::find(int i){

    while (i != id[i]) {
        id[i] = id[id[i]]; // make elements point to their grandparent
        i = id[i];
    }
    return i;
}

/// \brief
///
/// Algorithm to union two elements'
/// subsets into a single subset
/// \param int p - first element
/// \param int q - second element
void DisjointSet::join(int p, int q){

    int i = find(p);
    int j = find(q);
    if (i == j) return;

    if (size[i] < size[j]) {
        id[i] = j;
        size[j] += size[i];
    } else {
        id[j] = i;
        size[i] += size[j];
    }

}

/// \brief
///
/// Compare two subsets based on the specified element
/// \param int p - first element
/// \param int q - second element
/// \return bool - true if elements belong to the same subset
bool DisjointSet::sameComponent(int p, int q){
    return find(p) == find(q);
}
