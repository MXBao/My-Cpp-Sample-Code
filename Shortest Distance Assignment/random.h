/// Created by Phuc Tran 08908184
///
/// File: random.h
/// Header of Random class, contains private method for seeding
/// randomizer and generating a random real number
/// and methods for generating random integers and probability

#ifndef _random_h
#define _random_h


/// This class provides functions for generating random integers
/// and random probability
///
class Random {
    public:

       /// \brief
       ///
       /// Constructor, initializes the randomizer.
       Random();


        /// \brief
        ///
        /// Generates a random integer number greater than or equal to low and less than high.
        /// \param low int - lower bound for range (inclusive)
        /// \param high int - upper bound for range (exclusive)
        /// \return int - A random integer number between low and high
        int randomInteger(int low, int high);


        /// \brief
        /// Generates a true false outcome based on the probability
        /// determined by p. e.g. 0.5 results in true 50% of the time
        ///
        /// \param double p - Value between 0 (never) and 1 (always)
        /// \return bool - true or false based on p
        bool randomChance(double p);

    private:

        /// \brief
        ///
        /// Initializes the seed based on time to obtain different results
        /// with different runs
        void randomize();

        /// \brief
        ///
        /// Helper method for randomChance
        /// Generates a random real number greater than or equal to low and less than high
        ///
        /// \param low double - lower bound for range (inclusive)
        /// \param high double - upper bound for range (exclusive)
        /// \return double - A random real number between low and high
        double randomReal(double low, double high);
};

#endif // _random_h
