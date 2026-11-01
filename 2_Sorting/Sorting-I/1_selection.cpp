#include <iostream>
using namespace std;

void sort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int min = i; // current element is defined as minimum
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        // swap minimum element in unsorted part(min) with current(i) element
        swap(arr[i], arr[min]);
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