#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> twoSum(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (arr[i] + arr[j] == target)
            {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

vector<int> twoSum_better(int arr[], int n, int target)
{
    map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        int more = target - arr[i];
        if (mpp.find(more) != mpp.end())
        {
            return {mpp[more], i};
        }
        mpp[arr[i]] = i;
    }

    return {-1, -1};
}

// Variety - 2
string twoSum_v2(vector<int> arr, int n, int target)
{
    sort(arr.begin(), arr.end());

    int left = 0, right = n - 1;

    while (left < right)
    {
        int sum = arr[left] + arr[right];
        if (sum == target)
        {
            return "YES";
        }
        else if (sum > target)
            right--;
        else
            left++;
    }

    return "NO";
}

int main()
{
    int arr[] = {2, 6, 5, 8, 11};
    vector<int> ans = twoSum(arr, 5, 13);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    vector<int> ans2 = twoSum(arr, 5, 13);
    for (auto it : ans2)
    {
        cout << it << " ";
    }

    vector<int> arr2 = {2, 6, 5, 11, 8};
    cout << twoSum_v2(arr2, 5, 13) << endl;

    return 0;
}