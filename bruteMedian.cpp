#include <vector>
#include <iostream>
using namespace std;

tuple<int, long long int> BruteForceMedian(vector<int> &input) {
    // Calculate the half-way index of the array.
    int k = (int) ceil(input.size() / 2.0);
    long long int numOp = 0;

    for (int i = 0; i < input.size(); i++) {
        int numSmaller = 0; // Number of elements smaller than input[i];
        int numEqual = 0; // Number of elements equal to input[i];

        for (int j = 0; j < input.size(); j++) {
            // Calculate number of array items that are smaller, and equal.
            if (input[j] < input[i]) {
                numSmaller++;
                numOp += 1;
            } else {
                if (input[j] == input[i]) {
                    numEqual++;
                    numOp += 2;
                }
            }
        }
/*
            else {
                numOp += 2; // None matched, add 2.
            }*/
//        numOp += 2;

        if (numSmaller < k && k <= (numSmaller + numEqual)) {
            return make_tuple(input[i], numOp);
        }
    }
    return tuple<int, long long int>();
}
