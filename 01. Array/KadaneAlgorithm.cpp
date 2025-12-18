#include <iostream>
#include <algorithm>  // for std::max
#include <climits>    // for INT_MIN

int main()
{
    int nums[] = {1, 2, 3, 4, 6, 7, 9};
    int currSum = 0;
    int maxSum = INT_MIN;

    for (int val : nums)
    {
        currSum += val;
        maxSum = std::max(currSum, maxSum);

        if (currSum < 0)
        {
            currSum = 0;
        }
    }

    std::cout << "Maximum subarray sum: " << maxSum << std::endl;
    return 0;
}
