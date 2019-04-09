#include <iostream>
#include <fstream>
using namespace std;

void createCsv(vector<vector<int>> const &input, TEST_TYPE testType)
{
    ofstream outputFile;
    switch(testType)
    {
        case ODD:
            outputFile.open("ODD_TEST_INPUT.csv");
            break;
        case EVEN:
            outputFile.open("EVEN_TEST_INPUT.csv");
            break;
        case LARGE:
            outputFile.open("LARGE_TEST_INPUT.csv");
            break;
        case ONELEN:
            outputFile.open("ONELEN_TEST_INPUT.csv");
            break;
        case RANDOM:
            outputFile.open("RAND_TEST_INPUT.csv");
            break;
        case REVERSED:
            outputFile.open("REV_TEST_INPUT.csv");
            break;
        case SORTED:
            outputFile.open("SORTED_TEST_INPUT.csv");
            break;
        default:break;
    }
    outputFile << "TestNumber, InputArray," << endl;
    int i = 0;
    for (auto &row: input) {
        outputFile << i << ",";
        for (auto &col: row) {
            outputFile << col << ",";
        }
        outputFile << "," << endl;
        i++;
    }
    outputFile.close();
}
