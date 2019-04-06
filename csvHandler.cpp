////
//// Created by Jez Dufourq on 2019-04-06.
////
using namespace std;
using namespace std::chrono;


void createCsv3D(string &fileName, vector<vector<vector<int>>> const &input);
void createCsv2D(string &fileName, vector<vector<int>> const &input);
void createCsv1D(string &fileName, vector<int> const &input);

void createCsv3D(string &fileName, vector<vector<vector<int>>> const &input)
{
    ofstream newFile;
    newFile.open(fileName);
    for(auto &row: input) {
        for (auto &col: row) {
            for (auto &depth: col) {
                newFile << depth << ",";
            }
            newFile << "," << endl;
        }
    }
    newFile.close();
}

void createCsv2D(string &fileName, vector<vector<int>> const &input)
{
    ofstream newFile;
    newFile.open(fileName);
    for (auto &row: input) {
        for (auto &col: row) {
            newFile << col << ",";
        }
        newFile << "," << endl;
    }
    newFile.close();
}

void createCsv1D(string &fileName, vector<int> const &input)
{
    ofstream newFile;
    newFile.open(fileName);

    for (auto &col: input) {
        newFile << col << ",";
    }
    newFile << "," << endl;
    newFile.close();
}
