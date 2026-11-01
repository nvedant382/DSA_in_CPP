#include <iostream>
#include <vector>
using namespace std;

int maxSumOfNonAdjacent(int idx, vector<int> &arr)
{
    if (idx == 0)
        return arr[idx];

    if (idx < 0)
        return 0;

    int pick = arr[idx] + maxSumOfNonAdjacent(idx - 2, arr);
    int not_pick = 0 + maxSumOfNonAdjacent(idx - 1, arr);

    return max(pick, not_pick);
}

int maxSumOfNonAdjacent_memo(int idx, vector<int> &arr, vector<int> &dp)
{
    if (idx == 0)
        return arr[idx];

    if (idx < 0)
        return 0;

    if (dp[idx] != -1)
        return dp[idx];

    int pick = arr[idx] + maxSumOfNonAdjacent_memo(idx - 2, arr, dp);
    int not_pick = 0 + maxSumOfNonAdjacent_memo(idx - 1, arr, dp);

    return dp[idx] = max(pick, not_pick);
}

int maxSumOfNonAdjacent_tabu(int n, vector<int> &arr)
{
    vector<int> dp(n , 0);
    dp[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        int take = arr[i];
        if (i > 1)
            take += dp[i - 2];

        int not_take = 0 + dp[i - 1];

        dp[i] = max(take, not_take);
    }

    return dp[n-1];
}

int maxSumOfNonAdjacent_space_optmize(int n, vector<int> &arr)
{
    int curr, prev1 = arr[0], prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int take = arr[i];
        if (i > 1)
            take += prev2;

        int not_take = 0 + prev1;

        curr = max(take, not_take);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    vector<int> arr = {2, 1, 4, 9};
    cout << maxSumOfNonAdjacent(arr.size() - 1, arr) << endl;

    vector<int> dp(arr.size() + 1, -1);
    cout << maxSumOfNonAdjacent_memo(arr.size() - 1, arr, dp) << endl;

    cout << maxSumOfNonAdjacent_tabu(arr.size(), arr) << endl;

    cout << maxSumOfNonAdjacent_space_optmize(arr.size(), arr) << endl;
    return 0;
}