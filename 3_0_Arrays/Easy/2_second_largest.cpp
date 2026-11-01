#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> findLargestAndSecondLargest(vector<int> arr, int n)
{
    int largest = arr[0];
    int s_largest = INT_MIN;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
        {
            s_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest && arr[i] > s_largest)
        {
            s_largest = arr[i];
        }
    }

    return {largest, s_largest};
}
// 5 2 4 1
vector<int> findSmallestAndSecondSmallest(vector<int> arr, int n)
{
    int smallest = arr[0];
    int s_smallest = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < smallest)
        {
            s_smallest = smallest;
            smallest = arr[i];
        }
        else if (arr[i] > smallest && arr[i] < s_smallest)
        {
            s_smallest = arr[i];
        }
    }

    return {smallest, s_smallest};
}

int main()
{
    vector<int> arr = {2, 5, 1, 3, 7, 4};

    vector<int> ans = findLargestAndSecondLargest(arr, arr.size());

    for (auto it : ans)
    {
        cout << it << " ";
    }

    vector<int> ans2 = findSmallestAndSecondSmallest(arr, arr.size());

    for (auto it : ans2)
    {
        cout << it << " ";
    }

    return 0;
}