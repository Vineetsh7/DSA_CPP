#include <iostream>
#include <vector>

using namespace std;

int missingNumber(vector<int> &a, int N)
{
    int xor1 = 0, xor2 = 0;
    int n = N - 1;
    for (int i = 0; i < n; i++)
    {
        xor2 = xor2 ^ a[i];
        xor1 = xor1 ^ (i + 1);
    }
    return xor1 ^ xor2;
}

int main()
{
    vector<int> a{0, 1};
    int N = 2;

    int result = missingNumber(a, N);
    cout << result;

    return 0;
}