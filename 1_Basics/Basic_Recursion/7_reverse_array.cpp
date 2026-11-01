#include <iostream>
using namespace std;

// one pointer
void f(int i, int arr[], int n)
{
    if (i >= n / 2)
        return;
    swap(arr[i], arr[n - i - 1]);
    f(i + 1, arr, n);
}

// 2 pointer
void f2(int left, int right, int arr[])
{
    if (left >= right)
        return;
    swap(arr[left], arr[right]);
    f2(left + 1, right - 1, arr);
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

    f(0, arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    f2(0, n - 1, arr);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}