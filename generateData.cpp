using namespace std;
#include "generateData.h"

vector<vector<int>> generateArray(unsigned long numSims, TEST_TYPE type) {
    vector<vector<int>> outputArray;
    vector<int> innerArray;
    unsigned int Count = 0;
    int random;

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
            for(int i = 0; i < (numSims + 1); i++)
            {
                Count+=ARRAY_STEP_SIZE;
                for(int j = 0;j < ARRAY_NUM_SIMS; j++)
                {
                    for (int k = 0; k < Count; k++)
                    {
                        random = rand() % RANDOM_RANGE;
                        innerArray[k] = random;
                    }
                    outputArray[j] = innerArray;
                }
            }
            break;
        case REVERSED:
            for(int i = 0; i < (numSims + 1); i++)
            {
                Count+=ARRAY_STEP_SIZE;
                for(int j = 0;j < ARRAY_NUM_SIMS; j++)
                {
                    for (int k = 0; k < Count; k++)
                    {
                        innerArray[k] = (int) (Count - k - 1);
                    }
                    outputArray[j] = innerArray;
                }
            }
            break;
        case SORTED:
            for(int i = 0; i < (numSims + 1); i++)
            {
                Count+=ARRAY_STEP_SIZE;
                for(int j = 0;j < ARRAY_NUM_SIMS; j++)
                {
                    for (int k = 0; k < Count; k++)
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