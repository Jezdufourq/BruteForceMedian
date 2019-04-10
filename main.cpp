#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <iterator>
#include <chrono>
#include "bruteMedian.cpp"
#include "generateData.cpp"
#include "csvGenerator.cpp"
#include "printConsoleHandler.cpp"
#include <iomanip>
#include "testMedian.cpp"
#include <tuple>
#include "bruteMedianTime.cpp"
#include "runTests.cpp"

using namespace std;
using namespace std::chrono;

// Calling the main method with the following arguments
// ./main.out TESTTYPE (As an integer)
int main(int argc, char *argv[]) {
    int userInput;
    cout << "============!WELCOME TO ALGOCRUNCH!=============" << endl;
    cout << "Enter the program that you would like to run" << endl;
    cout << "FUNCTIONALITY=0, OPERATIONS=1, TIMING=2" << endl;
    cin >> userInput;
    duration<double> timeTaken;

    auto startTime = chrono::high_resolution_clock::now();
    switch (userInput) {
        case FUNCTIONALITY:
            for (int i = TEST_TYPE::NEGATIVE; i <= TEST_TYPE::ONELEN; i++) {
                runTests((TEST_TYPE) i, PROGRAM_TYPE::FUNCTIONALITY);
            }
            break;
        case OPERATIONS:
            for (int i = TEST_TYPE::RANDOM; i <= TEST_TYPE::RANDOM; i++) {
                runTests((TEST_TYPE) i, PROGRAM_TYPE::OPERATIONS);
            }
            break;
        case TIMING:
            for (int i = TEST_TYPE::RANDOM; i <= TEST_TYPE::RANDOM; i++) {
                runTests((TEST_TYPE) i, PROGRAM_TYPE::TIMING);
            }
            break;

        default:
            return -8;
    }

    auto endTime = chrono::high_resolution_clock::now();
    timeTaken = duration_cast<duration<double>>(endTime - startTime);
    cout << "\n=====The execution time for the program is: " << timeTaken.count() << "=====" << endl;

    return 0;
}

