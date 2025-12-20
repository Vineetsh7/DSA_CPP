#include <iostream>
#include <vector>
using namespace std;

vector<int> rotateArrayByOnePlace(vector<int> &arr, int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; ++i)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
    return arr;
}
int main()
{
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = arr.size();
    vector<int> result = rotateArrayByOnePlace(arr, n);
    for (int val : result)
    {
        cout << val << " ";
    }
}