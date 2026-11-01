#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int fun(int i, vector<int> &arr, int k, vector<int> &dp)
{
    if (i == 0)
        return 0;
    if (dp[i] != -1)
        return dp[i];

    int minSteps = INT_MAX;

    for (int j = 1; j <= k; j++)
    {
        if (i - j >= 0)
        {
            int jump_energy = fun(i - j, arr, k, dp) + abs(arr[i] - arr[i - j]);
            minSteps = min(minSteps, jump_energy);
        }
    }

    return dp[i] = minSteps;
}

int fun_tabu(vector<int> &arr, int k)
{
    vector<int> dp(arr.size() + 1, 0);

    dp[0] = 0;

    for (int i = 1; i < arr.size(); i++)
    {
        int minSteps = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jumps = dp[i - j] + abs(arr[i] - arr[i - j]);
                minSteps = min(minSteps, jumps);
            }
        }
        dp[i] = minSteps;
    }

    return dp[arr.size() - 1];
}

int main()
{
    vector<int> arr = {30, 10, 60, 10, 60, 50};
    int n = arr.size();
    int k = 4;
    vector<int> dp(n, -1);
    cout << fun(n - 1, arr, k, dp) << endl;
    cout << fun_tabu(arr, k) << endl;
    return 0;
}
