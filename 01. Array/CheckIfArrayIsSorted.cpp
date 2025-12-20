#include <iostream>
#include <vector>
using namespace std;

bool isArraySorted(vector<int> &a, int n)
{

    for (int i = 1; i < n; ++i)
    {
        if (a[i] >= a[i - 1])
        {
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cout << boolalpha;
    vector<int> a{1, 2, 3, 4, 6};
    int n = a.size();
    cout << isArraySorted(a, n) << "\n";
}