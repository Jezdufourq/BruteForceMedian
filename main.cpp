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
#include "testHandler.cpp"
#include "consoleHandler.cpp"

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[])
{
    vector<vector<vector<int>>> newArray;
    newArray = randArray(10,100);
    print3D(newArray);
    string test = "test.csv";
//    double output = inputCSV(100, 10, 300, 10, 10);
//
//    cout << "amount of total sims: " << output << endl;
    createCsv3D(test,newArray);

    return 0;
}
