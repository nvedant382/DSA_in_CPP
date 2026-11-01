#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int max_product_subarray(vector<int> arr)
{
    int n = arr.size();
    int maxi = INT_MIN;
    int pre = 1;
    int suff = 1;

    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
            pre = 1;
        if (suff == 0)
            suff = 1;

        pre = pre * arr[i];
        suff = suff * arr[n - i - 1];

        maxi = max(maxi, max(pre, suff));
    }

    return maxi;
}

int main()
{
    vector<int> arr = {2, 3, -2, 4};
    vector<int> arr2 = {-2, 3, 4, -1, 0, -2, 3, 1, 4, 0, 4, 6, -1, 4};
    vector<int> arr3 = {5, -3, 5};

    cout << max_product_subarray(arr2) << endl;
    return 0;
}