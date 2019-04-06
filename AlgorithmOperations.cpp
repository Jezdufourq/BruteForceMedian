//
// Created by Jez Dufourq on 2019-04-06.
//
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

tuple<long,long> BruteForceMedianOperations(vector<int> A);

tuple<long,long> BruteForceMedianOperations(vector<int> A)
{
    int n = A.size();
    int k = ceil(n/2.0);
    int basicOp = 0;
    tuple<int,int> outputArray;

    for (int i = 0; i < (n - 1); i++ )
    {
        long numSmaller = 0;
        long numEqual = 0;
        for(int j = 0; j < (n - 1); j++)
        {
            if (A[j] < A[i])
            {
                basicOp++;
                numSmaller++;
            }
            else
            {
                if(A[j] == A[i])
                {
                    basicOp++;
                    numEqual++;
                }
            }
        }
        if(numSmaller < k and k <= (numSmaller+numEqual))
        {
            return make_tuple(A[i],basicOp);
        }
    }
    return tuple<long, long>();
}