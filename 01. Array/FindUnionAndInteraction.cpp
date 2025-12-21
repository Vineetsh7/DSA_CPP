#include <iostream>
#include <vector>
using namespace std;

// Union Of the 2-Array
vector<int> findUnion(vector<int> a, vector<int> b, int n1, int n2)
{
    int i = 0;
    int j = 0;
    vector<int> unionArray;

    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            if (unionArray.size() == 0 || unionArray.back() != a[i])
            {
                unionArray.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (unionArray.size() == 0 || unionArray.back() != b[j])
            {
                unionArray.push_back(b[j]);
            }
            j++;
        }
    }

    while (j < n2)
    {
        if (unionArray.size() == 0 || unionArray.back() != b[j])
        {
            unionArray.push_back(b[j]);
        }
        j++;
    }
    while (i < n1)
    {
        if (unionArray.size() == 0 || unionArray.back() != a[i])
        {
            unionArray.push_back(a[i]);
        }

        i++;
    }
    return unionArray;
}

// Interaction of the 2-Array
vector<int> findIntersection(vector<int> a, vector<int> b, int n1, int n2)
{
    vector<int> intersection;
    int i = 0;
    int j = 0;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (b[j] < a[i])
        {
            j++;
        }
        else
        {
            intersection.push_back(a[i]);
            i++;
            j++;
        }
    }
    return intersection;
}
int main()
{
    vector<int> a{1, 1, 2, 3, 4, 5, 6};
    vector<int> b{2, 3, 4, 4, 5, 6, 6, 7};
    int n1 = a.size();
    int n2 = b.size();
    vector<int> result = findUnion(a, b, n1, n2);
    vector<int> result2 = findIntersection(a, b, n1, n2);
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
    for (int val : result2)
    {
        cout << val << " ";
    }
}