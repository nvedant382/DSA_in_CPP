#include <iostream>
#include <climits>
using namespace std;

int max_subarray_sum(int arr[], int n)
{
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

int max_subarray_sum_better(int arr[], int n)
{
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
         {
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }

    return maxi;
}

int kadanesAlgo(int arr[], int n)
{
    int maxi = INT_MIN;
    int sum = 0;
    int start = -1, ansStart = -1, ansEnd = -1;

    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
            start = i;
        sum += arr[i];
        if (sum > maxi)
        {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0)
        {
            sum = 0;
        }
    }

    if (maxi < 0)
    {
        maxi = 0; // if none of subarray is giving maxi > 0 , then just maxi=0;
    }

    cout << ansStart << " " << ansEnd << endl;
    return maxi;
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3}; // ans = 7
    cout << max_subarray_sum(arr, 8) << endl;
    cout << max_subarray_sum_better(arr, 8) << endl;
    cout << kadanesAlgo(arr, 8) << endl;
    return 0;
}