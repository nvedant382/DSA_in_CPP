#include <iostream>
#include <map>
#include <vector>
using namespace std;

int total_subArrays(vector<int> &arr, int k)
{
    // time = O(N^2) & space = O(N)
    int n = arr.size(), cnt = 0;
    map<int, int> mpp;

    for (int i = 0; i < n; i++)
    {
        mpp.clear();
        for (int j = i; j < n; j++)
        {
            mpp[arr[j]]++;

            if (mpp.size() > k)
                break;
            else if (mpp.size() == k)
            {
                cnt++;
            }
        }
    }

    return cnt;
}

int total_subArrays_opt(vector<int> &arr, int k)
{
    // time = O(2N) & space = O(N)
    int n = arr.size(), cnt = 0, r = 0, l = 0;
    map<int, int> mpp;

    while (r < n)
    {
        mpp[arr[r]]++;

        while (mpp.size() > k)
        {
            mpp[arr[l]]--;
            if (mpp[arr[l]] == 0)
                mpp.erase(arr[l]);
            l++;
        }

        cnt += (r - l + 1);

        r++;
    }

    return cnt;
}

int main()
{
    vector<int> arr = {1, 2, 1, 3, 4};
    cout << total_subArrays(arr, 3) << endl;
    cout << (total_subArrays_opt(arr, 3) - total_subArrays_opt(arr, 2)) << endl;
    return 0;
}