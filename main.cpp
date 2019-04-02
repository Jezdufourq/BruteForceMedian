#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <limits>
#include <random>
#include <ctime>
#include <ratio>
#include <chrono>

using namespace std;
using namespace std::chrono;

vector<int>Rand(int length, int range);
void print(vector<int> const &input);

int main()
{
    int range = 100;
    int length = 20;

    print(Rand(length,range));
    return 0;
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


void print(vector<int> const &input)
{
    cout <<  "[";
    // Auto in this case is used to cut down on writing vector each time
    // Auto is implemented when the program is built
    // It sets the input value automatically to a vector value
    // TODO: Need to research this.
    for (auto v: input)
    {
        cout << v << ",";
    }
    cout <<  "]" << endl;
}

