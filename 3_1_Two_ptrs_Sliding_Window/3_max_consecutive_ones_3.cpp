#include <iostream>
#include <vector>
using namespace std;

int maxOnes(vector<int> &arr, int k)
{
    int n = arr.size();
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        int zeros = 0;
        for (int j = i; j < n; j++)
        {
            if (arr[j] == 0)
                zeros++;

            if (zeros <= k)
            {
                maxLen = max(maxLen, j - i + 1);
            }
            else
            {
                break;
            }
        }
    }

    return maxLen;
}

int maxOnes_opt(vector<int> &arr, int k)
{
    int maxLen = 0, l = 0, r = 0, zeros = 0, n = arr.size();

    while (r < n)
    {
        if (arr[r] == 0)
            zeros++;

        if (zeros > k)
        {
            while (arr[l] == 1)
                l++;
            if (arr[l] == 0)
            {
                l++;
                zeros--;
            }
        }
        /*
        OR
        while(zeros>k){
            if(arr[l] == 0) zeros--;
            l++;
        }
        */

        maxLen = max(maxLen, r - l + 1);
        r++;
    }

    return maxLen;
}

int main()
{
    vector<int> arr = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    cout << maxOnes(arr, 2) << endl;
    cout << maxOnes_opt(arr, 2) << endl;
    return 0;
}