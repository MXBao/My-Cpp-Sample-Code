/// Created by Phuc Tran 08908184
///
/// File: random.cpp
/// Header of Random class, contains private method for seeding
/// randomizer and generating a random real number
/// and methods for generating random integers and probability

#include <cstdlib>
#include <ctime>
#include "random.h"

/// This class provides functions for generating random integers
/// and random probability

/// \brief
///
/// Constructor, initializes the randomizer.
Random::Random() {
   randomize();
}


/// \brief
///
/// Generates a random integer number greater than or equal to low and less than high.
/// \param low int - lower bound for range (inclusive)
/// \param high int - upper bound for range (exclusive)
/// \return int - A random integer number between low and high
int Random::randomInteger(int low, int high) {
   double d = double(rand()) / (double(RAND_MAX) + 1);
   int k = int(d * (high - low  + 1));
   return low + k;
}

/// \brief
/// Generates a true false outcome based on the probability
/// determined by p. e.g. 0.5 results in true 50% of the time
///
/// \param double p - Value between 0 (never) and 1 (always)
/// \return bool - true or false based on p
bool Random::randomChance(double p) {
   return randomReal(0, 1) < p;
}

/// \brief
///
/// Initializes the seed based on time to obtain different results
/// with different runs
void Random::randomize() {
   srand(int(time(NULL)));
}

/// \brief
///
/// Helper method for randomChance
/// Generates a random real number greater than or equal to low and less than high
///
/// \param low double - lower bound for range (inclusive)
/// \param high double - upper bound for range (exclusive)
/// \return double - A random real number between low and high
double Random::randomReal(double low, double high) {
   double d = double(rand()) / (double(RAND_MAX) + 1);
   return low + d * (high - low);
}
