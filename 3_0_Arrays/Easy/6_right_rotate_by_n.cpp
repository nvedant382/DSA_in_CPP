#include <iostream>
#include <vector>
using namespace std;

void rotateRightByOne(int arr[], int n)
{
    int temp = arr[n - 1];

    for (int i = n - 2; i >= 0; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[0] = temp;
}

void rotateRightByK(int arr[], int n, int k)
{
    k = k % n;
    vector<int> temp;
    // Storing
    for (int i = n - k; i < n; i++)
    {
        temp.push_back(arr[i]);
    }

    // Shifting
    for (int i = n - k - 1; i >= 0; i--)
    {
        arr[i + k] = arr[i];
    }

    // Adjusting to Right Position
    for (int i = 0; i < k; i++)
    {
        arr[i] = temp[i];
    }
}

/*

for optimal:
1) reverse Entire array
2) reverse 1st k elements
3) reverse n-k elements
*/

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    rotateRightByK(arr, 7, 3);

    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;

    return 0;
}