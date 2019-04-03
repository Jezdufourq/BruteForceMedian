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

using namespace std;
using namespace std::chrono;

vector<int>Rand(int length, int range);
tuple<long,long,float>BruteForceMedian(vector<int>A);
void print(vector<int> const &input);
double inputCSV(int maxLen, int minLen, int range, int amountSims, int stepSize);
void print2D(vector<vector<int>> const &input);

int main(int argc, char* argv[])
{

//    int range = 100;
//    int length = 20;
//    vector<int>randArray;
//
//    randArray = Rand(length, range);
//
//    auto [median, basicOp, timeTaken] = BruteForceMedian(randArray);
//
//    cout << "This is the random array" << endl;
//    print(randArray);
//    cout << "This is the output" << endl;
//    cout << median << ',' << basicOp << ',' << timeTaken << endl;

    double output = inputCSV(100, 10, 300, 10, 10);

    cout << "amount of total sims: " << output << endl;

    return 0;
}

// inputCSV
// INPUTS:
// totalSims = (maxLen/stepSize)*amountSims
// amountSims = amount of simulations on each step size
// maxLen - the length of the array
// range - the range of the random values in the array
// sims - # of simulations
// minLen - The minimum length of an array
double inputCSV(int maxLen, int minLen, int range, int amountSims, int stepSize){
    // This is going to be the input array which is streamed to a .csv file
    vector<vector<int>> inputArray;
    ofstream output;
    output.open("input.csv");
    int totalSims = (maxLen/stepSize) * amountSims;
    int arrayLen = minLen;

    for (int i = 0; i < amountSims; i++)
    {
        for (int j = 0; j < stepSize; j++)
        {
            inputArray.push_back(Rand(arrayLen, range));
        }
        minLen+=stepSize;
    }

    print2D(inputArray);

    output.close();
    return totalSims;
}


// Creating a vector which stores an array of random ints
// This function is implemented using a random seed which is determined on the current time of the computer
// INTPUTS:
// Length - The length of the array
// Range - The range of the random variables
// OUTPUT:
// Vector Rand - A vector of random variables
vector<int>Rand(int length, int range)
{
    vector<int> random_vector;
    milliseconds ms = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

    srand(ms.count());
    for(int index = 0; index < length; index++)
    {
        int random = rand() & range;
        random_vector.push_back(random);
    }
    return random_vector;
}



tuple<long,long, float> BruteForceMedian(vector<int> A)
{
    int n = A.size();
    int k = ceil(n/2);
    int basicOp = 0;
    tuple<int,int> outputArray;
    duration<double> timeTaken;

    for (int i = 0; i < (n - 1); i++ )
    {
        auto startTime = chrono::high_resolution_clock::now();

        int numSmaller = 0;
        int numEqual = 0;
        for(int j = 0; j < (n - 1); j++)
        {
            if (A[j] < A[i])
            {
                basicOp++;
                numSmaller++;
            }
            else if(A[j] == A[i])
            {
                basicOp++;
                numEqual++;
            }
        }
    if(numSmaller < k and k <= (numSmaller+numEqual))
    {
        auto endTime = chrono::high_resolution_clock::now();
        timeTaken = duration_cast<duration<double>>(endTime - startTime);

        return make_tuple(A[i],basicOp, timeTaken.count());
    }
    }
    return tuple<long, long, float>();
}

void print2D(vector<vector<int>> const &input)
{
    // Auto in this case is used to cut down on writing vector each time
    // Auto is implemented when the program is built
    // It sets the input value automatically to a vector value
    // TODO: Need to research this.
    for (auto &row: input)
    {
        for (auto col: row) {
            cout << col << endl;
        }
    }
}



void print(vector<int> const &input)
{
    cout <<  "[";
    // Auto in this case is used to cut down on writing vector each time
    // Auto is implemented when the program is built
    // It sets the input value automatically to a vector value
    // TODO: Need to research this.
    for (auto v: input)
    {
        cout << v << endl;
    }
    cout <<  "]" << endl;
}

//TODO: Create the to csv function


