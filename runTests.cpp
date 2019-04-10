using namespace std::chrono;


void runTests(TEST_TYPE test,  PROGRAM_TYPE program)
{
    // Defining the input and the output vector
    vector<vector<int>> inputVector;
    vector<double> algoMedianVector;
    vector<double> actualMedianVector;
    vector<unsigned long long> numOpsVector;
    vector<double> execTimeVector;
    vector<int> arrayLength;
    clock_t startTime, endTime;
    std::chrono::steady_clock::time_point begin;
    std::chrono::steady_clock::time_point end;



    // Creating the input vector
    inputVector = generateArray(SIMULATIONS, test);
    createInputCsv(inputVector, test);

    for (int i = 0; i < inputVector.size(); i++)
    {
        arrayLength.push_back(inputVector[i].size());
    }

    // Printing the input vector to the console - Checks to see if the user wants to print to the console
//    if(INPUT_PRINT)
//    {
//        cout << "=========INPUT DATA=========\n" << endl;
//        printConsoleInput(inputVector, test);
//    }

    // Creating the output vector - Running the simulation
    switch(program) {
        case FUNCTIONALITY:
            for (auto &col : inputVector) // For the length of the input vector, run the test
            {
                // Running the tests, storing the results in a vector to compare
                algoMedianVector.push_back(BruteForceMedian(col));
                actualMedianVector.push_back(testMedian(col));
            }
            // Comparing the results and printing to the console
            cout << "========FUNCTIONALITY TESTING RESULTS========" << endl;
            cout << "=====THIS IS THE TEST (" << test << ")=====" << endl;
            printConsoleFunctionality(actualMedianVector, algoMedianVector, arrayLength);
            // Saving the results to a csv file
            createOutputCsvFunc(arrayLength, algoMedianVector, actualMedianVector, test);
            break;
        case OPERATIONS:
            for (auto &col : inputVector) {
                algoMedianVector.push_back(BruteForceMedian(col));
                numOpsVector.push_back(numOp);
            }
            // Comparing the results and printing to the console
            cout << "========OPERATION TESTING RESULTS========" << endl;
            cout << "=====THIS IS THE TEST (" << test << ")=====" << endl;
            printConsoleOperations(numOpsVector, algoMedianVector, arrayLength);
            // Saving the results to a csv file
            createOutputCsvOps(arrayLength, algoMedianVector, numOpsVector, test);
            break;
        case TIMING:
            for (auto &col : inputVector)
            {
                cout << "TestArraySize: "<< col.size() << endl;
                begin = std::chrono::steady_clock::now();
                algoMedianVector.push_back(BruteForceMedianTime(col));

                end= std::chrono::steady_clock::now();
                double elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
                execTimeVector.push_back(elapsed);
            }

//                Count+=ARRAY_STEP_SIZE;
//                for (int j =0; j < ARRAY_NUM_SIMS; j++)
//                {
//                    algoMedianVector.push_back(BruteForceMedianTime(inputVector[j]));
//                    execTimeVector.push_back(execTime);
            cout << "========TIMING TESTING RESULTS========" << endl;
            cout << "=====THIS IS THE TEST (" << test << ")=====" << endl;
            cout << inputVector.size() << endl;
//            printConsoleTiming(execTimeVector,algoMedianVector,arrayLength);
            // Saving the results to a csv file
            createOutputCsvTiming(arrayLength, algoMedianVector, execTimeVector, test);
            break;
        default:break;
    }
}