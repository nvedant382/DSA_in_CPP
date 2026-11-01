#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

vector<int> findLeaders(vector<int> arr, int n)
{
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        bool isLeader = true;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                isLeader = false;
                break;
            }
        }

        if (isLeader)
        {
            ans.push_back(arr[i]);
        }
    }

    return ans;
}

vector<int> findLeaders_opt(vector<int> arr, int n)
{
    vector<int> ans;
    int maxi = INT_MIN;

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > maxi)
        {
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> arr = {10, 22, 12, 3, 0, 6};
    vector<int> ans = findLeaders_opt(arr, arr.size());

    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}