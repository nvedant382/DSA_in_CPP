#include <iostream>
#include <vector>
using namespace std;

// int glo_cnt = 0;
int merge(vector<int> &arr, int low, int mid, int high)
{
    int cnt = 0;
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left++]);
        }
        else
        {
            // right is smaller
            temp.push_back(arr[right++]);
            cnt += (mid - left + 1);
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left++]);
    }

    while (right <= high)
    {
        temp.push_back(arr[right++]);
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low == high)
        return cnt;

    int mid = (low + high) / 2;

    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += merge(arr, low, mid, high);
    return cnt;
}

int main()
{
    vector<int> arr = {5, 3, 2, 4, 1};
    cout << mergeSort(arr, 0, arr.size() - 1) << endl;
    ;
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // cout << glo_cnt << endl;
    return 0;
}