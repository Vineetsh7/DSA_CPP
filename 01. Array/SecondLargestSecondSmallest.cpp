#include <iostream>
#include <vector>
using namespace std;

int secondLargest(vector<int> &a, int n)
{
    int largest = INT_MIN;
    int sLargest = INT_MIN;
    for (int i{}; i < n; ++i)
    {
        if (a[i] > largest)
        {
            sLargest = largest;
            largest = a[i];
        }
        else if (a[i] < largest && a[i] > sLargest)

        {
            sLargest = a[i];
        }
    }
    return sLargest;
}

int secondSmallest(vector<int> &a, int n)
{
    int smallest = INT_MAX;
    int sSmallest = INT_MAX;
    for (int i{}; i < n; ++i)
    {
        if (a[i] < smallest)
        {
            sSmallest = smallest;
            smallest = a[i];
        }
        else if (a[i] > smallest && a[i] < sSmallest)
        {
            sSmallest = a[i];
        }
    }
    return sSmallest;
}

int main()
{

    vector<int> a{8, 6, 7, 1, 2, 9, 3};
    int n = a.size();
    cout << secondLargest(a, n) << "\n";
    cout << secondSmallest(a, n) << "\n";
    return 0;
}