#include <iostream>
using namespace std;
// T.C. = O(N^2) worst case
// best case : O(N) if array is already sorted
void sort(int arr[], int n)
{
    int didSwap = 0;
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didSwap = 1;
            }
        }

        if (didSwap == 0)
        {
            break;
        }
        cout << "Runs" << endl;
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}