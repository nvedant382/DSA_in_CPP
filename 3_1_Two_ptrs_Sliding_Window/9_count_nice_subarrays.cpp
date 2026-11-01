#include <iostream>
#include <vector>
using namespace std;

int NicesubArraysWithK(int arr[], int k, int n)
{
    if (k < 0)
        return 0;
    int cnt = 0, l = 0, r = 0, odds = 0;

    while (r < n)
    {
        if (arr[r] % 2 == 1)
            odds++;

        while (odds > k)
        {
            if (arr[l] % 2 == 1)
                odds--;

            l++;
        }

        cnt += (r - l + 1);
        r++;
    }

    return cnt;
}

int countSubArrays(int arr[], int k, int n)
{
    return NicesubArraysWithK(arr, k, n) - NicesubArraysWithK(arr, k - 1, n);
}

int main()
{
    int arr[5] = {1, 1, 2, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << countSubArrays(arr, 3, n) << endl;
    return 0;
}