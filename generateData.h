//
// Created by Jez Dufourq on 2019-04-08.
//
#pragma once

#ifndef ASSIGNMENT1_GENERATEDATA_H
#define ASSIGNMENT1_GENERATEDATA_H

// Defining the large array value - preprocessor
#define LARGE_ARRAY_VALUE (1000) // Defining the value for the large array generator
#define NUM_SAME_ARRAY_SIMS (10) // Defining the value for the number of simulations for the same array

// These ARRAY_* are for all ARRAY'S which are used to test the operations and also the execution time of the algorithm
#define ARRAY_STEP_SIZE (101) // Defining the step size for the random array
#define ARRAY_NUM_SIMS (100) // Defining the number of same length arrays for the random implementation
#define RANDOM_RANGE (100) // Range of the random variable


#define SIMULATIONS (50) // How many simulations that the program will run

// TODO: This is not working
//#define INPUT_PRINT (false)


#endif //ASSIGNMENT1_GENERATEDATA_H


enum TEST_TYPE{
    NEGATIVE = 0,
    ODD = 1,
    EVEN = 2,
    LARGE = 3,
    ONELEN = 4,
    RANDOM = 5,
    REVERSED = 6,
    SORTED = 7,
};

enum PROGRAM_TYPE{
    FUNCTIONALITY = 0,
    OPERATIONS = 1,
    TIMING = 2,
};

extern PROGRAM_TYPE programType;
extern TEST_TYPE testType;


