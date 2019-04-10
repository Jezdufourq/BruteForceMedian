#include <vector>
#include <iostream>
using namespace std;

unsigned long long numOp = 0;

double BruteForceMedian(vector<int> &input) {
    // Calculate the half-way index of the array.
    int k = (int) ceil(input.size() / 2.0);

    for (int i = 0; i < input.size(); i++) {
        int numSmaller = 0; // Number of elements smaller than input[i];
        int numEqual = 0; // Number of elements equal to input[i];

        for (int j = 0; j < input.size(); j++) {
            // Calculate number of array items that are smaller, and equal.
            if (input[j] < input[i]) {
                numSmaller++;
                numOp++;
            } else if (input[j] == input[i]) {
                numEqual++;
                numOp++;
            }
        }
        if (numSmaller < k && k <= (numSmaller + numEqual)) {
            return input[i];
        }
    }
    return 0;
}
