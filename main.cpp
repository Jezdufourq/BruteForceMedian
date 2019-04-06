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
typedef vector <tuple<long, long>>operationTuples;

operationTuples test1;
enum testCase{TESTING=0, EXECUTION_TIME=1, OPERATION_COUNT=2};


int main(int argc, char* argv[])
{
    testOddArray();
    cout << setw(80) << setfill('=') << "\n";
    cout << setw(80) << setfill('=') << "\n" << endl;
    testEvenArray();
    cout << setw(80) << setfill('=') << "\n";
    cout << setw(80) << setfill('=') << "\n" << endl;
    testOneLenArray();
    cout << setw(80) << setfill('=') << "\n";
    cout << setw(80) << setfill('=') << "\n" << endl;
    testRandArray(10,100);


//    int userInput;
//    cout << "=======WELCOME!=============" << endl;
//    cout << "Enter the program that you would like to run" << endl;
//    cout << "TESTING=0, EXECUTION_TIME=1, OPERATION_COUNT=2" << endl;
//    cin >> userInput;
//
//    switch(userInput)
//    {
//        case TESTING:
//        {
//            // Needs to include the following tests:
//            // odd array
//            // even array
//            // test median
//            // array length 1
//
//            cout << "=======TEST 1 : Odd Array=======" << endl;
//            testOddArray();
//
//            cout << "=======TEST 2 : Even Array=======" << endl;
//            testEvenArray();
//
//            cout << "=======TEST 3 : Array Length One Array=======" << endl;
//            testOneLenArray();
//
//            cout << "=======TEST 4 : Large Input Array Size=======" << endl;
//            testLargeSizeArray();
//        }
//        case EXECUTION_TIME:
//        {
//
//        }
//        case OPERATION_COUNT:
//        {
//
//        }
//        default:
//        {
//            return -1;
//        }
//    }


}
