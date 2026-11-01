#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int fun(int idx, vector<int> &arr, vector<int> &dp)
{
    if (idx == 0)
        return 0;
    if (dp[idx] != -1)
        return dp[idx];

    int left = fun(idx - 1, arr, dp) + abs(arr[idx] - arr[idx - 1]);
    int right = INT_MAX;

    if (idx > 1)
        right = fun(idx - 2, arr, dp) + abs(arr[idx] - arr[idx - 2]);

    return dp[idx] = min(left, right);
}

int fun_tabu(int idx, vector<int> &arr)
{
    vector<int> dp(arr.size() + 1, -1);

    dp[0] = 0;

    for (int i = 1; i <= arr.size() - 1; i++)
    {
        int left = dp[i - 1] + abs(arr[i] - arr[i - 1]);
        int right = INT_MAX;

        if (idx > 1)
            right = dp[i - 2] + abs(arr[i] - arr[i - 2]);

        dp[i] = min(left, right);
    }

    return dp[idx];
}

int fun_space_opt(int idx, vector<int> &arr)
{
    int prev1 = 0, prev2 = 0, curr;

    for (int i = 1; i < arr.size(); i++)
    {
        int left = prev1 + abs(arr[i] - arr[i - 1]);
        int right = INT_MAX;

        if (idx > 1)
            right = prev2 + abs(arr[i] - arr[i - 2]);

        curr = min(left, right);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    vector<int> arr = {30, 10, 60, 10, 60, 50}; // 30->60->60->50
    int n = arr.size();
    vector<int> dp(n + 1, -1);
    cout << fun(n - 1, arr, dp) << endl;
    cout << fun_tabu(n - 1, arr) << endl;
    cout << fun_space_opt(n - 1, arr) << endl;
    return 0;
}