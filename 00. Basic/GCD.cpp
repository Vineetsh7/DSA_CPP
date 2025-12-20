#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    while (a > 0 && b > 0)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }

    if (a == 0)
        cout << b;
    else
        cout << a;

    return 0;

    /*
        int n1, n2;
        cin >> n1 >> n2;

        int gcd = 1;
        for (int i = min(n1, n2); i >= 1; --i)
        {
            if (n1 % i == 0 && n2 % i == 0)
            {
                gcd = i;
                break;
            }
        }
        cout << gcd;

    */
    /*
        int n1, n2;
        cin >> n1 >> n2;
        vector<int> vec1;
        vector<int> vec2;

        for (int i = 1, j = 1; i <= sqrt(n1), j <= sqrt(n2); ++i, ++j)
        {
            if (n1 % i == 0)
            {
                vec1.push_back(i);
                if ((n1 / i) != i)
                {
                    vec1.push_back(n1 / i);
                }
            }
            if (n2 % j == 0)
            {
                vec2.push_back(j);
                if ((n2 / j) != j)
                {
                    vec2.push_back(n2 / j);
                }
            }
        }
        sort(vec1.begin(), vec1.end());
        sort(vec2.begin(), vec2.end());

        for (int val1 : vec1)
        {
            cout << val1 << " ";
        }
        cout << endl;
        for (int val2 : vec2)
        {
            cout << val2 << " ";
        }


    */

    return 0;
}