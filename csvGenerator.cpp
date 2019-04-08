#include <iostream>
#include <fstream>

using namespace std;

ofstream csvExporter;
csvExporter.open("timings.csv");
for (int k = TEST_TYPE::SORTED; k <= TEST_TYPE::RANDOMIZED; k++) {
    switch(k) {
        case TEST_TYPE::SORTED:
            csvExporter << "SORTED,time" << std::endl;
            break;
        case TEST_TYPE::REVERSED:
            csvExporter << "REVERSED,time" << std::endl;
            break;
        case TEST_TYPE::RANDOMIZED:
            csvExporter << "RANDOMIZED,time" << std::endl;
            break;
        default:break;
}
for (int i = 1; i <= 10000; i += (10000 * TEST_COUNT) / (255)) {
    for (int j = 0; j < TEST_COUNT; j++) {
        testVector = generateArray((unsigned long) i, (TEST_TYPE) k);
        clock_t start = clock();
        runMethod(testVector);
        double duration = (std::clock() - start) / (CLOCKS_PER_SEC / 1000.0);
        csvExporter << i << "," << duration << std::endl;
            }
        }
    }
csvExporter.close();
}