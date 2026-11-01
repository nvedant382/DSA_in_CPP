#include <iostream>
#include <vector>
using namespace std;

/*

Solution 1: Same as count subarrays with sum k
Time = O(N logN)
Space = O(N)

*/

int subArraysWithGoal(vector<int> &arr, int k)
{
    if (k < 0)
        return 0;

    int n = arr.size(), cnt = 0, r = 0, l = 0, sum = 0;

    while (r < n)
    {
        sum += arr[r];
        // if() is for finding maxLen
        while (sum > k)
        {
            sum -= arr[l];
            l++;
        }

        cnt += (r - l + 1);
        r++;
    }

    return cnt;
}

// Time = O(4N)  &  Space = O(1)
int countSubArrays(vector<int> &arr, int goal)
{
    return subArraysWithGoal(arr, goal) - subArraysWithGoal(arr, goal - 1);
}

int main()
{
    vector<int> arr = {1, 0, 1, 0, 1};
    // O/P: all subarrays with sum/goal = k
    cout << countSubArrays(arr, 2) << endl;
    return 0;
}