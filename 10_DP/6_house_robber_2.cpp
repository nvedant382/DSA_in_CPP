#include <iostream>
#include <vector>
using namespace std;

int f(int start, int end, vector<int> &arr)
{
    int len = (end - start) + 1;
    vector<int> dp(len, 0);
    dp[0] = arr[start];

    for (int i = 1; i < len; i++)
    {
        int j = i + start;
        int take = arr[j];
        if (i > 1)
            take += dp[i - 2];
        int not_take = 0 + dp[i - 1];

        dp[i] = max(take, not_take);
    }

    return dp[len - 1];
}

int main()
{
    vector<int> arr = {2, 1, 1, 2};
    int n = arr.size();
    cout << max(f(0, n - 2, arr), f(1, n - 1, arr)) << endl;
    return 0;
}