#include <iostream>
#include <vector>
using namespace std;
// T.C. = O(N * log2 N)
// S.C. = O(N)
void merge(int arr[], int low, int mid, int high)
{
    vector<int> temp;

    int left = low;      // [low....mid]
    int right = mid + 1; // [mid+1....high]

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // right array exhausted
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    // left array exhausted
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int arr[], int low, int high)
{
    if (low == high) // atomic value
        return;

    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
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

    mergeSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}