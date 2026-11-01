#include <iostream>
#include <vector>
using namespace std;

int f(int n)
{ // time = O(2^N)  and  space = O(N) stack spa
    if (n <= 1)
        return n;
    return f(n - 1) + f(n - 2);
}

int f_dp(int n, vector<int> &dp)
{ // time = O(N)  and  space = O(N) + (N) stack space + array
    if (n <= 1)
        return n;

    if (dp[n] != -1)
        return dp[n];

    return dp[n] = f_dp(n - 1, dp) + f_dp(n - 2, dp);
}

int f_tab(int n)
{ // time = O(N)  and  space = O(N) array
    vector<int> dp(n + 1, -1);

    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int f_space_opt(int n)
{ // time = O(N)  and  space = O(1)
    int prev2 = 0;
    int prev1 = 1;
    int curr;

    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

int main()
{
    int n;
    cin >> n;
    cout << f(n) << endl;

    vector<int> dp(n + 1, -1);
    cout << f_dp(n, dp) << endl; // memoization

    cout << f_tab(n) << endl; // tabulation

    cout << f_space_opt(n) << endl; // space-optimized
    return 0;
}