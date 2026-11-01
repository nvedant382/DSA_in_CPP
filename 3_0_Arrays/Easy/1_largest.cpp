#include <iostream>
using namespace std;

int printLargest(int arr[], int n)
{
    int largest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}

int main()
{
    int arr[] = {2, 5, 1, 3, 7, 4};

    cout << printLargest(arr, 6) << endl;

    return 0;
}