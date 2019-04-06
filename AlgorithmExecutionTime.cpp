//
// Created by Jez Dufourq on 2019-04-06.
//
#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>
#include <tuple>

using namespace std;
using namespace std::chrono;

tuple<long, float> BruteForceMedianTime(vector<int> A);

tuple<long, float> BruteForceMedianTime(vector<int> A)
{
    int n = A.size();
    int k = ceil(n/2.0);
    int basicOp = 0;
    tuple<int,int> outputArray;
    duration<double> timeTaken;

    for (int i = 0; i < (n - 1); i++ )
    {
        auto startTime = chrono::high_resolution_clock::now();
        long numSmaller = 0;
        long numEqual = 0;

        for(int j = 0; j < (n - 1); j++)
        {
            if (A[j] < A[i])
            {
                numSmaller++;
            }
            else
            {
                if(A[j] == A[i])
                {
                    numEqual++;
                }
            }
        }
        if(numSmaller < k and k <= (numSmaller+numEqual))
        {
            auto endTime = chrono::high_resolution_clock::now();
            timeTaken = duration_cast<duration<double>>(endTime - startTime);

            return make_tuple(A[i], timeTaken.count());
        }
    }
    return tuple<long, float>();
}