#include <iostream>
#include <vector>
using namespace std;

int maximum_training_points(int day, int last, vector<vector<int>> &arr, int n, int m, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < m; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, arr[0][i]);
            }
        }
        return maxi;
    }

    if (dp[day][last] != -1)
        return dp[day][last];

    int maxi = 0;
    for (int i = 0; i < m; i++)
    {
        if (i != last)
        {
            int points = arr[day][i] + maximum_training_points(day - 1, i, arr, n, m, dp);
            maxi = max(maxi, points);
        }
    }

    return dp[day][last] = maxi;
}

int maximum_training_points_tabu(vector<vector<int>> &arr, int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m + 1, 0));

    for (int j = 0; j <= m; j++)
    {
        int maxi = 0;
        for (int k = 0; k < m; k++)
        {
            if (j != k)
            {
                int points = arr[0][k];
                maxi = max(maxi, points);
            }
        }
        dp[0][j] = maxi;
    }

    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last <= m; last++)
        {
            int maxi = 0;
            for (int task = 0; task < m; task++)
            {
                if (task != last)
                {
                    int points = arr[day][task] + dp[day - 1][task];
                    maxi = max(maxi, points);
                }
            }

            dp[day][last] = maxi;
        }
    }

    return dp[n - 1][m];
}

int maximum_training_points_space_opt(vector<vector<int>> &arr, int n, int m)
{
    vector<int> dp(m + 1, 0);

    for (int last = 0; last <= m; last++)
    {
        int maxi = 0;
        for (int task = 0; task < m; task++)
        {
            if (task != last)
            {
                maxi = max(maxi, arr[0][task]);
            }
        }
        dp[last] = maxi;
    }

    for (int day = 1; day < n; day++)
    {
        vector<int> temp(m + 1, 0);
        for (int last = 0; last <= m; last++)
        {
            int maxi = 0;
            for (int task = 0; task < m; task++)
            {
                if (task != last)
                {
                    int points = arr[day][task] + dp[task];
                    maxi = max(maxi, points);
                }
            }

            temp[last] = maxi;
        }
        dp = temp;
    }

    return dp[m];
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 5}, {3, 1, 1}, {3, 3, 3}};
    vector<vector<int>> arr2 = {{2, 1, 3}, {3, 4, 6}, {10, 1, 6}, {8, 3, 7}};
    int n = arr2.size();
    int m = arr2[0].size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << maximum_training_points(n - 1, m, arr2, n, m, dp) << endl;
    cout << maximum_training_points_tabu(arr2, n, m) << endl;
    cout << maximum_training_points_space_opt(arr2, n, m);
    return 0;
}