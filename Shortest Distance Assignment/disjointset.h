/// Created by Phuc Tran 08908184
///
/// File: disjointset.h
/// Header of Disjointset class
/// Encapsulates methods to implement a
/// disjoint set data structure

#ifndef _disjointset_
#define _disjointset_

// Constant defining the default number
// for elements of the size array
const int INITIAL = 1;

/// Encapsulates methods to implement a
/// disjoint set data structure, including union-find algorithms
class DisjointSet {

    public:

        /// \brief
        ///
        /// Constructor, initializes the disjoint set
        /// of a specified size
        /// \param int - size of disjoint set
        DisjointSet(int);

        /// \brief
        ///
        /// Destructor, deletes the arrays created
        ~DisjointSet();

        /// \brief
        ///
        /// Algorithm for determining which subset an element is in
        /// \param int i - element
        /// \return int - subset
        int find(int i);

        /// \brief
        ///
        /// Algorithm to union two elements'
        /// subsets into a single subset
        /// \param int p - first subset
        /// \param int q - second subset
        void join(int p, int q);

        /// \brief
        ///
        /// Compare two subsets based on the specified element
        /// \param int p - first element
        /// \param int q - second element
        /// \return bool - true if elements belong to the same subset
        bool sameComponent(int p, int q);

    private:

        // Instance variables storing the size of the disjoint sets
        // and arrays holding the identifiers for id and subset
        int* id;
        int* size;
        int N;

};

#endif // _disjointset_h
