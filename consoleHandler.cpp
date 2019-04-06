//
// Created by Jez Dufourq on 2019-04-06.
//
#include <iomanip>
using namespace std;

void print3D(vector<vector<vector<int>>> const &input);
void print2D(vector<vector<int>> const &input);
void print(vector<int> const &input);
void printOutput(vector<tuple<long,long,long>> const &algoOp, vector<tuple<long,long,float>>const &algoTime);
void printResults(vector<tuple<long,long, long>> results, long solutions, vector<bool> outcome);

void print3D(vector<vector<vector<int>>> const &input)
{
    // Auto in this case is used to cut down on writing vector each time
    // Auto is implemented when the program is built
    // It sets the input value automatically to a vector value
    // TODO: Need to research this.
    for(auto &row: input) {
        cout << "," << endl;
        for (auto &col: row) {
            cout << "[";
            for (auto &depth: col) {
                cout << depth << ",";
            }
            cout << "]" << endl;
        }
    }
}

void print2D(vector<vector<int>> const &input)
{
    // Auto in this case is used to cut down on writing vector each time
    // Auto is implemented when the program is built
    // It sets the input value automatically to a vector value
    // TODO: Need to research this.
    int i = 0;
    cout << "| TestNumber | InputArray                                                   |" << endl;
    cout << "|------------|--------------------------------------------------------------|" << endl;
    for (auto &row: input)
    {
        cout << "| " << i << setfill(' ') << setw(12) << "| " << "{";
        for (auto col: row) {
            cout << col << ",";
        }
        i++;

        cout << "}" << endl;
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
        cout << v << ",";
    }
    cout <<  "]" << endl;
}

void printOutput(vector<tuple<long,long,long>> const &algoOp, vector<tuple<long,long,float>>const &algoTime)
{
    cout << "| TestNumber | ArrayLength | MedianValue | NumberOperations | ExecutionTime |"<< endl;
    cout << "|------------|-------------|-------------|------------------|---------------|"<< endl;
    cout << setprecision(-2);
    for (int i = 0; i < algoOp.size(); i++)
    {
        cout << "| " << i << setfill(' ') <<setw(11) << "|";
        cout << get<0>(algoOp[i]) << setfill(' ') << setw(13) << "|";
        cout << get<1>(algoOp[i]) << setfill(' ') << setw(13) << "|";
        cout << get<2>(algoOp[i]) << setfill(' ') << setw(17) << "|";
        cout << get<2>(algoTime[i]) << endl;
    }
}

void printResults(vector<tuple<long,long, long>> results, long *solutions, vector<string> outcome)
{
    cout << "| TestNumber | MedianOutput | ExpectedValue | TestOutcome |" << endl;
    cout << "|------------|--------------|---------------|-------------|" << endl;
    for (int i = 0; i < results.size(); i++)
    {
        cout << "| " << i << setw(12);
        cout << " | " << get<1>(results[i]) << setw(14);
        cout << " | " << solutions[i] << setw(15);
        cout << " | " << outcome[i] << endl;
    }
    cout << "\n" << endl;
}


