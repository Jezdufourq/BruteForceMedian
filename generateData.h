//
// Created by Jez Dufourq on 2019-04-08.
//

#ifndef ASSIGNMENT1_GENERATEDATA_H
#define ASSIGNMENT1_GENERATEDATA_H


// Defining the large array value - preprocessor
#define LARGE_ARRAY_VALUE (1000) // Defining the value for the large array generator
#define NUM_SAME_ARRAY_SIMS (10) // Defining the value for the number of simulations for the same array

// These ARRAY_* are for all ARRAY'S which are used to test the operations and also the execution time of the algorithm
#define ARRAY_STEP_SIZE (10) // Defining the step size for the random array
#define ARRAY_NUM_SIMS (10) // Defining the number of same length arrays for the random implementation
#define RANDOM_RANGE (100) // Range of the random variable
#endif //ASSIGNMENT1_GENERATEDATA_H

enum TEST_TYPE{
    ODD = 0,
    EVEN = 1,
    LARGE = 2,
    ONELEN = 3,
    RANDOM = 4,
    REVERSED = 5,
    SORTED = 6,
};

extern TEST_TYPE testType;
