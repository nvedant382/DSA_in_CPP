#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        int start = arr[i][0];
        int end = arr[i][1];

        if (!ans.empty() && end <= ans.back()[1])
        {
            // already in the interval (ans)
            continue;
        }

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j][0] <= end)
            {
                end = max(end, arr[j][1]);
            }
            else
            {

                break;
            }
        }
        ans.push_back({start, end});
    }

    return ans;
}

vector<vector<int>> mergeOverlappingIntervals_better(vector<vector<int>> &arr)
{
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 9}, {9, 11}, {8, 10}, {2, 4}, {15, 18}, {16, 17}};

    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    for (auto row : ans)
    {
        for (auto ele : row)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    vector<vector<int>> ans2 = mergeOverlappingIntervals_better(arr);
    for (auto row : ans2)
    {
        for (auto ele : row)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}