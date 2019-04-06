#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <limits>
#include <random>
#include <ctime>
#include <ratio>
#include <chrono>
#include <tuple>
#include <sstream>
#include <fstream>
#include "testing.cpp"
#include "AlgorithmOperations.cpp"
#include "AlgorithmExecutionTime.cpp"
#include "csvHandler.cpp"
#include "dataHandler.cpp"
#include "consoleHandler.cpp"
#include "testHandler.cpp"
#include <iomanip>

using namespace std;
using namespace std::chrono;

enum testCase{TESTING=0, EXECUTION_TIME=1, OPERATION_COUNT=2,EVEN_ARRAY=4};


int main(int argc, char* argv[])
{
    int userInput;
    cout << "=======WELCOME!=============" << endl;
    cout << "Enter the program that you would like to run" << endl;
    cout << "TESTING=0, EXECUTION_TIME=1, OPERATION_COUNT=2" << endl;
    cin >> userInput;

    switch(userInput) {
        case EVEN_ARRAY:
            cout << "=============TEST 2 : Even Array============" << endl;
            testEvenArray();
            cout << "=============================================\n" << endl;
            break;
        case TESTING:
            // Needs to include the following tests:
            // odd array
            // even array
            // test median
            // array length 1
            cout << "=======TEST 1 : Odd Array=======" << endl;
            testOddArray();
            cout << "================================\n" << endl;

            cout << "=============TEST 2 : Even Array============" << endl;
            testEvenArray();
            cout << "=============================================\n" << endl;

            cout << "==========TEST 3 : Array Length One Array============" << endl;
            testOneLenArray();
            cout << "=====================================================\n" << endl;

            cout << "=======TEST 4 : Large Input Array Size of 1000=======" << endl;
            testLargeSizeArray(1000);
            cout << "=====================================================\n" << endl;
            break;
        case EXECUTION_TIME:
            // Tests which need to be included
            cout << "=======TEST 1 : Random array of 100 simulations=======" << endl;
            cout << "===========TEST 1 : EXECUTION TIME TEST===============" << endl;
            testRandArray(1000, 10, 2);
            cout << "======================================================\n" << endl;
            break;

        case OPERATION_COUNT:
            cout << "=======TEST 1 : Random array of 100 simulations=======" << endl;
            cout << "===========TEST 1 : OPERATION COUNT TEST==============" << endl;
            testRandArray(1000, 10, 3);
            cout << "======================================================\n" << endl;
            break;

        default:
            return -1;
    }
}
