#include <iostream>
#include <vector>
using namespace std;

vector<int> RepeatingAndMissing(vector<int> &arr)
{
    int n = arr.size();
    int missing = -1;
    int repeating = -1;

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] == i)
            {
                cnt++;
            }
        }
        if (cnt == 2)
            repeating = i;
        if (cnt == 0)
            missing = i;
        if (missing != -1 && repeating != -1)
        {
            break;
        }
    }

    return {missing, repeating};
}

vector<int> RepeatingAndMissing_opt_1(vector<int> &arr)
{
    long long n = arr.size();

    long long SN = n * (n + 1) / 2;
    long long SN2 = n * (n + 1) * (2 * n + 1) / 6;
    long long S = 0, S2 = 0;

    for (int i = 0; i < n; i++)
    {
        S += arr[i];
        S2 += ((long long)arr[i] * (long long)arr[i]);
    }

    long long val1 = S - SN;
    long long val2 = S2 - SN2; // x2 - y2 = val2 // (x+y)(x-y) = val2
    val2 = val2 / val1;        // x+y = val2

    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)y, (int)x};
}

int main()
{
    vector<int> arr = {4, 3, 6, 2, 1, 1};

    vector<int> ans = RepeatingAndMissing(arr);
    for (auto ele : ans)
    {
        cout << ele << " ";
    }
    cout << endl;

    vector<int> ans2 = RepeatingAndMissing_opt_1(arr);
    for (auto ele : ans2)
    {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}