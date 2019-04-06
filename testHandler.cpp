//
// Created by Jez Dufourq on 2019-04-06.
//
typedef vector<tuple<long,long, long>> MedianOperationsVector;
typedef vector<tuple<long, long, float>> MedianTimeVector;
#include <iomanip>
using namespace std;

void testOddArray();
void testEvenArray();
void testOneLenArray();
void testRandArray();
void testMedianArray();
void testLargeSizeArray();

void testOddArray() {
    // Creating the data
    vector<vector<int>> oddData;
    oddData = oddArray();

    // Storing the data in a csv
    string oddInputStr = "testOddArrayInput.csv";
    createCsv2D(oddInputStr, oddData);

    // Run the algorithms on the odd length array
    MedianOperationsVector oddTestOperations;
    MedianTimeVector oddTestExecutionTime;

    for (auto &row : oddData) {
        oddTestOperations.push_back(BruteForceMedianOperations(row));
        oddTestExecutionTime.push_back(BruteForceMedianTime(row));
    }
    // Store the results in an output csv
    string oddTestStr = "testOddArrayOutput.csv";
    createCsvOutput(oddTestStr, oddTestOperations, oddTestExecutionTime);

    // Print the results to the console
    cout << "=======ODD TEST : Input values=======" << endl;
    print2D(oddData);
    cout << "\n=======ODD TEST : Output values=======" << endl;
    printOutput(oddTestOperations, oddTestExecutionTime);

    // Printing the results of the comparison
    long oddSolutions[] = {4, 2, 87};
    vector<string> testOutcome;
    // Compare the test results with what we expect
    cout << "\n=======ODD TEST : Test results=======" << endl;
    for (int i = 0; i < oddTestOperations.size(); i++) {
        if (get<1>(oddTestOperations[i]) == oddSolutions[i]) {
           testOutcome.emplace_back("PASSED");
        } else {
            testOutcome.emplace_back("FAILED");
        }
    }
    printResults(oddTestOperations,oddSolutions, testOutcome);
}

void testEvenArray() {
    // Creating the data
    vector<vector<int>> evenData;
    evenData = evenArray();

    // Storing the data in a csv
    string evenInputStr = "testEvenArrayInput.csv";
    createCsv2D(evenInputStr, evenData);

    // Run the algorithms on the odd length array
    MedianOperationsVector evenTestOperations;
    MedianTimeVector evenTestExecutionTime;

    for (auto &row : evenData) {
        evenTestOperations.push_back(BruteForceMedianOperations(row));
        evenTestExecutionTime.push_back(BruteForceMedianTime(row));
    }
    // Store the results in an output csv
    string evenTestStr = "testEvenArrayOutput.csv";
    createCsvOutput(evenTestStr, evenTestOperations, evenTestExecutionTime);

    // Print the results to the console
    cout << "=======EVEN TEST : Input values=======" << endl;
    print2D(evenData);
    cout << "\n=======EVEN TEST : Output values=======" << endl;
    printOutput(evenTestOperations, evenTestExecutionTime);

    // Printing the results of the comparison
    long oddSolutions[] = {5, 2, 32};
    vector<string> testOutcome;
    // Compare the test results with what we expect
    cout << "\n=======EVEN TEST : Test results=======" << endl;
    for (int i = 0; i < evenTestOperations.size(); i++) {
        if (get<1>(evenTestOperations[i]) == oddSolutions[i]) {
            testOutcome.emplace_back("PASSED");
        } else {
            testOutcome.emplace_back("FAILED");
        }
    }
    printResults(evenTestOperations,oddSolutions, testOutcome);
}

void testOneLenArray()
{
    // Creating the data
    vector<vector<int>> onelenData;
    onelenData = onelenArray();

    // Storing the data in a csv
    string onelenInputStr = "testOneLenInput.csv";
    createCsv2D(onelenInputStr, onelenData);

    // Run the algorithms on the odd length array
    MedianOperationsVector onelenTestOperations;
    MedianTimeVector onelenTestExecutionTime;

    for (auto &row : onelenData) {
        onelenTestOperations.push_back(BruteForceMedianOperations(row));
        onelenTestExecutionTime.push_back(BruteForceMedianTime(row));
    }
    // Store the results in an output csv
    string onelenTestStr = "testOneLenOutput.csv";
    createCsvOutput(onelenTestStr, onelenTestOperations, onelenTestExecutionTime);

    // Print the results to the console
    cout << "=======ONE LENGTH TEST : Input values=======" << endl;
    print2D(onelenData);
    cout << "\n=======ONE LENGTH TEST : Output values=======" << endl;
    printOutput(onelenTestOperations, onelenTestExecutionTime);

    // Printing the results of the comparison
    long oddSolutions[] = {1, 1000, -300};
    vector<string> testOutcome;
    // Compare the test results with what we expect
    cout << "\n=======ONE LENGTH : Test results=======" << endl;
    for (int i = 0; i < onelenTestOperations.size(); i++) {
        if (get<1>(onelenTestOperations[i]) == oddSolutions[i]) {
            testOutcome.emplace_back("PASSED");
        } else {
            testOutcome.emplace_back("FAILED");
        }
    }
    printResults(onelenTestOperations,oddSolutions, testOutcome);
}

void testRandArray(int numArray,int numSims)
{
    // Creating the data
    vector<vector<vector<int>>> randData;
    randData = randArray(numSims, numArray);

    // Storing the data in a csv
    string randInputStr = "testRandInput.csv";
    createCsv3D(randInputStr, randData);

    // Run the algorithms on the odd length array
    MedianOperationsVector randTestOperations;
    MedianTimeVector randTestExecutionTime;

    for (auto &row : randData) {
        for(auto &col : row)
        {
            randTestOperations.push_back(BruteForceMedianOperations(col));
            randTestExecutionTime.push_back(BruteForceMedianTime(col));
        }
    }
    // Store the results in an output csv
    string randTestStr = "testRandOutput.csv";
    createCsvOutput(randTestStr, randTestOperations, randTestExecutionTime);

    // Print the results to the console
    cout << "=======RANDOM ARRAY TEST : Input values=======" << endl;
    print3D(randData);
    cout << "\n=======RANDOM ARRAY TEST : Output values=======" << endl;
    printOutput(randTestOperations, randTestExecutionTime);
//
//    // Printing the results of the comparison
//    long oddSolutions[] = {1, 1000, -300};
//
//    vector<string> testOutcome;
//    // Compare the test results with what we expect
//    cout << "\n=======ONE LENGTH : Test results=======" << endl;
//    for (int i = 0; i < randTestOperations.size(); i++) {
//        if (get<1>(randTestOperations[i]) == oddSolutions[i]) {
//            testOutcome.emplace_back("PASSED");
//        } else {
//            testOutcome.emplace_back("FAILED");
//        }
//    }
//    printResults(randTestOperations,oddSolutions, testOutcome);
}


