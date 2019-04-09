using namespace std;
#include <iomanip>

void printConsoleInput(vector<vector<int>> const &input, TEST_TYPE test)
{
    switch(test)
    {
        case ODD:
            cout << setfill('=') << setw(20) << "ODD TEST INPUT" << setw(20) << endl;
            break;
        case EVEN:
            cout << setfill('=') << setw(20) << "EVEN TEST INPUT" << setw(20) << endl;
            break;
        case LARGE:
            cout << setfill('=') << setw(20) << "LARGE TEST INPUT" << setw(20) << endl;
            break;
        case ONELEN:
            cout << setfill('=') << setw(20) << "ONELENGTH TEST INPUT" << setw(20) << endl;
            break;
        case RANDOM:
            cout << setfill('=') << setw(20) << "RANDOM TEST INPUT" << setw(20) << endl;
            break;
        case REVERSED:
            cout << setfill('=') << setw(20) << "REVERSED TEST INPUT" << setw(20) << endl;
            break;
        case SORTED:
            cout << setfill('=') << setw(20) << "SORTED TEST INPUT" << setw(20) << endl;
            break;
        default:break;
    }

    //TODO: Fix up the comma issue at the end of the input array when printing to the console.
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

