#include <iostream>
#include <vector>
using namespace std;

vector<int> moveZeroToEnd(vector<int> a, int n)
{
    int j = -1;

    for (int i = 0; i < n; ++i)
    {
        if (a[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
        return a;

    for (int i = j + 1; i < n; ++i)
    {
        if (a[i] != 0)
        {
            swap(a[i], a[j]);
            j++;
        }
    }
    return a;
}

int main()
{
    vector<int> a{1, 2, 0, 2, 6, 8, 0, 4, 0, 0, 0, 5, 3, 0};
    int n = a.size();
    vector<int> result = moveZeroToEnd(a, n);
    for (int val : result)
    {
        cout << val << " ";
    }

    return 0;
}