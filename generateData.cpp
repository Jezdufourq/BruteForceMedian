using namespace std;
#include "generateData.h"

vector<vector<int>> generateArray(unsigned long numSims, TEST_TYPE type) {
    vector<vector<int>> outputArray;
    vector<int> innerArray;

    switch (type) {
        case ODD:
            for (int i = 0; i < numSims; i++)
            {
                for (int j = 1; j < (i*2)+2; j++)
                {
                    innerArray[j] = j;
                }
                outputArray[i] = innerArray;
                innerArray.clear();
            }
            break;
        case EVEN:
            for (int i = 0; i < numSims; i++)
            {
                for (int j = 1; j < (i*2)+1; j++)
                {
                    innerArray[j] = j;
                }
                outputArray[i] = innerArray;
                innerArray.clear();
            }
            break;
        case LARGE:
            for (int i = 0; i < numSims; i++)
            {
                for (int j = 1; j < LARGE_ARRAY_VALUE; j++)
                {
                    innerArray[j] = j;
                }
                outputArray[i] = innerArray;
                innerArray.clear();
            }
            break;
        case ONELEN:
            for (int i = 0; i < numSims; i++)
            {
                for (int j = 1; j <= 1; j++)
                {
                    innerArray[j] = j;
                }
                outputArray[i] = innerArray;
                innerArray.clear();
            }
            break;
        case RANDOM:
            unsigned int randCount = 0;
            int random;
            for(int i = 0; i < (numSims + 1); i++)
            {
                randCount+=ARRAY_STEP_SIZE;
                for(int j = 0;j < ARRAY_NUM_SIMS; j++)
                {
                    for (int k = 0; k < randCount; k++)
                    {
                        random = rand() % RANDOM_RANGE;
                        innerArray[k] = random;
                    }
                    outputArray[j] = innerArray;
                }
            }
            break;
        case REVERSED:
            unsigned int revCount = 0;
            for(int i = 0; i < (numSims + 1); i++)
            {
                revCount+=ARRAY_STEP_SIZE;
                for(int j = 0;j < ARRAY_NUM_SIMS; j++)
                {
                    for (int k = 0; k < revCount; k++)
                    {
                        innerArray[k] = (int) (revCount - k - 1);
                    }
                    outputArray[j] = innerArray;
                }
            }
            break;
        case SORTED:
            unsigned int sortCount = 0;
            for(int i = 0; i < (numSims + 1); i++)
            {
                sortCount+=ARRAY_STEP_SIZE;
                for(int j = 0;j < ARRAY_NUM_SIMS; j++)
                {
                    for (int k = 0; k < sortCount; k++)
                    {
                        innerArray[k] = k;
                    }
                    outputArray[j] = innerArray;
                }
            }
            break;
    }
    return outputArray;
}