#include <iostream>
using namespace std;

bool isSorted(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int arr2[] = {3, 5, 8, 10, 2, 1};

    cout << isSorted(arr, 5) << endl;
    cout << isSorted(arr2, 6) << endl;

    return 0;
}