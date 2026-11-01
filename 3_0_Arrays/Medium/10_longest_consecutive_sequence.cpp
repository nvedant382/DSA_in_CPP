#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_set>
using namespace std;

bool ls(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return true;
    }
    return false;
}

int brute(int arr[], int n)
{
    int longest = 1;

    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        int cnt = 1;

        while (ls(arr, n, x + 1))
        {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }

    return longest;
}

int opt(vector<int> arr, int n)
{
    int longest = 1;
    unordered_set<int> st;

    for (int i = 0; i < n; i++)
    {
        st.insert(arr[i]);
    }

    for (auto it : st)
    {
        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x += 1;
                cnt += 1;
            }
            longest = max(longest, cnt);
        }
    }

    return longest;
}

int better(vector<int> arr, int n)
{
    sort(arr.begin(), arr.end());
    int longest = 1;
    int cnt = 0;
    int lastSmaller = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] - 1 == lastSmaller)
        {
            cnt += 1;
            lastSmaller = arr[i];
        }
        else if (arr[i] != lastSmaller)
        {
            cnt = 1;
            lastSmaller = arr[i];
        }
        longest = max(longest, cnt);
    }

    return longest;
}

int main()
{
    int arr[] = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    vector<int> arr2 = {102, 4, 100, 1, 101, 3, 2, 1, 1};

    cout << brute(arr, 9) << endl;
    cout << better(arr2, 9) << endl;
    cout << opt(arr2, 9) << endl;
    return 0;
}