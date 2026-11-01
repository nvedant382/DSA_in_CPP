#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void rotateLeftByOne(int arr[], int n)
{
    int temp = arr[0];

    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }

    arr[n - 1] = temp;
}

void rotateLeftByK(int arr[], int n, int k)
{
    k = k % n;
    vector<int> temp;

    for (int i = 0; i < k; i++)
    {
        temp.push_back(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        arr[i - k] = arr[i];
    }

    for (int i = n - k; i < n; i++)
    {
        arr[i] = temp[i - (n - k)];
    }
}

void rotateLeftByK_opt(int arr[], int n, int k)
{
    k = k % n;
    reverse(arr, arr + k);
    reverse(arr + k, arr + n);
    reverse(arr, arr + n);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int arr2[] = {1, 2, 3, 4, 5, 6, 7};

    rotateLeftByOne(arr, 7);

    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    rotateLeftByK(arr2, 7, 3);

    for (int i = 0; i < 7; i++)
    {
        cout << arr2[i] << " ";
    }

    return 0;
}