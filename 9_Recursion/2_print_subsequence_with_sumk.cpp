#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void generateAllSequences_with_sum_K(int idx, vector<int> &arr, vector<int> &ans, int sum, int k)
{
    if (idx == arr.size())
    {
        if (sum == k)
        {
            for (auto ele : ans)
            {
                cout << ele << " ";
            }
            cout << endl;
        }

        return;
    }

    // take
    ans.push_back(arr[idx]);
    sum += arr[idx];
    generateAllSequences_with_sum_K(idx + 1, arr, ans, sum, k);

    // not take
    ans.pop_back();
    sum -= arr[idx];
    generateAllSequences_with_sum_K(idx + 1, arr, ans, sum, k);
}

bool generateAllSequences_with_sum_K_one_sol(int idx, vector<int> &arr, vector<int> &ans, int sum, int k)
{
    if (idx == arr.size())
    {
        if (sum == k)
        {
            for (auto ele : ans)
            {
                cout << ele << " ";
            }
            cout << endl;
            return true;
        }

        return false;
    }

    // take
    ans.push_back(arr[idx]);
    sum += arr[idx];
    if (generateAllSequences_with_sum_K_one_sol(idx + 1, arr, ans, sum, k))
        return true;

    // not take
    ans.pop_back();
    sum -= arr[idx];
    if (generateAllSequences_with_sum_K_one_sol(idx + 1, arr, ans, sum, k))
        return true;

    return false;
}

int generateAllSequences_with_sum_K_count(int idx, vector<int> &arr, vector<int> &ans, int sum, int k)
{
    if (idx == arr.size())
    {
        if (sum == k)
        {
            return 1;
        }

        return 0;
    }

    // take
    ans.push_back(arr[idx]);
    sum += arr[idx];
    int l = generateAllSequences_with_sum_K_count(idx + 1, arr, ans, sum, k);

    // not take
    ans.pop_back();
    sum -= arr[idx];
    int r = generateAllSequences_with_sum_K_count(idx + 1, arr, ans, sum, k);

    return l + r;
}

int main()
{
    vector<int> arr = {1, 2, 1};
    vector<int> ans = {};
    generateAllSequences_with_sum_K(0, arr, ans, 0, 2);
    generateAllSequences_with_sum_K_one_sol(0, arr, ans, 0, 2);
    cout << generateAllSequences_with_sum_K_count(0, arr, ans, 0, 2) << endl;
    return 0;
}