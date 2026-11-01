#include <iostream>
#include <vector>
using namespace std;

int func(int n)
{
    if (n == 0 || n == 1)
        return 1;
    if (n < 0)
        return 0;

    return func(n - 1) + func(n - 2);
}

int func_memo(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
        return 1;
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = func_memo(n - 1, dp) + func_memo(n - 2, dp);
}

int func_tabulation(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int func_space_opt(int n)
{
    int prev2 = 1;
    int prev1 = 1, curr = 0;

    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main()
{
    int n;
    cin >> n;
    cout << func(n) << endl;

    vector<int> dp(n + 1, -1);
    cout << func_memo(n, dp) << endl;

    cout << func_tabulation(n) << endl;

    cout << func_space_opt(n) << endl;
    return 0;
}