#include <iostream>
#include <map>
#include <vector>
using namespace std;

int longestSubarray(int arr[], int n, int k)
{
    int len = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            if (sum == k)
            {
                len = max(len, j - i + 1);
            }
        }
    }
    return len;
}

int longestSubarray_better_1(int arr[], int n, int k)
{
    int len = -1;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                len = max(len, j - i + 1);
            }
        }
    }
    return len;
}

// using hashing : for all neg,pos,zero
int longestSubarray_better_2(int arr[], int n, long long k)
{
    map<long long, int> prevSumMap;
    long long sum = 0;
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
            // continue;
        }

        int remaining = sum - k; // if arr previous sum is sum-k then current one is subarray with k.
        if (prevSumMap.find(remaining) != prevSumMap.end())
        {
            maxLen = max(maxLen, i - prevSumMap[remaining]);
        }

        // if prevSumMap don't exist early then don't update index.
        if (prevSumMap.find(sum) == prevSumMap.end())
        {
            prevSumMap[sum] = i;
        }
    }

    return maxLen;
}
// 2 pointers
int optimal(int arr[], int n, int k)
{
    int left = 0, right = 0, sum = arr[0], maxLen = 0;

    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }

        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        if (right < n)
        {
            sum += arr[right];
        }
    }

    return maxLen;
}

int main()
{
    int arr[] = {1, 2, 3, 1, 1, 1, 1, 4, 2, 3};

    cout << longestSubarray(arr, 10, 8) << endl;
    cout << longestSubarray_better_1(arr, 10, 8) << endl;
    cout << longestSubarray_better_2(arr, 10, 8) << endl;
    cout << optimal(arr, 10, 8) << endl;

    return 0;
}