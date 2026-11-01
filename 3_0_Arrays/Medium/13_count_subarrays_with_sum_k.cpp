#include <iostream>
#include <vector>
#include <map>
using namespace std;

int countSubArrSumK(vector<int> &arr, int k)
{
    map<int, int> mpp;
    mpp[0] = 1;

    int n = arr.size();
    int preSum = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        preSum += arr[i]; // if(preSum == k) cnt++ so no need of 0 -> 1 in map
        int remove = preSum - k;

        cnt += mpp[remove];
        mpp[preSum] += 1;
    }

    return cnt;
}

int main()
{
    vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    cout << countSubArrSumK(arr, 3) << endl;
    return 0;
}