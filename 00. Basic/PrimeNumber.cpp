#include <iostream>
using namespace std;

int main()
{
    cout << boolalpha;
    int n;
    cin >> n;
    if (n <= 0)
    {
        cout << false;
    }
    if (n == 1)
    {
        cout << true;
    }
    int cnt = 0;
    for (int i = 2; i <= n; ++i)
    {
        if ((n % i) == 0)
        {
            cnt++;
        }
    }
    if (cnt >= 2)
    {
        cout << false;
    }
    else
    {
        cout << true;
    }
}