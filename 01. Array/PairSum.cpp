#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> pairSum(std::vector<int> nums, int target)
{
    std::sort(nums.begin(), nums.end());
    std::vector<int> ans;
    int n = nums.size();
    int i=0,j=n-1;

    while (i < j)
    {
        int pairSum = nums[i] + nums[j];
        if (pairSum < target)
        {
            i++;
        }
        else if (pairSum > target)
        {
            j--;
        }
        else
        {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    return ans;
}

int main()
{

    std::vector<int> nums{3,2,4};
    int target=6;

    std::vector<int> ans = pairSum(nums, target);
    std::cout << ans[0] << " " << ans[1] << std::endl;

    return 0;
}