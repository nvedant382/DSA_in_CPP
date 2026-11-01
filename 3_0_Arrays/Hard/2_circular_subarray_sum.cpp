#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void rotateByOne(vector<int> &arr)
{
    int n = arr.size();
    int temp = arr[0];

    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }

    arr[n - 1] = temp;
}

int kadane(vector<int> &arr)
{
    int sum = 0;
    int maxi = INT_MIN;

    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];

        if (sum > maxi)
            maxi = sum;

        if (sum < 0)
            sum = 0;
    }

    return maxi;
}

// O(N^2)
int maxCircularSubArraySum(vector<int> &arr)
{
    int n = arr.size();
    int maxi = INT_MIN;
    int sum = -1;

    for (int i = 0; i < n; i++)
    {
        rotateByOne(arr);
        sum = kadane(arr);
        maxi = max(maxi, sum);
    }

    return maxi;
}

int main()
{
    vector<int> arr = {5, -3, 5};
    cout << maxCircularSubArraySum(arr) << endl;
    return 0;
}