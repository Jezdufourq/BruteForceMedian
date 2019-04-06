//
// Created by Jez Dufourq on 2019-04-06.
//
void print3D(vector<vector<vector<int>>> const &input);
void print2D(vector<vector<int>> const &input);
void print(vector<int> const &input);

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
    for (auto &row: input)
    {
        for (auto col: row) {
            cout << col;
        }
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
