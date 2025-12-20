#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int> &arr, int n)
{
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            arr[i + 1] = arr[j];
            i++;
        }
    }
    return i + 1;
}

int main()
{
    vector<int> arr{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int n=arr.size();
    cout << removeDuplicates(arr, n) << "\n";
}