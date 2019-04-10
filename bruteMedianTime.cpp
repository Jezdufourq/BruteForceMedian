#include <vector>
#include <iostream>
using namespace std;
using namespace std::chrono;

double BruteForceMedianTime(vector<int> &input) {
    // Calculate the half-way index of the array.
    int k = (int) ceil(float(input.size()) / 2.0);

    for (int i = 0; i <= (input.size()-1); i++) {
        int numSmaller = 0; // Number of elements smaller than input[i];
        int numEqual = 0; // Number of elements equal to input[i];

        for (int j = 0; j <= (input.size() - 1); j++) {
            // Calculate number of array items that are smaller, and equal.
            if (input[j] < input[i]) {
                numSmaller++;

            } else {
                if (input[j] == input[i]) {
                    numEqual++;
                }
            }
            if ((numSmaller < k) && (k <= (numSmaller + numEqual))) {
                return input[i];
            }
        }
    }
    return 0;
}


