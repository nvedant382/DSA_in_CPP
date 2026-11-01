#include <iostream>
#include <vector>
using namespace std;

int maxPoints(vector<int> &arr, int k)
{
    int lsum = 0, rsum = 0, maxSum = 0;

    for (int i = 0; i <= k - 1; i++)
    {
        lsum += arr[i];
    }

    maxSum = lsum;

    int right = arr.size() - 1;

    for (int i = k - 1; i >= 0; i--)
    {
        lsum -= arr[i];
        rsum += arr[right];
        right--;

        maxSum = max(maxSum, lsum + rsum);
    }

    return maxSum;
}

int main()
{
    vector<int> arr = {6, 2, 3, 4, 7, 2, 1, 7, 1};
    cout << maxPoints(arr, 4) << endl;
    return 0;
}