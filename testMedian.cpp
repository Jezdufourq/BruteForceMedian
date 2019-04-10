using namespace std;

// sourced from - https://stackoverflow.com/questions/2114797/compute-median-of-values-stored-in-vector-c/2114817#2114817

double testMedian(vector<int> &input)
{
    vector<int> sortedVect(input);
    sort(sortedVect.begin(), sortedVect.end());

    size_t size = sortedVect.size();
    if(size == 0)
    {
        return 0;
    }else{
        sort(input.begin(), input.end());
        return size % 2 == 0 ? ceil((input[size / 2.0 - 1] + input[size / 2.0]) / 2.0) : input[size / 2];
        // Shorthand for this:
//        if(size % 2 == 0) // Testing for the even array case
//        {
//            return ceil((input[size/2.0-1]+input[size/2.0])/2.0);
//        }else{
//            return input[size/2];
//        }
    }
}