#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int maxConsecutiveOne(vector<int> a, int n)
{
    int cnt = 0;
    int maxOne = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 1)
        {
            cnt++;
            maxOne = max(maxOne, cnt);
        }
        else
        {
            cnt = 0;
        }
    }
    return maxOne;
}

int main()
{

    vector<int> nums{1, 1, 0, 1, 1, 1};
    int n = nums.size();
    int result = maxConsecutiveOne(nums, n);
    cout << result << "\n";
}